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
	givemon SPECIES_SABLEYE, 10, ITEM_LIFE_ORB, 0, NATURE_BRAVE, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 20, MOVE_SCRATCH, MOVE_FLING, MOVE_PROTECT, MOVE_DISABLE
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
	applymovement OBJ_EVENT_ID_PLAYER, Move_exclmark
	waitmovement 0
	msgbox TARC_Sea_EveryFrame_GameStart_Text_0, MSGBOX_AUTOCLOSE
	release
	return


TARC_SEA_Wingull::
	lock
	faceplayer
	playmoncry SPECIES_WINGULL, CRY_MODE_NORMAL
	msgbox TARC_SEA_Wingull_Text_0, MSGBOX_AUTOCLOSE
	release
	return


TARC_SEA_GameEnd::
	lock
	special StopPlayTimer
	specialvar VAR_RESULT, GetPlayTimeHours
	buffernumberstring STR_VAR_1, VAR_RESULT
	specialvar VAR_RESULT, GetPlayTimeMinutes
	buffertimestring STR_VAR_2, VAR_RESULT
	specialvar VAR_RESULT, GetPlayTimeSeconds
	buffertimestring STR_VAR_3, VAR_RESULT
	msgbox TARC_SEA_GameEnd_Text_0, MSGBOX_AUTOCLOSE
	applymovement OBJ_EVENT_ID_PLAYER, Move_ArchieLeaves
	waitmovement 0
	fadescreen FADE_TO_BLACK
	msgbox TARC_SEA_GameEnd_Text_1
	waitmessage
	setorcopyvar VAR_TARC_COUNT, 0
	goto_if_set FLAG_HINT01, TARC_SEA_GameEnd_2
TARC_SEA_GameEnd_1:
	goto_if_set FLAG_HINT02, TARC_SEA_GameEnd_5
TARC_SEA_GameEnd_4:
	goto_if_set FLAG_HINT03, TARC_SEA_GameEnd_8
TARC_SEA_GameEnd_7:
	goto_if_set FLAG_HINT04, TARC_SEA_GameEnd_11
TARC_SEA_GameEnd_10:
	goto_if_set FLAG_HINT05, TARC_SEA_GameEnd_14
TARC_SEA_GameEnd_13:
	goto_if_set FLAG_HINT06, TARC_SEA_GameEnd_17
TARC_SEA_GameEnd_16:
	goto_if_set FLAG_HINT07, TARC_SEA_GameEnd_20
TARC_SEA_GameEnd_19:
	goto_if_set FLAG_HINT08, TARC_SEA_GameEnd_23
TARC_SEA_GameEnd_22:
	goto_if_set FLAG_HINT09, TARC_SEA_GameEnd_26
TARC_SEA_GameEnd_25:
	goto_if_set FLAG_HINT10, TARC_SEA_GameEnd_29
TARC_SEA_GameEnd_28:
	goto_if_set FLAG_HINT11, TARC_SEA_GameEnd_32
TARC_SEA_GameEnd_31:
	goto_if_set FLAG_HINT12, TARC_SEA_GameEnd_35
TARC_SEA_GameEnd_34:
	goto_if_set FLAG_HINT13, TARC_SEA_GameEnd_38
TARC_SEA_GameEnd_37:
	goto_if_set FLAG_HINT14, TARC_SEA_GameEnd_41
TARC_SEA_GameEnd_40:
	goto_if_set FLAG_HINT15, TARC_SEA_GameEnd_44
TARC_SEA_GameEnd_43:
	goto_if_set FLAG_HINT16, TARC_SEA_GameEnd_47
TARC_SEA_GameEnd_46:
	goto_if_set FLAG_HINT17, TARC_SEA_GameEnd_50
TARC_SEA_GameEnd_49:
	goto_if_set FLAG_HINT18, TARC_SEA_GameEnd_53
TARC_SEA_GameEnd_52:
	goto_if_set FLAG_HINT19, TARC_SEA_GameEnd_56
TARC_SEA_GameEnd_55:
	goto_if_set FLAG_HINT20, TARC_SEA_GameEnd_59
TARC_SEA_GameEnd_58:
	buffernumberstring STR_VAR_1, VAR_TARC_COUNT
	msgbox TARC_SEA_GameEnd_Text_2
	waitmessage
	special StartCredits
	return

TARC_SEA_GameEnd_2:
	addvar VAR_TARC_COUNT, 1
	goto TARC_SEA_GameEnd_1

TARC_SEA_GameEnd_5:
	addvar VAR_TARC_COUNT, 1
	goto TARC_SEA_GameEnd_4

TARC_SEA_GameEnd_8:
	addvar VAR_TARC_COUNT, 1
	goto TARC_SEA_GameEnd_7

TARC_SEA_GameEnd_11:
	addvar VAR_TARC_COUNT, 1
	goto TARC_SEA_GameEnd_10

TARC_SEA_GameEnd_14:
	addvar VAR_TARC_COUNT, 1
	goto TARC_SEA_GameEnd_13

TARC_SEA_GameEnd_17:
	addvar VAR_TARC_COUNT, 1
	goto TARC_SEA_GameEnd_16

TARC_SEA_GameEnd_20:
	addvar VAR_TARC_COUNT, 1
	goto TARC_SEA_GameEnd_19

TARC_SEA_GameEnd_23:
	addvar VAR_TARC_COUNT, 1
	goto TARC_SEA_GameEnd_22

TARC_SEA_GameEnd_26:
	addvar VAR_TARC_COUNT, 1
	goto TARC_SEA_GameEnd_25

TARC_SEA_GameEnd_29:
	addvar VAR_TARC_COUNT, 1
	goto TARC_SEA_GameEnd_28

TARC_SEA_GameEnd_32:
	addvar VAR_TARC_COUNT, 1
	goto TARC_SEA_GameEnd_31

TARC_SEA_GameEnd_35:
	addvar VAR_TARC_COUNT, 1
	goto TARC_SEA_GameEnd_34

TARC_SEA_GameEnd_38:
	addvar VAR_TARC_COUNT, 1
	goto TARC_SEA_GameEnd_37

TARC_SEA_GameEnd_41:
	addvar VAR_TARC_COUNT, 1
	goto TARC_SEA_GameEnd_40

TARC_SEA_GameEnd_44:
	addvar VAR_TARC_COUNT, 1
	goto TARC_SEA_GameEnd_43

TARC_SEA_GameEnd_47:
	addvar VAR_TARC_COUNT, 1
	goto TARC_SEA_GameEnd_46

TARC_SEA_GameEnd_50:
	addvar VAR_TARC_COUNT, 1
	goto TARC_SEA_GameEnd_49

TARC_SEA_GameEnd_53:
	addvar VAR_TARC_COUNT, 1
	goto TARC_SEA_GameEnd_52

TARC_SEA_GameEnd_56:
	addvar VAR_TARC_COUNT, 1
	goto TARC_SEA_GameEnd_55

TARC_SEA_GameEnd_59:
	addvar VAR_TARC_COUNT, 1
	goto TARC_SEA_GameEnd_58


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

TARC_Sea_EveryFrame_GameStart_Text_0:
	.string "{PLAYER} regained consciousness.$"

TARC_SEA_Wingull_Text_0:
	.string "Wingull!$"

TARC_SEA_GameEnd_Text_0:
	.string "Congratulations {PLAYER}!\p"
	.string "You freed yourself from the island and\n"
	.string "can now safely surf back home.$"

TARC_SEA_GameEnd_Text_1:
	.string "You have completed the challenge. Well\n"
	.string "done!\p"
	.string "Your final time is\n"
	.string "{STR_VAR_1}:{STR_VAR_2}:{STR_VAR_3}.$"

TARC_SEA_GameEnd_Text_2:
	.string "You have been using {STR_VAR_1}\n"
	.string "hint(s).$"
