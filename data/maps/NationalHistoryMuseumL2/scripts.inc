NationalHistoryMuseumL2_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, NHML2_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, NHML2_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, NationalHistoryMuseumL2_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

NationalHistoryMuseumL2_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_NHML1_BOULDER_FELL_DOWN, 1, NHML2_EveryFrame_Boulder
	map_script_2 VAR_NHML2_FIGHT_KABUTOPS, 1, NHML2_EveryFrame_Sash
	.2byte 0


NHML2_OnTransition::
	goto_if_unset FLAG_NHML2_SHOW_BOULDER, NHML2_OnTransition_1
	return

NHML2_OnTransition_1:
	setflag FLAG_NHML2_BOULDER
	return


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


NHML2_EveryFrame_Boulder::
	call NHML2_Boulder_in_hole
	end


NHML2_EveryFrame_Sash::
	setorcopyvar VAR_NHML2_FIGHT_KABUTOPS, 0
	clearflag FLAG_HOLD_NO_SASH
	checkpartyitem ITEM_FOCUS_SASH
	compare VAR_RESULT, 6
	goto_if_lt NHML2_EveryFrame_Sash_2
NHML2_EveryFrame_Sash_1:
	checkitem ITEM_FOCUS_SASH
	compare VAR_RESULT, TRUE
	goto_if_eq NHML2_EveryFrame_Sash_5
NHML2_EveryFrame_Sash_4:
	checkpcitem ITEM_FOCUS_SASH
	compare VAR_RESULT, TRUE
	goto_if_eq NHML2_EveryFrame_Sash_8
NHML2_EveryFrame_Sash_7:
	end

NHML2_EveryFrame_Sash_2:
	setflag FLAG_HOLD_NO_SASH
	setflag FLAG_GOT_SASH
	goto NHML2_EveryFrame_Sash_1

NHML2_EveryFrame_Sash_5:
	setflag FLAG_HOLD_NO_SASH
	setflag FLAG_GOT_SASH
	goto NHML2_EveryFrame_Sash_4

NHML2_EveryFrame_Sash_8:
	setflag FLAG_HOLD_NO_SASH
	setflag FLAG_GOT_SASH
	goto NHML2_EveryFrame_Sash_7


NHML2_Trigger_WarpL3::
	lockall
	warp MAP_NATIONAL_HISTORY_MUSEUM_L3, 3, 3
	releaseall
	end


NHML2_Trigger_WarpL1::
	lockall
	warp MAP_NATIONAL_HISTORY_MUSEUM_L1, 27, 3
	setflag FLAG_MOVE_BACK
	releaseall
	end


NHML2_PC::
	call EventScript_PC
	return


NHML2_Nurse::
	lock
	faceplayer
	msgbox NHML2_Nurse_Text_0, MSGBOX_AUTOCLOSE
	call Common_EventScript_OutOfCenterPartyHeal
	incrementgamestat GAME_STAT_RESTED_AT_HOME
	msgbox NHML2_Nurse_Text_1, MSGBOX_AUTOCLOSE
	release
	end


NHML2_BlondeMan::
	lock
	faceplayer
	checktrainerflag TRAINER_NHM_BRANDON
	goto_if 1, NHML2_BlondeMan_2
	msgbox NHML2_BlondeMan_Text_1, MSGBOX_AUTOCLOSE
	waitmessage
	goto_if_set FLAG_CAUGHT_ARCHEN, NHML2_BlondeMan_5
	msgbox NHML2_BlondeMan_Text_4, MSGBOX_AUTOCLOSE
NHML2_BlondeMan_1:
	waitmessage
	release
	end

NHML2_BlondeMan_2:
	msgbox NHML2_BlondeMan_Text_0, MSGBOX_AUTOCLOSE
	goto NHML2_BlondeMan_1

NHML2_BlondeMan_5:
	checkpartymon SPECIES_YAMASK
	compare VAR_RESULT, TRUE
	goto_if_eq NHML2_BlondeMan_8
	msgbox NHML2_BlondeMan_Text_3, MSGBOX_AUTOCLOSE
	goto NHML2_BlondeMan_1

NHML2_BlondeMan_8:
	checkpartymove MOVE_ENDEAVOR
	compare VAR_RESULT, PARTY_SIZE
	goto_if_lt NHML2_BlondeMan_11
	msgbox NHML2_BlondeMan_Text_3, MSGBOX_AUTOCLOSE
	goto NHML2_BlondeMan_1

NHML2_BlondeMan_11:
	msgbox NHML2_BlondeMan_Text_2, MSGBOX_AUTOCLOSE
	goto NHML2_BlondeMan_1


NHML2_Battle_Brandon::
	trainerbattle_single TRAINER_NHM_BRANDON, NHML2_Battle_Brandon_Text_0, NHML2_Battle_Brandon_Text_1
	lock
	msgbox NHML2_Battle_Brandon_Text_2, MSGBOX_AUTOCLOSE
	release
	goto_if_unset FLAG_MOVE_BACK, NHML2_Battle_Brandon_2
NHML2_Battle_Brandon_1:
	end

NHML2_Battle_Brandon_2:
	applymovement 1, Move_back
	waitmovement 0
	setobjectxy 1, 27, 11
	setflag FLAG_MOVE_BACK
	goto NHML2_Battle_Brandon_1


NHM2_Battle_Archen::
	msgbox NHM2_Battle_Archen_Text_0, MSGBOX_AUTOCLOSE
	waitmessage
	checktrainerflag TRAINER_NHM_BRANDON
	goto_if 0, NHM2_Battle_Archen_2
	playmoncry SPECIES_ARCHEOPS, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_ARCHEOPS, 100
NHM2_Battle_Archen_1:
	dowildbattle
	end

NHM2_Battle_Archen_2:
	playmoncry SPECIES_ARCHEN, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_ARCHEN, 12
	goto NHM2_Battle_Archen_1


NHM2_Battle_Kabutops::
	lock
	compare VAR_NHM_L2_RIDDLE, 0
	goto_if_eq NHM2_Battle_Kabutops_5
NHM2_Battle_Kabutops_3:
	randomnr 3
	setorcopyvar VAR_NHM_L2_RIDDLE, VAR_RESULT
	setflag FLAG_NHML2_RIDDLE_START
	clearflag FLAG_NHML2_RIDDLE_STEP1_CHECK
	clearflag FLAG_NHML2_RIDDLE_STEP2_CHECK
	msgbox NHM2_Battle_Kabutops_Text_2, MSGBOX_AUTOCLOSE
	waitmessage
	playmoncry SPECIES_KABUTOPS, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	goto_if_set FLAG_HOLD_NO_SASH, NHM2_Battle_Kabutops_14
	checktrainerflag TRAINER_NHM_BRANDON
	goto_if 1, NHM2_Battle_Kabutops_14
	setorcopyvar VAR_NHML2_FIGHT_KABUTOPS, 1
	setwildbattle SPECIES_KABUTOPS, 100, ITEM_FOCUS_SASH
NHM2_Battle_Kabutops_13:
	dowildbattle
NHM2_Battle_Kabutops_1:
	release
	end

NHM2_Battle_Kabutops_2:
	goto_if_set FLAG_NHML1_WALLPAPER_GUY, NHM2_Battle_Kabutops_10
	msgbox NHM2_Battle_Kabutops_Text_1, MSGBOX_AUTOCLOSE
	randomnr 3
	setorcopyvar VAR_NHM_L2_RIDDLE, VAR_RESULT
	setflag FLAG_NHML2_RIDDLE_START
	clearflag FLAG_NHML2_RIDDLE_STEP1_CHECK
	clearflag FLAG_NHML2_RIDDLE_STEP2_CHECK
NHM2_Battle_Kabutops_9:
	waitmessage
	goto NHM2_Battle_Kabutops_1

NHM2_Battle_Kabutops_4:
	goto_if_unset FLAG_NHML2_RIDDLE_SOLVED, NHM2_Battle_Kabutops_2
	goto NHM2_Battle_Kabutops_3

NHM2_Battle_Kabutops_5:
	goto_if_set FLAG_NHML2_RIDDLE_STEP1_CHECK, NHM2_Battle_Kabutops_4
	goto NHM2_Battle_Kabutops_3

NHM2_Battle_Kabutops_10:
	clearflag FLAG_NHML2_RIDDLE_START
	clearflag FLAG_NHML2_RIDDLE_STEP1_CHECK
	setflag FLAG_NHML2_RIDDLE_STEP2_CHECK
	msgbox NHM2_Battle_Kabutops_Text_0, MSGBOX_AUTOCLOSE
	goto NHM2_Battle_Kabutops_9

NHM2_Battle_Kabutops_14:
	setorcopyvar VAR_NHML2_FIGHT_KABUTOPS, 1
	setwildbattle SPECIES_KABUTOPS, 100
	goto NHM2_Battle_Kabutops_13


NHM2_Battle_Omastar::
	lock
	compare VAR_NHM_L2_RIDDLE, 2
	goto_if_eq NHM2_Battle_Omastar_5
NHM2_Battle_Omastar_3:
	randomnr 3
	setorcopyvar VAR_NHM_L2_RIDDLE, VAR_RESULT
	setflag FLAG_NHML2_RIDDLE_START
	clearflag FLAG_NHML2_RIDDLE_STEP1_CHECK
	clearflag FLAG_NHML2_RIDDLE_STEP2_CHECK
	msgbox NHM2_Battle_Omastar_Text_2, MSGBOX_AUTOCLOSE
	waitmessage
	playmoncry SPECIES_OMASTAR, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_OMASTAR, 100
	dowildbattle
NHM2_Battle_Omastar_1:
	release
	end

NHM2_Battle_Omastar_2:
	setflag FLAG_NHML2_RIDDLE_SOLVED
	setflag FLAG_NHML2_SHOW_BOULDER
	msgbox NHM2_Battle_Omastar_Text_0, MSGBOX_AUTOCLOSE
	waitmessage
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 4
	setvar VAR_0x8007, 5
	special ShakeCamera
	waitstate
	fadescreen FADE_TO_BLACK
	addobject 3, MAP_NATIONAL_HISTORY_MUSEUM_L2
	fadescreen FADE_FROM_BLACK
	clearflag FLAG_NHML2_BOULDER
	applymovement OBJ_EVENT_ID_PLAYER, Move_exclmark
	waitmovement 0
	msgbox NHM2_Battle_Omastar_Text_1
	waitmessage
	goto NHM2_Battle_Omastar_1

NHM2_Battle_Omastar_4:
	goto_if_unset FLAG_NHML2_RIDDLE_SOLVED, NHM2_Battle_Omastar_2
	goto NHM2_Battle_Omastar_3

NHM2_Battle_Omastar_5:
	goto_if_set FLAG_NHML2_RIDDLE_STEP2_CHECK, NHM2_Battle_Omastar_4
	goto NHM2_Battle_Omastar_3


NHM2_Battle_Aerodactyl::
	lock
	compare VAR_NHM_L2_RIDDLE, 1
	goto_if_eq NHM2_Battle_Aerodactyl_5
NHM2_Battle_Aerodactyl_3:
	randomnr 3
	setorcopyvar VAR_NHM_L2_RIDDLE, VAR_RESULT
	setflag FLAG_NHML2_RIDDLE_START
	clearflag FLAG_NHML2_RIDDLE_STEP1_CHECK
	clearflag FLAG_NHML2_RIDDLE_STEP2_CHECK
	msgbox NHM2_Battle_Aerodactyl_Text_2, MSGBOX_AUTOCLOSE
	waitmessage
	playmoncry SPECIES_AERODACTYL, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_AERODACTYL, 100
	dowildbattle
NHM2_Battle_Aerodactyl_1:
	release
	end

NHM2_Battle_Aerodactyl_2:
	goto_if_set FLAG_NHML1_WALLPAPER_GUY, NHM2_Battle_Aerodactyl_10
	msgbox NHM2_Battle_Aerodactyl_Text_1, MSGBOX_AUTOCLOSE
	randomnr 3
	setorcopyvar VAR_NHM_L2_RIDDLE, VAR_RESULT
	setflag FLAG_NHML2_RIDDLE_START
	clearflag FLAG_NHML2_RIDDLE_STEP1_CHECK
	clearflag FLAG_NHML2_RIDDLE_STEP2_CHECK
NHM2_Battle_Aerodactyl_9:
	waitmessage
	goto NHM2_Battle_Aerodactyl_1

NHM2_Battle_Aerodactyl_4:
	goto_if_unset FLAG_NHML2_RIDDLE_SOLVED, NHM2_Battle_Aerodactyl_2
	goto NHM2_Battle_Aerodactyl_3

NHM2_Battle_Aerodactyl_5:
	goto_if_set FLAG_NHML2_RIDDLE_STEP1_CHECK, NHM2_Battle_Aerodactyl_4
	goto NHM2_Battle_Aerodactyl_3

NHM2_Battle_Aerodactyl_10:
	clearflag FLAG_NHML2_RIDDLE_START
	clearflag FLAG_NHML2_RIDDLE_STEP1_CHECK
	setflag FLAG_NHML2_RIDDLE_STEP2_CHECK
	msgbox NHM2_Battle_Aerodactyl_Text_0, MSGBOX_AUTOCLOSE
	goto NHM2_Battle_Aerodactyl_9


NHM2_Battle_Cradily::
	lock
	compare VAR_NHM_L2_RIDDLE, 0
	goto_if_eq NHM2_Battle_Cradily_5
NHM2_Battle_Cradily_3:
	randomnr 3
	setorcopyvar VAR_NHM_L2_RIDDLE, VAR_RESULT
	setflag FLAG_NHML2_RIDDLE_START
	clearflag FLAG_NHML2_RIDDLE_STEP1_CHECK
	clearflag FLAG_NHML2_RIDDLE_STEP2_CHECK
	msgbox NHM2_Battle_Cradily_Text_1, MSGBOX_AUTOCLOSE
	waitmessage
	playmoncry SPECIES_CRADILY, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_CRADILY, 100
	dowildbattle
NHM2_Battle_Cradily_1:
	release
	end

NHM2_Battle_Cradily_2:
	setflag FLAG_NHML2_RIDDLE_SOLVED
	setflag FLAG_NHML2_SHOW_BOULDER
	msgbox NHM2_Battle_Cradily_Text_0, MSGBOX_AUTOCLOSE
	waitmessage
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 4
	setvar VAR_0x8007, 5
	special ShakeCamera
	waitstate
	fadescreen FADE_TO_BLACK
	addobject 3, MAP_NATIONAL_HISTORY_MUSEUM_L2
	fadescreen FADE_FROM_BLACK
	clearflag FLAG_NHML2_BOULDER
	applymovement OBJ_EVENT_ID_PLAYER, Move_exclmark
	waitmovement 0
	msgbox NHM2_Battle_Omastar_Text_1
	waitmessage
	goto NHM2_Battle_Cradily_1

NHM2_Battle_Cradily_4:
	goto_if_unset FLAG_NHML2_RIDDLE_SOLVED, NHM2_Battle_Cradily_2
	goto NHM2_Battle_Cradily_3

NHM2_Battle_Cradily_5:
	goto_if_set FLAG_NHML2_RIDDLE_STEP2_CHECK, NHM2_Battle_Cradily_4
	goto NHM2_Battle_Cradily_3


NHM2_Battle_Armaldo::
	lock
	compare VAR_NHM_L2_RIDDLE, 1
	goto_if_eq NHM2_Battle_Armaldo_5
NHM2_Battle_Armaldo_3:
	randomnr 3
	setorcopyvar VAR_NHM_L2_RIDDLE, VAR_RESULT
	setflag FLAG_NHML2_RIDDLE_START
	clearflag FLAG_NHML2_RIDDLE_STEP1_CHECK
	clearflag FLAG_NHML2_RIDDLE_STEP2_CHECK
	msgbox NHM2_Battle_Armaldo_Text_1, MSGBOX_AUTOCLOSE
	waitmessage
	playmoncry SPECIES_ARMALDO, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_ARMALDO, 100
	dowildbattle
NHM2_Battle_Armaldo_1:
	release
	end

NHM2_Battle_Armaldo_2:
	setflag FLAG_NHML2_RIDDLE_SOLVED
	setflag FLAG_NHML2_SHOW_BOULDER
	msgbox NHM2_Battle_Armaldo_Text_0, MSGBOX_AUTOCLOSE
	waitmessage
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 4
	setvar VAR_0x8007, 5
	special ShakeCamera
	waitstate
	fadescreen FADE_TO_BLACK
	addobject 3, MAP_NATIONAL_HISTORY_MUSEUM_L2
	fadescreen FADE_FROM_BLACK
	clearflag FLAG_NHML2_BOULDER
	applymovement OBJ_EVENT_ID_PLAYER, Move_exclmark
	waitmovement 0
	msgbox NHM2_Battle_Omastar_Text_1
	waitmessage
	goto NHM2_Battle_Armaldo_1

NHM2_Battle_Armaldo_4:
	goto_if_unset FLAG_NHML2_RIDDLE_SOLVED, NHM2_Battle_Armaldo_2
	goto NHM2_Battle_Armaldo_3

NHM2_Battle_Armaldo_5:
	goto_if_set FLAG_NHML2_RIDDLE_STEP2_CHECK, NHM2_Battle_Armaldo_4
	goto NHM2_Battle_Armaldo_3


NHM2_Battle_Rampardos::
	lock
	compare VAR_NHM_L2_RIDDLE, 0
	goto_if_eq NHM2_Battle_Rampardos_5
NHM2_Battle_Rampardos_3:
	setflag FLAG_NHML2_RIDDLE_START
	clearflag FLAG_NHML2_RIDDLE_STEP1_CHECK
	clearflag FLAG_NHML2_RIDDLE_STEP2_CHECK
	randomnr 3
	setorcopyvar VAR_NHM_L2_RIDDLE, VAR_RESULT
	msgbox NHM2_Battle_Rampardos_Text_1, MSGBOX_AUTOCLOSE
	waitmessage
	playmoncry SPECIES_RAMPARDOS, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_RAMPARDOS, 100
	dowildbattle
NHM2_Battle_Rampardos_1:
	release
	end

NHM2_Battle_Rampardos_2:
	clearflag FLAG_NHML2_RIDDLE_START
	setflag FLAG_NHML2_RIDDLE_STEP1_CHECK
	msgbox NHM2_Battle_Rampardos_Text_0, MSGBOX_AUTOCLOSE
	waitmessage
	goto NHM2_Battle_Rampardos_1

NHM2_Battle_Rampardos_4:
	goto_if_unset FLAG_NHML2_RIDDLE_SOLVED, NHM2_Battle_Rampardos_2
	goto NHM2_Battle_Rampardos_3

NHM2_Battle_Rampardos_5:
	goto_if_set FLAG_NHML2_RIDDLE_START, NHM2_Battle_Rampardos_4
	goto NHM2_Battle_Rampardos_3


NHM2_Battle_Bastiodon::
	lock
	compare VAR_NHM_L2_RIDDLE, 1
	goto_if_eq NHM2_Battle_Bastiodon_5
NHM2_Battle_Bastiodon_3:
	setflag FLAG_NHML2_RIDDLE_START
	clearflag FLAG_NHML2_RIDDLE_STEP1_CHECK
	clearflag FLAG_NHML2_RIDDLE_STEP2_CHECK
	randomnr 3
	setorcopyvar VAR_NHM_L2_RIDDLE, VAR_RESULT
	msgbox NHM2_Battle_Bastiodon_Text_1, MSGBOX_AUTOCLOSE
	waitmessage
	playmoncry SPECIES_BASTIODON, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_BASTIODON, 100
	dowildbattle
NHM2_Battle_Bastiodon_1:
	release
	end

NHM2_Battle_Bastiodon_2:
	clearflag FLAG_NHML2_RIDDLE_START
	setflag FLAG_NHML2_RIDDLE_STEP1_CHECK
	msgbox NHM2_Battle_Bastiodon_Text_0, MSGBOX_AUTOCLOSE
	waitmessage
	goto NHM2_Battle_Bastiodon_1

NHM2_Battle_Bastiodon_4:
	goto_if_unset FLAG_NHML2_RIDDLE_SOLVED, NHM2_Battle_Bastiodon_2
	goto NHM2_Battle_Bastiodon_3

NHM2_Battle_Bastiodon_5:
	goto_if_set FLAG_NHML2_RIDDLE_START, NHM2_Battle_Bastiodon_4
	goto NHM2_Battle_Bastiodon_3


NHM2_Battle_Carracosta::
	lock
	compare VAR_NHM_L2_RIDDLE, 2
	goto_if_eq NHM2_Battle_Carracosta_5
NHM2_Battle_Carracosta_3:
	randomnr 3
	setorcopyvar VAR_NHM_L2_RIDDLE, VAR_RESULT
	setflag FLAG_NHML2_RIDDLE_START
	clearflag FLAG_NHML2_RIDDLE_STEP1_CHECK
	clearflag FLAG_NHML2_RIDDLE_STEP2_CHECK
	msgbox NHM2_Battle_Carracosta_Text_2, MSGBOX_AUTOCLOSE
	waitmessage
	playmoncry SPECIES_CARRACOSTA, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_CARRACOSTA, 100
	dowildbattle
NHM2_Battle_Carracosta_1:
	release
	end

NHM2_Battle_Carracosta_2:
	goto_if_set FLAG_NHML1_WALLPAPER_GUY, NHM2_Battle_Carracosta_10
	msgbox NHM2_Battle_Carracosta_Text_1, MSGBOX_AUTOCLOSE
	randomnr 3
	setorcopyvar VAR_NHM_L2_RIDDLE, VAR_RESULT
	setflag FLAG_NHML2_RIDDLE_START
	clearflag FLAG_NHML2_RIDDLE_STEP1_CHECK
	clearflag FLAG_NHML2_RIDDLE_STEP2_CHECK
NHM2_Battle_Carracosta_9:
	waitmessage
	goto NHM2_Battle_Carracosta_1

NHM2_Battle_Carracosta_4:
	goto_if_unset FLAG_NHML2_RIDDLE_SOLVED, NHM2_Battle_Carracosta_2
	goto NHM2_Battle_Carracosta_3

NHM2_Battle_Carracosta_5:
	goto_if_set FLAG_NHML2_RIDDLE_STEP1_CHECK, NHM2_Battle_Carracosta_4
	goto NHM2_Battle_Carracosta_3

NHM2_Battle_Carracosta_10:
	clearflag FLAG_NHML2_RIDDLE_START
	clearflag FLAG_NHML2_RIDDLE_STEP1_CHECK
	setflag FLAG_NHML2_RIDDLE_STEP2_CHECK
	msgbox NHM2_Battle_Carracosta_Text_0, MSGBOX_AUTOCLOSE
	goto NHM2_Battle_Carracosta_9


NHM2_Battle_Aurorus::
	lock
	compare VAR_NHM_L2_RIDDLE, 2
	goto_if_eq NHM2_Battle_Aurorus_5
NHM2_Battle_Aurorus_3:
	setflag FLAG_NHML2_RIDDLE_START
	clearflag FLAG_NHML2_RIDDLE_STEP1_CHECK
	clearflag FLAG_NHML2_RIDDLE_STEP2_CHECK
	randomnr 3
	setorcopyvar VAR_NHM_L2_RIDDLE, VAR_RESULT
	msgbox NHM2_Battle_Aurorus_Text_1, MSGBOX_AUTOCLOSE
	waitmessage
	playmoncry SPECIES_AURORUS, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_AURORUS, 100
	dowildbattle
NHM2_Battle_Aurorus_1:
	release
	end

NHM2_Battle_Aurorus_2:
	clearflag FLAG_NHML2_RIDDLE_START
	setflag FLAG_NHML2_RIDDLE_STEP1_CHECK
	msgbox NHM2_Battle_Aurorus_Text_0, MSGBOX_AUTOCLOSE
	waitmessage
	goto NHM2_Battle_Aurorus_1

NHM2_Battle_Aurorus_4:
	goto_if_unset FLAG_NHML2_RIDDLE_SOLVED, NHM2_Battle_Aurorus_2
	goto NHM2_Battle_Aurorus_3

NHM2_Battle_Aurorus_5:
	goto_if_set FLAG_NHML2_RIDDLE_START, NHM2_Battle_Aurorus_4
	goto NHM2_Battle_Aurorus_3


NHML2_Camper::
	lock
	faceplayer
	goto_if_set FLAG_NHML2_RIDDLE_SOLVED, NHML2_Camper_2
	switch VAR_NHM_L2_RIDDLE
	case 0, NHML2_Camper_6
	case 1, NHML2_Camper_7
	case 2, NHML2_Camper_8
NHML2_Camper_1:
	waitmessage
	release
	end

NHML2_Camper_2:
	msgbox NHML2_Camper_Text_0, MSGBOX_AUTOCLOSE
	goto NHML2_Camper_1

NHML2_Camper_6:
	msgbox NHML2_Camper_Text_1, MSGBOX_AUTOCLOSE
	goto NHML2_Camper_1

NHML2_Camper_7:
	msgbox NHML2_Camper_Text_2, MSGBOX_AUTOCLOSE
	goto NHML2_Camper_1

NHML2_Camper_8:
	msgbox NHML2_Camper_Text_3, MSGBOX_AUTOCLOSE
	goto NHML2_Camper_1


NHML2_Game_Master::
	lock
	clearflag FLAG_P01_ADDTIME
	clearflag FLAG_P01_GIVE_ADVICE
	faceplayer
	msgbox NHML2_Game_Master_Text_0
	waitmessage
	msgbox NHML2_Game_Master_Text_1, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq NHML2_Game_Master_2
	msgbox NHML2_Game_Master_Text_20, MSGBOX_AUTOCLOSE
	waitmessage
	release
	end

NHML2_Game_Master_1:
	waitmessage
	goto_if_set FLAG_P01_ADDTIME, NHML2_Game_Master_6
	goto_if_set FLAG_P01_GIVE_ADVICE, NHML2_Game_Master_12
	msgbox NHML2_Game_Master_Text_22
	waitmessage
NHML2_Game_Master_5:
	release
	end

NHML2_Game_Master_2:
	setflag FLAG_P01_GIVE_ADVICE
	specialvar VAR_RESULT, IsPcEmpty
	compare VAR_RESULT, FALSE
	goto_if_eq NHML2_Game_Master_9
	checkitem ITEM_POKE_BALL
	goto_if_unset FLAG_CAUGHT_ARCHEN, NHML2_Game_Master_17
NHML2_Game_Master_15:
	checktrainerflag TRAINER_NHM_BRANDON
	goto_if 0, NHML2_Game_Master_22
NHML2_Game_Master_20:
	checktrainerflag TRAINER_NHM_BRANDON
	goto_if 0, NHML2_Game_Master_35
NHML2_Game_Master_32:
	checktrainerflag TRAINER_NHM_BRANDON
	goto_if 1, NHML2_Game_Master_44
NHML2_Game_Master_42:
	checktrainerflag TRAINER_NHM_DOUBLE
	goto_if 1, NHML2_Game_Master_57
	goto NHML2_Game_Master_1

NHML2_Game_Master_6:
	setorcopyvar VAR_0x8004, 20
	special PlayTimeAddMin
	goto NHML2_Game_Master_5

NHML2_Game_Master_9:
	msgbox NHML2_Game_Master_Text_2
	clearflag FLAG_P01_GIVE_ADVICE
	goto NHML2_Game_Master_1

NHML2_Game_Master_12:
	msgbox NHML2_Game_Master_Text_21
	waitmessage
	goto NHML2_Game_Master_5

NHML2_Game_Master_16:
	goto_if_unset FLAG_HINT17, NHML2_Game_Master_30
NHML2_Game_Master_29:
	msgbox NHML2_Game_Master_Text_3, MSGBOX_AUTOCLOSE
	clearflag FLAG_P01_GIVE_ADVICE
	goto NHML2_Game_Master_15

NHML2_Game_Master_17:
	compare VAR_RESULT, TRUE
	goto_if_eq NHML2_Game_Master_16
	goto NHML2_Game_Master_15

NHML2_Game_Master_21:
	checkpartymove MOVE_COVET
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq NHML2_Game_Master_39
	goto_if_unset FLAG_GOT_SASH, NHML2_Game_Master_53
	goto_if_unset FLAG_GOT_HEART_SCALE, NHML2_Game_Master_78
	goto NHML2_Game_Master_20

NHML2_Game_Master_22:
	goto_if_unset FLAG_GOT_SASH, NHML2_Game_Master_24
	goto_if_unset FLAG_GOT_HEART_SCALE, NHML2_Game_Master_24
	goto NHML2_Game_Master_20

NHML2_Game_Master_24:
	goto_if_set FLAG_CAUGHT_ARCHEN, NHML2_Game_Master_21
	goto NHML2_Game_Master_20

NHML2_Game_Master_30:
	setflag FLAG_HINT17
	setflag FLAG_P01_ADDTIME
	goto NHML2_Game_Master_29

NHML2_Game_Master_33:
	goto_if_unset FLAG_CAUGHT_ARCHEN, NHML2_Game_Master_47
	checkpartymon SPECIES_YAMASK
	compare VAR_RESULT, FALSE
	goto_if_eq NHML2_Game_Master_66
	checkpartymove MOVE_ENDEAVOR
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq NHML2_Game_Master_94
	goto_if_unset FLAG_HINT06, NHML2_Game_Master_130
NHML2_Game_Master_129:
	msgbox NHML2_Game_Master_Text_13, MSGBOX_AUTOCLOSE
	clearflag FLAG_P01_GIVE_ADVICE
	goto NHML2_Game_Master_32

NHML2_Game_Master_34:
	goto_if_set FLAG_GOT_HEART_SCALE, NHML2_Game_Master_33
	goto NHML2_Game_Master_32

NHML2_Game_Master_35:
	goto_if_set FLAG_GOT_SASH, NHML2_Game_Master_34
	goto NHML2_Game_Master_32

NHML2_Game_Master_39:
	getpartymonlevel SPECIES_MUNCHLAX
	compare VAR_RESULT, 12
	goto_if_ge NHML2_Game_Master_50
	goto_if_unset FLAG_HINT01, NHML2_Game_Master_73
NHML2_Game_Master_72:
	msgbox NHML2_Game_Master_Text_6, MSGBOX_AUTOCLOSE
	clearflag FLAG_P01_GIVE_ADVICE
	goto NHML2_Game_Master_20

NHML2_Game_Master_43:
	goto_if_unset FLAG_NHML2_RIDDLE_SOLVED, NHML2_Game_Master_60
	checkpartymon SPECIES_CLEFAIRY
	copyvar VAR_RESULT2, VAR_RESULT
	checkpartymon SPECIES_SKITTY
	compare VAR_RESULT, TRUE
	goto_if_eq NHML2_Game_Master_88
	goto NHML2_Game_Master_42

NHML2_Game_Master_44:
	checktrainerflag TRAINER_NHM_DOUBLE
	goto_if 0, NHML2_Game_Master_43
	goto NHML2_Game_Master_42

NHML2_Game_Master_47:
	goto_if_unset FLAG_HINT15, NHML2_Game_Master_64
NHML2_Game_Master_63:
	msgbox NHML2_Game_Master_Text_10, MSGBOX_AUTOCLOSE
	clearflag FLAG_P01_GIVE_ADVICE
	goto NHML2_Game_Master_32

NHML2_Game_Master_50:
	goto_if_unset FLAG_HINT13, NHML2_Game_Master_70
NHML2_Game_Master_69:
	msgbox NHML2_Game_Master_Text_4, MSGBOX_AUTOCLOSE
	waitmessage
	getpartymonslot SPECIES_MUNCHLAX
	switch VAR_RESULT
	case 0, NHML2_Game_Master_99
	case 1, NHML2_Game_Master_100
	case 2, NHML2_Game_Master_101
	case 3, NHML2_Game_Master_102
NHML2_Game_Master_97:
	msgbox NHML2_Game_Master_Text_5, MSGBOX_AUTOCLOSE
	clearflag FLAG_P01_GIVE_ADVICE
	goto NHML2_Game_Master_20

NHML2_Game_Master_53:
	checkpartymove MOVE_RECYCLE
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq NHML2_Game_Master_75
	goto_if_unset FLAG_HINT02, NHML2_Game_Master_107
NHML2_Game_Master_106:
	msgbox NHML2_Game_Master_Text_8, MSGBOX_AUTOCLOSE
	clearflag FLAG_P01_GIVE_ADVICE
	goto NHML2_Game_Master_20

NHML2_Game_Master_56:
	goto_if_unset FLAG_NHML2_RIDDLE_SOLVED, NHML2_Game_Master_80
	goto_if_unset FLAG_NHML1_BOULDER_FELL_DOWN, NHML2_Game_Master_81
	setorcopyvar VAR_NHML1_COUNT, 0
	checkpartymove MOVE_BELLY_DRUM
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq NHML2_Game_Master_118
NHML2_Game_Master_117:
	checkpartymove MOVE_COVET
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq NHML2_Game_Master_142
NHML2_Game_Master_141:
	checkpartymove MOVE_FLING
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq NHML2_Game_Master_151
NHML2_Game_Master_150:
	compare VAR_NHML1_COUNT, 0
	goto_if_gt NHML2_Game_Master_159
	goto_if_unset FLAG_HINT11, NHML2_Game_Master_166
NHML2_Game_Master_165:
	msgbox NHML2_Game_Master_Text_19, MSGBOX_AUTOCLOSE
	clearflag FLAG_P01_GIVE_ADVICE
	goto NHML2_Game_Master_1

NHML2_Game_Master_57:
	checktrainerflag TRAINER_NHM_HAIL
	goto_if 0, NHML2_Game_Master_56
	goto NHML2_Game_Master_1

NHML2_Game_Master_60:
	goto_if_set FLAG_NHML1_WALLPAPER_GUY, NHML2_Game_Master_85
	goto NHML2_Game_Master_42

NHML2_Game_Master_64:
	setflag FLAG_HINT15
	setflag FLAG_P01_ADDTIME
	goto NHML2_Game_Master_63

NHML2_Game_Master_66:
	goto_if_unset FLAG_HINT04, NHML2_Game_Master_92
NHML2_Game_Master_91:
	msgbox NHML2_Game_Master_Text_11, MSGBOX_AUTOCLOSE
	clearflag FLAG_P01_GIVE_ADVICE
	goto NHML2_Game_Master_32

NHML2_Game_Master_70:
	setflag FLAG_HINT13
	setflag FLAG_P01_ADDTIME
	goto NHML2_Game_Master_69

NHML2_Game_Master_73:
	setflag FLAG_HINT01
	setflag FLAG_P01_ADDTIME
	goto NHML2_Game_Master_72

NHML2_Game_Master_75:
	goto_if_unset FLAG_HINT12, NHML2_Game_Master_104
NHML2_Game_Master_103:
	msgbox NHML2_Game_Master_Text_7, MSGBOX_AUTOCLOSE
	waitmessage
	getpartymonslot SPECIES_MUNCHLAX
	switch VAR_RESULT
	case 0, NHML2_Game_Master_134
	case 1, NHML2_Game_Master_135
	case 2, NHML2_Game_Master_136
	case 3, NHML2_Game_Master_137
NHML2_Game_Master_132:
	msgbox NHML2_Game_Master_Text_5, MSGBOX_AUTOCLOSE
	clearflag FLAG_P01_GIVE_ADVICE
	goto NHML2_Game_Master_20

NHML2_Game_Master_78:
	goto_if_unset FLAG_HINT03, NHML2_Game_Master_110
NHML2_Game_Master_109:
	msgbox NHML2_Game_Master_Text_9, MSGBOX_AUTOCLOSE
	clearflag FLAG_P01_GIVE_ADVICE
	goto NHML2_Game_Master_20

NHML2_Game_Master_80:
	goto_if_set FLAG_NHML1_WALLPAPER_GUY, NHML2_Game_Master_112
	goto NHML2_Game_Master_1

NHML2_Game_Master_81:
	goto_if_unset FLAG_HINT10, NHML2_Game_Master_115
NHML2_Game_Master_114:
	msgbox NHML2_Game_Master_Text_17, MSGBOX_AUTOCLOSE
	clearflag FLAG_P01_GIVE_ADVICE
	goto NHML2_Game_Master_1

NHML2_Game_Master_85:
	goto_if_unset FLAG_HINT07, NHML2_Game_Master_121
NHML2_Game_Master_120:
	msgbox NHML2_Game_Master_Text_14, MSGBOX_AUTOCLOSE
	clearflag FLAG_P01_GIVE_ADVICE
	goto NHML2_Game_Master_42

NHML2_Game_Master_87:
	checkpartymove MOVE_ROLE_PLAY
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq NHML2_Game_Master_123
	checkpartymonmove SPECIES_YAMASK, MOVE_SUBSTITUTE
	compare VAR_RESULT, FALSE
	goto_if_eq NHML2_Game_Master_147
	goto_if_unset FLAG_HINT09, NHML2_Game_Master_157
NHML2_Game_Master_156:
	msgbox NHML2_Game_Master_Text_16, MSGBOX_AUTOCLOSE
	clearflag FLAG_P01_GIVE_ADVICE
	goto NHML2_Game_Master_42

NHML2_Game_Master_88:
	compare VAR_RESULT2, TRUE
	goto_if_eq NHML2_Game_Master_87
	goto NHML2_Game_Master_42

NHML2_Game_Master_92:
	setflag FLAG_HINT04
	setflag FLAG_P01_ADDTIME
	goto NHML2_Game_Master_91

NHML2_Game_Master_94:
	goto_if_unset FLAG_HINT05, NHML2_Game_Master_127
NHML2_Game_Master_126:
	msgbox NHML2_Game_Master_Text_12, MSGBOX_AUTOCLOSE
	clearflag FLAG_P01_GIVE_ADVICE
	goto NHML2_Game_Master_32

NHML2_Game_Master_99:
	setmonmove 0, 0, MOVE_ICY_WIND
	setmonmove 0, 1, MOVE_TACKLE
	setmonmove 0, 2, MOVE_COVET
	setmonmove 0, 3, MOVE_RECYCLE
	goto NHML2_Game_Master_97

NHML2_Game_Master_100:
	setmonmove 1, 0, MOVE_ICY_WIND
	setmonmove 1, 1, MOVE_TACKLE
	setmonmove 1, 2, MOVE_COVET
	setmonmove 1, 3, MOVE_RECYCLE
	goto NHML2_Game_Master_97

NHML2_Game_Master_101:
	setmonmove 2, 0, MOVE_ICY_WIND
	setmonmove 2, 1, MOVE_TACKLE
	setmonmove 2, 2, MOVE_COVET
	setmonmove 2, 3, MOVE_RECYCLE
	goto NHML2_Game_Master_97

NHML2_Game_Master_102:
	setmonmove 3, 0, MOVE_ICY_WIND
	setmonmove 3, 1, MOVE_TACKLE
	setmonmove 3, 2, MOVE_COVET
	setmonmove 3, 3, MOVE_RECYCLE
	goto NHML2_Game_Master_97

NHML2_Game_Master_104:
	setflag FLAG_HINT12
	setflag FLAG_P01_ADDTIME
	goto NHML2_Game_Master_103

NHML2_Game_Master_107:
	setflag FLAG_HINT02
	setflag FLAG_P01_ADDTIME
	goto NHML2_Game_Master_106

NHML2_Game_Master_110:
	setflag FLAG_HINT03
	setflag FLAG_P01_ADDTIME
	goto NHML2_Game_Master_109

NHML2_Game_Master_112:
	goto_if_unset FLAG_HINT07, NHML2_Game_Master_139
NHML2_Game_Master_138:
	msgbox NHML2_Game_Master_Text_14, MSGBOX_AUTOCLOSE
	clearflag FLAG_P01_GIVE_ADVICE
	goto NHML2_Game_Master_1

NHML2_Game_Master_115:
	setflag FLAG_HINT10
	setflag FLAG_P01_ADDTIME
	goto NHML2_Game_Master_114

NHML2_Game_Master_118:
	addvar VAR_NHML1_COUNT, 1
	goto NHML2_Game_Master_117

NHML2_Game_Master_121:
	setflag FLAG_HINT07
	setflag FLAG_P01_ADDTIME
	goto NHML2_Game_Master_120

NHML2_Game_Master_123:
	goto_if_unset FLAG_HINT08, NHML2_Game_Master_145
NHML2_Game_Master_144:
	msgbox NHML2_Game_Master_Text_15, MSGBOX_AUTOCLOSE
	clearflag FLAG_P01_GIVE_ADVICE
	goto NHML2_Game_Master_42

NHML2_Game_Master_127:
	setflag FLAG_HINT05
	setflag FLAG_P01_ADDTIME
	goto NHML2_Game_Master_126

NHML2_Game_Master_130:
	setflag FLAG_HINT06
	setflag FLAG_P01_ADDTIME
	goto NHML2_Game_Master_129

NHML2_Game_Master_134:
	setmonmove 0, 0, MOVE_ICY_WIND
	setmonmove 0, 1, MOVE_TACKLE
	setmonmove 0, 2, MOVE_COVET
	setmonmove 0, 3, MOVE_RECYCLE
	goto NHML2_Game_Master_132

NHML2_Game_Master_135:
	setmonmove 1, 0, MOVE_ICY_WIND
	setmonmove 1, 1, MOVE_TACKLE
	setmonmove 1, 2, MOVE_COVET
	setmonmove 1, 3, MOVE_RECYCLE
	goto NHML2_Game_Master_132

NHML2_Game_Master_136:
	setmonmove 2, 0, MOVE_ICY_WIND
	setmonmove 2, 1, MOVE_TACKLE
	setmonmove 2, 2, MOVE_COVET
	setmonmove 2, 3, MOVE_RECYCLE
	goto NHML2_Game_Master_132

NHML2_Game_Master_137:
	setmonmove 3, 0, MOVE_ICY_WIND
	setmonmove 3, 1, MOVE_TACKLE
	setmonmove 3, 2, MOVE_COVET
	setmonmove 3, 3, MOVE_RECYCLE
	goto NHML2_Game_Master_132

NHML2_Game_Master_139:
	setflag FLAG_HINT07
	setflag FLAG_P01_ADDTIME
	goto NHML2_Game_Master_138

NHML2_Game_Master_142:
	addvar VAR_NHML1_COUNT, 1
	goto NHML2_Game_Master_141

NHML2_Game_Master_145:
	setflag FLAG_HINT08
	setflag FLAG_P01_ADDTIME
	goto NHML2_Game_Master_144

NHML2_Game_Master_147:
	goto_if_unset FLAG_HINT08, NHML2_Game_Master_154
NHML2_Game_Master_153:
	msgbox NHML2_Game_Master_Text_15, MSGBOX_AUTOCLOSE
	clearflag FLAG_P01_GIVE_ADVICE
	goto NHML2_Game_Master_42

NHML2_Game_Master_151:
	addvar VAR_NHML1_COUNT, 1
	goto NHML2_Game_Master_150

NHML2_Game_Master_154:
	setflag FLAG_HINT08
	setflag FLAG_P01_ADDTIME
	goto NHML2_Game_Master_153

NHML2_Game_Master_157:
	setflag FLAG_HINT09
	setflag FLAG_P01_ADDTIME
	goto NHML2_Game_Master_156

NHML2_Game_Master_159:
	goto_if_unset FLAG_HINT16, NHML2_Game_Master_163
NHML2_Game_Master_162:
	msgbox NHML2_Game_Master_Text_18, MSGBOX_AUTOCLOSE
	waitmessage
	getpartymonslot SPECIES_MUNCHLAX
	switch VAR_RESULT
	case 0, NHML2_Game_Master_170
	case 1, NHML2_Game_Master_171
	case 2, NHML2_Game_Master_172
	case 3, NHML2_Game_Master_173
NHML2_Game_Master_168:
	msgbox NHML2_Game_Master_Text_5, MSGBOX_AUTOCLOSE
	clearflag FLAG_P01_GIVE_ADVICE
	goto NHML2_Game_Master_1

NHML2_Game_Master_163:
	setflag FLAG_HINT16
	setflag FLAG_P01_ADDTIME
	goto NHML2_Game_Master_162

NHML2_Game_Master_166:
	setflag FLAG_HINT11
	setflag FLAG_P01_ADDTIME
	goto NHML2_Game_Master_165

NHML2_Game_Master_170:
	setmonmove 0, 0, MOVE_ICY_WIND
	setmonmove 0, 1, MOVE_BELLY_DRUM
	setmonmove 0, 2, MOVE_COVET
	setmonmove 0, 3, MOVE_FLING
	goto NHML2_Game_Master_168

NHML2_Game_Master_171:
	setmonmove 1, 0, MOVE_ICY_WIND
	setmonmove 1, 1, MOVE_BELLY_DRUM
	setmonmove 1, 2, MOVE_COVET
	setmonmove 1, 3, MOVE_FLING
	goto NHML2_Game_Master_168

NHML2_Game_Master_172:
	setmonmove 2, 0, MOVE_ICY_WIND
	setmonmove 2, 1, MOVE_BELLY_DRUM
	setmonmove 2, 2, MOVE_COVET
	setmonmove 2, 3, MOVE_FLING
	goto NHML2_Game_Master_168

NHML2_Game_Master_173:
	setmonmove 3, 0, MOVE_ICY_WIND
	setmonmove 3, 1, MOVE_BELLY_DRUM
	setmonmove 3, 2, MOVE_COVET
	setmonmove 3, 3, MOVE_FLING
	goto NHML2_Game_Master_168


NHML2_Boulder::
	call EventScript_StrengthBoulder
	end


NHML2_Sign_wiz1989::
	lock
	msgbox NHML2_Sign_wiz1989_Text_0, MSGBOX_AUTOCLOSE
	waitmessage
	release
	end


NHML2_Sign_tileset::
	lock
	msgbox NHML2_Sign_tileset_Text_0, MSGBOX_AUTOCLOSE
	waitmessage
	release
	end


NHML2_Sign_hole::
	lock
	msgbox NHML2_Sign_hole_Text_0, MSGBOX_AUTOCLOSE
	waitmessage
	release
	end


NHML2_Boulder_in_hole::
	lock
	removeobject 3, MAP_NATIONAL_HISTORY_MUSEUM_L2
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 4
	setvar VAR_0x8007, 5
	special ShakeCamera
	waitstate
	applymovement OBJ_EVENT_ID_PLAYER, Move_exclmark
	waitmovement 0
	msgbox NHML2_Boulder_in_hole_Text_0, MSGBOX_AUTOCLOSE
	waitmessage
	setorcopyvar VAR_NHML1_BOULDER_FELL_DOWN, 0
	release
	end


NHM2_Sign_Archen::
	lock
	msgbox NHM2_Sign_Archen_Text_0, MSGBOX_AUTOCLOSE
	waitmessage
	release
	end


NHM2_Sign_Kabutops::
	lock
	msgbox NHM2_Sign_Kabutops_Text_0, MSGBOX_AUTOCLOSE
	waitmessage
	release
	end


NHM2_Sign_Omastar::
	lock
	msgbox NHM2_Sign_Omastar_Text_0, MSGBOX_AUTOCLOSE
	waitmessage
	release
	end


NHM2_Sign_Aerodactyl::
	lock
	msgbox NHM2_Sign_Aerodactyl_Text_0, MSGBOX_AUTOCLOSE
	waitmessage
	release
	end


NHM2_Sign_Cradily::
	lock
	msgbox NHM2_Sign_Cradily_Text_0, MSGBOX_AUTOCLOSE
	waitmessage
	release
	end


NHM2_Sign_Armaldo::
	lock
	msgbox NHM2_Sign_Armaldo_Text_0, MSGBOX_AUTOCLOSE
	waitmessage
	release
	end


NHM2_Sign_Rampardos::
	lock
	msgbox NHM2_Sign_Rampardos_Text_0, MSGBOX_AUTOCLOSE
	waitmessage
	release
	end


NHM2_Sign_Bastiodon::
	lock
	msgbox NHM2_Sign_Bastiodon_Text_0, MSGBOX_AUTOCLOSE
	waitmessage
	release
	end


NHM2_Sign_Carracosta::
	lock
	msgbox NHM2_Sign_Carracosta_Text_0, MSGBOX_AUTOCLOSE
	waitmessage
	release
	end


NHM2_Sign_Aurorus::
	lock
	msgbox NHM2_Sign_Aurorus_Text_0, MSGBOX_AUTOCLOSE
	waitmessage
	release
	end


NHML2_Sign_Skeleton_Tyrantrum::
	lock
	msgbox NHML2_Sign_Skeleton_Tyrantrum_Text_0, MSGBOX_AUTOCLOSE
	waitmessage
	release
	end


NHML2_Sign_Skeleton_Armaldo::
	lock
	msgbox NHML2_Sign_Skeleton_Armaldo_Text_0, MSGBOX_AUTOCLOSE
	waitmessage
	release
	end


NHML2_Sign_Skeleton_Kabuto::
	lock
	msgbox NHML2_Sign_Skeleton_Kabuto_Text_0, MSGBOX_AUTOCLOSE
	waitmessage
	release
	end


NHML2_Sign_Skeleton_Omanyte::
	lock
	msgbox NHML2_Sign_Skeleton_Omanyte_Text_0, MSGBOX_AUTOCLOSE
	waitmessage
	release
	end


NHML2_Item_HeartScale::
	lock
	finditem ITEM_HEART_SCALE, 2
	release
	end


NHML2_Sign_Bastiodon_skull::
	lock
	goto_if_unset FLAG_NHML2_BASTIODON_SKULL, NHML2_Sign_Bastiodon_skull_4
NHML2_Sign_Bastiodon_skull_3:
	msgbox NHML2_Sign_Bastiodon_skull_Text_5, MSGBOX_AUTOCLOSE
	waitmessage
NHML2_Sign_Bastiodon_skull_1:
	release
	end

NHML2_Sign_Bastiodon_skull_2:
	msgbox NHML2_Sign_Bastiodon_skull_Text_0, MSGBOX_AUTOCLOSE
	waitmessage
	msgbox NHML2_Sign_Bastiodon_skull_Text_1, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq NHML2_Sign_Bastiodon_skull_7
	msgbox NHML2_Sign_Bastiodon_skull_Text_4, MSGBOX_AUTOCLOSE
	waitmessage
	goto NHML2_Sign_Bastiodon_skull_1

NHML2_Sign_Bastiodon_skull_4:
	goto_if_unset FLAG_CAUGHT_ARCHEN, NHML2_Sign_Bastiodon_skull_2
	goto NHML2_Sign_Bastiodon_skull_3

NHML2_Sign_Bastiodon_skull_7:
	setflag FLAG_NHML2_BASTIODON_SKULL
	msgbox NHML2_Sign_Bastiodon_skull_Text_2, MSGBOX_AUTOCLOSE
	waitmessage
	setvar VAR_0x8006, ITEM_PRETTY_FEATHER
	showitemdesc
	msgbox NHML2_Sign_Bastiodon_skull_Text_3
	waitmessage
	hideitemdesc
	goto NHML2_Sign_Bastiodon_skull_1


Move_exclmark:
	emote_exclamation_mark
	step_end

Move_back:
	face_right
	walk_right
	face_left
	step_end

NHML2_Nurse_Text_0:
	.string "Let me heal your party.$"

NHML2_Nurse_Text_1:
	.string "You're good to go again.$"

NHML2_BlondeMan_Text_0:
	.string "YOU DID IT!\p"
	.string "I went down to leave but came back as\n"
	.string "it was too cold for my taste.\l"
	.string "Looks like their A/C has a malfunction\l"
	.string "or so.$"

NHML2_BlondeMan_Text_1:
	.string "This guy over there won't let anybody\n"
	.string "out here until someone defeats him.\l"
	.string "What a jerk!$"

NHML2_BlondeMan_Text_2:
	.string "Wow...\n"
	.string "...you really look like you could have a\l"
	.string "good chance of winning.$"

NHML2_BlondeMan_Text_3:
	.string "Welp...looks like you're also not ready,\n"
	.string "yet.$"

NHML2_BlondeMan_Text_4:
	.string "You should consider getting more\n"
	.string "Pokémon before challenging him.$"

NHML2_Battle_Brandon_Text_0:
	.string "Don't think about fighting the couple\n"
	.string "on the third floor, if you can't even get\l"
	.string "past me!$"

NHML2_Battle_Brandon_Text_1:
	.string "I wasn't FEARful enough.$"

NHML2_Battle_Brandon_Text_2:
	.string "The couple on floor 3 won't be as easy\n"
	.string "on you as I was.\p"
	.string "If there only was a way to stop them\n"
	.string "from hitting you that hard!$"

NHM2_Battle_Archen_Text_0:
	.string "The PLUME FOSSIL is glowing brightly.\p"
	.string "Feel its power!$"

NHM2_Battle_Kabutops_Text_0:
	.string "There is a DOME FOSSIL exhibited...\l"
	.string "...A hidden switch clicked.$"

NHM2_Battle_Kabutops_Text_1:
	.string "There is a DOME FOSSIL exhibited...\l"
	.string "...A hidden switch shows.\p"
	.string "But it's stuck.\l"
	.string "You should try that again later.$"

NHM2_Battle_Kabutops_Text_2:
	.string "The DOME FOSSIL is glowing brightly.\p"
	.string "Feel its power!$"

NHM2_Battle_Omastar_Text_0:
	.string "There is a HELIX FOSSIL exhibited...\l"
	.string "...A hidden switch clicked.$"

NHM2_Battle_Omastar_Text_1:
	.string "Something heavy fell from above!$"

NHM2_Battle_Omastar_Text_2:
	.string "The HELIX FOSSIL is glowing brightly.\p"
	.string "Feel its power!$"

NHM2_Battle_Aerodactyl_Text_0:
	.string "There is an OLD AMBER exhibited...\l"
	.string "...A hidden switch clicked.$"

NHM2_Battle_Aerodactyl_Text_1:
	.string "There is an OLD AMBER exhibited...\l"
	.string "...A hidden switch shows.\p"
	.string "But it's stuck.\l"
	.string "You should try that again later.$"

NHM2_Battle_Aerodactyl_Text_2:
	.string "The OLD AMBER is glowing brightly.\p"
	.string "Feel its power!$"

NHM2_Battle_Cradily_Text_0:
	.string "There is a ROOT FOSSIL exhibited...\l"
	.string "...A hidden switch clicked.$"

NHM2_Battle_Cradily_Text_1:
	.string "The ROOT FOSSIL is glowing brightly.\p"
	.string "Feel its power!$"

NHM2_Battle_Armaldo_Text_0:
	.string "There is a CLAW FOSSIL exhibited...\l"
	.string "...A hidden switch clicked.$"

NHM2_Battle_Armaldo_Text_1:
	.string "The CLAW FOSSIL is glowing brightly.\p"
	.string "Feel its power!$"

NHM2_Battle_Rampardos_Text_0:
	.string "There is a SKULL FOSSIL exhibited...\l"
	.string "...A hidden switch clicked.$"

NHM2_Battle_Rampardos_Text_1:
	.string "The SKULL FOSSIL is glowing brightly.\p"
	.string "Feel its power!$"

NHM2_Battle_Bastiodon_Text_0:
	.string "There is a ARMOR FOSSIL exhibited...\l"
	.string "...A hidden switch clicked.$"

NHM2_Battle_Bastiodon_Text_1:
	.string "The ARMOR FOSSIL is glowing brightly.\p"
	.string "Feel its power!$"

NHM2_Battle_Carracosta_Text_0:
	.string "There is a COVER FOSSIL exhibited...\l"
	.string "...A hidden switch clicked.$"

NHM2_Battle_Carracosta_Text_1:
	.string "There is a COVER FOSSIL exhibited...\l"
	.string "...A hidden switch shows.\p"
	.string "But it's stuck.\l"
	.string "You should try that again later.$"

NHM2_Battle_Carracosta_Text_2:
	.string "The COVER FOSSIL is glowing brightly.\p"
	.string "Feel its power!$"

NHM2_Battle_Aurorus_Text_0:
	.string "There is a SAIL FOSSIL exhibited...\l"
	.string "...A hidden switch clicked.$"

NHM2_Battle_Aurorus_Text_1:
	.string "The SAIL FOSSIL is glowing brightly.\p"
	.string "Feel its power!$"

NHML2_Camper_Text_0:
	.string "Now that I think of it...\p"
	.string "I guess I like all kinds of Pokémon.$"

NHML2_Camper_Text_1:
	.string "Hey, there! What's your favorite TYPE?\p"
	.string "Mine is GRASS.$"

NHML2_Camper_Text_2:
	.string "Hey, there! What's your favorite TYPE?\p"
	.string "Mine is FIRE.$"

NHML2_Camper_Text_3:
	.string "Hey, there! What's your favorite TYPE?\p"
	.string "Mine is WATER.$"

NHML2_Game_Master_Text_0:
	.string "I am the Game Master.\p"
	.string "I will give you helpful advice for each\n"
	.string "situation, but it adds an additional\l"
	.string "20min to your play clock.$"

NHML2_Game_Master_Text_1:
	.string "Do you want me to give you a hint?$"

NHML2_Game_Master_Text_2:
	.string "You still have Pokémon in your PC. I can\n"
	.string "only give you tips when it's empty.\p"
	.string "Of course, you won't be charged 20\n"
	.string "minutes this time.$"

NHML2_Game_Master_Text_3:
	.string "Looks like you haven't used your\n"
	.string "Pokéball, yet.\p"
	.string "There is one specific encounter here\n"
	.string "that is weak enough to catch it.\l"
	.string "...\l"
	.string "...did you have a closer look at that\l"
	.string "Bastiodon skull over there?$"

NHML2_Game_Master_Text_4:
	.string "Oh no, your Munchlax didn't learn the\n"
	.string "move COVET when leveling up?\p"
	.string "Let me update its moveset so you can\n"
	.string "continue your journey...$"

NHML2_Game_Master_Text_5:
	.string "Munchlax' moveset has been updated.$"

NHML2_Game_Master_Text_6:
	.string "Have you seen the mail in your PC?\p"
	.string "You should check out Munchlax'\n"
	.string "learnset to see if it can help you\l"
	.string "solving that hint!$"

NHML2_Game_Master_Text_7:
	.string "Oh no, your Munchlax forgot the move\n"
	.string "RECYCLE?\p"
	.string "Let me update its moveset so you can\n"
	.string "continue your journey...$"

NHML2_Game_Master_Text_8:
	.string "People are making so much trash.\p"
	.string "We should all try to RECYCLE more!\l"
	.string "Even when trying to obtain a FOCUS\l"
	.string "SASH.$"

NHML2_Game_Master_Text_9:
	.string "I heard HEART SCALES can be found\n"
	.string "after some battles.\p"
	.string "Your Munchlax is key to obtain them.$"

NHML2_Game_Master_Text_10:
	.string "Looks like you haven't used your\n"
	.string "Pokéball, yet.\p"
	.string "There is one specific encounter here\n"
	.string "that is weak enough to catch it.\l"
	.string "You should look out for it and make it a\l"
	.string "member of your team.$"

NHML2_Game_Master_Text_11:
	.string "You are struggling to defeat that\n"
	.string "trainer on the right?\p"
	.string "Let me tell you that you won't defeat\n"
	.string "him with Munchlax in your party!$"

NHML2_Game_Master_Text_12:
	.string "There's only one way to defeat the\n"
	.string "trainer on the right and it leads you to\l"
	.string "the Move Tutor upstairs.$"

NHML2_Game_Master_Text_13:
	.string "You are struggling to defeat that\n"
	.string "Tyrantrum?\p"
	.string "You should take a closer look at\n"
	.string "Yamask's ability.$"

NHML2_Game_Master_Text_14:
	.string "You spoke to the gentleman talking\n"
	.string "about the wallpapers here, haven't you?\p"
	.string "You should think about how and where\n"
	.string "you can take a specific look at\l"
	.string "WALLPAPERS.$"

NHML2_Game_Master_Text_15:
	.string "You should go visit the Move Tutor\n"
	.string "again.\p"
	.string "Without his excellent service you won't\n"
	.string "be able to proceed.$"

NHML2_Game_Master_Text_16:
	.string "To continue you will have to defeat the\n"
	.string "couple upstairs.\l"
	.string "They will gift you STRENGTH in return.\p"
	.string "Managing different abilities among all\n"
	.string "Pokémon will be the key to success.$"

NHML2_Game_Master_Text_17:
	.string "Oh you still can't find the right\n"
	.string "passage through the ice maze in the\l"
	.string "first floor?\p"
	.string "You will have to push the boulder\n"
	.string "through the hole to open the right\l"
	.string "path.$"

NHML2_Game_Master_Text_18:
	.string "Oh no, your Munchlax forgot an\n"
	.string "important move.\p"
	.string "Let me update its moveset so you can\n"
	.string "continue your journey...$"

NHML2_Game_Master_Text_19:
	.string "Have you noticed the papers on the\n"
	.string "counter?\p"
	.string "And have you considered that by always\n"
	.string "moving last Skitty could copycat your\l"
	.string "own team mates?\p"
	.string "...so many questions...$"

NHML2_Game_Master_Text_20:
	.string "Come back whenever you need me.$"

NHML2_Game_Master_Text_21:
	.string "I am sorry, but I currently have no\n"
	.string "hints to give to you.\p"
	.string "Try proceeding by looking for items,\n"
	.string "catching Pokémon, talking to NPCs and\l"
	.string "winning battles.\p"
	.string "Of course, you won't be charged 20\n"
	.string "minutes this time.$"

NHML2_Game_Master_Text_22:
	.string "\p"
	.string "...\p"
	.string "I had already given this hint to you\n"
	.string "before.\p"
	.string "I guess it's fair if I don't charge you\n"
	.string "any more time for it.$"

NHML2_Sign_wiz1989_Text_0:
	.string "This ROM hack was designed and created\n"
	.string "by WIZ1989.$"

NHML2_Sign_tileset_Text_0:
	.string "This Fossil Museum tileset was\n"
	.string "originally designed and created by\l"
	.string "princess-phoenix and adapted to fit\l"
	.string "gba style.$"

NHML2_Sign_hole_Text_0:
	.string "A hole in the ground. \lMaybe you can push something through \nit.$"

NHML2_Boulder_in_hole_Text_0:
	.string "The boulder fell through the hole!$"

NHM2_Sign_Archen_Text_0:
	.string "This showcase contains an ancient\n"
	.string "PLUME FOSSIL.$"

NHM2_Sign_Kabutops_Text_0:
	.string "This showcase contains an ancient DOME\n"
	.string "FOSSIL.$"

NHM2_Sign_Omastar_Text_0:
	.string "This showcase contains an ancient\n"
	.string "HELIX FOSSIL.$"

NHM2_Sign_Aerodactyl_Text_0:
	.string "This showcase contains an ancient OLD\n"
	.string "AMBER.$"

NHM2_Sign_Cradily_Text_0:
	.string "This showcase contains an ancient ROOT\n"
	.string "FOSSIL.$"

NHM2_Sign_Armaldo_Text_0:
	.string "This showcase contains an ancient CLAW\n"
	.string "FOSSIL.$"

NHM2_Sign_Rampardos_Text_0:
	.string "This showcase contains an ancient\n"
	.string "SKULL FOSSIL.$"

NHM2_Sign_Bastiodon_Text_0:
	.string "This showcase contains an ancient\n"
	.string "ARMOR FOSSIL.$"

NHM2_Sign_Carracosta_Text_0:
	.string "This showcase contains an ancient\n"
	.string "COVER FOSSIL.$"

NHM2_Sign_Aurorus_Text_0:
	.string "This showcase contains an ancient SAIL\n"
	.string "FOSSIL.$"

NHML2_Sign_Skeleton_Tyrantrum_Text_0:
	.string "An impressive Tyrantrum skeleton.$"

NHML2_Sign_Skeleton_Armaldo_Text_0:
	.string "A skeleton of an Armaldo.$"

NHML2_Sign_Skeleton_Kabuto_Text_0:
	.string "It's a big rock with Kabuto fossils\n"
	.string "attached to it.$"

NHML2_Sign_Skeleton_Omanyte_Text_0:
	.string "It's a big rock with Omanyte fossils\n"
	.string "attached to it.$"

NHML2_Sign_Bastiodon_skull_Text_0:
	.string "There's a tiny note sticking in the\n"
	.string "Bastiodon skull.\p"
	.string "But you are NOT ALLOWED TO TOUCH THE\n"
	.string "EXHIBITS!$"

NHML2_Sign_Bastiodon_skull_Text_1:
	.string "Do you still want to take it out and\n"
	.string "read it?$"

NHML2_Sign_Bastiodon_skull_Text_2:
	.string "What an outlaw you are!$"

NHML2_Sign_Bastiodon_skull_Text_3:
	.string "The note shows a little picture of a\n"
	.string "feather.$"

NHML2_Sign_Bastiodon_skull_Text_4:
	.string "You left the note where it was.$"

NHML2_Sign_Bastiodon_skull_Text_5:
	.string "It's a Bastiodon skull.\l"
	.string "What did you expect?$"

Text_NotEnoughMons::
	.string "You don't have enough Pokémon to fight\n"
	.string "us.$"
