#include "global.h"
#include "battle.h"
#include "battle_rules.h"
#include "battle_setup.h"
#include "event_data.h"
#include "malloc.h"
#include "random.h"
#include "constants/abilities.h"

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
        .enabled = FALSE,
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
        .enabled = TRUE,
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
        .enabled = FALSE,
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
        .enabled = FALSE,
        .category = BATTLERULE_CATEGORY_ACTIVATE_ITEM,
    },
    [BATTLERULE_NOABILITY] =
    {
        .weight = 1,
        .enabled = FALSE,
        .category = BATTLERULE_CATEGORY_ACTIVATE_ABILITY,
    },
    [BATTLERULE_NOSTATUS] =
    {
        .weight = 1,
        .enabled = TRUE,
        .category = BATTLERULE_CATEGORY_MOVEEFFECT,
    },
    [BATTLERULE_SHAREDDAMAGE] =
    {
        .weight = 1,
        .enabled = FALSE,
        .category = BATTLERULE_CATEGORY_GENERAL,
    },
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
}

u8 GetRandomBattleRuleSeeded(void)
{
    u16 value = 0;
    u16 trainerId = (TRAINER_FLAGS_START + gSaveBlock1Ptr->lastTrainerId);

    FlagClear(FLAG_INVERSE_BATTLE);

    value = RandomSeededModulo2(trainerId + GetTrainerClassFromId(gSaveBlock1Ptr->lastTrainerId) + gSaveBlock1Ptr->battleRuleRerollCounter, BATTLE_RULES_COUNT);

    while (!gBattleRules[value].enabled || (IsDoubleBattle() && value == BATTLERULE_NOSAMESEX))
    {
        IncrementBattleRuleRerollCounter();
        value = RandomSeededModulo2(trainerId + GetTrainerClassFromId(gSaveBlock1Ptr->lastTrainerId) + gSaveBlock1Ptr->battleRuleRerollCounter, BATTLE_RULES_COUNT);
    }

    // value = BATTLERULE_TRUANT; // test line
    if (!(gBattleTypeFlags & BATTLE_TYPE_TRAINER))
        value = BATTLERULE_NONE;
    DebugPrintf("--- Random Battle Rule: %d ---", value);

    if (value == BATTLERULE_INVERSE)
        FlagSet(FLAG_INVERSE_BATTLE);

    return value;
}

u8 GetRandomTypeSeeded(void)
{
    u16 value = 0;
    u16 trainerId = (TRAINER_FLAGS_START + gSaveBlock1Ptr->lastTrainerId);

    value = RandomSeededModulo2(trainerId + GetTrainerClassFromId(gSaveBlock1Ptr->lastTrainerId) + gSaveBlock1Ptr->typeRerollCounter, NUMBER_OF_MON_TYPES);

    while (value == TYPE_MYSTERY || value == TYPE_NONE || value == TYPE_STELLAR)
    {
        IncrementTypeRerollCounter();
        value = RandomSeededModulo2(trainerId + GetTrainerClassFromId(gSaveBlock1Ptr->lastTrainerId) + gSaveBlock1Ptr->typeRerollCounter, NUMBER_OF_MON_TYPES);
    }
    
    DebugPrintf("--- Random Type is %d ---", value);
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
