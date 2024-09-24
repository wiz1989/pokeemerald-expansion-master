TARC_UNDERWATER_MapScripts::
	.byte 0


TARC_UNDERWATER_Archie::
	trainerbattle_single TRAINER_ARCHIE, Archie_Intro, Archie_Defeat
	lock
	msgbox TARC_UNDERWATER_Archie_Text_0, MSGBOX_AUTOCLOSE
	applymovement 1, Move_ArchieLeaves
	waitmovement 0
	removeobject 1
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


TARC_UNDERWATER_Octillery::
	lock
	faceplayer
	playmoncry SPECIES_OCTILLERY, CRY_MODE_NORMAL
	msgbox TARC_UNDERWATER_Octillery_Text_0, MSGBOX_AUTOCLOSE
	release
	return


TARC_UNDERWATER_Lanturn::
	lock
	faceplayer
	playmoncry SPECIES_LANTURN, CRY_MODE_NORMAL
	msgbox TARC_UNDERWATER_Lanturn_Text_0, MSGBOX_AUTOCLOSE
	release
	return


Move_ArchieLeaves:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

TARC_UNDERWATER_Archie_Text_0:
	.string "I will return stronger!$"

TARC_UNDERWATER_OpenCave_Sign_Text_0:
	.string "The secret switch is hidden in the sand.$"

TARC_UNDERWATER_OpenCave_Sign_Text_1:
	.string "What is this?$"

TARC_UNDERWATER_OpenCave_Text_0:
	.string "A hidden trigger activated.$"

TARC_UNDERWATER_Octillery_Text_0:
	.string "Octillery!$"

TARC_UNDERWATER_Lanturn_Text_0:
	.string "Lanturn!$"

Archie_Intro::
	.string "Maxie and I might have a\n"
	.string "TOXIC relationship, but\l"
	.string "this has nothing to do with\l"
	.string "me taking over this island!\p"
	.string "You won't BREAK my plans!$"

Archie_Defeat::
	.string "How dare you!\p"
	.string "Where did you get these Pokémon\n"
	.string "from?\p"
	.string "Aaaargh!$"
