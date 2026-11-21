#include "global.h"
#include "options_plus_menu.h"
#include "main.h"
#include "menu.h"
#include "event_data.h"
#include "scanline_effect.h"
#include "palette.h"
#include "sprite.h"
#include "task.h"
#include "malloc.h"
#include "bg.h"
#include "gpu_regs.h"
#include "window.h"
#include "text.h"
#include "text_window.h"
#include "international_string_util.h"
#include "strings.h"
#include "gba/m4a_internal.h"
#include "constants/rgb.h"

enum
{
    MENU_VANILLA,
    MENU_HACK,
    MENU_NUZLOCKE,
    MENU_COUNT,
};

// Menu items
enum
{
    MENUITEM_VANILLA_TEXTSPEED,
    MENUITEM_VANILLA_BATTLESCENE,
    MENUITEM_VANILLA_BATTLESTYLE,
    MENUITEM_VANILLA_SOUND,
    MENUITEM_VANILLA_BUTTONMODE,
    MENUITEM_VANILLA_FRAMETYPE,
    MENUITEM_VANILLA_CANCEL,
    MENUITEM_VANILLA_COUNT,
};

enum
{
    MENUITEM_HACK_BATTLE_SPEEDUP,
    MENUITEM_HACK_50DAMAGE,
    MENUITEM_HACK_REVEAL_RULE,
    MENUITEM_HACK_ANNOUNCE_RULES,
    MENUITEM_HACK_CONCURRENT_RULES,
    MENUITEM_HACK_INSTA_TRIGGER,
    MENUITEM_HACK_ACTIVATE_NOCRITS,
    MENUITEM_HACK_HARDER_TRAINERS,
    MENUITEM_HACK_BOSS_UPGRADE,
    MENUITEM_HACK_DAYNIGHT_TINT,
    MENUITEM_HACK_RULES_INFO,
    MENUITEM_HACK_CANCEL,
    MENUITEM_HACK_COUNT,
};

enum
{
    MENUITEM_NUZLOCKE_PERMADEATH,
    MENUITEM_NUZLOCKE_NOBAG,
    MENUITEM_NUZLOCKE_DUPE_CLAUSE,
    MENUITEM_NUZLOCKE_METLOC_CLAUSE,
    MENUITEM_NUZLOCKE_CANCEL,
    MENUITEM_NUZLOCKE_COUNT,
};

#define MENUITEM_COUNT_MAX MENUITEM_HACK_COUNT

// Window Ids
enum
{
    WIN_TOPBAR,
    WIN_OPTIONS,
    WIN_DESCRIPTION
};

static const struct WindowTemplate sOptionMenuWinTemplates[] =
{
    {//WIN_TOPBAR
        .bg = 1,
        .tilemapLeft = 0,
        .tilemapTop = 0,
        .width = 30,
        .height = 2,
        .paletteNum = 1,
        .baseBlock = 2
    },
    {//WIN_OPTIONS
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 3,
        .width = 26,
        .height = 10,
        .paletteNum = 1,
        .baseBlock = 62
    },
    {//WIN_DESCRIPTION
        .bg = 1,
        .tilemapLeft = 2,
        .tilemapTop = 15,
        .width = 26,
        .height = 4,
        .paletteNum = 1,
        .baseBlock = 500
    },
    DUMMY_WIN_TEMPLATE
};

static const struct BgTemplate sOptionMenuBgTemplates[] =
{
    {
       .bg = 0,
       .charBaseIndex = 1,
       .mapBaseIndex = 30,
       .screenSize = 0,
       .paletteMode = 0,
       .priority = 1,
       .baseTile = 0
    },
    {
       .bg = 1,
       .charBaseIndex = 1,
       .mapBaseIndex = 31,
       .screenSize = 0,
       .paletteMode = 0,
       .priority = 0,
       .baseTile = 0
    },
};

struct OptionMenu
{
    u8 submenu;
    u8 sel[MENU_COUNT][MENUITEM_COUNT_MAX];
    int menuCursor[MENU_COUNT];
    int visibleCursor[MENU_COUNT];
    u8 arrowTaskId;
    u8 arrowItemCount;
};

#define Y_DIFF 16 // Difference in pixels between items.
#define OPTIONS_ON_SCREEN 5
#define NUM_OPTIONS_FROM_BORDER 1

// local functions
static void MainCB2(void);
static void VBlankCB(void);
static void DrawTopBarText(void); //top Option text
static void DrawLeftSideOptionText(int selection, int y);
static void DrawRightSideChoiceText(const u8 *str, int x, int y, bool8 choosen, bool8 active);
static void DrawOptionMenuTexts(void); //left side text;
static void DrawChoices(u32 id, int y); //right side draw function
static void HighlightOptionMenuItem(void);
static void Task_OptionMenuFadeIn(u8 taskId);
static void Task_OptionMenuProcessInput(u8 taskId);
static void Task_OptionMenuSave(u8 taskId);
static void Task_OptionMenuFadeOut(u8 taskId);
static void ScrollMenu(int direction);
static void ScrollAll(int direction); // to bottom or top
static int GetMiddleX(const u8 *txt1, const u8 *txt2, const u8 *txt3);
static int XOptions_ProcessInput(int x, int selection);
static int ProcessInput_Options_Two(int selection);
static int ProcessInput_Options_Three(int selection);
static int ProcessInput_Options_Four(int selection);
static int ProcessInput_Sound(int selection);
static int ProcessInput_FrameType(int selection);
static const u8 *const OptionTextDescription(void);
static const u8 *const OptionTextRight(u8 menuItem);
static u8 MenuItemCount(void);
static u8 MenuItemCancel(void);
static void DrawDescriptionText(void);
static void DrawOptionMenuChoice(const u8 *text, u8 x, u8 y, u8 style, bool8 active);
static void ReDrawAll(void);
static void DrawChoices_TextSpeed(int selection, int y);
static void DrawChoices_BattleScene(int selection, int y);
static void DrawChoices_BattleStyle(int selection, int y);
static void DrawChoices_Sound(int selection, int y);
static void DrawChoices_ButtonMode(int selection, int y);
static void DrawChoices_FrameType(int selection, int y);
static void DrawChoices_BattleSpeedup(int selection, int y);
static void DrawChoices_HalfDamage(int selection, int y);
static void DrawChoices_RevealRule(int selection, int y);
static void DrawChoices_AnnounceRules(int selection, int y);
static void DrawChoices_ConcurrentRules(int selection, int y);
static void DrawChoices_OptionOnOff(int selection, int y);
static void DrawChoices_NoCrits(int selection, int y);
static void DrawChoices_Permadeath(int selection, int y);
static void DrawBgWindowFrames(void);

// EWRAM vars
EWRAM_DATA static struct OptionMenu *sOptions = NULL;

// const data
static const u8 sEqualSignGfx[] = INCBIN_U8("graphics/interface/option_menu_equals_sign.4bpp"); // note: this is only used in the Japanese release
static const u16 sOptionMenuBg_Pal[] = {RGB(17, 18, 31)};
static const u16 sOptionMenuText_Pal[] = INCBIN_U16("graphics/interface/option_menu_text_custom.gbapal");

#define TEXT_COLOR_OPTIONS_WHITE                1
#define TEXT_COLOR_OPTIONS_GRAY_FG              2
#define TEXT_COLOR_OPTIONS_GRAY_SHADOW          3
#define TEXT_COLOR_OPTIONS_GRAY_LIGHT_FG        4
#define TEXT_COLOR_OPTIONS_ORANGE_FG            5
#define TEXT_COLOR_OPTIONS_ORANGE_SHADOW        6
#define TEXT_COLOR_OPTIONS_RED_FG               7
#define TEXT_COLOR_OPTIONS_RED_SHADOW           8
#define TEXT_COLOR_OPTIONS_GREEN_FG             9
#define TEXT_COLOR_OPTIONS_GREEN_SHADOW         10
#define TEXT_COLOR_OPTIONS_GREEN_DARK_FG        11
#define TEXT_COLOR_OPTIONS_GREEN_DARK_SHADOW    12
#define TEXT_COLOR_OPTIONS_RED_DARK_FG          13
#define TEXT_COLOR_OPTIONS_RED_DARK_SHADOW      14

struct ItemFunctions
{
    void (*drawChoices)(int selection, int y);
    int (*processInput)(int selection);
};

static const struct ItemFunctions sItemFunctionsVanilla[MENUITEM_VANILLA_COUNT] =
{
    [MENUITEM_VANILLA_TEXTSPEED]   = {DrawChoices_TextSpeed,   ProcessInput_Options_Three},
    [MENUITEM_VANILLA_BATTLESCENE] = {DrawChoices_BattleScene, ProcessInput_Options_Two},
    [MENUITEM_VANILLA_BATTLESTYLE] = {DrawChoices_BattleStyle, ProcessInput_Options_Two},
    [MENUITEM_VANILLA_SOUND]       = {DrawChoices_Sound,       ProcessInput_Sound},
    [MENUITEM_VANILLA_BUTTONMODE]  = {DrawChoices_ButtonMode,  ProcessInput_Options_Three},
    [MENUITEM_VANILLA_FRAMETYPE]   = {DrawChoices_FrameType,   ProcessInput_FrameType},
};

static const struct ItemFunctions sItemFunctionsHack[MENUITEM_HACK_COUNT] =
{
    [MENUITEM_HACK_BATTLE_SPEEDUP]     = {DrawChoices_BattleSpeedup,    ProcessInput_Options_Four},
    [MENUITEM_HACK_50DAMAGE]           = {DrawChoices_HalfDamage,       ProcessInput_Options_Two},
    [MENUITEM_HACK_REVEAL_RULE]        = {DrawChoices_RevealRule,        ProcessInput_Options_Two},
    [MENUITEM_HACK_ANNOUNCE_RULES]     = {DrawChoices_AnnounceRules,     ProcessInput_Options_Three},
    [MENUITEM_HACK_CONCURRENT_RULES]   = {DrawChoices_ConcurrentRules,   ProcessInput_Options_Three},
    [MENUITEM_HACK_INSTA_TRIGGER]      = {DrawChoices_OptionOnOff,       ProcessInput_Options_Two},
    [MENUITEM_HACK_ACTIVATE_NOCRITS]   = {DrawChoices_NoCrits,           ProcessInput_Options_Two},
    [MENUITEM_HACK_HARDER_TRAINERS]    = {DrawChoices_OptionOnOff,       ProcessInput_Options_Two},
    [MENUITEM_HACK_BOSS_UPGRADE]       = {DrawChoices_OptionOnOff,       ProcessInput_Options_Two},
    [MENUITEM_HACK_DAYNIGHT_TINT]      = {DrawChoices_OptionOnOff,       ProcessInput_Options_Two},
    [MENUITEM_HACK_RULES_INFO]         = {DrawChoices_OptionOnOff,       ProcessInput_Options_Two},
};

static const struct ItemFunctions sItemFunctionsNuzlocke[MENUITEM_NUZLOCKE_COUNT] =
{
    [MENUITEM_NUZLOCKE_PERMADEATH]    = {DrawChoices_Permadeath,  ProcessInput_Options_Two},
    [MENUITEM_NUZLOCKE_NOBAG]         = {DrawChoices_OptionOnOff, ProcessInput_Options_Two},
    [MENUITEM_NUZLOCKE_DUPE_CLAUSE]   = {DrawChoices_OptionOnOff, ProcessInput_Options_Two},
    [MENUITEM_NUZLOCKE_METLOC_CLAUSE] = {DrawChoices_OptionOnOff, ProcessInput_Options_Two},
};

static const u8 *const sOptionMenuItemsNamesVanilla[MENUITEM_VANILLA_COUNT] =
{
    [MENUITEM_VANILLA_TEXTSPEED]   = gText_TextSpeed,
    [MENUITEM_VANILLA_BATTLESCENE] = gText_BattleScene,
    [MENUITEM_VANILLA_BATTLESTYLE] = gText_BattleStyle,
    [MENUITEM_VANILLA_SOUND]       = gText_Sound,
    [MENUITEM_VANILLA_BUTTONMODE]  = gText_ButtonMode,
    [MENUITEM_VANILLA_FRAMETYPE]   = gText_Frame,
    [MENUITEM_VANILLA_CANCEL]      = gText_OptionMenuCancel,
};

static const u8 *const sOptionMenuItemsNamesHack[MENUITEM_HACK_COUNT] =
{
    [MENUITEM_HACK_BATTLE_SPEEDUP]     = gText_BattleSpeedup,
    [MENUITEM_HACK_50DAMAGE]           = gText_50Damage,
    [MENUITEM_HACK_REVEAL_RULE]        = gText_RevealRule,
    [MENUITEM_HACK_ANNOUNCE_RULES]     = gText_AnnounceRules,
    [MENUITEM_HACK_CONCURRENT_RULES]   = gText_ConcurrentRules,
    [MENUITEM_HACK_INSTA_TRIGGER]      = gText_InstaTrigger,
    [MENUITEM_HACK_ACTIVATE_NOCRITS]   = gText_ActivateNoCrits,
    [MENUITEM_HACK_HARDER_TRAINERS]    = gText_HarderTrainers,
    [MENUITEM_HACK_BOSS_UPGRADE]       = gText_LeadersE4Upgrade,
    [MENUITEM_HACK_DAYNIGHT_TINT]      = gText_DayNightTint,
    [MENUITEM_HACK_RULES_INFO]         = gText_RulesInfo,
    [MENUITEM_HACK_CANCEL]             = gText_OptionMenuCancel,
};

static const u8 *const sOptionMenuItemsNamesNuzlocke[MENUITEM_NUZLOCKE_COUNT] =
{
    [MENUITEM_NUZLOCKE_PERMADEATH]    = gText_PermaDeath,
    [MENUITEM_NUZLOCKE_NOBAG]         = gText_NoBagInBattle,
    [MENUITEM_NUZLOCKE_DUPE_CLAUSE]   = gText_DupeClause,
    [MENUITEM_NUZLOCKE_METLOC_CLAUSE] = gText_MetLocClause,
    [MENUITEM_NUZLOCKE_CANCEL]        = gText_OptionMenuCancel,
};

static const u8 *const OptionTextRight(u8 menuItem)
{
    switch (sOptions->submenu)
    {
    case MENU_VANILLA:  return sOptionMenuItemsNamesVanilla[menuItem];
    case MENU_HACK:     return sOptionMenuItemsNamesHack[menuItem];
    case MENU_NUZLOCKE: return sOptionMenuItemsNamesNuzlocke[menuItem];
    }
    return gText_OptionMenuCancel;
}

// Menu left side text conditions
static bool8 CheckConditions(int selection)
{
    switch (sOptions->submenu)
    {
    case MENU_VANILLA:
        switch(selection)
        {
        case MENUITEM_VANILLA_TEXTSPEED:       return TRUE;
        case MENUITEM_VANILLA_BATTLESCENE:     return TRUE;
        case MENUITEM_VANILLA_BATTLESTYLE:     return TRUE;
        case MENUITEM_VANILLA_SOUND:           return TRUE;
        case MENUITEM_VANILLA_BUTTONMODE:      return TRUE;
        case MENUITEM_VANILLA_FRAMETYPE:       return TRUE;
        case MENUITEM_VANILLA_CANCEL:          return TRUE;
        case MENUITEM_VANILLA_COUNT:           return TRUE;
        }
    case MENU_HACK:
        switch(selection)
        {
        case MENUITEM_HACK_BATTLE_SPEEDUP:     return TRUE;
        case MENUITEM_HACK_50DAMAGE:           return TRUE;
        case MENUITEM_HACK_REVEAL_RULE:        return TRUE;
        case MENUITEM_HACK_ANNOUNCE_RULES:     return TRUE;
        case MENUITEM_HACK_CONCURRENT_RULES:   return TRUE;
        case MENUITEM_HACK_INSTA_TRIGGER:      return TRUE;
        case MENUITEM_HACK_ACTIVATE_NOCRITS:   return TRUE;
        case MENUITEM_HACK_HARDER_TRAINERS:    return TRUE;
        case MENUITEM_HACK_BOSS_UPGRADE:       return TRUE;
        case MENUITEM_HACK_DAYNIGHT_TINT:      return TRUE;
        case MENUITEM_HACK_RULES_INFO:         return TRUE;
        case MENUITEM_HACK_CANCEL:             return TRUE;
        case MENUITEM_HACK_COUNT:              return TRUE;
        }
    case MENU_NUZLOCKE:
        switch(selection)
        {
        case MENUITEM_NUZLOCKE_PERMADEATH:     return TRUE;
        case MENUITEM_NUZLOCKE_NOBAG:          return TRUE;
        case MENUITEM_NUZLOCKE_DUPE_CLAUSE:    return TRUE;
        case MENUITEM_NUZLOCKE_METLOC_CLAUSE:  return TRUE;
        case MENUITEM_NUZLOCKE_CANCEL:         return TRUE;
        case MENUITEM_NUZLOCKE_COUNT:          return TRUE;
        }
    }
    return FALSE;
}

// Descriptions
static const u8 sText_Empty[]                   = _("");
static const u8 sText_Desc_Save[]               = _("Save your settings.");
static const u8 sText_Desc_TextSpeed[]          = _("Choose one of the three text-display\nspeeds.");
static const u8 sText_Desc_BattleScene_On[]     = _("Show the POKéMON battle animations.");
static const u8 sText_Desc_BattleScene_Off[]    = _("Skip the POKéMON battle animations.");
static const u8 sText_Desc_BattleStyle_Shift[]  = _("Get the option to switch your\nPOKéMON after the enemies faints.");
static const u8 sText_Desc_BattleStyle_Set[]    = _("No free switch after fainting the\nenemies POKéMON.");
static const u8 sText_Desc_SoundMono[]          = _("Sound is the same in all speakers.\nRecommended for original hardware.");
static const u8 sText_Desc_SoundStereo[]        = _("Play the left and right audio channel\nseperatly. Great with headphones.");
static const u8 sText_Desc_ButtonMode[]         = _("All buttons work as normal.");
static const u8 sText_Desc_ButtonMode_LR[]      = _("On some screens the L and R buttons\nact as left and right.");
static const u8 sText_Desc_ButtonMode_LA[]      = _("The L button acts as another A\nbutton for one-handed play.");
static const u8 sText_Desc_FrameType[]          = _("Choose the frame surrounding the\nwindows.");

static const u8 *const sOptionMenuItemDescriptionsVanilla[MENUITEM_VANILLA_COUNT][3] =
{
    [MENUITEM_VANILLA_TEXTSPEED]   = {sText_Desc_TextSpeed,         sText_Empty,                sText_Empty},
    [MENUITEM_VANILLA_BATTLESCENE] = {sText_Desc_BattleScene_On,    sText_Desc_BattleScene_Off, sText_Empty},
    [MENUITEM_VANILLA_BATTLESTYLE] = {sText_Desc_BattleStyle_Shift, sText_Desc_BattleStyle_Set, sText_Empty},
    [MENUITEM_VANILLA_SOUND]       = {sText_Desc_SoundMono,         sText_Desc_SoundStereo,     sText_Empty},
    [MENUITEM_VANILLA_BUTTONMODE]  = {sText_Desc_ButtonMode,        sText_Desc_ButtonMode_LR,   sText_Desc_ButtonMode_LA},
    [MENUITEM_VANILLA_FRAMETYPE]   = {sText_Desc_FrameType,         sText_Empty,                sText_Empty},
    [MENUITEM_VANILLA_CANCEL]      = {sText_Desc_Save,              sText_Empty,                sText_Empty},
};

// Hack and Nuzlocke descriptions
static const u8 sText_Desc_BattleSpeedup[]      = _("Change the battle animation speed.");
static const u8 sText_Desc_HalfDamage[]         = _("Change the damage from battle\nrule violations.");
static const u8 sText_Desc_RevealRuleNo[]       = _("Battle rules are not revealed\nafter a violation.");
static const u8 sText_Desc_RevealRuleYes[]      = _("Battle rules are revealed after a\nviolation.");
static const u8 sText_Desc_AnnounceRulesNever[] = _("Battle rules are not announced at\nthe start of a battle.");
static const u8 sText_Desc_AnnounceRulesAlways[] = _("Battle rules are announced at\nthe start of a battle.");
static const u8 sText_Desc_AnnounceRulesBosses[] = _("Battle rules are only announced\nat the start of a BOSS battle.");
static const u8 sText_Desc_ConcurrentRules[]    = _("Set how many rules can be active\nat the same time.");
static const u8 sText_Desc_InstaTrigger[]       = _("Trigger rule violations immediately\nat the start of a battle.");
static const u8 sText_Desc_NoCritsOn[]          = _("Play with no-critical-hits\nrule violations.");
static const u8 sText_Desc_NoCritsOff[]         = _("Deactivate no-critical-hits\nrule violations.");
static const u8 sText_Desc_HarderTrainers[]     = _("Trainers will be close to cap and\nevolve the team if possible.");
static const u8 sText_Desc_BossUpgrade[]        = _("Use competitive teams for boss\nbattles. Check team sheets.");
static const u8 sText_Desc_DayNightTint[]       = _("Tint the overworld based on the\ntime of day. Visual only.");
static const u8 sText_Desc_RulesInfo[]          = _("Show revealed rules in the battle\ninfo screen (SELECT in battle).");
static const u8 sText_Desc_Permadeath[]         = _("Pokémon cannot be revived.");
static const u8 sText_Desc_NoBag[]              = _("Prevent using the bag in battle.");
static const u8 sText_Desc_DupeClause[]         = _("Species dupes cannot be caught.");
static const u8 sText_Desc_MetLocClause[]       = _("Allow only one encounter per\nmet location.");

static const u8 *const sOptionMenuItemDescriptionsHack[MENUITEM_HACK_COUNT][3] =
{
    [MENUITEM_HACK_BATTLE_SPEEDUP]     = {sText_Desc_BattleSpeedup,    sText_Empty,                sText_Empty},
    [MENUITEM_HACK_50DAMAGE]           = {sText_Desc_HalfDamage,       sText_Desc_HalfDamage,      sText_Empty},
    [MENUITEM_HACK_REVEAL_RULE]        = {sText_Desc_RevealRuleNo,     sText_Desc_RevealRuleYes,   sText_Empty},
    [MENUITEM_HACK_ANNOUNCE_RULES]     = {sText_Desc_AnnounceRulesNever, sText_Desc_AnnounceRulesAlways, sText_Desc_AnnounceRulesBosses},
    [MENUITEM_HACK_CONCURRENT_RULES]   = {sText_Desc_ConcurrentRules,  sText_Desc_ConcurrentRules, sText_Desc_ConcurrentRules},
    [MENUITEM_HACK_INSTA_TRIGGER]      = {sText_Desc_InstaTrigger,     sText_Desc_InstaTrigger,    sText_Empty},
    [MENUITEM_HACK_ACTIVATE_NOCRITS]   = {sText_Desc_NoCritsOff,       sText_Desc_NoCritsOn,       sText_Empty},
    [MENUITEM_HACK_HARDER_TRAINERS]    = {sText_Desc_HarderTrainers,   sText_Desc_HarderTrainers,  sText_Empty},
    [MENUITEM_HACK_BOSS_UPGRADE]       = {sText_Desc_BossUpgrade,      sText_Desc_BossUpgrade,     sText_Empty},
    [MENUITEM_HACK_DAYNIGHT_TINT]      = {sText_Desc_DayNightTint,     sText_Desc_DayNightTint,    sText_Empty},
    [MENUITEM_HACK_RULES_INFO]         = {sText_Desc_RulesInfo,        sText_Desc_RulesInfo,       sText_Empty},
    [MENUITEM_HACK_CANCEL]             = {sText_Desc_Save,             sText_Empty,                sText_Empty},
};

static const u8 *const sOptionMenuItemDescriptionsNuzlocke[MENUITEM_NUZLOCKE_COUNT][3] =
{
    [MENUITEM_NUZLOCKE_PERMADEATH]    = {sText_Desc_Permadeath,   sText_Desc_Permadeath,   sText_Empty},
    [MENUITEM_NUZLOCKE_NOBAG]         = {sText_Desc_NoBag,        sText_Desc_NoBag,        sText_Empty},
    [MENUITEM_NUZLOCKE_DUPE_CLAUSE]   = {sText_Desc_DupeClause,   sText_Desc_DupeClause,   sText_Empty},
    [MENUITEM_NUZLOCKE_METLOC_CLAUSE] = {sText_Desc_MetLocClause, sText_Desc_MetLocClause, sText_Empty},
    [MENUITEM_NUZLOCKE_CANCEL]        = {sText_Desc_Save,         sText_Empty,             sText_Empty},
};

static const u8 *const OptionTextDescription(void)
{
    u8 menuItem = sOptions->menuCursor[sOptions->submenu];
    u8 selection = min(sOptions->sel[sOptions->submenu][menuItem], 2);

    switch (sOptions->submenu)
    {
    case MENU_VANILLA:
        if (menuItem == MENUITEM_VANILLA_TEXTSPEED || menuItem == MENUITEM_VANILLA_FRAMETYPE)
            selection = 0;
        return sOptionMenuItemDescriptionsVanilla[menuItem][selection];
    case MENU_HACK:
        if (menuItem == MENUITEM_HACK_BATTLE_SPEEDUP)
            selection = 0;
        return sOptionMenuItemDescriptionsHack[menuItem][selection];
    case MENU_NUZLOCKE:
        return sOptionMenuItemDescriptionsNuzlocke[menuItem][selection];
    }
    return sText_Empty;
}

static u8 MenuItemCount(void)
{
    switch (sOptions->submenu)
    {
    case MENU_VANILLA:  return MENUITEM_VANILLA_COUNT;
    case MENU_HACK:     return MENUITEM_HACK_COUNT;
    case MENU_NUZLOCKE: return MENUITEM_NUZLOCKE_COUNT;
    }
    return 0;
}

static u8 MenuItemCancel(void)
{
    switch (sOptions->submenu)
    {
    case MENU_VANILLA:  return MENUITEM_VANILLA_CANCEL;
    case MENU_HACK:     return MENUITEM_HACK_CANCEL;
    case MENU_NUZLOCKE: return MENUITEM_NUZLOCKE_CANCEL;
    }
    return 0;
}

// Main code
static void MainCB2(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void VBlankCB(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static const u8 sText_TopBar_Vanilla[]        = _("VANILLA");
static const u8 sText_TopBar_Vanilla_Left[]   = _("{L_BUTTON} NUZLOCKE");
static const u8 sText_TopBar_Vanilla_Right[]  = _("{R_BUTTON} HACK");
static const u8 sText_TopBar_Hack[]           = _("HACK");
static const u8 sText_TopBar_Hack_Left[]      = _("{L_BUTTON} VANILLA");
static const u8 sText_TopBar_Hack_Right[]     = _("{R_BUTTON} NUZLOCKE");
static const u8 sText_TopBar_Nuzlocke[]       = _("NUZLOCKE");
static const u8 sText_TopBar_Nuzlocke_Left[]  = _("{L_BUTTON} HACK");
static const u8 sText_TopBar_Nuzlocke_Right[] = _("{R_BUTTON} VANILLA");

static void DrawTopBarText(void)
{
    const u8 color[3] = { TEXT_DYNAMIC_COLOR_6, TEXT_COLOR_WHITE, TEXT_COLOR_OPTIONS_GRAY_FG };

    FillWindowPixelBuffer(WIN_TOPBAR, PIXEL_FILL(15));
    switch (sOptions->submenu)
    {
        case MENU_VANILLA:
            AddTextPrinterParameterized3(WIN_TOPBAR, FONT_SMALL, 103, 1, color, 0, sText_TopBar_Vanilla);
            AddTextPrinterParameterized3(WIN_TOPBAR, FONT_SMALL, 2, 1, color, 0, sText_TopBar_Vanilla_Left);
            AddTextPrinterParameterized3(WIN_TOPBAR, FONT_SMALL, 178, 1, color, 0, sText_TopBar_Vanilla_Right);
            break;
        case MENU_HACK:
            AddTextPrinterParameterized3(WIN_TOPBAR, FONT_SMALL, 110, 1, color, 0, sText_TopBar_Hack);
            AddTextPrinterParameterized3(WIN_TOPBAR, FONT_SMALL, 2, 1, color, 0, sText_TopBar_Hack_Left);
            AddTextPrinterParameterized3(WIN_TOPBAR, FONT_SMALL, 178, 1, color, 0, sText_TopBar_Hack_Right);
            break;
        case MENU_NUZLOCKE:
            AddTextPrinterParameterized3(WIN_TOPBAR, FONT_SMALL, 99, 1, color, 0, sText_TopBar_Nuzlocke);
            AddTextPrinterParameterized3(WIN_TOPBAR, FONT_SMALL, 2, 1, color, 0, sText_TopBar_Nuzlocke_Left);
            AddTextPrinterParameterized3(WIN_TOPBAR, FONT_SMALL, 178, 1, color, 0, sText_TopBar_Nuzlocke_Right);
            break;
    }
    PutWindowTilemap(WIN_TOPBAR);
    CopyWindowToVram(WIN_TOPBAR, COPYWIN_FULL);
}

static void DrawOptionMenuTexts(void) //left side text
{
    u8 i;
    u8 firstItem = sOptions->menuCursor[sOptions->submenu] - sOptions->visibleCursor[sOptions->submenu];
    u8 itemsToDraw = min(OPTIONS_ON_SCREEN, MenuItemCount());

    FillWindowPixelBuffer(WIN_OPTIONS, PIXEL_FILL(1));
    for (i = 0; i < itemsToDraw; i++)
        DrawLeftSideOptionText(firstItem + i, (i * Y_DIFF) + 1);
    CopyWindowToVram(WIN_OPTIONS, COPYWIN_FULL);
}

static void DrawDescriptionText(void)
{
    u8 color_gray[3];
    color_gray[0] = TEXT_COLOR_TRANSPARENT;
    color_gray[1] = TEXT_COLOR_OPTIONS_GRAY_FG;
    color_gray[2] = TEXT_COLOR_OPTIONS_GRAY_SHADOW;
        
    FillWindowPixelBuffer(WIN_DESCRIPTION, PIXEL_FILL(1));
    AddTextPrinterParameterized4(WIN_DESCRIPTION, FONT_NORMAL, 8, 1, 0, 0, color_gray, TEXT_SKIP_DRAW, OptionTextDescription());
    CopyWindowToVram(WIN_DESCRIPTION, COPYWIN_FULL);
}

static void DrawLeftSideOptionText(int selection, int y)
{
    u8 color_yellow[3];
    u8 color_gray[3];

    color_yellow[0] = TEXT_COLOR_TRANSPARENT;
    color_yellow[1] = TEXT_COLOR_OPTIONS_ORANGE_FG;
    color_yellow[2] = TEXT_COLOR_OPTIONS_ORANGE_SHADOW;
    color_gray[0] = TEXT_COLOR_TRANSPARENT;
    color_gray[1] = TEXT_COLOR_OPTIONS_GRAY_LIGHT_FG;
    color_gray[2] = TEXT_COLOR_OPTIONS_GRAY_SHADOW;

    if (CheckConditions(selection))
        AddTextPrinterParameterized4(WIN_OPTIONS, FONT_NORMAL, 8, y, 0, 0, color_yellow, TEXT_SKIP_DRAW, OptionTextRight(selection));
    else
        AddTextPrinterParameterized4(WIN_OPTIONS, FONT_NORMAL, 8, y, 0, 0, color_gray, TEXT_SKIP_DRAW, OptionTextRight(selection));
}

static void DrawRightSideChoiceText(const u8 *text, int x, int y, bool8 choosen, bool8 active)
{
    u8 color_red[3];
    u8 color_gray[3];

    if (active)
    {
        color_red[0] = TEXT_COLOR_TRANSPARENT;
        color_red[1] = TEXT_COLOR_OPTIONS_RED_FG;
        color_red[2] = TEXT_COLOR_OPTIONS_RED_SHADOW;
        color_gray[0] = TEXT_COLOR_TRANSPARENT;
        color_gray[1] = TEXT_COLOR_OPTIONS_GRAY_FG;
        color_gray[2] = TEXT_COLOR_OPTIONS_GRAY_SHADOW;
    }
    else
    {
        color_red[0] = TEXT_COLOR_TRANSPARENT;
        color_red[1] = TEXT_COLOR_OPTIONS_RED_DARK_FG;
        color_red[2] = TEXT_COLOR_OPTIONS_RED_DARK_SHADOW;
        color_gray[0] = TEXT_COLOR_TRANSPARENT;
        color_gray[1] = TEXT_COLOR_OPTIONS_GRAY_LIGHT_FG;
        color_gray[2] = TEXT_COLOR_OPTIONS_GRAY_SHADOW;
    }


    if (choosen)
        AddTextPrinterParameterized4(WIN_OPTIONS, FONT_NORMAL, x, y, 0, 0, color_red, TEXT_SKIP_DRAW, text);
    else
        AddTextPrinterParameterized4(WIN_OPTIONS, FONT_NORMAL, x, y, 0, 0, color_gray, TEXT_SKIP_DRAW, text);
}

static void DrawChoices(u32 id, int y) //right side draw function
{
    const struct ItemFunctions *functions = NULL;

    switch (sOptions->submenu)
    {
    case MENU_VANILLA:  functions = &sItemFunctionsVanilla[id];  break;
    case MENU_HACK:     functions = &sItemFunctionsHack[id];     break;
    case MENU_NUZLOCKE: functions = &sItemFunctionsNuzlocke[id]; break;
    }
    if (functions != NULL && functions->drawChoices != NULL)
        functions->drawChoices(sOptions->sel[sOptions->submenu][id], y);
}

static void HighlightOptionMenuItem(void)
{
    int cursor = sOptions->visibleCursor[sOptions->submenu];

    SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(Y_DIFF, 224));
    SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(cursor * Y_DIFF + 24, cursor * Y_DIFF + 40));
}

void CB2_InitOptionPlusMenu(void)
{
    u32 i;
    switch (gMain.state)
    {
    default:
    case 0:
        SetVBlankCallback(NULL);
        gMain.state++;
        break;
    case 1:
        DmaClearLarge16(3, (void *)(VRAM), VRAM_SIZE, 0x1000);
        DmaClear32(3, OAM, OAM_SIZE);
        DmaClear16(3, PLTT, PLTT_SIZE);
        SetGpuReg(REG_OFFSET_DISPCNT, 0);
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(0, sOptionMenuBgTemplates, ARRAY_COUNT(sOptionMenuBgTemplates));
        ResetBgPositions();
        InitWindows(sOptionMenuWinTemplates);
        DeactivateAllTextPrinters();
        SetGpuReg(REG_OFFSET_WIN0H, 0);
        SetGpuReg(REG_OFFSET_WIN0V, 0);
        SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG0 | WININ_WIN1_BG0 | WININ_WIN0_OBJ);
        SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG0 | WINOUT_WIN01_BG1 | WINOUT_WIN01_OBJ | WINOUT_WIN01_CLR);
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_EFFECT_DARKEN | BLDCNT_TGT1_BG0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        SetGpuReg(REG_OFFSET_BLDY, 4);
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON | DISPCNT_WIN1_ON | DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
        ShowBg(0);
        ShowBg(1);
        gMain.state++;
        break;
    case 2:
        ResetPaletteFade();
        ScanlineEffect_Stop();
        ResetTasks();
        ResetSpriteData();
        gMain.state++;
        break;
    case 3:
        LoadBgTiles(1, GetWindowFrameTilesPal(gSaveBlock2Ptr->optionsWindowFrameType)->tiles, 0x120, 0x1A2);
        gMain.state++;
        break;
    case 4:
        LoadPalette(sOptionMenuBg_Pal, 0, sizeof(sOptionMenuBg_Pal));
        LoadPalette(GetWindowFrameTilesPal(gSaveBlock2Ptr->optionsWindowFrameType)->pal, 0x70, 0x20);
        gMain.state++;
        break;
    case 5:
        LoadPalette(sOptionMenuText_Pal, 16, sizeof(sOptionMenuText_Pal));
        gMain.state++;
        break;
    case 6:
        sOptions = AllocZeroed(sizeof(*sOptions));
        sOptions->sel[MENU_VANILLA][MENUITEM_VANILLA_TEXTSPEED]   = gSaveBlock2Ptr->optionsTextSpeed;
        sOptions->sel[MENU_VANILLA][MENUITEM_VANILLA_BATTLESCENE] = gSaveBlock2Ptr->optionsBattleSceneOff;
        sOptions->sel[MENU_VANILLA][MENUITEM_VANILLA_BATTLESTYLE] = gSaveBlock2Ptr->optionsBattleStyle;
        sOptions->sel[MENU_VANILLA][MENUITEM_VANILLA_SOUND]       = gSaveBlock2Ptr->optionsSound;
        sOptions->sel[MENU_VANILLA][MENUITEM_VANILLA_BUTTONMODE]  = gSaveBlock2Ptr->optionsButtonMode;
        sOptions->sel[MENU_VANILLA][MENUITEM_VANILLA_FRAMETYPE]   = gSaveBlock2Ptr->optionsWindowFrameType;

        sOptions->sel[MENU_HACK][MENUITEM_HACK_BATTLE_SPEEDUP]   = gSaveBlock2Ptr->battleSpeed;
        sOptions->sel[MENU_HACK][MENUITEM_HACK_50DAMAGE]         = gSaveBlock2Ptr->halfDamage;
        sOptions->sel[MENU_HACK][MENUITEM_HACK_REVEAL_RULE]      = gSaveBlock2Ptr->revealRule;
        sOptions->sel[MENU_HACK][MENUITEM_HACK_ANNOUNCE_RULES]   = gSaveBlock2Ptr->announceRules;
        sOptions->sel[MENU_HACK][MENUITEM_HACK_CONCURRENT_RULES] = gSaveBlock2Ptr->concurrentRules;
        sOptions->sel[MENU_HACK][MENUITEM_HACK_INSTA_TRIGGER]    = gSaveBlock2Ptr->instaRuleTrigger;
        sOptions->sel[MENU_HACK][MENUITEM_HACK_ACTIVATE_NOCRITS] = gSaveBlock2Ptr->activateNoCritRule;
        sOptions->sel[MENU_HACK][MENUITEM_HACK_HARDER_TRAINERS]  = gSaveBlock2Ptr->harderTrainers;
        sOptions->sel[MENU_HACK][MENUITEM_HACK_BOSS_UPGRADE]     = gSaveBlock2Ptr->bossUpgrade;
        sOptions->sel[MENU_HACK][MENUITEM_HACK_DAYNIGHT_TINT]    = gSaveBlock2Ptr->dayNightTint;
        sOptions->sel[MENU_HACK][MENUITEM_HACK_RULES_INFO]       = gSaveBlock2Ptr->rulesInfo;

        sOptions->sel[MENU_NUZLOCKE][MENUITEM_NUZLOCKE_PERMADEATH]    = gSaveBlock2Ptr->permadeath;
        sOptions->sel[MENU_NUZLOCKE][MENUITEM_NUZLOCKE_NOBAG]         = gSaveBlock2Ptr->noBagInBattle;
        sOptions->sel[MENU_NUZLOCKE][MENUITEM_NUZLOCKE_DUPE_CLAUSE]   = gSaveBlock2Ptr->dupeClause;
        sOptions->sel[MENU_NUZLOCKE][MENUITEM_NUZLOCKE_METLOC_CLAUSE] = gSaveBlock2Ptr->metLocClause;

        sOptions->submenu = MENU_VANILLA;

        gMain.state++;
        break;
    case 7:
        PutWindowTilemap(WIN_TOPBAR);
        DrawTopBarText();
        gMain.state++;
        break;
    case 8:
        PutWindowTilemap(WIN_DESCRIPTION);
        DrawDescriptionText();
        gMain.state++;
        break;
    case 9:
        PutWindowTilemap(WIN_OPTIONS);
        DrawOptionMenuTexts();
        gMain.state++;
        break;
    case 10:
        CreateTask(Task_OptionMenuFadeIn, 0);
        
        sOptions->arrowTaskId = AddScrollIndicatorArrowPairParameterized(SCROLL_ARROW_UP, 240 / 2, 20, 110, MenuItemCount() - 1, 110, 110, 0);
        sOptions->arrowItemCount = MenuItemCount();

        for (i = 0; i < min(OPTIONS_ON_SCREEN, MenuItemCount()); i++)
            DrawChoices(i, i * Y_DIFF);

        HighlightOptionMenuItem();

        CopyWindowToVram(WIN_OPTIONS, COPYWIN_FULL);
        gMain.state++;
        break;
    case 11:
        DrawBgWindowFrames();
        gMain.state++;
        break;
    case 12:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0x10, 0, RGB_BLACK);
        SetVBlankCallback(VBlankCB);
        SetMainCallback2(MainCB2);
        return;
    }
}

static void Task_OptionMenuFadeIn(u8 taskId)
{
    if (!gPaletteFade.active)
        gTasks[taskId].func = Task_OptionMenuProcessInput;
}

static void Task_OptionMenuProcessInput(u8 taskId)
{
    const struct ItemFunctions *functions = NULL;
    int cursor;

    if (sOptions->submenu >= MENU_COUNT)
        return;

    u8 optionsToDraw = min(OPTIONS_ON_SCREEN , MenuItemCount());
    if (JOY_NEW(A_BUTTON))
    {
        if (sOptions->menuCursor[sOptions->submenu] == MenuItemCancel())
            gTasks[taskId].func = Task_OptionMenuSave;
    }
    else if (JOY_NEW(B_BUTTON))
    {
        gTasks[taskId].func = Task_OptionMenuSave;
    }
    else if (JOY_NEW(DPAD_UP))
    {
        if (sOptions->visibleCursor[sOptions->submenu] == NUM_OPTIONS_FROM_BORDER) // don't advance visible cursor until scrolled to the bottom
        {
            if (--sOptions->menuCursor[sOptions->submenu] == 0)
                sOptions->visibleCursor[sOptions->submenu]--;
            else
                ScrollMenu(1);
        }
        else
        {
            if (--sOptions->menuCursor[sOptions->submenu] < 0) // Scroll all the way to the bottom.
            {
                sOptions->visibleCursor[sOptions->submenu] = sOptions->menuCursor[sOptions->submenu] = optionsToDraw-2;
                ScrollAll(0);
                sOptions->visibleCursor[sOptions->submenu] = optionsToDraw-1;
                sOptions->menuCursor[sOptions->submenu] = MenuItemCount() - 1;
            }
            else
            {
                sOptions->visibleCursor[sOptions->submenu]--;
            }
        }
        HighlightOptionMenuItem();
        DrawDescriptionText();
    }
    else if (JOY_NEW(DPAD_DOWN))
    {
        if (sOptions->visibleCursor[sOptions->submenu] == optionsToDraw-2) // don't advance visible cursor until scrolled to the bottom
        {
            if (++sOptions->menuCursor[sOptions->submenu] == MenuItemCount() - 1)
                sOptions->visibleCursor[sOptions->submenu]++;
            else
                ScrollMenu(0);
        }
        else
        {
            if (++sOptions->menuCursor[sOptions->submenu] >= MenuItemCount()-1) // Scroll all the way to the top.
            {
                sOptions->visibleCursor[sOptions->submenu] = optionsToDraw-2;
                sOptions->menuCursor[sOptions->submenu] = MenuItemCount() - optionsToDraw-1;
                ScrollAll(1);
                sOptions->visibleCursor[sOptions->submenu] = sOptions->menuCursor[sOptions->submenu] = 0;
            }
            else
            {
                sOptions->visibleCursor[sOptions->submenu]++;
            }
        }
        HighlightOptionMenuItem();
        DrawDescriptionText();
    }
    else if (JOY_NEW(DPAD_LEFT | DPAD_RIGHT))
    {
        cursor = sOptions->menuCursor[sOptions->submenu];
        switch (sOptions->submenu)
        {
        case MENU_VANILLA:  functions = &sItemFunctionsVanilla[cursor];  break;
        case MENU_HACK:     functions = &sItemFunctionsHack[cursor];     break;
        case MENU_NUZLOCKE: functions = &sItemFunctionsNuzlocke[cursor]; break;
        }
        if (CheckConditions(cursor) && functions != NULL && functions->processInput != NULL)
        {
            u8 previousOption = sOptions->sel[sOptions->submenu][cursor];
            sOptions->sel[sOptions->submenu][cursor] = functions->processInput(previousOption);
            ReDrawAll();
            DrawDescriptionText();

            if (previousOption != sOptions->sel[sOptions->submenu][cursor])
                DrawChoices(cursor, sOptions->visibleCursor[sOptions->submenu] * Y_DIFF);
        }
    }
    else if (JOY_NEW(R_BUTTON))
    {
        sOptions->submenu = (sOptions->submenu + 1) % MENU_COUNT;

        DrawTopBarText();
        ReDrawAll();
        HighlightOptionMenuItem();
        DrawDescriptionText();
    }
    else if (JOY_NEW(L_BUTTON))
    {
        sOptions->submenu = (sOptions->submenu + MENU_COUNT - 1) % MENU_COUNT;
        
        DrawTopBarText();
        ReDrawAll();
        HighlightOptionMenuItem();
        DrawDescriptionText();
    }
}

static void Task_OptionMenuSave(u8 taskId)
{
    gSaveBlock2Ptr->optionsTextSpeed       = sOptions->sel[MENU_VANILLA][MENUITEM_VANILLA_TEXTSPEED];
    gSaveBlock2Ptr->optionsBattleSceneOff  = sOptions->sel[MENU_VANILLA][MENUITEM_VANILLA_BATTLESCENE];
    gSaveBlock2Ptr->optionsBattleStyle     = sOptions->sel[MENU_VANILLA][MENUITEM_VANILLA_BATTLESTYLE];
    gSaveBlock2Ptr->optionsSound           = sOptions->sel[MENU_VANILLA][MENUITEM_VANILLA_SOUND];
    gSaveBlock2Ptr->optionsButtonMode      = sOptions->sel[MENU_VANILLA][MENUITEM_VANILLA_BUTTONMODE];
    gSaveBlock2Ptr->optionsWindowFrameType = sOptions->sel[MENU_VANILLA][MENUITEM_VANILLA_FRAMETYPE];

    gSaveBlock2Ptr->battleSpeed        = sOptions->sel[MENU_HACK][MENUITEM_HACK_BATTLE_SPEEDUP];
    gSaveBlock2Ptr->halfDamage         = sOptions->sel[MENU_HACK][MENUITEM_HACK_50DAMAGE];
    gSaveBlock2Ptr->revealRule         = sOptions->sel[MENU_HACK][MENUITEM_HACK_REVEAL_RULE];
    gSaveBlock2Ptr->announceRules      = sOptions->sel[MENU_HACK][MENUITEM_HACK_ANNOUNCE_RULES];
    gSaveBlock2Ptr->concurrentRules    = sOptions->sel[MENU_HACK][MENUITEM_HACK_CONCURRENT_RULES];
    gSaveBlock2Ptr->instaRuleTrigger   = sOptions->sel[MENU_HACK][MENUITEM_HACK_INSTA_TRIGGER];
    gSaveBlock2Ptr->activateNoCritRule = sOptions->sel[MENU_HACK][MENUITEM_HACK_ACTIVATE_NOCRITS];
    gSaveBlock2Ptr->harderTrainers     = sOptions->sel[MENU_HACK][MENUITEM_HACK_HARDER_TRAINERS];
    gSaveBlock2Ptr->bossUpgrade        = sOptions->sel[MENU_HACK][MENUITEM_HACK_BOSS_UPGRADE];
    gSaveBlock2Ptr->dayNightTint       = sOptions->sel[MENU_HACK][MENUITEM_HACK_DAYNIGHT_TINT];
    gSaveBlock2Ptr->rulesInfo          = sOptions->sel[MENU_HACK][MENUITEM_HACK_RULES_INFO];

    gSaveBlock2Ptr->permadeath    = sOptions->sel[MENU_NUZLOCKE][MENUITEM_NUZLOCKE_PERMADEATH];
    gSaveBlock2Ptr->noBagInBattle = sOptions->sel[MENU_NUZLOCKE][MENUITEM_NUZLOCKE_NOBAG];
    gSaveBlock2Ptr->dupeClause    = sOptions->sel[MENU_NUZLOCKE][MENUITEM_NUZLOCKE_DUPE_CLAUSE];
    gSaveBlock2Ptr->metLocClause  = sOptions->sel[MENU_NUZLOCKE][MENUITEM_NUZLOCKE_METLOC_CLAUSE];

    VarSet(VAR_BATTLE_SPEED, gSaveBlock2Ptr->battleSpeed);
    VarSet(VAR_ENABLE_DNS, gSaveBlock2Ptr->dayNightTint);

    if (gSaveBlock2Ptr->revealRule)
        FlagSet(FLAG_REVEAL_RULE);
    else
        FlagClear(FLAG_REVEAL_RULE);

    if (gSaveBlock2Ptr->noBagInBattle)
        FlagSet(FLAG_NO_BAG_IN_BATTLE);
    else
        FlagClear(FLAG_NO_BAG_IN_BATTLE);

    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 0x10, RGB_BLACK);
    gTasks[taskId].func = Task_OptionMenuFadeOut;
}

static void Task_OptionMenuFadeOut(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        DestroyTask(taskId);
        FreeAllWindowBuffers();
        FREE_AND_SET_NULL(sOptions);
        SetMainCallback2(gMain.savedCallback);
    }
}

static void ScrollMenu(int direction)
{
    int menuItem, pos;
    u8 optionsToDraw = min(OPTIONS_ON_SCREEN, MenuItemCount());

    if (direction == 0) // scroll down
        menuItem = sOptions->menuCursor[sOptions->submenu] + NUM_OPTIONS_FROM_BORDER, pos = optionsToDraw - 1;
    else
        menuItem = sOptions->menuCursor[sOptions->submenu] - NUM_OPTIONS_FROM_BORDER, pos = 0;

    // Hide one
    ScrollWindow(WIN_OPTIONS, direction, Y_DIFF, PIXEL_FILL(0));
    // Show one
    FillWindowPixelRect(WIN_OPTIONS, PIXEL_FILL(1), 0, Y_DIFF * pos, 26 * 8, Y_DIFF);
    // Print
    DrawChoices(menuItem, pos * Y_DIFF);
    DrawLeftSideOptionText(menuItem, (pos * Y_DIFF) + 1);
    CopyWindowToVram(WIN_OPTIONS, COPYWIN_GFX);
}
static void ScrollAll(int direction) // to bottom or top
{
    int i, y, menuItem, pos;
    int scrollCount;
    u8 optionsToDraw = min(OPTIONS_ON_SCREEN, MenuItemCount());

    scrollCount = MenuItemCount() - optionsToDraw;

    // Move items up/down
    ScrollWindow(WIN_OPTIONS, direction, Y_DIFF * scrollCount, PIXEL_FILL(1));

    // Clear moved items
    if (direction == 0)
    {
        y = optionsToDraw - scrollCount;
        if (y < 0)
            y = optionsToDraw;
        y *= Y_DIFF;
    }
    else
    {
        y = 0;
    }

    FillWindowPixelRect(WIN_OPTIONS, PIXEL_FILL(1), 0, y, 26 * 8, Y_DIFF * scrollCount);
    // Print new texts
    for (i = 0; i < scrollCount; i++)
    {
        if (direction == 0) // From top to bottom
            menuItem = MenuItemCount() - 1 - i, pos = optionsToDraw - 1 - i;
        else // From bottom to top
            menuItem = i, pos = i;
        DrawChoices(menuItem, pos * Y_DIFF);
        DrawLeftSideOptionText(menuItem, (pos * Y_DIFF) + 1);
    }
    CopyWindowToVram(WIN_OPTIONS, COPYWIN_GFX);
}

// Process Input functions ****GENERIC****
static int GetMiddleX(const u8 *txt1, const u8 *txt2, const u8 *txt3)
{
    int xMid;
    int widthLeft = GetStringWidth(1, txt1, 0);
    int widthMid = GetStringWidth(1, txt2, 0);
    int widthRight = GetStringWidth(1, txt3, 0);

    widthMid -= (198 - 104);
    xMid = (widthLeft - widthMid - widthRight) / 2 + 104;
    return xMid;
}

static int XOptions_ProcessInput(int x, int selection)
{
    if (JOY_NEW(DPAD_RIGHT))
    {
        if (++selection > (x - 1))
            selection = 0;
    }
    if (JOY_NEW(DPAD_LEFT))
    {
        if (--selection < 0)
            selection = (x - 1);
    }
    return selection;
}

static int ProcessInput_Options_Two(int selection)
{
    if (JOY_NEW(DPAD_LEFT | DPAD_RIGHT))
        selection ^= 1;

    return selection;
}

static int ProcessInput_Options_Three(int selection)
{
    return XOptions_ProcessInput(3, selection);
}

static int ProcessInput_Options_Four(int selection)
{
    return XOptions_ProcessInput(4, selection);
}

// Process Input functions ****SPECIFIC****
static int ProcessInput_Sound(int selection)
{
    if (JOY_NEW(DPAD_LEFT | DPAD_RIGHT))
    {
        selection ^= 1;
        SetPokemonCryStereo(selection);
    }

    return selection;
}

static int ProcessInput_FrameType(int selection)
{
    if (JOY_NEW(DPAD_RIGHT))
    {
        if (selection < WINDOW_FRAMES_COUNT - 1)
            selection++;
        else
            selection = 0;

        LoadBgTiles(1, GetWindowFrameTilesPal(selection)->tiles, 0x120, 0x1A2);
        LoadPalette(GetWindowFrameTilesPal(selection)->pal, 0x70, 0x20);
    }
    if (JOY_NEW(DPAD_LEFT))
    {
        if (selection != 0)
            selection--;
        else
            selection = WINDOW_FRAMES_COUNT - 1;

        LoadBgTiles(1, GetWindowFrameTilesPal(selection)->tiles, 0x120, 0x1A2);
        LoadPalette(GetWindowFrameTilesPal(selection)->pal, 0x70, 0x20);
    }
    return selection;
}

// Draw Choices functions ****GENERIC****
static void DrawOptionMenuChoice(const u8 *text, u8 x, u8 y, u8 style, bool8 active)
{
    bool8 choosen = FALSE;
    if (style != 0)
        choosen = TRUE;

    DrawRightSideChoiceText(text, x, y+1, choosen, active);
}

static void ReDrawAll(void)
{
    u8 menuItem = sOptions->menuCursor[sOptions->submenu] - sOptions->visibleCursor[sOptions->submenu];
    u8 i;
    u8 optionsToDraw = min(OPTIONS_ON_SCREEN, MenuItemCount());

    if (MenuItemCount() <= OPTIONS_ON_SCREEN) // Draw or delete the scrolling arrows based on options in the menu
    {
        if (sOptions->arrowTaskId != TASK_NONE)
        {
            RemoveScrollIndicatorArrowPair(sOptions->arrowTaskId);
            sOptions->arrowTaskId = TASK_NONE;
        }
    }
    else
    {
        if (sOptions->arrowTaskId != TASK_NONE && sOptions->arrowItemCount != MenuItemCount())
        {
            RemoveScrollIndicatorArrowPair(sOptions->arrowTaskId);
            sOptions->arrowTaskId = TASK_NONE;
        }
        if (sOptions->arrowTaskId == TASK_NONE)
        {
            sOptions->arrowTaskId = AddScrollIndicatorArrowPairParameterized(SCROLL_ARROW_UP, 240 / 2, 20, 110, MenuItemCount() - 1, 110, 110, 0);
            sOptions->arrowItemCount = MenuItemCount();
        }
    }

    FillWindowPixelBuffer(WIN_OPTIONS, PIXEL_FILL(1));
    for (i = 0; i < optionsToDraw; i++)
    {
        DrawChoices(menuItem+i, i * Y_DIFF);
        DrawLeftSideOptionText(menuItem+i, (i * Y_DIFF) + 1);
    }
    CopyWindowToVram(WIN_OPTIONS, COPYWIN_GFX);
}

// Process Input functions ****SPECIFIC****
static void DrawChoices_TextSpeed(int selection, int y)
{
    int xMid = GetMiddleX(gText_TextSpeedSlow, gText_TextSpeedFast, gText_TextSpeedInstant);

    DrawOptionMenuChoice(gText_TextSpeedSlow, 104, y, selection == 0, TRUE);
    DrawOptionMenuChoice(gText_TextSpeedFast, xMid, y, selection == 1, TRUE);
    DrawOptionMenuChoice(gText_TextSpeedInstant, GetStringRightAlignXOffset(FONT_NORMAL, gText_TextSpeedInstant, 198), y, selection == 2, TRUE);
}

static void DrawChoices_BattleScene(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_VANILLA_BATTLESCENE);
    u8 styles[2] = {0};
    styles[selection] = 1;

    DrawOptionMenuChoice(gText_BattleSceneOn, 104, y, styles[0], active);
    DrawOptionMenuChoice(gText_BattleSceneOff, GetStringRightAlignXOffset(FONT_NORMAL, gText_BattleSceneOff, 198), y, styles[1], active);
}

static void DrawChoices_BattleStyle(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_VANILLA_BATTLESTYLE);
    u8 styles[2] = {0};
    styles[selection] = 1;

    DrawOptionMenuChoice(gText_BattleStyleShift, 104, y, styles[0], active);
    DrawOptionMenuChoice(gText_BattleStyleSet, GetStringRightAlignXOffset(FONT_NORMAL, gText_BattleStyleSet, 198), y, styles[1], active);
}

static void DrawChoices_Sound(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_VANILLA_SOUND);
    u8 styles[2] = {0};
    styles[selection] = 1;

    DrawOptionMenuChoice(gText_SoundMono, 104, y, styles[0], active);
    DrawOptionMenuChoice(gText_SoundStereo, GetStringRightAlignXOffset(FONT_NORMAL, gText_SoundStereo, 198), y, styles[1], active);
}

static void DrawChoices_ButtonMode(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_VANILLA_BUTTONMODE);
    u8 styles[3] = {0};
    int xMid = GetMiddleX(gText_ButtonTypeNormal, gText_ButtonTypeLR, gText_ButtonTypeLEqualsA);
    styles[selection] = 1;

    DrawOptionMenuChoice(gText_ButtonTypeNormal, 104, y, styles[0], active);
    DrawOptionMenuChoice(gText_ButtonTypeLR, xMid, y, styles[1], active);
    DrawOptionMenuChoice(gText_ButtonTypeLEqualsA, GetStringRightAlignXOffset(1, gText_ButtonTypeLEqualsA, 198), y, styles[2], active);
}

static void DrawChoices_FrameType(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_VANILLA_FRAMETYPE);
    u8 text[16];
    u8 n = selection + 1;
    u16 i;

    for (i = 0; gText_FrameTypeNumber[i] != EOS && i <= 5; i++)
        text[i] = gText_FrameTypeNumber[i];

    // Convert a number to decimal string
    if (n / 10 != 0)
    {
        text[i] = n / 10 + CHAR_0;
        i++;
        text[i] = n % 10 + CHAR_0;
        i++;
    }
    else
    {
        text[i] = n % 10 + CHAR_0;
        i++;
        text[i] = 0x77;
        i++;
    }

    text[i] = EOS;

    DrawOptionMenuChoice(gText_FrameType, 104, y, 0, active);
    DrawOptionMenuChoice(text, 128, y, 1, active);
}

static void DrawChoices_BattleSpeedup(int selection, int y)
{
    const u8 *const choices[] =
    {
        gText_BattleSpeedup1x,
        gText_BattleSpeedup2x,
        gText_BattleSpeedup3x,
        gText_BattleSpeedup4x,
    };
    u8 i;

    for (i = 0; i < ARRAY_COUNT(choices); i++)
        DrawOptionMenuChoice(choices[i], 104 + i * 27, y, selection == i, TRUE);
}

static void DrawChoices_HalfDamage(int selection, int y)
{
    DrawOptionMenuChoice(gText_ViolationDamage100, 104, y, selection == 0, TRUE);
    DrawOptionMenuChoice(gText_ViolationDamage50, GetStringRightAlignXOffset(FONT_NORMAL, gText_ViolationDamage50, 198), y, selection == 1, TRUE);
}

static void DrawChoices_RevealRule(int selection, int y)
{
    DrawOptionMenuChoice(gText_OptionOff, 104, y, selection == 0, TRUE);
    DrawOptionMenuChoice(gText_OptionOn, GetStringRightAlignXOffset(FONT_NORMAL, gText_OptionOn, 198), y, selection == 1, TRUE);
}

static void DrawChoices_AnnounceRules(int selection, int y)
{
    DrawOptionMenuChoice(gText_OptionOff, 104, y, selection == ANNOUNCE_RULES_NEVER, TRUE);
    DrawOptionMenuChoice(gText_OptionOn, 134, y, selection == ANNOUNCE_RULES_ALWAYS, TRUE);
    DrawOptionMenuChoice(gText_AnnounceRulesBosses, GetStringRightAlignXOffset(FONT_NORMAL, gText_AnnounceRulesBosses, 198), y, selection == ANNOUNCE_RULES_BOSSES_ONLY, TRUE);
}

static void DrawChoices_ConcurrentRules(int selection, int y)
{
    DrawOptionMenuChoice(gText_ConcurrentRules1, 104, y, selection == 0, TRUE);
    DrawOptionMenuChoice(gText_ConcurrentRules2, 145, y, selection == 1, TRUE);
    DrawOptionMenuChoice(gText_ConcurrentRules3, GetStringRightAlignXOffset(FONT_NORMAL, gText_ConcurrentRules3, 198), y, selection == 2, TRUE);
}

static void DrawChoices_OptionOnOff(int selection, int y)
{
    DrawOptionMenuChoice(gText_OptionOff, 104, y, selection == 0, TRUE);
    DrawOptionMenuChoice(gText_OptionOn, GetStringRightAlignXOffset(FONT_NORMAL, gText_OptionOn, 198), y, selection == 1, TRUE);
}

static void DrawChoices_NoCrits(int selection, int y)
{
    DrawOptionMenuChoice(gText_OptionInactive, 104, y, selection == 0, TRUE);
    DrawOptionMenuChoice(gText_OptionActive, GetStringRightAlignXOffset(FONT_NORMAL, gText_OptionActive, 198), y, selection == 1, TRUE);
}

static void DrawChoices_Permadeath(int selection, int y)
{
    DrawOptionMenuChoice(gText_PermaDeathOff, 104, y, selection == 0, TRUE);
    DrawOptionMenuChoice(gText_PermaDeathOn, GetStringRightAlignXOffset(FONT_NORMAL, gText_PermaDeathOn, 198), y, selection == 1, TRUE);
}


// Background tilemap
#define TILE_TOP_CORNER_L 0x1A2 // 418
#define TILE_TOP_EDGE     0x1A3 // 419
#define TILE_TOP_CORNER_R 0x1A4 // 420
#define TILE_LEFT_EDGE    0x1A5 // 421
#define TILE_RIGHT_EDGE   0x1A7 // 423
#define TILE_BOT_CORNER_L 0x1A8 // 424
#define TILE_BOT_EDGE     0x1A9 // 425
#define TILE_BOT_CORNER_R 0x1AA // 426

static void DrawBgWindowFrames(void)
{
    //                     bg, tile,              x, y, width, height, palNum
    // Option Texts window
    FillBgTilemapBufferRect(1, TILE_TOP_CORNER_L,  1,  2,  1,  1,  7);
    FillBgTilemapBufferRect(1, TILE_TOP_EDGE,      2,  2, 26,  1,  7);
    FillBgTilemapBufferRect(1, TILE_TOP_CORNER_R, 28,  2,  1,  1,  7);
    FillBgTilemapBufferRect(1, TILE_LEFT_EDGE,     1,  3,  1, 16,  7);
    FillBgTilemapBufferRect(1, TILE_RIGHT_EDGE,   28,  3,  1, 16,  7);
    FillBgTilemapBufferRect(1, TILE_BOT_CORNER_L,  1, 13,  1,  1,  7);
    FillBgTilemapBufferRect(1, TILE_BOT_EDGE,      2, 13, 26,  1,  7);
    FillBgTilemapBufferRect(1, TILE_BOT_CORNER_R, 28, 13,  1,  1,  7);

    // Description window
    FillBgTilemapBufferRect(1, TILE_TOP_CORNER_L,  1, 14,  1,  1,  7);
    FillBgTilemapBufferRect(1, TILE_TOP_EDGE,      2, 14, 27,  1,  7);
    FillBgTilemapBufferRect(1, TILE_TOP_CORNER_R, 28, 14,  1,  1,  7);
    FillBgTilemapBufferRect(1, TILE_LEFT_EDGE,     1, 15,  1,  2,  7);
    FillBgTilemapBufferRect(1, TILE_RIGHT_EDGE,   28, 15,  1,  2,  7);
    FillBgTilemapBufferRect(1, TILE_BOT_CORNER_L,  1, 19,  1,  1,  7);
    FillBgTilemapBufferRect(1, TILE_BOT_EDGE,      2, 19, 27,  1,  7);
    FillBgTilemapBufferRect(1, TILE_BOT_CORNER_R, 28, 19,  1,  1,  7);

    CopyBgTilemapBufferToVram(1);
}
