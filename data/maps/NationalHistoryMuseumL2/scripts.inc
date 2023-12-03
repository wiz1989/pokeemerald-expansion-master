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
	msgbox NHM2_Battle_Kabutops_Text_0, MSGBOX_AUTOCLOSE
	waitmessage
	playmoncry SPECIES_KABUTOPS, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_KABUTOPS, 100
	dowildbattle
	end


NHM2_Battle_Omastar::
	msgbox NHM2_Battle_Omastar_Text_0, MSGBOX_AUTOCLOSE
	waitmessage
	playmoncry SPECIES_OMASTAR, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_OMASTAR, 100
	dowildbattle
	end


NHM2_Battle_Aerodactyl::
	msgbox NHM2_Battle_Aerodactyl_Text_0, MSGBOX_AUTOCLOSE
	waitmessage
	playmoncry SPECIES_AERODACTYL, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_AERODACTYL, 100
	dowildbattle
	end


NHM2_Battle_Cradily::
	msgbox NHM2_Battle_Cradily_Text_0, MSGBOX_AUTOCLOSE
	waitmessage
	playmoncry SPECIES_CRADILY, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_CRADILY, 100
	dowildbattle
	end


NHM2_Battle_Armaldo::
	msgbox NHM2_Battle_Armaldo_Text_0, MSGBOX_AUTOCLOSE
	waitmessage
	playmoncry SPECIES_ARMALDO, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_ARMALDO, 100
	dowildbattle
	end


NHM2_Battle_Rampardos::
	msgbox NHM2_Battle_Rampardos_Text_0, MSGBOX_AUTOCLOSE
	waitmessage
	playmoncry SPECIES_RAMPARDOS, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_RAMPARDOS, 100
	dowildbattle
	end


NHM2_Battle_Bastiodon::
	msgbox NHM2_Battle_Bastiodon_Text_0, MSGBOX_AUTOCLOSE
	waitmessage
	playmoncry SPECIES_BASTIODON, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_BASTIODON, 100
	dowildbattle
	end


NHM2_Battle_Carracosta::
	msgbox NHM2_Battle_Carracosta_Text_0, MSGBOX_AUTOCLOSE
	waitmessage
	playmoncry SPECIES_CARRACOSTA, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_CARRACOSTA, 100
	dowildbattle
	end


NHM2_Battle_Aurorus::
	msgbox NHM2_Battle_Aurorus_Text_0, MSGBOX_AUTOCLOSE
	waitmessage
	playmoncry SPECIES_AURORUS, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_AURORUS, 100
	dowildbattle
	end


NHML2_Camper::
	lock
	buffernumberstring STR_VAR_2, VAR_NHM_L2_RIDDLE
	msgbox NHML2_Camper_Text_0, MSGBOX_AUTOCLOSE
	release
	end


NHML2_Boulder::
	return


Dummy_Give_Furret::
	msgbox Dummy_Give_Furret_Text_0, MSGBOX_AUTOCLOSE
	givemon SPECIES_FURRET, 21
	return


Dummy_Give_Skitty::
	msgbox Dummy_Give_Skitty_Text_0, MSGBOX_AUTOCLOSE
	givemon SPECIES_SKITTY, 11
	return


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
	.string "There is a DOME FOSSIL exhibited.\l"
	.string "Feel it's power!$"

NHM2_Battle_Omastar_Text_0:
	.string "There is a HELIX FOSSIL exhibited.\l"
	.string "Feel it's power!$"

NHM2_Battle_Aerodactyl_Text_0:
	.string "There is an OLD AMBER exhibited.\l"
	.string "Feel it's power!$"

NHM2_Battle_Cradily_Text_0:
	.string "There is a ROOT FOSSIL exhibited.\l"
	.string "Feel it's power!$"

NHM2_Battle_Armaldo_Text_0:
	.string "There is a CLAW FOSSIL exhibited.\l"
	.string "Feel it's power!$"

NHM2_Battle_Rampardos_Text_0:
	.string "There is a SKULL FOSSIL exhibited.\l"
	.string "Feel it's power!$"

NHM2_Battle_Bastiodon_Text_0:
	.string "There is an ARMOR FOSSIL exhibited.\l"
	.string "Feel it's power!$"

NHM2_Battle_Carracosta_Text_0:
	.string "There is a COVER FOSSIL exhibited.\l"
	.string "Feel it's power!$"

NHM2_Battle_Aurorus_Text_0:
	.string "There is a SAIL FOSSIL exhibited.\l"
	.string "Feel it's power!$"

NHML2_Camper_Text_0:
	.string "{STR_VAR_2} - Hey, there! What's\n"
	.string "your favorite TYPE?\p"
	.string "Mine is GRASS.$"

Dummy_Give_Furret_Text_0:
	.string "You got a Furret.$"

Dummy_Give_Skitty_Text_0:
	.string "You got a Skitty.$"

Text_NotEnoughMons::
	.string "You don't have enough Pokémon to fight\n"
	.string "us.$"
