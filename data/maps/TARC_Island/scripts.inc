TARC_Island_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, TARC_Island_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, TARC_Island_OnTransition
	.byte 0


TARC_Island_OnResume::
	setvar VAR_TEMP_2, 0
	return


TARC_Island_OnTransition::
	setrespawn HEAL_LOCATION_TARC_ISLAND
	return


TARC_Island_Fisherman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_OLD_ROD, TARC_Island_Fisherman_2
	msgbox TARC_Island_Fisherman_Text_0, MSGBOX_AUTOCLOSE
	giveitem ITEM_OLD_ROD
	setflag FLAG_RECEIVED_OLD_ROD
	msgbox TARC_Island_Fisherman_Text_1, MSGBOX_AUTOCLOSE
TARC_Island_Fisherman_1:
	release
	end

TARC_Island_Fisherman_2:
	goto TARC_Island_Fisherman_1


TARC_Island_Fisherman_Text_0:
	.string "I am stranded here and try to catch\n"
	.string "some fish to survive.\p"
	.string "But these are shark infested waters!\p"
	.string "I don't get anything else to bite.\p"
	.string "Take this rod of mine.$"

TARC_Island_Fisherman_Text_1:
	.string "And please think of me if you are\n"
	.string "getting luckier than I am.$"
