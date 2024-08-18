TARC_Island_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, TARC_Island_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, TARC_Island_OnTransition
	.byte 0


TARC_Island_OnResume::
	setvar VAR_TEMP_2, 0
	return


TARC_Island_OnTransition::
	setrespawn HEAL_LOCATION_TARC_ISLAND
	clearflag FLAG_DONT_REMOVE_OFFSCREEN_OBJECT
	compare VAR_RHYDON_STATE, 5
	goto_if_lt TARC_Island_OnTransition_2
TARC_Island_OnTransition_1:
	compare VAR_RHYDON_STATE, 5
	goto_if_eq TARC_Island_OnTransition_4
	return

TARC_Island_OnTransition_2:
	setorcopyvar VAR_RHYDON_STATE, 0
	goto TARC_Island_OnTransition_1

TARC_Island_OnTransition_4:
	setobjectxyperm 20, 26, 13
	return


TARC_Island_Fisherman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_OLD_ROD, TARC_Island_Fisherman_2
	msgbox TARC_Island_Fisherman_Text_4, MSGBOX_AUTOCLOSE
	giveitem ITEM_OLD_ROD
	setflag FLAG_RECEIVED_OLD_ROD
	msgbox TARC_Island_Fisherman_Text_5, MSGBOX_AUTOCLOSE
TARC_Island_Fisherman_1:
	release
	end

TARC_Island_Fisherman_2:
	goto_if_set FLAG_TARC_REMORAID, TARC_Island_Fisherman_5
	msgbox TARC_Island_Fisherman_Text_3, MSGBOX_AUTOCLOSE
	goto TARC_Island_Fisherman_1

TARC_Island_Fisherman_5:
	goto_if_set FLAG_WON_SEISMITOAD, TARC_Island_Fisherman_8
	msgbox TARC_Island_Fisherman_Text_2, MSGBOX_AUTOCLOSE
	goto TARC_Island_Fisherman_1

TARC_Island_Fisherman_8:
	goto_if_set FLAG_REMORAID_TRADE_COMPLETED, TARC_Island_Fisherman_11
	msgbox TARC_Island_Fisherman_Text_0, MSGBOX_AUTOCLOSE
	setvar VAR_0x8008, INGAME_TRADE_REMORAID
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox TARC_Island_Fisherman_Text_1, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq TARC_Island_Fisherman_15
TARC_Island_Fisherman_14:
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	compare VAR_0x8004, PARTY_NOTHING_CHOSEN
	goto_if_eq TARC_Island_Fisherman_18
TARC_Island_Fisherman_17:
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	compare VAR_RESULT, VAR_0x8009
	goto_if_ne TARC_Island_Fisherman_21
TARC_Island_Fisherman_20:
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox FortreeCity_House1_Text_MonYouTakeCare, MSGBOX_AUTOCLOSE
	setflag FLAG_REMORAID_TRADE_COMPLETED
	goto TARC_Island_Fisherman_1

TARC_Island_Fisherman_11:
	msgbox FortreeCity_House1_Text_MonYouTakeCare, MSGBOX_AUTOCLOSE
	goto TARC_Island_Fisherman_1

TARC_Island_Fisherman_15:
	goto FortreeCity_House1_EventScript_DeclineTrade
	goto TARC_Island_Fisherman_14

TARC_Island_Fisherman_18:
	goto FortreeCity_House1_EventScript_DeclineTrade
	goto TARC_Island_Fisherman_17

TARC_Island_Fisherman_21:
	goto FortreeCity_House1_EventScript_NotRequestedMon
	goto TARC_Island_Fisherman_20


TARC_Island_Chansey::
	lock
	faceplayer
	msgbox TARC_Island_Chansey_Text_0, MSGBOX_AUTOCLOSE
	call Common_EventScript_OutOfCenterPartyHeal
	incrementgamestat GAME_STAT_RESTED_AT_HOME
	msgbox TARC_Island_Chansey_Text_1, MSGBOX_AUTOCLOSE
	release
	return


TARC_Island_Corphish::
	lock
	faceplayer
	msgbox TARC_Island_Corphish_Text_0, MSGBOX_AUTOCLOSE
	release
	return


TARC_Island_ItemBall_Nugget::
	lock
	removeobject 12, MAP_TARC_ISLAND
	finditem ITEM_BIG_NUGGET, 1
	release
	return


TARC_Island_ItemBall_Balls::
	lock
	removeobject 12, MAP_TARC_ISLAND
	finditem ITEM_POKE_BALL, 1
	release
	return


TARC_Island_ItemBall_Dive::
	lock
	removeobject 2, MAP_TARC_ISLAND
	finditem ITEM_HM_DIVE
	release
	return


TARC_Island_ItemBall_Rock_Climb::
	lock
	removeobject 3, MAP_TARC_ISLAND
	finditem ITEM_TM100
	release
	return


TARC_Island_Celebi::
	lockall
	faceplayer
	goto_if_unset FLAG_TARC_TALKED_TO_CELEBI, TARC_Island_Celebi_2
TARC_Island_Celebi_1:
	msgbox TARC_Island_Celebi_Text_1, MSGBOX_AUTOCLOSE
	special ChooseMonForMoveRelearner
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, EndOfRelearnerScript
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, EndOfRelearnerScript
	goto_if_eq VAR_0x8005, 0, EndOfRelearnerScript
	special TeachMoveRelearnerMove
	waitstate
	releaseall
	return

TARC_Island_Celebi_2:
	setflag FLAG_TARC_TALKED_TO_CELEBI
	msgbox TARC_Island_Celebi_Text_0, MSGBOX_AUTOCLOSE
	goto TARC_Island_Celebi_1


EndOfRelearnerScript::
	releaseall
	return


TARC_Island_Zigzagoon::
	lockall
	faceplayer
	msgbox TARC_Island_Zigzagoon_Text_0, MSGBOX_AUTOCLOSE
	releaseall
	return


TARC_Island_Game_Master::
	lockall
	faceplayer
	msgbox TARC_Island_Game_Master_Text_0, MSGBOX_AUTOCLOSE
	releaseall
	return


TARC_Island_Maxie::
	lock
	faceplayer
	msgbox TARC_Island_Maxie_Text_0, MSGBOX_AUTOCLOSE
	msgbox TARC_Island_Maxie_Text_1, MSGBOX_AUTOCLOSE
	release
	return


TARC_Island_sign_Game_Start::
	lockall
	msgbox TARC_Island_sign_Game_Start_Text_0, MSGBOX_AUTOCLOSE
	releaseall
	return


TARC_Island_sign_Rock_Climb::
	lockall
	msgbox TARC_Island_sign_Rock_Climb_Text_0, MSGBOX_AUTOCLOSE
	releaseall
	return


TARC_Island_Rhydon::
	lock
	faceplayer
	msgbox TARC_Island_Rhydon_Text_0, MSGBOX_AUTOCLOSE
	waitmessage
	compare VAR_RHYDON_STATE, 0
	goto_if_eq TARC_Island_Rhydon_20
TARC_Island_Rhydon_18:
	compare VAR_RHYDON_STATE, 1
	goto_if_eq TARC_Island_Rhydon_17
TARC_Island_Rhydon_15:
	compare VAR_RHYDON_STATE, 2
	goto_if_eq TARC_Island_Rhydon_14
TARC_Island_Rhydon_12:
	compare VAR_RHYDON_STATE, 3
	goto_if_eq TARC_Island_Rhydon_11
TARC_Island_Rhydon_9:
	compare VAR_RHYDON_STATE, 4
	goto_if_eq TARC_Island_Rhydon_8
TARC_Island_Rhydon_7:
	setorcopyvar VAR_RHYDON_STATE, 0
TARC_Island_Rhydon_1:
	release
	return

TARC_Island_Rhydon_2:
	setorcopyvar VAR_RHYDON_STATE, 1
	goto TARC_Island_Rhydon_1

TARC_Island_Rhydon_3:
	setorcopyvar VAR_RHYDON_STATE, 2
	goto TARC_Island_Rhydon_1

TARC_Island_Rhydon_4:
	setorcopyvar VAR_RHYDON_STATE, 3
	goto TARC_Island_Rhydon_1

TARC_Island_Rhydon_5:
	setorcopyvar VAR_RHYDON_STATE, 4
	goto TARC_Island_Rhydon_1

TARC_Island_Rhydon_6:
	setorcopyvar VAR_RHYDON_STATE, 5
	applymovement 20, Move_exclmark
	waitmovement 0
	msgbox TARC_Island_Rhydon_Text_1, MSGBOX_AUTOCLOSE
	playmoncry SPECIES_RHYDON, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	applymovement 20, Move_Rhydon
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, Move_Camera
	waitmovement 0
	applymovement 21, Move_Rock_smash_break
	waitmovement 0
	removeobject 21
	setflag FLAG_TARC_BREAKABLE_ROCK
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 2
	setvar VAR_0x8006, 4
	setvar VAR_0x8007, 5
	special ShakeCamera
	waitstate
	delay 60
	applymovement OBJ_EVENT_ID_CAMERA, Move_CameraBack
	waitmovement 0
	special RemoveCameraObject
	setobjectxyperm 20, 26, 13
	goto TARC_Island_Rhydon_1

TARC_Island_Rhydon_8:
	compare VAR_FACING, DIR_NORTH
	goto_if_eq TARC_Island_Rhydon_6
	goto TARC_Island_Rhydon_7

TARC_Island_Rhydon_11:
	compare VAR_FACING, DIR_EAST
	goto_if_eq TARC_Island_Rhydon_5
	goto TARC_Island_Rhydon_9

TARC_Island_Rhydon_14:
	compare VAR_FACING, DIR_SOUTH
	goto_if_eq TARC_Island_Rhydon_4
	goto TARC_Island_Rhydon_12

TARC_Island_Rhydon_17:
	compare VAR_FACING, DIR_WEST
	goto_if_eq TARC_Island_Rhydon_3
	goto TARC_Island_Rhydon_15

TARC_Island_Rhydon_20:
	compare VAR_FACING, DIR_SOUTH
	goto_if_eq TARC_Island_Rhydon_2
	goto TARC_Island_Rhydon_18


TARC_Island_Battle_Seismitoad::
	lock
	faceplayer
	goto_if_unset FLAG_WON_SEISMITOAD, TARC_Island_Battle_Seismitoad_2
	msgbox TARC_Island_Battle_Seismitoad_Text_2, MSGBOX_AUTOCLOSE
TARC_Island_Battle_Seismitoad_1:
	release
	return

TARC_Island_Battle_Seismitoad_2:
	setwildbattle SPECIES_SEISMITOAD, 15
	waitse
	playmoncry SPECIES_SEISMITOAD, CRY_MODE_ENCOUNTER
	delay 20
	waitmoncry
	msgbox TARC_Island_Battle_Seismitoad_Text_0, MSGBOX_AUTOCLOSE
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	switch VAR_RESULT
	case B_OUTCOME_WON, TARC_Island_Battle_Seismitoad_6
	case B_OUTCOME_RAN, TARC_Island_Battle_Seismitoad_7
	clearflag FLAG_BATTLE_SEISMITOAD
	goto TARC_Island_Battle_Seismitoad_1

TARC_Island_Battle_Seismitoad_6:
	setflag FLAG_WON_SEISMITOAD
	removeobject 18
	msgbox TARC_Island_Battle_Seismitoad_Text_1, MSGBOX_AUTOCLOSE
	setflag FLAG_HIDE_SEISMITOAD
	goto TARC_Island_Battle_Seismitoad_1

TARC_Island_Battle_Seismitoad_7:
	clearflag FLAG_BATTLE_SEISMITOAD
	goto EventScript_FieldWhiteOut
	goto TARC_Island_Battle_Seismitoad_1


TARC_Island_Battle_Slowking::
	lock
	faceplayer
	goto_if_unset FLAG_WON_SLOWKING, TARC_Island_Battle_Slowking_2
	msgbox TARC_Island_Battle_Slowking_Text_1, MSGBOX_AUTOCLOSE
TARC_Island_Battle_Slowking_1:
	release
	return

TARC_Island_Battle_Slowking_2:
	setwildbattle SPECIES_SLOWKING, 12
	waitse
	playmoncry SPECIES_SLOWKING, CRY_MODE_ENCOUNTER
	delay 20
	waitmoncry
	msgbox TARC_Island_Battle_Slowking_Text_0, MSGBOX_AUTOCLOSE
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	switch VAR_RESULT
	case B_OUTCOME_WON, TARC_Island_Battle_Slowking_6
	case B_OUTCOME_RAN, TARC_Island_Battle_Slowking_7
	clearflag FLAG_BATTLE_SLOWKING
	goto TARC_Island_Battle_Slowking_1

TARC_Island_Battle_Slowking_6:
	setflag FLAG_WON_SLOWKING
	goto TARC_Island_Battle_Slowking_1

TARC_Island_Battle_Slowking_7:
	clearflag FLAG_BATTLE_SLOWKING
	goto EventScript_FieldWhiteOut
	goto TARC_Island_Battle_Slowking_1


TARC_Island_Battle_Wonderguard::
	trainerbattle_single TRAINER_CHASE, Route129_Text_ChaseIntro, Route129_Text_ChaseDefeat
	return


Move_Rhydon:
	walk_slow_right
	walk_slow_right
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	jump_2_down
	walk_slow_left
	walk_slow_left
	walk_slow_down
	walk_slow_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	lock_facing_direction
	jump_right
	unlock_facing_direction
	step_end

Move_Camera:
	walk_slow_right
	walk_slow_right
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_down
	walk_down
	walk_slow_left
	walk_slow_left
	walk_slow_down
	walk_slow_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_right
	step_end

Move_Rhydon_collision:
	step_end

Move_Rock_smash_break:
	rock_smash_break
	step_end

Move_CameraBack:
	walk_diag_northeast
	walk_diag_northeast
	walk_diag_northeast
	walk_diag_northeast
	walk_diag_northeast
	walk_diag_northeast
	walk_diag_northeast
	walk_diag_northeast
	walk_up
	step_end

TARC_Island_Fisherman_Text_0:
	.string "Ohh....what a tasty catch!$"

TARC_Island_Fisherman_Text_1:
	.string "Fantastic!\p"
	.string "I am afraid to ask, but do you mind\n"
	.string "sharing it for dinner?\p"
	.string "...\p"
	.string "Well... I mean...\p"
	.string "...trading it for my Porygon?$"

TARC_Island_Fisherman_Text_2:
	.string "How sad you still need it for now...$"

TARC_Island_Fisherman_Text_3:
	.string "Please think of me if you are getting\n"
	.string "luckier than I am.$"

TARC_Island_Fisherman_Text_4:
	.string "I am stranded here and try to catch\n"
	.string "some fish to survive.\p"
	.string "But these are shark infested waters!\p"
	.string "I don't get anything else to bite.\p"
	.string "Take this rod of mine.$"

TARC_Island_Fisherman_Text_5:
	.string "And please think of me if you are\n"
	.string "getting luckier than I am.$"

TARC_Island_Chansey_Text_0:
	.string "Chansey wants to take care of your\n"
	.string "Pokémon.$"

TARC_Island_Chansey_Text_1:
	.string "Your party has been healed.$"

TARC_Island_Corphish_Text_0:
	.string "Corph...$"

TARC_Island_Celebi_Text_0:
	.string "Dear traveller,\n"
	.string "I am the guardian of this island.\p"
	.string "I can travel through time to grant you\n"
	.string "access to moves your Pokémon might\l"
	.string "have forgotten a long time ago.$"

TARC_Island_Celebi_Text_1:
	.string "Please choose a Pokémon to teach a\n"
	.string "move to.$"

TARC_Island_Zigzagoon_Text_0:
	.string "Ziggie!!!$"

TARC_Island_Game_Master_Text_0:
	.string "I am the Game Master.$"

TARC_Island_Maxie_Text_0:
	.string "Hello traveller!\l"
	.string "Welcome to my island!$"

TARC_Island_Maxie_Text_1:
	.string "It's been a long time since I have seen\n"
	.string "a soul on this plateau.\p"
	.string "A famous trainer named Archie was the\n"
	.string "last one in ages.\p"
	.string "He visited this place riding a Kyogre\n"
	.string "and came here to practice his sword\l"
	.string "fighting skills.\p"
	.string "He said he was going to become as\n"
	.string "skillful as his big idol Link.\p"
	.string "What an extraordinary person he was...$"

TARC_Island_sign_Game_Start_Text_0:
	.string "Info sign for game start.$"

TARC_Island_sign_Rock_Climb_Text_0:
	.string "The rock below looks climbable. {DOWN_ARROW}$"

TARC_Island_Rhydon_Text_0:
	.string "RHYHORN!$"

TARC_Island_Rhydon_Text_1:
	.string "GRWAHH!$"

TARC_Island_Battle_Seismitoad_Text_0:
	.string "RIBBIT!$"

TARC_Island_Battle_Seismitoad_Text_1:
	.string "Seismitoad vanished in the depths of\n"
	.string "the pond.$"

TARC_Island_Battle_Seismitoad_Text_2:
	.string "Seismitoad is watching the pond.$"

TARC_Island_Battle_Slowking_Text_0:
	.string "Slowking looks furious being disturbed\n"
	.string "from sleeping!$"

TARC_Island_Battle_Slowking_Text_1:
	.string "...snore...$"
