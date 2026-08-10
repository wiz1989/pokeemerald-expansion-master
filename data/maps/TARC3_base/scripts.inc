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


TARC3_Base_Wooper::
# 17 "data/maps/TARC3_base/scripts.pory"
	goto TARC3_Base_Dewpider
	return


TARC3_Base_Paras::
# 24 "data/maps/TARC3_base/scripts.pory"
	cant_see_if_set FLAG_BASE_PARAS_BEATEN
# 25 "data/maps/TARC3_base/scripts.pory"
	lock
# 26 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 27 "data/maps/TARC3_base/scripts.pory"
	createfieldmugshot MUGSHOT_TEST, EMOTE_NORMAL
# 28 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Base_Paras_Text_0
# 29 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_PARAS_BEATEN, TARC3_Base_Paras_2
# 35 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Base_Paras_Text_2
# 36 "data/maps/TARC3_base/scripts.pory"
	setwildbattle SPECIES_PARAS, 25
# 37 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_PARAS, CRY_MODE_ENCOUNTER
# 38 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 39 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 40 "data/maps/TARC3_base/scripts.pory"
	dowildbattle
# 41 "data/maps/TARC3_base/scripts.pory"
	callnative WasBattleWon
# 42 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Base_Paras_5
TARC3_Base_Paras_1:
# 47 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Base_Paras_2:
# 31 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Base_Paras_Text_1
	goto TARC3_Base_Paras_1

TARC3_Base_Paras_5:
# 44 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_BASE_PARAS_BEATEN
	goto TARC3_Base_Paras_1


TARC3_Base_Vulpix::
# 52 "data/maps/TARC3_base/scripts.pory"
	cant_see_if_set FLAG_BASE_VULPIX_BEATEN
# 53 "data/maps/TARC3_base/scripts.pory"
	lock
# 54 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 55 "data/maps/TARC3_base/scripts.pory"
	createfieldmugshot MUGSHOT_TEST, EMOTE_NORMAL
# 56 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Base_Vulpix_Text_0
# 57 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_VULPIX_BEATEN, TARC3_Base_Vulpix_2
# 63 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Base_Vulpix_Text_1
# 64 "data/maps/TARC3_base/scripts.pory"
	setwildbattle SPECIES_VULPIX, 25
# 65 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_VULPIX, CRY_MODE_ENCOUNTER
# 66 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 67 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 68 "data/maps/TARC3_base/scripts.pory"
	dowildbattle
# 69 "data/maps/TARC3_base/scripts.pory"
	callnative WasBattleWon
# 70 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Base_Vulpix_5
TARC3_Base_Vulpix_1:
# 75 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Base_Vulpix_2:
# 59 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Base_Paras_Text_1
	goto TARC3_Base_Vulpix_1

TARC3_Base_Vulpix_5:
# 72 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_BASE_VULPIX_BEATEN
	goto TARC3_Base_Vulpix_1


TARC3_Base_Dewpider::
# 80 "data/maps/TARC3_base/scripts.pory"
	cant_see_if_set FLAG_BASE_DEWPIDER_BEATEN
# 81 "data/maps/TARC3_base/scripts.pory"
	lock
# 82 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 83 "data/maps/TARC3_base/scripts.pory"
	createfieldmugshot MUGSHOT_TEST, EMOTE_NORMAL
# 84 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Base_Dewpider_Text_0
# 85 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_DEWPIDER_BEATEN, TARC3_Base_Dewpider_2
# 91 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Base_Dewpider_Text_1
# 92 "data/maps/TARC3_base/scripts.pory"
	setwildbattle SPECIES_DEWPIDER, 25
# 93 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_DEWPIDER, CRY_MODE_ENCOUNTER
# 94 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 95 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 96 "data/maps/TARC3_base/scripts.pory"
	dowildbattle
# 97 "data/maps/TARC3_base/scripts.pory"
	callnative WasBattleWon
# 98 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Base_Dewpider_5
TARC3_Base_Dewpider_1:
# 103 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Base_Dewpider_2:
# 87 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Base_Paras_Text_1
	goto TARC3_Base_Dewpider_1

TARC3_Base_Dewpider_5:
# 100 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_BASE_DEWPIDER_BEATEN
	goto TARC3_Base_Dewpider_1


TARC3_Base_Wooper_backup::
# 108 "data/maps/TARC3_base/scripts.pory"
	cant_see_if_set FLAG_BASE_WOOPER_BEATEN
# 109 "data/maps/TARC3_base/scripts.pory"
	lock
# 110 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 111 "data/maps/TARC3_base/scripts.pory"
	createfieldmugshot MUGSHOT_WOOPER, EMOTE_NORMAL
# 112 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Base_Wooper_backup_Text_0
# 113 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_WOOPER_BEATEN, TARC3_Base_Wooper_backup_2
# 119 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Base_Wooper_backup_Text_2
# 120 "data/maps/TARC3_base/scripts.pory"
	setwildbattle SPECIES_WOOPER, 25
# 121 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_WOOPER, CRY_MODE_ENCOUNTER
# 122 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 123 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 124 "data/maps/TARC3_base/scripts.pory"
	dowildbattle
# 125 "data/maps/TARC3_base/scripts.pory"
	callnative WasBattleWon
# 126 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Base_Wooper_backup_5
TARC3_Base_Wooper_backup_1:
# 131 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Base_Wooper_backup_2:
# 115 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Base_Wooper_backup_Text_1
	goto TARC3_Base_Wooper_backup_1

TARC3_Base_Wooper_backup_5:
# 128 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_BASE_WOOPER_BEATEN
	goto TARC3_Base_Wooper_backup_1


TARC3_Base_Torkoal::
# 136 "data/maps/TARC3_base/scripts.pory"
	cant_see_if_set FLAG_BASE_TORKOAL_BEATEN
# 137 "data/maps/TARC3_base/scripts.pory"
	lock
# 138 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 139 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Base_Torkoal_Text_0
# 140 "data/maps/TARC3_base/scripts.pory"
	createfieldmugshot MUGSHOT_TORKOAL, EMOTE_ALT
# 141 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_TORKOAL_BEATEN, TARC3_Base_Torkoal_2
# 147 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Base_Torkoal_Text_1
# 148 "data/maps/TARC3_base/scripts.pory"
	setwildbattle SPECIES_TORKOAL, 25
# 149 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_TORKOAL, CRY_MODE_ENCOUNTER
# 150 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 151 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 152 "data/maps/TARC3_base/scripts.pory"
	dowildbattle
# 153 "data/maps/TARC3_base/scripts.pory"
	callnative WasBattleWon
# 154 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Base_Torkoal_5
TARC3_Base_Torkoal_1:
# 159 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Base_Torkoal_2:
# 143 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Base_Paras_Text_1
	goto TARC3_Base_Torkoal_1

TARC3_Base_Torkoal_5:
# 156 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_BASE_TORKOAL_BEATEN
	goto TARC3_Base_Torkoal_1


TARC3_Base_Paras_Text_0:
# 28 "data/maps/TARC3_base/scripts.pory"
	.string "Paras$"

TARC3_Base_Paras_Text_1:
# 31 "data/maps/TARC3_base/scripts.pory"
	.string "I still like you!$"

TARC3_Base_Paras_Text_2:
# 35 "data/maps/TARC3_base/scripts.pory"
	.string "Hi, I'm PARAS.\nLet's battle!$"

TARC3_Base_Vulpix_Text_0:
# 56 "data/maps/TARC3_base/scripts.pory"
	.string "Vulpix$"

TARC3_Base_Vulpix_Text_1:
# 63 "data/maps/TARC3_base/scripts.pory"
	.string "Hi, I'm VULPIX.\nLet's battle!$"

TARC3_Base_Dewpider_Text_0:
# 84 "data/maps/TARC3_base/scripts.pory"
	.string "Dewpider$"

TARC3_Base_Dewpider_Text_1:
# 91 "data/maps/TARC3_base/scripts.pory"
	.string "Hi, I'm DEWPIDER.\nLet's battle!$"

TARC3_Base_Wooper_backup_Text_0:
# 112 "data/maps/TARC3_base/scripts.pory"
	.string "Wooper$"

TARC3_Base_Wooper_backup_Text_1:
# 115 "data/maps/TARC3_base/scripts.pory"
	.string "Hey, my berry!$"

TARC3_Base_Wooper_backup_Text_2:
# 119 "data/maps/TARC3_base/scripts.pory"
	.string "Hi, I'm WOOPER.\nLet's battle!$"

TARC3_Base_Torkoal_Text_0:
# 139 "data/maps/TARC3_base/scripts.pory"
	.string "Torkoal$"

TARC3_Base_Torkoal_Text_1:
# 147 "data/maps/TARC3_base/scripts.pory"
	.string "Hi, I'm TORKOAL.\nLet's battle!$"
