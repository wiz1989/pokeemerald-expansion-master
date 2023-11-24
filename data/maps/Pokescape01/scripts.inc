Pokescape01_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Pokescape01_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Pokescape01_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_TEMP_2, 0, EveryFrame
	.2byte 0


OnResume::
	setvar VAR_TEMP_2, 0
	compare VAR_LITTLEROOT_TOWN_STATE, 0
	goto_if_eq OnResume_2
OnResume_1:
	goto_if_set FLAG_P01_MASTER_BALL, OnResume_5
OnResume_4:
	setrespawn HEAL_LOCATION_POKESCAPE01
	setflag FLAG_BADGE01_GET
	setflag FLAG_BADGE02_GET
	setflag FLAG_BADGE03_GET
	setflag FLAG_BADGE04_GET
	setflag FLAG_BADGE05_GET
	setflag FLAG_BADGE06_GET
	setflag FLAG_BADGE07_GET
	setflag FLAG_BADGE08_GET
	setflag FLAG_SYS_POKEDEX_GET
	call load_HONOR_MODE
	end

OnResume_2:
	givemon SPECIES_MAKUHITA, 15
	givemonpc SPECIES_YAMASK, 16, ITEM_RARE_CANDY, 7, 19
	setinitialmovesPC MOVE_ASTONISH, MOVE_TRICK_ROOM, MOVE_TOXIC_SPIKES, MOVE_PROTECT
	setflag FLAG_SYS_POKEMON_GET
	addpcitem ITEM_TM_DIG, 1
	setvar VAR_LITTLEROOT_TOWN_STATE, 1
	goto OnResume_1

OnResume_5:
	setflag FLAG_TEMP_3
	goto OnResume_4


EveryFrame::
	goto_if_set FLAG_P01_HONOR_MODE, EveryFrame_3
EveryFrame_1:
	setvar VAR_TEMP_2, 1
	return

EveryFrame_2:
	lock
	clearflag FLAG_P01_LOAD_SAVEGAME
	buffernumberstring STR_VAR_1, VAR_P01_CALC
	call Common_EventScript_SaveGame
	closemessage
	release
	goto EveryFrame_1

EveryFrame_3:
	goto_if_set FLAG_P01_LOAD_SAVEGAME, EveryFrame_2
	goto EveryFrame_1


load_HONOR_MODE::
	goto_if_set FLAG_P01_HONOR_MODE, load_HONOR_MODE_2
	return

load_HONOR_MODE_1:
	addvar VAR_P01_PENALTY, 1
	setorcopyvar VAR_P01_CALC, VAR_P01_PENALTY
	multvar VAR_P01_CALC, 15
	setorcopyvar VAR_0x8004, VAR_P01_CALC
	special PlayTimeAddMin
	return

load_HONOR_MODE_2:
	goto_if_set FLAG_P01_LOAD_SAVEGAME, load_HONOR_MODE_1
	return


Pokescape01_EventScript_Azurill02::
	lock
	faceplayer
	msgbox Pokescape01_EventScript_Azurill02_Text_0
	waitmessage
	setobjectmovementtype 1, MOVEMENT_TYPE_WANDER_AROUND
	release
	end


Pokescape01_EventScript_Kirlia10::
	lock
	setflag FLAG_P01_KIRLIA
	faceplayer
	msgbox Pokescape01_EventScript_Kirlia10_Text_0
	waitmessage
	checkitem ITEM_SWEET_APPLE
	compare VAR_RESULT, TRUE
	goto_if_eq Pokescape01_EventScript_Kirlia10_2
	setobjectmovementtype 10, MOVEMENT_TYPE_WANDER_AROUND
Pokescape01_EventScript_Kirlia10_1:
	release
	end

Pokescape01_EventScript_Kirlia10_2:
	msgbox Pokescape01_EventScript_Kirlia10_Text_1, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Pokescape01_EventScript_Kirlia10_5
	msgbox Pokescape01_EventScript_Kirlia10_Text_3
	waitmessage
	setobjectmovementtype 10, MOVEMENT_TYPE_WANDER_AROUND
	goto Pokescape01_EventScript_Kirlia10_1

Pokescape01_EventScript_Kirlia10_5:
	msgbox Pokescape01_EventScript_Kirlia10_Text_2
	waitmessage
	removeitem ITEM_SWEET_APPLE
	fadescreen FADE_TO_BLACK
	removeobject 10
	fadescreen FADE_FROM_BLACK
	givemon SPECIES_KIRLIA, 20, ITEM_EVERSTONE
	clearflag FLAG_P01_KIRLIA
	setflag FLAG_P01_GOTKIRLIA
	setflag FLAG_HIDE_KIRLIA
	goto Pokescape01_EventScript_Kirlia10_1


Pokescape01_EventScript_Swimmer12::
	lock
	faceplayer
	msgbox Pokescape01_EventScript_Swimmer12_Text_0
	waitmessage
	msgbox Pokescape01_EventScript_Swimmer12_Text_1
	waitmessage
	setobjectmovementtype 12, MOVEMENT_TYPE_WANDER_AROUND
	release
	end


Pokescape01_EventScript_PokecenterSign::
	lockall
	buffernumberstring STR_VAR_1, VAR_P01_PENALTY
	buffernumberstring STR_VAR_2, VAR_P01_CALC
	msgbox Pokescape01_EventScript_PokecenterSign_Text_0
	waitmessage
	releaseall
	end


Pokescape01_EventScript_Building01Sign::
	lockall
	msgbox Pokescape01_EventScript_Building01Sign_Text_0
	waitmessage
	releaseall
	end


Pokescape01_EventScript_SignGrass::
	lockall
	msgbox Pokescape01_EventScript_SignGrass_Text_0
	showmonpic SPECIES_GIRAFARIG, 10, 3
	msgbox Pokescape01_EventScript_SignGrass_Text_1
	waitmessage
	hidemonpic
	showmonpic SPECIES_SCYTHER, 10, 3
	msgbox Pokescape01_EventScript_SignGrass_Text_2
	waitmessage
	hidemonpic
	releaseall
	end


Pokescape01_EventScript_PokecenterTriggers::
	compare VAR_UNUSED_0x408B, 0
	goto_if_eq Pokescape01_EventScript_PokecenterTriggers_2
Pokescape01_EventScript_PokecenterTriggers_1:
	end

Pokescape01_EventScript_PokecenterTriggers_2:
	lockall
	msgbox Pokescape01_EventScript_PokecenterTriggers_Text_0, MSGBOX_AUTOCLOSE
	waitmessage
	msgbox Pokescape01_EventScript_PokecenterTriggers_Text_1, MSGBOX_AUTOCLOSE
	waitmessage
	msgbox Pokescape01_EventScript_PokecenterTriggers_Text_2, MSGBOX_AUTOCLOSE
	waitmessage
	msgbox Pokescape01_EventScript_PokecenterTriggers_Text_3, MSGBOX_AUTOCLOSE
	waitmessage
	msgbox Pokescape01_EventScript_PokecenterTriggers_Text_4, MSGBOX_AUTOCLOSE
	waitmessage
	msgbox Pokescape01_EventScript_PokecenterTriggers_Text_5, MSGBOX_AUTOCLOSE
	waitmessage
	multichoicedefault 0, 0, MULTI_POKESCAPE_GAME_MODE, 0, TRUE
	switch VAR_RESULT
	case 0, Pokescape01_EventScript_PokecenterTriggers_6
	case 1, Pokescape01_EventScript_PokecenterTriggers_7
Pokescape01_EventScript_PokecenterTriggers_4:
	msgbox Pokescape01_EventScript_PokecenterTriggers_Text_8, MSGBOX_AUTOCLOSE
	waitmessage
	special ChangePlayerName
	waitmessage
	msgbox Pokescape01_EventScript_PokecenterTriggers_Text_9, MSGBOX_YESNO
Pokescape01_EventScript_PokecenterTriggers_9:
	compare VAR_RESULT, NO
	goto_if_eq Pokescape01_EventScript_PokecenterTriggers_10
	msgbox Pokescape01_EventScript_PokecenterTriggers_Text_10, MSGBOX_AUTOCLOSE
	waitmessage
	special RestartPlayTimer
	setvar VAR_UNUSED_0x408B, 1
	releaseall
	goto Pokescape01_EventScript_PokecenterTriggers_1

Pokescape01_EventScript_PokecenterTriggers_6:
	msgbox Pokescape01_EventScript_PokecenterTriggers_Text_6, MSGBOX_AUTOCLOSE
	waitmessage
	goto Pokescape01_EventScript_PokecenterTriggers_4

Pokescape01_EventScript_PokecenterTriggers_7:
	setflag FLAG_P01_HONOR_MODE
	msgbox Pokescape01_EventScript_PokecenterTriggers_Text_7, MSGBOX_AUTOCLOSE
	waitmessage
	goto Pokescape01_EventScript_PokecenterTriggers_4

Pokescape01_EventScript_PokecenterTriggers_10:
	special ChangePlayerName
	waitmessage
	msgbox Pokescape01_EventScript_PokecenterTriggers_Text_9, MSGBOX_YESNO
	goto Pokescape01_EventScript_PokecenterTriggers_9


Pokescape01_EventScript_TriggerLittleGirl::
	lockall
	checkpartymon SPECIES_SCYTHER
	compare VAR_RESULT, 0
	goto_if_ne Pokescape01_EventScript_TriggerLittleGirl_2
Pokescape01_EventScript_TriggerLittleGirl_1:
	releaseall
	end

Pokescape01_EventScript_TriggerLittleGirl_2:
	applymovement 15, Move01
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, MovePlayer01
	waitmovement 0
	msgbox Pokescape01_EventScript_TriggerLittleGirl_Text_0
	waitmessage
	applymovement OBJ_EVENT_ID_PLAYER, Move02
	waitmovement 0
	goto Pokescape01_EventScript_TriggerLittleGirl_1


Pokescape01_EventScript_ItemMasterBall::
	lock
	msgbox Pokescape01_EventScript_ItemMasterBall_Text_0
	waitmessage
	giveitem ITEM_MASTER_BALL, 1
	removeobject 5
	setflag FLAG_P01_MASTER_BALL
	setflag FLAG_TEMP_3
	release
	end


Pokescape01_EventScript_ItemEviolite::
	lock
	giveitem ITEM_EVIOLITE, 1
	fadescreen FADE_TO_BLACK
	removeobject 16
	fadescreen FADE_FROM_BLACK
	setflag FLAG_P01_EVIOLITE
	release
	end


Pokescape01_EventScript_AppleTree::
	lock
	compare VAR_UNUSED_0x40F7, 0
	goto_if_eq Pokescape01_EventScript_AppleTree_2
	msgbox Pokescape01_EventScript_AppleTree_Text_3
Pokescape01_EventScript_AppleTree_1:
	release
	end

Pokescape01_EventScript_AppleTree_2:
	checkpartymon SPECIES_GIRAFARIG
	compare VAR_RESULT, 0
	goto_if_ne Pokescape01_EventScript_AppleTree_6
	clearflag FLAG_P01_GOTGIRAFARIG
Pokescape01_EventScript_AppleTree_5:
	goto_if_set FLAG_P01_GOTGIRAFARIG, Pokescape01_EventScript_AppleTree_9
	goto_if_set FLAG_P01_SCYTHER, Pokescape01_EventScript_AppleTree_10
	msgbox Pokescape01_EventScript_AppleTree_Text_2
	goto Pokescape01_EventScript_AppleTree_1

Pokescape01_EventScript_AppleTree_6:
	setflag FLAG_P01_GOTGIRAFARIG
	goto Pokescape01_EventScript_AppleTree_5

Pokescape01_EventScript_AppleTree_9:
	msgbox Pokescape01_EventScript_AppleTree_Text_0
	giveitem ITEM_SWEET_APPLE, 1
	setvar VAR_UNUSED_0x40F7, 1
	goto Pokescape01_EventScript_AppleTree_1

Pokescape01_EventScript_AppleTree_10:
	msgbox Pokescape01_EventScript_AppleTree_Text_1
	goto Pokescape01_EventScript_AppleTree_1


Pokescape01_EventScript_LittleGirl15::
	lockall
	faceplayer
	msgbox Pokescape01_EventScript_LittleGirl15_Text_0
	waitmessage
	releaseall
	end


Pokescape01_EventScript_Geodude::
	checktrainerflag TRAINER_POKESCAPE01_01
	goto_if 0, Pokescape01_EventScript_Geodude_2
	lockall
	msgbox Pokescape01_EventScript_Geodude_Text_0, MSGBOX_AUTOCLOSE
	waitmessage
	releaseall
Pokescape01_EventScript_Geodude_1:
	end

Pokescape01_EventScript_Geodude_2:
	playmoncry SPECIES_GEODUDE, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_GEODUDE, 14
	dowildbattle
	goto Pokescape01_EventScript_Geodude_1


Pokescape01_EventScript_Battle01::
	trainerbattle_single TRAINER_POKESCAPE01_01, Pokescape01_EventScript_Battle01_Text_0, Pokescape01_EventScript_Battle01_Text_1
	lock
	msgbox Pokescape01_EventScript_Battle01_Text_2
	waitmessage
	release
	end


Pokescape01_EventScript_BattleDouble02::
	trainerbattle_double TRAINER_POKESCAPE01_02, Pokescape01_EventScript_BattleDouble02_Text_0, Pokescape01_EventScript_BattleDouble02_Text_1, Text_NotEnoughMons
	lockall
	goto_if_unset FLAG_UNUSED_0x95E, Pokescape01_EventScript_BattleDouble02_2
	msgbox Pokescape01_EventScript_BattleDouble02_Text_1
	waitmessage
Pokescape01_EventScript_BattleDouble02_1:
	releaseall
	end

Pokescape01_EventScript_BattleDouble02_2:
	checkpartymon SPECIES_MAKUHITA
	compare VAR_RESULT, 0
	goto_if_ne Pokescape01_EventScript_BattleDouble02_5
	checkpartymon SPECIES_HARIYAMA
	compare VAR_RESULT, 0
	goto_if_ne Pokescape01_EventScript_BattleDouble02_11
	msgbox Pokescape01_EventScript_BattleDouble02_Text_8
	waitmessage
	goto Pokescape01_EventScript_BattleDouble02_1

Pokescape01_EventScript_BattleDouble02_5:
	msgbox Pokescape01_EventScript_BattleDouble02_Text_2, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Pokescape01_EventScript_BattleDouble02_8
	msgbox Pokescape01_EventScript_BattleDouble02_Text_5
	waitmessage
	goto Pokescape01_EventScript_BattleDouble02_1

Pokescape01_EventScript_BattleDouble02_8:
	setflag FLAG_UNUSED_0x95D
	setflag FLAG_UNUSED_0x95E
	getpartymonslot SPECIES_MAKUHITA
	special DeletePartyMon
	givemon SPECIES_WOOPER, 19
	msgbox Pokescape01_EventScript_BattleDouble02_Text_3
	waitmessage
	msgbox Pokescape01_EventScript_BattleDouble02_Text_4
	waitmessage
	goto Pokescape01_EventScript_BattleDouble02_1

Pokescape01_EventScript_BattleDouble02_11:
	msgbox Pokescape01_EventScript_BattleDouble02_Text_6, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Pokescape01_EventScript_BattleDouble02_14
	msgbox Pokescape01_EventScript_BattleDouble02_Text_5
	waitmessage
	goto Pokescape01_EventScript_BattleDouble02_1

Pokescape01_EventScript_BattleDouble02_14:
	setflag FLAG_UNUSED_0x95D
	setflag FLAG_UNUSED_0x95E
	getpartymonslot SPECIES_HARIYAMA
	special DeletePartyMon
	givemon SPECIES_WOOPER, 19
	msgbox Pokescape01_EventScript_BattleDouble02_Text_7
	waitmessage
	msgbox Pokescape01_EventScript_BattleDouble02_Text_4
	waitmessage
	goto Pokescape01_EventScript_BattleDouble02_1


Pokescape01_EventScript_BattleDouble03::
	setvar VAR_BATTLE_TURN, 0
	trainerbattle_double TRAINER_POKESCAPE01_03, Pokescape01_EventScript_BattleDouble03_Text_0, Pokescape01_EventScript_BattleDouble03_Text_1, Text_NotEnoughMons
	setflag FLAG_UNUSED_0x95C
	end


Pokescape01_Pokecenter_EventScript_Picture01::
	lock
	showmonpic SPECIES_MEGANIUM, 10, 3
	msgbox Pokescape01_Pokecenter_EventScript_Picture01_Text_0
	waitmessage
	hidemonpic
	release
	end


Pokescape01_Pokecenter_EventScript_Picture02::
	lock
	showmonpic SPECIES_CLEFABLE, 10, 3
	msgbox Pokescape01_Pokecenter_EventScript_Picture02_Text_0
	waitmessage
	hidemonpic
	release
	end


Pokescape01_Pokecenter_EventScript_Nurse::
	lock
	setvar VAR_0x800B, 1
	checktrainerflag TRAINER_POKESCAPE01_01
	goto_if 0, Pokescape01_Pokecenter_EventScript_Nurse_2
	goto_if_unset FLAG_UNUSED_0x95D, Pokescape01_Pokecenter_EventScript_Nurse_3
	call Common_EventScript_PkmnCenterNurse
	waitmessage
Pokescape01_Pokecenter_EventScript_Nurse_1:
	release
	end

Pokescape01_Pokecenter_EventScript_Nurse_2:
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	msgbox Pokescape01_Pokecenter_EventScript_Nurse_Text_0
	waitmessage
	goto Pokescape01_Pokecenter_EventScript_Nurse_1

Pokescape01_Pokecenter_EventScript_Nurse_3:
	msgbox Pokescape01_Pokecenter_EventScript_Nurse_Text_1
	waitmessage
	goto Pokescape01_Pokecenter_EventScript_Nurse_1


Pokescape01_Pokecenter_EventScript_Boy::
	lock
	faceplayer
	checktrainerflag TRAINER_POKESCAPE01_01
	goto_if 0, Pokescape01_Pokecenter_EventScript_Boy_2
	goto_if_unset FLAG_UNUSED_0x95D, Pokescape01_Pokecenter_EventScript_Boy_3
	msgbox Pokescape01_Pokecenter_EventScript_Boy_Text_2
	waitmessage
Pokescape01_Pokecenter_EventScript_Boy_1:
	release
	end

Pokescape01_Pokecenter_EventScript_Boy_2:
	msgbox Pokescape01_Pokecenter_EventScript_Boy_Text_0
	waitmessage
	goto Pokescape01_Pokecenter_EventScript_Boy_1

Pokescape01_Pokecenter_EventScript_Boy_3:
	msgbox Pokescape01_Pokecenter_EventScript_Boy_Text_1
	waitmessage
	goto Pokescape01_Pokecenter_EventScript_Boy_1


Pokescape01_Pokecenter_EventScript_Gentleman::
	lock
	clearflag FLAG_P01_ADD30MIN
	clearflag FLAG_P01_GIVE_ADVICE
	faceplayer
	msgbox Pokescape01_Pokecenter_EventScript_Gentleman_Text_0
	waitmessage
	msgbox Pokescape01_Pokecenter_EventScript_Gentleman_Text_1, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Pokescape01_Pokecenter_EventScript_Gentleman_2
	msgbox Pokescape01_Pokecenter_EventScript_Gentleman_Text_10
Pokescape01_Pokecenter_EventScript_Gentleman_1:
	waitmessage
	goto_if_set FLAG_P01_ADD30MIN, Pokescape01_Pokecenter_EventScript_Gentleman_6
	goto_if_set FLAG_P01_DONT_CHEAT, Pokescape01_Pokecenter_EventScript_Gentleman_15
	goto_if_set FLAG_P01_GIVE_ADVICE, Pokescape01_Pokecenter_EventScript_Gentleman_23
	msgbox Pokescape01_Pokecenter_EventScript_Gentleman_Text_13
	waitmessage
Pokescape01_Pokecenter_EventScript_Gentleman_5:
	release
	end

Pokescape01_Pokecenter_EventScript_Gentleman_2:
	setflag FLAG_P01_GIVE_ADVICE
	getpartysize
	checktrainerflag TRAINER_POKESCAPE01_01
	goto_if 0, Pokescape01_Pokecenter_EventScript_Gentleman_11
Pokescape01_Pokecenter_EventScript_Gentleman_10:
	specialvar VAR_RESULT, IsPcEmpty
	compare VAR_RESULT, FALSE
	goto_if_eq Pokescape01_Pokecenter_EventScript_Gentleman_20
	checktrainerflag TRAINER_POKESCAPE01_01
	goto_if 0, Pokescape01_Pokecenter_EventScript_Gentleman_27
Pokescape01_Pokecenter_EventScript_Gentleman_26:
	specialvar VAR_RESULT, HasOneUnfaintedMon
	checktrainerflag TRAINER_POKESCAPE01_01
	goto_if 1, Pokescape01_Pokecenter_EventScript_Gentleman_32
Pokescape01_Pokecenter_EventScript_Gentleman_29:
	checkpartymon SPECIES_WOOPER
	compare VAR_RESULT, 0
	goto_if_ne Pokescape01_Pokecenter_EventScript_Gentleman_40
	clearflag FLAG_P01_GOTWOOPER
Pokescape01_Pokecenter_EventScript_Gentleman_39:
	checkpartymon SPECIES_QUAGSIRE
	compare VAR_RESULT, 0
	goto_if_ne Pokescape01_Pokecenter_EventScript_Gentleman_53
	clearflag FLAG_P01_GOTQUAGSIRE
Pokescape01_Pokecenter_EventScript_Gentleman_52:
	checkpartymon SPECIES_GALLADE
	compare VAR_RESULT, 0
	goto_if_ne Pokescape01_Pokecenter_EventScript_Gentleman_70
	clearflag FLAG_P01_GOTGALLADE
Pokescape01_Pokecenter_EventScript_Gentleman_69:
	checkpartymon SPECIES_GARDEVOIR
	compare VAR_RESULT, 0
	goto_if_ne Pokescape01_Pokecenter_EventScript_Gentleman_74
	clearflag FLAG_P01_GOTGARDEVOIR
Pokescape01_Pokecenter_EventScript_Gentleman_73:
	checkitem ITEM_HM_CUT
	compare VAR_RESULT, 0
	goto_if_ne Pokescape01_Pokecenter_EventScript_Gentleman_78
	clearflag FLAG_P01_HM_CUT
Pokescape01_Pokecenter_EventScript_Gentleman_77:
	goto_if_set FLAG_P01_GOTKIRLIA, Pokescape01_Pokecenter_EventScript_Gentleman_83
Pokescape01_Pokecenter_EventScript_Gentleman_82:
	checktrainerflag TRAINER_POKESCAPE01_02
	goto_if 1, Pokescape01_Pokecenter_EventScript_Gentleman_91
	goto Pokescape01_Pokecenter_EventScript_Gentleman_1

Pokescape01_Pokecenter_EventScript_Gentleman_6:
	setorcopyvar VAR_0x8004, 30
	special PlayTimeAddMin
	goto Pokescape01_Pokecenter_EventScript_Gentleman_5

Pokescape01_Pokecenter_EventScript_Gentleman_9:
	goto_if_unset FLAG_P01_Hint01, Pokescape01_Pokecenter_EventScript_Gentleman_18
Pokescape01_Pokecenter_EventScript_Gentleman_17:
	msgbox Text_TipCheckPC
	clearflag FLAG_P01_GIVE_ADVICE
	goto Pokescape01_Pokecenter_EventScript_Gentleman_1

Pokescape01_Pokecenter_EventScript_Gentleman_11:
	compare VAR_RESULT, 1
	goto_if_le Pokescape01_Pokecenter_EventScript_Gentleman_9
	goto Pokescape01_Pokecenter_EventScript_Gentleman_10

Pokescape01_Pokecenter_EventScript_Gentleman_15:
	setorcopyvar VAR_0x8004, 30
	special PlayTimeAddMin
	clearflag FLAG_P01_DONT_CHEAT
	msgbox Pokescape01_Pokecenter_EventScript_Gentleman_Text_11
	waitmessage
	release
	end

Pokescape01_Pokecenter_EventScript_Gentleman_18:
	setflag FLAG_P01_Hint01
	setflag FLAG_P01_ADD30MIN
	goto Pokescape01_Pokecenter_EventScript_Gentleman_17

Pokescape01_Pokecenter_EventScript_Gentleman_20:
	msgbox Pokescape01_Pokecenter_EventScript_Gentleman_Text_2
	clearflag FLAG_P01_GIVE_ADVICE
	goto Pokescape01_Pokecenter_EventScript_Gentleman_1

Pokescape01_Pokecenter_EventScript_Gentleman_23:
	msgbox Pokescape01_Pokecenter_EventScript_Gentleman_Text_12
	waitmessage
	goto Pokescape01_Pokecenter_EventScript_Gentleman_5

Pokescape01_Pokecenter_EventScript_Gentleman_27:
	getpartysize
	compare VAR_RESULT, 1
	goto_if_le Pokescape01_Pokecenter_EventScript_Gentleman_36
	goto_if_set FLAG_P01_RARE_CANDY, Pokescape01_Pokecenter_EventScript_Gentleman_49
	goto_if_unset FLAG_P01_Hint04, Pokescape01_Pokecenter_EventScript_Gentleman_67
Pokescape01_Pokecenter_EventScript_Gentleman_66:
	msgbox Text_TipFirstFight
	clearflag FLAG_P01_GIVE_ADVICE
	goto Pokescape01_Pokecenter_EventScript_Gentleman_26

Pokescape01_Pokecenter_EventScript_Gentleman_30:
	goto_if_set FLAG_P01_RARE_CANDY, Pokescape01_Pokecenter_EventScript_Gentleman_43
	goto_if_unset FLAG_P01_Hint06, Pokescape01_Pokecenter_EventScript_Gentleman_61
Pokescape01_Pokecenter_EventScript_Gentleman_60:
	msgbox Text_TipRareCandyUse
	clearflag FLAG_P01_GIVE_ADVICE
	goto Pokescape01_Pokecenter_EventScript_Gentleman_29

Pokescape01_Pokecenter_EventScript_Gentleman_31:
	compare VAR_RESULT, 0
	goto_if_ne Pokescape01_Pokecenter_EventScript_Gentleman_30
	goto Pokescape01_Pokecenter_EventScript_Gentleman_29

Pokescape01_Pokecenter_EventScript_Gentleman_32:
	checktrainerflag TRAINER_POKESCAPE01_02
	goto_if 0, Pokescape01_Pokecenter_EventScript_Gentleman_31
	goto Pokescape01_Pokecenter_EventScript_Gentleman_29

Pokescape01_Pokecenter_EventScript_Gentleman_36:
	goto_if_unset FLAG_P01_Hint02, Pokescape01_Pokecenter_EventScript_Gentleman_47
Pokescape01_Pokecenter_EventScript_Gentleman_46:
	msgbox Text_TipCheckPC
	clearflag FLAG_P01_GIVE_ADVICE
	goto Pokescape01_Pokecenter_EventScript_Gentleman_26

Pokescape01_Pokecenter_EventScript_Gentleman_40:
	setflag FLAG_P01_GOTWOOPER
	goto Pokescape01_Pokecenter_EventScript_Gentleman_39

Pokescape01_Pokecenter_EventScript_Gentleman_43:
	goto_if_unset FLAG_P01_Hint05, Pokescape01_Pokecenter_EventScript_Gentleman_57
	setflag FLAG_P01_DONT_CHEAT
Pokescape01_Pokecenter_EventScript_Gentleman_56:
	msgbox Text_TipRareCandyRevive
	giveitem ITEM_RARE_CANDY, 1
	clearflag FLAG_P01_RARE_CANDY
	clearflag FLAG_P01_GIVE_ADVICE
	goto Pokescape01_Pokecenter_EventScript_Gentleman_29

Pokescape01_Pokecenter_EventScript_Gentleman_47:
	setflag FLAG_P01_Hint02
	setflag FLAG_P01_ADD30MIN
	goto Pokescape01_Pokecenter_EventScript_Gentleman_46

Pokescape01_Pokecenter_EventScript_Gentleman_49:
	goto_if_unset FLAG_P01_Hint03, Pokescape01_Pokecenter_EventScript_Gentleman_64
Pokescape01_Pokecenter_EventScript_Gentleman_63:
	msgbox Text_TipRareCandy
	giveitem ITEM_RARE_CANDY, 1
	clearflag FLAG_P01_RARE_CANDY
	clearflag FLAG_P01_GIVE_ADVICE
	goto Pokescape01_Pokecenter_EventScript_Gentleman_26

Pokescape01_Pokecenter_EventScript_Gentleman_53:
	setflag FLAG_P01_GOTQUAGSIRE
	goto Pokescape01_Pokecenter_EventScript_Gentleman_52

Pokescape01_Pokecenter_EventScript_Gentleman_57:
	setflag FLAG_P01_Hint05
	setflag FLAG_P01_ADD30MIN
	goto Pokescape01_Pokecenter_EventScript_Gentleman_56

Pokescape01_Pokecenter_EventScript_Gentleman_61:
	setflag FLAG_P01_Hint06
	setflag FLAG_P01_ADD30MIN
	goto Pokescape01_Pokecenter_EventScript_Gentleman_60

Pokescape01_Pokecenter_EventScript_Gentleman_64:
	setflag FLAG_P01_Hint03
	setflag FLAG_P01_ADD30MIN
	goto Pokescape01_Pokecenter_EventScript_Gentleman_63

Pokescape01_Pokecenter_EventScript_Gentleman_67:
	setflag FLAG_P01_Hint04
	setflag FLAG_P01_ADD30MIN
	goto Pokescape01_Pokecenter_EventScript_Gentleman_66

Pokescape01_Pokecenter_EventScript_Gentleman_70:
	setflag FLAG_P01_GOTGALLADE
	goto Pokescape01_Pokecenter_EventScript_Gentleman_69

Pokescape01_Pokecenter_EventScript_Gentleman_74:
	setflag FLAG_P01_GOTGARDEVOIR
	goto Pokescape01_Pokecenter_EventScript_Gentleman_73

Pokescape01_Pokecenter_EventScript_Gentleman_78:
	setflag FLAG_P01_HM_CUT
	goto Pokescape01_Pokecenter_EventScript_Gentleman_77

Pokescape01_Pokecenter_EventScript_Gentleman_81:
	goto_if_set FLAG_P01_GOTWOOPER, Pokescape01_Pokecenter_EventScript_Gentleman_86
	goto_if_set FLAG_P01_GOTGARDEVOIR, Pokescape01_Pokecenter_EventScript_Gentleman_87
	goto_if_set FLAG_P01_GOTQUAGSIRE, Pokescape01_Pokecenter_EventScript_Gentleman_102
Pokescape01_Pokecenter_EventScript_Gentleman_101:
	goto_if_set FLAG_P01_GOTGALLADE, Pokescape01_Pokecenter_EventScript_Gentleman_100
	goto Pokescape01_Pokecenter_EventScript_Gentleman_1

Pokescape01_Pokecenter_EventScript_Gentleman_83:
	goto_if_set FLAG_P01_HM_CUT, Pokescape01_Pokecenter_EventScript_Gentleman_81
	goto Pokescape01_Pokecenter_EventScript_Gentleman_82

Pokescape01_Pokecenter_EventScript_Gentleman_86:
	goto_if_unset FLAG_P01_Hint07, Pokescape01_Pokecenter_EventScript_Gentleman_94
Pokescape01_Pokecenter_EventScript_Gentleman_93:
	msgbox Pokescape01_Pokecenter_EventScript_Gentleman_Text_3
	clearflag FLAG_P01_GIVE_ADVICE
	goto Pokescape01_Pokecenter_EventScript_Gentleman_1

Pokescape01_Pokecenter_EventScript_Gentleman_87:
	goto_if_unset FLAG_P01_Hint08, Pokescape01_Pokecenter_EventScript_Gentleman_97
Pokescape01_Pokecenter_EventScript_Gentleman_96:
	msgbox Text_TipGardevoir
	waitmessage
	clearflag FLAG_P01_GIVE_ADVICE
	getpartymonslot SPECIES_GARDEVOIR
	special DeletePartyMon
	msgbox Pokescape01_Pokecenter_EventScript_Gentleman_Text_4
	givemon SPECIES_KIRLIA, 20, ITEM_EVERSTONE
	checkitem ITEM_EVERSTONE
	compare VAR_RESULT, TRUE
	goto_if_eq Pokescape01_Pokecenter_EventScript_Gentleman_108
	goto Pokescape01_Pokecenter_EventScript_Gentleman_1

Pokescape01_Pokecenter_EventScript_Gentleman_91:
	goto_if_unset FLAG_P01_MASTER_BALL, Pokescape01_Pokecenter_EventScript_Gentleman_105
	goto_if_set FLAG_P01_SCYTHER, Pokescape01_Pokecenter_EventScript_Gentleman_125
Pokescape01_Pokecenter_EventScript_Gentleman_123:
	goto_if_unset FLAG_P01_SCYTHER, Pokescape01_Pokecenter_EventScript_Gentleman_122
Pokescape01_Pokecenter_EventScript_Gentleman_121:
	checkitem ITEM_HM_CUT
	compare VAR_RESULT, FALSE
	goto_if_eq Pokescape01_Pokecenter_EventScript_Gentleman_134
	goto_if_set FLAG_P01_KIRLIA, Pokescape01_Pokecenter_EventScript_Gentleman_136
	goto Pokescape01_Pokecenter_EventScript_Gentleman_1

Pokescape01_Pokecenter_EventScript_Gentleman_94:
	setflag FLAG_P01_Hint07
	setflag FLAG_P01_ADD30MIN
	goto Pokescape01_Pokecenter_EventScript_Gentleman_93

Pokescape01_Pokecenter_EventScript_Gentleman_97:
	setflag FLAG_P01_Hint08
	setflag FLAG_P01_ADD30MIN
	goto Pokescape01_Pokecenter_EventScript_Gentleman_96

Pokescape01_Pokecenter_EventScript_Gentleman_99:
	goto_if_unset FLAG_P01_Hint09, Pokescape01_Pokecenter_EventScript_Gentleman_111
Pokescape01_Pokecenter_EventScript_Gentleman_110:
	msgbox Pokescape01_Pokecenter_EventScript_Gentleman_Text_6
	clearflag FLAG_P01_GIVE_ADVICE
	goto Pokescape01_Pokecenter_EventScript_Gentleman_1

Pokescape01_Pokecenter_EventScript_Gentleman_100:
	goto_if_unset FLAG_P01_Hint10, Pokescape01_Pokecenter_EventScript_Gentleman_114
Pokescape01_Pokecenter_EventScript_Gentleman_113:
	msgbox Pokescape01_Pokecenter_EventScript_Gentleman_Text_7
	clearflag FLAG_P01_GIVE_ADVICE
	goto Pokescape01_Pokecenter_EventScript_Gentleman_1

Pokescape01_Pokecenter_EventScript_Gentleman_102:
	goto_if_unset FLAG_P01_GOTGALLADE, Pokescape01_Pokecenter_EventScript_Gentleman_99
	goto Pokescape01_Pokecenter_EventScript_Gentleman_101

Pokescape01_Pokecenter_EventScript_Gentleman_105:
	goto_if_unset FLAG_P01_Hint11, Pokescape01_Pokecenter_EventScript_Gentleman_117
Pokescape01_Pokecenter_EventScript_Gentleman_116:
	msgbox Text_TipMasterBall
	clearflag FLAG_P01_GIVE_ADVICE
	goto Pokescape01_Pokecenter_EventScript_Gentleman_1

Pokescape01_Pokecenter_EventScript_Gentleman_108:
	waitmessage
	removeitem ITEM_EVERSTONE
	msgbox Pokescape01_Pokecenter_EventScript_Gentleman_Text_5
	goto Pokescape01_Pokecenter_EventScript_Gentleman_1

Pokescape01_Pokecenter_EventScript_Gentleman_111:
	setflag FLAG_P01_Hint09
	setflag FLAG_P01_ADD30MIN
	goto Pokescape01_Pokecenter_EventScript_Gentleman_110

Pokescape01_Pokecenter_EventScript_Gentleman_114:
	setflag FLAG_P01_Hint10
	setflag FLAG_P01_ADD30MIN
	goto Pokescape01_Pokecenter_EventScript_Gentleman_113

Pokescape01_Pokecenter_EventScript_Gentleman_117:
	setflag FLAG_P01_Hint11
	setflag FLAG_P01_ADD30MIN
	goto Pokescape01_Pokecenter_EventScript_Gentleman_116

Pokescape01_Pokecenter_EventScript_Gentleman_119:
	goto_if_unset FLAG_P01_Hint12, Pokescape01_Pokecenter_EventScript_Gentleman_129
Pokescape01_Pokecenter_EventScript_Gentleman_128:
	msgbox Text_TipScyther
	waitmessage
	clearflag FLAG_P01_GIVE_ADVICE
	getpartymonslot SPECIES_SCYTHER
	special DeletePartyMon
	giveitem ITEM_MASTER_BALL, 1
	msgbox Pokescape01_Pokecenter_EventScript_Gentleman_Text_8
	checkitem ITEM_HM_CUT
	compare VAR_RESULT, TRUE
	goto_if_eq Pokescape01_Pokecenter_EventScript_Gentleman_141
Pokescape01_Pokecenter_EventScript_Gentleman_140:
	clearflag FLAG_P01_SCYTHER
	goto Pokescape01_Pokecenter_EventScript_Gentleman_1

Pokescape01_Pokecenter_EventScript_Gentleman_120:
	goto_if_unset FLAG_P01_Hint13, Pokescape01_Pokecenter_EventScript_Gentleman_132
Pokescape01_Pokecenter_EventScript_Gentleman_131:
	msgbox Text_TipCatch
	clearflag FLAG_P01_GIVE_ADVICE
	goto Pokescape01_Pokecenter_EventScript_Gentleman_1

Pokescape01_Pokecenter_EventScript_Gentleman_122:
	goto_if_unset FLAG_P01_GIRAFARIG, Pokescape01_Pokecenter_EventScript_Gentleman_120
	goto Pokescape01_Pokecenter_EventScript_Gentleman_121

Pokescape01_Pokecenter_EventScript_Gentleman_125:
	goto_if_unset FLAG_P01_GIRAFARIG, Pokescape01_Pokecenter_EventScript_Gentleman_119
	goto Pokescape01_Pokecenter_EventScript_Gentleman_123

Pokescape01_Pokecenter_EventScript_Gentleman_129:
	setflag FLAG_P01_Hint12
	setflag FLAG_P01_ADD30MIN
	goto Pokescape01_Pokecenter_EventScript_Gentleman_128

Pokescape01_Pokecenter_EventScript_Gentleman_132:
	setflag FLAG_P01_Hint13
	setflag FLAG_P01_ADD30MIN
	goto Pokescape01_Pokecenter_EventScript_Gentleman_131

Pokescape01_Pokecenter_EventScript_Gentleman_134:
	setorcopyvar VAR_0x8004, ITEM_HM_CUT
	specialvar VAR_RESULT, ItemisHeldInParty
	compare VAR_RESULT, FALSE
	goto_if_eq Pokescape01_Pokecenter_EventScript_Gentleman_143
	goto Pokescape01_Pokecenter_EventScript_Gentleman_1

Pokescape01_Pokecenter_EventScript_Gentleman_135:
	goto_if_unset FLAG_P01_Hint15, Pokescape01_Pokecenter_EventScript_Gentleman_146
Pokescape01_Pokecenter_EventScript_Gentleman_145:
	msgbox Text_TipKirlia
	clearflag FLAG_P01_GIVE_ADVICE
	goto Pokescape01_Pokecenter_EventScript_Gentleman_1

Pokescape01_Pokecenter_EventScript_Gentleman_136:
	compare VAR_UNUSED_0x40F7, 0
	goto_if_eq Pokescape01_Pokecenter_EventScript_Gentleman_135
	goto Pokescape01_Pokecenter_EventScript_Gentleman_1

Pokescape01_Pokecenter_EventScript_Gentleman_141:
	waitmessage
	clearflag FLAG_P01_HM_CUT
	removeitem ITEM_HM_CUT
	msgbox Pokescape01_Pokecenter_EventScript_Gentleman_Text_9
	goto Pokescape01_Pokecenter_EventScript_Gentleman_140

Pokescape01_Pokecenter_EventScript_Gentleman_143:
	goto_if_unset FLAG_P01_Hint14, Pokescape01_Pokecenter_EventScript_Gentleman_149
Pokescape01_Pokecenter_EventScript_Gentleman_148:
	msgbox Text_TipHMCut
	clearflag FLAG_P01_GIVE_ADVICE
	goto Pokescape01_Pokecenter_EventScript_Gentleman_1

Pokescape01_Pokecenter_EventScript_Gentleman_146:
	setflag FLAG_P01_Hint15
	setflag FLAG_P01_ADD30MIN
	goto Pokescape01_Pokecenter_EventScript_Gentleman_145

Pokescape01_Pokecenter_EventScript_Gentleman_149:
	setflag FLAG_P01_Hint14
	setflag FLAG_P01_ADD30MIN
	goto Pokescape01_Pokecenter_EventScript_Gentleman_148


Pokescape01_Pokecenter_EventScript_Scientist::
	lock
	faceplayer
	getpartysize
	compare VAR_RESULT, 1
	goto_if_le Pokescape01_Pokecenter_EventScript_Scientist_2
	goto_if_unset FLAG_UNUSED_0x95E, Pokescape01_Pokecenter_EventScript_Scientist_5
	msgbox Pokescape01_Pokecenter_EventScript_Scientist_Text_2
Pokescape01_Pokecenter_EventScript_Scientist_1:
	waitmessage
	release
	end

Pokescape01_Pokecenter_EventScript_Scientist_2:
	msgbox Pokescape01_Pokecenter_EventScript_Scientist_Text_0
	goto Pokescape01_Pokecenter_EventScript_Scientist_1

Pokescape01_Pokecenter_EventScript_Scientist_5:
	msgbox Pokescape01_Pokecenter_EventScript_Scientist_Text_1
	goto Pokescape01_Pokecenter_EventScript_Scientist_1


Pokescape01_House_EventScript_Birch::
	lock
	special StopPlayTimer
	faceplayer
	specialvar VAR_RESULT, GetPlayTimeHours
	buffernumberstring STR_VAR_1, VAR_RESULT
	specialvar VAR_RESULT, GetPlayTimeMinutes
	buffertimestring STR_VAR_2, VAR_RESULT
	specialvar VAR_RESULT, GetPlayTimeSeconds
	buffertimestring STR_VAR_3, VAR_RESULT
	goto_if_set FLAG_P01_HONOR_MODE, Pokescape01_House_EventScript_Birch_2
	msgbox Text_Finale_regular
Pokescape01_House_EventScript_Birch_1:
	waitmessage
	release
	end

Pokescape01_House_EventScript_Birch_2:
	msgbox Text_Finale_honor
	goto Pokescape01_House_EventScript_Birch_1


Pokescape01_House_EventScript_Pikachu::
	lock
	faceplayer
	msgbox Pokescape01_House_EventScript_Pikachu_Text_0
	waitmessage
	setobjectmovementtype 2, MOVEMENT_TYPE_WANDER_AROUND
	release
	end


Move01:
	emote_exclamation_mark
	step_end

MovePlayer01:
	face_left
	step_end

Move02:
	face_down
	walk_down
	step_end

Pokescape01_EventScript_Azurill02_Text_0:
	.string "...Rill...$"

Pokescape01_EventScript_Kirlia10_Text_0:
	.string "Kirlia looks very hungry.$"

Pokescape01_EventScript_Kirlia10_Text_1:
	.string "Oh, you have a Sweet Apple. Do you want\n"
	.string "to give it to Kirlia?$"

Pokescape01_EventScript_Kirlia10_Text_2:
	.string "Kirlia is very thankful and joins your\n"
	.string "team.$"

Pokescape01_EventScript_Kirlia10_Text_3:
	.string "Poor Kirlia.$"

Pokescape01_EventScript_Swimmer12_Text_0:
	.string "These trainers on the hill look pretty\n"
	.string "strong.\p"
	.string "But you should be able to fight and\n"
	.string "pass them without a lot of grinding.$"

Pokescape01_EventScript_Swimmer12_Text_1:
	.string "I heard their specialty is grass and\n"
	.string "electric type moves. But what do I\l"
	.string "know?$"

Pokescape01_EventScript_PokecenterSign_Text_0:
	.string "IMPORTANT INFORMATION:\p"
	.string "1.) This game is featuring gen 5\n"
	.string "movesets for any Pokemon you control\l"
	.string "yourself.\p"
	.string "2.) It is not required to grind multiple\n"
	.string "levels to win any of the fights.\p"
	.string "3.) All items are there for a reason.\n"
	.string "Think twice before using them.\p"
	.string "4.) There are no invisible items or\n"
	.string "messages hidden on the ground. Don't\l"
	.string "waste your time hitting the A button\l"
	.string "throughout the whole overworld.$"

Pokescape01_EventScript_Building01Sign_Text_0:
	.string "This ROM hack was made by wiz1989.\l"
	.string "Great work, you've made it!$"

Pokescape01_EventScript_SignGrass_Text_0:
	.string "Two species are typically found here.$"

Pokescape01_EventScript_SignGrass_Text_1:
	.string "Girafarig, the two brain pokemon.\p"
	.string "Watch out, these are brilliant thieves!$"

Pokescape01_EventScript_SignGrass_Text_2:
	.string "Scyther, the mantis pokemon.\p"
	.string "With its sharp scythes it holds the\n"
	.string "secret to even cutting bushes.$"

Pokescape01_EventScript_PokecenterTriggers_Text_0:
	.string "Welcome, to Pokescape, the Pokémon\n"
	.string "Escape Challenge.\p"
	.string "The goal is to reach the house on the\n"
	.string "left side of this map.$"

Pokescape01_EventScript_PokecenterTriggers_Text_1:
	.string "You will need to develop unique tactics\n"
	.string "to battle your opponents and make the\l"
	.string "right decisions based on all\l"
	.string "information available.$"

Pokescape01_EventScript_PokecenterTriggers_Text_2:
	.string "If you are stuck you can approach the\n"
	.string "Game Master in the Pokecenter for\l"
	.string "help.\p"
	.string "More details can be found on the sign\n"
	.string "next to its entrance.$"

Pokescape01_EventScript_PokecenterTriggers_Text_3:
	.string "This challenge can be completed\n"
	.string "without any savegame resets.\p"
	.string "Worst case is you have to approach the\n"
	.string "Game Master to continue.$"

Pokescape01_EventScript_PokecenterTriggers_Text_4:
	.string "There are two game modes:\n"
	.string "REGULAR MODE and HONOR MODE.\p"
	.string "HONOR MODE will add penalty time to your\n"
	.string "game clock everytime you restart the\l"
	.string "game from a savefile.\l"
	.string "REGULAR mode will not do this.$"

Pokescape01_EventScript_PokecenterTriggers_Text_5:
	.string "The first reset will cost you 15min, the\n"
	.string "second 30min, the third 45min...\l"
	.string "...you get the idea.\p"
	.string "Which mode do you want to play with?$"

Pokescape01_EventScript_PokecenterTriggers_Text_6:
	.string "Oh, you don't have what it takes?\p"
	.string "It's okay though, at least you are\n"
	.string "honest.$"

Pokescape01_EventScript_PokecenterTriggers_Text_7:
	.string "What an honorable Pokémon trainer you\n"
	.string "are!$"

Pokescape01_EventScript_PokecenterTriggers_Text_8:
	.string "Please enter your name next.$"

Pokescape01_EventScript_PokecenterTriggers_Text_9:
	.string "So your name is {PLAYER}?$"

Pokescape01_EventScript_PokecenterTriggers_Text_10:
	.string "Good luck! Your play time starts NOW.$"

Pokescape01_EventScript_TriggerLittleGirl_Text_0:
	.string "Eek! Your Scyther looks so scary.\p"
	.string "Please don't bring it up here. I just\n"
	.string "can't stand any more bugs.$"

Pokescape01_EventScript_ItemMasterBall_Text_0:
	.string "You found a lost Master Ball on the\n"
	.string "ground.\p"
	.string "Make sure to make good use of it!$"

Pokescape01_EventScript_AppleTree_Text_0:
	.string "{PLAYER} found a Sweet Apple in the\n"
	.string "tree.$"

Pokescape01_EventScript_AppleTree_Text_1:
	.string "The apple hangs so high. You should\n"
	.string "bring someone who is able to reach up\l"
	.string "high in the tree.$"

Pokescape01_EventScript_AppleTree_Text_2:
	.string "There is an apple growing in the tree.\n"
	.string "You should go catch more Pokemon and\l"
	.string "return later to pick it.$"

Pokescape01_EventScript_AppleTree_Text_3:
	.string "There's nothing to find in the tree.$"

Pokescape01_EventScript_LittleGirl15_Text_0:
	.string "I'm too scared to get off from here...\p"
	.string "Mosquitoes tried to bite me in the\n"
	.string "grass down there.$"

Pokescape01_EventScript_Geodude_Text_0:
	.string "Geodude is tired of fighting.$"

Pokescape01_EventScript_Battle01_Text_0:
	.string "I'll blow you away!$"

Pokescape01_EventScript_Battle01_Text_1:
	.string "I'm blown away!$"

Pokescape01_EventScript_Battle01_Text_2:
	.string "What a day! First I lost an item and now\n"
	.string "I lost a fight.$"

Pokescape01_EventScript_BattleDouble02_Text_0:
	.string "Mom said we are too young, but we are\n"
	.string "already grown up!$"

Pokescape01_EventScript_BattleDouble02_Text_1:
	.string "Mommy!!!$"

Pokescape01_EventScript_BattleDouble02_Text_2:
	.string "I don't wanna play with my Wooper\n"
	.string "anymore. Can I trade it for your\l"
	.string "Makuhita?$"

Pokescape01_EventScript_BattleDouble02_Text_3:
	.string "{PLAYER} traded Wooper for Makuhita.$"

Pokescape01_EventScript_BattleDouble02_Text_4:
	.string "Have you heard? Nurse Joy is well again!$"

Pokescape01_EventScript_BattleDouble02_Text_5:
	.string "Don't like yours anyway.$"

Pokescape01_EventScript_BattleDouble02_Text_6:
	.string "I don't wanna play with my Wooper\n"
	.string "anymore. Can I trade it for your\l"
	.string "Hariyama?$"

Pokescape01_EventScript_BattleDouble02_Text_7:
	.string "{PLAYER} traded Wooper for Hariyama.$"

Pokescape01_EventScript_BattleDouble02_Text_8:
	.string "Wooper is so weak! I'd rather wanna\n"
	.string "have a fighting type.$"

Pokescape01_EventScript_BattleDouble03_Text_0:
	.string "Hey there, we found that strange\n"
	.string "Pokemon.\p"
	.string "Looks like it swallowed a special stone\n"
	.string "or something...\l"
	.string "...$"

Pokescape01_EventScript_BattleDouble03_Text_1:
	.string "Go ahead, you're almost there.$"

Pokescape01_Pokecenter_EventScript_Picture01_Text_0:
	.string "Solar Beam, Sweet Scent, Synthesis,\n"
	.string "Protect$"

Pokescape01_Pokecenter_EventScript_Picture02_Text_0:
	.string "Misty Explosion$"

Pokescape01_Pokecenter_EventScript_Nurse_Text_0:
	.string "...cough...sniff...$"

Pokescape01_Pokecenter_EventScript_Nurse_Text_1:
	.string "I am sorry I caught a flu. I have to\n"
	.string "take care of myself first.\l"
	.string "...cough...sniff...$"

Pokescape01_Pokecenter_EventScript_Boy_Text_0:
	.string "Nurse Joy sounds a little sick. I hope\n"
	.string "she will get well soon!$"

Pokescape01_Pokecenter_EventScript_Boy_Text_1:
	.string "Oh no! Who takes care of the Pokemons\n"
	.string "now?$"

Pokescape01_Pokecenter_EventScript_Boy_Text_2:
	.string "Woohoo, nurse Joy is feeling well again!$"

Pokescape01_Pokecenter_EventScript_Gentleman_Text_0:
	.string "I am the game master.\p"
	.string "I will give you helpful advice for each\n"
	.string "situation, but it adds an additional\l"
	.string "30min to your play clock.$"

Pokescape01_Pokecenter_EventScript_Gentleman_Text_1:
	.string "Do you want me to give you a hint?$"

Pokescape01_Pokecenter_EventScript_Gentleman_Text_2:
	.string "You still have Pokemon in your PC. I can\n"
	.string "only give you tips when it's empty.\p"
	.string "Of course, you won't be charged 30\n"
	.string "minutes this time.$"

Pokescape01_Pokecenter_EventScript_Gentleman_Text_3:
	.string "Oh you are still accompanied by Wooper?\p"
	.string "You should think about evolving it!\n"
	.string "Quagsire can do stuff that Wooper\l"
	.string "can't.$"

Pokescape01_Pokecenter_EventScript_Gentleman_Text_4:
	.string "{PLAYER}: Good bye, Gardevoir.$"

Pokescape01_Pokecenter_EventScript_Gentleman_Text_5:
	.string "GAME MASTER: I also took all items you\n"
	.string "might have acquired from Kirlia before.$"

Pokescape01_Pokecenter_EventScript_Gentleman_Text_6:
	.string "Your Girafarig and Quagsire are a great\n"
	.string "tag team!\p"
	.string "Played right Quagsire can become quite\n"
	.string "invincible against some Pokemon.\p"
	.string "However, you should not try to defeat\n"
	.string "the couple on the hill. But their\l"
	.string "Venusaur is hiding something very\l"
	.string "interesting for you.$"

Pokescape01_Pokecenter_EventScript_Gentleman_Text_7:
	.string "You are almost there.\p"
	.string "Try sneaking past the couple by having\n"
	.string "only one Pokemon in your party.$"

Pokescape01_Pokecenter_EventScript_Gentleman_Text_8:
	.string "{PLAYER}: Good bye, Scyther.$"

Pokescape01_Pokecenter_EventScript_Gentleman_Text_9:
	.string "GAME MASTER: I also took all items you\n"
	.string "might have acquired through catching\l"
	.string "Scyther.$"

Pokescape01_Pokecenter_EventScript_Gentleman_Text_10:
	.string "Come back whenever you need me.$"

Pokescape01_Pokecenter_EventScript_Gentleman_Text_11:
	.string "Hey, don't try to trick me for additional\n"
	.string "rare candies!\p"
	.string "I will still charge you 30min for this.$"

Pokescape01_Pokecenter_EventScript_Gentleman_Text_12:
	.string "I am sorry, but I currently have no\n"
	.string "hints to give to you.\p"
	.string "Try proceeding by looking for hidden\n"
	.string "and held items, catching Pokemon,\l"
	.string "talking to NPCs and winning battles.\p"
	.string "Of course, you won't be charged 30\n"
	.string "minutes this time.$"

Pokescape01_Pokecenter_EventScript_Gentleman_Text_13:
	.string "\p"
	.string "...\p"
	.string "I had already given this hint to you\n"
	.string "before.\l"
	.string "I guess it's fair if I don't charge you\l"
	.string "any more time for it.$"

Pokescape01_Pokecenter_EventScript_Scientist_Text_0:
	.string "You have so little pokemon in your\n"
	.string "party. I'm not talking to such a\l"
	.string "wannabe.$"

Pokescape01_Pokecenter_EventScript_Scientist_Text_1:
	.string "Your Yamask seems to be very stubborn.\p"
	.string "It is not interested in learning any new\n"
	.string "moves.\p"
	.string "How sad.$"

Pokescape01_Pokecenter_EventScript_Scientist_Text_2:
	.string "Did you know that some species can\n"
	.string "have access to completely new moves\l"
	.string "after evolving?\p"
	.string "There is so much to learn about\n"
	.string "Pokemon.$"

Pokescape01_House_EventScript_Pikachu_Text_0:
	.string "...Pika...$"

Text_NotEnoughMons::
	.string "You don't have enough Pokemons to\n"
	.string "fight us. Poor boy!$"

Text_TipCheckPC::
	.string "Your team is too small. You should check\n"
	.string "out that PC over there.\p"
	.string "Also look out for some items in there.$"

Text_TipRareCandy::
	.string "Oh, you have already used your Rare\n"
	.string "Candy?\p"
	.string "You should be a little more thoughtful\n"
	.string "about spending stuff!\p"
	.string "Here, I can give you another one. But\n"
	.string "make sure to keep it for now!$"

Text_TipFirstFight::
	.string "Your exquisite team could probably\n"
	.string "release a toxic storm at the opponent.\p"
	.string "Makuhita is the key to do so. You could\n"
	.string "do some sparring with Geodude outside.$"

Text_TipRareCandyRevive::
	.string "Nurse Joy is sick and you have already\n"
	.string "used your Rare Candy?\p"
	.string "You should be a little more thoughtful\n"
	.string "about spending stuff!\p"
	.string "Here, I can give you another one.$"

Text_TipRareCandyUse::
	.string "Nurse Joy is sick and you are looking\n"
	.string "for a way to revive your Pokemon?\p"
	.string "You should go check the medicine box in\n"
	.string "your bag.$"

Text_TipMasterBall::
	.string "People often get excited close to the\n"
	.string "Pokemon Center.\p"
	.string "Sometimes they even drop stuff around\n"
	.string "there.$"

Text_TipScyther::
	.string "Nice Scyther you got there! I just\n"
	.string "don't think catching it was a good idea.\p"
	.string "Let me take it and give you back\n"
	.string "another Master Ball.$"

Text_TipCatch::
	.string "Oh, you found a Master Ball?\p"
	.string "You should go and catch another\n"
	.string "Pokemon for your party.$"

Text_TipHMCut::
	.string "You are looking for HM Cut? I heard\n"
	.string "there are Scythers in the area holding\l"
	.string "on to it.\p"
	.string "Or has your Girafarig already stolen it?$"

Text_TipKirlia::
	.string "You are looking for some food for\n"
	.string "Kirlia?\p"
	.string "There's a unique tree in the woods that\n"
	.string "should provide some tasty fruits.$"

Text_TipGardevoir::
	.string "Oh your Kirlia evolved into Gardevoir?\p"
	.string "I don't think that's helpful. It should\n"
	.string "have kept holding its Everstone.\p"
	.string "You don't want it to evolve\n"
	.string "uncontrolledly.\p"
	.string "Let me take your Gardevoir and give you\n"
	.string "a Kirlia back for it.$"

Text_Finale_regular::
	.string "Congratulations {PLAYER}!\p"
	.string "You have completed the challenge. Well\n"
	.string "done!\p"
	.string "Your final time is\n"
	.string "{STR_VAR_1}:{STR_VAR_2}:{STR_VAR_3}\l"
	.string "in REGULAR MODE.$"

Text_Finale_honor::
	.string "Congratulations {PLAYER}!\p"
	.string "You have completed the challenge.\l"
	.string "Well done!\p"
	.string "Your final time is\n"
	.string "{STR_VAR_1}:{STR_VAR_2}:{STR_VAR_3}\l"
	.string "in HONOR MODE.$"
