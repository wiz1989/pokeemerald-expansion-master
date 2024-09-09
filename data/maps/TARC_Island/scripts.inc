TARC_Island_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, TARC_Island_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, TARC_Island_OnTransition
	.byte 0


TARC_Island_OnResume::
	setvar VAR_TEMP_2, 0
	setflag FLAG_HIDE_RHYDON
	setflag FLAG_HIDE_RHYDON_TRAINER
	return


TARC_Island_OnTransition::
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
	msgbox TARC_Island_Fisherman_Text_5, MSGBOX_AUTOCLOSE
	giveitem ITEM_OLD_ROD
	setflag FLAG_RECEIVED_OLD_ROD
	msgbox TARC_Island_Fisherman_Text_6, MSGBOX_AUTOCLOSE
TARC_Island_Fisherman_1:
	release
	end

TARC_Island_Fisherman_2:
	goto_if_set FLAG_TARC_REMORAID, TARC_Island_Fisherman_5
	msgbox TARC_Island_Fisherman_Text_4, MSGBOX_AUTOCLOSE
	goto TARC_Island_Fisherman_1

TARC_Island_Fisherman_5:
	checkpartymon SPECIES_MANTINE
	compare VAR_RESULT, TRUE
	goto_if_eq TARC_Island_Fisherman_8
	msgbox TARC_Island_Fisherman_Text_0, MSGBOX_AUTOCLOSE
	msgbox TARC_Island_Fisherman_Text_3, MSGBOX_AUTOCLOSE
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
	msgbox TARC_Island_Fisherman_Text_2, MSGBOX_AUTOCLOSE
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
	playmoncry SPECIES_CHANSEY, CRY_MODE_NORMAL
	msgbox TARC_Island_Chansey_Text_0, MSGBOX_AUTOCLOSE
	call Common_EventScript_OutOfCenterPartyHeal
	incrementgamestat GAME_STAT_RESTED_AT_HOME
	msgbox TARC_Island_Chansey_Text_1, MSGBOX_AUTOCLOSE
	release
	return


TARC_Island_Corphish::
	lock
	faceplayer
	playmoncry SPECIES_CORPHISH, CRY_MODE_NORMAL
	msgbox TARC_Island_Corphish_Text_0, MSGBOX_AUTOCLOSE
	release
	return


TARC_Island_Rhydon::
	lock
	faceplayer
	playmoncry SPECIES_RHYDON, CRY_MODE_ENCOUNTER
	msgbox TARC_Island_Rhydon_Text_0, MSGBOX_AUTOCLOSE
	release
	return


TARC_Island_Rhydon_Trainer::
	lock
	faceplayer
	msgbox TARC_Island_Rhydon_Trainer_Text_0, MSGBOX_AUTOCLOSE
	dynmultichoice 0, 0, TRUE, 6, 0, DYN_MULTICHOICE_CB_NONE, TARC_Island_Rhydon_Trainer_Text_1
	msgbox TARC_Island_Rhydon_Trainer_Text_2, MSGBOX_AUTOCLOSE
	msgbox TARC_Island_Rhydon_Trainer_Text_3
	applymovement 24, Move_walk_away_right
	applymovement 25, Move_walk_away_right
	waitmovement 0
	removeobject 24
	removeobject 25
	release
	return


TARC_Island_Azurill::
	lock
	faceplayer
	playmoncry SPECIES_AZURILL, CRY_MODE_NORMAL
	msgbox TARC_Island_Azurill_Text_0, MSGBOX_AUTOCLOSE
	release
	return


TARC_Island_Shark::
	lock
	playmoncry SPECIES_SHARPEDO, CRY_MODE_ENCOUNTER
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
	lock
	faceplayer
	playmoncry SPECIES_CELEBI, CRY_MODE_NORMAL
	goto_if_set FLAG_WON_SEISMITOAD, TARC_Island_Celebi_2
	goto_if_unset FLAG_TARC_TALKED_TO_CELEBI, TARC_Island_Celebi_6
TARC_Island_Celebi_5:
	msgbox TARC_Island_Celebi_Text_3, MSGBOX_AUTOCLOSE
	special ChooseMonForMoveRelearner
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, EndOfRelearnerScript
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, EndOfRelearnerScript
	goto_if_eq VAR_0x8005, 0, EndOfRelearnerScript
	special TeachMoveRelearnerMove
	waitstate
TARC_Island_Celebi_1:
	release
	return

TARC_Island_Celebi_2:
	msgbox TARC_Island_Celebi_Text_0, MSGBOX_AUTOCLOSE
	dofieldeffectsparkle 13, 3, 0
	waitfieldeffect FLDEFF_SPARKLE
	delay 10
	dofieldeffectsparkle 15, 3, 0
	waitfieldeffect FLDEFF_SPARKLE
	delay 10
	dofieldeffectsparkle 14, 3, 0
	waitfieldeffect FLDEFF_SPARKLE
	delay 10
	dofieldeffect FLDEFF_RAYQUAZA_SPOTLIGHT
	delay 400
	removeobject 9
	delay 60
	applymovement OBJ_EVENT_ID_PLAYER, Move_faceright
	waitmovement 0
	delay 60
	applymovement OBJ_EVENT_ID_PLAYER, Move_faceleft
	waitmovement 0
	delay 60
	applymovement OBJ_EVENT_ID_PLAYER, Move_facedown
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Move_exclmark
	waitmovement 0
	msgbox TARC_Island_Celebi_Text_1, MSGBOX_AUTOCLOSE
	goto TARC_Island_Celebi_1

TARC_Island_Celebi_6:
	setflag FLAG_TARC_TALKED_TO_CELEBI
	msgbox TARC_Island_Celebi_Text_2, MSGBOX_AUTOCLOSE
	goto TARC_Island_Celebi_5


EndOfRelearnerScript::
	releaseall
	return


TARC_Island_Zigzagoon::
	lock
	faceplayer
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox TARC_Island_Zigzagoon_Text_0, MSGBOX_AUTOCLOSE
	waitmessage
	setorcopyvar VAR_TARC_COLLECTOR_COUNT, 0
	clearflag FLAG_COLLECTOR_DONT_GIVE_ITEM
	goto_if_set FLAG_TARC_item_Pokeballs, TARC_Island_Zigzagoon_3
TARC_Island_Zigzagoon_1:
	clearflag FLAG_COLLECTOR_DONT_GIVE_ITEM
	goto_if_set FLAG_TARC_item_Big_Nugget, TARC_Island_Zigzagoon_8
TARC_Island_Zigzagoon_6:
	clearflag FLAG_COLLECTOR_DONT_GIVE_ITEM
	goto_if_set FLAG_TARC_item_Pokeballs2, TARC_Island_Zigzagoon_16
TARC_Island_Zigzagoon_14:
	clearflag FLAG_COLLECTOR_DONT_GIVE_ITEM
	goto_if_set FLAG_TARC_ITEM_X, TARC_Island_Zigzagoon_27
TARC_Island_Zigzagoon_25:
	clearflag FLAG_COLLECTOR_DONT_GIVE_ITEM
	checkitem ITEM_LIFE_ORB
	compare VAR_RESULT, TRUE
	goto_if_eq TARC_Island_Zigzagoon_40
TARC_Island_Zigzagoon_39:
	checkpartyitem ITEM_LIFE_ORB
	compare VAR_RESULT, 6
	goto_if_lt TARC_Island_Zigzagoon_52
TARC_Island_Zigzagoon_51:
	goto_if_set FLAG_COLLECTOR_DONT_GIVE_ITEM, TARC_Island_Zigzagoon_61
	msgbox TARC_Island_Zigzagoon_Text_5, MSGBOX_AUTOCLOSE
	waitmessage
	msgbox TARC_Island_Zigzagoon_Text_2, MSGBOX_AUTOCLOSE
	waitmessage
	giveitem ITEM_LIFE_ORB
TARC_Island_Zigzagoon_60:
	clearflag FLAG_COLLECTOR_DONT_GIVE_ITEM
	goto_if_set FLAG_HIDE_GYARADOSITE, TARC_Island_Zigzagoon_68
TARC_Island_Zigzagoon_67:
	clearflag FLAG_COLLECTOR_DONT_GIVE_ITEM
	goto_if_set FLAG_TARC_item_Rock_Climb, TARC_Island_Zigzagoon_76
TARC_Island_Zigzagoon_74:
	release
	return

TARC_Island_Zigzagoon_2:
	checkitem ITEM_POKE_BALL
	compare VAR_RESULT, TRUE
	goto_if_eq TARC_Island_Zigzagoon_12
TARC_Island_Zigzagoon_11:
	checkpartyitem ITEM_POKE_BALL
	compare VAR_RESULT, 6
	goto_if_lt TARC_Island_Zigzagoon_23
TARC_Island_Zigzagoon_22:
	goto_if_set FLAG_COLLECTOR_DONT_GIVE_ITEM, TARC_Island_Zigzagoon_36
	msgbox TARC_Island_Zigzagoon_Text_1, MSGBOX_AUTOCLOSE
	waitmessage
	msgbox TARC_Island_Zigzagoon_Text_2, MSGBOX_AUTOCLOSE
	waitmessage
	giveitem ITEM_POKE_BALL
	goto TARC_Island_Zigzagoon_1

TARC_Island_Zigzagoon_3:
	goto_if_unset FLAG_TARC_REMORAID, TARC_Island_Zigzagoon_2
	goto TARC_Island_Zigzagoon_1

TARC_Island_Zigzagoon_7:
	checkitem ITEM_BIG_NUGGET
	compare VAR_RESULT, TRUE
	goto_if_eq TARC_Island_Zigzagoon_20
TARC_Island_Zigzagoon_19:
	checkpartyitem ITEM_BIG_NUGGET
	compare VAR_RESULT, 6
	goto_if_lt TARC_Island_Zigzagoon_34
TARC_Island_Zigzagoon_33:
	goto_if_set FLAG_COLLECTOR_DONT_GIVE_ITEM, TARC_Island_Zigzagoon_48
	msgbox TARC_Island_Zigzagoon_Text_3, MSGBOX_AUTOCLOSE
	waitmessage
	msgbox TARC_Island_Zigzagoon_Text_2, MSGBOX_AUTOCLOSE
	waitmessage
	giveitem ITEM_BIG_NUGGET
	goto TARC_Island_Zigzagoon_6

TARC_Island_Zigzagoon_8:
	goto_if_unset FLAG_WON_SLOWKING, TARC_Island_Zigzagoon_7
	goto TARC_Island_Zigzagoon_6

TARC_Island_Zigzagoon_12:
	setflag FLAG_COLLECTOR_DONT_GIVE_ITEM
	goto TARC_Island_Zigzagoon_11

TARC_Island_Zigzagoon_15:
	checkitem ITEM_POKE_BALL
	compare VAR_RESULT, TRUE
	goto_if_eq TARC_Island_Zigzagoon_31
TARC_Island_Zigzagoon_30:
	checkpartyitem ITEM_POKE_BALL
	compare VAR_RESULT, 6
	goto_if_lt TARC_Island_Zigzagoon_46
TARC_Island_Zigzagoon_45:
	goto_if_set FLAG_COLLECTOR_DONT_GIVE_ITEM, TARC_Island_Zigzagoon_57
	msgbox TARC_Island_Zigzagoon_Text_1, MSGBOX_AUTOCLOSE
	waitmessage
	msgbox TARC_Island_Zigzagoon_Text_2, MSGBOX_AUTOCLOSE
	waitmessage
	giveitem ITEM_POKE_BALL
	goto TARC_Island_Zigzagoon_14

TARC_Island_Zigzagoon_16:
	goto_if_unset FLAG_TARC_FARFETCHD, TARC_Island_Zigzagoon_15
	goto TARC_Island_Zigzagoon_14

TARC_Island_Zigzagoon_20:
	setflag FLAG_COLLECTOR_DONT_GIVE_ITEM
	goto TARC_Island_Zigzagoon_19

TARC_Island_Zigzagoon_23:
	setflag FLAG_COLLECTOR_DONT_GIVE_ITEM
	goto TARC_Island_Zigzagoon_22

TARC_Island_Zigzagoon_26:
	checkitem ITEM_ABILITY_CAPSULE
	compare VAR_RESULT, TRUE
	goto_if_eq TARC_Island_Zigzagoon_43
TARC_Island_Zigzagoon_42:
	checkpartyitem ITEM_ABILITY_CAPSULE
	compare VAR_RESULT, 6
	goto_if_lt TARC_Island_Zigzagoon_55
TARC_Island_Zigzagoon_54:
	goto_if_set FLAG_COLLECTOR_DONT_GIVE_ITEM, TARC_Island_Zigzagoon_64
	checkpartyability 36
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq TARC_Island_Zigzagoon_71
	goto TARC_Island_Zigzagoon_25

TARC_Island_Zigzagoon_27:
	goto_if_unset FLAG_HIDE_WILSON, TARC_Island_Zigzagoon_26
	goto TARC_Island_Zigzagoon_25

TARC_Island_Zigzagoon_31:
	setflag FLAG_COLLECTOR_DONT_GIVE_ITEM
	goto TARC_Island_Zigzagoon_30

TARC_Island_Zigzagoon_34:
	setflag FLAG_COLLECTOR_DONT_GIVE_ITEM
	goto TARC_Island_Zigzagoon_33

TARC_Island_Zigzagoon_36:
	goto TARC_Island_Zigzagoon_1

TARC_Island_Zigzagoon_40:
	setflag FLAG_COLLECTOR_DONT_GIVE_ITEM
	goto TARC_Island_Zigzagoon_39

TARC_Island_Zigzagoon_43:
	setflag FLAG_COLLECTOR_DONT_GIVE_ITEM
	goto TARC_Island_Zigzagoon_42

TARC_Island_Zigzagoon_46:
	setflag FLAG_COLLECTOR_DONT_GIVE_ITEM
	goto TARC_Island_Zigzagoon_45

TARC_Island_Zigzagoon_48:
	goto TARC_Island_Zigzagoon_6

TARC_Island_Zigzagoon_52:
	setflag FLAG_COLLECTOR_DONT_GIVE_ITEM
	goto TARC_Island_Zigzagoon_51

TARC_Island_Zigzagoon_55:
	setflag FLAG_COLLECTOR_DONT_GIVE_ITEM
	goto TARC_Island_Zigzagoon_54

TARC_Island_Zigzagoon_57:
	goto TARC_Island_Zigzagoon_14

TARC_Island_Zigzagoon_61:
	goto TARC_Island_Zigzagoon_60

TARC_Island_Zigzagoon_64:
	goto TARC_Island_Zigzagoon_25

TARC_Island_Zigzagoon_68:
	checkitem ITEM_GYARADOSITE
	compare VAR_RESULT, TRUE
	goto_if_eq TARC_Island_Zigzagoon_80
TARC_Island_Zigzagoon_79:
	checkpartyitem ITEM_GYARADOSITE
	compare VAR_RESULT, 6
	goto_if_lt TARC_Island_Zigzagoon_86
TARC_Island_Zigzagoon_85:
	goto_if_set FLAG_COLLECTOR_DONT_GIVE_ITEM, TARC_Island_Zigzagoon_91
	msgbox TARC_Island_Zigzagoon_Text_6, MSGBOX_AUTOCLOSE
	waitmessage
	msgbox TARC_Island_Zigzagoon_Text_2, MSGBOX_AUTOCLOSE
	waitmessage
	giveitem ITEM_GYARADOSITE
	goto TARC_Island_Zigzagoon_67

TARC_Island_Zigzagoon_70:
	msgbox TARC_Island_Zigzagoon_Text_4, MSGBOX_AUTOCLOSE
	waitmessage
	msgbox TARC_Island_Zigzagoon_Text_2, MSGBOX_AUTOCLOSE
	waitmessage
	giveitem ITEM_ABILITY_CAPSULE
	goto TARC_Island_Zigzagoon_25

TARC_Island_Zigzagoon_71:
	goto_if_unset FLAG_AQUA_CHANGED_PARTY, TARC_Island_Zigzagoon_70
	goto TARC_Island_Zigzagoon_25

TARC_Island_Zigzagoon_75:
	checkitem ITEM_TM100
	compare VAR_RESULT, TRUE
	goto_if_eq TARC_Island_Zigzagoon_83
TARC_Island_Zigzagoon_82:
	checkpartyitem ITEM_TM100
	compare VAR_RESULT, 6
	goto_if_lt TARC_Island_Zigzagoon_89
TARC_Island_Zigzagoon_88:
	checkpartymove MOVE_ROCK_CLIMB
	compare VAR_RESULT, 6
	goto_if_lt TARC_Island_Zigzagoon_95
TARC_Island_Zigzagoon_94:
	goto_if_set FLAG_COLLECTOR_DONT_GIVE_ITEM, TARC_Island_Zigzagoon_97
	msgbox TARC_Island_Zigzagoon_Text_7, MSGBOX_AUTOCLOSE
	waitmessage
	msgbox TARC_Island_Zigzagoon_Text_2, MSGBOX_AUTOCLOSE
	waitmessage
	giveitem ITEM_TM100
	goto TARC_Island_Zigzagoon_74

TARC_Island_Zigzagoon_76:
	goto_if_unset FLAG_AQUA_CHANGED_PARTY, TARC_Island_Zigzagoon_75
	goto TARC_Island_Zigzagoon_74

TARC_Island_Zigzagoon_80:
	setflag FLAG_COLLECTOR_DONT_GIVE_ITEM
	goto TARC_Island_Zigzagoon_79

TARC_Island_Zigzagoon_83:
	setflag FLAG_COLLECTOR_DONT_GIVE_ITEM
	goto TARC_Island_Zigzagoon_82

TARC_Island_Zigzagoon_86:
	setflag FLAG_COLLECTOR_DONT_GIVE_ITEM
	goto TARC_Island_Zigzagoon_85

TARC_Island_Zigzagoon_89:
	setflag FLAG_COLLECTOR_DONT_GIVE_ITEM
	goto TARC_Island_Zigzagoon_88

TARC_Island_Zigzagoon_91:
	goto TARC_Island_Zigzagoon_67

TARC_Island_Zigzagoon_95:
	setflag FLAG_COLLECTOR_DONT_GIVE_ITEM
	goto TARC_Island_Zigzagoon_94

TARC_Island_Zigzagoon_97:
	goto TARC_Island_Zigzagoon_74


TARC_Island_Game_Master::
	lock
	clearflag FLAG_TARC_ADDTIME
	clearflag FLAG_TARC_GIVE_NO_ADVICE
	faceplayer
	msgbox TARC_Island_Game_Master_Text_0
	waitmessage
	msgbox TARC_Island_Game_Master_Text_1, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq TARC_Island_Game_Master_2
	msgbox TARC_Island_Game_Master_Text_16, MSGBOX_AUTOCLOSE
	waitmessage
	release
	end

TARC_Island_Game_Master_1:
	waitmessage
	goto_if_set FLAG_TARC_ADDTIME, TARC_Island_Game_Master_6
	goto_if_set FLAG_TARC_GIVE_NO_ADVICE, TARC_Island_Game_Master_12
	msgbox TARC_Island_Game_Master_Text_18
	waitmessage
TARC_Island_Game_Master_5:
	release
	return

TARC_Island_Game_Master_2:
	setflag FLAG_TARC_GIVE_NO_ADVICE
	goto_if_unset FLAG_WON_SLOWKING, TARC_Island_Game_Master_10
TARC_Island_Game_Master_9:
	goto_if_set FLAG_WON_SLOWKING, TARC_Island_Game_Master_17
TARC_Island_Game_Master_15:
	goto_if_set FLAG_WON_SEISMITOAD, TARC_Island_Game_Master_25
TARC_Island_Game_Master_23:
	goto_if_set FLAG_CAVE_SOLVED2, TARC_Island_Game_Master_37
TARC_Island_Game_Master_35:
	goto_if_set FLAG_TARC_ITEM_X, TARC_Island_Game_Master_56
TARC_Island_Game_Master_54:
	checktrainerflag TRAINER_CHASE
	goto_if 1, TARC_Island_Game_Master_70
TARC_Island_Game_Master_68:
	checktrainerflag TRAINER_CHASE
	goto_if 1, TARC_Island_Game_Master_85
TARC_Island_Game_Master_82:
	goto_if_set FLAG_USED_DIVE, TARC_Island_Game_Master_93
	goto TARC_Island_Game_Master_1

TARC_Island_Game_Master_6:
	setorcopyvar VAR_0x8004, 20
	special PlayTimeAddMin
	goto TARC_Island_Game_Master_5

TARC_Island_Game_Master_10:
	goto_if_unset FLAG_HINT01, TARC_Island_Game_Master_21
TARC_Island_Game_Master_20:
	msgbox TARC_Island_Game_Master_Text_2, MSGBOX_AUTOCLOSE
	clearflag FLAG_TARC_GIVE_NO_ADVICE
	goto TARC_Island_Game_Master_9

TARC_Island_Game_Master_12:
	msgbox TARC_Island_Game_Master_Text_17
	waitmessage
	goto TARC_Island_Game_Master_5

TARC_Island_Game_Master_16:
	checkpartymon SPECIES_MANTINE
	goto_if_unset FLAG_TARC_item_Pokeballs, TARC_Island_Game_Master_28
	goto_if_unset FLAG_TARC_REMORAID, TARC_Island_Game_Master_29
	compare VAR_RESULT, FALSE
	goto_if_eq TARC_Island_Game_Master_30
	checkpartymove MOVE_BULLET_SEED
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq TARC_Island_Game_Master_52
	goto TARC_Island_Game_Master_15

TARC_Island_Game_Master_17:
	goto_if_unset FLAG_WON_SEISMITOAD, TARC_Island_Game_Master_16
	goto TARC_Island_Game_Master_15

TARC_Island_Game_Master_21:
	setflag FLAG_HINT01
	setflag FLAG_TARC_ADDTIME
	goto TARC_Island_Game_Master_20

TARC_Island_Game_Master_24:
	goto_if_unset FLAG_HINT06, TARC_Island_Game_Master_41
TARC_Island_Game_Master_40:
	msgbox TARC_Island_Game_Master_Text_7, MSGBOX_AUTOCLOSE
	clearflag FLAG_TARC_GIVE_NO_ADVICE
	goto TARC_Island_Game_Master_23

TARC_Island_Game_Master_25:
	goto_if_unset FLAG_CAVE_SOLVED2, TARC_Island_Game_Master_24
	goto TARC_Island_Game_Master_23

TARC_Island_Game_Master_28:
	goto_if_unset FLAG_HINT02, TARC_Island_Game_Master_44
TARC_Island_Game_Master_43:
	msgbox TARC_Island_Game_Master_Text_3, MSGBOX_AUTOCLOSE
	clearflag FLAG_TARC_GIVE_NO_ADVICE
	goto TARC_Island_Game_Master_15

TARC_Island_Game_Master_29:
	goto_if_unset FLAG_HINT03, TARC_Island_Game_Master_47
TARC_Island_Game_Master_46:
	msgbox TARC_Island_Game_Master_Text_4, MSGBOX_AUTOCLOSE
	clearflag FLAG_TARC_GIVE_NO_ADVICE
	goto TARC_Island_Game_Master_15

TARC_Island_Game_Master_30:
	goto_if_unset FLAG_HINT04, TARC_Island_Game_Master_50
TARC_Island_Game_Master_49:
	msgbox TARC_Island_Game_Master_Text_5, MSGBOX_AUTOCLOSE
	clearflag FLAG_TARC_GIVE_NO_ADVICE
	goto TARC_Island_Game_Master_15

TARC_Island_Game_Master_36:
	goto_if_unset FLAG_TARC_item_Pokeballs2, TARC_Island_Game_Master_59
	goto_if_set FLAG_TARC_FARFETCHD, TARC_Island_Game_Master_61
	goto TARC_Island_Game_Master_35

TARC_Island_Game_Master_37:
	goto_if_unset FLAG_TARC_ITEM_X, TARC_Island_Game_Master_36
	goto TARC_Island_Game_Master_35

TARC_Island_Game_Master_41:
	setflag FLAG_HINT06
	setflag FLAG_TARC_ADDTIME
	goto TARC_Island_Game_Master_40

TARC_Island_Game_Master_44:
	setflag FLAG_HINT02
	setflag FLAG_TARC_ADDTIME
	goto TARC_Island_Game_Master_43

TARC_Island_Game_Master_47:
	setflag FLAG_HINT03
	setflag FLAG_TARC_ADDTIME
	goto TARC_Island_Game_Master_46

TARC_Island_Game_Master_50:
	setflag FLAG_HINT04
	setflag FLAG_TARC_ADDTIME
	goto TARC_Island_Game_Master_49

TARC_Island_Game_Master_52:
	goto_if_unset FLAG_HINT05, TARC_Island_Game_Master_66
TARC_Island_Game_Master_65:
	msgbox TARC_Island_Game_Master_Text_6, MSGBOX_AUTOCLOSE
	clearflag FLAG_TARC_GIVE_NO_ADVICE
	goto TARC_Island_Game_Master_15

TARC_Island_Game_Master_55:
	goto_if_unset FLAG_HINT09, TARC_Island_Game_Master_74
TARC_Island_Game_Master_73:
	msgbox TARC_Island_Game_Master_Text_10, MSGBOX_AUTOCLOSE
	clearflag FLAG_TARC_GIVE_NO_ADVICE
	goto TARC_Island_Game_Master_54

TARC_Island_Game_Master_56:
	checktrainerflag TRAINER_CHASE
	goto_if 0, TARC_Island_Game_Master_55
	goto TARC_Island_Game_Master_54

TARC_Island_Game_Master_59:
	goto_if_unset FLAG_HINT07, TARC_Island_Game_Master_77
TARC_Island_Game_Master_76:
	msgbox TARC_Island_Game_Master_Text_8, MSGBOX_AUTOCLOSE
	clearflag FLAG_TARC_GIVE_NO_ADVICE
	goto TARC_Island_Game_Master_35

TARC_Island_Game_Master_60:
	goto_if_unset FLAG_HINT08, TARC_Island_Game_Master_80
TARC_Island_Game_Master_79:
	msgbox TARC_Island_Game_Master_Text_9, MSGBOX_AUTOCLOSE
	clearflag FLAG_TARC_GIVE_NO_ADVICE
	goto TARC_Island_Game_Master_35

TARC_Island_Game_Master_61:
	goto_if_unset FLAG_TARC_CUT_X, TARC_Island_Game_Master_60
	goto TARC_Island_Game_Master_35

TARC_Island_Game_Master_66:
	setflag FLAG_HINT05
	setflag FLAG_TARC_ADDTIME
	goto TARC_Island_Game_Master_65

TARC_Island_Game_Master_69:
	goto_if_unset FLAG_HINT10, TARC_Island_Game_Master_90
TARC_Island_Game_Master_89:
	msgbox TARC_Island_Game_Master_Text_11, MSGBOX_AUTOCLOSE
	clearflag FLAG_TARC_GIVE_NO_ADVICE
	goto TARC_Island_Game_Master_68

TARC_Island_Game_Master_70:
	goto_if_unset FLAG_TARC_BREAKABLE_ROCK, TARC_Island_Game_Master_69
	goto TARC_Island_Game_Master_68

TARC_Island_Game_Master_74:
	setflag FLAG_HINT09
	setflag FLAG_TARC_ADDTIME
	goto TARC_Island_Game_Master_73

TARC_Island_Game_Master_77:
	setflag FLAG_HINT07
	setflag FLAG_TARC_ADDTIME
	goto TARC_Island_Game_Master_76

TARC_Island_Game_Master_80:
	setflag FLAG_HINT08
	setflag FLAG_TARC_ADDTIME
	goto TARC_Island_Game_Master_79

TARC_Island_Game_Master_83:
	goto_if_unset FLAG_HINT11, TARC_Island_Game_Master_97
TARC_Island_Game_Master_96:
	msgbox TARC_Island_Game_Master_Text_12, MSGBOX_AUTOCLOSE
	clearflag FLAG_TARC_GIVE_NO_ADVICE
	goto TARC_Island_Game_Master_82

TARC_Island_Game_Master_84:
	goto_if_unset FLAG_USED_DIVE, TARC_Island_Game_Master_83
	goto TARC_Island_Game_Master_82

TARC_Island_Game_Master_85:
	goto_if_set FLAG_TARC_BREAKABLE_ROCK, TARC_Island_Game_Master_84
	goto TARC_Island_Game_Master_82

TARC_Island_Game_Master_90:
	setflag FLAG_HINT10
	setflag FLAG_TARC_ADDTIME
	goto TARC_Island_Game_Master_89

TARC_Island_Game_Master_92:
	compare VAR_TARC_UNDERWATER_CAVE, 0
	goto_if_eq TARC_Island_Game_Master_99
	goto_if_set FLAG_HIDE_GYARADOSITE, TARC_Island_Game_Master_102
TARC_Island_Game_Master_101:
	goto_if_unset FLAG_HINT14, TARC_Island_Game_Master_113
TARC_Island_Game_Master_112:
	msgbox TARC_Island_Game_Master_Text_15, MSGBOX_AUTOCLOSE
	clearflag FLAG_TARC_GIVE_NO_ADVICE
	goto TARC_Island_Game_Master_1

TARC_Island_Game_Master_93:
	checktrainerflag TRAINER_ARCHIE
	goto_if 0, TARC_Island_Game_Master_92
	goto TARC_Island_Game_Master_1

TARC_Island_Game_Master_97:
	setflag FLAG_HINT11
	setflag FLAG_TARC_ADDTIME
	goto TARC_Island_Game_Master_96

TARC_Island_Game_Master_99:
	goto_if_unset FLAG_HINT12, TARC_Island_Game_Master_107
TARC_Island_Game_Master_106:
	msgbox TARC_Island_Game_Master_Text_13, MSGBOX_AUTOCLOSE
	clearflag FLAG_TARC_GIVE_NO_ADVICE
	goto TARC_Island_Game_Master_1

TARC_Island_Game_Master_100:
	goto_if_unset FLAG_HINT13, TARC_Island_Game_Master_110
TARC_Island_Game_Master_109:
	msgbox TARC_Island_Game_Master_Text_14, MSGBOX_AUTOCLOSE
	clearflag FLAG_TARC_GIVE_NO_ADVICE
	goto TARC_Island_Game_Master_1

TARC_Island_Game_Master_102:
	goto_if_unset FLAG_HIDE_MEGA_RING, TARC_Island_Game_Master_100
	goto TARC_Island_Game_Master_101

TARC_Island_Game_Master_107:
	setflag FLAG_HINT12
	setflag FLAG_TARC_ADDTIME
	goto TARC_Island_Game_Master_106

TARC_Island_Game_Master_110:
	setflag FLAG_HINT13
	setflag FLAG_TARC_ADDTIME
	goto TARC_Island_Game_Master_109

TARC_Island_Game_Master_113:
	setflag FLAG_HINT14
	setflag FLAG_TARC_ADDTIME
	goto TARC_Island_Game_Master_112


TARC_Island_Maxie::
	lock
	faceplayer
	goto_if_unset FLAG_TARC_CUT_X, TARC_Island_Maxie_2
	goto_if_unset FLAG_TARC_ITEM_X, TARC_Island_Maxie_5
	msgbox TARC_Island_Maxie_Text_3, MSGBOX_AUTOCLOSE
TARC_Island_Maxie_1:
	release
	return

TARC_Island_Maxie_2:
	msgbox TARC_Island_Maxie_Text_0, MSGBOX_AUTOCLOSE
	msgbox TARC_Island_Maxie_Text_1, MSGBOX_AUTOCLOSE
	goto TARC_Island_Maxie_1

TARC_Island_Maxie_5:
	msgbox TARC_Island_Maxie_Text_2, MSGBOX_AUTOCLOSE
	goto TARC_Island_Maxie_1


TARC_Island_sign_Game_Start::
	lock
	msgbox TARC_Island_sign_Game_Start_Text_0
	waitmessage
	release
	return


TARC_Island_sign_Rock_Climb::
	lockall
	msgbox TARC_Island_sign_Rock_Climb_Text_0, MSGBOX_AUTOCLOSE
	releaseall
	return


TARC_Island_Rhyhorn::
	lock
	faceplayer
	msgbox TARC_Island_Rhyhorn_Text_0, MSGBOX_AUTOCLOSE
	waitmessage
	compare VAR_RHYDON_STATE, 0
	goto_if_eq TARC_Island_Rhyhorn_22
TARC_Island_Rhyhorn_20:
	compare VAR_RHYDON_STATE, 1
	goto_if_eq TARC_Island_Rhyhorn_19
TARC_Island_Rhyhorn_17:
	compare VAR_RHYDON_STATE, 2
	goto_if_eq TARC_Island_Rhyhorn_16
TARC_Island_Rhyhorn_14:
	compare VAR_RHYDON_STATE, 3
	goto_if_eq TARC_Island_Rhyhorn_13
TARC_Island_Rhyhorn_12:
	compare VAR_FACING, DIR_SOUTH
	goto_if_eq TARC_Island_Rhyhorn_6
	compare VAR_RHYDON_STATE, 4
	goto_if_eq TARC_Island_Rhyhorn_9
TARC_Island_Rhyhorn_8:
	setorcopyvar VAR_RHYDON_STATE, 0
TARC_Island_Rhyhorn_1:
	release
	return

TARC_Island_Rhyhorn_2:
	setorcopyvar VAR_RHYDON_STATE, 1
	goto TARC_Island_Rhyhorn_1

TARC_Island_Rhyhorn_3:
	setorcopyvar VAR_RHYDON_STATE, 2
	goto TARC_Island_Rhyhorn_1

TARC_Island_Rhyhorn_4:
	setorcopyvar VAR_RHYDON_STATE, 3
	goto TARC_Island_Rhyhorn_1

TARC_Island_Rhyhorn_5:
	setorcopyvar VAR_RHYDON_STATE, 4
	goto TARC_Island_Rhyhorn_1

TARC_Island_Rhyhorn_6:
	setorcopyvar VAR_RHYDON_STATE, 1
	goto TARC_Island_Rhyhorn_1

TARC_Island_Rhyhorn_7:
	setorcopyvar VAR_RHYDON_STATE, 5
	applymovement 20, Move_exclmark
	waitmovement 0
	msgbox TARC_Island_Rhyhorn_Text_1, MSGBOX_AUTOCLOSE
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
	goto TARC_Island_Rhyhorn_1

TARC_Island_Rhyhorn_9:
	compare VAR_FACING, DIR_NORTH
	goto_if_eq TARC_Island_Rhyhorn_7
	goto TARC_Island_Rhyhorn_8

TARC_Island_Rhyhorn_13:
	compare VAR_FACING, DIR_EAST
	goto_if_eq TARC_Island_Rhyhorn_5
	goto TARC_Island_Rhyhorn_12

TARC_Island_Rhyhorn_16:
	compare VAR_FACING, DIR_SOUTH
	goto_if_eq TARC_Island_Rhyhorn_4
	goto TARC_Island_Rhyhorn_14

TARC_Island_Rhyhorn_19:
	compare VAR_FACING, DIR_WEST
	goto_if_eq TARC_Island_Rhyhorn_3
	goto TARC_Island_Rhyhorn_17

TARC_Island_Rhyhorn_22:
	compare VAR_FACING, DIR_SOUTH
	goto_if_eq TARC_Island_Rhyhorn_2
	goto TARC_Island_Rhyhorn_20


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
	goto EventScript_FieldWhiteOutAfterRunning
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
	goto EventScript_FieldWhiteOutAfterRunning
	goto TARC_Island_Battle_Slowking_1


TARC_Island_Battle_Wonderguard::
	trainerbattle_single TRAINER_CHASE, Route129_Text_ChaseIntro, Route129_Text_ChaseDefeat
	lock
	msgbox TARC_Island_Battle_Wonderguard_Text_0, MSGBOX_AUTOCLOSE
	release
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

Move_walk_away_right:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
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
	.string "This Pokémon is really weird.\p"
	.string "Someone did install a very strange move\n"
	.string "on its hard drive.$"

TARC_Island_Fisherman_Text_3:
	.string "How sad you still need it for now...$"

TARC_Island_Fisherman_Text_4:
	.string "Please think of me if you are getting\n"
	.string "luckier than I am.$"

TARC_Island_Fisherman_Text_5:
	.string "I am stranded here and trying to catch\n"
	.string "some fish to survive.\p"
	.string "But these are shark infested waters!\p"
	.string "I can't get anything else to bite.\p"
	.string "Here, take this rod of mine.$"

TARC_Island_Fisherman_Text_6:
	.string "And please think of me if you get\n"
	.string "luckier than I am.$"

TARC_Island_Chansey_Text_0:
	.string "Chansey wants to take care of your\n"
	.string "Pokémon.$"

TARC_Island_Chansey_Text_1:
	.string "Your party has been healed.$"

TARC_Island_Corphish_Text_0:
	.string "Corph...$"

TARC_Island_Rhydon_Text_0:
	.string "RHYDON!!!$"

TARC_Island_Rhydon_Trainer_Text_0:
	.string "Hello {PLAYER},\p"
	.string "have you seen that stupid Rhydon next\n"
	.string "to me?$"

TARC_Island_Rhydon_Trainer_Text_1:
	.string "Rhydon?$"

TARC_Island_Rhydon_Trainer_Text_2:
	.string "RHYDON DEEZ NUTS!$"

TARC_Island_Rhydon_Trainer_Text_3:
	.string "HAHAHAHA!$"

TARC_Island_Azurill_Text_0:
	.string "Rill...$"

TARC_Island_Celebi_Text_0:
	.string "Dear traveler,\n"
	.string "my time in this place is up.\p"
	.string "My path is leading me to a far future,\n"
	.string "many years from now.\p"
	.string "Farewell!$"

TARC_Island_Celebi_Text_1:
	.string "Celebi vanished in a beam of light.$"

TARC_Island_Celebi_Text_2:
	.string "Dear traveler,\n"
	.string "I am the guardian of this island.\p"
	.string "I can travel through time to grant you\n"
	.string "access to moves your Pokémon might\l"
	.string "have forgotten a long time ago.$"

TARC_Island_Celebi_Text_3:
	.string "Please choose a Pokémon to teach a\n"
	.string "move to.$"

TARC_Island_Zigzagoon_Text_0:
	.string "Zigzagoon is running around searching\n"
	.string "for items!\p"
	.string "It will help you out in case you lost\n"
	.string "crucial items after obtaining them in\l"
	.string "the first place.$"

TARC_Island_Zigzagoon_Text_1:
	.string "Oh no, you lost a POKE BALL!$"

TARC_Island_Zigzagoon_Text_2:
	.string "You are very lucky that Zigzagoon has\n"
	.string "found it!$"

TARC_Island_Zigzagoon_Text_3:
	.string "Oh no, you lost a precious BIG NUGGET!$"

TARC_Island_Zigzagoon_Text_4:
	.string "Oh no, you lost an Ability Capsule!$"

TARC_Island_Zigzagoon_Text_5:
	.string "Oh no, you lost your LIFE ORB!$"

TARC_Island_Zigzagoon_Text_6:
	.string "Oh no, you lost your GYARADOSITE!$"

TARC_Island_Zigzagoon_Text_7:
	.string "Oh no, you lost your ROCK CLIMB TM!$"

TARC_Island_Game_Master_Text_0:
	.string "I am the Game Master.\p"
	.string "I will give you helpful advice for each\n"
	.string "situation, but it adds an additional\l"
	.string "20min to your play clock.$"

TARC_Island_Game_Master_Text_1:
	.string "Do you want me to give you a hint?$"

TARC_Island_Game_Master_Text_2:
	.string "Are you struggling against Slowking?\p"
	.string "Check out how Fling works to make good\n"
	.string "use of your items!$"

TARC_Island_Game_Master_Text_3:
	.string "Your party seems too small to continue\n"
	.string "from here.\p"
	.string "You should explore the outer limits of\n"
	.string "this island to make progress from your\l"
	.string "CURRENT situation!$"

TARC_Island_Game_Master_Text_4:
	.string "Seismitoad is too much for you?\p"
	.string "Having a team member with a super\n"
	.string "effective move would help\l"
	.string "tremendously!\p"
	.string "You should check out the pond above.$"

TARC_Island_Game_Master_Text_5:
	.string "What a cute Mantyke you have there!\p"
	.string "It's just a little weak.\p"
	.string "Maybe you can make use of your\n"
	.string "Remoraid to make it stronger?$"

TARC_Island_Game_Master_Text_6:
	.string "Have you visited Celebi?\p"
	.string "Mantine is so versatile to even learn a\n"
	.string "Grass type move!\p"
	.string "And don't forget to include Sableye in\n"
	.string "the fight!$"

TARC_Island_Game_Master_Text_7:
	.string "You need help with the cave mechanics?\p"
	.string "I cannot solve the puzzle for you, but I\n"
	.string "can explain the details for you.\p"
	.string "When spotted by a Kadabra or Onix it\n"
	.string "will warp you back to the last entrance.\p"
	.string "If spotted by a Zubat it will move\n"
	.string "towards you and stay there.\p"
	.string "When all boulders are placed on the\n"
	.string "target fields Onix will turn around and\l"
	.string "let you pass.$"

TARC_Island_Game_Master_Text_8:
	.string "Oh, you haven't picked up the second\n"
	.string "Pokéball, yet.\p"
	.string "Go to the north to find it!$"

TARC_Island_Game_Master_Text_9:
	.string "Your Farfetch'd looks strong!\p"
	.string "It seems to be able to even cut patches\n"
	.string "of grass.\p"
	.string "You should look into that possibility!$"

TARC_Island_Game_Master_Text_10:
	.string "The Castaway is too much for you?\p"
	.string "You should look into Porygon's abilities\n"
	.string "to make it a fair pairing!\p"
	.string "The key to success then is to manage\n"
	.string "your typing skillfully!$"

TARC_Island_Game_Master_Text_11:
	.string "You still cannot reach past the\n"
	.string "breakable rock?\p"
	.string "You gotta SELECT the right functions\n"
	.string "of your Pokédex to find the HINT.$"

TARC_Island_Game_Master_Text_12:
	.string "You are free, {PLAYER}!\p"
	.string "Just dive out of here and follow the\n"
	.string "way south.$"

TARC_Island_Game_Master_Text_13:
	.string "Archie is stopping you from leaving the\n"
	.string "UNDERWATER PATH?\p"
	.string "You need to closely explore the area\n"
	.string "then!$"

TARC_Island_Game_Master_Text_14:
	.string "Oh, you have found a Gyaradosite!\p"
	.string "But you are still searching for a Mega\n"
	.string "Ring?\p"
	.string "Seems like you missed to properly\n"
	.string "explore the cave.$"

TARC_Island_Game_Master_Text_15:
	.string "You keep losing to toxic damage?\p"
	.string "There is a way to get rid of the spikes!\p"
	.string "It will be teamwork but you need to find\n"
	.string "a way to ignore Weezing's Levitate!$"

TARC_Island_Game_Master_Text_16:
	.string "Come back whenever you need me.$"

TARC_Island_Game_Master_Text_17:
	.string "I am sorry, but I currently have no\n"
	.string "hints to give to you.\p"
	.string "Try proceeding by looking for items,\n"
	.string "catching Pokémon, talking to NPCs and\l"
	.string "winning battles.\p"
	.string "Of course, you won't be charged 20\n"
	.string "minutes this time.$"

TARC_Island_Game_Master_Text_18:
	.string "\p"
	.string "...\p"
	.string "I had already given this hint to you\n"
	.string "before.\p"
	.string "I guess it's fair if I don't charge you\n"
	.string "any more time for it.$"

TARC_Island_Maxie_Text_0:
	.string "Hello traveler!\l"
	.string "Welcome to my island!$"

TARC_Island_Maxie_Text_1:
	.string "It's been a long time since I have seen\n"
	.string "a soul on this plateau.\p"
	.string "A famous trainer named Archie was the\n"
	.string "last one in ages.\p"
	.string "He visited this place riding a Kyogre\n"
	.string "and came here to practice his sword\l"
	.string "fighting skills.\p"
	.string "He was wandering these MEADOWS\n"
	.string "swinging his sword to become as skillful\l"
	.string "as his big idol Link.\p"
	.string "Such a tragedy he later founded that\n"
	.string "stupid ass Team Aqua...$"

TARC_Island_Maxie_Text_2:
	.string "That's weird!\p"
	.string "You found the hidden spot cutting the\n"
	.string "grass and didn't interact with it?\p"
	.string "Why wouldn't you?$"

TARC_Island_Maxie_Text_3:
	.string "You found the item I had hidden!\p"
	.string "A magnificent feat that only a real\n"
	.string "Pokémon Master could've pulled off.$"

TARC_Island_sign_Game_Start_Text_0:
	.string "IMPORTANT INFORMATION:\p"
	.string "1.) This game is featuring Gen 8 LEVEL\n"
	.string "UP move LEARNSETS for any Pokemon you\l"
	.string "control yourself.\p"
	.string "2.) It is NOT required to grind MULTIPLE\n"
	.string "levels to win any of the fights.\p"
	.string "3.) The game mechanics are basically\n"
	.string "vanilla.\l"
	.string "However, crits are removed, confusions\l"
	.string "snap out immediately and RNG odds are\l"
	.string "either 100% or 0% to balance the game.\p"
	.string "4.) Running from trainer battles is\n"
	.string "explicitly ALLOWED.\p"
	.string "5.) Bulbapedia is your friend!$"

TARC_Island_sign_Rock_Climb_Text_0:
	.string "The rock below looks climbable. {DOWN_ARROW}$"

TARC_Island_Rhyhorn_Text_0:
	.string "RHYHORN!$"

TARC_Island_Rhyhorn_Text_1:
	.string "GRWAHH!$"

TARC_Island_Battle_Seismitoad_Text_0:
	.string "RIBBIT!$"

TARC_Island_Battle_Seismitoad_Text_1:
	.string "Seismitoad disappeared in the depths\n"
	.string "of the pond.$"

TARC_Island_Battle_Seismitoad_Text_2:
	.string "Seismitoad is watching the pond.$"

TARC_Island_Battle_Slowking_Text_0:
	.string "Slowking looks furious at being\n"
	.string "disturbed from sleeping!$"

TARC_Island_Battle_Slowking_Text_1:
	.string "...snore...$"

TARC_Island_Battle_Wonderguard_Text_0:
	.string "I should've taken a look into your\n"
	.string "Pokédex first!\p"
	.string "You are way too experienced for a\n"
	.string "Castaway like me.$"
