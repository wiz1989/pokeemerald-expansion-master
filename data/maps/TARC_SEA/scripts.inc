TARC_SEA_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, TARC_Sea_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, TARC_Sea_OnTransition
	.byte 0


TARC_Sea_OnResume::
	compare VAR_LITTLEROOT_TOWN_STATE, 0
	goto_if_eq TARC_Sea_OnResume_1
	return

TARC_Sea_OnResume_1:
	givemon SPECIES_MANTYKE, 5
	setflag FLAG_SYS_POKEMON_GET
	setflag FLAG_RECEIVED_RUNNING_SHOES
	setflag FLAG_SYS_B_DASH
	setflag FLAG_BADGE01_GET
	setflag FLAG_BADGE02_GET
	setflag FLAG_BADGE03_GET
	setflag FLAG_BADGE04_GET
	setflag FLAG_BADGE05_GET
	setflag FLAG_BADGE06_GET
	setflag FLAG_BADGE07_GET
	setflag FLAG_BADGE08_GET
	setflag FLAG_SYS_POKEDEX_GET
	setflag FLAG_SYS_NATIONAL_DEX
	special EnableNationalPokedex
	giveitem ITEM_POKE_BALL, 2
	return


TARC_Sea_OnTransition::
	setrespawn HEAL_LOCATION_TARC_ISLAND
	return

