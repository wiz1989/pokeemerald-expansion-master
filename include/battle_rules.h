#ifndef GUARD_BATTLE_RULES_H
#define GUARD_BATTLE_RULES_H

#define REROLL_EACH_BATTLE FALSE
#define MAX_CONCURRENT_RULES 3

extern u8 gActiveBattleRules[MAX_CONCURRENT_RULES];
extern bool8 gBattleRulesInitialized;
extern u8 gBattleRuleViolated;

void IncrementBattleRuleRerollCounter(void);
void IncrementBossRuleRerollCounter(void);
void ResetBossRuleRerollCounter(void);
void IncrementTypeRerollCounter(void);
void ComputeActiveBattleRules(void);
u32 RandomSeededNonModulo(u32 *inputValue, u32 limit);
bool8 IsActiveBattleRule(u8 rule);
u8 GetRandomSpeciesTypeSeeded(void);
u8 GetRandomMoveTypeSeeded(void);
bool8 IsTruantBattleRule(u32 battler);
u8 GetBattleRuleCount(void);
u8 GetBossPoolsCount(void);
bool8 HasLimitedRulesPool(u16 trainerId);
bool8 IsBossRule(u8 battleRule);

struct BattleRule
{
    u8 impact;
    bool8 enabled;
    u8 category;
};

extern const struct BattleRule gBattleRules[];

#define BOSS_RULE_POOL_SIZE 3

struct BossRulePool
{
    u16 trainerId;
    u8 rules[BOSS_RULE_POOL_SIZE];
};

extern const struct BossRulePool gBossRulePools[];

#endif // GUARD_BATTLE_RULES_H
