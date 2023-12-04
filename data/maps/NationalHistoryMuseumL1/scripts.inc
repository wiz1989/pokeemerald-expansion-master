NationalHistoryMuseumL1_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, NHML1_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, NationalHistoryMuseumL1_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

NationalHistoryMuseumL1_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_TEMP_2, 0, NHML1_EveryFrame
	.2byte 0


NHML1_OnResume::
	setvar VAR_TEMP_2, 0
	call load_HONOR_MODE
	end


NHML1_EveryFrame::
	goto_if_set FLAG_P01_HONOR_MODE, NHML1_EveryFrame_3
NHML1_EveryFrame_1:
	setvar VAR_TEMP_2, 1
	return

NHML1_EveryFrame_2:
	lock
	clearflag FLAG_P01_LOAD_SAVEGAME
	buffernumberstring STR_VAR_1, VAR_P01_CALC
	call Common_EventScript_SaveGame
	closemessage
	release
	goto NHML1_EveryFrame_1

NHML1_EveryFrame_3:
	goto_if_set FLAG_P01_LOAD_SAVEGAME, NHML1_EveryFrame_2
	goto NHML1_EveryFrame_1


NHML1_Trigger_WarpL2::
	lockall
	randomnr 3
	setorcopyvar VAR_NHM_L2_RIDDLE, VAR_RESULT
	setflag FLAG_NHML2_RIDDLE_START
	clearflag FLAG_NHML2_RIDDLE_STEP1_CHECK
	clearflag FLAG_NHML2_RIDDLE_STEP2_CHECK
	warp MAP_NATIONAL_HISTORY_MUSEUM_L2, 26, 1
	releaseall
	end

