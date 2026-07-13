TARC3_base_MapScripts::
	.byte 0


TARC3_Base_Sunkern::
# 6 "data/maps/TARC3_base/scripts.pory"
	cant_see_if_set FLAG_BASE_SUNKERN_BEATEN
# 7 "data/maps/TARC3_base/scripts.pory"
	lock
# 8 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 9 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_SUNKERN_BEATEN, TARC3_Base_Sunkern_2
# 15 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Base_Sunkern_Text_1
# 16 "data/maps/TARC3_base/scripts.pory"
	setwildbattle SPECIES_SUNKERN, 25
# 17 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_SUNKERN, CRY_MODE_ENCOUNTER
# 18 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 19 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 20 "data/maps/TARC3_base/scripts.pory"
	dowildbattle
# 21 "data/maps/TARC3_base/scripts.pory"
	callnative WasBattleWon
# 22 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Base_Sunkern_5
TARC3_Base_Sunkern_1:
# 27 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Base_Sunkern_2:
# 11 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Base_Sunkern_Text_0
	goto TARC3_Base_Sunkern_1

TARC3_Base_Sunkern_5:
# 24 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_BASE_SUNKERN_BEATEN
	goto TARC3_Base_Sunkern_1


TARC3_Base_Wooper::
# 32 "data/maps/TARC3_base/scripts.pory"
	cant_see_if_set FLAG_BASE_WOOPER_BEATEN
# 33 "data/maps/TARC3_base/scripts.pory"
	lock
# 34 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 35 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_WOOPER_BEATEN, TARC3_Base_Wooper_2
# 41 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Base_Wooper_Text_1
# 42 "data/maps/TARC3_base/scripts.pory"
	setwildbattle SPECIES_WOOPER, 25
# 43 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_WOOPER, CRY_MODE_ENCOUNTER
# 44 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 45 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 46 "data/maps/TARC3_base/scripts.pory"
	dowildbattle
# 47 "data/maps/TARC3_base/scripts.pory"
	callnative WasBattleWon
# 48 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Base_Wooper_5
TARC3_Base_Wooper_1:
# 53 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Base_Wooper_2:
# 37 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Base_Wooper_Text_0
	goto TARC3_Base_Wooper_1

TARC3_Base_Wooper_5:
# 50 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_BASE_WOOPER_BEATEN
	goto TARC3_Base_Wooper_1


TARC3_Base_Sunkern_Text_0:
# 11 "data/maps/TARC3_base/scripts.pory"
	.string "I still like you!$"

TARC3_Base_Sunkern_Text_1:
# 15 "data/maps/TARC3_base/scripts.pory"
	.string "Hi, I'm SUNKERN.\nLet's battle!$"

TARC3_Base_Wooper_Text_0:
# 37 "data/maps/TARC3_base/scripts.pory"
	.string "Hey, my berry!$"

TARC3_Base_Wooper_Text_1:
# 41 "data/maps/TARC3_base/scripts.pory"
	.string "Hi, I'm WOOPER.\nLet's battle!$"
