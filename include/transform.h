#ifndef GUARD_TRANSFORM_H
#define GUARD_TRANSFORM_H

bool32 PlayerIsCastform(void);
void BeginPlayerTransformEffect(u8 type, bool8 unlockPlayerFieldControls);
u16 GetValidTransformationSpeciesFromParty(u8 partyId);
u8 BlitTransformationIconToWindow(u16 speciesId, u8 windowId, u16 x, u16 y, void *paletteDest);

void TryCreatePokemonAvatarSpriteBob(void);
void Task_CreatePokemonAvatarBob(u8 taskId);
void Task_PokemonAvatar_HandleBob(u8 taskId);
void UpdatePlayerTransformAnimation(u8 taskId);

u16 ReturnAvatarGraphicsId(u16 avatarId);
u16 ReturnAvatarTrainerFrontPicId(u16 avatarId);
u16 ReturnAvatarTrainerBackPicId(u16 avatarId);

typedef void (*TransformFunc)(u8);

void SetPlayerAvatarTransformation(u16 speciesId, bool8 UnlockPlayerFieldControls);
void TrySetPlayerAvatarTransformation(u16 speciesId, bool8 UnlockPlayerFieldControls);
void SetPlayerAvatarSurfTransformation(u16 speciesId, bool8 UnlockPlayerFieldControls);
void SetPlayerAvatarStopSurfTransformation(u16 speciesId, bool8 UnlockPlayerFieldControls);
TransformFunc GetTransformationFunc(u16 speciesId);
u16 GetTransformationMoves(u16 speciesId, u8 i);
u16 GetTransformationAbility(u16 speciesId);
u16 GetTransformationBattleSpecies(u16 speciesId);
u16 GetTransformationWarpMap(u16 speciesId);
u16 GetCurrentTransformationSpecies(void);

#define TRANSFORM_TYPE_PLAYER_SPECIES 1
#define AVATAR_POKEMON_CHOICE 1

// choose type of mosaic effect for transformation
#define TRANSFORM_ANIM_SPRITE 0
#define TRANSFORM_ANIM_SCREEN 1
#define TRANSFORM_ANIM_TYPE   TRANSFORM_ANIM_SCREEN

// transformation animation constants
#if TRANSFORM_ANIM_TYPE == TRANSFORM_ANIM_SCREEN
  #define TRANSFORM_ANIM_TOTAL_FRAMES 48
  #define TRANSFORM_ANIM_SWAP_FRAME 24
  #define TRANSFORM_ANIM_MAX_STRETCH 12
#else
  #define TRANSFORM_ANIM_TOTAL_FRAMES 16
  #define TRANSFORM_ANIM_SWAP_FRAME 8
  #define TRANSFORM_ANIM_MAX_STRETCH 4
#endif

extern EWRAM_DATA u8 gPlayerTransformEffectActive;

struct Transformation
{
    TransformFunc fieldUseFunc;
    u8 name[ITEM_NAME_LENGTH];
    const u32 *iconPic;
    const u16 *iconPalette;
    u16 battleSpecies;
    u16 ability;
    u16 moves[4];
    u16 targetMap;
};


u16 CountMyItemsAndEvents(void);
u16 CountFlagsInRange(u16 start_flag, u16 end_flag);
u16 CountSpecificFlags(const u16* flagArray, u16 numFlags);


#endif // GUARD_TRANSFORM_H