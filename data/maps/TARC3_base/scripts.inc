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
	goto_if_set FLAG_BASE_SUNKERN_BEATEN, TARC3_Base_Sunkern_2
# 22 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Base_Sunkern_Text_1
# 23 "data/maps/TARC3_base/scripts.pory"
	setwildbattle SPECIES_SUNKERN, 25
# 24 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_SUNKERN, CRY_MODE_ENCOUNTER
# 25 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 26 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 27 "data/maps/TARC3_base/scripts.pory"
	dowildbattle
# 28 "data/maps/TARC3_base/scripts.pory"
	callnative WasBattleWon
# 29 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Base_Sunkern_5
TARC3_Base_Sunkern_1:
# 34 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Base_Sunkern_2:
# 18 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Base_Sunkern_Text_0
	goto TARC3_Base_Sunkern_1

TARC3_Base_Sunkern_5:
# 31 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_BASE_SUNKERN_BEATEN
	goto TARC3_Base_Sunkern_1


TARC3_Base_Wooper::
# 39 "data/maps/TARC3_base/scripts.pory"
	cant_see_if_set FLAG_BASE_WOOPER_BEATEN
# 40 "data/maps/TARC3_base/scripts.pory"
	lock
# 41 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 42 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_WOOPER_BEATEN, TARC3_Base_Wooper_2
# 48 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Base_Wooper_Text_1
# 49 "data/maps/TARC3_base/scripts.pory"
	setwildbattle SPECIES_WOOPER, 25
# 50 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_WOOPER, CRY_MODE_ENCOUNTER
# 51 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 52 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 53 "data/maps/TARC3_base/scripts.pory"
	dowildbattle
# 54 "data/maps/TARC3_base/scripts.pory"
	callnative WasBattleWon
# 55 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Base_Wooper_5
TARC3_Base_Wooper_1:
# 60 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Base_Wooper_2:
# 44 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Base_Wooper_Text_0
	goto TARC3_Base_Wooper_1

TARC3_Base_Wooper_5:
# 57 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_BASE_WOOPER_BEATEN
	goto TARC3_Base_Wooper_1


TARC3_Base_Torkoal::
# 65 "data/maps/TARC3_base/scripts.pory"
	cant_see_if_set FLAG_BASE_TORKOAL_BEATEN
# 66 "data/maps/TARC3_base/scripts.pory"
	lock
# 67 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 68 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_TORKOAL_BEATEN, TARC3_Base_Torkoal_2
# 74 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Base_Torkoal_Text_0
# 75 "data/maps/TARC3_base/scripts.pory"
	setwildbattle SPECIES_TORKOAL, 25
# 76 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_TORKOAL, CRY_MODE_ENCOUNTER
# 77 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 78 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 79 "data/maps/TARC3_base/scripts.pory"
	dowildbattle
# 80 "data/maps/TARC3_base/scripts.pory"
	callnative WasBattleWon
# 81 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Base_Torkoal_5
TARC3_Base_Torkoal_1:
# 86 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Base_Torkoal_2:
# 70 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Base_Sunkern_Text_0
	goto TARC3_Base_Torkoal_1

TARC3_Base_Torkoal_5:
# 83 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_BASE_TORKOAL_BEATEN
	goto TARC3_Base_Torkoal_1


TARC3_Base_Sunkern_Text_0:
# 18 "data/maps/TARC3_base/scripts.pory"
	.string "I still like you!$"

TARC3_Base_Sunkern_Text_1:
# 22 "data/maps/TARC3_base/scripts.pory"
	.string "Hi, I'm SUNKERN.\nLet's battle!$"

TARC3_Base_Wooper_Text_0:
# 44 "data/maps/TARC3_base/scripts.pory"
	.string "Hey, my berry!$"

TARC3_Base_Wooper_Text_1:
# 48 "data/maps/TARC3_base/scripts.pory"
	.string "Hi, I'm WOOPER.\nLet's battle!$"

TARC3_Base_Torkoal_Text_0:
# 74 "data/maps/TARC3_base/scripts.pory"
	.string "Hi, I'm TORKOAL.\nLet's battle!$"
