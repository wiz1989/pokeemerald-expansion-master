#include "global.h"
#include "battle.h"
#include "battle_rules.h"
#include "battle_setup.h"
#include "event_data.h"
#include "malloc.h"
#include "new_game.h"
#include "random.h"
#include "constants/abilities.h"
#include "constants/battle_rules.h"

static bool8 IsInArray(u8 value, const u8 *array, u8 size);
static bool8 IsRandomTypeRule(u8 rule);
static bool8 IsBannedMoveCatRule(u8 rule);
static u8 GetRuleImpactValue(u8 rule);
static bool8 IsValidPairing(u8 value, const u8 *excluded, u8 excludedCount);
static u8 PickNextBossRule(void);
static void CalculateActiveBattleRules(void);
static bool8 IsBattleRuleAvailable(u8 rule);

u8 gActiveBattleRules[MAX_CONCURRENT_RULES];
bool8 gBattleRulesInitialized = FALSE;
u8 gBattleRuleViolated = BATTLERULE_NONE;

#define SEED_MULTIPLIER 2654435761u // Knuth's constant

static const u8 sBossRules[] =
{
    BATTLERULE_BANNEDTYPE,
    BATTLERULE_NOHEALING,
    BATTLERULE_NOSTAB,
    BATTLERULE_NOSUPEREFFECTIVE,
    BATTLERULE_NOSWITCHING,
    BATTLERULE_PERISHCOUNT,
    BATTLERULE_SWITCHMOVES,
    BATTLERULE_TRICKROOM,
    BATTLERULE_BANNEDMOVECAT_PHYSICAL,
    BATTLERULE_BANNEDMOVECAT_SPECIAL,
    BATTLERULE_BANNEDMOVECAT_STATUS,
    BATTLERULE_INVERSE,
    BATTLERULE_TRUANT,
};

#define INVALID_TYPES_COUNT ARRAY_COUNT(sInvalidTypes)
static const u8 sInvalidTypes[] = 
{
    TYPE_MYSTERY,
    TYPE_NONE,
    TYPE_STELLAR,
    TYPE_FAIRY
};

#define IMPACT_LOW     1
#define IMPACT_MED     2
#define IMPACT_HIGH    3
#define IMPACT_HIGHEST 4

#define BATTLE_RULES_COUNT ARRAY_COUNT(gBattleRules)
const struct BattleRule gBattleRules[] = 
{
    [BATTLERULE_BANNEDTYPE] =
    {
        .impact = IMPACT_HIGH,
        .enabled = TRUE,
        .category = BATTLERULE_CATEGORY_SENDOUT,
    },
    [BATTLERULE_BANNEDMOVETYPE] =
    {
        .impact = IMPACT_MED,
        .enabled = TRUE,
        .category = BATTLERULE_CATEGORY_USEMOVE,
    },
    [BATTLERULE_NOHEALING] =
    {
        .impact = IMPACT_LOW,
        .enabled = TRUE,
        .category = BATTLERULE_CATEGORY_MULTIPLE,
    },
    [BATTLERULE_NOCRITS] =
    {
        .impact = IMPACT_MED,
        .enabled = TRUE,
        .category = BATTLERULE_CATEGORY_MOVEEFFECT,
    },
    [BATTLERULE_NORECOIL] =
    {
        .impact = IMPACT_LOW,
        .enabled = TRUE,
        .category = BATTLERULE_CATEGORY_MOVEEFFECT,
    },
    [BATTLERULE_NOSTAB] =
    {
        .impact = IMPACT_HIGH,
        .enabled = TRUE,
        .category = BATTLERULE_CATEGORY_USEMOVE,
    },
    [BATTLERULE_ONLYSTAB] =
    {
        .impact = IMPACT_HIGH,
        .enabled = TRUE,
        .category = BATTLERULE_CATEGORY_USEMOVE,
    },
    [BATTLERULE_NOSUPEREFFECTIVE] =
    {
        .impact = IMPACT_HIGH,
        .enabled = TRUE,
        .category = BATTLERULE_CATEGORY_USEMOVE,
    },
    [BATTLERULE_1HP] =
    {
        .impact = IMPACT_HIGH,
        .enabled = FALSE, // rule is too impactful
        .category = BATTLERULE_CATEGORY_GENERAL,
    },
    [BATTLERULE_1PP] =
    {
        .impact = IMPACT_HIGHEST,
        .enabled = TRUE,
        .category = BATTLERULE_CATEGORY_GENERAL,
    },
    [BATTLERULE_NOSAMESEX] =
    {
        .impact = IMPACT_HIGHEST,
        .enabled = TRUE,
        .category = BATTLERULE_CATEGORY_SENDOUT,
    },
    [BATTLERULE_NOSWITCHING] =
    {
        .impact = IMPACT_HIGHEST,
        .enabled = TRUE,
        .category = BATTLERULE_CATEGORY_SWITCHOUT,
    },
    [BATTLERULE_PERISHCOUNT] =
    {
        .impact = IMPACT_MED,
        .enabled = TRUE,
        .category = BATTLERULE_CATEGORY_GENERAL,
    },
    [BATTLERULE_SWITCHMOVES] =
    {
        .impact = IMPACT_MED,
        .enabled = TRUE,
        .category = BATTLERULE_CATEGORY_USEMOVE,
    },
    [BATTLERULE_NOPRIO] =
    {
        .impact = IMPACT_LOW,
        .enabled = TRUE,
        .category = BATTLERULE_CATEGORY_USEMOVE,
    },
    [BATTLERULE_NOHELDITEMS] =
    {
        .impact = IMPACT_LOW,
        .enabled = TRUE,
        .category = BATTLERULE_CATEGORY_ACTIVATE_ITEM,
    },
    [BATTLERULE_NOABILITY] =
    {
        .impact = IMPACT_LOW,
        .enabled = TRUE,
        .category = BATTLERULE_CATEGORY_ACTIVATE_ABILITY,
    },
    [BATTLERULE_NOSTATUS] =
    {
        .impact = IMPACT_LOW,
        .enabled = TRUE,
        .category = BATTLERULE_CATEGORY_MOVEEFFECT,
    },
    // [BATTLERULE_SHAREDDAMAGE] =
    // {
    //     .impact = 1,
    //     .enabled = FALSE,
    //     .category = BATTLERULE_CATEGORY_GENERAL,
    // },
    [BATTLERULE_NOSETUP] =
    {
        .impact = IMPACT_LOW,
        .enabled = TRUE,
        .category = BATTLERULE_CATEGORY_USEMOVE,
    },
    [BATTLERULE_TRICKROOM] =
    {
        .impact = IMPACT_MED,
        .enabled = TRUE,
        .category = BATTLERULE_CATEGORY_GENERAL,
    },
    [BATTLERULE_BANNEDMOVECAT_PHYSICAL] =
    {
        .impact = IMPACT_HIGH,
        .enabled = TRUE,
        .category = BATTLERULE_CATEGORY_USEMOVE,
    },
    [BATTLERULE_BANNEDMOVECAT_SPECIAL] =
    {
        .impact = IMPACT_HIGH,
        .enabled = TRUE,
        .category = BATTLERULE_CATEGORY_USEMOVE,
    },
    [BATTLERULE_BANNEDMOVECAT_STATUS] =
    {
        .impact = IMPACT_HIGH,
        .enabled = TRUE,
        .category = BATTLERULE_CATEGORY_USEMOVE,
    },
    [BATTLERULE_INVERSE] =
    {
        .impact = IMPACT_HIGH,
        .enabled = TRUE,
        .category = BATTLERULE_CATEGORY_GENERAL,
    },
    [BATTLERULE_FIRSTMOVEONLY] =
    {
        .impact = IMPACT_HIGHEST,
        .enabled = TRUE,
        .category = BATTLERULE_CATEGORY_USEMOVE,
    },
    [BATTLERULE_TRUANT] =
    {
        .impact = IMPACT_HIGHEST,
        .enabled = TRUE,
        .category = BATTLERULE_CATEGORY_GENERAL,
    },
    [BATTLERULE_NOMISSES] =
    {
        .impact = IMPACT_LOW,
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
    // increment +10 to jump further in the seed sequence
    gSaveBlock1Ptr->battleRuleRerollCounter = (gSaveBlock1Ptr->battleRuleRerollCounter + 10);
    if (gSaveBlock1Ptr->battleRuleRerollCounter > 65000)
        gSaveBlock1Ptr->battleRuleRerollCounter = 0;
}

void IncrementBossRuleRerollCounter(void)
{
    gSaveBlock1Ptr->bossRuleRerollCounter++;
    if (gSaveBlock1Ptr->bossRuleRerollCounter > 50)
        gSaveBlock1Ptr->bossRuleRerollCounter = 0;
}

void ResetBossRuleRerollCounter(void)
{
    gSaveBlock1Ptr->bossRuleRerollCounter = 0;
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

static u8 GetRuleImpactValue(u8 rule)
{
    return gBattleRules[rule].impact;
}

static bool8 ArrayHoldsRuleAboveImpactValue(const u8 *array, u8 size, u8 impact)
{
    for (u8 i = 0; i < size; i++)
    {
        if (GetRuleImpactValue(array[i]) > impact)
            return TRUE;
    }
    return FALSE;
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

    // BATTLERULE_1PP must never coexist with any other rule - it's too influential on its own
    if (IsInArray(BATTLERULE_1PP, excluded, excludedCount))
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

    // BATTLERULE_FIRSTMOVEONLY + BATTLERULE_BANNEDMOVECAT_*: super unfair, could leave you with no viable move at all
    if (value == BATTLERULE_FIRSTMOVEONLY
     && (IsInArray(BATTLERULE_BANNEDMOVECAT_PHYSICAL, excluded, excludedCount)
      || IsInArray(BATTLERULE_BANNEDMOVECAT_SPECIAL, excluded, excludedCount)
      || IsInArray(BATTLERULE_BANNEDMOVECAT_STATUS, excluded, excludedCount)))
        return FALSE;
    if (IsBannedMoveCatRule(value) && IsInArray(BATTLERULE_FIRSTMOVEONLY, excluded, excludedCount))
        return FALSE;
    
    // FirstMoveOnly must only be paired with low impact rules
    if (value == BATTLERULE_FIRSTMOVEONLY
     && ArrayHoldsRuleAboveImpactValue(excluded, excludedCount, IMPACT_MED))
        return FALSE;
    if (GetRuleImpactValue(value) > IMPACT_MED
     && IsInArray(BATTLERULE_FIRSTMOVEONLY, excluded, excludedCount))
        return FALSE;

    return TRUE;
}

static u8 PickNextBossRule(void)
{
    u8 validRules[ARRAY_COUNT(sBossRules)];
    u8 validCount = 0;
    u8 i;
    u8 ruleIndex;
    u32 baseSeed = (u32)gSaveBlock1Ptr->lastTrainerId * SEED_MULTIPLIER
                 + gSaveBlock1Ptr->battleRuleRerollCounter
                 + gSaveBlock1Ptr->bossRuleRerollCounter
                 + GetTrainerId(gSaveBlock2Ptr->playerTrainerId);

    for (i = 0; i < ARRAY_COUNT(sBossRules); i++)
    {
        u8 rule = sBossRules[i];

        if (!IsBattleRuleAvailable(rule))
            continue;

        validRules[validCount++] = rule;
    }

    if (validCount == 0)
        return BATTLERULE_NONE;

    ruleIndex = RandomSeededModulo2(baseSeed, validCount);
    ruleIndex = (ruleIndex + gSaveBlock1Ptr->bossRuleRerollCounter) % validCount;

    return validRules[ruleIndex];
}

static void OverwriteActiveBattleRules(void)
{
    u8 i;

    // gActiveBattleRules[0] = BATTLERULE_NOMISSES; // test line
    // gActiveBattleRules[1] = BATTLERULE_NONE; // test line
    // gActiveBattleRules[2] = BATTLERULE_NONE; // test line

    // Norman's gym
    switch (gSaveBlock1Ptr->lastTrainerId)
    {
        case TRAINER_MARY: // Physical Room
            gActiveBattleRules[0] = BATTLERULE_BANNEDMOVECAT_SPECIAL;
            gActiveBattleRules[1] = BATTLERULE_NONE;
            gActiveBattleRules[2] = BATTLERULE_NONE;
            break;
        case TRAINER_RANDALL: // Shuffle Room
            gActiveBattleRules[0] = BATTLERULE_NOSAMESEX;
            gActiveBattleRules[1] = BATTLERULE_NONE;
            gActiveBattleRules[2] = BATTLERULE_NONE;
            break;
        case TRAINER_ALEXIA: // Dodge Room
            gActiveBattleRules[0] = BATTLERULE_NOMISSES;
            gActiveBattleRules[1] = BATTLERULE_NONE;
            gActiveBattleRules[2] = BATTLERULE_NONE;
            break;
        case TRAINER_PARKER: // Wolfe Room
            gActiveBattleRules[0] = BATTLERULE_PERISHCOUNT;
            gActiveBattleRules[1] = BATTLERULE_NONE;
            gActiveBattleRules[2] = BATTLERULE_NONE;
            break;
        case TRAINER_GEORGE: // Reposition Room
            gActiveBattleRules[0] = BATTLERULE_FIRSTMOVEONLY;
            gActiveBattleRules[1] = BATTLERULE_NONE;
            gActiveBattleRules[2] = BATTLERULE_NONE;
            break;
        case TRAINER_BERKE: // Inverse Room
            gActiveBattleRules[0] = BATTLERULE_INVERSE;
            gActiveBattleRules[1] = BATTLERULE_NONE;
            gActiveBattleRules[2] = BATTLERULE_NONE;
            break;
        case TRAINER_JODY: // Power Room
            gActiveBattleRules[0] = BATTLERULE_BANNEDMOVECAT_STATUS;
            gActiveBattleRules[1] = BATTLERULE_NONE;
            gActiveBattleRules[2] = BATTLERULE_NONE;
            break;
    }

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
    FlagClear(FLAG_INVERSE_BATTLE);
    for (i = 0; i < MAX_CONCURRENT_RULES; i++)
    {
        if (gActiveBattleRules[i] == BATTLERULE_INVERSE)
        {
            FlagSet(FLAG_INVERSE_BATTLE);
            break;
        }
    }
}

// calculate current battle rules based on a Trainer ID seed
void ComputeActiveBattleRules(void)
{
    u8 i;

    if (gBattleRulesInitialized)
    {
        OverwriteActiveBattleRules();
        return;
    }

    if (IsBossTrainer(gSaveBlock1Ptr->lastTrainerId) && B_BOSS_LIMITED_RULES)
    {
        gActiveBattleRules[0] = PickNextBossRule();
        gActiveBattleRules[1] = BATTLERULE_NONE;
        gActiveBattleRules[2] = BATTLERULE_NONE;
    }
    else
    {
        // reset gActiveBattleRules before calculation
        for (i = 0; i < MAX_CONCURRENT_RULES; i++)
            gActiveBattleRules[i] = BATTLERULE_NONE;

        CalculateActiveBattleRules();
    }

    gBattleRulesInitialized = TRUE;
    OverwriteActiveBattleRules();
}

static u32 BattleRuleBitScrambler(u32 x)
{
    x ^= x >> 16;
    x *= 0x7FEB352D;
    x ^= x >> 15;
    x *= 0x846CA68B;
    x ^= x >> 16;
    return x;
}

#define GOLDEN_RATIO_CONST 0x9E3779B9
static u32 NextBattleRuleRandom(u32 *seed)
{
    *seed += GOLDEN_RATIO_CONST;
    return BattleRuleBitScrambler(*seed);
}

// RNG function without modulo bias
// returns value in the range [0 - <limit]
static u32 RandomSeededNonModulo(u32 *inputValue, u32 limit)
{
    u32 value;
    u32 threshold;

    threshold = (0u - limit) % limit;
    do
    {
        value = NextBattleRuleRandom(inputValue);
    } while (value < threshold);

    return value % limit;
}

static bool8 IsBattleRuleAvailable(u8 rule)
{
    if (rule == BATTLERULE_NONE || rule >= BATTLE_RULES_COUNT)
        return FALSE;
    if (!gBattleRules[rule].enabled)
        return FALSE;

    if (rule == BATTLERULE_NOCRITS
     && !gSaveBlock2Ptr->activateNoCritRule)
        return FALSE;
    if (rule == BATTLERULE_NOSAMESEX && IsDoubleBattle())
        return FALSE;
    // remove NOSWITCHING from the pool for later game
    if (rule == BATTLERULE_NOSWITCHING && FlagGet(FLAG_BADGE05_GET))
        return FALSE;
    // remove NOSTAB from the pool for early game
    if (rule == BATTLERULE_NOSTAB && !FlagGet(FLAG_BADGE01_GET))
        return FALSE;
    if (rule == BATTLERULE_1PP && CalculateEnemyPartyCount() > 4)
        return FALSE;

    return TRUE;
}

#define RULE_BUDGET_1PP 0xFF
#define BUDGET_DENOMINATOR 1000
#define BUDGET_2R_1PP 36 // 3,6%
#define BUDGET_2R_3 74   // 7,4%
#define BUDGET_2R_4 460  // 46%
#define BUDGET_2R_5 430  // 43%
#define BUDGET_3R_1PP 36 // 3,6%
#define BUDGET_3R_4 44   // 4,4%
#define BUDGET_3R_5 230  // 23%
#define BUDGET_3R_6 400  // 40%
#define BUDGET_3R_7 280  // 28%
// roll the difficulty bucket (4-7 points); also handles 1PP rule
static u8 RollBattleRuleBudget(u8 ruleCount, bool8 onePPRuleAllowed, u32 *seed)
{
    u32 roll;
    u16 limit;

    if (ruleCount == 2)
    {
        // weights out of 1000
        limit = onePPRuleAllowed ? BUDGET_DENOMINATOR : (BUDGET_2R_3 + BUDGET_2R_4 + BUDGET_2R_5);
        roll = RandomSeededNonModulo(seed, limit);
        if (onePPRuleAllowed)
        {
            if (roll < BUDGET_2R_1PP)
                return RULE_BUDGET_1PP;
            roll -= BUDGET_2R_1PP;
        }

        if (roll < BUDGET_2R_3)
            return 3;
        if (roll < BUDGET_2R_3 + BUDGET_2R_4)
            return 4;
        return 5;
    }

    // weights out of 1000
    limit = onePPRuleAllowed ? BUDGET_DENOMINATOR : (BUDGET_3R_4 + BUDGET_3R_5 + BUDGET_3R_6 + BUDGET_3R_7);
    roll = RandomSeededNonModulo(seed, limit);
    if (onePPRuleAllowed)
    {
        if (roll < BUDGET_3R_1PP)
            return RULE_BUDGET_1PP;
        roll -= BUDGET_3R_1PP;
    }

    if (roll < BUDGET_3R_4)
        return 4;
    if (roll < BUDGET_3R_4 + BUDGET_3R_5)
        return 5;
    if (roll < BUDGET_3R_4 + BUDGET_3R_5 + BUDGET_3R_6)
        return 6;
    return 7;
}

// randomize a rule combination based on the given budget value
static bool8 SelectBattleRuleCombination(u8 ruleCount, u8 budget, u32 *seed)
{
    u8 available[BATTLE_RULES_COUNT];
    u8 impact[BATTLE_RULES_COUNT];
    u8 availableCount = 0;
    u8 i, j, k;
    u8 pair[2];
    u8 third;
    u16 seen = 0;

    // build array of all currently available battle rules
    for (i = 1; i < BATTLE_RULES_COUNT; i++)
    {
        if (i == BATTLERULE_1PP || !IsBattleRuleAvailable(i))
            continue;

        available[availableCount] = i;
        impact[availableCount] = GetRuleImpactValue(i);
        availableCount++;
    }

    // walk through all valid combinations and select them using reservoir sampling
    // each valid combination has an equal chance of replacing the existing selection at that point
    for (i = 0; i < availableCount; i++)
    {
        pair[0] = available[i];
        for (j = i + 1; j < availableCount; j++)
        {
            pair[1] = available[j];
            if (!IsValidPairing(pair[1], pair, 1))
                continue;

            if (ruleCount == 2)
            {
                if (impact[i] + impact[j] != budget)
                    continue;

                seen++;
                if (RandomSeededNonModulo(seed, seen) == 0)
                {
                    gActiveBattleRules[0] = pair[0];
                    gActiveBattleRules[1] = pair[1];
                }
            }
            else
            {
                for (k = j + 1; k < availableCount; k++)
                {
                    if (impact[i] + impact[j] + impact[k] != budget)
                        continue;

                    third = available[k];
                    if (!IsValidPairing(third, pair, 2))
                        continue;

                    seen++;
                    if (RandomSeededNonModulo(seed, seen) == 0)
                    {
                        gActiveBattleRules[0] = pair[0];
                        gActiveBattleRules[1] = pair[1];
                        gActiveBattleRules[2] = third;
                    }
                }
            }
        }
    }

    return (seen != 0);
}

static void SelectSingleBattleRule(u32 *seed)
{
    u8 candidates[BATTLE_RULES_COUNT];
    u8 count = 0;
    u8 index = 0;
    u8 i;

    for (i = 1; i < BATTLE_RULES_COUNT; i++)
    {
        if (IsBattleRuleAvailable(i))
            candidates[count++] = i;
    }

    index = RandomSeededNonModulo(seed, count);
    gActiveBattleRules[0] = candidates[index];
}

#define FIXED_CONST 0x12345678
// using a budget points based approach to combine battle rules
static void CalculateActiveBattleRules(void)
{
    u32 baseSeed;
    u8 count;
    u8 budget;
    bool8 onePPRuleAllowed;

    count = gSaveBlock2Ptr->concurrentRules + 1;
    if (count > MAX_CONCURRENT_RULES)
        count = MAX_CONCURRENT_RULES;

    baseSeed = (u32)gSaveBlock1Ptr->lastTrainerId * SEED_MULTIPLIER
             + gSaveBlock1Ptr->battleRuleRerollCounter
             + GetTrainerId(gSaveBlock2Ptr->playerTrainerId);
    baseSeed ^= FIXED_CONST;

    if (count == 1)
    {
        SelectSingleBattleRule(&baseSeed);
        return;
    }

    // below code is only for using multiple battle rules

    // roll budget points first (to allow a predetermined difficulty distribution)
    onePPRuleAllowed = IsBattleRuleAvailable(BATTLERULE_1PP);
    budget = RollBattleRuleBudget(count, onePPRuleAllowed, &baseSeed);

    if (budget == RULE_BUDGET_1PP)
    {
        gActiveBattleRules[0] = BATTLERULE_1PP;
        return;
    }

    // use budget for rule combinations, fall back on lower budgets in case of failure
    while (budget >= count)
    {
        if (SelectBattleRuleCombination(count, budget, &baseSeed))
            return;
        budget--;
    }

    DebugPrintf("--- No valid battle rule combination found ---");
}

bool8 IsActiveBattleRule(u8 rule)
{
    u8 i;

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

bool8 IsBossRule(u8 battleRule)
{
    u8 i;

    for (i = 0; i < ARRAY_COUNT(sBossRules); i++)
    {
        if (sBossRules[i] == battleRule)
            return TRUE;
    }

    return FALSE;
}
