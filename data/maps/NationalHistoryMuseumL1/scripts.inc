NationalHistoryMuseumL1_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, NHML1_OnResume
	.byte 0


NHML1_OnResume::
	setvar VAR_TEMP_2, 0
	call load_HONOR_MODE
	goto_if_unset FLAG_NHML1_BOULDER_FELL_DOWN, NHML1_OnResume_2
	clearflag FLAG_NHML1_BOULDER
NHML1_OnResume_1:
	compare VAR_FINAL_BATTLE, 0
	goto_if_eq NHML1_OnResume_6
	clearflag FLAG_NHML1_FINAL_BATTLE
NHML1_OnResume_5:
	end

NHML1_OnResume_2:
	setflag FLAG_NHML1_BOULDER
	goto NHML1_OnResume_1

NHML1_OnResume_6:
	setflag FLAG_NHML1_FINAL_BATTLE
	goto NHML1_OnResume_5


NHML1_EveryFrame::
	goto_if_set FLAG_P01_HONOR_MODE, NHML1_EveryFrame_3
NHML1_EveryFrame_1:
	setvar VAR_TEMP_2, 1
	return

NHML1_EveryFrame_2:
	lock
	clearflag FLAG_P01_LOAD_SAVEGAME
	buffernumberstring STR_VAR_1, VAR_P01_CALC
	call Common_EventScript_SaveGame
	closemessage
	release
	goto NHML1_EveryFrame_1

NHML1_EveryFrame_3:
	goto_if_set FLAG_P01_LOAD_SAVEGAME, NHML1_EveryFrame_2
	goto NHML1_EveryFrame_1


NHML1_Trigger_WarpL2::
	lockall
	randomnr 3
	setorcopyvar VAR_NHM_L2_RIDDLE, VAR_RESULT
	setflag FLAG_NHML2_RIDDLE_START
	clearflag FLAG_NHML2_RIDDLE_STEP1_CHECK
	clearflag FLAG_NHML2_RIDDLE_STEP2_CHECK
	warp MAP_NATIONAL_HISTORY_MUSEUM_L2, 27, 3
	releaseall
	end


NHML1_Judge::
	lock
	faceplayer
	msgbox NHML1_Judge_Text_0, MSGBOX_AUTOCLOSE
	waitmessage
	setflag FLAG_NHML1_WALLPAPER_GUY
	release
	end


NHML1_Artist::
	call FortreeCity_House1_EventScript_Trader3
	setflag FLAG_NHML2_TEST_OBTAIN_CLEFAIRY
	end


NHML1_ItemBall::
	lock
	msgbox NHML1_ItemBall_Text_0, MSGBOX_AUTOCLOSE
	waitmessage
	fadescreen FADE_TO_BLACK
	removeobject 3, MAP_NATIONAL_HISTORY_MUSEUM_L1
	setflag FLAG_NHML1_ITEMBALL
	fadescreen FADE_FROM_BLACK
	givemon SPECIES_SKITTY, 20
	setflag FLAG_NHML2_TEST_OBTAIN_SKITTY
	release
	end


NHML1_Boulder::
	call EventScript_StrengthBoulder
	end


NHML1_Cooltrainer::
	trainerbattle_single TRAINER_NHM_HAIL, NHML1_Cooltrainer_Text_0, NHML1_Cooltrainer_Text_1
	lock
	msgbox NHML1_Cooltrainer_Text_1, MSGBOX_AUTOCLOSE
	release
	end


NHML1_Juan::
	lock
	faceplayer
	msgbox NHML1_Juan_Text_0, MSGBOX_AUTOCLOSE
	release
	end


NHML1_Trigger_Juan::
	lock
	goto_if_unset FLAG_NHML1_YAMASK_TAKEN, NHML1_Trigger_Juan_2
NHML1_Trigger_Juan_1:
	release
	end

NHML1_Trigger_Juan_2:
	applymovement 5, Move_exclmark
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Move_lookup
	waitmovement 0
	msgbox NHML1_Trigger_Juan_Text_0, MSGBOX_AUTOCLOSE
	waitmessage
	msgbox NHML1_Trigger_Juan_Text_1, MSGBOX_AUTOCLOSE
	waitmessage
	fadescreen FADE_TO_BLACK
	msgbox NHML1_Trigger_Juan_Text_2, MSGBOX_AUTOCLOSE
	waitmessage
	fadescreen FADE_FROM_BLACK
	msgbox NHML1_Trigger_Juan_Text_3, MSGBOX_AUTOCLOSE
	waitmessage
	getpartymonslot SPECIES_YAMASK
	special DeletePartyMon
	setflag FLAG_GIVE_BACK_MUNCHLAX
	givemon SPECIES_MUNCHLAX, 20, ITEM_LAGGING_TAIL
	msgbox NHML1_Trigger_Juan_Text_4
	waitmessage
	setflag FLAG_NHML1_YAMASK_TAKEN
	setflag FLAG_GOT_LAGGING_TAIL
	setflag FLAG_NHML3_Trader
	goto NHML1_Trigger_Juan_1


NHML1_Trigger_Final_Battle_Up::
	lock
	clearflag FLAG_NHML1_FINAL_BATTLE
	addobject 6, MAP_NATIONAL_HISTORY_MUSEUM_L1
	setobjectxy 6, 21, 17
	applymovement 6, Move_to_uppos
	waitmovement 0
	setorcopyvar VAR_FINAL_BATTLE, 1
	release
	call NHML1_Cooltrainer
	end


NHML1_Trigger_Final_Battle_Dn::
	lock
	clearflag FLAG_NHML1_FINAL_BATTLE
	addobject 6, MAP_NATIONAL_HISTORY_MUSEUM_L1
	setobjectxy 6, 21, 17
	applymovement 6, Move_to_dnpos
	waitmovement 0
	setorcopyvar VAR_FINAL_BATTLE, 1
	release
	call NHML1_Cooltrainer
	end


NHML1_Counter::
	lock
	setrespawn HEAL_LOCATION_NATIONAL_HISTORY_MUSEUM_F1
	msgbox NHML1_Counter_Text_0, MSGBOX_AUTOCLOSE
	waitmessage
	setorcopyvar VAR_NHML1_COUNTER_TRIGGER, 1
	release
	end


NHML1_FinishGame::
	lock
	fadescreen FADE_TO_BLACK
	special StopPlayTimer
	specialvar VAR_RESULT, GetPlayTimeHours
	buffernumberstring STR_VAR_1, VAR_RESULT
	specialvar VAR_RESULT, GetPlayTimeMinutes
	buffertimestring STR_VAR_2, VAR_RESULT
	specialvar VAR_RESULT, GetPlayTimeSeconds
	buffertimestring STR_VAR_3, VAR_RESULT
	msgbox Text_Finale
	waitmessage
	setorcopyvar VAR_NHML1_COUNT, 0
	goto_if_set FLAG_HINT01, NHML1_FinishGame_2
NHML1_FinishGame_1:
	goto_if_set FLAG_HINT02, NHML1_FinishGame_5
NHML1_FinishGame_4:
	goto_if_set FLAG_HINT03, NHML1_FinishGame_8
NHML1_FinishGame_7:
	goto_if_set FLAG_HINT04, NHML1_FinishGame_11
NHML1_FinishGame_10:
	goto_if_set FLAG_HINT05, NHML1_FinishGame_14
NHML1_FinishGame_13:
	goto_if_set FLAG_HINT06, NHML1_FinishGame_17
NHML1_FinishGame_16:
	goto_if_set FLAG_HINT07, NHML1_FinishGame_20
NHML1_FinishGame_19:
	goto_if_set FLAG_HINT08, NHML1_FinishGame_23
NHML1_FinishGame_22:
	goto_if_set FLAG_HINT09, NHML1_FinishGame_26
NHML1_FinishGame_25:
	goto_if_set FLAG_HINT10, NHML1_FinishGame_29
NHML1_FinishGame_28:
	goto_if_set FLAG_HINT11, NHML1_FinishGame_32
NHML1_FinishGame_31:
	goto_if_set FLAG_HINT12, NHML1_FinishGame_35
NHML1_FinishGame_34:
	goto_if_set FLAG_HINT13, NHML1_FinishGame_38
NHML1_FinishGame_37:
	goto_if_set FLAG_HINT14, NHML1_FinishGame_41
NHML1_FinishGame_40:
	goto_if_set FLAG_HINT15, NHML1_FinishGame_44
NHML1_FinishGame_43:
	goto_if_set FLAG_HINT16, NHML1_FinishGame_47
NHML1_FinishGame_46:
	goto_if_set FLAG_HINT17, NHML1_FinishGame_50
NHML1_FinishGame_49:
	goto_if_set FLAG_HINT18, NHML1_FinishGame_53
NHML1_FinishGame_52:
	goto_if_set FLAG_HINT19, NHML1_FinishGame_56
NHML1_FinishGame_55:
	goto_if_set FLAG_HINT20, NHML1_FinishGame_59
NHML1_FinishGame_58:
	buffernumberstring STR_VAR_1, VAR_NHML1_COUNT
	msgbox Text_Finale_Hints
	waitmessage
	fadescreen FADE_FROM_BLACK
	fadescreen FADE_TO_BLACK
	special StartCredits
	end

NHML1_FinishGame_2:
	addvar VAR_NHML1_COUNT, 1
	goto NHML1_FinishGame_1

NHML1_FinishGame_5:
	addvar VAR_NHML1_COUNT, 1
	goto NHML1_FinishGame_4

NHML1_FinishGame_8:
	addvar VAR_NHML1_COUNT, 1
	goto NHML1_FinishGame_7

NHML1_FinishGame_11:
	addvar VAR_NHML1_COUNT, 1
	goto NHML1_FinishGame_10

NHML1_FinishGame_14:
	addvar VAR_NHML1_COUNT, 1
	goto NHML1_FinishGame_13

NHML1_FinishGame_17:
	addvar VAR_NHML1_COUNT, 1
	goto NHML1_FinishGame_16

NHML1_FinishGame_20:
	addvar VAR_NHML1_COUNT, 1
	goto NHML1_FinishGame_19

NHML1_FinishGame_23:
	addvar VAR_NHML1_COUNT, 1
	goto NHML1_FinishGame_22

NHML1_FinishGame_26:
	addvar VAR_NHML1_COUNT, 1
	goto NHML1_FinishGame_25

NHML1_FinishGame_29:
	addvar VAR_NHML1_COUNT, 1
	goto NHML1_FinishGame_28

NHML1_FinishGame_32:
	addvar VAR_NHML1_COUNT, 1
	goto NHML1_FinishGame_31

NHML1_FinishGame_35:
	addvar VAR_NHML1_COUNT, 1
	goto NHML1_FinishGame_34

NHML1_FinishGame_38:
	addvar VAR_NHML1_COUNT, 1
	goto NHML1_FinishGame_37

NHML1_FinishGame_41:
	addvar VAR_NHML1_COUNT, 1
	goto NHML1_FinishGame_40

NHML1_FinishGame_44:
	addvar VAR_NHML1_COUNT, 1
	goto NHML1_FinishGame_43

NHML1_FinishGame_47:
	addvar VAR_NHML1_COUNT, 1
	goto NHML1_FinishGame_46

NHML1_FinishGame_50:
	addvar VAR_NHML1_COUNT, 1
	goto NHML1_FinishGame_49

NHML1_FinishGame_53:
	addvar VAR_NHML1_COUNT, 1
	goto NHML1_FinishGame_52

NHML1_FinishGame_56:
	addvar VAR_NHML1_COUNT, 1
	goto NHML1_FinishGame_55

NHML1_FinishGame_59:
	addvar VAR_NHML1_COUNT, 1
	goto NHML1_FinishGame_58


NHML1_Sign_Brochures::
	lock
	msgbox NHML1_Sign_Brochures_Text_0, MSGBOX_AUTOCLOSE
	waitmessage
	release
	end


NHML1_Sign_Flame_Orb::
	lock
	showmonpic SPECIES_MUNCHLAX, 10, 3
	setvar VAR_0x8006, ITEM_FLAME_ORB
	showitemdesc
	msgbox NHML1_Sign_Flame_Orb_Text_0
	waitmessage
	hidemonpic
	hideitemdesc
	release
	end


NHML1_Sign_Replica::
	lock
	msgbox NHML1_Sign_Replica_Text_0
	waitmessage
	release
	end


NHML1_Sign_CavePainting::
	lock
	msgbox NHML1_Sign_CavePainting_Text_0
	waitmessage
	release
	end


NHML1_Sign_Tent::
	lock
	msgbox NHML1_Sign_Tent_Text_0
	waitmessage
	release
	end


NHML1_Sign_Desk::
	lock
	msgbox NHML1_Sign_Desk_Text_0
	waitmessage
	release
	end


NHML1_Sign_tileset::
	lock
	msgbox NHML1_Sign_tileset_Text_0, MSGBOX_AUTOCLOSE
	waitmessage
	release
	end


Move_lookup:
	face_up
	step_end

Move_to_uppos:
	face_up
	walk_up
	face_left
	walk_left
	walk_left
	walk_left
	step_end

Move_to_dnpos:
	face_up
	face_left
	walk_left
	walk_left
	walk_left
	step_end

NHML1_Judge_Text_0:
	.string "What an exquisite place!\l"
	.string "All these artifacts are just\l"
	.string "mezmerizing.\p"
	.string "And have you noticed these special\n"
	.string "WALLPAPERS they display?\l"
	.string "Wonderful!$"

NHML1_ItemBall_Text_0:
	.string "You found an abandoned PokeBall with a\n"
	.string "SKITTY inside.$"

NHML1_Cooltrainer_Text_0:
	.string "Oh hey, where are you trying to go?$"

NHML1_Cooltrainer_Text_1:
	.string "Bye, bye!$"

NHML1_Juan_Text_0:
	.string "I am sorry for any inconvenience!$"

NHML1_Trigger_Juan_Text_0:
	.string "Where did you get this Yamask from?\l"
	.string "It's part of our Egyptian exhibition!$"

NHML1_Trigger_Juan_Text_1:
	.string "Someone traded it to you for MUNCHLAX?\p"
	.string "Please let me clarify this.$"

NHML1_Trigger_Juan_Text_2:
	.string "...$"

NHML1_Trigger_Juan_Text_3:
	.string "I am sorry, you will have to return it to\n"
	.string "me.\p"
	.string "However, I managed to get the kid you\n"
	.string "traded with and will give you MUNCHLAX\l"
	.string "back in return!$"

NHML1_Trigger_Juan_Text_4:
	.string "{PLAYER} handed over YAMASK and\n"
	.string "received MUNCHLAX back.$"

NHML1_Counter_Text_0:
	.string "Good bye!\p"
	.string "Thank you for visiting us!$"

NHML1_Sign_Brochures_Text_0:
	.string "Just some brochures about upcoming\n"
	.string "exhibitions.$"

NHML1_Sign_Flame_Orb_Text_0:
	.string "The papers on the shelf are showing two\n"
	.string "pictures.$"

NHML1_Sign_Replica_Text_0:
	.string "A very realistic replica of a Mamoswine.$"

NHML1_Sign_CavePainting_Text_0:
	.string "An old stone plate showing ancient cave\n"
	.string "paintings.$"

NHML1_Sign_Tent_Text_0:
	.string "The replica of a tent from the Ice Age.$"

NHML1_Sign_Desk_Text_0:
	.string "Thank you for your visit!$"

NHML1_Sign_tileset_Text_0:
	.string "Parts of this tileset have originally\n"
	.string "been designed by princess-phoenix,\l"
	.string "aveontrainer and rbrnnova.$"

Text_Finale::
	.string "Congratulations {PLAYER}!\p"
	.string "You have completed the challenge. Well\n"
	.string "done!\p"
	.string "Your final time is\n"
	.string "{STR_VAR_1}:{STR_VAR_2}:{STR_VAR_3}.$"

Text_Finale_Hints::
	.string "You have been using {STR_VAR_1}\n"
	.string "hint(s).$"
