TARC_SEA_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, TARC_Sea_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, TARC_Sea_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TARC_SEA_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

TARC_SEA_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_LITTLEROOT_TOWN_STATE, 1, TARC_Sea_EveryFrame_GameStart
	.2byte 0


TARC_Sea_OnResume::
	compare VAR_LITTLEROOT_TOWN_STATE, 0
	goto_if_eq TARC_Sea_OnResume_1
	return

TARC_Sea_OnResume_1:
	setorcopyvar VAR_LITTLEROOT_TOWN_STATE, 1
	givemon SPECIES_MANTYKE, 10, ITEM_NONE, 0, NATURE_LONELY, 0, 0, 0, 0, 0, 0, 0, 0, 0, 31, 0, 0, 0, 0, MOVE_TACKLE, MOVE_WING_ATTACK, MOVE_WATER_GUN, MOVE_SURF
	givemon SPECIES_SABLEYE, 10, ITEM_SILK_SCARF, 0, NATURE_BRAVE, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 20, MOVE_SCRATCH, MOVE_FLING, MOVE_PROTECT, MOVE_DISABLE
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
	callnative SetAllDexFlagsSeen
	return


TARC_Sea_OnTransition::
	setrespawn HEAL_LOCATION_TARC_ISLAND
	return


TARC_Sea_EveryFrame_GameStart::
	lock
	setorcopyvar VAR_LITTLEROOT_TOWN_STATE, 2
	applymovement OBJ_EVENT_ID_PLAYER, Move_driftintocurrents
	waitmovement 0
	release
	return


Move_exclmark:
	emote_exclamation_mark
	step_end

Move_driftintocurrents:
	face_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	face_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	face_left
	walk_left
	walk_left
	face_up
	walk_up
	walk_up
	walk_up
	walk_up
	face_left
	walk_left
	walk_left
	walk_left
	face_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Move_AfterRelease:
	walk_up
	step_end

Move_AfterCurrent:
	emote_exclamation_mark
	delay_4
	face_right
	delay_1
	face_left
	delay_1
	face_right
	delay_1
	face_left
	delay_1
	step_end
