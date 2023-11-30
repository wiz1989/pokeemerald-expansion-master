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

