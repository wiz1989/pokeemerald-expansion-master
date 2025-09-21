#ifndef GUARD_BATTLE_RULES_H
#define GUARD_BATTLE_RULES_H

void IncrementBattleRuleRerollCounter(void);
void IncrementTypeRerollCounter(void);
u8 GetRandomBattleRuleSeeded(void);
u8 GetRandomTypeSeeded(void);
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
