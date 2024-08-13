TARC_CAVE_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, TARC_CAVE_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, TARC_CAVE_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TARC_CAVE_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

TARC_CAVE_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_TARC_CAVE_FIELD, 3, TARC_CAVE_EveryFrame_Room1
	map_script_2 VAR_TARC_CAVE_FIELD, 13, TARC_CAVE_EveryFrame_Room2
	map_script_2 VAR_TARC_CAVE_GUARD1_STATE, 1, TARC_CAVE_EveryFrame_Guard1
	map_script_2 VAR_TARC_CAVE_GUARD2_STATE, 1, TARC_CAVE_EveryFrame_Guard2
	.2byte 0


TARC_CAVE_OnResume::
	return


TARC_CAVE_OnTransition::
	setflag FLAG_DONT_REMOVE_OFFSCREEN_OBJECT
	clearflag FLAG_CAVE_KICKOUT1
	clearflag FLAG_CAVE_MOVER1
	clearflag FLAG_CAVE_GUARD1
	clearflag FLAG_CAVE_KICKOUT2
	clearflag FLAG_CAVE_KICKOUT3
	clearflag FLAG_CAVE_MOVER2
	goto_if_set FLAG_CAVE_SOLVED1, TARC_CAVE_OnTransition_2
	setorcopyvar VAR_TARC_CAVE_FIELD, 0
TARC_CAVE_OnTransition_1:
	goto_if_set FLAG_CAVE_SOLVED2, TARC_CAVE_OnTransition_5
	return

TARC_CAVE_OnTransition_2:
	setorcopyvar VAR_TARC_CAVE_FIELD, 10
	setorcopyvar VAR_TARC_CAVE_GUARD1_STATE, 1
	setflag FLAG_CAVE_KICKOUT1
	setflag FLAG_CAVE_MOVER1
	setflag FLAG_CAVE_GUARD1
	setflag FLAG_HIDE_KICKOUT1
	setflag FLAG_HIDE_MOVER1
	setflag FLAG_HIDE_GUARD1
	goto TARC_CAVE_OnTransition_1

TARC_CAVE_OnTransition_5:
	setorcopyvar VAR_TARC_CAVE_GUARD2_STATE, 1
	setflag FLAG_CAVE_KICKOUT2
	setflag FLAG_CAVE_KICKOUT3
	setflag FLAG_CAVE_MOVER2
	setflag FLAG_CAVE_GUARD2
	setflag FLAG_HIDE_KICKOUT2
	setflag FLAG_HIDE_KICKOUT3
	setflag FLAG_HIDE_MOVER2
	setflag FLAG_HIDE_GUARD2
	return


TARC_CAVE_EveryFrame_Room1::
	setorcopyvar VAR_TARC_CAVE_FIELD, 10
	goto_if_unset FLAG_CAVE_SOLVED1, TARC_CAVE_EveryFrame_Room1_1
	return

TARC_CAVE_EveryFrame_Room1_1:
	applymovement 6, Move_faceright
	setflag FLAG_CAVE_SOLVED1
	setorcopyvar VAR_TARC_CAVE_GUARD1_STATE, 1
	setflag FLAG_CAVE_KICKOUT1
	setflag FLAG_CAVE_MOVER1
	setflag FLAG_CAVE_GUARD1
	return


TARC_CAVE_EveryFrame_Room2::
	setorcopyvar VAR_TARC_CAVE_FIELD, 20
	goto_if_set FLAG_CAVE_SOLVED1, TARC_CAVE_EveryFrame_Room2_1
	return

TARC_CAVE_EveryFrame_Room2_1:
	turnobject 13, DIR_WEST
	setflag FLAG_CAVE_SOLVED2
	setorcopyvar VAR_TARC_CAVE_GUARD2_STATE, 1
	setflag FLAG_CAVE_KICKOUT2
	setflag FLAG_CAVE_KICKOUT3
	setflag FLAG_CAVE_MOVER2
	setflag FLAG_CAVE_GUARD2
	return


TARC_CAVE_EveryFrame_Guard1::
	goto_if_set FLAG_CAVE_SOLVED1, TARC_CAVE_EveryFrame_Guard1_1
	return

TARC_CAVE_EveryFrame_Guard1_1:
	turnobject 6, DIR_EAST
	setorcopyvar VAR_TARC_CAVE_GUARD1_STATE, 2
	return


TARC_CAVE_EveryFrame_Guard2::
	goto_if_set FLAG_CAVE_SOLVED2, TARC_CAVE_EveryFrame_Guard2_1
	return

TARC_CAVE_EveryFrame_Guard2_1:
	turnobject 13, DIR_WEST
	setorcopyvar VAR_TARC_CAVE_GUARD2_STATE, 2
	return


TARC_CAVE_Regirock::
	lock
	faceplayer
	msgbox TARC_CAVE_Regirock_Text_0, MSGBOX_AUTOCLOSE
	release
	return


TARC_Cave_Kickout::
	lock
	faceplayer
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
	msgbox TARC_Cave_Kickout_Text_0, MSGBOX_AUTOCLOSE
	warp MAP_TARC_CAVE, 0
	release
	return


TARC_Cave_Kickout2::
	lock
	faceplayer
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
	msgbox TARC_Cave_Kickout_Text_0, MSGBOX_AUTOCLOSE
	warp MAP_TARC_CAVE, 2
	release
	return


TARC_Cave_Mover::
	lock
	faceplayer
	playmoncry SPECIES_DUSCLOPS, CRY_MODE_ENCOUNTER
	msgbox TARC_Cave_Mover_Text_0, MSGBOX_AUTOCLOSE
	release
	return


TARC_Cave_Kickout_Guard::
	lock
	faceplayer
	playmoncry SPECIES_PIKACHU, CRY_MODE_ENCOUNTER
	msgbox TARC_Cave_Kickout_Text_0, MSGBOX_AUTOCLOSE
	warp MAP_TARC_CAVE, 0
	release
	return


TARC_Cave_Kickout_Guard2::
	lock
	faceplayer
	playmoncry SPECIES_PIKACHU, CRY_MODE_ENCOUNTER
	msgbox TARC_Cave_Kickout_Text_0, MSGBOX_AUTOCLOSE
	warp MAP_TARC_CAVE, 2
	release
	return


Move_faceright:
	face_right
	step_end

TARC_CAVE_Regirock_Text_0:
	.string "Who dares to enter these halls?$"

TARC_Cave_Kickout_Text_0:
	.string "AN INTRUDER!\p"
	.string "Leave this sacred place immediately!$"

TARC_Cave_Mover_Text_0:
	.string "Screech!$"
