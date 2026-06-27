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

#include "bike.h"
#include "data/transformations.h"

const void *GetTransformationPic(u16 speciesId);
const u16 *GetTransformationPalette(u16 speciesId);

//
// 	Player Avatar System Code
//

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

bool32 PlayerIsCastform(void)
{
    return TRUE;
}

u16 ReturnAvatarMugshotId(u16 avatarId) // unused
{
    return sPitAvatars[avatarId].mugshotId;
}

u16 ReturnAvatarGraphicsId(u16 avatarId)
{
    u16 graphicsId = OBJ_EVENT_GFX_VAR_D; // Directly assign the variable graphic ID
    if (IsMonShiny(&gParties[B_TRAINER_PLAYER][0]) == TRUE)
    {
        VarSet(VAR_OBJ_GFX_ID_D, gSaveBlock2Ptr->pokemonAvatarSpecies + OBJ_EVENT_MON + OBJ_EVENT_MON_SHINY);
    }
    else
    {
        VarSet(VAR_OBJ_GFX_ID_D, gSaveBlock2Ptr->pokemonAvatarSpecies + OBJ_EVENT_MON);
    }
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

EWRAM_DATA u8 gPlayerTransformEffectActive = FALSE;
#define unlockFieldControls data[0]

void BeginPlayerTransformEffect(u8 type, bool8 unlockPlayerFieldControls)
{
    struct Sprite *sprite = &gSprites[gPlayerAvatar.spriteId];
    if (sprite)
    {
        sprite->data[0] = 0; 
        sprite->data[1] = type; 
        sprite->oam.priority = 2; 
        gPlayerTransformEffectActive = TRUE; 
        u8 taskId = CreateTask(UpdatePlayerTransformAnimation, 0xFF);
        gTasks[taskId].unlockFieldControls = unlockPlayerFieldControls;
    }
}

void EndPlayerTransformAnimation(struct Sprite *sprite, u8 taskId)
{
    gPlayerTransformEffectActive = FALSE;
    REG_MOSAIC = 0;
    sprite->oam.mosaic = FALSE;
    sprite->oam.priority = 2;
    sprite->data[0] = 0;
    sprite->data[1] = 0;

    struct ObjectEvent *playerObjectEvent = &gObjectEvents[gPlayerAvatar.objectEventId];
    ObjectEventSetGraphicsId(playerObjectEvent, GetPlayerAvatarGraphicsIdByStateId(PLAYER_AVATAR_STATE_NORMAL));
    ObjectEventTurn(playerObjectEvent, playerObjectEvent->movementDirection);
    SetPlayerAvatarStateMask(PLAYER_AVATAR_FLAG_ON_FOOT);
    ObjectEventSetHeldMovement(playerObjectEvent, GetFaceDirectionMovementAction(playerObjectEvent->facingDirection));
    if (gTasks[taskId].unlockFieldControls)
    {
        gPlayerAvatar.preventStep = FALSE;
        UnlockPlayerFieldControls();
    }
    return DestroyTask(taskId);
}

#undef unlockFieldControls

// Main update logic for the player transform effect 
void UpdatePlayerTransformAnimation(u8 taskId)
{
    struct ObjectEvent *playerObjectEvent = &gObjectEvents[gPlayerAvatar.objectEventId];
    struct Sprite *sprite = &gSprites[gPlayerAvatar.spriteId];
    u8 frames = sprite->data[0];
    u8 stretch;

    sprite->oam.mosaic = TRUE;

    if (frames < 8)
        stretch = frames >> 1;
    else if (frames < 16)
        stretch = (16 - frames) >> 1;
    else // Animation finished
        return EndPlayerTransformAnimation(sprite, taskId);

    SetGpuReg(REG_OFFSET_MOSAIC, (stretch << 12) | (stretch << 8));

    if (frames == 8)
        ObjectEventSetGraphicsId(playerObjectEvent, GetPlayerAvatarGraphicsIdByStateId(PLAYER_AVATAR_STATE_NORMAL));
    
    sprite->data[0]++; // Increment frames
}

static u8 IsSpeciesValidTransformation(u16 speciesId)
{
    switch (speciesId)
    {
        case SPECIES_CASTFORM:
        case SPECIES_CASTFORM_RAINY:
        case SPECIES_CASTFORM_SUNNY:
        case SPECIES_CASTFORM_SNOWY:
            DebugPrintfLevel(MGBA_LOG_WARN, "Got valid species %d", speciesId);
            return TRUE;
        default:
            DebugPrintfLevel(MGBA_LOG_WARN, "No valid species");
            return FALSE;
    }
}

u16 GetValidTransformationSpeciesFromParty(u8 partyId)
{
    if (partyId >= gPartiesCount[B_TRAINER_PLAYER])
        return SPECIES_NONE;

    u16 speciesId = GetMonData(&gParties[B_TRAINER_PLAYER][partyId], MON_DATA_SPECIES);

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

void TransformCastformBoxMon(u16 targetSpecies)
{
    if (!IsSpeciesValidTransformation(targetSpecies))
        return;

    struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][0];
    u16 castformForm = gTransformations[targetSpecies].battleSpecies;

    SetMonData(mon, MON_DATA_SPECIES, &castformForm);
    for (u32 i = 0; i < MAX_MON_MOVES; i++)
        SetMonMoveSlot(mon, gTransformations[targetSpecies].moves[i], i);
    u32 abilityNum = 0; // gave the mons only one ability
    SetMonData(mon, MON_DATA_ABILITY_NUM, &abilityNum);
    CalculateXformStats(mon);
}

void SetPlayerAvatarFromScript(struct ScriptContext *ctx)
{
    u16 speciesId = SpeciesToNationalPokedexNum(VarGet(ScriptReadHalfword(ctx)));

    if (!IsSpeciesValidTransformation(speciesId))
        return;

    gSaveBlock2Ptr->pokemonAvatarSpecies = speciesId;
    VarSet(VAR_TRANSFORM_MON, speciesId); 

    DebugPrintfLevel(MGBA_LOG_WARN, "Set VAR_TRANSFORM_MON to %d", VarGet(VAR_TRANSFORM_MON));

    if (PlayerIsCastform())
        TransformCastformBoxMon(speciesId);

    BeginPlayerTransformEffect(TRANSFORM_TYPE_PLAYER_SPECIES, TRUE);
    PlaySE(SE_M_TELEPORT);
}

void SetPlayerAvatarTransformation(u16 speciesId, bool8 UnlockPlayerFieldControls)
{
    if (!IsSpeciesValidTransformation(speciesId))
        return;

    gSaveBlock2Ptr->pokemonAvatarSpecies = speciesId;
    VarSet(VAR_TRANSFORM_MON, speciesId); 
    
    DebugPrintfLevel(MGBA_LOG_WARN, "Set VAR_TRANSFORM_MON to %d", VarGet(VAR_TRANSFORM_MON));
    if (PlayerIsCastform())
        TransformCastformBoxMon(speciesId);
        
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
    DebugPrintfLevel(MGBA_LOG_WARN, "Attempting to Blit Species %d", speciesId);
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
