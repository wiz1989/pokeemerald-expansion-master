#ifndef GUARD_BATTLE_RULES_H
#define GUARD_BATTLE_RULES_H

#define REROLL_EACH_BATTLE FALSE
#define MAX_CONCURRENT_RULES 3

extern u8 gActiveBattleRules[MAX_CONCURRENT_RULES];
extern u8 gBattleRuleViolated;

void IncrementBattleRuleRerollCounter(void);
void IncrementTypeRerollCounter(void);
void ComputeActiveBattleRules(void);
bool8 IsActiveBattleRule(u8 rule);
u8 GetRandomSpeciesTypeSeeded(void);
u8 GetRandomMoveTypeSeeded(void);
bool8 IsTruantBattleRule(u32 battler);
u8 GetBattleRuleCount(void);

struct BattleRule
{
    u8 weight; // currently not used;
    bool8 enabled;
    u8 category;
};

extern const struct BattleRule gBattleRules[];

#endif // GUARD_BATTLE_RULES_H
