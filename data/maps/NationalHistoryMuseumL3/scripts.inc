NationalHistoryMuseumL3_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, NHML3_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, NationalHistoryMuseumL3_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

NationalHistoryMuseumL3_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_TEMP_2, 0, NHML3_EveryFrame
	.2byte 0


NHML3_OnResume::
	setvar VAR_TEMP_2, 0
	compare VAR_LITTLEROOT_TOWN_STATE, 0
	goto_if_eq NHML3_OnResume_2
NHML3_OnResume_1:
	setrespawn HEAL_LOCATION_NATIONAL_HISTORY_MUSEUM
	setflag FLAG_BADGE01_GET
	setflag FLAG_BADGE02_GET
	setflag FLAG_BADGE03_GET
	setflag FLAG_BADGE04_GET
	setflag FLAG_BADGE05_GET
	setflag FLAG_BADGE06_GET
	setflag FLAG_BADGE07_GET
	setflag FLAG_BADGE08_GET
	setflag FLAG_SYS_POKEDEX_GET
	call load_HONOR_MODE
	end

NHML3_OnResume_2:
	givemon SPECIES_MUNCHLAX, 11
	setflag FLAG_SYS_POKEMON_GET
	setvar VAR_LITTLEROOT_TOWN_STATE, 1
	goto NHML3_OnResume_1


NHML3_EveryFrame::
	goto_if_set FLAG_P01_HONOR_MODE, NHML3_EveryFrame_3
NHML3_EveryFrame_1:
	setvar VAR_TEMP_2, 1
	return

NHML3_EveryFrame_2:
	lock
	clearflag FLAG_P01_LOAD_SAVEGAME
	buffernumberstring STR_VAR_1, VAR_P01_CALC
	call Common_EventScript_SaveGame
	closemessage
	release
	goto NHML3_EveryFrame_1

NHML3_EveryFrame_3:
	goto_if_set FLAG_P01_LOAD_SAVEGAME, NHML3_EveryFrame_2
	goto NHML3_EveryFrame_1


load_HONOR_MODE::
	goto_if_set FLAG_P01_HONOR_MODE, load_HONOR_MODE_2
	return

load_HONOR_MODE_1:
	addvar VAR_P01_PENALTY, 1
	setorcopyvar VAR_P01_CALC, VAR_P01_PENALTY
	multvar VAR_P01_CALC, 15
	setorcopyvar VAR_0x8004, VAR_P01_CALC
	special PlayTimeAddMin
	return

load_HONOR_MODE_2:
	goto_if_set FLAG_P01_LOAD_SAVEGAME, load_HONOR_MODE_1
	return


NHML3_Move_Tutor::
	lock
	faceplayer
	msgbox NHML3_Move_Tutor_Text_0
	waitmessage
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 0
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_1
	setvar VAR_0x8006, 0
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, NHML3_Move_Tutor_3
	case 1, NHML3_Move_Tutor_4
	case 2, NHML3_Move_Tutor_5
	case 3, NHML3_Move_Tutor_6
	case MULTI_B_PRESSED, NHML3_Move_Tutor_7
NHML3_Move_Tutor_1:
	waitmessage
	release
	end

NHML3_Move_Tutor_3:
	call NHML3_Tutor_RolePlay
	goto NHML3_Move_Tutor_1

NHML3_Move_Tutor_4:
	call NHML3_Tutor_Endeavor
	goto NHML3_Move_Tutor_1

NHML3_Move_Tutor_5:
	call NHML3_Tutor_Substitute
	goto NHML3_Move_Tutor_1

NHML3_Move_Tutor_6:
	call NHML3_Exit
	goto NHML3_Move_Tutor_1

NHML3_Move_Tutor_7:
	call NHML3_Exit
	goto NHML3_Move_Tutor_1


NHML3_Tutor_RolePlay::
	setvar VAR_0x8008, 1
	setvar VAR_0x8005, MOVE_ROLE_PLAY
	call NHML3_Tutor_ConfirmMoveSelection
	end


NHML3_Tutor_Endeavor::
	setvar VAR_0x8008, 1
	setvar VAR_0x8005, MOVE_ENDEAVOR
	call NHML3_Tutor_ConfirmMoveSelection
	end


NHML3_Tutor_Substitute::
	setvar VAR_0x8008, 1
	setvar VAR_0x8005, MOVE_SUBSTITUTE
	call NHML3_Tutor_ConfirmMoveSelection
	end


NHML3_Exit::
	special CloseBattleFrontierTutorWindow
	msgbox NHML3_Exit_Text_0, MSGBOX_AUTOCLOSE
	release
	end


NHML3_Tutor_ConfirmMoveSelection::
	special BufferBattleFrontierTutorMoveName
	buffernumberstring STR_VAR_2, VAR_0x8008
	msgbox NHML3_Tutor_ConfirmMoveSelection_Text_0
	msgbox NHML3_Tutor_ConfirmMoveSelection_Text_1, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq NHML3_Tutor_ConfirmMoveSelection_2
	checkitem ITEM_HEART_SCALE
	compare VAR_RESULT, NO
	goto_if_eq NHML3_Tutor_ConfirmMoveSelection_5
	msgbox BattleFrontier_Lounge7_Text_TeachMoveToWhichMon, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special CloseBattleFrontierTutorWindow
	special ChooseMonForMoveTutor
	waitstate
	compare VAR_RESULT, FALSE
	goto_if_eq NHML3_Tutor_ConfirmMoveSelection_8
	msgbox NHML3_Tutor_ConfirmMoveSelection_Text_4, MSGBOX_AUTOCLOSE
	removeitem ITEM_HEART_SCALE
NHML3_Tutor_ConfirmMoveSelection_4:
	waitmessage
	release
	end

NHML3_Tutor_ConfirmMoveSelection_2:
	msgbox NHML3_Tutor_ConfirmMoveSelection_Text_2, MSGBOX_AUTOCLOSE
	waitmessage
	special CloseBattleFrontierTutorWindow
	release
	end

NHML3_Tutor_ConfirmMoveSelection_5:
	msgbox NHML3_Tutor_ConfirmMoveSelection_Text_3, MSGBOX_AUTOCLOSE
	waitmessage
	special CloseBattleFrontierTutorWindow
	release
	end

NHML3_Tutor_ConfirmMoveSelection_8:
	call NHML3_Exit
	goto NHML3_Tutor_ConfirmMoveSelection_4


NHML3_Trader::
	call FortreeCity_House1_EventScript_Trader
	end


NHML3_Move_Tutor_Text_0:
	.string "I am the Move Tutor. \lI will teach your Pokemon moves for\nprecious Heart Scales. \pWhich move should I teach?$"

NHML3_Exit_Text_0:
	.string "Well, if you don't want to...$"

NHML3_Tutor_ConfirmMoveSelection_Text_0:
	.string "The move {STR_VAR_1}, is it?$"

NHML3_Tutor_ConfirmMoveSelection_Text_1:
	.string "That will be {STR_VAR_2} Heart Scale, okay?$"

NHML3_Tutor_ConfirmMoveSelection_Text_2:
	.string "Alright. Come back anytime you want.$"

NHML3_Tutor_ConfirmMoveSelection_Text_3:
	.string "Oh, you don't have any Heart Scales!\l"
	.string "Don't waste my time then!$"

NHML3_Tutor_ConfirmMoveSelection_Text_4:
	.string "Thanks for doing business with me.$"
