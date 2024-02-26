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
	end

OnResume_2:
	givemon SPECIES_MAKUHITA, 15
	givemonpc SPECIES_YAMASK, 20, ITEM_RARE_CANDY, 7, 19
	setinitialmovesPC MOVE_HEX, MOVE_TRICK_ROOM, MOVE_TOXIC_SPIKES, MOVE_PROTECT
	setflag FLAG_SYS_POKEMON_GET
	addpcitem ITEM_TM_DIG, 1
	setvar VAR_LITTLEROOT_TOWN_STATE, 1
	setrespawn HEAL_LOCATION_POKESCAPE01
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
	setflag FLAG_SYS_POKEDEX_GET
	setflag FLAG_SYS_NATIONAL_DEX
	special EnableNationalPokedex
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
	special ChangePlayerName
	waitmessage
	msgbox Pokescape01_EventScript_PokecenterTriggers_Text_5, MSGBOX_YESNO
Pokescape01_EventScript_PokecenterTriggers_5:
	compare VAR_RESULT, NO
	goto_if_eq Pokescape01_EventScript_PokecenterTriggers_6
	msgbox Pokescape01_EventScript_PokecenterTriggers_Text_6, MSGBOX_AUTOCLOSE
	waitmessage
	special RestartPlayTimer
	setvar VAR_UNUSED_0x408B, 1
	releaseall
	goto Pokescape01_EventScript_PokecenterTriggers_1

Pokescape01_EventScript_PokecenterTriggers_6:
	special ChangePlayerName
	waitmessage
	msgbox Pokescape01_EventScript_PokecenterTriggers_Text_5, MSGBOX_YESNO
	goto Pokescape01_EventScript_PokecenterTriggers_5


Pokescape01_EventScript_TriggerLittleGirl::
	lockall
	setvar VAR_BATTLE_TURN, 0
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
	goto_if_set FLAG_P01_GIRAFARIG, Pokescape01_EventScript_AppleTree_5
	goto_if_set FLAG_P01_SCYTHER, Pokescape01_EventScript_AppleTree_6
	msgbox Pokescape01_EventScript_AppleTree_Text_2
	goto Pokescape01_EventScript_AppleTree_1

Pokescape01_EventScript_AppleTree_5:
	msgbox Pokescape01_EventScript_AppleTree_Text_0
	giveitem ITEM_SWEET_APPLE, 1
	setvar VAR_UNUSED_0x40F7, 1
	goto Pokescape01_EventScript_AppleTree_1

Pokescape01_EventScript_AppleTree_6:
	msgbox Pokescape01_EventScript_AppleTree_Text_1
	goto Pokescape01_EventScript_AppleTree_1


Pokescape01_EventScript_LittleGirl15::
	lockall
	faceplayer
	goto_if_unset FLAG_P01_GIRAFARIG, Pokescape01_EventScript_LittleGirl15_2
	msgbox Pokescape01_EventScript_LittleGirl15_Text_1
Pokescape01_EventScript_LittleGirl15_1:
	waitmessage
	releaseall
	end

Pokescape01_EventScript_LittleGirl15_2:
	msgbox Pokescape01_EventScript_LittleGirl15_Text_0
	goto Pokescape01_EventScript_LittleGirl15_1


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
	goto_if_set FLAG_P01_MASTER_BALL, Pokescape01_EventScript_Battle01_2
	msgbox Pokescape01_EventScript_Battle01_Text_4
Pokescape01_EventScript_Battle01_1:
	waitmessage
	release
	end

Pokescape01_EventScript_Battle01_2:
	msgbox Pokescape01_EventScript_Battle01_Text_2, MSGBOX_AUTOCLOSE
	msgbox Pokescape01_EventScript_Battle01_Text_3, MSGBOX_AUTOCLOSE
	goto Pokescape01_EventScript_Battle01_1


Pokescape01_EventScript_BattleDouble02::
	trainerbattle_double TRAINER_POKESCAPE01_02, Pokescape01_EventScript_BattleDouble02_Text_0, Pokescape01_EventScript_BattleDouble02_Text_1, Text_NotEnoughMons
	lockall
	goto_if_unset FLAG_UNUSED_0x95E, Pokescape01_EventScript_BattleDouble02_2
	msgbox Pokescape01_EventScript_BattleDouble02_Text_4
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
	trainerbattle_double TRAINER_POKESCAPE01_03, Pokescape01_EventScript_BattleDouble03_Text_0, Pokescape01_EventScript_BattleDouble03_Text_1, Text_NotEnoughMons
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
	clearflag FLAG_P01_NO_ADVICE
	faceplayer
	msgbox Pokescape01_Pokecenter_EventScript_Gentleman_Text_0
	waitmessage
	msgbox Pokescape01_Pokecenter_EventScript_Gentleman_Text_1, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Pokescape01_Pokecenter_EventScript_Gentleman_2
	msgbox Pokescape01_Pokecenter_EventScript_Gentleman_Text_11
	release
	end

Pokescape01_Pokecenter_EventScript_Gentleman_1:
	waitmessage
	goto_if_set FLAG_P01_ADD30MIN, Pokescape01_Pokecenter_EventScript_Gentleman_6
	goto_if_set FLAG_P01_DONT_CHEAT, Pokescape01_Pokecenter_EventScript_Gentleman_15
	goto_if_set FLAG_P01_GIVE_ADVICE, Pokescape01_Pokecenter_EventScript_Gentleman_23
	goto_if_unset FLAG_P01_NO_ADVICE, Pokescape01_Pokecenter_EventScript_Gentleman_29
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
	goto_if 1, Pokescape01_Pokecenter_EventScript_Gentleman_34
Pokescape01_Pokecenter_EventScript_Gentleman_31:
	checkpartymon SPECIES_WOOPER
	compare VAR_RESULT, 0
	goto_if_ne Pokescape01_Pokecenter_EventScript_Gentleman_42
	clearflag FLAG_P01_GOTWOOPER
Pokescape01_Pokecenter_EventScript_Gentleman_41:
	checkpartymon SPECIES_QUAGSIRE
	compare VAR_RESULT, 0
	goto_if_ne Pokescape01_Pokecenter_EventScript_Gentleman_55
	clearflag FLAG_P01_GOTQUAGSIRE
Pokescape01_Pokecenter_EventScript_Gentleman_54:
	checkpartymon SPECIES_GALLADE
	compare VAR_RESULT, 0
	goto_if_ne Pokescape01_Pokecenter_EventScript_Gentleman_72
	clearflag FLAG_P01_GOTGALLADE
Pokescape01_Pokecenter_EventScript_Gentleman_71:
	checkpartymon SPECIES_GARDEVOIR
	compare VAR_RESULT, 0
	goto_if_ne Pokescape01_Pokecenter_EventScript_Gentleman_82
	clearflag FLAG_P01_GOTGARDEVOIR
Pokescape01_Pokecenter_EventScript_Gentleman_81:
	checkitem ITEM_HM_CUT
	compare VAR_RESULT, 0
	goto_if_ne Pokescape01_Pokecenter_EventScript_Gentleman_86
	clearflag FLAG_P01_HM_CUT
Pokescape01_Pokecenter_EventScript_Gentleman_85:
	goto_if_set FLAG_P01_GOTKIRLIA, Pokescape01_Pokecenter_EventScript_Gentleman_91
Pokescape01_Pokecenter_EventScript_Gentleman_90:
	checktrainerflag TRAINER_POKESCAPE01_02
	goto_if 1, Pokescape01_Pokecenter_EventScript_Gentleman_99
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
	msgbox Pokescape01_Pokecenter_EventScript_Gentleman_Text_12
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
	setflag FLAG_P01_NO_ADVICE
	goto Pokescape01_Pokecenter_EventScript_Gentleman_1

Pokescape01_Pokecenter_EventScript_Gentleman_23:
	msgbox Pokescape01_Pokecenter_EventScript_Gentleman_Text_13
	waitmessage
	goto Pokescape01_Pokecenter_EventScript_Gentleman_5

Pokescape01_Pokecenter_EventScript_Gentleman_27:
	getpartysize
	compare VAR_RESULT, 1
	goto_if_le Pokescape01_Pokecenter_EventScript_Gentleman_38
	getpartymonlevel SPECIES_MAKUHITA
	compare VAR_RESULT, 15
	goto_if_gt Pokescape01_Pokecenter_EventScript_Gentleman_51
	goto_if_unset FLAG_P01_Hint04, Pokescape01_Pokecenter_EventScript_Gentleman_69
Pokescape01_Pokecenter_EventScript_Gentleman_68:
	msgbox Text_TipFirstFight
	clearflag FLAG_P01_GIVE_ADVICE
	goto Pokescape01_Pokecenter_EventScript_Gentleman_26

Pokescape01_Pokecenter_EventScript_Gentleman_29:
	msgbox Pokescape01_Pokecenter_EventScript_Gentleman_Text_14
	waitmessage
	goto Pokescape01_Pokecenter_EventScript_Gentleman_5

Pokescape01_Pokecenter_EventScript_Gentleman_32:
	goto_if_set FLAG_P01_RARE_CANDY, Pokescape01_Pokecenter_EventScript_Gentleman_45
	goto_if_unset FLAG_P01_Hint06, Pokescape01_Pokecenter_EventScript_Gentleman_63
Pokescape01_Pokecenter_EventScript_Gentleman_62:
	msgbox Text_TipRareCandyUse
	clearflag FLAG_P01_GIVE_ADVICE
	goto Pokescape01_Pokecenter_EventScript_Gentleman_31

Pokescape01_Pokecenter_EventScript_Gentleman_33:
	compare VAR_RESULT, 0
	goto_if_ne Pokescape01_Pokecenter_EventScript_Gentleman_32
	goto Pokescape01_Pokecenter_EventScript_Gentleman_31

Pokescape01_Pokecenter_EventScript_Gentleman_34:
	checktrainerflag TRAINER_POKESCAPE01_02
	goto_if 0, Pokescape01_Pokecenter_EventScript_Gentleman_33
	goto Pokescape01_Pokecenter_EventScript_Gentleman_31

Pokescape01_Pokecenter_EventScript_Gentleman_38:
	goto_if_unset FLAG_P01_Hint02, Pokescape01_Pokecenter_EventScript_Gentleman_49
Pokescape01_Pokecenter_EventScript_Gentleman_48:
	msgbox Text_TipCheckPC
	clearflag FLAG_P01_GIVE_ADVICE
	goto Pokescape01_Pokecenter_EventScript_Gentleman_26

Pokescape01_Pokecenter_EventScript_Gentleman_42:
	setflag FLAG_P01_GOTWOOPER
	goto Pokescape01_Pokecenter_EventScript_Gentleman_41

Pokescape01_Pokecenter_EventScript_Gentleman_45:
	goto_if_unset FLAG_P01_Hint05, Pokescape01_Pokecenter_EventScript_Gentleman_59
	setflag FLAG_P01_DONT_CHEAT
Pokescape01_Pokecenter_EventScript_Gentleman_58:
	msgbox Text_TipRareCandyRevive
	giveitem ITEM_RARE_CANDY, 1
	clearflag FLAG_P01_RARE_CANDY
	clearflag FLAG_P01_GIVE_ADVICE
	goto Pokescape01_Pokecenter_EventScript_Gentleman_31

Pokescape01_Pokecenter_EventScript_Gentleman_49:
	setflag FLAG_P01_Hint02
	setflag FLAG_P01_ADD30MIN
	goto Pokescape01_Pokecenter_EventScript_Gentleman_48

Pokescape01_Pokecenter_EventScript_Gentleman_51:
	checkpartymove MOVE_WHIRLWIND
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq Pokescape01_Pokecenter_EventScript_Gentleman_65
	goto_if_unset FLAG_P01_Hint04, Pokescape01_Pokecenter_EventScript_Gentleman_79
Pokescape01_Pokecenter_EventScript_Gentleman_78:
	msgbox Text_TipFirstFight
	clearflag FLAG_P01_GIVE_ADVICE
	goto Pokescape01_Pokecenter_EventScript_Gentleman_26

Pokescape01_Pokecenter_EventScript_Gentleman_55:
	setflag FLAG_P01_GOTQUAGSIRE
	goto Pokescape01_Pokecenter_EventScript_Gentleman_54

Pokescape01_Pokecenter_EventScript_Gentleman_59:
	setflag FLAG_P01_Hint05
	setflag FLAG_P01_ADD30MIN
	goto Pokescape01_Pokecenter_EventScript_Gentleman_58

Pokescape01_Pokecenter_EventScript_Gentleman_63:
	setflag FLAG_P01_Hint06
	setflag FLAG_P01_ADD30MIN
	goto Pokescape01_Pokecenter_EventScript_Gentleman_62

Pokescape01_Pokecenter_EventScript_Gentleman_65:
	goto_if_unset FLAG_P01_Hint16, Pokescape01_Pokecenter_EventScript_Gentleman_76
Pokescape01_Pokecenter_EventScript_Gentleman_75:
	clearflag FLAG_P01_GIVE_ADVICE
	msgbox Pokescape01_Pokecenter_EventScript_Gentleman_Text_3
	getpartymonslot SPECIES_MAKUHITA
	special DeletePartyMon
	givemon SPECIES_MAKUHITA, 15
	goto Pokescape01_Pokecenter_EventScript_Gentleman_26

Pokescape01_Pokecenter_EventScript_Gentleman_69:
	setflag FLAG_P01_Hint04
	setflag FLAG_P01_ADD30MIN
	goto Pokescape01_Pokecenter_EventScript_Gentleman_68

Pokescape01_Pokecenter_EventScript_Gentleman_72:
	setflag FLAG_P01_GOTGALLADE
	goto Pokescape01_Pokecenter_EventScript_Gentleman_71

Pokescape01_Pokecenter_EventScript_Gentleman_76:
	setflag FLAG_P01_Hint16
	setflag FLAG_P01_ADD30MIN
	goto Pokescape01_Pokecenter_EventScript_Gentleman_75

Pokescape01_Pokecenter_EventScript_Gentleman_79:
	setflag FLAG_P01_Hint04
	setflag FLAG_P01_ADD30MIN
	goto Pokescape01_Pokecenter_EventScript_Gentleman_78

Pokescape01_Pokecenter_EventScript_Gentleman_82:
	setflag FLAG_P01_GOTGARDEVOIR
	goto Pokescape01_Pokecenter_EventScript_Gentleman_81

Pokescape01_Pokecenter_EventScript_Gentleman_86:
	setflag FLAG_P01_HM_CUT
	goto Pokescape01_Pokecenter_EventScript_Gentleman_85

Pokescape01_Pokecenter_EventScript_Gentleman_89:
	goto_if_set FLAG_P01_GOTWOOPER, Pokescape01_Pokecenter_EventScript_Gentleman_94
	goto_if_set FLAG_P01_GOTGARDEVOIR, Pokescape01_Pokecenter_EventScript_Gentleman_95
	goto_if_set FLAG_P01_GOTQUAGSIRE, Pokescape01_Pokecenter_EventScript_Gentleman_110
Pokescape01_Pokecenter_EventScript_Gentleman_109:
	goto_if_set FLAG_P01_GOTGALLADE, Pokescape01_Pokecenter_EventScript_Gentleman_108
	goto Pokescape01_Pokecenter_EventScript_Gentleman_1

Pokescape01_Pokecenter_EventScript_Gentleman_91:
	goto_if_set FLAG_P01_HM_CUT, Pokescape01_Pokecenter_EventScript_Gentleman_89
	goto Pokescape01_Pokecenter_EventScript_Gentleman_90

Pokescape01_Pokecenter_EventScript_Gentleman_94:
	goto_if_unset FLAG_P01_Hint07, Pokescape01_Pokecenter_EventScript_Gentleman_102
Pokescape01_Pokecenter_EventScript_Gentleman_101:
	msgbox Pokescape01_Pokecenter_EventScript_Gentleman_Text_4
	clearflag FLAG_P01_GIVE_ADVICE
	goto Pokescape01_Pokecenter_EventScript_Gentleman_1

Pokescape01_Pokecenter_EventScript_Gentleman_95:
	goto_if_unset FLAG_P01_Hint08, Pokescape01_Pokecenter_EventScript_Gentleman_105
Pokescape01_Pokecenter_EventScript_Gentleman_104:
	msgbox Text_TipGardevoir
	waitmessage
	clearflag FLAG_P01_GIVE_ADVICE
	getpartymonslot SPECIES_GARDEVOIR
	special DeletePartyMon
	msgbox Pokescape01_Pokecenter_EventScript_Gentleman_Text_5
	givemon SPECIES_KIRLIA, 20, ITEM_EVERSTONE
	checkitem ITEM_EVERSTONE
	compare VAR_RESULT, TRUE
	goto_if_eq Pokescape01_Pokecenter_EventScript_Gentleman_116
	goto Pokescape01_Pokecenter_EventScript_Gentleman_1

Pokescape01_Pokecenter_EventScript_Gentleman_99:
	goto_if_unset FLAG_P01_MASTER_BALL, Pokescape01_Pokecenter_EventScript_Gentleman_113
	goto_if_set FLAG_P01_SCYTHER, Pokescape01_Pokecenter_EventScript_Gentleman_133
Pokescape01_Pokecenter_EventScript_Gentleman_131:
	goto_if_unset FLAG_P01_SCYTHER, Pokescape01_Pokecenter_EventScript_Gentleman_130
Pokescape01_Pokecenter_EventScript_Gentleman_129:
	checkitem ITEM_HM_CUT
	compare VAR_RESULT, FALSE
	goto_if_eq Pokescape01_Pokecenter_EventScript_Gentleman_142
	goto_if_set FLAG_P01_KIRLIA, Pokescape01_Pokecenter_EventScript_Gentleman_144
	goto Pokescape01_Pokecenter_EventScript_Gentleman_1

Pokescape01_Pokecenter_EventScript_Gentleman_102:
	setflag FLAG_P01_Hint07
	setflag FLAG_P01_ADD30MIN
	goto Pokescape01_Pokecenter_EventScript_Gentleman_101

Pokescape01_Pokecenter_EventScript_Gentleman_105:
	setflag FLAG_P01_Hint08
	setflag FLAG_P01_ADD30MIN
	goto Pokescape01_Pokecenter_EventScript_Gentleman_104

Pokescape01_Pokecenter_EventScript_Gentleman_107:
	goto_if_unset FLAG_P01_Hint09, Pokescape01_Pokecenter_EventScript_Gentleman_119
Pokescape01_Pokecenter_EventScript_Gentleman_118:
	msgbox Pokescape01_Pokecenter_EventScript_Gentleman_Text_7
	clearflag FLAG_P01_GIVE_ADVICE
	goto Pokescape01_Pokecenter_EventScript_Gentleman_1

Pokescape01_Pokecenter_EventScript_Gentleman_108:
	goto_if_unset FLAG_P01_Hint10, Pokescape01_Pokecenter_EventScript_Gentleman_122
Pokescape01_Pokecenter_EventScript_Gentleman_121:
	msgbox Pokescape01_Pokecenter_EventScript_Gentleman_Text_8
	clearflag FLAG_P01_GIVE_ADVICE
	goto Pokescape01_Pokecenter_EventScript_Gentleman_1

Pokescape01_Pokecenter_EventScript_Gentleman_110:
	goto_if_unset FLAG_P01_GOTGALLADE, Pokescape01_Pokecenter_EventScript_Gentleman_107
	goto Pokescape01_Pokecenter_EventScript_Gentleman_109

Pokescape01_Pokecenter_EventScript_Gentleman_113:
	goto_if_unset FLAG_P01_Hint11, Pokescape01_Pokecenter_EventScript_Gentleman_125
Pokescape01_Pokecenter_EventScript_Gentleman_124:
	msgbox Text_TipMasterBall
	clearflag FLAG_P01_GIVE_ADVICE
	goto Pokescape01_Pokecenter_EventScript_Gentleman_1

Pokescape01_Pokecenter_EventScript_Gentleman_116:
	waitmessage
	removeitem ITEM_EVERSTONE
	msgbox Pokescape01_Pokecenter_EventScript_Gentleman_Text_6
	goto Pokescape01_Pokecenter_EventScript_Gentleman_1

Pokescape01_Pokecenter_EventScript_Gentleman_119:
	setflag FLAG_P01_Hint09
	setflag FLAG_P01_ADD30MIN
	goto Pokescape01_Pokecenter_EventScript_Gentleman_118

Pokescape01_Pokecenter_EventScript_Gentleman_122:
	setflag FLAG_P01_Hint10
	setflag FLAG_P01_ADD30MIN
	goto Pokescape01_Pokecenter_EventScript_Gentleman_121

Pokescape01_Pokecenter_EventScript_Gentleman_125:
	setflag FLAG_P01_Hint11
	setflag FLAG_P01_ADD30MIN
	goto Pokescape01_Pokecenter_EventScript_Gentleman_124

Pokescape01_Pokecenter_EventScript_Gentleman_127:
	goto_if_unset FLAG_P01_Hint12, Pokescape01_Pokecenter_EventScript_Gentleman_137
Pokescape01_Pokecenter_EventScript_Gentleman_136:
	msgbox Text_TipScyther
	waitmessage
	clearflag FLAG_P01_GIVE_ADVICE
	getpartymonslot SPECIES_SCYTHER
	special DeletePartyMon
	giveitem ITEM_MASTER_BALL, 1
	msgbox Pokescape01_Pokecenter_EventScript_Gentleman_Text_9
	checkitem ITEM_HM_CUT
	compare VAR_RESULT, TRUE
	goto_if_eq Pokescape01_Pokecenter_EventScript_Gentleman_149
Pokescape01_Pokecenter_EventScript_Gentleman_148:
	clearflag FLAG_P01_SCYTHER
	goto Pokescape01_Pokecenter_EventScript_Gentleman_1

Pokescape01_Pokecenter_EventScript_Gentleman_128:
	goto_if_unset FLAG_P01_Hint13, Pokescape01_Pokecenter_EventScript_Gentleman_140
Pokescape01_Pokecenter_EventScript_Gentleman_139:
	msgbox Text_TipCatch
	clearflag FLAG_P01_GIVE_ADVICE
	goto Pokescape01_Pokecenter_EventScript_Gentleman_1

Pokescape01_Pokecenter_EventScript_Gentleman_130:
	goto_if_unset FLAG_P01_GIRAFARIG, Pokescape01_Pokecenter_EventScript_Gentleman_128
	goto Pokescape01_Pokecenter_EventScript_Gentleman_129

Pokescape01_Pokecenter_EventScript_Gentleman_133:
	goto_if_unset FLAG_P01_GIRAFARIG, Pokescape01_Pokecenter_EventScript_Gentleman_127
	goto Pokescape01_Pokecenter_EventScript_Gentleman_131

Pokescape01_Pokecenter_EventScript_Gentleman_137:
	setflag FLAG_P01_Hint12
	setflag FLAG_P01_ADD30MIN
	goto Pokescape01_Pokecenter_EventScript_Gentleman_136

Pokescape01_Pokecenter_EventScript_Gentleman_140:
	setflag FLAG_P01_Hint13
	setflag FLAG_P01_ADD30MIN
	goto Pokescape01_Pokecenter_EventScript_Gentleman_139

Pokescape01_Pokecenter_EventScript_Gentleman_142:
	setorcopyvar VAR_0x8004, ITEM_HM_CUT
	specialvar VAR_RESULT, ItemisHeldInParty
	compare VAR_RESULT, FALSE
	goto_if_eq Pokescape01_Pokecenter_EventScript_Gentleman_151
	goto Pokescape01_Pokecenter_EventScript_Gentleman_1

Pokescape01_Pokecenter_EventScript_Gentleman_143:
	goto_if_unset FLAG_P01_Hint15, Pokescape01_Pokecenter_EventScript_Gentleman_154
Pokescape01_Pokecenter_EventScript_Gentleman_153:
	msgbox Text_TipKirlia
	clearflag FLAG_P01_GIVE_ADVICE
	goto Pokescape01_Pokecenter_EventScript_Gentleman_1

Pokescape01_Pokecenter_EventScript_Gentleman_144:
	compare VAR_UNUSED_0x40F7, 0
	goto_if_eq Pokescape01_Pokecenter_EventScript_Gentleman_143
	goto Pokescape01_Pokecenter_EventScript_Gentleman_1

Pokescape01_Pokecenter_EventScript_Gentleman_149:
	waitmessage
	clearflag FLAG_P01_HM_CUT
	removeitem ITEM_HM_CUT
	msgbox Pokescape01_Pokecenter_EventScript_Gentleman_Text_10
	goto Pokescape01_Pokecenter_EventScript_Gentleman_148

Pokescape01_Pokecenter_EventScript_Gentleman_151:
	goto_if_unset FLAG_P01_Hint14, Pokescape01_Pokecenter_EventScript_Gentleman_157
Pokescape01_Pokecenter_EventScript_Gentleman_156:
	msgbox Text_TipHMCut
	clearflag FLAG_P01_GIVE_ADVICE
	goto Pokescape01_Pokecenter_EventScript_Gentleman_1

Pokescape01_Pokecenter_EventScript_Gentleman_154:
	setflag FLAG_P01_Hint15
	setflag FLAG_P01_ADD30MIN
	goto Pokescape01_Pokecenter_EventScript_Gentleman_153

Pokescape01_Pokecenter_EventScript_Gentleman_157:
	setflag FLAG_P01_Hint14
	setflag FLAG_P01_ADD30MIN
	goto Pokescape01_Pokecenter_EventScript_Gentleman_156


Pokescape01_Pokecenter_EventScript_Scientist::
	lock
	faceplayer
	getpartysize
	compare VAR_RESULT, 1
	goto_if_le Pokescape01_Pokecenter_EventScript_Scientist_2
	goto_if_set FLAG_P01_GIRAFARIG, Pokescape01_Pokecenter_EventScript_Scientist_5
	goto_if_set FLAG_UNUSED_0x95E, Pokescape01_Pokecenter_EventScript_Scientist_6
	goto_if_set FLAG_P01_MASTER_BALL, Pokescape01_Pokecenter_EventScript_Scientist_6
	msgbox Pokescape01_Pokecenter_EventScript_Scientist_Text_3
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

Pokescape01_Pokecenter_EventScript_Scientist_6:
	msgbox Pokescape01_Pokecenter_EventScript_Scientist_Text_2
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
	.string "1.) This game is featuring gen 5 move\n"
	.string "LEARNSETS for any Pokémon you control\l"
	.string "yourself.\p"
	.string "2.) It is NOT required to grind MULTIPLE\n"
	.string "levels to win any of the fights.\p"
	.string "3.) All items are there for a reason.\n"
	.string "Think twice before using them.\p"
	.string "4.) Any potentially hidden items would\n"
	.string "have collision so you can't just walk\l"
	.string "over them without noticing.\l"
	.string "Spamming the A button throughout the\l"
	.string "whole overworld is therefore not\l"
	.string "necessary.\l"
	.string "5.) Wrong decisions can cause soft\l"
	.string "locks. However, these will always be\l"
	.string "fixed by the Game Master NPC.$"

Pokescape01_EventScript_Building01Sign_Text_0:
	.string "This ROM hack was made by wiz1989.\l"
	.string "Great work, you've made it!$"

Pokescape01_EventScript_SignGrass_Text_0:
	.string "Two species are typically found here.$"

Pokescape01_EventScript_SignGrass_Text_1:
	.string "Girafarig, the two brain Pokémon.\p"
	.string "Watch out, these are brilliant thieves!$"

Pokescape01_EventScript_SignGrass_Text_2:
	.string "Scyther, the mantis Pokémon.\p"
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
	.string "Please enter your name next.$"

Pokescape01_EventScript_PokecenterTriggers_Text_5:
	.string "So your name is {PLAYER}?$"

Pokescape01_EventScript_PokecenterTriggers_Text_6:
	.string "Good luck! Your play time starts NOW.$"

Pokescape01_EventScript_TriggerLittleGirl_Text_0:
	.string "Eek! Your Scyther looks so scary.\p"
	.string "Please don't bring it up here. I just\n"
	.string "can't stand any more bugs.$"

Pokescape01_EventScript_ItemMasterBall_Text_0:
	.string "You found a lost Master Ball lying right\n"
	.string "behind the Pokecenter.\p"
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
	.string "You should go catch more Pokémon and\l"
	.string "return later to pick it.$"

Pokescape01_EventScript_AppleTree_Text_3:
	.string "There's nothing to find in the tree.$"

Pokescape01_EventScript_LittleGirl15_Text_0:
	.string "I'm too scared to get off from here...\p"
	.string "Mosquitoes tried to bite me in the\n"
	.string "grass down there.$"

Pokescape01_EventScript_LittleGirl15_Text_1:
	.string "I think the bugs are gone by now. What a\n"
	.string "relief!\p"
	.string "By the way:\n"
	.string "Did you know that some Pokémon species\l"
	.string "can have access to completely new\l"
	.string "moves after evolving?\p"
	.string "Just like bugs are going through\n"
	.string "metamorphosis.\p"
	.string "Well...maybe bugs are more interesting\n"
	.string "than I thought.$"

Pokescape01_EventScript_Geodude_Text_0:
	.string "Geodude is tired of fighting.$"

Pokescape01_EventScript_Battle01_Text_0:
	.string "I'll blow you away!$"

Pokescape01_EventScript_Battle01_Text_1:
	.string "I'm blown away!$"

Pokescape01_EventScript_Battle01_Text_2:
	.string "You found my Master Ball?\p"
	.string "That's great, but you can keep it!$"

Pokescape01_EventScript_Battle01_Text_3:
	.string "My grandpa is building them in his\n"
	.string "garage.$"

Pokescape01_EventScript_Battle01_Text_4:
	.string "What a day! First I lost an item and now\n"
	.string "I lost a fight.\p"
	.string "I must have dropped it somewhere close\n"
	.string "by.\l"
	.string "Hopefully someone's gonna bump into it!$"

Pokescape01_EventScript_BattleDouble02_Text_0:
	.string "Mom said we are too young, but we are\n"
	.string "already grown up!$"

Pokescape01_EventScript_BattleDouble02_Text_1:
	.string "Mommy!$"

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
	.string "Pokémon.\p"
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
	.string "Oh no! Who takes care of the Pokémon\n"
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
	.string "You still have Pokémon in your PC. I can\n"
	.string "only give you tips when it's empty.\p"
	.string "Of course, you won't be charged 30\n"
	.string "minutes this time.$"

Pokescape01_Pokecenter_EventScript_Gentleman_Text_3:
	.string "Your Makuhita doesn't know Whirlwind by\n"
	.string "now?\l"
	.string "Oh no, you should definitely teach it\l"
	.string "that move!\p"
	.string "Let me take it and give you back\n"
	.string "another Lvl15 Makuhita.$"

Pokescape01_Pokecenter_EventScript_Gentleman_Text_4:
	.string "Oh you are still accompanied by Wooper?\p"
	.string "You should think about evolving it!\n"
	.string "Quagsire can do stuff that Wooper\l"
	.string "can't.$"

Pokescape01_Pokecenter_EventScript_Gentleman_Text_5:
	.string "{PLAYER}: Good bye, Gardevoir.$"

Pokescape01_Pokecenter_EventScript_Gentleman_Text_6:
	.string "GAME MASTER: I also took all items you\n"
	.string "might have acquired from Kirlia before.$"

Pokescape01_Pokecenter_EventScript_Gentleman_Text_7:
	.string "Your Girafarig and Quagsire are a great\n"
	.string "tag team!\p"
	.string "Played right Quagsire can become quite\n"
	.string "invincible against some Pokémon.\p"
	.string "However, you should not try to defeat\n"
	.string "the couple on the hill. But their\l"
	.string "Venusaur is hiding something very\l"
	.string "interesting for you.$"

Pokescape01_Pokecenter_EventScript_Gentleman_Text_8:
	.string "You are almost there.\p"
	.string "Try sneaking past the couple by having\n"
	.string "only one Pokémon in your party.$"

Pokescape01_Pokecenter_EventScript_Gentleman_Text_9:
	.string "{PLAYER}: Good bye, Scyther.$"

Pokescape01_Pokecenter_EventScript_Gentleman_Text_10:
	.string "GAME MASTER: I also took all items you\n"
	.string "might have acquired through catching\l"
	.string "Scyther.$"

Pokescape01_Pokecenter_EventScript_Gentleman_Text_11:
	.string "Come back whenever you need me.$"

Pokescape01_Pokecenter_EventScript_Gentleman_Text_12:
	.string "Hey, don't try to trick me for additional\n"
	.string "rare candies!\p"
	.string "I will still charge you 30min for this.$"

Pokescape01_Pokecenter_EventScript_Gentleman_Text_13:
	.string "I am sorry, but I currently have no\n"
	.string "hints to give to you.\p"
	.string "Try proceeding by looking for hidden\n"
	.string "and held items, catching Pokémon,\l"
	.string "talking to NPCs and winning battles.\p"
	.string "Of course, you won't be charged 30\n"
	.string "minutes this time.$"

Pokescape01_Pokecenter_EventScript_Gentleman_Text_14:
	.string "\p"
	.string "...\p"
	.string "I had already given this hint to you\n"
	.string "before.\l"
	.string "I guess it's fair if I don't charge you\l"
	.string "any more time for it.$"

Pokescape01_Pokecenter_EventScript_Scientist_Text_0:
	.string "You have so little Pokémon in your\n"
	.string "party. I'm not talking to such a\l"
	.string "wannabe.$"

Pokescape01_Pokecenter_EventScript_Scientist_Text_1:
	.string "You did well so far! You will also figure\n"
	.string "out a way to make it to the finish line!$"

Pokescape01_Pokecenter_EventScript_Scientist_Text_2:
	.string "You will need more Pokémon to become a\n"
	.string "successful trainer.\l"
	.string "There is a sign at the grass patch in\l"
	.string "the south. It tells you which one you\l"
	.string "should get...$"

Pokescape01_Pokecenter_EventScript_Scientist_Text_3:
	.string "Your Yamask seems to be very stubborn.\p"
	.string "It is not interested in learning any new\n"
	.string "moves.\p"
	.string "How sad.$"

Pokescape01_House_EventScript_Pikachu_Text_0:
	.string "...Pika...$"

Text_NotEnoughMons::
	.string "You don't have enough Pokémon to fight\n"
	.string "us, sorry!$"

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
	.string "do some sparring with Geodude outside.\p"
	.string "Ohh...and you have checked your item\n"
	.string "box, right?$"

Text_TipRareCandyRevive::
	.string "Nurse Joy is sick and you have already\n"
	.string "used your Rare Candy?\p"
	.string "You should be a little more thoughtful\n"
	.string "about spending stuff!\p"
	.string "Here, I can give you another one.$"

Text_TipRareCandyUse::
	.string "Nurse Joy is sick and you are looking\n"
	.string "for a way to revive your Pokémon?\p"
	.string "You should go check the medicine box in\n"
	.string "your bag.$"

Text_TipMasterBall::
	.string "People often get excited close to the\n"
	.string "Pokémon Center.\p"
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
	.string "Pokémon for your party.$"

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
