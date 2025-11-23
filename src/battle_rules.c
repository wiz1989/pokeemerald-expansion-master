#include "global.h"
#include "battle.h"
#include "battle_rules.h"
#include "battle_setup.h"
#include "event_data.h"
#include "malloc.h"
#include "random.h"
#include "constants/abilities.h"
#include "constants/battle_rules.h"

static bool8 IsInArray(u8 value, const u8 *array, u8 size);
static bool8 IsBossRule(u8 battleRule);

#define INVALID_TYPES_COUNT ARRAY_COUNT(sInvalidTypes)
static const u8 sInvalidTypes[] = 
{
    TYPE_MYSTERY,
    TYPE_NONE,
    TYPE_STELLAR,
    TYPE_FAIRY
};

#define BATTLE_RULES_COUNT ARRAY_COUNT(gBattleRules)
const struct BattleRule gBattleRules[] = 
{
    [BATTLERULE_BANNEDTYPE] =
    {
        .weight = 1,
        .enabled = TRUE,
        .category = BATTLERULE_CATEGORY_SENDOUT,
    },
    [BATTLERULE_BANNEDMOVETYPE] =
    {
        .weight = 1,
        .enabled = TRUE,
        .category = BATTLERULE_CATEGORY_USEMOVE,
    },
    [BATTLERULE_NOHEALING] =
    {
        .weight = 1,
        .enabled = TRUE,
        .category = BATTLERULE_CATEGORY_MULTIPLE,
    },
    [BATTLERULE_NOCRITS] =
    {
        .weight = 1,
        .enabled = TRUE,
        .category = BATTLERULE_CATEGORY_MOVEEFFECT,
    },
    [BATTLERULE_NORECOIL] =
    {
        .weight = 1,
        .enabled = TRUE,
        .category = BATTLERULE_CATEGORY_MOVEEFFECT,
    },
    [BATTLERULE_NOSTAB] =
    {
        .weight = 1,
        .enabled = TRUE,
        .category = BATTLERULE_CATEGORY_USEMOVE,
    },
    [BATTLERULE_ONLYSTAB] =
    {
        .weight = 1,
        .enabled = TRUE,
        .category = BATTLERULE_CATEGORY_USEMOVE,
    },
    [BATTLERULE_NOSUPEREFFECTIVE] =
    {
        .weight = 1,
        .enabled = TRUE,
        .category = BATTLERULE_CATEGORY_USEMOVE,
    },
    [BATTLERULE_1HP] =
    {
        .weight = 1,
        .enabled = FALSE, // rule is too impactful
        .category = BATTLERULE_CATEGORY_GENERAL,
    },
    [BATTLERULE_1PP] =
    {
        .weight = 1,
        .enabled = TRUE,
        .category = BATTLERULE_CATEGORY_GENERAL,
    },
    [BATTLERULE_NOSAMESEX] =
    {
        .weight = 1,
        .enabled = TRUE,
        .category = BATTLERULE_CATEGORY_SENDOUT,
    },
    [BATTLERULE_NOSWITCHING] =
    {
        .weight = 1,
        .enabled = TRUE,
        .category = BATTLERULE_CATEGORY_SWITCHOUT,
    },
    [BATTLERULE_PERISHCOUNT] =
    {
        .weight = 1,
        .enabled = TRUE,
        .category = BATTLERULE_CATEGORY_GENERAL,
    },
    [BATTLERULE_SWITCHMOVES] =
    {
        .weight = 1,
        .enabled = TRUE,
        .category = BATTLERULE_CATEGORY_USEMOVE,
    },
    [BATTLERULE_NOPRIO] =
    {
        .weight = 1,
        .enabled = TRUE,
        .category = BATTLERULE_CATEGORY_USEMOVE,
    },
    [BATTLERULE_NOHELDITEMS] =
    {
        .weight = 1,
        .enabled = TRUE,
        .category = BATTLERULE_CATEGORY_ACTIVATE_ITEM,
    },
    [BATTLERULE_NOABILITY] =
    {
        .weight = 1,
        .enabled = TRUE,
        .category = BATTLERULE_CATEGORY_ACTIVATE_ABILITY,
    },
    [BATTLERULE_NOSTATUS] =
    {
        .weight = 1,
        .enabled = TRUE,
        .category = BATTLERULE_CATEGORY_MOVEEFFECT,
    },
    // [BATTLERULE_SHAREDDAMAGE] =
    // {
    //     .weight = 1,
    //     .enabled = FALSE,
    //     .category = BATTLERULE_CATEGORY_GENERAL,
    // },
    [BATTLERULE_NOSETUP] =
    {
        .weight = 1,
        .enabled = TRUE,
        .category = BATTLERULE_CATEGORY_USEMOVE,
    },
    [BATTLERULE_TRICKROOM] =
    {
        .weight = 1,
        .enabled = TRUE,
        .category = BATTLERULE_CATEGORY_GENERAL,
    },
    [BATTLERULE_BANNEDMOVECAT_PHYSICAL] =
    {
        .weight = 1,
        .enabled = TRUE,
        .category = BATTLERULE_CATEGORY_USEMOVE,
    },
    [BATTLERULE_BANNEDMOVECAT_SPECIAL] =
    {
        .weight = 1,
        .enabled = TRUE,
        .category = BATTLERULE_CATEGORY_USEMOVE,
    },
    [BATTLERULE_BANNEDMOVECAT_STATUS] =
    {
        .weight = 1,
        .enabled = TRUE,
        .category = BATTLERULE_CATEGORY_USEMOVE,
    },
    [BATTLERULE_INVERSE] =
    {
        .weight = 1,
        .enabled = TRUE,
        .category = BATTLERULE_CATEGORY_GENERAL,
    },
    [BATTLERULE_FIRSTMOVEONLY] =
    {
        .weight = 1,
        .enabled = TRUE,
        .category = BATTLERULE_CATEGORY_USEMOVE,
    },
    [BATTLERULE_TRUANT] =
    {
        .weight = 1,
        .enabled = TRUE,
        .category = BATTLERULE_CATEGORY_GENERAL,
    },
    [BATTLERULE_NOMISSES] =
    {
        .weight = 1,
        .enabled = TRUE,
        .category = BATTLERULE_CATEGORY_MOVEEFFECT,
    }
};

u8 GetBattleRuleCount(void)
{
    return BATTLE_RULES_COUNT;
}

void IncrementBattleRuleRerollCounter(void)
{
    gSaveBlock1Ptr->battleRuleRerollCounter++;
    if (gSaveBlock1Ptr->battleRuleRerollCounter > 65000)
        gSaveBlock1Ptr->battleRuleRerollCounter = 0;
}

void IncrementTypeRerollCounter(void)
{
    gSaveBlock1Ptr->typeRerollCounter++;
    if (gSaveBlock1Ptr->typeRerollCounter > 250)
        gSaveBlock1Ptr->typeRerollCounter = 0;

    //reset random type for all trainers
    for (int i = 0; i < TRAINERS_COUNT; i++)
    {
        gSaveBlock2Ptr->randomSpeciesType[i] = TYPE_NONE;
        gSaveBlock3Ptr->randomMoveType[i] = TYPE_NONE;
    }
}

u8 GetRandomBattleRuleSeeded(void)
{
    u16 value = 0;
    u16 trainerId = (TRAINER_FLAGS_START + gSaveBlock1Ptr->lastTrainerId);
    u32 increment = 0;
    u16 maxAttempts = 1000;

    FlagClear(FLAG_INVERSE_BATTLE);

    value = RandomSeededModulo2(trainerId + GetTrainerClassFromId(gSaveBlock1Ptr->lastTrainerId) + gSaveBlock1Ptr->battleRuleRerollCounter, BATTLE_RULES_COUNT);

    while ((!gBattleRules[value].enabled || (IsDoubleBattle() && value == BATTLERULE_NOSAMESEX)
        || (B_BOSS_LIMITED_RULES && !IsBossRule(value) && IsBossTrainer(gSaveBlock1Ptr->lastTrainerId))) && increment < maxAttempts)
    {
        increment++;
        value = RandomSeededModulo2(trainerId + GetTrainerClassFromId(gSaveBlock1Ptr->lastTrainerId) + gSaveBlock1Ptr->battleRuleRerollCounter + increment, BATTLE_RULES_COUNT);
        // DebugPrintf("--- new rule %d ---", value);
    }

    // Fallback: if we reached max attempts or the final value is still invalid, use a safe default rule (none).
    if (increment >= maxAttempts)
    {
        DebugPrintf("--- Battle rule reroll limit reached or invalid final rule, using fallback NONE ---");
        value = BATTLERULE_NONE;
    }

    // value = BATTLERULE_BANNEDTYPE; // test line

    // battle debug
    if (FlagGet(FLAG_DEBUG_BATTLERULE))
    {
        value = gSaveBlock1Ptr->debugBattleRule;
    }

    // deactivate for Wild Battles and First Battle
    if ((!(gBattleTypeFlags & BATTLE_TYPE_TRAINER) || (gBattleTypeFlags & BATTLE_TYPE_FIRST_BATTLE))
      && !FlagGet(FLAG_DEBUG_BATTLERULE))
        value = BATTLERULE_NONE;

    // set fixed rule for tutorial battle
    if ((gBattleTypeFlags & BATTLE_TYPE_FIRST_BATTLE_RIVAL)
      && !FlagGet(FLAG_DEBUG_BATTLERULE))
        value = BATTLERULE_NOCRITS;
    
    // DebugPrintf("--- Random Battle Rule: %d ---", value);

    if (value == BATTLERULE_INVERSE)
        FlagSet(FLAG_INVERSE_BATTLE);

    return value;
}

u8 GetRandomSpeciesTypeSeeded(void)
{
    u16 value = 0;
    u16 trainerId = (TRAINER_FLAGS_START + gSaveBlock1Ptr->lastTrainerId);
    u32 increment = 0;

    value = gSaveBlock2Ptr->randomSpeciesType[gSaveBlock1Ptr->lastTrainerId];

    if (value == TYPE_NONE || REROLL_EACH_BATTLE)
    {
        value = RandomSeededModulo2(trainerId + GetTrainerClassFromId(gSaveBlock1Ptr->lastTrainerId) + gSaveBlock1Ptr->typeRerollCounter, NUMBER_OF_MON_TYPES);

        //get current party types
        u8 *party_types = AllocZeroed(NUMBER_OF_MON_TYPES * sizeof(u8));
        for (int i = 0; i < PARTY_SIZE; i++)
        {
            if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES) != SPECIES_NONE  && !GetMonData(&gPlayerParty[i], MON_DATA_IS_EGG))
            {
                u8 type1 = gSpeciesInfo[GetMonData(&gPlayerParty[i], MON_DATA_SPECIES)].types[0];
                u8 type2 = gSpeciesInfo[GetMonData(&gPlayerParty[i], MON_DATA_SPECIES)].types[1];
                party_types[type1] = TRUE;
                party_types[type2] = TRUE;
            }
        }

        while (IsInArray(value, sInvalidTypes, INVALID_TYPES_COUNT) || party_types[value] == FALSE)
        {
            increment++;
            value = RandomSeededModulo2(trainerId + GetTrainerClassFromId(gSaveBlock1Ptr->lastTrainerId) + gSaveBlock1Ptr->typeRerollCounter + increment, NUMBER_OF_MON_TYPES);
        }

        gSaveBlock2Ptr->randomSpeciesType[gSaveBlock1Ptr->lastTrainerId] = value;
        
        // Cleanup
        Free(party_types);
    }

    // value = TYPE_NORMAL; // test line

    // battle debug
    if (FlagGet(FLAG_DEBUG_RANDOMSPECIESTYPE))
    {
        value = gSaveBlock2Ptr->DebugRandomSpeciesType;
    }
    
    // DebugPrintf("--- Random Type is %d ---", value);
    return value;
}

u8 GetRandomMoveTypeSeeded(void)
{
    u16 value = 0;
    u16 trainerId = (TRAINER_FLAGS_START + gSaveBlock1Ptr->lastTrainerId);
    u32 increment = 0;

    value = gSaveBlock3Ptr->randomMoveType[gSaveBlock1Ptr->lastTrainerId];

    if (value == TYPE_NONE || REROLL_EACH_BATTLE)
    {
        value = RandomSeededModulo2(trainerId + GetTrainerClassFromId(gSaveBlock1Ptr->lastTrainerId) + gSaveBlock1Ptr->typeRerollCounter, NUMBER_OF_MON_TYPES);

        //get current party move types
        u8 *party_movetypes = AllocZeroed(NUMBER_OF_MON_TYPES * sizeof(u8));
        for (int i = 0; i < PARTY_SIZE; i++)
        {
            if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES) != SPECIES_NONE  && !GetMonData(&gPlayerParty[i], MON_DATA_IS_EGG))
            {
                for (u8 slot = 0; slot < MAX_MON_MOVES; slot++)
                {
                    u8 type = gMovesInfo[GetMonData(&gPlayerParty[i], MON_DATA_MOVE1 + slot)].type;
                    party_movetypes[type] = TRUE;
                }
            }
        }

        while (IsInArray(value, sInvalidTypes, INVALID_TYPES_COUNT) || party_movetypes[value] == FALSE)
        {
            increment++;
            value = RandomSeededModulo2(trainerId + GetTrainerClassFromId(gSaveBlock1Ptr->lastTrainerId) + gSaveBlock1Ptr->typeRerollCounter + increment, NUMBER_OF_MON_TYPES);
        }

        gSaveBlock3Ptr->randomMoveType[gSaveBlock1Ptr->lastTrainerId] = value;
        
        // Cleanup
        Free(party_movetypes);
    }

    // value = TYPE_NORMAL; // test line

    // battle debug
    if (FlagGet(FLAG_DEBUG_RANDOMMOVETYPE))
    {
        value = gSaveBlock2Ptr->DebugRandomMoveType;
    }
    
    // DebugPrintf("--- Random Type is %d ---", value);
    return value;
}

bool8 IsTruantBattleRule(u32 battler)
{
    if (GetRandomBattleRuleSeeded() == BATTLERULE_TRUANT && IsOnPlayerSide(battler)
      && GetBattlerAbility(battler) != ABILITY_TRUANT)
        return TRUE;
    else
        return FALSE;
}

static bool8 IsInArray(u8 value, const u8 *array, u8 size)
{
    for (int i = 0; i < size; i++) {
        if (value == array[i]) {
            return TRUE;
        }
    }
    return FALSE;
}

static bool8 IsBossRule(u8 battleRule)
{
    switch (battleRule)
    {
        case BATTLERULE_BANNEDTYPE:
        case BATTLERULE_NOHEALING:
        case BATTLERULE_NOSTAB:
        case BATTLERULE_NOSUPEREFFECTIVE:
        case BATTLERULE_NOSWITCHING:
        case BATTLERULE_PERISHCOUNT:
        case BATTLERULE_SWITCHMOVES:
        case BATTLERULE_1HP:
        case BATTLERULE_1PP:
        case BATTLERULE_TRICKROOM:
        case BATTLERULE_BANNEDMOVECAT_PHYSICAL:
        case BATTLERULE_BANNEDMOVECAT_SPECIAL:
        case BATTLERULE_BANNEDMOVECAT_STATUS:
        case BATTLERULE_INVERSE:
        case BATTLERULE_FIRSTMOVEONLY:
        case BATTLERULE_TRUANT:
            return TRUE;
        default:
            return FALSE;
    }
}
