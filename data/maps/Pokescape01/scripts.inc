Pokescape01_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, OnResume
	.byte 0


OnResume::
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


OnTransition::
	setvar VAR_LITTLEROOT_TOWN_STATE, 0
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
	special ChangePlayerName
	waitmessage
	msgbox Pokescape01_EventScript_PokecenterTriggers_Text_0, MSGBOX_YESNO
Pokescape01_EventScript_PokecenterTriggers_5:
	compare VAR_RESULT, NO
	goto_if_eq Pokescape01_EventScript_PokecenterTriggers_6
	setvar VAR_UNUSED_0x408B, 1
	releaseall
	goto Pokescape01_EventScript_PokecenterTriggers_1

Pokescape01_EventScript_PokecenterTriggers_6:
	msgbox Pokescape01_EventScript_PokecenterTriggers_Text_0, MSGBOX_YESNO
	goto Pokescape01_EventScript_PokecenterTriggers_5


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
	msgbox Pokescape01_EventScript_AppleTree_Text_2
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
	msgbox Pokescape01_EventScript_AppleTree_Text_1
	goto Pokescape01_EventScript_AppleTree_1

Pokescape01_EventScript_AppleTree_6:
	setflag FLAG_P01_GOTGIRAFARIG
	goto Pokescape01_EventScript_AppleTree_5

Pokescape01_EventScript_AppleTree_9:
	msgbox Pokescape01_EventScript_AppleTree_Text_0
	giveitem ITEM_SWEET_APPLE, 1
	setvar VAR_UNUSED_0x40F7, 1
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
	givemon SPECIES_WOOPER, 18
	msgbox Pokescape01_EventScript_BattleDouble02_Text_7
	waitmessage
	msgbox Pokescape01_EventScript_BattleDouble02_Text_4
	waitmessage
	goto Pokescape01_EventScript_BattleDouble02_1


Pokescape01_EventScript_BattleDouble03::
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
Pokescape01_Pokecenter_EventScript_Gentleman_5:
	goto_if_set FLAG_P01_GIVE_ADVICE, Pokescape01_Pokecenter_EventScript_Gentleman_15
Pokescape01_Pokecenter_EventScript_Gentleman_13:
	release
	end

Pokescape01_Pokecenter_EventScript_Gentleman_2:
	setflag FLAG_P01_GIVE_ADVICE
	getpartysize
	checktrainerflag TRAINER_POKESCAPE01_01
	goto_if 0, Pokescape01_Pokecenter_EventScript_Gentleman_10
Pokescape01_Pokecenter_EventScript_Gentleman_9:
	specialvar VAR_RESULT, IsPcEmpty
	compare VAR_RESULT, FALSE
	goto_if_eq Pokescape01_Pokecenter_EventScript_Gentleman_18
	checktrainerflag TRAINER_POKESCAPE01_01
	goto_if 0, Pokescape01_Pokecenter_EventScript_Gentleman_22
Pokescape01_Pokecenter_EventScript_Gentleman_21:
	checktrainerflag TRAINER_POKESCAPE01_01
	goto_if 1, Pokescape01_Pokecenter_EventScript_Gentleman_26
Pokescape01_Pokecenter_EventScript_Gentleman_24:
	checkpartymon SPECIES_WOOPER
	compare VAR_RESULT, 0
	goto_if_ne Pokescape01_Pokecenter_EventScript_Gentleman_33
	clearflag FLAG_P01_GOTWOOPER
Pokescape01_Pokecenter_EventScript_Gentleman_32:
	checkpartymon SPECIES_QUAGSIRE
	compare VAR_RESULT, 0
	goto_if_ne Pokescape01_Pokecenter_EventScript_Gentleman_43
	clearflag FLAG_P01_GOTQUAGSIRE
Pokescape01_Pokecenter_EventScript_Gentleman_42:
	checkpartymon SPECIES_GALLADE
	compare VAR_RESULT, 0
	goto_if_ne Pokescape01_Pokecenter_EventScript_Gentleman_47
	clearflag FLAG_P01_GOTGALLADE
Pokescape01_Pokecenter_EventScript_Gentleman_46:
	checkpartymon SPECIES_GARDEVOIR
	compare VAR_RESULT, 0
	goto_if_ne Pokescape01_Pokecenter_EventScript_Gentleman_51
	clearflag FLAG_P01_GOTGARDEVOIR
Pokescape01_Pokecenter_EventScript_Gentleman_50:
	checkitem ITEM_HM_CUT
	compare VAR_RESULT, 0
	goto_if_ne Pokescape01_Pokecenter_EventScript_Gentleman_55
	clearflag FLAG_P01_HM_CUT
Pokescape01_Pokecenter_EventScript_Gentleman_54:
	goto_if_set FLAG_P01_GOTKIRLIA, Pokescape01_Pokecenter_EventScript_Gentleman_60
Pokescape01_Pokecenter_EventScript_Gentleman_59:
	checktrainerflag TRAINER_POKESCAPE01_02
	goto_if 1, Pokescape01_Pokecenter_EventScript_Gentleman_68
	goto Pokescape01_Pokecenter_EventScript_Gentleman_1

Pokescape01_Pokecenter_EventScript_Gentleman_6:
	playtimeaddmin 30
	goto Pokescape01_Pokecenter_EventScript_Gentleman_5

Pokescape01_Pokecenter_EventScript_Gentleman_8:
	setflag FLAG_P01_ADD30MIN
	msgbox Text_TipCheckPC
	goto Pokescape01_Pokecenter_EventScript_Gentleman_1

Pokescape01_Pokecenter_EventScript_Gentleman_10:
	compare VAR_RESULT, 1
	goto_if_le Pokescape01_Pokecenter_EventScript_Gentleman_8
	goto Pokescape01_Pokecenter_EventScript_Gentleman_9

Pokescape01_Pokecenter_EventScript_Gentleman_14:
	msgbox Pokescape01_Pokecenter_EventScript_Gentleman_Text_11
	goto Pokescape01_Pokecenter_EventScript_Gentleman_13

Pokescape01_Pokecenter_EventScript_Gentleman_15:
	goto_if_unset FLAG_P01_ADD30MIN, Pokescape01_Pokecenter_EventScript_Gentleman_14
	goto Pokescape01_Pokecenter_EventScript_Gentleman_13

Pokescape01_Pokecenter_EventScript_Gentleman_18:
	msgbox Pokescape01_Pokecenter_EventScript_Gentleman_Text_2
	clearflag FLAG_P01_GIVE_ADVICE
	goto Pokescape01_Pokecenter_EventScript_Gentleman_1

Pokescape01_Pokecenter_EventScript_Gentleman_22:
	getpartysize
	compare VAR_RESULT, 1
	goto_if_le Pokescape01_Pokecenter_EventScript_Gentleman_29
	goto_if_set FLAG_P01_RARE_CANDY, Pokescape01_Pokecenter_EventScript_Gentleman_39
	setflag FLAG_P01_ADD30MIN
	msgbox Text_TipFirstFight
	goto Pokescape01_Pokecenter_EventScript_Gentleman_21

Pokescape01_Pokecenter_EventScript_Gentleman_25:
	goto_if_set FLAG_P01_RARE_CANDY, Pokescape01_Pokecenter_EventScript_Gentleman_36
	setflag FLAG_P01_ADD30MIN
	msgbox Text_TipRareCandyUse
	goto Pokescape01_Pokecenter_EventScript_Gentleman_24

Pokescape01_Pokecenter_EventScript_Gentleman_26:
	checktrainerflag TRAINER_POKESCAPE01_02
	goto_if 0, Pokescape01_Pokecenter_EventScript_Gentleman_25
	goto Pokescape01_Pokecenter_EventScript_Gentleman_24

Pokescape01_Pokecenter_EventScript_Gentleman_29:
	setflag FLAG_P01_ADD30MIN
	msgbox Text_TipCheckPC
	goto Pokescape01_Pokecenter_EventScript_Gentleman_21

Pokescape01_Pokecenter_EventScript_Gentleman_33:
	setflag FLAG_P01_GOTWOOPER
	goto Pokescape01_Pokecenter_EventScript_Gentleman_32

Pokescape01_Pokecenter_EventScript_Gentleman_36:
	setflag FLAG_P01_ADD30MIN
	msgbox Text_TipRareCandyRevive
	giveitem ITEM_RARE_CANDY, 1
	clearflag FLAG_P01_RARE_CANDY
	goto Pokescape01_Pokecenter_EventScript_Gentleman_24

Pokescape01_Pokecenter_EventScript_Gentleman_39:
	setflag FLAG_P01_ADD30MIN
	msgbox Text_TipRareCandy
	giveitem ITEM_RARE_CANDY, 1
	clearflag FLAG_P01_RARE_CANDY
	goto Pokescape01_Pokecenter_EventScript_Gentleman_21

Pokescape01_Pokecenter_EventScript_Gentleman_43:
	setflag FLAG_P01_GOTQUAGSIRE
	goto Pokescape01_Pokecenter_EventScript_Gentleman_42

Pokescape01_Pokecenter_EventScript_Gentleman_47:
	setflag FLAG_P01_GOTGALLADE
	goto Pokescape01_Pokecenter_EventScript_Gentleman_46

Pokescape01_Pokecenter_EventScript_Gentleman_51:
	setflag FLAG_P01_GOTGARDEVOIR
	goto Pokescape01_Pokecenter_EventScript_Gentleman_50

Pokescape01_Pokecenter_EventScript_Gentleman_55:
	setflag FLAG_P01_HM_CUT
	goto Pokescape01_Pokecenter_EventScript_Gentleman_54

Pokescape01_Pokecenter_EventScript_Gentleman_58:
	goto_if_set FLAG_P01_GOTWOOPER, Pokescape01_Pokecenter_EventScript_Gentleman_63
	goto_if_set FLAG_P01_GOTGARDEVOIR, Pokescape01_Pokecenter_EventScript_Gentleman_64
	goto_if_set FLAG_P01_GOTQUAGSIRE, Pokescape01_Pokecenter_EventScript_Gentleman_75
Pokescape01_Pokecenter_EventScript_Gentleman_74:
	goto_if_set FLAG_P01_GOTGALLADE, Pokescape01_Pokecenter_EventScript_Gentleman_73
	goto Pokescape01_Pokecenter_EventScript_Gentleman_1

Pokescape01_Pokecenter_EventScript_Gentleman_60:
	goto_if_set FLAG_P01_HM_CUT, Pokescape01_Pokecenter_EventScript_Gentleman_58
	goto Pokescape01_Pokecenter_EventScript_Gentleman_59

Pokescape01_Pokecenter_EventScript_Gentleman_63:
	setflag FLAG_P01_ADD30MIN
	msgbox Pokescape01_Pokecenter_EventScript_Gentleman_Text_3
	goto Pokescape01_Pokecenter_EventScript_Gentleman_1

Pokescape01_Pokecenter_EventScript_Gentleman_64:
	setflag FLAG_P01_ADD30MIN
	msgbox Text_TipGardevoir
	waitmessage
	getpartymonslot SPECIES_GARDEVOIR
	special DeletePartyMon
	msgbox Pokescape01_Pokecenter_EventScript_Gentleman_Text_4
	givemon SPECIES_KIRLIA, 20, ITEM_EVERSTONE
	checkitem ITEM_EVERSTONE
	compare VAR_RESULT, TRUE
	goto_if_eq Pokescape01_Pokecenter_EventScript_Gentleman_70
	goto Pokescape01_Pokecenter_EventScript_Gentleman_1

Pokescape01_Pokecenter_EventScript_Gentleman_68:
	goto_if_unset FLAG_P01_MASTER_BALL, Pokescape01_Pokecenter_EventScript_Gentleman_78
	goto_if_set FLAG_P01_SCYTHER, Pokescape01_Pokecenter_EventScript_Gentleman_87
Pokescape01_Pokecenter_EventScript_Gentleman_85:
	goto_if_unset FLAG_P01_SCYTHER, Pokescape01_Pokecenter_EventScript_Gentleman_84
Pokescape01_Pokecenter_EventScript_Gentleman_83:
	checkitem ITEM_HM_CUT
	compare VAR_RESULT, FALSE
	goto_if_eq Pokescape01_Pokecenter_EventScript_Gentleman_93
	goto_if_set FLAG_P01_KIRLIA, Pokescape01_Pokecenter_EventScript_Gentleman_94
	goto Pokescape01_Pokecenter_EventScript_Gentleman_1

Pokescape01_Pokecenter_EventScript_Gentleman_70:
	waitmessage
	removeitem ITEM_EVERSTONE
	msgbox Pokescape01_Pokecenter_EventScript_Gentleman_Text_5
	goto Pokescape01_Pokecenter_EventScript_Gentleman_1

Pokescape01_Pokecenter_EventScript_Gentleman_72:
	setflag FLAG_P01_ADD30MIN
	msgbox Pokescape01_Pokecenter_EventScript_Gentleman_Text_6
	goto Pokescape01_Pokecenter_EventScript_Gentleman_1

Pokescape01_Pokecenter_EventScript_Gentleman_73:
	setflag FLAG_P01_ADD30MIN
	msgbox Pokescape01_Pokecenter_EventScript_Gentleman_Text_7
	goto Pokescape01_Pokecenter_EventScript_Gentleman_1

Pokescape01_Pokecenter_EventScript_Gentleman_75:
	goto_if_unset FLAG_P01_GOTGALLADE, Pokescape01_Pokecenter_EventScript_Gentleman_72
	goto Pokescape01_Pokecenter_EventScript_Gentleman_74

Pokescape01_Pokecenter_EventScript_Gentleman_78:
	setflag FLAG_P01_ADD30MIN
	msgbox Text_TipMasterBall
	goto Pokescape01_Pokecenter_EventScript_Gentleman_1

Pokescape01_Pokecenter_EventScript_Gentleman_81:
	setflag FLAG_P01_ADD30MIN
	msgbox Text_TipScyther
	waitmessage
	getpartymonslot SPECIES_SCYTHER
	special DeletePartyMon
	giveitem ITEM_MASTER_BALL, 1
	msgbox Pokescape01_Pokecenter_EventScript_Gentleman_Text_8
	checkitem ITEM_HM_CUT
	compare VAR_RESULT, TRUE
	goto_if_eq Pokescape01_Pokecenter_EventScript_Gentleman_91
Pokescape01_Pokecenter_EventScript_Gentleman_90:
	clearflag FLAG_P01_SCYTHER
	goto Pokescape01_Pokecenter_EventScript_Gentleman_1

Pokescape01_Pokecenter_EventScript_Gentleman_82:
	setflag FLAG_P01_ADD30MIN
	msgbox Text_TipCatch
	goto Pokescape01_Pokecenter_EventScript_Gentleman_1

Pokescape01_Pokecenter_EventScript_Gentleman_84:
	goto_if_unset FLAG_P01_GIRAFARIG, Pokescape01_Pokecenter_EventScript_Gentleman_82
	goto Pokescape01_Pokecenter_EventScript_Gentleman_83

Pokescape01_Pokecenter_EventScript_Gentleman_87:
	goto_if_unset FLAG_P01_GIRAFARIG, Pokescape01_Pokecenter_EventScript_Gentleman_81
	goto Pokescape01_Pokecenter_EventScript_Gentleman_85

Pokescape01_Pokecenter_EventScript_Gentleman_91:
	waitmessage
	clearflag FLAG_P01_HM_CUT
	removeitem ITEM_HM_CUT
	msgbox Pokescape01_Pokecenter_EventScript_Gentleman_Text_9
	goto Pokescape01_Pokecenter_EventScript_Gentleman_90

Pokescape01_Pokecenter_EventScript_Gentleman_93:
	setflag FLAG_P01_ADD30MIN
	msgbox Text_TipHMCut
	goto Pokescape01_Pokecenter_EventScript_Gentleman_1

Pokescape01_Pokecenter_EventScript_Gentleman_94:
	setflag FLAG_P01_ADD30MIN
	msgbox Text_TipKirlia
	goto Pokescape01_Pokecenter_EventScript_Gentleman_1


Pokescape01_Pokecenter_EventScript_Scientist::
	lock
	faceplayer
	getpartysize
	checktrainerflag TRAINER_POKESCAPE01_01
	goto_if 0, Pokescape01_Pokecenter_EventScript_Scientist_4
Pokescape01_Pokecenter_EventScript_Scientist_3:
	msgbox Pokescape01_Pokecenter_EventScript_Scientist_Text_0
Pokescape01_Pokecenter_EventScript_Scientist_1:
	waitmessage
	release
	end

Pokescape01_Pokecenter_EventScript_Scientist_2:
	checkpartymove MOVE_TRICK_ROOM
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne Pokescape01_Pokecenter_EventScript_Scientist_7
	msgbox Pokescape01_Pokecenter_EventScript_Scientist_Text_1
	goto Pokescape01_Pokecenter_EventScript_Scientist_1

Pokescape01_Pokecenter_EventScript_Scientist_4:
	compare VAR_RESULT, 1
	goto_if_le Pokescape01_Pokecenter_EventScript_Scientist_2
	goto Pokescape01_Pokecenter_EventScript_Scientist_3

Pokescape01_Pokecenter_EventScript_Scientist_7:
	msgbox Pokescape01_Pokecenter_EventScript_Scientist_Text_0
	goto Pokescape01_Pokecenter_EventScript_Scientist_1


Pokescape01_House_EventScript_Birch::
	lock
	special StopPlayTimer
	faceplayer
	specialvar VAR_RESULT, GetPlayTimeHours
	buffernumberstring STR_VAR_1, VAR_RESULT
	specialvar VAR_RESULT, GetPlayTimeMinutes
	buffernumberstring STR_VAR_2, VAR_RESULT
	specialvar VAR_RESULT, GetPlayTimeSeconds
	buffernumberstring STR_VAR_3, VAR_RESULT
	msgbox Text_Finale
	waitmessage
	setobjectmovementtype 1, MOVEMENT_TYPE_WANDER_AROUND
	release
	end


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
	.string "Think twice before using them.$"

Pokescape01_EventScript_Building01Sign_Text_0:
	.string "Hooray, you made it!$"

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
	.string "So your name is {PLAYER}?$"

Pokescape01_EventScript_TriggerLittleGirl_Text_0:
	.string "Eek! Your Scyther looks so scary.\p"
	.string "Please don't bring it up here.$"

Pokescape01_EventScript_ItemMasterBall_Text_0:
	.string "You found a lost Master Ball on the\n"
	.string "ground.\p"
	.string "Make sure to make good use of it!$"

Pokescape01_EventScript_AppleTree_Text_0:
	.string "{PLAYER} found a Sweet Apple in the\n"
	.string "tree.$"

Pokescape01_EventScript_AppleTree_Text_1:
	.string "There is an apple growing in the tree.\n"
	.string "You should go catch more Pokemon and\l"
	.string "return later to pick it.$"

Pokescape01_EventScript_AppleTree_Text_2:
	.string "There's nothing to find in the tree.$"

Pokescape01_EventScript_LittleGirl15_Text_0:
	.string "Did you know that some species can\n"
	.string "have access to completely new moves\l"
	.string "after evolving?\p"
	.string "There is so much to learn about\n"
	.string "Pokemon.$"

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
	.string "Looks like it ate a special stone or\n"
	.string "something.$"

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
	.string "You should think about evolving it! It\n"
	.string "can do stuff that Wooper can't.$"

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
	.string "I am sorry, but I currently have no\n"
	.string "hints to give to you.\p"
	.string "Try proceeding by looking for hidden\n"
	.string "and held items, catching Pokemon,\l"
	.string "talking to NPCs and winning battles.\p"
	.string "Of course, you won't be charged 30\n"
	.string "minutes this time.$"

Pokescape01_Pokecenter_EventScript_Scientist_Text_0:
	.string "Your Yamask seems to be very stubborn.\p"
	.string "It is not interested in learning any new\n"
	.string "moves.\p"
	.string "How sad.$"

Pokescape01_Pokecenter_EventScript_Scientist_Text_1:
	.string "You have so little pokemon in your\n"
	.string "party. I'm not talking to such a\l"
	.string "wannabe.$"

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

Text_Finale::
	.string "Congratulations {PLAYER}!\p"
	.string "You have completed the challenge. Well\n"
	.string "done!\p"
	.string "Your final time is\n"
	.string "{STR_VAR_1}:{STR_VAR_2}:{STR_VAR_3}$"