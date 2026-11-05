#ifndef GUARD_CAPS_H
#define GUARD_CAPS_H

#define CAP_START      5
#define CAP_ROXANNE   15
#define CAP_BRAWLY    19
#define CAP_WATTSON   24
#define CAP_FLANNERY  29
#define CAP_NORMAN    34
#define CAP_WINONA    40
#define CAP_TATE_LIZA 46
#define CAP_WALLACE   55
#define CAP_CHAMPION  65

#define CAP_VANILLA_START      5
#define CAP_VANILLA_ROXANNE   15
#define CAP_VANILLA_BRAWLY    19
#define CAP_VANILLA_WATTSON   24
#define CAP_VANILLA_FLANNERY  29
#define CAP_VANILLA_NORMAN    31
#define CAP_VANILLA_WINONA    33
#define CAP_VANILLA_TATE_LIZA 42
#define CAP_VANILLA_WALLACE   46
#define CAP_VANILLA_CHAMPION  58

#if B_EXP_CAP_TYPE != EXP_CAP_NONE && B_EXP_CAP_TYPE != EXP_CAP_HARD && B_EXP_CAP_TYPE != EXP_CAP_SOFT
#error "Invalid choice for B_EXP_CAP_TYPE, must be of [EXP_CAP_NONE, EXP_CAP_HARD, EXP_CAP_SOFT]"
#endif

#if B_EXP_CAP_TYPE == EXP_CAP_HARD || B_EXP_CAP_TYPE == EXP_CAP_SOFT
#if B_LEVEL_CAP_TYPE != LEVEL_CAP_FLAG_LIST && B_LEVEL_CAP_TYPE != LEVEL_CAP_VARIABLE
#error "Invalid choice for B_LEVEL_CAP_TYPE, must be of [LEVEL_CAP_FLAG_LIST, LEVEL_CAP_VARIABLE]"
#endif
#if B_LEVEL_CAP_TYPE == LEVEL_CAP_VARIABLE && B_LEVEL_CAP_VARIABLE == 0
#error "B_LEVEL_CAP_TYPE set to LEVEL_CAP_VARIABLE, but no variable chosen for B_LEVEL_CAP_VARIABLE, set B_LEVEL_CAP_VARIABLE to a valid event variable"
#endif
#endif

#if B_EV_CAP_TYPE != EV_CAP_NONE && B_EV_CAP_TYPE != EV_CAP_FLAG_LIST && B_EV_CAP_TYPE != EV_CAP_VARIABLE && B_EV_CAP_TYPE != EV_CAP_NO_GAIN
#error "Invalid choice for B_EV_CAP_TYPE, must be one of [EV_CAP_NONE, EV_CAP_FLAG_LIST, EV_CAP_VARIABLE, EV_CAP_NO_GAIN]"
#endif

u32 GetCurrentLevelCap(void);
u32 GetSoftLevelCapExpValue(u32 level, u32 expValue);
u32 GetCurrentEVCap(void);
void LevelBoxesToCap(void);

#endif /* GUARD_CAPS_H */
