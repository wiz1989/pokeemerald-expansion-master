TARC_UNDERWATER_MapScripts::
	.byte 0


TARC_UNDERWATER_Archie::
	trainerbattle_single TRAINER_ARCHIE, Archie_Intro, Archie_Defeat
	lock
	msgbox TARC_UNDERWATER_Archie_Text_0, MSGBOX_AUTOCLOSE
	release
	return


TARC_UNDERWATER_OpenCave_Sign::
	lock
	compare VAR_TARC_UNDERWATER_CAVE, 0
	goto_if_gt TARC_UNDERWATER_OpenCave_Sign_2
	msgbox TARC_UNDERWATER_OpenCave_Sign_Text_1, MSGBOX_AUTOCLOSE
TARC_UNDERWATER_OpenCave_Sign_1:
	release
	return

TARC_UNDERWATER_OpenCave_Sign_2:
	msgbox TARC_UNDERWATER_OpenCave_Sign_Text_0, MSGBOX_AUTOCLOSE
	goto TARC_UNDERWATER_OpenCave_Sign_1


TARC_UNDERWATER_OpenCave::
	lockall
	msgbox TARC_UNDERWATER_OpenCave_Text_0, MSGBOX_AUTOCLOSE
	waitmessage
	setvar VAR_TARC_UNDERWATER_CAVE, 1
	setmetatile 49, 23, METATILE_Underwater_DoorTop, TRUE
	setmetatile 49, 24, METATILE_Underwater_DoorBottom, FALSE
	special DrawWholeMapView
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	applymovement OBJ_EVENT_ID_PLAYER, Move_exclmark
	waitmovement 0
	releaseall
	return


TARC_UNDERWATER_OpenCave_Pre::
	lockall
	setmetatile 49, 23, METATILE_Underwater_RockWall, TRUE
	setmetatile 49, 24, METATILE_Underwater_RockWall, TRUE
	special DrawWholeMapView
	releaseall
	return


TARC_UNDERWATER_Update_Healspot::
	lock
	setrespawn HEAL_LOCATION_TARC_UNDERWATER
	release
	return


TARC_UNDERWATER_Archie_Text_0:
	.string "Archie placeholder text$"

TARC_UNDERWATER_OpenCave_Sign_Text_0:
	.string "The secret switch is hidden in the sand.$"

TARC_UNDERWATER_OpenCave_Sign_Text_1:
	.string "What is this?$"

TARC_UNDERWATER_OpenCave_Text_0:
	.string "A hidden trigger activated.$"

Archie_Intro::
	.string "Hello, there.\p"
	.string "You can refer to me in scripts or C code.$"

Archie_Defeat::
	.string "Hello, there.\p"
	.string "You can refer to me in scripts or C code.$"
