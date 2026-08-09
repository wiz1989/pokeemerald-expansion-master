TARC3_base_MapScripts::
# 2 "data/maps/TARC3_base/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, TARC3_Base_OnResume
	.byte 0


TARC3_Base_OnResume::
# 6 "data/maps/TARC3_base/scripts.pory"
	setstepcallback STEP_CB_CLAY_TILES
	end


TARC3_Base_Sunkern::
# 13 "data/maps/TARC3_base/scripts.pory"
	goto TARC3_Base_Paras
	return


TARC3_Base_Paras::
# 19 "data/maps/TARC3_base/scripts.pory"
	cant_see_if_set FLAG_BASE_PARAS_BEATEN
# 20 "data/maps/TARC3_base/scripts.pory"
	lock
# 21 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 22 "data/maps/TARC3_base/scripts.pory"
	createfieldmugshot MUGSHOT_TEST, EMOTE_NORMAL
# 23 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Base_Paras_Text_0
# 24 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_PARAS_BEATEN, TARC3_Base_Paras_2
# 30 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Base_Paras_Text_2
# 31 "data/maps/TARC3_base/scripts.pory"
	setwildbattle SPECIES_PARAS, 25
# 32 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_PARAS, CRY_MODE_ENCOUNTER
# 33 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 34 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 35 "data/maps/TARC3_base/scripts.pory"
	dowildbattle
# 36 "data/maps/TARC3_base/scripts.pory"
	callnative WasBattleWon
# 37 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Base_Paras_5
TARC3_Base_Paras_1:
# 42 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Base_Paras_2:
# 26 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Base_Paras_Text_1
	goto TARC3_Base_Paras_1

TARC3_Base_Paras_5:
# 39 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_BASE_PARAS_BEATEN
	goto TARC3_Base_Paras_1


TARC3_Base_Vulpix::
# 47 "data/maps/TARC3_base/scripts.pory"
	cant_see_if_set FLAG_BASE_VULPIX_BEATEN
# 48 "data/maps/TARC3_base/scripts.pory"
	lock
# 49 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 50 "data/maps/TARC3_base/scripts.pory"
	createfieldmugshot MUGSHOT_TEST, EMOTE_NORMAL
# 51 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Base_Vulpix_Text_0
# 52 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_VULPIX_BEATEN, TARC3_Base_Vulpix_2
# 58 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Base_Vulpix_Text_1
# 59 "data/maps/TARC3_base/scripts.pory"
	setwildbattle SPECIES_VULPIX, 25
# 60 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_VULPIX, CRY_MODE_ENCOUNTER
# 61 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 62 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 63 "data/maps/TARC3_base/scripts.pory"
	dowildbattle
# 64 "data/maps/TARC3_base/scripts.pory"
	callnative WasBattleWon
# 65 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Base_Vulpix_5
TARC3_Base_Vulpix_1:
# 70 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Base_Vulpix_2:
# 54 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Base_Paras_Text_1
	goto TARC3_Base_Vulpix_1

TARC3_Base_Vulpix_5:
# 67 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_BASE_VULPIX_BEATEN
	goto TARC3_Base_Vulpix_1


TARC3_Base_Wooper::
# 75 "data/maps/TARC3_base/scripts.pory"
	cant_see_if_set FLAG_BASE_WOOPER_BEATEN
# 76 "data/maps/TARC3_base/scripts.pory"
	lock
# 77 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 78 "data/maps/TARC3_base/scripts.pory"
	createfieldmugshot MUGSHOT_WOOPER, EMOTE_NORMAL
# 79 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Base_Wooper_Text_0
# 80 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_WOOPER_BEATEN, TARC3_Base_Wooper_2
# 86 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Base_Wooper_Text_2
# 87 "data/maps/TARC3_base/scripts.pory"
	setwildbattle SPECIES_WOOPER, 25
# 88 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_WOOPER, CRY_MODE_ENCOUNTER
# 89 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 90 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 91 "data/maps/TARC3_base/scripts.pory"
	dowildbattle
# 92 "data/maps/TARC3_base/scripts.pory"
	callnative WasBattleWon
# 93 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Base_Wooper_5
TARC3_Base_Wooper_1:
# 98 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Base_Wooper_2:
# 82 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Base_Wooper_Text_1
	goto TARC3_Base_Wooper_1

TARC3_Base_Wooper_5:
# 95 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_BASE_WOOPER_BEATEN
	goto TARC3_Base_Wooper_1


TARC3_Base_Torkoal::
# 103 "data/maps/TARC3_base/scripts.pory"
	cant_see_if_set FLAG_BASE_TORKOAL_BEATEN
# 104 "data/maps/TARC3_base/scripts.pory"
	lock
# 105 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 106 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Base_Torkoal_Text_0
# 107 "data/maps/TARC3_base/scripts.pory"
	createfieldmugshot MUGSHOT_TORKOAL, EMOTE_ALT
# 108 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_TORKOAL_BEATEN, TARC3_Base_Torkoal_2
# 114 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Base_Torkoal_Text_1
# 115 "data/maps/TARC3_base/scripts.pory"
	setwildbattle SPECIES_TORKOAL, 25
# 116 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_TORKOAL, CRY_MODE_ENCOUNTER
# 117 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 118 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 119 "data/maps/TARC3_base/scripts.pory"
	dowildbattle
# 120 "data/maps/TARC3_base/scripts.pory"
	callnative WasBattleWon
# 121 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Base_Torkoal_5
TARC3_Base_Torkoal_1:
# 126 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Base_Torkoal_2:
# 110 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Base_Paras_Text_1
	goto TARC3_Base_Torkoal_1

TARC3_Base_Torkoal_5:
# 123 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_BASE_TORKOAL_BEATEN
	goto TARC3_Base_Torkoal_1


TARC3_Base_Paras_Text_0:
# 23 "data/maps/TARC3_base/scripts.pory"
	.string "Paras$"

TARC3_Base_Paras_Text_1:
# 26 "data/maps/TARC3_base/scripts.pory"
	.string "I still like you!$"

TARC3_Base_Paras_Text_2:
# 30 "data/maps/TARC3_base/scripts.pory"
	.string "Hi, I'm PARAS.\nLet's battle!$"

TARC3_Base_Vulpix_Text_0:
# 51 "data/maps/TARC3_base/scripts.pory"
	.string "Vulpix$"

TARC3_Base_Vulpix_Text_1:
# 58 "data/maps/TARC3_base/scripts.pory"
	.string "Hi, I'm VULPIX.\nLet's battle!$"

TARC3_Base_Wooper_Text_0:
# 79 "data/maps/TARC3_base/scripts.pory"
	.string "Wooper$"

TARC3_Base_Wooper_Text_1:
# 82 "data/maps/TARC3_base/scripts.pory"
	.string "Hey, my berry!$"

TARC3_Base_Wooper_Text_2:
# 86 "data/maps/TARC3_base/scripts.pory"
	.string "Hi, I'm WOOPER.\nLet's battle!$"

TARC3_Base_Torkoal_Text_0:
# 106 "data/maps/TARC3_base/scripts.pory"
	.string "Torkoal$"

TARC3_Base_Torkoal_Text_1:
# 114 "data/maps/TARC3_base/scripts.pory"
	.string "Hi, I'm TORKOAL.\nLet's battle!$"
