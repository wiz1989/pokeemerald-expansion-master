NationalHistoryMuseumL3_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, NHML3_OnResume
	.byte 0


NHML3_OnResume::
	setvar VAR_TEMP_2, 0
	compare VAR_LITTLEROOT_TOWN_STATE, 0
	goto_if_eq NHML3_OnResume_2
NHML3_OnResume_1:
	end

NHML3_OnResume_2:
	givemon SPECIES_MUNCHLAX, 11
	setflag FLAG_SYS_POKEMON_GET
	setorcopyvar VAR_LITTLEROOT_TOWN_STATE, 1
	special CreateMail
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
	setrespawn HEAL_LOCATION_NATIONAL_HISTORY_MUSEUM
	goto NHML3_OnResume_1


NHML3_EveryFrame::
	goto_if_set FLAG_P01_HONOR_MODE, NHML3_EveryFrame_3
NHML3_EveryFrame_1:
	setvar VAR_TEMP_2, 1
	return

NHML3_EveryFrame_2:
	lock
	clearflag FLAG_P01_LOAD_SAVEGAME
	buffernumberstring STR_VAR_1, VAR_P01_CALC
	call Common_EventScript_SaveGame
	closemessage
	release
	goto NHML3_EveryFrame_1

NHML3_EveryFrame_3:
	goto_if_set FLAG_P01_LOAD_SAVEGAME, NHML3_EveryFrame_2
	goto NHML3_EveryFrame_1


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


NHML3_Trigger_WarpL2::
	lockall
	randomnr 3
	setorcopyvar VAR_NHM_L2_RIDDLE, VAR_RESULT
	setflag FLAG_NHML2_RIDDLE_START
	clearflag FLAG_NHML2_RIDDLE_STEP1_CHECK
	clearflag FLAG_NHML2_RIDDLE_STEP2_CHECK
	warp MAP_NATIONAL_HISTORY_MUSEUM_L2, 3, 3
	releaseall
	end


NHML3_Move_Tutor::
	lock
	faceplayer
	msgbox NHML3_Move_Tutor_Text_0
	waitmessage
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 0
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_1
	setvar VAR_0x8006, 0
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, NHML3_Move_Tutor_3
	case 1, NHML3_Move_Tutor_4
	case 2, NHML3_Move_Tutor_5
	case 3, NHML3_Move_Tutor_6
	case MULTI_B_PRESSED, NHML3_Move_Tutor_7
NHML3_Move_Tutor_1:
	waitmessage
	release
	end

NHML3_Move_Tutor_3:
	call NHML3_Tutor_RolePlay
	goto NHML3_Move_Tutor_1

NHML3_Move_Tutor_4:
	call NHML3_Tutor_Endeavor
	goto NHML3_Move_Tutor_1

NHML3_Move_Tutor_5:
	call NHML3_Tutor_Substitute
	goto NHML3_Move_Tutor_1

NHML3_Move_Tutor_6:
	call NHML3_Exit
	goto NHML3_Move_Tutor_1

NHML3_Move_Tutor_7:
	call NHML3_Exit
	goto NHML3_Move_Tutor_1


NHML3_Tutor_RolePlay::
	checktrainerflag TRAINER_NHM_BRANDON
	goto_if 1, NHML3_Tutor_RolePlay_2
	msgbox NHML3_Tutor_RolePlay_Text_0
	waitmessage
	special CloseBattleFrontierTutorWindow
	release
NHML3_Tutor_RolePlay_1:
	end

NHML3_Tutor_RolePlay_2:
	setvar VAR_0x8008, 1
	setvar VAR_0x8005, MOVE_ROLE_PLAY
	call NHML3_Tutor_ConfirmMoveSelection
	goto NHML3_Tutor_RolePlay_1


NHML3_Tutor_Endeavor::
	setvar VAR_0x8008, 1
	setvar VAR_0x8005, MOVE_ENDEAVOR
	call NHML3_Tutor_ConfirmMoveSelection
	end


NHML3_Tutor_Substitute::
	checktrainerflag TRAINER_NHM_BRANDON
	goto_if 1, NHML3_Tutor_Substitute_2
	msgbox NHML3_Tutor_RolePlay_Text_0
	waitmessage
	special CloseBattleFrontierTutorWindow
	release
NHML3_Tutor_Substitute_1:
	end

NHML3_Tutor_Substitute_2:
	setvar VAR_0x8008, 1
	setvar VAR_0x8005, MOVE_SUBSTITUTE
	call NHML3_Tutor_ConfirmMoveSelection
	goto NHML3_Tutor_Substitute_1


NHML3_Exit::
	special CloseBattleFrontierTutorWindow
	msgbox NHML3_Exit_Text_0, MSGBOX_AUTOCLOSE
	release
	end


NHML3_Battle_Double::
	trainerbattle_double TRAINER_NHM_DOUBLE, NHML3_Battle_Double_Text_0, NHML3_Battle_Double_Text_1, Text_NotEnoughMons
	lockall
	goto_if_unset FLAG_NHML3_RECEIVED_STRENGTH, NHML3_Battle_Double_2
	msgbox NHML3_Battle_Double_Text_3, MSGBOX_AUTOCLOSE
	waitmessage
NHML3_Battle_Double_1:
	releaseall
	end

NHML3_Battle_Double_2:
	msgbox NHML3_Battle_Double_Text_2, MSGBOX_AUTOCLOSE
	waitmessage
	giveitem ITEM_HM04
	setflag FLAG_NHML3_RECEIVED_STRENGTH
	goto NHML3_Battle_Double_1


NHML3_Tutor_ConfirmMoveSelection::
	special BufferBattleFrontierTutorMoveName
	buffernumberstring STR_VAR_2, VAR_0x8008
	msgbox NHML3_Tutor_ConfirmMoveSelection_Text_0
	msgbox NHML3_Tutor_ConfirmMoveSelection_Text_1, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq NHML3_Tutor_ConfirmMoveSelection_2
	checkitem ITEM_HEART_SCALE
	compare VAR_RESULT, NO
	goto_if_eq NHML3_Tutor_ConfirmMoveSelection_5
	msgbox BattleFrontier_Lounge7_Text_TeachMoveToWhichMon, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special CloseBattleFrontierTutorWindow
	special ChooseMonForMoveTutor
	waitstate
	compare VAR_RESULT, FALSE
	goto_if_eq NHML3_Tutor_ConfirmMoveSelection_8
	msgbox NHML3_Tutor_ConfirmMoveSelection_Text_4, MSGBOX_AUTOCLOSE
	removeitem ITEM_HEART_SCALE
NHML3_Tutor_ConfirmMoveSelection_4:
	waitmessage
	release
	end

NHML3_Tutor_ConfirmMoveSelection_2:
	msgbox NHML3_Tutor_ConfirmMoveSelection_Text_2, MSGBOX_AUTOCLOSE
	waitmessage
	special CloseBattleFrontierTutorWindow
	release
	end

NHML3_Tutor_ConfirmMoveSelection_5:
	msgbox NHML3_Tutor_ConfirmMoveSelection_Text_3, MSGBOX_AUTOCLOSE
	waitmessage
	special CloseBattleFrontierTutorWindow
	release
	end

NHML3_Tutor_ConfirmMoveSelection_8:
	call NHML3_Exit
	goto NHML3_Tutor_ConfirmMoveSelection_4


NHML3_Trader::
	goto_if_unset FLAG_CAUGHT_ARCHEN, NHML3_Trader_2
	goto_if_unset FLAG_GOT_HEART_SCALE, NHML3_Trader_3
	goto_if_unset FLAG_GOT_SASH, NHML3_Trader_3
	call FortreeCity_House1_EventScript_Trader
NHML3_Trader_1:
	end

NHML3_Trader_2:
	lock
	faceplayer
	msgbox NHML3_Trader_Text_0, MSGBOX_AUTOCLOSE
	waitmessage
	release
	goto NHML3_Trader_1

NHML3_Trader_3:
	lock
	faceplayer
	msgbox NHML3_Trader_Text_1, MSGBOX_AUTOCLOSE
	waitmessage
	release
	goto NHML3_Trader_1


NHML3_Trader2::
	goto_if_unset FLAG_CAUGHT_ARCHEN, NHML3_Trader2_2
	call FortreeCity_House1_EventScript_Trader2
NHML3_Trader2_1:
	end

NHML3_Trader2_2:
	lock
	faceplayer
	msgbox NHML3_Trader2_Text_0, MSGBOX_AUTOCLOSE
	waitmessage
	release
	goto NHML3_Trader2_1


NHML3_ItemManager::
	lock
	faceplayer
	msgbox NHML3_ItemManager_Text_0, MSGBOX_AUTOCLOSE
	waitmessage
	setorcopyvar VAR_NHML3_COLLECTOR_COUNT, 0
	clearflag FLAG_COLLECTOR_DONT_GIVE_ITEM
	goto_if_set FLAG_GOT_SASH, NHML3_ItemManager_2
NHML3_ItemManager_1:
	clearflag FLAG_COLLECTOR_DONT_GIVE_ITEM
	goto_if_set FLAG_GOT_HEART_SCALE, NHML3_ItemManager_6
NHML3_ItemManager_5:
	clearflag FLAG_COLLECTOR_DONT_GIVE_ITEM
	goto_if_unset FLAG_CAUGHT_ARCHEN, NHML3_ItemManager_13
NHML3_ItemManager_12:
	clearflag FLAG_COLLECTOR_DONT_GIVE_ITEM
	goto_if_set FLAG_GOT_LAGGING_TAIL, NHML3_ItemManager_22
NHML3_ItemManager_21:
	release
	return

NHML3_ItemManager_2:
	checkitem ITEM_FOCUS_SASH
	compare VAR_RESULT, TRUE
	goto_if_eq NHML3_ItemManager_10
NHML3_ItemManager_9:
	checkpcitem ITEM_FOCUS_SASH
	compare VAR_RESULT, TRUE
	goto_if_eq NHML3_ItemManager_19
NHML3_ItemManager_18:
	checkpartyitem ITEM_FOCUS_SASH
	compare VAR_RESULT, 6
	goto_if_lt NHML3_ItemManager_32
NHML3_ItemManager_31:
	setorcopyvar VAR_TEMP_1, ITEM_FOCUS_SASH
	specialvar VAR_RESULT, ItemisHeldInPC
	compare VAR_RESULT, TRUE
	goto_if_eq NHML3_ItemManager_44
NHML3_ItemManager_43:
	goto_if_set FLAG_COLLECTOR_DONT_GIVE_ITEM, NHML3_ItemManager_55
	checktrainerflag TRAINER_NHM_BRANDON
	goto_if 0, NHML3_ItemManager_67
	goto NHML3_ItemManager_1

NHML3_ItemManager_6:
	checkitem ITEM_HEART_SCALE
	compare VAR_RESULT, TRUE
	goto_if_eq NHML3_ItemManager_16
NHML3_ItemManager_15:
	checkpcitem ITEM_HEART_SCALE
	compare VAR_RESULT, TRUE
	goto_if_eq NHML3_ItemManager_29
NHML3_ItemManager_28:
	checkpartyitem ITEM_HEART_SCALE
	compare VAR_RESULT, 6
	goto_if_lt NHML3_ItemManager_41
NHML3_ItemManager_40:
	setorcopyvar VAR_TEMP_1, ITEM_HEART_SCALE
	specialvar VAR_RESULT, ItemisHeldInPC
	compare VAR_RESULT, TRUE
	goto_if_eq NHML3_ItemManager_53
NHML3_ItemManager_52:
	goto_if_set FLAG_COLLECTOR_DONT_GIVE_ITEM, NHML3_ItemManager_64
	checktrainerflag TRAINER_NHM_BRANDON
	goto_if 1, NHML3_ItemManager_77
	goto NHML3_ItemManager_5

NHML3_ItemManager_10:
	setflag FLAG_COLLECTOR_DONT_GIVE_ITEM
	goto NHML3_ItemManager_9

NHML3_ItemManager_13:
	checkitem ITEM_POKE_BALL
	compare VAR_RESULT, TRUE
	goto_if_eq NHML3_ItemManager_26
NHML3_ItemManager_25:
	checkpcitem ITEM_POKE_BALL
	compare VAR_RESULT, TRUE
	goto_if_eq NHML3_ItemManager_38
NHML3_ItemManager_37:
	checkpartyitem ITEM_POKE_BALL
	compare VAR_RESULT, 6
	goto_if_lt NHML3_ItemManager_50
NHML3_ItemManager_49:
	setorcopyvar VAR_TEMP_1, ITEM_POKE_BALL
	specialvar VAR_RESULT, ItemisHeldInPC
	compare VAR_RESULT, TRUE
	goto_if_eq NHML3_ItemManager_62
NHML3_ItemManager_61:
	goto_if_set FLAG_COLLECTOR_DONT_GIVE_ITEM, NHML3_ItemManager_72
	msgbox NHML3_ItemManager_Text_5, MSGBOX_AUTOCLOSE
	waitmessage
	msgbox NHML3_ItemManager_Text_6, MSGBOX_AUTOCLOSE
	waitmessage
	giveitem ITEM_POKE_BALL, 1
	goto NHML3_ItemManager_12

NHML3_ItemManager_16:
	setflag FLAG_COLLECTOR_DONT_GIVE_ITEM
	goto NHML3_ItemManager_15

NHML3_ItemManager_19:
	setflag FLAG_COLLECTOR_DONT_GIVE_ITEM
	goto NHML3_ItemManager_18

NHML3_ItemManager_22:
	checkitem ITEM_LAGGING_TAIL
	compare VAR_RESULT, TRUE
	goto_if_eq NHML3_ItemManager_35
NHML3_ItemManager_34:
	checkpcitem ITEM_LAGGING_TAIL
	compare VAR_RESULT, TRUE
	goto_if_eq NHML3_ItemManager_47
NHML3_ItemManager_46:
	checkpartyitem ITEM_LAGGING_TAIL
	compare VAR_RESULT, 6
	goto_if_lt NHML3_ItemManager_59
NHML3_ItemManager_58:
	setorcopyvar VAR_TEMP_1, ITEM_LAGGING_TAIL
	specialvar VAR_RESULT, ItemisHeldInPC
	compare VAR_RESULT, TRUE
	goto_if_eq NHML3_ItemManager_70
NHML3_ItemManager_69:
	goto_if_set FLAG_COLLECTOR_DONT_GIVE_ITEM, NHML3_ItemManager_81
	checktrainerflag TRAINER_NHM_HAIL
	goto_if 0, NHML3_ItemManager_87
	goto NHML3_ItemManager_21

NHML3_ItemManager_26:
	setflag FLAG_COLLECTOR_DONT_GIVE_ITEM
	goto NHML3_ItemManager_25

NHML3_ItemManager_29:
	setflag FLAG_COLLECTOR_DONT_GIVE_ITEM
	goto NHML3_ItemManager_28

NHML3_ItemManager_32:
	setflag FLAG_COLLECTOR_DONT_GIVE_ITEM
	goto NHML3_ItemManager_31

NHML3_ItemManager_35:
	setflag FLAG_COLLECTOR_DONT_GIVE_ITEM
	goto NHML3_ItemManager_34

NHML3_ItemManager_38:
	setflag FLAG_COLLECTOR_DONT_GIVE_ITEM
	goto NHML3_ItemManager_37

NHML3_ItemManager_41:
	setflag FLAG_COLLECTOR_DONT_GIVE_ITEM
	goto NHML3_ItemManager_40

NHML3_ItemManager_44:
	setflag FLAG_COLLECTOR_DONT_GIVE_ITEM
	goto NHML3_ItemManager_43

NHML3_ItemManager_47:
	setflag FLAG_COLLECTOR_DONT_GIVE_ITEM
	goto NHML3_ItemManager_46

NHML3_ItemManager_50:
	setflag FLAG_COLLECTOR_DONT_GIVE_ITEM
	goto NHML3_ItemManager_49

NHML3_ItemManager_53:
	setflag FLAG_COLLECTOR_DONT_GIVE_ITEM
	goto NHML3_ItemManager_52

NHML3_ItemManager_55:
	goto NHML3_ItemManager_1

NHML3_ItemManager_59:
	setflag FLAG_COLLECTOR_DONT_GIVE_ITEM
	goto NHML3_ItemManager_58

NHML3_ItemManager_62:
	setflag FLAG_COLLECTOR_DONT_GIVE_ITEM
	goto NHML3_ItemManager_61

NHML3_ItemManager_64:
	goto NHML3_ItemManager_5

NHML3_ItemManager_67:
	msgbox NHML3_ItemManager_Text_1, MSGBOX_AUTOCLOSE
	waitmessage
	msgbox NHML3_ItemManager_Text_2, MSGBOX_AUTOCLOSE
	waitmessage
	giveitem ITEM_FOCUS_SASH
	goto NHML3_ItemManager_1

NHML3_ItemManager_70:
	setflag FLAG_COLLECTOR_DONT_GIVE_ITEM
	goto NHML3_ItemManager_69

NHML3_ItemManager_72:
	goto NHML3_ItemManager_12

NHML3_ItemManager_75:
	checkpartymonmove SPECIES_YAMASK, MOVE_ROLE_PLAY
	compare VAR_RESULT, FALSE
	goto_if_eq NHML3_ItemManager_85
NHML3_ItemManager_84:
	checkpartymonmove SPECIES_YAMASK, MOVE_SUBSTITUTE
	compare VAR_RESULT, FALSE
	goto_if_eq NHML3_ItemManager_90
NHML3_ItemManager_89:
	compare VAR_NHML3_COLLECTOR_COUNT, 0
	goto_if_gt NHML3_ItemManager_92
	goto NHML3_ItemManager_5

NHML3_ItemManager_76:
	goto_if_set FLAG_NHML2_ITEMBALL, NHML3_ItemManager_75
	goto NHML3_ItemManager_5

NHML3_ItemManager_77:
	checktrainerflag TRAINER_NHM_DOUBLE
	goto_if 0, NHML3_ItemManager_76
	goto NHML3_ItemManager_5

NHML3_ItemManager_81:
	goto NHML3_ItemManager_21

NHML3_ItemManager_85:
	addvar VAR_NHML3_COLLECTOR_COUNT, 1
	goto NHML3_ItemManager_84

NHML3_ItemManager_87:
	msgbox NHML3_ItemManager_Text_7, MSGBOX_AUTOCLOSE
	waitmessage
	msgbox NHML3_ItemManager_Text_2, MSGBOX_AUTOCLOSE
	waitmessage
	giveitem ITEM_LAGGING_TAIL
	goto NHML3_ItemManager_21

NHML3_ItemManager_90:
	addvar VAR_NHML3_COLLECTOR_COUNT, 1
	goto NHML3_ItemManager_89

NHML3_ItemManager_92:
	msgbox NHML3_ItemManager_Text_3, MSGBOX_AUTOCLOSE
	waitmessage
	switch VAR_NHML3_COLLECTOR_COUNT
	case 1, NHML3_ItemManager_95
	case 2, NHML3_ItemManager_96
	goto NHML3_ItemManager_5

NHML3_ItemManager_95:
	msgbox NHML3_ItemManager_Text_2, MSGBOX_AUTOCLOSE
	waitmessage
	giveitem ITEM_HEART_SCALE
	goto NHML3_ItemManager_5

NHML3_ItemManager_96:
	msgbox NHML3_ItemManager_Text_4, MSGBOX_AUTOCLOSE
	waitmessage
	giveitem ITEM_HEART_SCALE, 2
	goto NHML3_ItemManager_5


NHML3_InfoSign::
	lockall
	msgbox NHML3_InfoSign_Text_0
	waitmessage
	releaseall
	end


NHML3_Sign_Stakataka::
	lock
	showmonpic SPECIES_STAKATAKA, 10, 3
	msgbox NHML3_Sign_Stakataka_Text_0
	waitmessage
	hidemonpic
	release
	end


NHML3_Sign_Persian::
	lock
	showmonpic SPECIES_PERSIAN, 10, 3
	msgbox NHML3_Sign_Persian_Text_0
	waitmessage
	hidemonpic
	release
	end


NHML3_Sign_Cofagrigus::
	lock
	showmonpic SPECIES_COFAGRIGUS, 10, 3
	msgbox NHML3_Sign_Cofagrigus_Text_0
	waitmessage
	hidemonpic
	release
	end


NHML3_Sign_Regirock::
	lock
	showmonpic SPECIES_REGIROCK, 10, 3
	msgbox NHML3_Sign_Regirock_Text_0
	waitmessage
	hidemonpic
	release
	end


NHML3_Sign_tileset::
	lock
	msgbox NHML3_Sign_tileset_Text_0, MSGBOX_AUTOCLOSE
	waitmessage
	release
	end


NHML3_Sign_Pyramid::
	lock
	msgbox NHML3_Sign_Pyramid_Text_0, MSGBOX_AUTOCLOSE
	waitmessage
	release
	end


NHML3_Sign_Pokedex::
	lock
	msgbox NHML3_Sign_Pokedex_Text_0, MSGBOX_AUTOCLOSE
	waitmessage
	release
	end


NHML3_Move_Tutor_Text_0:
	.string "I am the Move Tutor. \lI will teach your Pokemon moves for\nprecious Heart Scales. \pWhich move should I teach?$"

NHML3_Tutor_RolePlay_Text_0:
	.string "Oh I am sorry.\p"
	.string "I don't have this move available right\n"
	.string "now.\l"
	.string "You should come back later for it.$"

NHML3_Exit_Text_0:
	.string "Well, if you don't want to...$"

NHML3_Battle_Double_Text_0:
	.string "Do you like all these artifacts?\l"
	.string "We always enjoyed exhibits outside of\l"
	.string "the NORMAL.$"

NHML3_Battle_Double_Text_1:
	.string "We should have trusted the prophecy on\n"
	.string "that old sarcophagus over there.\l"
	.string "It even foretold the broken AC in the\l"
	.string "first floor!$"

NHML3_Battle_Double_Text_2:
	.string "That was very impressive!\l"
	.string "You are a very STRONG trainer.\l"
	.string "Let us give you this as a reward.$"

NHML3_Battle_Double_Text_3:
	.string "The AC in the lobby is running crazy.\l"
	.string "Be careful making it through there!$"

NHML3_Tutor_ConfirmMoveSelection_Text_0:
	.string "The move {STR_VAR_1}, is it?$"

NHML3_Tutor_ConfirmMoveSelection_Text_1:
	.string "That will be {STR_VAR_2} Heart Scale, okay?$"

NHML3_Tutor_ConfirmMoveSelection_Text_2:
	.string "Alright. Come back anytime you want.$"

NHML3_Tutor_ConfirmMoveSelection_Text_3:
	.string "Oh, you don't have any Heart Scales!\l"
	.string "Don't waste my time then!$"

NHML3_Tutor_ConfirmMoveSelection_Text_4:
	.string "Thanks for doing business with me.$"

NHML3_Trader_Text_0:
	.string "Ohhh you got a MUNCHLAX!!!\l"
	.string "I love it!\p"
	.string "I'd really like to trade Pokemon with a\n"
	.string "skilled trainer...\p"
	.string "So you should consider coming back\n"
	.string "when you have a bigger party.$"

NHML3_Trader_Text_1:
	.string "Oh you got an Archen? Very cool!\p"
	.string "I think there's more to do for you\n"
	.string "though before trading your MUNCHLAX.\l"
	.string "Please come back later.$"

NHML3_Trader2_Text_0:
	.string "Oh hey, I'd really like to trade Pokemon\n"
	.string "with a skilled trainer...\p"
	.string "So you should consider coming back\n"
	.string "when you have a bigger party.$"

NHML3_ItemManager_Text_0:
	.string "Hello {PLAYER}, I am the collector!\p"
	.string "I will help you out in case you lost\n"
	.string "crucial items after obtaining them in\l"
	.string "the first place.$"

NHML3_ItemManager_Text_1:
	.string "Oh no, you lost a FOCUS SASH!$"

NHML3_ItemManager_Text_2:
	.string "Here, I will give you another one to\n"
	.string "continue your journey.$"

NHML3_ItemManager_Text_3:
	.string "Oh no, you no longer possess any HEART\n"
	.string "SCALES!$"

NHML3_ItemManager_Text_4:
	.string "Here, I will give you two more to\n"
	.string "continue your journey.$"

NHML3_ItemManager_Text_5:
	.string "Oh no, you lost your POKéBALL!$"

NHML3_ItemManager_Text_6:
	.string "Here, I will give you another one!\l"
	.string "But make sure to use it wisely.$"

NHML3_ItemManager_Text_7:
	.string "Oh no, you lost your LAGGING TAIL!$"

NHML3_InfoSign_Text_0:
	.string "IMPORTANT INFORMATION:\p"
	.string "1.) This game is featuring the most\n"
	.string "recent move learnsets for any Pokemon\l"
	.string "you control yourself.\p"
	.string "2.) It is not required to grind multiple\n"
	.string "levels to win any of the fights.\p"
	.string "3.) All items are there for a reason.\n"
	.string "Think twice before using them.\p"
	.string "4.) Running from trainer battles is\n"
	.string "explicitly allowed.$"

NHML3_Sign_Stakataka_Text_0:
	.string "STAKATAKA...very slow$"

NHML3_Sign_Persian_Text_0:
	.string "PERSIAN...very fast$"

NHML3_Sign_Cofagrigus_Text_0:
	.string "COFAGRIGUS...very scary$"

NHML3_Sign_Regirock_Text_0:
	.string "REGIROCK...very reckless$"

NHML3_Sign_tileset_Text_0:
	.string "Parts of this tileset have originally\n"
	.string "been designed by princess-phoenix and\l"
	.string "aveontrainer.$"

NHML3_Sign_Pyramid_Text_0:
	.string "A very realistic replica of an ancient\n"
	.string "Pyramid.$"

NHML3_Sign_Pokedex_Text_0:
	.string "It's the first ever found evidence of a\n"
	.string "Pokédex in history picturing a\l"
	.string "legendary and sacred Pokémon.$"
