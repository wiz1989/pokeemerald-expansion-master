#include "global.h"
#include "battle.h"
#include "battle_rules.h"
#include "battle_setup.h"
#include "data.h"
#include "malloc.h"
#include "random.h"

#define BATTLE_RULES_COUNT ARRAY_COUNT(gBattleRules)
const struct BattleRule gBattleRules[] = 
{
    [BATTLERULE_BANNEDTYPE_NORMAL] =
    {
        .weight = 1,
        .enabled = TRUE,
        .category = BATTLERULE_CATEGORY_SENDOUT,
    },
    [BATTLERULE_BANNEDTYPE_FIGHTING] =
    {
        .weight = 1,
        .enabled = TRUE,
        .category = BATTLERULE_CATEGORY_SENDOUT,
    },
    [BATTLERULE_BANNEDTYPE_FLYING] =
    {
        .weight = 1,
        .enabled = TRUE,
        .category = BATTLERULE_CATEGORY_SENDOUT,
    },
    [BATTLERULE_BANNEDTYPE_POISON] =
    {
        .weight = 1,
        .enabled = TRUE,
        .category = BATTLERULE_CATEGORY_SENDOUT,
    },
    [BATTLERULE_BANNEDTYPE_GROUND] =
    {
        .weight = 1,
        .enabled = TRUE,
        .category = BATTLERULE_CATEGORY_SENDOUT,
    },
    [BATTLERULE_BANNEDTYPE_ROCK] =
    {
        .weight = 1,
        .enabled = TRUE,
        .category = BATTLERULE_CATEGORY_SENDOUT,
    },
    [BATTLERULE_BANNEDTYPE_BUG] =
    {
        .weight = 1,
        .enabled = TRUE,
        .category = BATTLERULE_CATEGORY_SENDOUT,
    },
    [BATTLERULE_BANNEDTYPE_GHOST] =
    {
        .weight = 1,
        .enabled = TRUE,
        .category = BATTLERULE_CATEGORY_SENDOUT,
    },
    [BATTLERULE_BANNEDTYPE_STEEL] =
    {
        .weight = 1,
        .enabled = TRUE,
        .category = BATTLERULE_CATEGORY_SENDOUT,
    },
    [BATTLERULE_BANNEDTYPE_MYSTERY] = // always disabled
    {
        .weight = 1,
        .enabled = FALSE,
        .category = BATTLERULE_CATEGORY_SENDOUT,
    },
    [BATTLERULE_BANNEDTYPE_FIRE] =
    {
        .weight = 1,
        .enabled = TRUE,
        .category = BATTLERULE_CATEGORY_SENDOUT,
    },
    [BATTLERULE_BANNEDTYPE_WATER] =
    {
        .weight = 1,
        .enabled = TRUE,
        .category = BATTLERULE_CATEGORY_SENDOUT,
    },
    [BATTLERULE_BANNEDTYPE_GRASS] =
    {
        .weight = 1,
        .enabled = TRUE,
        .category = BATTLERULE_CATEGORY_SENDOUT,
    },
    [BATTLERULE_BANNEDTYPE_ELECTRIC] =
    {
        .weight = 1,
        .enabled = TRUE,
        .category = BATTLERULE_CATEGORY_SENDOUT,
    },
    [BATTLERULE_BANNEDTYPE_PSYCHIC] =
    {
        .weight = 1,
        .enabled = TRUE,
        .category = BATTLERULE_CATEGORY_SENDOUT,
    },
    [BATTLERULE_BANNEDTYPE_ICE] =
    {
        .weight = 1,
        .enabled = TRUE,
        .category = BATTLERULE_CATEGORY_SENDOUT,
    },
    [BATTLERULE_BANNEDTYPE_DRAGON] =
    {
        .weight = 1,
        .enabled = TRUE,
        .category = BATTLERULE_CATEGORY_SENDOUT,
    },
    [BATTLERULE_BANNEDTYPE_DARK] =
    {
        .weight = 1,
        .enabled = TRUE,
        .category = BATTLERULE_CATEGORY_SENDOUT,
    },
    [BATTLERULE_BANNEDTYPE_FAIRY] =
    {
        .weight = 1,
        .enabled = TRUE,
        .category = BATTLERULE_CATEGORY_SENDOUT,
    },
    [BATTLERULE_BANNEDMOVETYPE_NORMAL] =
    {
        .weight = 1,
        .enabled = FALSE,
        .category = BATTLERULE_CATEGORY_USEMOVE,
    },
    [BATTLERULE_BANNEDMOVETYPE_FIGHTING] =
    {
        .weight = 1,
        .enabled = FALSE,
        .category = BATTLERULE_CATEGORY_USEMOVE,
    },
    [BATTLERULE_BANNEDMOVETYPE_FLYING] =
    {
        .weight = 1,
        .enabled = FALSE,
        .category = BATTLERULE_CATEGORY_USEMOVE,
    },
    [BATTLERULE_BANNEDMOVETYPE_POISON] =
    {
        .weight = 1,
        .enabled = FALSE,
        .category = BATTLERULE_CATEGORY_USEMOVE,
    },
    [BATTLERULE_BANNEDMOVETYPE_GROUND] =
    {
        .weight = 1,
        .enabled = FALSE,
        .category = BATTLERULE_CATEGORY_USEMOVE,
    },
    [BATTLERULE_BANNEDMOVETYPE_ROCK] =
    {
        .weight = 1,
        .enabled = FALSE,
        .category = BATTLERULE_CATEGORY_USEMOVE,
    },
    [BATTLERULE_BANNEDMOVETYPE_BUG] =
    {
        .weight = 1,
        .enabled = FALSE,
        .category = BATTLERULE_CATEGORY_USEMOVE,
    },
    [BATTLERULE_BANNEDMOVETYPE_GHOST] =
    {
        .weight = 1,
        .enabled = FALSE,
        .category = BATTLERULE_CATEGORY_USEMOVE,
    },
    [BATTLERULE_BANNEDMOVETYPE_STEEL] =
    {
        .weight = 1,
        .enabled = FALSE,
        .category = BATTLERULE_CATEGORY_USEMOVE,
    },
    [BATTLERULE_BANNEDMOVETYPE_MYSTERY] = // always disabled
    {
        .weight = 1,
        .enabled = FALSE,
        .category = BATTLERULE_CATEGORY_USEMOVE,
    },
    [BATTLERULE_BANNEDMOVETYPE_FIRE] =
    {
        .weight = 1,
        .enabled = FALSE,
        .category = BATTLERULE_CATEGORY_USEMOVE,
    },
    [BATTLERULE_BANNEDMOVETYPE_WATER] =
    {
        .weight = 1,
        .enabled = FALSE,
        .category = BATTLERULE_CATEGORY_USEMOVE,
    },
    [BATTLERULE_BANNEDMOVETYPE_GRASS] =
    {
        .weight = 1,
        .enabled = FALSE,
        .category = BATTLERULE_CATEGORY_USEMOVE,
    },
    [BATTLERULE_BANNEDMOVETYPE_ELECTRIC] =
    {
        .weight = 1,
        .enabled = FALSE,
        .category = BATTLERULE_CATEGORY_USEMOVE,
    },
    [BATTLERULE_BANNEDMOVETYPE_PSYCHIC] =
    {
        .weight = 1,
        .enabled = FALSE,
        .category = BATTLERULE_CATEGORY_USEMOVE,
    },
    [BATTLERULE_BANNEDMOVETYPE_ICE] =
    {
        .weight = 1,
        .enabled = FALSE,
        .category = BATTLERULE_CATEGORY_USEMOVE,
    },
    [BATTLERULE_BANNEDMOVETYPE_DRAGON] =
    {
        .weight = 1,
        .enabled = FALSE,
        .category = BATTLERULE_CATEGORY_USEMOVE,
    },
    [BATTLERULE_BANNEDMOVETYPE_DARK] =
    {
        .weight = 1,
        .enabled = FALSE,
        .category = BATTLERULE_CATEGORY_USEMOVE,
    },
    [BATTLERULE_BANNEDMOVETYPE_FAIRY] =
    {
        .weight = 1,
        .enabled = FALSE,
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
        .enabled = FALSE,
        .category = BATTLERULE_CATEGORY_MOVEEFFECT,
    },
    [BATTLERULE_NORECOIL] =
    {
        .weight = 1,
        .enabled = FALSE,
        .category = BATTLERULE_CATEGORY_MOVEEFFECT,
    },
    [BATTLERULE_NOSTAB] =
    {
        .weight = 1,
        .enabled = FALSE,
        .category = BATTLERULE_CATEGORY_USEMOVE,
    },
    [BATTLERULE_ONLYSTAB] =
    {
        .weight = 1,
        .enabled = FALSE,
        .category = BATTLERULE_CATEGORY_USEMOVE,
    },
    [BATTLERULE_NOSUPEREFFECTIVE] =
    {
        .weight = 1,
        .enabled = FALSE,
        .category = BATTLERULE_CATEGORY_USEMOVE,
    },
    [BATTLERULE_1HP] =
    {
        .weight = 1,
        .enabled = FALSE,
        .category = BATTLERULE_CATEGORY_GENERAL,
    },
    [BATTLERULE_1PP] =
    {
        .weight = 1,
        .enabled = FALSE,
        .category = BATTLERULE_CATEGORY_GENERAL,
    },
    [BATTLERULE_NOSAMESEX] =
    {
        .weight = 1,
        .enabled = FALSE,
        .category = BATTLERULE_CATEGORY_SENDOUT,
    },
    [BATTLERULE_NOSWITCHING] =
    {
        .weight = 1,
        .enabled = FALSE,
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
        .enabled = FALSE,
        .category = BATTLERULE_CATEGORY_USEMOVE,
    },
    [BATTLERULE_NOPRIO] =
    {
        .weight = 1,
        .enabled = FALSE,
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
        .enabled = FALSE,
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
        .enabled = FALSE,
        .category = BATTLERULE_CATEGORY_USEMOVE,
    },
    [BATTLERULE_TRICKROOM] =
    {
        .weight = 1,
        .enabled = FALSE,
        .category = BATTLERULE_CATEGORY_GENERAL,
    },
    [BATTLERULE_BANNEDMOVECAT_PHYSICAL] =
    {
        .weight = 1,
        .enabled = FALSE,
        .category = BATTLERULE_CATEGORY_USEMOVE,
    },
    [BATTLERULE_BANNEDMOVECAT_SPECIAL] =
    {
        .weight = 1,
        .enabled = FALSE,
        .category = BATTLERULE_CATEGORY_USEMOVE,
    },
    [BATTLERULE_BANNEDMOVECAT_STATUS] =
    {
        .weight = 1,
        .enabled = FALSE,
        .category = BATTLERULE_CATEGORY_USEMOVE,
    },
    [BATTLERULE_INVERSE] =
    {
        .weight = 1,
        .enabled = FALSE,
        .category = BATTLERULE_CATEGORY_GENERAL,
    },
    [BATTLERULE_FIRSTMOVEONLY] =
    {
        .weight = 1,
        .enabled = FALSE,
        .category = BATTLERULE_CATEGORY_USEMOVE,
    },
    [BATTLERULE_TRUANT] =
    {
        .weight = 1,
        .enabled = FALSE,
        .category = BATTLERULE_CATEGORY_GENERAL,
    },
    [BATTLERULE_NOMISSES] =
    {
        .weight = 1,
        .enabled = FALSE,
        .category = BATTLERULE_CATEGORY_MOVEEFFECT,
    }
};

void IncrementBattleRuleRerollCounter(void)
{
    gSaveBlock1Ptr->battleRuleRerollCounter++;
    if (gSaveBlock1Ptr->battleRuleRerollCounter > 65000)
        gSaveBlock1Ptr->battleRuleRerollCounter = 0;
}

u8 GetRandomBattleRuleSeeded(void)
{
    u16 value = 0;

    value = RandomSeededModulo2(GetTrainerFlag() + GetTrainerClassFromId(TRAINER_BATTLE_PARAM.opponentA) + gSaveBlock1Ptr->battleRuleRerollCounter, BATTLE_RULES_COUNT);

    while (!gBattleRules[value].enabled || (IsDoubleBattle() && value == BATTLERULE_NOSAMESEX))
    {
        IncrementBattleRuleRerollCounter();
        value = RandomSeededModulo2(GetTrainerFlag() + GetTrainerClassFromId(TRAINER_BATTLE_PARAM.opponentA) + gSaveBlock1Ptr->battleRuleRerollCounter, BATTLE_RULES_COUNT);
        DebugPrintf("Random Battle Rule: %d is %d", value, gBattleRules[value].enabled);
    }
    
    DebugPrintf("--- Random Battle Rule: %d ---\n", value);
    return value;
}
