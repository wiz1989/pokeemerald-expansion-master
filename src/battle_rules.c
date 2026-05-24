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
static bool8 IsRandomTypeRule(u8 rule);
static bool8 IsBannedMoveCatRule(u8 rule);
static bool8 IsValidPairing(u8 value, const u8 *excluded, u8 excludedCount);
static u8 PickNextRule(u32 baseSeed, u32 startIncrement, u8 *excluded, u8 excludedCount, u32 *outIncrement, bool8 excludeBossRules);

u8 gActiveBattleRules[MAX_CONCURRENT_RULES];
u8 gBattleRuleViolated = BATTLERULE_NONE;

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

static bool8 IsRandomTypeRule(u8 rule)
{
    return (rule == BATTLERULE_BANNEDTYPE || rule == BATTLERULE_BANNEDMOVETYPE);
}

static bool8 IsBannedMoveCatRule(u8 rule)
{
    return (rule == BATTLERULE_BANNEDMOVECAT_PHYSICAL
         || rule == BATTLERULE_BANNEDMOVECAT_SPECIAL
         || rule == BATTLERULE_BANNEDMOVECAT_STATUS);
}

// handles mutually-exclusive rule combinations
static bool8 IsValidPairing(u8 value, const u8 *excluded, u8 excludedCount)
{
    // type dependant rules like BATTLERULE_BANNEDTYPE and BATTLERULE_BANNEDMOVETYPE cannot coexist
    if (IsRandomTypeRule(value)
     && (IsInArray(BATTLERULE_BANNEDTYPE, excluded, excludedCount)
      || IsInArray(BATTLERULE_BANNEDMOVETYPE, excluded, excludedCount)))
        return FALSE;

    // BATTLERULE_NOSTAB and BATTLERULE_ONLYSTAB combination
    if ((value == BATTLERULE_NOSTAB && IsInArray(BATTLERULE_ONLYSTAB, excluded, excludedCount))
     || (value == BATTLERULE_ONLYSTAB && IsInArray(BATTLERULE_NOSTAB, excluded, excludedCount)))
        return FALSE;

    // BATTLERULE_SWITCHMOVES and BATTLERULE_FIRSTMOVEONLY combination
    if ((value == BATTLERULE_SWITCHMOVES && IsInArray(BATTLERULE_FIRSTMOVEONLY, excluded, excludedCount))
     || (value == BATTLERULE_FIRSTMOVEONLY && IsInArray(BATTLERULE_SWITCHMOVES, excluded, excludedCount)))
        return FALSE;

    // BATTLERULE_BANNEDMOVECAT_* rules cannot coexist with each other
    if (IsBannedMoveCatRule(value)
     && (IsInArray(BATTLERULE_BANNEDMOVECAT_PHYSICAL, excluded, excludedCount)
      || IsInArray(BATTLERULE_BANNEDMOVECAT_SPECIAL, excluded, excludedCount)
      || IsInArray(BATTLERULE_BANNEDMOVECAT_STATUS, excluded, excludedCount)))
        return FALSE;

    // BATTLERULE_NOSTAB + BATTLERULE_NOSUPEREFFECTIVE would remove any offensive multipliers
    if ((value == BATTLERULE_NOSTAB && IsInArray(BATTLERULE_NOSUPEREFFECTIVE, excluded, excludedCount))
     || (value == BATTLERULE_NOSUPEREFFECTIVE && IsInArray(BATTLERULE_NOSTAB, excluded, excludedCount)))
        return FALSE;

    // BATTLERULE_PERISHCOUNT + BATTLERULE_NOSWITCHING: guaranteed faint with no counterplay lol
    if ((value == BATTLERULE_PERISHCOUNT && IsInArray(BATTLERULE_NOSWITCHING, excluded, excludedCount))
     || (value == BATTLERULE_NOSWITCHING && IsInArray(BATTLERULE_PERISHCOUNT, excluded, excludedCount)))
        return FALSE;

    // BATTLERULE_INVERSE + BATTLERULE_NOSUPEREFFECTIVE: that's fucked up too... surprise, surprise!
    if ((value == BATTLERULE_INVERSE && IsInArray(BATTLERULE_NOSUPEREFFECTIVE, excluded, excludedCount))
     || (value == BATTLERULE_NOSUPEREFFECTIVE && IsInArray(BATTLERULE_INVERSE, excluded, excludedCount)))
        return FALSE;

    // BATTLERULE_TRUANT + BATTLERULE_NOSWITCHING: stuck with a half-speed attacker that can't be rotated out
    if ((value == BATTLERULE_TRUANT && IsInArray(BATTLERULE_NOSWITCHING, excluded, excludedCount))
     || (value == BATTLERULE_NOSWITCHING && IsInArray(BATTLERULE_TRUANT, excluded, excludedCount)))
        return FALSE;

    // BATTLERULE_1PP + BATTLERULE_FIRSTMOVEONLY: one use of the only available move, then Struggle for the rest of the battle
    if ((value == BATTLERULE_1PP && IsInArray(BATTLERULE_FIRSTMOVEONLY, excluded, excludedCount))
     || (value == BATTLERULE_FIRSTMOVEONLY && IsInArray(BATTLERULE_1PP, excluded, excludedCount)))
        return FALSE;

    // BATTLERULE_ONLYSTAB + BATTLERULE_BANNEDMOVECAT_PHYSICAL/SPECIAL: could leave a mon with zero usable moves
    // uses two conditions to check both directions of the pairing
    if (value == BATTLERULE_ONLYSTAB
     && (IsInArray(BATTLERULE_BANNEDMOVECAT_PHYSICAL, excluded, excludedCount)
      || IsInArray(BATTLERULE_BANNEDMOVECAT_SPECIAL, excluded, excludedCount)))
        return FALSE;
    if ((value == BATTLERULE_BANNEDMOVECAT_PHYSICAL || value == BATTLERULE_BANNEDMOVECAT_SPECIAL)
     && IsInArray(BATTLERULE_ONLYSTAB, excluded, excludedCount))
        return FALSE;

    return TRUE;
}

// calculate battle rules based on the given input, skipping certain cases:
//  - already-included rules
//  - special pairing exceptions
//  - boss rule exceptions
// updates *outIncrement at the end (for multiple calls in case of multiple concurrent rules)
static u8 PickNextRule(u32 baseSeed, u32 startIncrement, u8 *excluded, u8 excludedCount, u32 *outIncrement, bool8 excludeBossRules)
{
    u16 value;
    u32 increment = startIncrement;
    u32 currentAttempts = 0;
    u16 maxAttempts = 1000;

    value = RandomSeededModulo2(baseSeed + increment, BATTLE_RULES_COUNT);

    while ((!gBattleRules[value].enabled // ignore disabled rules
        || (IsDoubleBattle() && value == BATTLERULE_NOSAMESEX)
        || (B_BOSS_LIMITED_RULES && !IsBossRule(value) && IsBossTrainer(gSaveBlock1Ptr->lastTrainerId))
        || (excludeBossRules && IsBossRule(value)) // one boss rule at max!
        || IsInArray(value, excluded, excludedCount) // rule was already picked in previous iteration
        || !IsValidPairing(value, excluded, excludedCount)) // handle special rule combination exceptions
        && currentAttempts < maxAttempts)
    {
        increment++;
        currentAttempts++;
        value = RandomSeededModulo2(baseSeed + increment, BATTLE_RULES_COUNT);
        // DebugPrintf("--- new rule %d ---", value);
    }

    // Fallback: if we reached max attempts or the final value is still invalid, use a safe default rule (none).
    if (currentAttempts >= maxAttempts)
    {
        DebugPrintf("--- Battle rule reroll limit reached, using fallback NONE ---");
        value = BATTLERULE_NONE;
    }

    *outIncrement = increment + 1;
    return value;
}

// calculate current battle rules based on a Trainer ID seed
void ComputeActiveBattleRules(void)
{
    u8 i;
    u32 baseSeed = (u32)(TRAINER_FLAGS_START + gSaveBlock1Ptr->lastTrainerId)
                 + GetTrainerClassFromId(gSaveBlock1Ptr->lastTrainerId)
                 + gSaveBlock1Ptr->battleRuleRerollCounter;
    u8 count = gSaveBlock2Ptr->concurrentRules + 1;
    u32 nextIncrement = 0;
    bool8 bossRulePicked = FALSE;

    // Boss trainers always get exactly one rule (from the harder boss pool)
    if (IsBossTrainer(gSaveBlock1Ptr->lastTrainerId))
        count = 1;

    FlagClear(FLAG_INVERSE_BATTLE);

    // reset gActiveBattleRules before calculation
    for (i = 0; i < MAX_CONCURRENT_RULES; i++)
        gActiveBattleRules[i] = BATTLERULE_NONE;

    // calculate gActiveBattleRules based on how many concurrent rules are currently set
    for (i = 0; i < count; i++)
    {
        // PickNextRule() gets an increment value and updates this value for the next call, ensuring different results
        // required for special handling of concurrent rules and boss rules
        gActiveBattleRules[i] = PickNextRule(baseSeed, nextIncrement, gActiveBattleRules, i, &nextIncrement, bossRulePicked);
        if (IsBossRule(gActiveBattleRules[i]))
            bossRulePicked = TRUE;
    }

    // gActiveBattleRules[0] = BATTLERULE_BANNEDTYPE; // test line
    // gActiveBattleRules[1] = BATTLERULE_NONE; // test line
    // gActiveBattleRules[2] = BATTLERULE_NONE; // test line

    
    // ### post handling of calculated rules below ###

    // battle debug
    if (FlagGet(FLAG_DEBUG_BATTLERULE))
    {
        for (i = 0; i < MAX_CONCURRENT_RULES; i++)
            gActiveBattleRules[i] = gSaveBlock1Ptr->debugBattleRule[i];
    }

    // deactivate for Wild Battles and First Battle
    if ((!(gBattleTypeFlags & BATTLE_TYPE_TRAINER) || (gBattleTypeFlags & BATTLE_TYPE_FIRST_BATTLE))
      && !FlagGet(FLAG_DEBUG_BATTLERULE))
    {
        for (i = 0; i < MAX_CONCURRENT_RULES; i++)
            gActiveBattleRules[i] = BATTLERULE_NONE;
    }

    // set fixed rule for tutorial battle
    if ((gBattleTypeFlags & BATTLE_TYPE_FIRST_BATTLE_RIVAL)
      && !FlagGet(FLAG_DEBUG_BATTLERULE))
    {
        gActiveBattleRules[0] = BATTLERULE_NOCRITS;
        for (i = 1; i < MAX_CONCURRENT_RULES; i++)
            gActiveBattleRules[i] = BATTLERULE_NONE;
    }

    // Set inverse battle flag if any active rule is BATTLERULE_INVERSE
    for (i = 0; i < MAX_CONCURRENT_RULES; i++)
    {
        if (gActiveBattleRules[i] == BATTLERULE_INVERSE)
        {
            FlagSet(FLAG_INVERSE_BATTLE);
            break;
        }
    }
}

bool8 IsActiveBattleRule(u8 rule)
{
    u8 i;

    ComputeActiveBattleRules(); // recalc every time, no matter the current state. ToDo: check for performance!
    
    for (i = 0; i < MAX_CONCURRENT_RULES; i++)
    {
        if (gActiveBattleRules[i] == rule)
            return TRUE;
    }
    
    return FALSE;
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
            if (i == 1 && Random() % 2 == 0) // in 50% of the cases, only check first mon
                break;
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
    if (IsActiveBattleRule(BATTLERULE_TRUANT) && IsOnPlayerSide(battler)
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
        // case BATTLERULE_1HP:
        // case BATTLERULE_1PP:
        case BATTLERULE_TRICKROOM:
        case BATTLERULE_BANNEDMOVECAT_PHYSICAL:
        case BATTLERULE_BANNEDMOVECAT_SPECIAL:
        case BATTLERULE_BANNEDMOVECAT_STATUS:
        case BATTLERULE_INVERSE:
        // case BATTLERULE_FIRSTMOVEONLY:
        case BATTLERULE_TRUANT:
            return TRUE;
        default:
            return FALSE;
    }
}
