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
	cant_see_if_set FLAG_BASE_SUNKERN_BEATEN
# 14 "data/maps/TARC3_base/scripts.pory"
	lock
# 15 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 16 "data/maps/TARC3_base/scripts.pory"
	createfieldmugshot MUGSHOT_SUNKERN, EMOTE_NORMAL
# 17 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Base_Sunkern_Text_0
# 18 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_SUNKERN_BEATEN, TARC3_Base_Sunkern_2
# 24 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Base_Sunkern_Text_2
# 25 "data/maps/TARC3_base/scripts.pory"
	setwildbattle SPECIES_SUNKERN, 25
# 26 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_SUNKERN, CRY_MODE_ENCOUNTER
# 27 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 28 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 29 "data/maps/TARC3_base/scripts.pory"
	dowildbattle
# 30 "data/maps/TARC3_base/scripts.pory"
	callnative WasBattleWon
# 31 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Base_Sunkern_5
TARC3_Base_Sunkern_1:
# 36 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Base_Sunkern_2:
# 20 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Base_Sunkern_Text_1
	goto TARC3_Base_Sunkern_1

TARC3_Base_Sunkern_5:
# 33 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_BASE_SUNKERN_BEATEN
	goto TARC3_Base_Sunkern_1


TARC3_Base_Wooper::
# 41 "data/maps/TARC3_base/scripts.pory"
	cant_see_if_set FLAG_BASE_WOOPER_BEATEN
# 42 "data/maps/TARC3_base/scripts.pory"
	lock
# 43 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 44 "data/maps/TARC3_base/scripts.pory"
	createfieldmugshot MUGSHOT_WOOPER, EMOTE_NORMAL
# 45 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Base_Wooper_Text_0
# 46 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_WOOPER_BEATEN, TARC3_Base_Wooper_2
# 52 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Base_Wooper_Text_2
# 53 "data/maps/TARC3_base/scripts.pory"
	setwildbattle SPECIES_WOOPER, 25
# 54 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_WOOPER, CRY_MODE_ENCOUNTER
# 55 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 56 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 57 "data/maps/TARC3_base/scripts.pory"
	dowildbattle
# 58 "data/maps/TARC3_base/scripts.pory"
	callnative WasBattleWon
# 59 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Base_Wooper_5
TARC3_Base_Wooper_1:
# 64 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Base_Wooper_2:
# 48 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Base_Wooper_Text_1
	goto TARC3_Base_Wooper_1

TARC3_Base_Wooper_5:
# 61 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_BASE_WOOPER_BEATEN
	goto TARC3_Base_Wooper_1


TARC3_Base_Torkoal::
# 69 "data/maps/TARC3_base/scripts.pory"
	cant_see_if_set FLAG_BASE_TORKOAL_BEATEN
# 70 "data/maps/TARC3_base/scripts.pory"
	lock
# 71 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 72 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Base_Torkoal_Text_0
# 73 "data/maps/TARC3_base/scripts.pory"
	createfieldmugshot MUGSHOT_TORKOAL, EMOTE_ALT
# 74 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_TORKOAL_BEATEN, TARC3_Base_Torkoal_2
# 80 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Base_Torkoal_Text_1
# 81 "data/maps/TARC3_base/scripts.pory"
	setwildbattle SPECIES_TORKOAL, 25
# 82 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_TORKOAL, CRY_MODE_ENCOUNTER
# 83 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 84 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 85 "data/maps/TARC3_base/scripts.pory"
	dowildbattle
# 86 "data/maps/TARC3_base/scripts.pory"
	callnative WasBattleWon
# 87 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Base_Torkoal_5
TARC3_Base_Torkoal_1:
# 92 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Base_Torkoal_2:
# 76 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Base_Sunkern_Text_1
	goto TARC3_Base_Torkoal_1

TARC3_Base_Torkoal_5:
# 89 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_BASE_TORKOAL_BEATEN
	goto TARC3_Base_Torkoal_1


TARC3_Base_Sunkern_Text_0:
# 17 "data/maps/TARC3_base/scripts.pory"
	.string "Sunkern$"

TARC3_Base_Sunkern_Text_1:
# 20 "data/maps/TARC3_base/scripts.pory"
	.string "I still like you!$"

TARC3_Base_Sunkern_Text_2:
# 24 "data/maps/TARC3_base/scripts.pory"
	.string "Hi, I'm SUNKERN.\nLet's battle!$"

TARC3_Base_Wooper_Text_0:
# 45 "data/maps/TARC3_base/scripts.pory"
	.string "Wooper$"

TARC3_Base_Wooper_Text_1:
# 48 "data/maps/TARC3_base/scripts.pory"
	.string "Hey, my berry!$"

TARC3_Base_Wooper_Text_2:
# 52 "data/maps/TARC3_base/scripts.pory"
	.string "Hi, I'm WOOPER.\nLet's battle!$"

TARC3_Base_Torkoal_Text_0:
# 72 "data/maps/TARC3_base/scripts.pory"
	.string "Torkoal$"

TARC3_Base_Torkoal_Text_1:
# 80 "data/maps/TARC3_base/scripts.pory"
	.string "Hi, I'm TORKOAL.\nLet's battle!$"
