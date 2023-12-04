NationalHistoryMuseumL2_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, NHML2_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, NHML2_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, NationalHistoryMuseumL2_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

NationalHistoryMuseumL2_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_TEMP_2, 0, NHML2_EveryFrame
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


NHML2_Trigger_WarpL3::
	lockall
	warp MAP_NATIONAL_HISTORY_MUSEUM_L3, 3, 1
	releaseall
	end


NHML2_Trigger_WarpL1::
	lockall
	warp MAP_NATIONAL_HISTORY_MUSEUM_L1, 26, 1
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


NHML2_Battle_Brandon::
	trainerbattle_single TRAINER_NHM_BRANDON, NHML2_Battle_Brandon_Text_0, NHML2_Battle_Brandon_Text_1
	lock
	msgbox NHML2_Battle_Brandon_Text_2, MSGBOX_AUTOCLOSE
	release
	end


NHM2_Battle_Archen::
	msgbox NHM2_Battle_Archen_Text_0, MSGBOX_AUTOCLOSE
	waitmessage
	playmoncry SPECIES_ARCHEN, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_ARCHEN, 12
	dowildbattle
	end


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
	msgbox NHM2_Battle_Kabutops_Text_1, MSGBOX_AUTOCLOSE
	waitmessage
	playmoncry SPECIES_KABUTOPS, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_KABUTOPS, 100
	dowildbattle
NHM2_Battle_Kabutops_1:
	release
	end

NHM2_Battle_Kabutops_2:
	clearflag FLAG_NHML2_RIDDLE_START
	clearflag FLAG_NHML2_RIDDLE_STEP1_CHECK
	setflag FLAG_NHML2_RIDDLE_STEP2_CHECK
	msgbox NHM2_Battle_Kabutops_Text_0, MSGBOX_AUTOCLOSE
	waitmessage
	goto NHM2_Battle_Kabutops_1

NHM2_Battle_Kabutops_4:
	goto_if_unset FLAG_NHML2_RIDDLE_SOLVED, NHM2_Battle_Kabutops_2
	goto NHM2_Battle_Kabutops_3

NHM2_Battle_Kabutops_5:
	goto_if_set FLAG_NHML2_RIDDLE_STEP1_CHECK, NHM2_Battle_Kabutops_4
	goto NHM2_Battle_Kabutops_3


NHM2_Battle_Omastar::
	lock
	compare VAR_NHM_L2_RIDDLE, 1
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
	msgbox NHM2_Battle_Aerodactyl_Text_1, MSGBOX_AUTOCLOSE
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
	clearflag FLAG_NHML2_RIDDLE_START
	clearflag FLAG_NHML2_RIDDLE_STEP1_CHECK
	setflag FLAG_NHML2_RIDDLE_STEP2_CHECK
	msgbox NHM2_Battle_Aerodactyl_Text_0, MSGBOX_AUTOCLOSE
	waitmessage
	goto NHM2_Battle_Aerodactyl_1

NHM2_Battle_Aerodactyl_4:
	goto_if_unset FLAG_NHML2_RIDDLE_SOLVED, NHM2_Battle_Aerodactyl_2
	goto NHM2_Battle_Aerodactyl_3

NHM2_Battle_Aerodactyl_5:
	goto_if_set FLAG_NHML2_RIDDLE_STEP1_CHECK, NHM2_Battle_Aerodactyl_4
	goto NHM2_Battle_Aerodactyl_3


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
	compare VAR_NHM_L2_RIDDLE, 1
	goto_if_eq NHM2_Battle_Carracosta_5
NHM2_Battle_Carracosta_3:
	randomnr 3
	setorcopyvar VAR_NHM_L2_RIDDLE, VAR_RESULT
	setflag FLAG_NHML2_RIDDLE_START
	clearflag FLAG_NHML2_RIDDLE_STEP1_CHECK
	clearflag FLAG_NHML2_RIDDLE_STEP2_CHECK
	msgbox NHM2_Battle_Carracosta_Text_1, MSGBOX_AUTOCLOSE
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
	clearflag FLAG_NHML2_RIDDLE_START
	clearflag FLAG_NHML2_RIDDLE_STEP1_CHECK
	setflag FLAG_NHML2_RIDDLE_STEP2_CHECK
	msgbox NHM2_Battle_Carracosta_Text_0, MSGBOX_AUTOCLOSE
	waitmessage
	goto NHM2_Battle_Carracosta_1

NHM2_Battle_Carracosta_4:
	goto_if_unset FLAG_NHML2_RIDDLE_SOLVED, NHM2_Battle_Carracosta_2
	goto NHM2_Battle_Carracosta_3

NHM2_Battle_Carracosta_5:
	goto_if_set FLAG_NHML2_RIDDLE_STEP1_CHECK, NHM2_Battle_Carracosta_4
	goto NHM2_Battle_Carracosta_3


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
	switch VAR_NHM_L2_RIDDLE
	case 0, NHML2_Camper_3
	case 1, NHML2_Camper_4
	case 2, NHML2_Camper_5
NHML2_Camper_1:
	release
	end

NHML2_Camper_3:
	msgbox NHML2_Camper_Text_0, MSGBOX_AUTOCLOSE
	goto NHML2_Camper_1

NHML2_Camper_4:
	msgbox NHML2_Camper_Text_1, MSGBOX_AUTOCLOSE
	goto NHML2_Camper_1

NHML2_Camper_5:
	msgbox NHML2_Camper_Text_2, MSGBOX_AUTOCLOSE
	goto NHML2_Camper_1


NHML2_Game_Master::
	lock
	faceplayer
	msgbox NHML2_Game_Master_Text_0, MSGBOX_AUTOCLOSE
	waitmessage
	release
	end


NHML2_Boulder::
	return


Dummy_Give_Furret::
	goto_if_unset FLAG_NHML2_TEST_OBTAIN_FURRET, Dummy_Give_Furret_1
	return

Dummy_Give_Furret_1:
	msgbox Dummy_Give_Furret_Text_0, MSGBOX_AUTOCLOSE
	givemon SPECIES_FURRET, 21
	setflag FLAG_NHML2_TEST_OBTAIN_FURRET
	return


Dummy_Give_Skitty::
	goto_if_unset FLAG_NHML2_TEST_OBTAIN_SKITTY, Dummy_Give_Skitty_1
	return

Dummy_Give_Skitty_1:
	msgbox Dummy_Give_Skitty_Text_0, MSGBOX_AUTOCLOSE
	givemon SPECIES_SKITTY, 11
	setflag FLAG_NHML2_TEST_OBTAIN_SKITTY
	return


Move_exclmark:
	emote_exclamation_mark
	step_end

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

NHM2_Battle_Archen_Text_0:
	.string "There is a PLUME FOSSIL exhibited.\l"
	.string "Feel it's power!$"

NHM2_Battle_Kabutops_Text_0:
	.string "There is a DOME FOSSIL exhibited...\l"
	.string "...A hidden switch clicked.$"

NHM2_Battle_Kabutops_Text_1:
	.string "There is a DOME FOSSIL exhibited.\l"
	.string "Feel it's power!$"

NHM2_Battle_Omastar_Text_0:
	.string "There is a HELIX FOSSIL exhibited...\l"
	.string "...A hidden switch clicked.$"

NHM2_Battle_Omastar_Text_1:
	.string "Something heavy fell from above!$"

NHM2_Battle_Omastar_Text_2:
	.string "There is a HELIX FOSSIL exhibited.\l"
	.string "Feel it's power!$"

NHM2_Battle_Aerodactyl_Text_0:
	.string "There is an OLD AMBER exhibited...\l"
	.string "...A hidden switch clicked.$"

NHM2_Battle_Aerodactyl_Text_1:
	.string "There is an OLD AMBER exhibited.\l"
	.string "Feel it's power!$"

NHM2_Battle_Cradily_Text_0:
	.string "There is a ROOT FOSSIL exhibited...\l"
	.string "...A hidden switch clicked.$"

NHM2_Battle_Cradily_Text_1:
	.string "There is a ROOT FOSSIL exhibited.\l"
	.string "Feel it's power!$"

NHM2_Battle_Armaldo_Text_0:
	.string "There is a CLAW FOSSIL exhibited...\l"
	.string "...A hidden switch clicked.$"

NHM2_Battle_Armaldo_Text_1:
	.string "There is a CLAW FOSSIL exhibited.\l"
	.string "Feel it's power!$"

NHM2_Battle_Rampardos_Text_0:
	.string "There is a SKULL FOSSIL exhibited...\l"
	.string "...A hidden switch clicked.$"

NHM2_Battle_Rampardos_Text_1:
	.string "There is a SKULL FOSSIL exhibited.\l"
	.string "Feel it's power!$"

NHM2_Battle_Bastiodon_Text_0:
	.string "There is a ARMOR FOSSIL exhibited...\l"
	.string "...A hidden switch clicked.$"

NHM2_Battle_Bastiodon_Text_1:
	.string "There is a ARMOR FOSSIL exhibited.\l"
	.string "Feel it's power!$"

NHM2_Battle_Carracosta_Text_0:
	.string "There is a COVER FOSSIL exhibited...\l"
	.string "...A hidden switch clicked.$"

NHM2_Battle_Carracosta_Text_1:
	.string "There is a COVER FOSSIL exhibited.\l"
	.string "Feel it's power!$"

NHM2_Battle_Aurorus_Text_0:
	.string "There is a SAIL FOSSIL exhibited...\l"
	.string "...A hidden switch clicked.$"

NHM2_Battle_Aurorus_Text_1:
	.string "There is a SAIL FOSSIL exhibited.\l"
	.string "Feel it's power!$"

NHML2_Camper_Text_0:
	.string "Hey, there! What's your favorite TYPE?\p"
	.string "Mine is GRASS.$"

NHML2_Camper_Text_1:
	.string "Hey, there! What's your favorite TYPE?\p"
	.string "Mine is FIRE.$"

NHML2_Camper_Text_2:
	.string "Hey, there! What's your favorite TYPE?\p"
	.string "Mine is WATER.$"

NHML2_Game_Master_Text_0:
	.string "I am the game master.\p"
	.string "I will give you helpful advice for each\n"
	.string "situation, but it adds an additional\l"
	.string "30min to your play clock.$"

Dummy_Give_Furret_Text_0:
	.string "You got a Furret.$"

Dummy_Give_Skitty_Text_0:
	.string "You got a Skitty.$"

Text_NotEnoughMons::
	.string "You don't have enough Pokémon to fight\n"
	.string "us.$"
