TARC3_WeatherInstitute_2F_MapScripts::
# 2 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TARC3_WeatherInstitute_2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

TARC3_WeatherInstitute_2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 3 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	map_script_2 VAR_TRIGGER_XATU_EVENT, 1, TARC3_WeatherInstitute_2F_AutoWalkToXatu
	.2byte 0


TARC3_WeatherInstitute_2F_AutoWalkToXatu::
# 9 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	setvar VAR_TRIGGER_XATU_EVENT, 0
# 10 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	compare VAR_CASTFORM_PHASE, 1
	goto_if_eq TARC3_WeatherInstitute_2F_AutoWalkToXatu_3
TARC3_WeatherInstitute_2F_AutoWalkToXatu_1:
# 20 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	compare VAR_CASTFORM_PHASE, 2
	goto_if_eq TARC3_WeatherInstitute_2F_AutoWalkToXatu_8
TARC3_WeatherInstitute_2F_AutoWalkToXatu_6:
	end

TARC3_WeatherInstitute_2F_AutoWalkToXatu_2:
# 12 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	clearflag FLAG_RUN_XATU_AMBER
# 13 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	applymovement LOCALID_PLAYER, Movement_ToXatu
# 14 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	waitmovement 0
# 15 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	setvar VAR_LAST_TALKED, LOCALID_TARC3_WEATHER_INSTITUTE_2F_XATU
# 16 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	lock
# 17 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	turnobject LOCALID_TARC3_WEATHER_INSTITUTE_2F_XATU, DIR_WEST
# 18 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	goto TARC3_Lab_F2_Xatu
	goto TARC3_WeatherInstitute_2F_AutoWalkToXatu_1

TARC3_WeatherInstitute_2F_AutoWalkToXatu_3:
# 10 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	goto_if_set FLAG_RUN_XATU_AMBER, TARC3_WeatherInstitute_2F_AutoWalkToXatu_2
	goto TARC3_WeatherInstitute_2F_AutoWalkToXatu_1

TARC3_WeatherInstitute_2F_AutoWalkToXatu_7:
# 22 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	clearflag FLAG_RUN_XATU_AZURE
# 23 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	applymovement LOCALID_PLAYER, Movement_ToXatu
# 24 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	waitmovement 0
# 25 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	setvar VAR_LAST_TALKED, LOCALID_TARC3_WEATHER_INSTITUTE_2F_XATU
# 26 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	lock
# 27 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	turnobject LOCALID_TARC3_WEATHER_INSTITUTE_2F_XATU, DIR_WEST
# 28 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	goto TARC3_Lab_F2_Xatu
	goto TARC3_WeatherInstitute_2F_AutoWalkToXatu_6

TARC3_WeatherInstitute_2F_AutoWalkToXatu_8:
# 20 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	goto_if_set FLAG_RUN_XATU_AZURE, TARC3_WeatherInstitute_2F_AutoWalkToXatu_7
	goto TARC3_WeatherInstitute_2F_AutoWalkToXatu_6


# 33 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
Movement_ToXatu:
# 34 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	walk_right
# 34 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	walk_right
# 35 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	walk_up
# 35 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	walk_up
# 35 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	walk_up
# 35 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	walk_up
# 36 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	walk_right
	step_end

TARC3_Lab_F2_Psyduck::
# 42 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	lock
# 43 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	faceplayer
# 44 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	playmoncry SPECIES_PSYDUCK, CRY_MODE_NORMAL
# 45 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	setspeaker TARC3_Lab_F2_Psyduck_Text_0
# 46 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	msgbox TARC3_Lab_F2_Psyduck_Text_1
# 47 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	release
	end


TARC3_Lab_F2_Porygon::
# 52 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	lock
# 53 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	faceplayer
# 54 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	playmoncry SPECIES_PORYGON, CRY_MODE_NORMAL
# 55 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	setspeaker TARC3_Lab_F2_Porygon_Text_0
# 56 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	msgbox TARC3_Lab_F2_Porygon_Text_1
# 57 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	release
	end


TARC3_Lab_F2_Xatu_Manual::
# 62 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	lock
# 63 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	faceplayer
# 64 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	playmoncry SPECIES_XATU, CRY_MODE_NORMAL
# 65 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	setspeaker TARC3_Lab_F2_Xatu_Manual_Text_0
# 67 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	switch VAR_CASTFORM_PHASE
# 69 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	case 0, TARC3_Lab_F2_Xatu_Manual_3
# 71 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	case 1, TARC3_Lab_F2_Xatu_Manual_4
# 73 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	case 2, TARC3_Lab_F2_Xatu_Manual_5
# 75 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	case 3, TARC3_Lab_F2_Xatu_Manual_6
# 78 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	msgbox TARC3_Lab_F2_Xatu_Manual_Text_1
TARC3_Lab_F2_Xatu_Manual_1:
# 81 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	release
	end

TARC3_Lab_F2_Xatu_Manual_3:
# 70 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	msgbox TARC3_Lab_F2_Xatu_Manual_Text_1
	goto TARC3_Lab_F2_Xatu_Manual_1

TARC3_Lab_F2_Xatu_Manual_4:
# 72 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	msgbox TARC3_Lab_F2_Xatu_Manual_Text_2
	goto TARC3_Lab_F2_Xatu_Manual_1

TARC3_Lab_F2_Xatu_Manual_5:
# 74 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	msgbox TARC3_Lab_F2_Xatu_Manual_Text_3
	goto TARC3_Lab_F2_Xatu_Manual_1

TARC3_Lab_F2_Xatu_Manual_6:
# 76 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	msgbox TARC3_Lab_F2_Xatu_Manual_Text_4
	goto TARC3_Lab_F2_Xatu_Manual_1


TARC3_Lab_F2_Xatu::
# 86 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	playmoncry SPECIES_XATU, CRY_MODE_NORMAL
# 87 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	setspeaker TARC3_Lab_F2_Xatu_Manual_Text_0
# 89 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	switch VAR_CASTFORM_PHASE
# 91 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	case 0, TARC3_Lab_F2_Xatu_3
# 93 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	case 1, TARC3_Lab_F2_Xatu_4
# 100 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	case 2, TARC3_Lab_F2_Xatu_5
# 107 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	case 3, TARC3_Lab_F2_Xatu_6
# 110 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	msgbox TARC3_Lab_F2_Xatu_Manual_Text_1
TARC3_Lab_F2_Xatu_1:
# 113 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	release
	end

TARC3_Lab_F2_Xatu_3:
# 92 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	msgbox TARC3_Lab_F2_Xatu_Manual_Text_1
	goto TARC3_Lab_F2_Xatu_1

TARC3_Lab_F2_Xatu_4:
# 94 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	msgbox TARC3_Lab_F2_Xatu_Text_0
# 95 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	fadescreen FADE_TO_WHITE
# 96 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	special HealPlayerParty
# 97 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	delay 60
# 98 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	fadescreen FADE_FROM_WHITE
# 99 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	msgbox TARC3_Lab_F2_Xatu_Text_1
	goto TARC3_Lab_F2_Xatu_1

TARC3_Lab_F2_Xatu_5:
# 101 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	msgbox TARC3_Lab_F2_Xatu_Text_2
# 102 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	fadescreen FADE_TO_WHITE
# 103 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	special HealPlayerParty
# 104 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	delay 60
# 105 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	fadescreen FADE_FROM_WHITE
# 106 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	msgbox TARC3_Lab_F2_Xatu_Text_3
	goto TARC3_Lab_F2_Xatu_1

TARC3_Lab_F2_Xatu_6:
# 108 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	msgbox TARC3_Lab_F2_Xatu_Manual_Text_1
	goto TARC3_Lab_F2_Xatu_1


TARC3_Lab_F2_Psyduck_Text_0:
# 45 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	.string "Psyduck$"

TARC3_Lab_F2_Psyduck_Text_1:
# 46 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	.string "Oh no oh no oh no...$"

TARC3_Lab_F2_Porygon_Text_0:
# 55 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	.string "Porygon Z$"

TARC3_Lab_F2_Porygon_Text_1:
# 56 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	.string "The professor is acting dubious.\pI don't understand the issue.\pLife is a simulation anyways.$"

TARC3_Lab_F2_Xatu_Manual_Text_0:
# 65 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	.string "Prof. Xatu$"

TARC3_Lab_F2_Xatu_Manual_Text_1:
# 70 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	.string "Please help us find the missing\nweather shards!\pYou are our only help!$"

TARC3_Lab_F2_Xatu_Manual_Text_2:
# 72 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	.string "That's the Amber Shard!\nFantastic!\pYou can now change the weather to sun\nwhenever you want!\pJust press SELECT when you are\noutside or L/R in battle.$"

TARC3_Lab_F2_Xatu_Manual_Text_3:
# 74 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	.string "That's the Azure Shard!\pNow you can also summon the rain.$"

TARC3_Lab_F2_Xatu_Manual_Text_4:
# 76 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	.string "That's the Glacial Shard!\pIt grants you the power to summon snow.$"

TARC3_Lab_F2_Xatu_Text_0:
# 94 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	.string "That's the Amber Shard!\nFantastic!\pLet me help you unleash its power!$"

TARC3_Lab_F2_Xatu_Text_1:
# 99 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	.string "You can now change the weather to sun\nwhenever you want!\pJust press SELECT when you are\noutside or L/R in battle.$"

TARC3_Lab_F2_Xatu_Text_2:
# 101 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	.string "Wow!\nThat's the Azure Shard!\pWith it you can also summon the rain.\pLet me activate it's power.$"

TARC3_Lab_F2_Xatu_Text_3:
# 106 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	.string "You are making great progress!\pI believe you can also find\nthe last missing piece!$"
