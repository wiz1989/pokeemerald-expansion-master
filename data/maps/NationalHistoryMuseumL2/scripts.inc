NationalHistoryMuseumL2_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, NHML2_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, NationalHistoryMuseumL2_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

NationalHistoryMuseumL2_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_TEMP_2, 0, NHML2_EveryFrame
	.2byte 0


NHML2_OnResume::
	setvar VAR_TEMP_2, 0
	call load_HONOR_MODE
	end


NHML2_EveryFrame::
	goto_if_set FLAG_P01_HONOR_MODE, NHML2_EveryFrame_3
NHML2_EveryFrame_1:
	setvar VAR_TEMP_2, 1
	return

NHML2_EveryFrame_2:
	lock
	clearflag FLAG_P01_LOAD_SAVEGAME
	buffernumberstring STR_VAR_1, VAR_P01_CALC
	call Common_EventScript_SaveGame
	closemessage
	release
	goto NHML2_EveryFrame_1

NHML2_EveryFrame_3:
	goto_if_set FLAG_P01_LOAD_SAVEGAME, NHML2_EveryFrame_2
	goto NHML2_EveryFrame_1


NHML2_PC::
	call EventScript_PC
	return


NHML2_Nurse::
	lock
	msgbox NHML2_Nurse_Text_0, MSGBOX_AUTOCLOSE
	call Common_EventScript_OutOfCenterPartyHeal
	incrementgamestat GAME_STAT_RESTED_AT_HOME
	msgbox NHML2_Nurse_Text_1, MSGBOX_AUTOCLOSE
	release
	end


NHML2_Battle_Brandon::
	trainerbattle_single TRAINER_NHM_BRANDON, NHML2_Battle_Brandon_Text_0, NHML2_Battle_Brandon_Text_1
	lock
	msgbox NHML2_Battle_Brandon_Text_2, MSGBOX_AUTOCLOSE
	release
	end


NHM2_Battle_Archen::
	playmoncry SPECIES_ARCHEN, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_ARCHEN, 8
	dowildbattle
	end


NHM2_Battle_Kabutops::
	playmoncry SPECIES_ARCHEN, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_KABUTOPS, 100
	dowildbattle
	end


NHML2_Nurse_Text_0:
	.string "Let me heal your party.$"

NHML2_Nurse_Text_1:
	.string "You're good to go again.$"

NHML2_Battle_Brandon_Text_0:
	.string "Are you scared, yet?$"

NHML2_Battle_Brandon_Text_1:
	.string "I wasn't FEARful enough.$"

NHML2_Battle_Brandon_Text_2:
	.string "Another HINT.$"
