#include "global.h"
#include "battle.h"
#include "battle_ai_switch.h"
#include "battle_ai_util.h"
#include "battle_anim.h"
#include "battle_controllers.h"
#include "battle_message.h"
#include "battle_interface.h"
#include "battle_setup.h"
#include "battle_tower.h"
#include "battle_z_move.h"
#include "bg.h"
#include "data.h"
#include "event_data.h"
#include "frontier_util.h"
#include "item_use.h"
#include "link.h"
#include "main.h"
#include "m4a.h"
#include "palette.h"
#include "party_menu.h"
#include "pokeball.h"
#include "pokemon.h"
#include "reshow_battle_screen.h"
#include "sound.h"
#include "string_util.h"
#include "task.h"
#include "text.h"
#include "trainer.h"
#include "transform.h"
#include "util.h"
#include "window.h"
#include "constants/battle_anim.h"
#include "constants/battle_partner.h"
#include "constants/songs.h"
#include "constants/party_menu.h"
#include "constants/trainers.h"
#include "test/battle.h"

static void UNUSED PlayerPartnerHandleDrawTrainerPic(enum BattlerId battler);
static void UNUSED PlayerPartnerHandleTrainerSlide(enum BattlerId battler);
static void UNUSED PlayerPartnerHandleTrainerSlideBack(enum BattlerId battler);
static void PlayerPartnerHandleChooseAction(enum BattlerId battler);
static void PlayerPartnerHandleChooseMove(enum BattlerId battler);
static void PlayerPartnerHandleChoosePokemon(enum BattlerId battler);
static void PlayerPartnerHandleIntroTrainerBallThrow(enum BattlerId battler);
static void PlayerPartnerHandleDrawPartyStatusSummary(enum BattlerId battler);
static void PlayerPartnerHandleEndLinkBattle(enum BattlerId battler);
static void PlayerPartnerHandleBattleDebug(enum BattlerId battler);
static void PlayerPartnerBufferRunCommand(enum BattlerId battler);

static void (*const sPlayerPartnerBufferCommands[CONTROLLER_CMDS_COUNT])(enum BattlerId battler) =
{
    [CONTROLLER_GETMONDATA]               = BtlController_HandleGetMonData,
    [CONTROLLER_GETRAWMONDATA]            = BtlController_Empty,
    [CONTROLLER_SETMONDATA]               = BtlController_HandleSetMonData,
    [CONTROLLER_SETRAWMONDATA]            = BtlController_HandleSetRawMonData,
    [CONTROLLER_LOADMONSPRITE]            = BtlController_HandleLoadMonSprite,
    [CONTROLLER_SWITCHINANIM]             = BtlController_HandleSwitchInAnim,
    [CONTROLLER_RETURNMONTOBALL]          = BtlController_HandleReturnMonToBall,
    [CONTROLLER_DRAWTRAINERPIC]           = BtlController_Empty,
    [CONTROLLER_TRAINERSLIDE]             = BtlController_Empty,
    [CONTROLLER_TRAINERSLIDEBACK]         = BtlController_Empty,
    [CONTROLLER_FAINTANIMATION]           = BtlController_HandleFaintAnimation,
    [CONTROLLER_PALETTEFADE]              = BtlController_Empty,
    [CONTROLLER_BALLTHROWANIM]            = BtlController_Empty,
    [CONTROLLER_PAUSE]                    = BtlController_Empty,
    [CONTROLLER_MOVEANIMATION]            = BtlController_HandleMoveAnimation,
    [CONTROLLER_PRINTSTRING]              = BtlController_HandlePrintString,
    [CONTROLLER_PRINTSTRINGPLAYERONLY]    = BtlController_Empty,
    [CONTROLLER_CHOOSEACTION]             = PlayerPartnerHandleChooseAction,
    [CONTROLLER_YESNOBOX]                 = BtlController_Empty,
    [CONTROLLER_CHOOSEMOVE]               = PlayerPartnerHandleChooseMove,
    [CONTROLLER_OPENBAG]                  = BtlController_Empty,
    [CONTROLLER_CHOOSEPOKEMON]            = PlayerPartnerHandleChoosePokemon,
    [CONTROLLER_23]                       = BtlController_Empty,
    [CONTROLLER_HEALTHBARUPDATE]          = BtlController_HandleHealthBarUpdate,
    [CONTROLLER_EXPUPDATE]                = PlayerHandleExpUpdate, // Partner's player gets experience the same way as the player.
    [CONTROLLER_STATUSICONUPDATE]         = BtlController_HandleStatusIconUpdate,
    [CONTROLLER_STATUSANIMATION]          = BtlController_HandleStatusAnimation,
    [CONTROLLER_STATUSXOR]                = BtlController_Empty,
    [CONTROLLER_DATATRANSFER]             = BtlController_Empty,
    [CONTROLLER_DMA3TRANSFER]             = BtlController_Empty,
    [CONTROLLER_PLAYBGM]                  = BtlController_Empty,
    [CONTROLLER_32]                       = BtlController_Empty,
    [CONTROLLER_TWORETURNVALUES]          = BtlController_Empty,
    [CONTROLLER_CHOSENMONRETURNVALUE]     = BtlController_Empty,
    [CONTROLLER_ONERETURNVALUE]           = BtlController_Empty,
    [CONTROLLER_ONERETURNVALUE_DUPLICATE] = BtlController_Empty,
    [CONTROLLER_HITANIMATION]             = BtlController_HandleHitAnimation,
    [CONTROLLER_CANTSWITCH]               = BtlController_Empty,
    [CONTROLLER_PLAYSE]                   = BtlController_HandlePlaySE,
    [CONTROLLER_PLAYFANFAREORBGM]         = BtlController_HandlePlayFanfareOrBGM,
    [CONTROLLER_FAINTINGCRY]              = BtlController_HandleFaintingCry,
    [CONTROLLER_INTROSLIDE]               = BtlController_HandleIntroSlide,
    [CONTROLLER_INTROTRAINERBALLTHROW]    = PlayerPartnerHandleIntroTrainerBallThrow,
    [CONTROLLER_DRAWPARTYSTATUSSUMMARY]   = PlayerPartnerHandleDrawPartyStatusSummary,
    [CONTROLLER_HIDEPARTYSTATUSSUMMARY]   = BtlController_HandleHidePartyStatusSummary,
    [CONTROLLER_ENDBOUNCE]                = BtlController_Empty,
    [CONTROLLER_SPRITEINVISIBILITY]       = BtlController_HandleSpriteInvisibility,
    [CONTROLLER_BATTLEANIMATION]          = BtlController_HandleBattleAnimation,
    [CONTROLLER_LINKSTANDBYMSG]           = BtlController_Empty,
    [CONTROLLER_RESETACTIONMOVESELECTION] = BtlController_Empty,
    [CONTROLLER_ENDLINKBATTLE]            = PlayerPartnerHandleEndLinkBattle,
    [CONTROLLER_DEBUGMENU]                = PlayerPartnerHandleBattleDebug,
    [CONTROLLER_TERMINATOR_NOP]           = BtlController_TerminatorNop
};

void SetControllerToPlayerPartner(enum BattlerId battler)
{
    gBattlerBattleController[battler] = BATTLE_CONTROLLER_PLAYER_PARTNER;
    gBattlerControllerEndFuncs[battler] = PlayerPartnerBufferExecCompleted;
    gBattlerControllerFuncs[battler] = PlayerPartnerBufferRunCommand;
}

static void PlayerPartnerBufferRunCommand(enum BattlerId battler)
{
    if (IsBattleControllerActiveOnLocal(battler))
    {
        if (gBattleResources->bufferA[battler][0] < ARRAY_COUNT(sPlayerPartnerBufferCommands))
            sPlayerPartnerBufferCommands[gBattleResources->bufferA[battler][0]](battler);
        else
            BtlController_Complete(battler);
    }
}

static void Intro_WaitForHealthbox(enum BattlerId battler)
{
    bool32 finished = FALSE;

    if (!IsDoubleBattle() || (IsDoubleBattle() && (gBattleTypeFlags & BATTLE_TYPE_MULTI)))
    {
        if (gSprites[gHealthboxSpriteIds[battler]].callback == SpriteCallbackDummy)
            finished = TRUE;
    }
    else
    {
        if (gSprites[gHealthboxSpriteIds[battler]].callback == SpriteCallbackDummy
            && gSprites[gHealthboxSpriteIds[BATTLE_PARTNER(battler)]].callback == SpriteCallbackDummy)
        {
            finished = TRUE;
        }
    }

    if (IsCryPlayingOrClearCrySongs())
        finished = FALSE;

    if (finished)
    {
        gBattleSpritesDataPtr->healthBoxesData[battler].introEndDelay = 3;
        gBattlerControllerFuncs[battler] = BtlController_Intro_DelayAndEnd;
    }
}

// Also used by the link partner.
void Controller_PlayerPartnerShowIntroHealthbox(enum BattlerId battler)
{
    if (!gBattleSpritesDataPtr->healthBoxesData[battler].ballAnimActive
        && !gBattleSpritesDataPtr->healthBoxesData[BATTLE_PARTNER(battler)].ballAnimActive
        && gSprites[gBattleControllerData[battler]].callback == SpriteCallbackDummy
        && gSprites[gBattlerSpriteIds[battler]].callback == SpriteCallbackDummy
        && ++gBattleSpritesDataPtr->healthBoxesData[battler].introEndDelay != 1)
    {
        gBattleSpritesDataPtr->healthBoxesData[battler].introEndDelay = 0;
        TryShinyAnimation(battler, GetBattlerMon(battler));

        if (IsDoubleBattle() && !(gBattleTypeFlags & BATTLE_TYPE_MULTI))
        {
            DestroySprite(&gSprites[gBattleControllerData[BATTLE_PARTNER(battler)]]);
            UpdateHealthboxAttribute(gHealthboxSpriteIds[BATTLE_PARTNER(battler)], GetBattlerMon(BATTLE_PARTNER(battler)), HEALTHBOX_ALL);
            StartHealthboxSlideIn(BATTLE_PARTNER(battler));
            SetHealthboxSpriteVisible(gHealthboxSpriteIds[BATTLE_PARTNER(battler)]);
        }

        DestroySprite(&gSprites[gBattleControllerData[battler]]);
        UpdateHealthboxAttribute(gHealthboxSpriteIds[battler], GetBattlerMon(battler), HEALTHBOX_ALL);
        StartHealthboxSlideIn(battler);
        SetHealthboxSpriteVisible(gHealthboxSpriteIds[battler]);

        gBattleSpritesDataPtr->animationData->introAnimActive = FALSE;

        gBattlerControllerFuncs[battler] = Intro_WaitForHealthbox;
    }
}

void PlayerPartnerBufferExecCompleted(enum BattlerId battler)
{
    gBattlerControllerFuncs[battler] = PlayerPartnerBufferRunCommand;
    if (gBattleTypeFlags & BATTLE_TYPE_LINK)
    {
        u8 playerId = GetMultiplayerId();

        PrepareBufferDataTransferLink(battler, B_COMM_CONTROLLER_IS_DONE, 4, &playerId);
        gBattleResources->bufferA[battler][0] = CONTROLLER_TERMINATOR_NOP;
    }
    else
    {
        MarkBattleControllerIdleOnLocal(battler);
    }
}

static enum TrainerPicID PlayerPartnerGetTrainerBackPicId(enum DifficultyLevel difficulty)
{
    enum TrainerPicID trainerPicId;

    if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER)
        trainerPicId = gBattlePartners[difficulty][gPartnerTrainerId - TRAINER_PARTNER(PARTNER_NONE)].trainerPic;
    else
        trainerPicId = GetPlayerTrainerPic(gSaveBlock2Ptr->playerGender, GAME_VERSION);

    return trainerPicId;
}

// some explanation here
// in emerald it's possible to have a tag battle in the battle frontier facilities with AI
// which use the front sprite for both the player and the partner as opposed to any other battles (including the one with Steven) that use the back pic as well as animate it
static void UNUSED PlayerPartnerHandleDrawTrainerPic(enum BattlerId battler)
{
    bool32 isFrontPic;
    s16 xPos, yPos;
    enum TrainerPicID trainerPicId;

    enum DifficultyLevel difficulty = GetBattlePartnerDifficultyLevel(gPartnerTrainerId);

    if (TESTING)
    {
        trainerPicId = TRAINER_PIC_STEVEN;
        xPos = 90;
        yPos = (8 - GetTrainerBackPicCoords(trainerPicId)->size) * 4 + 80;
    }
    else if (gPartnerTrainerId > TRAINER_PARTNER(PARTNER_NONE))
    {
        trainerPicId = PlayerPartnerGetTrainerBackPicId(difficulty);
        xPos = 90;
        yPos = (8 - GetTrainerBackPicCoords(trainerPicId)->size) * 4 + 80;
    }
    else if (IsAiVsAiBattle())
    {
        trainerPicId = GetTrainerPicFromId(gPartnerTrainerId);
        xPos = 60;
        yPos = 80;
    }
    else
    {
        trainerPicId = GetFrontierTrainerFrontSpriteId(gPartnerTrainerId);
        xPos = 32;
        yPos = 80;
    }

    // Use back pic only if the partner Steven or is custom.
    if (gPartnerTrainerId > TRAINER_PARTNER(PARTNER_NONE))
        isFrontPic = FALSE;
    else
        isFrontPic = TRUE;

    BtlController_HandleDrawTrainerPic(battler, trainerPicId, isFrontPic, xPos, yPos, -1);
}

static void UNUSED PlayerPartnerHandleTrainerSlide(enum BattlerId battler)
{
    enum DifficultyLevel difficulty = GetBattlePartnerDifficultyLevel(gPartnerTrainerId);
    enum TrainerPicID trainerPicId = PlayerPartnerGetTrainerBackPicId(difficulty);
    BtlController_HandleTrainerSlide(battler, trainerPicId);
}

static void UNUSED PlayerPartnerHandleTrainerSlideBack(enum BattlerId battler)
{
    BtlController_HandleTrainerSlideBack(battler, 35, FALSE);
}

static void SetUpWeatherChangeData(void)
{
    // Reset weatherAbilityDone to allow consecutive form changes.
    for (enum BattlerId i = 0; i < gBattlersCount; i++)
        gBattleMons[i].volatiles.weatherAbilityDone = FALSE;

    switch (gWeatherChangeMenuChosenWeather)
    {
    case NEXT_WEATHER_NONE:
    {
        u32 currWeather = GetCurrentBattleWeather();
        if (currWeather != 0xFF)
        {
            gBattleCommunication[MULTISTRING_CHOOSER] = GetCurrentWeatherEndMessage();
            gBattleWeather = B_WEATHER_NONE;
        }
        else
        {
            gWeatherChangeMenuNewWeatherSelected = FALSE;
        }
        break;
    }
    case NEXT_WEATHER_SUN:
        gBattleWeather = B_WEATHER_SUN;
        gBattleScripting.animArg1 = B_ANIM_SUN_CONTINUES;
        break;
    case NEXT_WEATHER_RAIN:
        gBattleWeather = B_WEATHER_RAIN;
        gBattleScripting.animArg1 = B_ANIM_RAIN_CONTINUES;
        break;
    case NEXT_WEATHER_SNOW:
        gBattleWeather = B_WEATHER_SNOW;
        gBattleScripting.animArg1 = B_ANIM_SNOW_CONTINUES;
        break;
    }
}

static void HandleInputChooseAction(enum BattlerId battler)
{
    if (gWeatherChangingScriptIsRunning)
        return;

    if (gWeatherChangeMenuOpened && gWeatherChangeMenuPresent)
    {
        if (JOY_NEW(A_BUTTON))
        {
            if (gWeatherChangeMenuChosenWeather == GetNextBattleWeatherId())
            {
                PlaySE(SE_PC_OFF);
                gWeatherChangeMenuOpened = FALSE;
                gWeatherChangeMenuNewWeatherSelected = FALSE;
                SlideWeatherTriggerWindow();
                return;
            }

            PlaySE(SE_SELECT);
            gWeatherChangeMenuNewWeatherSelected = TRUE;
            SetUpWeatherChangeData();

            gWeatherChangeMenuSlidingSpeed = 2;
            gWeatherChangeMenuOpened = FALSE;
            SlideWeatherTriggerWindow();

            if (gWeatherChangeMenuNewWeatherSelected)
            {
                gWeatherChangingScriptIsRunning = TRUE;
                MarkBattleControllerIdleOnLocal(battler);
                gBattleMainFunc = HandleWeatherChange;
            }
        }
        else if (JOY_NEW(B_BUTTON))
        {
            PlaySE(SE_PC_OFF);
            gWeatherChangeMenuOpened = FALSE;
            gWeatherChangeMenuNewWeatherSelected = FALSE;
            SlideWeatherTriggerWindow();
        }
        else if (JOY_NEW(L_BUTTON) || JOY_NEW(R_BUTTON))
        {
            PlaySE(SE_SELECT);
            gWeatherChangeMenuSlidingSpeed = 2;
            gWeatherChangeMenuOpened = FALSE;
            SlideWeatherTriggerWindow();
        }
        else if (JOY_NEW(DPAD_RIGHT))
        {
            if (gWeatherChangeMenuChosenWeather == NEXT_WEATHER_NONE)
                gWeatherChangeMenuChosenWeather = VarGet(VAR_CASTFORM_PHASE);
            else
                gWeatherChangeMenuChosenWeather--;
            PlaySE(SE_SELECT);
        }
        else if (JOY_NEW(DPAD_LEFT))
        {
            if (gWeatherChangeMenuChosenWeather == VarGet(VAR_CASTFORM_PHASE))
                gWeatherChangeMenuChosenWeather = VarGet(NEXT_WEATHER_NONE);
            else
                gWeatherChangeMenuChosenWeather++;
            PlaySE(SE_SELECT);
        }
    }
    else if ((JOY_NEW(L_BUTTON) || JOY_NEW(R_BUTTON)) && gWeatherChangeMenuPresent)
    {
        gWeatherChangeMenuSlidingSpeed = 2;
        gWeatherChangeMenuOpened ^= TRUE;
        PlaySE(SE_SELECT);
        SlideWeatherTriggerWindow();

        if (gWeatherChangeMenuOpened)
            gWeatherChangeMenuChosenWeather = GetNextBattleWeatherId();
    }
    else if (DEBUG_BATTLE_MENU == TRUE && JOY_NEW(SELECT_BUTTON))
    {
        BtlController_EmitTwoReturnValues(battler, B_COMM_TO_ENGINE, B_ACTION_DEBUG, 0);
        BtlController_Complete(battler);
    }
    else if (JOY_NEW(A_BUTTON))
    {
        PlaySE(SE_SELECT);
        gWeatherChangeMenuNewWeatherSelected = TRUE;
        // gBattleCommunication[battler] = STATE_BEFORE_ACTION_CHOSEN;
    }
}

static void PlayerPartnerHandleChooseActionIdle(enum BattlerId battler)
{
    if (!IsObserverBattle() || !IsOnPlayerSide(battler))
    {
        AI_TrySwitchOrUseItem(battler);
        BtlController_Complete(battler);
    }
    else if (gWeatherChangeMenuNewWeatherSelected)
    {
        gWeatherChangeMenuNewWeatherSelected = FALSE;
        TryHideWeatherTrigger();
        AI_TrySwitchOrUseItem(battler);
        BtlController_Complete(battler);
    }
    else
    {
        if (GetBattlerPosition(battler) == B_POSITION_PLAYER_LEFT)
            HandleInputChooseAction(battler);
    }
}

static void HandleChooseActionAfterDma3(enum BattlerId battler)
{
    if (!IsDma3ManagerBusyWithBgCopy())
    {
        gBattle_BG0_X = 0;
        gBattle_BG0_Y = 0; // 160 to show the action menu frame
        BattlePutTextOnWindow(gText_ChooseWeather, B_WIN_MSG); // B_WIN_ACTION_PROMPT for right side
        TryRestoreWeatherTrigger();
        gBattlerControllerFuncs[battler] = PlayerPartnerHandleChooseActionIdle;
    }
}

static void PlayerPartnerHandleChooseAction(enum BattlerId battler)
{
    if (IsObserverBattle() && IsOnPlayerSide(battler) && !gWeatherChangeMenuNewWeatherSelected && !gContinueObserverBattleAfterWeatherChange)
    {
        gBattlerControllerFuncs[battler] = HandleChooseActionAfterDma3;
    }
    else
    {
        gContinueObserverBattleAfterWeatherChange = FALSE;
        AI_TrySwitchOrUseItem(battler);
        BtlController_Complete(battler);
    }
}

static void PlayerPartnerHandleChooseMove(enum BattlerId battler)
{
    SetFinalChosenTarget(battler, TRUE);
    BtlController_Complete(battler);
}

static void PlayerPartnerHandleChoosePokemon(enum BattlerId battler)
{
    s32 chosenMonId;
    // Choosing Revival Blessing target
    if (gBattleResources->bufferA[battler][1] == PARTY_ACTION_CHOOSE_FAINTED_MON)
    {
        chosenMonId = gSelectedMonPartyId = GetFirstFaintedPartyIndex(battler);
    }
    // Switching out
    else if (gBattleStruct->monToSwitchIntoId[battler] >= PARTY_SIZE || !IsValidForBattle(&gParties[B_TRAINER_PARTNER][gBattleStruct->monToSwitchIntoId[battler]]))
    {
        chosenMonId = GetMostSuitableMonToSwitchInto(battler, SWITCH_AFTER_KO);
        if (chosenMonId == PARTY_SIZE || !IsValidForBattle(&gParties[B_TRAINER_PARTNER][chosenMonId])) // just switch to the next mon
        {
            enum BattlerId battler1 = GetBattlerAtPosition(B_POSITION_PLAYER_LEFT);
            enum BattlerId battler2 = IsDoubleBattle() ? GetBattlerAtPosition(B_POSITION_PLAYER_RIGHT) : battler1;

            for (chosenMonId = 0; chosenMonId < PARTY_SIZE; chosenMonId++)
            {
                if (GetMonData(&gParties[B_TRAINER_PARTNER][chosenMonId], MON_DATA_HP) != 0
                    && !(chosenMonId == gBattlerPartyIndexes[battler1] && BattlersShareParty(battler, battler1))
                    && !(chosenMonId == gBattlerPartyIndexes[battler2] && BattlersShareParty(battler, battler2)))
                {
                    break;
                }
            }
        }
        gBattleStruct->monToSwitchIntoId[battler] = chosenMonId;
    }
    else // Mon to switch out has been already chosen.
    {
        chosenMonId = gBattleStruct->monToSwitchIntoId[battler];
        gBattleStruct->AI_monToSwitchIntoId[battler] = PARTY_SIZE;
        gBattleStruct->monToSwitchIntoId[battler] = chosenMonId;
    }
    #if TESTING
    TestRunner_Battle_CheckSwitch(battler, chosenMonId);
    #endif
    BtlController_EmitChosenMonReturnValue(battler, B_COMM_TO_ENGINE, chosenMonId, NULL);
    BtlController_Complete(battler);
}

static void PlayerPartnerHandleIntroTrainerBallThrow(enum BattlerId battler)
{
    const u16 *trainerPal;
    enum DifficultyLevel difficulty = GetBattlePartnerDifficultyLevel(gPartnerTrainerId);

    if (gPartnerTrainerId > TRAINER_PARTNER(PARTNER_NONE))
        trainerPal = GetTrainerBackPicPalette(gBattlePartners[difficulty][gPartnerTrainerId - TRAINER_PARTNER(PARTNER_NONE)].trainerPic);
    else if (IsAiVsAiBattle())
        trainerPal = GetTrainerFrontPicPalette(GetTrainerPicFromId(gPartnerTrainerId));
    else
        trainerPal = GetTrainerFrontPicPalette(GetFrontierTrainerFrontSpriteId(gPartnerTrainerId)); // 2 vs 2 multi battle in Battle Frontier, load front sprite and pal.

    BtlController_HandleIntroTrainerBallThrow(battler, 0xD6F9, trainerPal, 24, Controller_PlayerPartnerShowIntroHealthbox);
}

static void PlayerPartnerHandleDrawPartyStatusSummary(enum BattlerId battler)
{
    BtlController_HandleDrawPartyStatusSummary(battler, B_SIDE_PLAYER, TRUE);
}

static void PlayerPartnerHandleEndLinkBattle(enum BattlerId battler)
{
    gBattleOutcome = gBattleResources->bufferA[battler][1];
    FadeOutMapMusic(5);
    BeginFastPaletteFade(3);
    BtlController_Complete(battler);
    gBattlerControllerFuncs[battler] = SetBattleEndCallbacks;
}

static void Controller_WaitForDebug(enum BattlerId battler)
{
    if (gMain.callback2 == BattleMainCB2 && !gPaletteFade.active)
        BtlController_Complete(battler);
}

static void PlayerPartnerHandleBattleDebug(enum BattlerId battler)
{
    BeginNormalPaletteFade(-1, 0, 0, 0x10, 0);
    SetMainCallback2(CB2_BattleDebugMenu);
    gBattlerControllerFuncs[battler] = Controller_WaitForDebug;
}
