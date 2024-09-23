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
	map_script_2 VAR_CAVE_STATE, 0, TARC_CAVE_EveryFrame_FirstTime
	.2byte 0


TARC_CAVE_OnResume::
	return


TARC_CAVE_EveryFrame_FirstTime::
	lock
	addvar VAR_CAVE_STATE, 1
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 4
	setvar VAR_0x8007, 5
	special ShakeCamera
	waitstate
	applymovement OBJ_EVENT_ID_PLAYER, Move_exclmark
	waitmovement 0
	playmoncry SPECIES_REGIROCK, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	applymovement 14, Move_Regirock
	waitmovement 0
	msgbox TARC_CAVE_EveryFrame_FirstTime_Text_0, MSGBOX_AUTOCLOSE
	applymovement 14, Move_exclmark
	waitmovement 0
	msgbox TARC_CAVE_EveryFrame_FirstTime_Text_1, MSGBOX_AUTOCLOSE
	waitmessage
	showmonpic SPECIES_SABLEYE, 10, 3
	playmoncry SPECIES_SABLEYE, CRY_MODE_NORMAL
	delay 40
	waitmoncry
	applymovement OBJ_EVENT_ID_PLAYER, Move_exclmark
	waitmovement 0
	msgbox TARC_CAVE_EveryFrame_FirstTime_Text_2, MSGBOX_AUTOCLOSE
	hidemonpic
	showmonpic SPECIES_REGIROCK, 10, 3
	playmoncry SPECIES_REGIROCK, CRY_MODE_NORMAL
	delay 40
	msgbox TARC_CAVE_EveryFrame_FirstTime_Text_3, MSGBOX_AUTOCLOSE
	hidemonpic
	getpartymonslot SPECIES_SABLEYE
	special DeletePartyMon
	givemon SPECIES_CUBONE, 5, ITEM_NONE, 0, NATURE_LONELY, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, MOVE_STRENGTH, MOVE_MUD_SLAP, MOVE_TAIL_WHIP, MOVE_GROWL
	playfanfare MUS_OBTAIN_ITEM
	message TARC_CAVE_EveryFrame_FirstTime_Text_4
	waitmessage
	waitfanfare
	closemessage
	release
	return


TARC_CAVE_OnTransition::
	setflag FLAG_DONT_REMOVE_OFFSCREEN_OBJECT
	clearflag FLAG_CAVE_KICKOUT1
	clearflag FLAG_CAVE_MOVER0
	clearflag FLAG_CAVE_MOVER1
	clearflag FLAG_CAVE_GUARD1
	clearflag FLAG_CAVE_KICKOUT2
	clearflag FLAG_CAVE_KICKOUT3
	clearflag FLAG_CAVE_MOVER2
	clearflag FLAG_CAVE_MOVER3
	goto_if_set FLAG_CAVE_SOLVED1, TARC_CAVE_OnTransition_2
	setorcopyvar VAR_TARC_CAVE_FIELD, 0
TARC_CAVE_OnTransition_1:
	goto_if_set FLAG_CAVE_SOLVED2, TARC_CAVE_OnTransition_5
	return

TARC_CAVE_OnTransition_2:
	setorcopyvar VAR_TARC_CAVE_FIELD, 10
	setorcopyvar VAR_TARC_CAVE_GUARD1_STATE, 1
	setflag FLAG_CAVE_KICKOUT1
	setflag FLAG_CAVE_GUARD1
	setobjectxyperm 5, 20, 9
	goto TARC_CAVE_OnTransition_1

TARC_CAVE_OnTransition_5:
	setorcopyvar VAR_TARC_CAVE_GUARD2_STATE, 1
	setflag FLAG_CAVE_KICKOUT2
	setflag FLAG_CAVE_KICKOUT3
	setflag FLAG_CAVE_GUARD2
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
	setflag FLAG_CAVE_MOVER0
	setflag FLAG_CAVE_MOVER1
	setflag FLAG_CAVE_GUARD1
	return


TARC_CAVE_EveryFrame_Room2::
	setorcopyvar VAR_TARC_CAVE_FIELD, 20
	goto_if_set FLAG_CAVE_SOLVED1, TARC_CAVE_EveryFrame_Room2_1
	return

TARC_CAVE_EveryFrame_Room2_1:
	addobject 13
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
	addobject 13
	turnobject 13, DIR_WEST
	setorcopyvar VAR_TARC_CAVE_GUARD2_STATE, 2
	return


TARC_CAVE_ItemBall::
	lock
	removeobject 17, MAP_TARC_CAVE
	finditem ITEM_GYARADOSITE, 1
	release
	return


TARC_CAVE_Regirock::
	lock
	faceplayer
	playmoncry SPECIES_REGIROCK, CRY_MODE_NORMAL
	msgbox TARC_CAVE_Regirock_Text_0, MSGBOX_AUTOCLOSE
	release
	return


TARC_Cave_Kickout::
	lock
	setflag FLAG_CAVE_KICKOUT1
	faceplayer
	playmoncry SPECIES_KADABRA, CRY_MODE_ENCOUNTER
	msgbox TARC_Cave_Kickout_Text_0, MSGBOX_AUTOCLOSE
	warp MAP_TARC_CAVE, 0
	release
	return


TARC_Cave_Kickout2::
	lock
	setflag FLAG_CAVE_KICKOUT2
	faceplayer
	playmoncry SPECIES_KADABRA, CRY_MODE_ENCOUNTER
	msgbox TARC_Cave_Kickout_Text_0, MSGBOX_AUTOCLOSE
	warp MAP_TARC_CAVE, 2
	release
	return


TARC_Cave_Kickout3::
	lock
	setflag FLAG_CAVE_KICKOUT3
	faceplayer
	playmoncry SPECIES_KADABRA, CRY_MODE_ENCOUNTER
	msgbox TARC_Cave_Kickout_Text_0, MSGBOX_AUTOCLOSE
	warp MAP_TARC_CAVE, 2
	release
	return


TARC_Cave_Mover::
	lock
	setflag FLAG_CAVE_MOVER0
	faceplayer
	playmoncry SPECIES_ZUBAT, CRY_MODE_ENCOUNTER
	msgbox TARC_Cave_Mover_Text_0, MSGBOX_AUTOCLOSE
	release
	return


TARC_Cave_Mover1::
	lock
	setflag FLAG_CAVE_MOVER1
	faceplayer
	playmoncry SPECIES_ZUBAT, CRY_MODE_ENCOUNTER
	msgbox TARC_Cave_Mover_Text_0, MSGBOX_AUTOCLOSE
	release
	return


TARC_Cave_Mover2::
	lock
	setflag FLAG_CAVE_MOVER2
	faceplayer
	playmoncry SPECIES_ZUBAT, CRY_MODE_ENCOUNTER
	msgbox TARC_Cave_Mover_Text_0, MSGBOX_AUTOCLOSE
	release
	return


TARC_Cave_Mover3::
	lock
	setflag FLAG_CAVE_MOVER3
	faceplayer
	playmoncry SPECIES_ZUBAT, CRY_MODE_ENCOUNTER
	msgbox TARC_Cave_Mover_Text_0, MSGBOX_AUTOCLOSE
	release
	return


TARC_Cave_Kickout_Guard::
	lock
	setflag FLAG_CAVE_GUARD1
	faceplayer
	playmoncry SPECIES_ONIX, CRY_MODE_ENCOUNTER
	msgbox TARC_Cave_Kickout_Text_0, MSGBOX_AUTOCLOSE
	warp MAP_TARC_CAVE, 0
	release
	return


TARC_Cave_Kickout_Guard2::
	lock
	setflag FLAG_CAVE_GUARD2
	faceplayer
	playmoncry SPECIES_ONIX, CRY_MODE_ENCOUNTER
	msgbox TARC_Cave_Kickout_Text_0, MSGBOX_AUTOCLOSE
	warp MAP_TARC_CAVE, 2
	release
	return


TARC_Cave_Move_Zubat_away::
	lock
	setobjectxy 16, 21, 37
	release
	return


TARC_Cave_Turn_Onix::
	lock
	goto_if_set FLAG_CAVE_SOLVED2, TARC_Cave_Turn_Onix_2
TARC_Cave_Turn_Onix_1:
	release
	return

TARC_Cave_Turn_Onix_2:
	turnobject 13, DIR_WEST
	goto TARC_Cave_Turn_Onix_1


TARC_CAVE_Braille1::
	lockall
	braillemsgbox TARC_CAVE_Braille1_Text
	releaseall
	return


TARC_CAVE_Braille2::
	lockall
	braillemsgbox TARC_CAVE_Braille2_Text
	releaseall
	return


TARC_CAVE_Braille3::
	lockall
	braillemsgbox TARC_CAVE_Braille3_Text
	releaseall
	return


Move_faceright:
	face_right
	step_end

Move_faceup:
	face_up
	step_end

Move_faceleft:
	face_left
	step_end

Move_facedown:
	face_down
	step_end

Move_Regirock:
	walk_down
	walk_down
	face_left
	walk_left
	walk_left
	walk_left
	face_down
	walk_down
	step_end

TARC_CAVE_EveryFrame_FirstTime_Text_0:
	.string "INTRUDER!\p"
	.string "Leave this place immediat...$"

TARC_CAVE_EveryFrame_FirstTime_Text_1:
	.string "... you are...\p"
	.string "...friends with a Sableye!\p"
	.string "The guardian of the mines!$"

TARC_CAVE_EveryFrame_FirstTime_Text_2:
	.string "What?\p"
	.string "Sableye just freed itself from its\n"
	.string "Pokéball.$"

TARC_CAVE_EveryFrame_FirstTime_Text_3:
	.string "Traveller, it seems that Sableye is\n"
	.string "willing to stay in this cave.\p"
	.string "I will give you a new companion to\n"
	.string "continue your journey through these\l"
	.string "halls.\p"
	.string "Farewell!$"

TARC_CAVE_EveryFrame_FirstTime_Text_4:
	.string "You received a little CUBONE.$"

TARC_CAVE_Regirock_Text_0:
	.string "Who dares to enter these halls?$"

TARC_Cave_Kickout_Text_0:
	.string "AN INTRUDER!\p"
	.string "Leave this sacred place immediately!$"

TARC_Cave_Mover_Text_0:
	.string "Screech!$"
