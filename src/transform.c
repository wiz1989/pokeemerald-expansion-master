#include "global.h"
#include "transform.h"
#include "event_data.h"
#include "mystery_gift.h"
#include "util.h"
#include "constants/event_objects.h"
#include "constants/map_scripts.h"
#include "main_menu.h"
#include "main.h"
#include "random.h"
#include "battle_setup.h"
#include "string_util.h"
#include "strings.h"
#include "pokemon_storage_system.h"
#include "task.h"
#include "field_weather.h"
#include "fldeff.h"
#include "new_game.h"
#include "start_menu.h"
#include "constants/metatile_labels.h"
#include "fieldmap.h"
#include "field_screen_effect.h"
#include "overworld.h"
#include "event_scripts.h"
#include "sound.h"
#include "constants/songs.h"
#include "constants/trainers.h"
#include "data.h"
#include "constants/battle.h"
#include "event_object_movement.h"
#include "script_pokemon_util.h"
#include "palette.h"
#include "decompress.h"
#include "window.h"
#include "text.h"
#include "menu.h"
#include "gpu_regs.h"
#include "constants/weather.h"
#include "global.fieldmap.h"
#include "tilesets.h"
#include "constants/decorations.h"
#include "decoration_inventory.h"
#include "decoration.h"
#include "pokemon.h"
#include "pokedex.h"
#include "pokedex_plus_hgss.h"
#include "field_player_avatar.h"
#include "naming_screen.h"
#include "config/general.h"
#include "item.h"
#include "item_use.h"
#include "item_icon.h"
#include "constants/abilities.h"
#include "constants/vars.h"
#include "event_object_lock.h"
#include "constants/species.h"
#include "graphics.h"
#include "script.h"
#include "egg_hatch.h"
#include "field_effect.h"
#include "bike.h"
#include "data/transformations.h"

const void *GetTransformationPic(u16 speciesId);
const u16 *GetTransformationPalette(u16 speciesId);
static u8 IsSpeciesValidTransformation(u16 speciesId);
static void WarpToTransformationMap(u16 speciesId, bool8 useFade);
static void SetObjectEventSpritesMosaic(bool8 enable);
static void DestroyWeatherSpriteArray(struct Sprite **sprites, u16 count);
static void ClearAllWeatherSprites(void);
static void RestartWeatherImmediate(u8 weather);

EWRAM_DATA u8 gPlayerTransformEffectActive = FALSE;
static EWRAM_DATA u16 sPendingTransformWarpSpecies = SPECIES_NONE;
static EWRAM_DATA bool8 sResumeMapWeatherAtMosaicEnd = FALSE;

struct PitAvatarInfo {
    u16 mugshotId;
    u16 graphicsId;
    u16 trainerFrontPicId;
    u16 trainerBackPicId;
};

#define PIT_AVATAR_COUNT ARRAY_COUNT(sPitAvatars)
static const struct PitAvatarInfo sPitAvatars[] =
{
    {
        .mugshotId = AVATAR_POKEMON_CHOICE,
        .graphicsId = 0xFFFF,
        .trainerFrontPicId = 0xFFFF,
        .trainerBackPicId = 0,
    },
};

// handle dynamic palettes; based on LoadDynamicFollowerPalette
// loads the pal and returns the id
static u8 LoadDynamicPlayerTransformPalette(u16 species, bool32 shiny)
{
    u32 paletteNum;

#if OW_POKEMON_OBJECT_EVENTS == TRUE && OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    if ((shiny && gSpeciesInfo[species].overworldShinyPalette != NULL)
     || (!shiny && gSpeciesInfo[species].overworldPalette != NULL))
    {
        struct SpritePalette spritePalette;
        u16 palTag = GetGraphicsIdForMon(species, shiny, FALSE);

        if ((paletteNum = IndexOfSpritePaletteTag(palTag)) < 16)
            return paletteNum;

        spritePalette.tag = palTag;
        spritePalette.data = shiny ? gSpeciesInfo[species].overworldShinyPalette
                                   : gSpeciesInfo[species].overworldPalette;
        paletteNum = LoadSpritePalette(&spritePalette);
    }
    else
#endif
    {
        const u16 *palette = GetMonSpritePalFromSpecies(species, shiny, FALSE);

        if ((paletteNum = IndexOfSpritePaletteTag(species)) < 16)
            return paletteNum;

        LoadSpritePaletteWithTag(palette, species);
        paletteNum = IndexOfSpritePaletteTag(species);
    }

    if (gWeatherPtr->currWeather != WEATHER_FOG_HORIZONTAL)
        UpdateSpritePaletteWithWeather(paletteNum, FALSE);

    return paletteNum;
}

// free old player pal and load new one
static void RefreshPlayerTransformPalette(struct ObjectEvent *playerObjectEvent)
{
    const struct ObjectEventGraphicsInfo *graphicsInfo = GetObjectEventGraphicsInfo(playerObjectEvent->graphicsId);
    struct Sprite *sprite = &gSprites[playerObjectEvent->spriteId];

    if (graphicsInfo->paletteTag != OBJ_EVENT_PAL_TAG_DYNAMIC)
        return;

    sprite->inUse = FALSE;
    FieldEffectFreePaletteIfUnused(sprite->oam.paletteNum);
    sprite->inUse = TRUE;
    sprite->oam.paletteNum = LoadDynamicPlayerTransformPalette(gSaveBlock2Ptr->pokemonAvatarSpecies, IsMonShiny(&gParties[B_TRAINER_PLAYER][0]));
}

// leftover from Pokémon Transform; not actually required
bool32 PlayerIsCastform(void)
{
    return TRUE;
}

// compute player's current graphics id, update var and start bob task
u16 ReturnAvatarGraphicsId(u16 avatarId)
{
    u16 graphicsId;
    
    if (IsMonShiny(&gParties[B_TRAINER_PLAYER][0]) == TRUE)
    {
        graphicsId = gSaveBlock2Ptr->pokemonAvatarSpecies + OBJ_EVENT_MON + OBJ_EVENT_MON_SHINY;
    }
    else
    {
        graphicsId = gSaveBlock2Ptr->pokemonAvatarSpecies + OBJ_EVENT_MON;
    }

    VarSet(VAR_OBJ_GFX_ID_D, graphicsId);
    TryCreatePokemonAvatarSpriteBob();

    return graphicsId;
}

u16 ReturnAvatarTrainerFrontPicId(u16 avatarId)
{
    return sPitAvatars[avatarId].trainerFrontPicId;
}

u16 ReturnAvatarTrainerBackPicId(u16 avatarId)
{
    return sPitAvatars[avatarId].trainerBackPicId;
}


// transform mosaic effect tasks
#define tUnlockFieldControls data[0]
#define tTransformFrame data[1]
#define tTransformType data[2]

void BeginPlayerTransformEffect(u8 type, bool8 unlockPlayerFieldControls)
{
    u8 taskId;

    sResumeMapWeatherAtMosaicEnd = FALSE;

    if (gPlayerAvatar.spriteId < MAX_SPRITES)
    {
        gSprites[gPlayerAvatar.spriteId].oam.priority = 2;
        gPlayerTransformEffectActive = TRUE;
        taskId = CreateTask(UpdatePlayerTransformAnimation, 0xFF);
        gTasks[taskId].tUnlockFieldControls = unlockPlayerFieldControls;
        gTasks[taskId].tTransformFrame = 0;
        gTasks[taskId].tTransformType = type;
    }
}

void EndPlayerTransformAnimation(u8 taskId)
{
    struct Sprite *sprite = NULL;
    u16 pendingWarpSpecies;

    // clear data
    gPlayerTransformEffectActive = FALSE;
    REG_MOSAIC = 0;

    if (TRANSFORM_ANIM_TYPE == TRANSFORM_ANIM_SCREEN)
    {
        ClearGpuRegBits(REG_OFFSET_BG0CNT, BGCNT_MOSAIC);
        ClearGpuRegBits(REG_OFFSET_BG1CNT, BGCNT_MOSAIC);
        ClearGpuRegBits(REG_OFFSET_BG2CNT, BGCNT_MOSAIC);
        ClearGpuRegBits(REG_OFFSET_BG3CNT, BGCNT_MOSAIC);
        SetObjectEventSpritesMosaic(FALSE);
    }   

    if (gPlayerAvatar.spriteId < MAX_SPRITES)
    {
        sprite = &gSprites[gPlayerAvatar.spriteId];
        sprite->oam.mosaic = FALSE;
        sprite->oam.priority = 2;
    }

    // reset weather
    if (sResumeMapWeatherAtMosaicEnd && TRANSFORM_ANIM_TYPE == TRANSFORM_ANIM_SCREEN)
    {
        RestartWeatherImmediate(GetSavedWeather());
        sResumeMapWeatherAtMosaicEnd = FALSE;
    }

    // update player sprite
    struct ObjectEvent *playerObjectEvent = &gObjectEvents[gPlayerAvatar.objectEventId];
    ObjectEventSetGraphicsId(playerObjectEvent, GetPlayerAvatarGraphicsIdByStateId(PLAYER_AVATAR_STATE_NORMAL));
    RefreshPlayerTransformPalette(playerObjectEvent);
    ObjectEventTurn(playerObjectEvent, playerObjectEvent->movementDirection);
    SetPlayerAvatarStateMask(PLAYER_AVATAR_FLAG_ON_FOOT);
    ObjectEventSetHeldMovement(playerObjectEvent, GetFaceDirectionMovementAction(playerObjectEvent->facingDirection));

    // warp handling, when transform is finished
    pendingWarpSpecies = sPendingTransformWarpSpecies;
    sPendingTransformWarpSpecies = SPECIES_NONE;
    if (pendingWarpSpecies != SPECIES_NONE)
    {
        WarpToTransformationMap(pendingWarpSpecies, TRUE);
        DestroyTask(taskId);
        return;
    }

    if (gTasks[taskId].tUnlockFieldControls)
    {
        gPlayerAvatar.preventStep = FALSE;
        UnlockPlayerFieldControls();
    }
    DestroyTask(taskId);
}

// main update logic for the player transform effect 
void UpdatePlayerTransformAnimation(u8 taskId)
{
    struct ObjectEvent *playerObjectEvent = &gObjectEvents[gPlayerAvatar.objectEventId];
    u8 frames = gTasks[taskId].tTransformFrame;
    u8 stretch;

    // exit and clean up if player sprite is invalid
    if (gPlayerAvatar.spriteId >= MAX_SPRITES)
    {
        gPlayerTransformEffectActive = FALSE;
        REG_MOSAIC = 0;
        if (sResumeMapWeatherAtMosaicEnd)
        {
            RestartWeatherImmediate(GetSavedWeather());
            sResumeMapWeatherAtMosaicEnd = FALSE;
        }
        DestroyTask(taskId);
        return;
    }

    // set up mosaic effect
    if (TRANSFORM_ANIM_TYPE == TRANSFORM_ANIM_SCREEN)
    {
        SetObjectEventSpritesMosaic(TRUE);
        SetGpuRegBits(REG_OFFSET_BG0CNT, BGCNT_MOSAIC);
        SetGpuRegBits(REG_OFFSET_BG1CNT, BGCNT_MOSAIC);
        SetGpuRegBits(REG_OFFSET_BG2CNT, BGCNT_MOSAIC);
        SetGpuRegBits(REG_OFFSET_BG3CNT, BGCNT_MOSAIC);
    }
    else
    {
        gSprites[gPlayerAvatar.spriteId].oam.mosaic = TRUE;
    }

    if (frames < TRANSFORM_ANIM_SWAP_FRAME)
        stretch = (frames * TRANSFORM_ANIM_MAX_STRETCH) / TRANSFORM_ANIM_SWAP_FRAME;
    else if (frames < TRANSFORM_ANIM_TOTAL_FRAMES)
        stretch = ((TRANSFORM_ANIM_TOTAL_FRAMES - frames) * TRANSFORM_ANIM_MAX_STRETCH)
                 / (TRANSFORM_ANIM_TOTAL_FRAMES - TRANSFORM_ANIM_SWAP_FRAME);
    else // Animation finished
        return EndPlayerTransformAnimation(taskId);

    if (TRANSFORM_ANIM_TYPE == TRANSFORM_ANIM_SCREEN)
    {
        // write to all mosaic sizes (BG and OBJ)
        SetGpuReg(REG_OFFSET_MOSAIC, (stretch << 12) | (stretch << 8) | (stretch << 4) | stretch);
    }
    else
    {
        // write to only OBJ mosaic sizes
        SetGpuReg(REG_OFFSET_MOSAIC, (stretch << 12) | (stretch << 8));
    }

    if (frames == TRANSFORM_ANIM_SWAP_FRAME)
    {
        ObjectEventSetGraphicsId(playerObjectEvent, GetPlayerAvatarGraphicsIdByStateId(PLAYER_AVATAR_STATE_NORMAL));
        RefreshPlayerTransformPalette(playerObjectEvent);
    }

    if (TRANSFORM_ANIM_TYPE == TRANSFORM_ANIM_SCREEN)
    {
        // in screen mode, warp at peak mosaic
        u16 pendingWarpSpecies = sPendingTransformWarpSpecies;
        sPendingTransformWarpSpecies = SPECIES_NONE;
        if (pendingWarpSpecies != SPECIES_NONE)
            WarpToTransformationMap(pendingWarpSpecies, FALSE);
    }
    
    gTasks[taskId].tTransformFrame++; // increment frames
}

// handle mosaic effects for all object events on screen
static void SetObjectEventSpritesMosaic(bool8 enable)
{
    u8 i;

    for (i = 0; i < OBJECT_EVENTS_COUNT; i++)
    {
        struct ObjectEvent *obj = &gObjectEvents[i];

        if (obj->active && obj->spriteId < MAX_SPRITES)
            gSprites[obj->spriteId].oam.mosaic = enable;
    }
}

#undef tUnlockFieldControls
#undef tTransformFrame
#undef tTransformType

// helper functions
static u8 IsSpeciesValidTransformation(u16 speciesId)
{
    switch (speciesId)
    {
        case SPECIES_CASTFORM:
        case SPECIES_CASTFORM_RAINY:
        case SPECIES_CASTFORM_SUNNY:
        case SPECIES_CASTFORM_SNOWY:
            return TRUE;
        default:
            return FALSE;
    }
}

u16 GetValidTransformationSpeciesFromParty(u8 partyId)
{
    if (partyId >= gPartiesCount[B_TRAINER_PLAYER])
        return SPECIES_NONE;

    u16 speciesId = GetMonData(&gParties[B_TRAINER_PLAYER][partyId], MON_DATA_SPECIES);

    if (speciesId == GetCurrentTransformationSpecies())
        return SPECIES_NONE;

    if (IsSpeciesValidTransformation(speciesId))
        return speciesId;
    
    return SPECIES_NONE;
}

TransformFunc GetTransformationFunc(u16 speciesId)
{
    return gTransformations[speciesId].fieldUseFunc;
}

u16 GetTransformationMoves(u16 speciesId, u8 i)
{
    return gTransformations[speciesId].moves[i];
}

u16 GetTransformationAbility(u16 speciesId)
{
    return gTransformations[speciesId].ability;
}

u16 GetTransformationBattleSpecies(u16 speciesId)
{
    return gTransformations[speciesId].battleSpecies;
}

u16 GetTransformationTargetMap(u16 speciesId)
{
    return gTransformations[speciesId].targetMap;
}

// warp function
static void WarpToTransformationMap(u16 speciesId, bool8 useFade)
{
    u16 targetMap;
    u16 mapGroup;
    u16 mapNum;

    if (!IsSpeciesValidTransformation(speciesId))
        return;

    targetMap = GetTransformationTargetMap(speciesId);
    if (targetMap == MAP_UNDEFINED)
        return;

    mapGroup = MAP_GROUP(targetMap);
    mapNum = MAP_NUM(targetMap);

    if (useFade)
    {
        SetWarpDestination(mapGroup, mapNum, WARP_ID_NONE, gSaveBlock1Ptr->pos.x, gSaveBlock1Ptr->pos.y);
        DoWarp();
        // ResetInitialPlayerAvatarState();
    }
    else
    {
        // directly load target map at current coordinates
        LoadMapFromCameraTransition(mapGroup, mapNum);
        // remove old weather instantly while the mosaic still covers the map
        RestartWeatherImmediate(WEATHER_NONE);
        sResumeMapWeatherAtMosaicEnd = TRUE;
    }
}

// weather related functions for a clean transition
static void DestroyWeatherSpriteArray(struct Sprite **sprites, u16 count)
{
    u16 i;

    for (i = 0; i < count; i++)
    {
        if (sprites[i] != NULL)
        {
            DestroySprite(sprites[i]);
            sprites[i] = NULL;
        }
    }
}

static void ClearAllWeatherSprites(void)
{
    DestroyWeatherSpriteArray(gWeatherPtr->sprites.s1.rainSprites, ARRAY_COUNT(gWeatherPtr->sprites.s1.rainSprites));
    DestroyWeatherSpriteArray(gWeatherPtr->sprites.s1.snowflakeSprites, ARRAY_COUNT(gWeatherPtr->sprites.s1.snowflakeSprites));
    DestroyWeatherSpriteArray(gWeatherPtr->sprites.s1.cloudSprites, ARRAY_COUNT(gWeatherPtr->sprites.s1.cloudSprites));

    DestroyWeatherSpriteArray(gWeatherPtr->sprites.s2.fogHSprites, ARRAY_COUNT(gWeatherPtr->sprites.s2.fogHSprites));
    DestroyWeatherSpriteArray(gWeatherPtr->sprites.s2.ashSprites, ARRAY_COUNT(gWeatherPtr->sprites.s2.ashSprites));
    DestroyWeatherSpriteArray(gWeatherPtr->sprites.s2.fogDSprites, ARRAY_COUNT(gWeatherPtr->sprites.s2.fogDSprites));
    DestroyWeatherSpriteArray(gWeatherPtr->sprites.s2.sandstormSprites1, ARRAY_COUNT(gWeatherPtr->sprites.s2.sandstormSprites1));
    DestroyWeatherSpriteArray(gWeatherPtr->sprites.s2.sandstormSprites2, ARRAY_COUNT(gWeatherPtr->sprites.s2.sandstormSprites2));

    gWeatherPtr->cloudSpritesCreated = FALSE;
    gWeatherPtr->fogHSpritesCreated = FALSE;
    gWeatherPtr->ashSpritesCreated = FALSE;
    gWeatherPtr->fogDSpritesCreated = FALSE;
    gWeatherPtr->sandstormSpritesCreated = FALSE;
    gWeatherPtr->sandstormSwirlSpritesCreated = FALSE;
    gWeatherPtr->bubblesSpritesCreated = FALSE;
    gWeatherPtr->rainSpriteCount = 0;
    gWeatherPtr->targetRainSpriteCount = 0;
    gWeatherPtr->snowflakeSpriteCount = 0;
    gWeatherPtr->targetSnowflakeSpriteCount = 0;
    gWeatherPtr->weatherGfxLoaded = FALSE;

    FreeSpriteTilesByTag(GFXTAG_CLOUD);
    FreeSpriteTilesByTag(GFXTAG_FOG_H);
    FreeSpriteTilesByTag(GFXTAG_ASH);
    FreeSpriteTilesByTag(GFXTAG_FOG_D);
    FreeSpriteTilesByTag(GFXTAG_SANDSTORM);
    FreeSpriteTilesByTag(GFXTAG_BUBBLE);
    FreeSpriteTilesByTag(GFXTAG_RAIN);
    FreeSpritePaletteByTag(PALTAG_WEATHER);
    FreeSpritePaletteByTag(PALTAG_WEATHER_2);
}

static void RestartWeatherImmediate(u8 weather)
{
    ClearAllWeatherSprites();

    if (gWeatherPtr->taskId < NUM_TASKS && gTasks[gWeatherPtr->taskId].isActive)
        DestroyTask(gWeatherPtr->taskId);

    // clear blend registers to have no side effects from flashes or similar effects
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDY, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);

    // reset weather palette
    gWeatherPtr->colorMapIndex = 0;
    gWeatherPtr->targetColorMapIndex = 0;
    gWeatherPtr->colorMapStepCounter = 0;
    gWeatherPtr->palProcessingState = WEATHER_PAL_STATE_IDLE;
    gWeatherPtr->fadeScreenCounter = 0;
    gWeatherPtr->thunderEnqueued = FALSE;
    gWeatherPtr->thunderTimer = 0;
    gWeatherPtr->thunderSETimer = 0;

    SetWeatherPalStateIdle();
    ApplyWeatherColorMapToPals(0, NUM_PALS_TOTAL);

    StartWeather();
    SetWeatherPalStateIdle();
    SetCurrentAndNextWeatherNoDelay(weather);
}

// void TransformCastformBoxMon(u16 targetSpecies)
// {
//     if (!IsSpeciesValidTransformation(targetSpecies))
//         return;

//     struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][0];
//     u16 castformForm = gTransformations[targetSpecies].battleSpecies;

//     SetMonData(mon, MON_DATA_SPECIES, &castformForm);
//     for (u32 i = 0; i < MAX_MON_MOVES; i++)
//         SetMonMoveSlot(mon, gTransformations[targetSpecies].moves[i], i);
//     u32 abilityNum = 0; // gave the mons only one ability
//     SetMonData(mon, MON_DATA_ABILITY_NUM, &abilityNum);
//     CalculateXformStats(mon);
// }

u16 GetCurrentTransformationSpecies(void)
{
    u16 speciesId = VarGet(VAR_TRANSFORM_MON);

    if (!IsSpeciesValidTransformation(speciesId))
        return SPECIES_CASTFORM;

    return speciesId;
}

void SetPlayerAvatarFromScript(struct ScriptContext *ctx)
{
    u16 speciesId = SpeciesToNationalPokedexNum(VarGet(ScriptReadHalfword(ctx)));

    if (!IsSpeciesValidTransformation(speciesId))
        return;

    gSaveBlock2Ptr->pokemonAvatarSpecies = speciesId;
    VarSet(VAR_TRANSFORM_MON, speciesId); 

    BeginPlayerTransformEffect(TRANSFORM_TYPE_PLAYER_SPECIES, TRUE);
    PlaySE(SE_M_TELEPORT);
}

void SetPlayerAvatarTransformation(u16 speciesId, bool8 UnlockPlayerFieldControls)
{
    if (!IsSpeciesValidTransformation(speciesId))
        return;

    gSaveBlock2Ptr->pokemonAvatarSpecies = speciesId;
    VarSet(VAR_TRANSFORM_MON, speciesId); 
    sPendingTransformWarpSpecies = speciesId;

    BeginPlayerTransformEffect(TRANSFORM_TYPE_PLAYER_SPECIES, UnlockPlayerFieldControls);
    PlaySE(SE_M_TELEPORT);
}

// void SetPlayerAvatarSurfTransformation(u16 speciesId, bool8 UnlockPlayerFieldControls)
// {

//     if (VarGet(VAR_TRANSFORM_MON)==SPECIES_MARILL)
//     {
//         gSaveBlock2Ptr->pokemonAvatarSpecies = SPECIES_GUMSHOOS;
//         VarSet(VAR_TRANSFORM_MON, SPECIES_GUMSHOOS);
//     }
//     else if (VarGet(VAR_TRANSFORM_MON)==SPECIES_DRAGONAIR)
//     {
//         gSaveBlock2Ptr->pokemonAvatarSpecies = SPECIES_VOLBEAT;
//         VarSet(VAR_TRANSFORM_MON, SPECIES_VOLBEAT);
//     }
//     else if (VarGet(VAR_TRANSFORM_MON)==SPECIES_CHINCHOU)
//     {
//         gSaveBlock2Ptr->pokemonAvatarSpecies = SPECIES_YUNGOOS;
//         VarSet(VAR_TRANSFORM_MON, SPECIES_YUNGOOS); 
//     }
//     FlagSet(FLAG_DISABLE_XFORM_MENU);
//     FlagSet(FLAG_IS_SURFING_MARILL);
//     // Start the transformation effect.
//     BeginPlayerTransformEffect(TRANSFORM_TYPE_PLAYER_SPECIES, UnlockPlayerFieldControls);
// }

// void SetPlayerAvatarStopSurfTransformation(u16 speciesId, bool8 UnlockPlayerFieldControls)
// {
//     if (VarGet(VAR_TRANSFORM_MON)==SPECIES_GUMSHOOS)
//     {
//         gSaveBlock2Ptr->pokemonAvatarSpecies = SPECIES_MARILL;
//         VarSet(VAR_TRANSFORM_MON, SPECIES_MARILL);
//     }
//     else if (VarGet(VAR_TRANSFORM_MON)==SPECIES_VOLBEAT)
//     {
//         gSaveBlock2Ptr->pokemonAvatarSpecies = SPECIES_DRAGONAIR;
//         VarSet(VAR_TRANSFORM_MON, SPECIES_DRAGONAIR);
//     }
//     else if (VarGet(VAR_TRANSFORM_MON)==SPECIES_YUNGOOS)
//     {
//         gSaveBlock2Ptr->pokemonAvatarSpecies = SPECIES_CHINCHOU;
//         VarSet(VAR_TRANSFORM_MON, SPECIES_CHINCHOU); 
//     }
//     FlagClear(FLAG_DISABLE_XFORM_MENU);
//     FlagClear(FLAG_IS_SURFING_MARILL);
    

//     // Start the transformation effect.
//     BeginPlayerTransformEffect(TRANSFORM_TYPE_PLAYER_SPECIES, UnlockPlayerFieldControls);

// }

void TrySetPlayerAvatarTransformation(u16 speciesId, bool8 UnlockPlayerFieldControls)
{
    if (gSaveBlock2Ptr->pokemonAvatarSpecies == speciesId)
        return;
    
    SetPlayerAvatarTransformation(speciesId, UnlockPlayerFieldControls);
}

void TryCreatePokemonAvatarSpriteBob(void)
{   
    if(!(FuncIsActiveTask(Task_CreatePokemonAvatarBob) || FuncIsActiveTask(Task_PokemonAvatar_HandleBob)))
        CreateTask(Task_CreatePokemonAvatarBob, 0);
}

void Task_CreatePokemonAvatarBob(u8 taskId)
{
    if(gMain.callback2 == CB2_Overworld)
    {
        gTasks[taskId].func = Task_PokemonAvatar_HandleBob;
    }
}

#define STEP_FRAME_DURATION 6
void Task_PokemonAvatar_HandleBob(u8 taskId)
{
    struct ObjectEvent *playerObj = &gObjectEvents[gPlayerAvatar.objectEventId];
    struct Sprite *playerSprite = &gSprites[playerObj->spriteId];
    u8 movementActionId = playerObj->movementActionId;
    s16 *data = gTasks[taskId].data;

    switch(movementActionId)
    {
        case MOVEMENT_ACTION_WALK_FAST_DOWN:  
        case MOVEMENT_ACTION_WALK_FAST_UP:    
        case MOVEMENT_ACTION_WALK_FAST_LEFT:  
        case MOVEMENT_ACTION_WALK_FAST_RIGHT: 
        case MOVEMENT_ACTION_WALK_NORMAL_DOWN:  
        case MOVEMENT_ACTION_WALK_NORMAL_UP:    
        case MOVEMENT_ACTION_WALK_NORMAL_LEFT:  
        case MOVEMENT_ACTION_WALK_NORMAL_RIGHT: 
            break;
        default:
            playerSprite->y2 = 1;
            data[0] = 0;
            return;
    }

    if(data[0] == 0)
    {
        playerSprite->y2 = 1;
    }

    if(data[0] == STEP_FRAME_DURATION)
    {
        playerSprite->y2 -= 1;
    }

    if(data[0] == (STEP_FRAME_DURATION * 2))
    {
        playerSprite->y2 += 1;
        data[0] = 0;
        return;
    }

    data[0]++;
}

u8 BlitTransformationIconToWindow(u16 speciesId, u8 windowId, u16 x, u16 y, void *paletteDest)
{
    if (!AllocItemIconTemporaryBuffers())
        return 16;

    DecompressDataWithHeaderWram(GetTransformationPic(speciesId), gItemIconDecompressionBuffer);
    CopyItemIconPicTo4x4Buffer(gItemIconDecompressionBuffer, gItemIcon4x4Buffer);
    BlitBitmapToWindow(windowId, gItemIcon4x4Buffer, x, y, 32, 32);

    // if paletteDest is nonzero, copies the palette directly into it
    // otherwise, loads the palette into the windowId's BG palette ID
    if (paletteDest)
        CpuCopy16(GetTransformationPalette(speciesId), paletteDest, PLTT_SIZE_4BPP);
    else
        LoadPalette(GetTransformationPalette(speciesId), BG_PLTT_ID(gWindows[windowId].window.paletteNum), PLTT_SIZE_4BPP);

    FreeItemIconTemporaryBuffers();
    return 0;
}

const void *GetTransformationPic(u16 speciesId)
{
    if (speciesId == SPECIES_NONE)
        return gItemIcon_ReturnToFieldArrow;
    if (speciesId >= NUM_SPECIES)
        return gItemIcon_ReturnToFieldArrow;

    return gTransformations[speciesId].iconPic;
}

const u16 *GetTransformationPalette(u16 speciesId)
{
    if (speciesId == SPECIES_NONE)
        return gItemIconPalette_ReturnToFieldArrow;
    if (speciesId >= NUM_SPECIES)
        return gItemIconPalette_ReturnToFieldArrow;

    return gTransformations[speciesId].iconPalette;
}

void IsCastformFieldMoveUser(struct ScriptContext *ctx)
{
    u32 var = VarGet(ScriptReadHalfword(ctx));

    if (PlayerIsCastform())
        gSpecialVar_Result = FLDEFF_CONST_PLAYER_IS_DITTO;
    else
        gSpecialVar_Result = var; // Mantains the state of the previous var
}

// void Task_MarillSurfSequence2(u8 taskId)
// {
//     if (gTasks[taskId].data[0] < 15)
//     {
//         gTasks[taskId].data[0]++;
//     }
//     else
//     {
//         if (VarGet(VAR_TRANSFORM_MON)==SPECIES_MARILL)
//             SetPlayerAvatarSurfTransformation(SPECIES_GUMSHOOS, TRUE);
//         else if (VarGet(VAR_TRANSFORM_MON)==SPECIES_DRAGONAIR)
//             SetPlayerAvatarSurfTransformation(SPECIES_VOLBEAT, TRUE);
//         else if (VarGet(VAR_TRANSFORM_MON)==SPECIES_CHINCHOU)
//             SetPlayerAvatarSurfTransformation(SPECIES_YUNGOOS, TRUE);   
//         PlaySE(SE_M_DIVE);
//         UnfreezeObjectEvents();
//         DestroyTask(taskId);
//     }
// }

// void Task_StartJump(u8 taskId)
// {
//     if (gPlayerTransformEffectActive == FALSE)
//     {
//         struct ObjectEvent *objectEvent;
//         objectEvent = &gObjectEvents[gPlayerAvatar.objectEventId];
//         u8 direction = gObjectEvents[gPlayerAvatar.objectEventId].movementDirection;
//         ObjectEventClearHeldMovement(objectEvent);
//         PlayerJump(direction);
//         gTasks[taskId].func = Task_MarillSurfSequence2;
//     }
// }

// extern struct Pokemon gParties[B_TRAINER_PLAYER][PARTY_SIZE];
// extern u8 CalculatePlayerPartyCount(void);

// static bool8 IsMonInParty(u16 species)
// {
//     u8 i;
//     u8 partyCount = CalculatePlayerPartyCount();
//     for (i = 0; i < partyCount; i++)
//     {
//         if (GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_SPECIES, NULL) == species)
//             return TRUE;
//     }
//     return FALSE;
// }

// void StartMarillSurf(void)
// {
//     if (IsMonInParty(SPECIES_MARILL))
//     {
//     TrySetPlayerAvatarTransformation(SPECIES_MARILL, FALSE);
//     }
//     else
//     {
//         if (IsMonInParty(SPECIES_DRAGONAIR))
//         {
//             TrySetPlayerAvatarTransformation(SPECIES_DRAGONAIR, FALSE);
//         }
//         else
//         {
//             if (IsMonInParty(SPECIES_CHINCHOU))
//             {
//                 TrySetPlayerAvatarTransformation(SPECIES_CHINCHOU, FALSE);
//             }
//         }
//     }
//     CreateTask(Task_StartJump, 0xFF);
// }

// void GetWhiteoutCount(void)
// {
//     VarSet(VAR_WHITEOUT_COUNT, gSaveBlock1Ptr->whiteoutCount);
// }

// void ForceShinyCastform(void)
// {
//     gSaveBlock2Ptr->forceShinyCastform = 1;
// }

// void RemoveForceShinyCastform(void)
// {
//     gSaveBlock2Ptr->forceShinyCastform = 0;
// }

bool8 Script_GiveFirstMonLevel(void)
{
    if (gPartiesCount[B_TRAINER_PLAYER] == 0)
        return FALSE;

    struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][0];

    u16 species = GetMonData(mon, MON_DATA_SPECIES, NULL);
    u8 level = GetMonData(mon, MON_DATA_LEVEL, NULL);

    if (level >= MAX_LEVEL)
        return FALSE;

    u32 growthRate = gSpeciesInfo[species].growthRate;

    // Rare Candy behavior: set EXP to the next level’s exp threshold
    u32 exp = gExperienceTables[growthRate][level + 1];

    SetMonData(mon, MON_DATA_EXP, &exp);
    CalculateMonStats(mon);

    return FALSE;
}
