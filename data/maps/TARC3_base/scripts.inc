TARC3_base_MapScripts::
# 2 "data/maps/TARC3_base/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, TARC3_Base_OnResume
	.byte 0


TARC3_Base_OnResume::
# 6 "data/maps/TARC3_base/scripts.pory"
	setstepcallback STEP_CB_CLAY_TILES
# 8 "data/maps/TARC3_base/scripts.pory"
	callnative GetCurrentTransformationSpecies
# 9 "data/maps/TARC3_base/scripts.pory"
	switch VAR_RESULT
# 11 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_RAINY, TARC3_Base_OnResume_3
# 13 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_SNOWY, TARC3_Base_OnResume_4
# 15 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_SUNNY, TARC3_Base_OnResume_5
# 19 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM, TARC3_Base_OnResume_6
TARC3_Base_OnResume_6:
# 21 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_HIDE_ITEM_UNDERWATER
TARC3_Base_OnResume_1:
	end

TARC3_Base_OnResume_3:
# 12 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_HIDE_ITEM_UNDERWATER
	goto TARC3_Base_OnResume_1

TARC3_Base_OnResume_4:
# 14 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_HIDE_ITEM_UNDERWATER
	goto TARC3_Base_OnResume_1

TARC3_Base_OnResume_5:
# 16 "data/maps/TARC3_base/scripts.pory"
	goto_if_unset FLAG_ITEM_COLLECTIBLE_2, TARC3_Base_OnResume_7
	goto TARC3_Base_OnResume_1

TARC3_Base_OnResume_7:
# 17 "data/maps/TARC3_base/scripts.pory"
	clearflag FLAG_HIDE_ITEM_UNDERWATER
	goto TARC3_Base_OnResume_1


TARC3_Base_Sunkern::
# 29 "data/maps/TARC3_base/scripts.pory"
	goto TARC3_Base_Paras
	return


TARC3_Base_Wooper::
# 33 "data/maps/TARC3_base/scripts.pory"
	goto TARC3_Base_Dewpider
	return


TARC3_Base_Paras::
# 40 "data/maps/TARC3_base/scripts.pory"
	cant_see_if_set FLAG_BASE_PARAS_BEATEN
# 41 "data/maps/TARC3_base/scripts.pory"
	lock
# 42 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 45 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Base_Paras_Text_0
# 46 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_PARAS_BEATEN, TARC3_Base_Paras_2
# 52 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_START
# 53 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Base_Paras_Text_0
# 54 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Base_Paras_Text_1
# 55 "data/maps/TARC3_base/scripts.pory"
	setwildbattle SPECIES_PARAS, 25
# 56 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_PARAS, CRY_MODE_ENCOUNTER
# 57 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 58 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 59 "data/maps/TARC3_base/scripts.pory"
	dowildbattle
# 60 "data/maps/TARC3_base/scripts.pory"
	callnative WasBattleWon
# 61 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Base_Paras_5
TARC3_Base_Paras_1:
# 67 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Base_Paras_2:
# 48 "data/maps/TARC3_base/scripts.pory"
	goto TARC3_Paras_Post
	goto TARC3_Base_Paras_1

TARC3_Base_Paras_5:
# 63 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_BASE_PARAS_BEATEN
# 64 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_START
	goto TARC3_Base_Paras_1


TARC3_Base_Vulpix::
# 72 "data/maps/TARC3_base/scripts.pory"
	cant_see_if_set FLAG_BASE_VULPIX_BEATEN
# 73 "data/maps/TARC3_base/scripts.pory"
	lock
# 74 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 77 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Base_Vulpix_Text_0
# 78 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_VULPIX_BEATEN, TARC3_Base_Vulpix_2
# 84 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_VULPIX
# 85 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Base_Vulpix_Text_0
# 86 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Base_Vulpix_Text_1
# 87 "data/maps/TARC3_base/scripts.pory"
	setwildbattle SPECIES_VULPIX, 25
# 88 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_VULPIX, CRY_MODE_ENCOUNTER
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
	goto_if_eq TARC3_Base_Vulpix_5
TARC3_Base_Vulpix_1:
# 99 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Base_Vulpix_2:
# 80 "data/maps/TARC3_base/scripts.pory"
	goto TARC3_Vulpix_Post
	goto TARC3_Base_Vulpix_1

TARC3_Base_Vulpix_5:
# 95 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_BASE_VULPIX_BEATEN
# 96 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_START
	goto TARC3_Base_Vulpix_1


TARC3_Base_Dewpider::
# 104 "data/maps/TARC3_base/scripts.pory"
	cant_see_if_set FLAG_BASE_DEWPIDER_BEATEN
# 105 "data/maps/TARC3_base/scripts.pory"
	lock
# 106 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 109 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Base_Dewpider_Text_0
# 110 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_DEWPIDER_BEATEN, TARC3_Base_Dewpider_2
# 116 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_DEWPIDER
# 117 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Base_Dewpider_Text_0
# 118 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Base_Dewpider_Text_1
# 119 "data/maps/TARC3_base/scripts.pory"
	setwildbattle SPECIES_DEWPIDER, 25
# 120 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_DEWPIDER, CRY_MODE_ENCOUNTER
# 121 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 122 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 123 "data/maps/TARC3_base/scripts.pory"
	dowildbattle
# 124 "data/maps/TARC3_base/scripts.pory"
	callnative WasBattleWon
# 125 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Base_Dewpider_5
TARC3_Base_Dewpider_1:
# 131 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Base_Dewpider_2:
# 112 "data/maps/TARC3_base/scripts.pory"
	goto TARC3_Dewpider_Post
	goto TARC3_Base_Dewpider_1

TARC3_Base_Dewpider_5:
# 127 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_BASE_DEWPIDER_BEATEN
# 128 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_START
	goto TARC3_Base_Dewpider_1


TARC3_Amber_Munchlax::
# 136 "data/maps/TARC3_base/scripts.pory"
	cant_see_if_set FLAG_BASE_MUNCHLAX_BEATEN
# 137 "data/maps/TARC3_base/scripts.pory"
	lock
# 138 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 141 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Amber_Munchlax_Text_0
# 142 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_MUNCHLAX_BEATEN, TARC3_Amber_Munchlax_2
# 148 "data/maps/TARC3_base/scripts.pory"
	compare VAR_TRANSFORM_MON, SPECIES_CASTFORM_SUNNY
	goto_if_eq TARC3_Amber_Munchlax_5
# 177 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_MUNCHLAX
# 178 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Amber_Munchlax_Text_0
# 179 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Amber_Munchlax_Text_2
# 180 "data/maps/TARC3_base/scripts.pory"
	setwildbattle SPECIES_MUNCHLAX, 25
# 181 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_MUNCHLAX, CRY_MODE_ENCOUNTER
# 182 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 183 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 184 "data/maps/TARC3_base/scripts.pory"
	dowildbattle
# 185 "data/maps/TARC3_base/scripts.pory"
	callnative WasBattleWon
# 186 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Amber_Munchlax_12
TARC3_Amber_Munchlax_1:
# 193 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Amber_Munchlax_2:
# 144 "data/maps/TARC3_base/scripts.pory"
	goto TARC3_Munchlax_Post
	goto TARC3_Amber_Munchlax_1

TARC3_Amber_Munchlax_5:
# 150 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Amber_Munchlax_Text_1
# 151 "data/maps/TARC3_base/scripts.pory"
	applymovement LOCALID_PLAYER, TARC3_Amber_Munchlax_Movement_0
# 155 "data/maps/TARC3_base/scripts.pory"
	waitmovement 0
# 157 "data/maps/TARC3_base/scripts.pory"
	switch VAR_TEMP_E
# 159 "data/maps/TARC3_base/scripts.pory"
	case 1, TARC3_Amber_Munchlax_10
# 164 "data/maps/TARC3_base/scripts.pory"
	case 2, TARC3_Amber_Munchlax_11
TARC3_Amber_Munchlax_8:
# 171 "data/maps/TARC3_base/scripts.pory"
	waitmovement 0
# 172 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Amber_Munchlax_10:
# 160 "data/maps/TARC3_base/scripts.pory"
	applymovement LOCALID_MUNCHLAX, TARC3_Amber_Munchlax_Movement_1
	goto TARC3_Amber_Munchlax_8

TARC3_Amber_Munchlax_11:
# 165 "data/maps/TARC3_base/scripts.pory"
	applymovement LOCALID_MUNCHLAX, TARC3_Amber_Munchlax_Movement_2
	goto TARC3_Amber_Munchlax_8

TARC3_Amber_Munchlax_12:
# 188 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_BASE_MUNCHLAX_BEATEN
# 189 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_START
	goto TARC3_Amber_Munchlax_1


TARC3_Amber_Combusken::
# 198 "data/maps/TARC3_base/scripts.pory"
	cant_see_if_set FLAG_BASE_COMBUSKEN_BEATEN
# 199 "data/maps/TARC3_base/scripts.pory"
	lock
# 200 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 202 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Amber_Combusken_Text_0
# 204 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_COMBUSKEN_BEATEN, TARC3_Amber_Combusken_2
# 210 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_COMBUSKEN
# 211 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Amber_Combusken_Text_0
# 212 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Amber_Combusken_Text_1
# 213 "data/maps/TARC3_base/scripts.pory"
	setwildbattle SPECIES_COMBUSKEN, 25
# 214 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_COMBUSKEN, CRY_MODE_ENCOUNTER
# 215 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 216 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 217 "data/maps/TARC3_base/scripts.pory"
	dowildbattle
# 218 "data/maps/TARC3_base/scripts.pory"
	callnative WasBattleWon
# 219 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Amber_Combusken_5
TARC3_Amber_Combusken_1:
# 225 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Amber_Combusken_2:
# 206 "data/maps/TARC3_base/scripts.pory"
	goto TARC3_Combusken_Post
	goto TARC3_Amber_Combusken_1

TARC3_Amber_Combusken_5:
# 221 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_BASE_COMBUSKEN_BEATEN
# 222 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_START
	goto TARC3_Amber_Combusken_1


TARC3_Amber_Observer::
# 230 "data/maps/TARC3_base/scripts.pory"
	cant_see_if_set FLAG_BASE_HELIOPTILE_BEATEN
# 231 "data/maps/TARC3_base/scripts.pory"
	lock
# 232 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 234 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Amber_Observer_Text_0
# 236 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_HELIOPTILE_BEATEN, TARC3_Amber_Observer_2
# 242 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_HELIOPTILE
# 243 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Amber_Observer_Text_2
# 244 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_HELIOPTILE, CRY_MODE_ENCOUNTER
# 245 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 246 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 247 "data/maps/TARC3_base/scripts.pory"
	ai_vs_ai_wild_battle SPECIES_FOMANTIS, SPECIES_HELIOPTILE, 25
# 248 "data/maps/TARC3_base/scripts.pory"
	callnative WasBattleWon
# 249 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Amber_Observer_5
TARC3_Amber_Observer_1:
# 278 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Amber_Observer_2:
# 238 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Amber_Observer_Text_1
	goto TARC3_Amber_Observer_1

TARC3_Amber_Observer_5:
# 251 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_BASE_HELIOPTILE_BEATEN
# 252 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_START
# 253 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Amber_Observer_Text_0
# 254 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Amber_Observer_Text_3
# 255 "data/maps/TARC3_base/scripts.pory"
	fadescreen FADE_TO_BLACK
# 256 "data/maps/TARC3_base/scripts.pory"
	special HealPlayerParty
# 258 "data/maps/TARC3_base/scripts.pory"
	callnative GetCurrentTransformationSpecies
# 259 "data/maps/TARC3_base/scripts.pory"
	switch VAR_RESULT
# 261 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM, TARC3_Amber_Observer_9
# 264 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_RAINY, TARC3_Amber_Observer_10
# 267 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_SUNNY, TARC3_Amber_Observer_11
# 270 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_SNOWY, TARC3_Amber_Observer_12
TARC3_Amber_Observer_7:
# 274 "data/maps/TARC3_base/scripts.pory"
	delay 60
# 275 "data/maps/TARC3_base/scripts.pory"
	fadescreen FADE_FROM_BLACK
	goto TARC3_Amber_Observer_1

TARC3_Amber_Observer_9:
# 262 "data/maps/TARC3_base/scripts.pory"
	removeobject LOCALID_BASE_FOMANTIS
# 263 "data/maps/TARC3_base/scripts.pory"
	removeobject LOCALID_BASE_HELIOPTILE
	goto TARC3_Amber_Observer_7

TARC3_Amber_Observer_10:
# 265 "data/maps/TARC3_base/scripts.pory"
	removeobject LOCALID_RAINY_FOMANTIS
# 266 "data/maps/TARC3_base/scripts.pory"
	removeobject LOCALID_RAINY_HELIOPTILE
	goto TARC3_Amber_Observer_7

TARC3_Amber_Observer_11:
# 268 "data/maps/TARC3_base/scripts.pory"
	removeobject LOCALID_SUNNY_FOMANTIS
# 269 "data/maps/TARC3_base/scripts.pory"
	removeobject LOCALID_SUNNY_HELIOPTILE
	goto TARC3_Amber_Observer_7

TARC3_Amber_Observer_12:
# 271 "data/maps/TARC3_base/scripts.pory"
	removeobject LOCALID_SNOWY_FOMANTIS
# 272 "data/maps/TARC3_base/scripts.pory"
	removeobject LOCALID_SNOWY_HELIOPTILE
	goto TARC3_Amber_Observer_7


TARC3_Amber_Torkoal::
# 283 "data/maps/TARC3_base/scripts.pory"
	cant_see_if_set FLAG_BASE_TORKOAL_BEATEN
# 284 "data/maps/TARC3_base/scripts.pory"
	lock
# 285 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 287 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Amber_Torkoal_Text_0
# 289 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_TORKOAL_BEATEN, TARC3_Amber_Torkoal_2
# 295 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_TORKOAL
# 296 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Amber_Torkoal_Text_0
# 297 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Amber_Torkoal_Text_1
# 298 "data/maps/TARC3_base/scripts.pory"
	setwildbattle SPECIES_TORKOAL, 25
# 299 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_TORKOAL, CRY_MODE_ENCOUNTER
# 300 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 301 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 302 "data/maps/TARC3_base/scripts.pory"
	dowildbattle
# 303 "data/maps/TARC3_base/scripts.pory"
	callnative WasBattleWon
# 304 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Amber_Torkoal_5
TARC3_Amber_Torkoal_1:
# 322 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Amber_Torkoal_2:
# 291 "data/maps/TARC3_base/scripts.pory"
	goto TARC3_Torkoal_Post
	goto TARC3_Amber_Torkoal_1

TARC3_Amber_Torkoal_5:
# 306 "data/maps/TARC3_base/scripts.pory"
	lock
# 307 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 308 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_BASE_TORKOAL_BEATEN
# 309 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_START
# 310 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Amber_Torkoal_Text_2
# 311 "data/maps/TARC3_base/scripts.pory"
	setvar VAR_CASTFORM_PHASE, 2
# 312 "data/maps/TARC3_base/scripts.pory"
	setvar VAR_TRIGGER_XATU_EVENT, 1
# 313 "data/maps/TARC3_base/scripts.pory"
	giveitem ITEM_DAMP_ROCK, 1
# 314 "data/maps/TARC3_base/scripts.pory"
	givemon SPECIES_CASTFORM_RAINY, 25
# 315 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_ITEM_AZURE_SHARD
# 316 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_RUN_XATU_AZURE
# 317 "data/maps/TARC3_base/scripts.pory"
	releaseall
# 318 "data/maps/TARC3_base/scripts.pory"
	warp MAP_TARC3_WEATHER_INSTITUTE_2F, 9, 8
# 319 "data/maps/TARC3_base/scripts.pory"
	waitstate
	goto TARC3_Amber_Torkoal_1


TARC3_Azure_Toxicroak::
# 327 "data/maps/TARC3_base/scripts.pory"
	cant_see_if_set FLAG_BASE_TOXICROAK_BEATEN
# 328 "data/maps/TARC3_base/scripts.pory"
	lock
# 329 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 331 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Azure_Toxicroak_Text_0
# 333 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_TOXICROAK_BEATEN, TARC3_Azure_Toxicroak_2
# 339 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_TOXICROAK
# 340 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Azure_Toxicroak_Text_0
# 341 "data/maps/TARC3_base/scripts.pory"
	callnative GetCurrentTransformationSpecies
# 342 "data/maps/TARC3_base/scripts.pory"
	switch VAR_RESULT
# 344 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_SUNNY, TARC3_Azure_Toxicroak_7
# 346 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_RAINY, TARC3_Azure_Toxicroak_8
# 349 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Azure_Toxicroak_Text_3
TARC3_Azure_Toxicroak_5:
# 351 "data/maps/TARC3_base/scripts.pory"
	setwildbattle SPECIES_TOXICROAK, 25
# 352 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_TOXICROAK, CRY_MODE_ENCOUNTER
# 353 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 354 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 355 "data/maps/TARC3_base/scripts.pory"
	dowildbattle
# 356 "data/maps/TARC3_base/scripts.pory"
	callnative WasBattleWon
# 357 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Azure_Toxicroak_10
TARC3_Azure_Toxicroak_1:
# 363 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Azure_Toxicroak_2:
# 335 "data/maps/TARC3_base/scripts.pory"
	goto TARC3_Toxicroak_Post
	goto TARC3_Azure_Toxicroak_1

TARC3_Azure_Toxicroak_7:
# 345 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Azure_Toxicroak_Text_1
	goto TARC3_Azure_Toxicroak_5

TARC3_Azure_Toxicroak_8:
# 347 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Azure_Toxicroak_Text_2
	goto TARC3_Azure_Toxicroak_5

TARC3_Azure_Toxicroak_10:
# 359 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_BASE_TOXICROAK_BEATEN
# 360 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_START
	goto TARC3_Azure_Toxicroak_1


TARC3_Azure_Gastrodon::
# 368 "data/maps/TARC3_base/scripts.pory"
	cant_see_if_set FLAG_BASE_GASTRODON_BEATEN
# 369 "data/maps/TARC3_base/scripts.pory"
	lock
# 370 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 372 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Azure_Gastrodon_Text_0
# 374 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_GASTRODON_BEATEN, TARC3_Azure_Gastrodon_2
# 380 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_GASTRODON
# 381 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Azure_Gastrodon_Text_0
# 382 "data/maps/TARC3_base/scripts.pory"
	callnative GetCurrentTransformationSpecies
# 383 "data/maps/TARC3_base/scripts.pory"
	switch VAR_RESULT
# 385 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_SUNNY, TARC3_Azure_Gastrodon_7
# 387 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_RAINY, TARC3_Azure_Gastrodon_8
# 390 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Azure_Gastrodon_Text_3
TARC3_Azure_Gastrodon_5:
# 392 "data/maps/TARC3_base/scripts.pory"
	setwildbattle SPECIES_GASTRODON, 25
# 393 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_GASTRODON, CRY_MODE_ENCOUNTER
# 394 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 395 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 396 "data/maps/TARC3_base/scripts.pory"
	dowildbattle
# 397 "data/maps/TARC3_base/scripts.pory"
	callnative WasBattleWon
# 398 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Azure_Gastrodon_10
TARC3_Azure_Gastrodon_1:
# 404 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Azure_Gastrodon_2:
# 376 "data/maps/TARC3_base/scripts.pory"
	goto TARC3_Gastrodon_Post
	goto TARC3_Azure_Gastrodon_1

TARC3_Azure_Gastrodon_7:
# 386 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Azure_Gastrodon_Text_1
	goto TARC3_Azure_Gastrodon_5

TARC3_Azure_Gastrodon_8:
# 388 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Azure_Gastrodon_Text_2
	goto TARC3_Azure_Gastrodon_5

TARC3_Azure_Gastrodon_10:
# 400 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_BASE_GASTRODON_BEATEN
# 401 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_START
	goto TARC3_Azure_Gastrodon_1


TARC3_Azure_Observer::
# 409 "data/maps/TARC3_base/scripts.pory"
	cant_see_if_set FLAG_BASE_SLOWKING_BEATEN
# 410 "data/maps/TARC3_base/scripts.pory"
	lock
# 411 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 413 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Azure_Observer_Text_0
# 415 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_SLOWKING_BEATEN, TARC3_Azure_Observer_2
# 421 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_SLOWKING
# 422 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Azure_Observer_Text_1
# 423 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_SLOWKING, CRY_MODE_ENCOUNTER
# 424 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 425 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 426 "data/maps/TARC3_base/scripts.pory"
	ai_vs_ai_wild_battle SPECIES_DRAMPA, SPECIES_SLOWKING, 25
# 427 "data/maps/TARC3_base/scripts.pory"
	callnative WasBattleWon
# 428 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Azure_Observer_5
TARC3_Azure_Observer_1:
# 457 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Azure_Observer_2:
# 417 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Amber_Observer_Text_1
	goto TARC3_Azure_Observer_1

TARC3_Azure_Observer_5:
# 430 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_BASE_SLOWKING_BEATEN
# 431 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_START
# 432 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Azure_Observer_Text_0
# 433 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Azure_Observer_Text_2
# 434 "data/maps/TARC3_base/scripts.pory"
	fadescreen FADE_TO_BLACK
# 435 "data/maps/TARC3_base/scripts.pory"
	special HealPlayerParty
# 437 "data/maps/TARC3_base/scripts.pory"
	callnative GetCurrentTransformationSpecies
# 438 "data/maps/TARC3_base/scripts.pory"
	switch VAR_RESULT
# 440 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM, TARC3_Azure_Observer_9
# 443 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_RAINY, TARC3_Azure_Observer_10
# 446 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_SUNNY, TARC3_Azure_Observer_11
# 449 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_SNOWY, TARC3_Azure_Observer_12
TARC3_Azure_Observer_7:
# 453 "data/maps/TARC3_base/scripts.pory"
	delay 60
# 454 "data/maps/TARC3_base/scripts.pory"
	fadescreen FADE_FROM_BLACK
	goto TARC3_Azure_Observer_1

TARC3_Azure_Observer_9:
# 441 "data/maps/TARC3_base/scripts.pory"
	removeobject LOCALID_BASE_DRAMPA
# 442 "data/maps/TARC3_base/scripts.pory"
	removeobject LOCALID_BASE_SLOWKING
	goto TARC3_Azure_Observer_7

TARC3_Azure_Observer_10:
# 444 "data/maps/TARC3_base/scripts.pory"
	removeobject LOCALID_RAINY_DRAMPA
# 445 "data/maps/TARC3_base/scripts.pory"
	removeobject LOCALID_RAINY_SLOWKING
	goto TARC3_Azure_Observer_7

TARC3_Azure_Observer_11:
# 447 "data/maps/TARC3_base/scripts.pory"
	removeobject LOCALID_SUNNY_DRAMPA
# 448 "data/maps/TARC3_base/scripts.pory"
	removeobject LOCALID_SUNNY_SLOWKING
	goto TARC3_Azure_Observer_7

TARC3_Azure_Observer_12:
# 450 "data/maps/TARC3_base/scripts.pory"
	removeobject LOCALID_SNOWY_DRAMPA
# 451 "data/maps/TARC3_base/scripts.pory"
	removeobject LOCALID_SNOWY_SLOWKING
	goto TARC3_Azure_Observer_7


TARC3_Azure_Flygon::
# 462 "data/maps/TARC3_base/scripts.pory"
	cant_see_if_set FLAG_BASE_FLYGON_BEATEN
# 463 "data/maps/TARC3_base/scripts.pory"
	lock
# 464 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 466 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Azure_Flygon_Text_0
# 468 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_FLYGON_BEATEN, TARC3_Azure_Flygon_2
# 474 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_FLYGON
# 475 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Azure_Flygon_Text_1
# 476 "data/maps/TARC3_base/scripts.pory"
	setwildbattle SPECIES_FLYGON, 25
# 477 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_FLYGON, CRY_MODE_ENCOUNTER
# 478 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 479 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 480 "data/maps/TARC3_base/scripts.pory"
	dowildbattle
# 481 "data/maps/TARC3_base/scripts.pory"
	callnative WasBattleWon
# 482 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Azure_Flygon_5
TARC3_Azure_Flygon_1:
# 509 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Azure_Flygon_2:
# 470 "data/maps/TARC3_base/scripts.pory"
	goto TARC3_Flygon_Post
	goto TARC3_Azure_Flygon_1

TARC3_Azure_Flygon_5:
# 484 "data/maps/TARC3_base/scripts.pory"
	lock
# 485 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 486 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_BASE_FLYGON_BEATEN
# 487 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_START
# 488 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Azure_Flygon_Text_0
# 489 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Azure_Flygon_Text_2
# 492 "data/maps/TARC3_base/scripts.pory"
	giveitem ITEM_ICY_ROCK, 1
# 494 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_ITEM_GLACIAL_SHARD
# 496 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Azure_Flygon_Text_3
# 497 "data/maps/TARC3_base/scripts.pory"
	checkitem ITEM_STARDUST, 9
# 498 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Azure_Flygon_8
# 502 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Azure_Flygon_Text_5
TARC3_Azure_Flygon_7:
# 504 "data/maps/TARC3_base/scripts.pory"
	releaseall
	goto TARC3_Azure_Flygon_1

TARC3_Azure_Flygon_8:
# 499 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Azure_Flygon_Text_4
	goto TARC3_Azure_Flygon_7


TARC3_Paras_Post::
# 516 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_SURSKIT, CRY_MODE_NORMAL
# 518 "data/maps/TARC3_base/scripts.pory"
	callnative GetCurrentTransformationSpecies
# 519 "data/maps/TARC3_base/scripts.pory"
	switch VAR_RESULT
# 521 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_SUNNY, TARC3_Paras_Post_3
# 523 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_RAINY, TARC3_Paras_Post_4
# 524 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_SNOWY, TARC3_Paras_Post_4
# 526 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM, TARC3_Paras_Post_5
TARC3_Paras_Post_5:
# 528 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Paras_Post_Text_2
TARC3_Paras_Post_1:
# 530 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Paras_Post_3:
# 522 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Paras_Post_Text_0
	goto TARC3_Paras_Post_1

TARC3_Paras_Post_4:
# 525 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Paras_Post_Text_1
	goto TARC3_Paras_Post_1


TARC3_Surskit::
# 535 "data/maps/TARC3_base/scripts.pory"
	lock
# 536 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 537 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_SURSKIT, CRY_MODE_NORMAL
# 538 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Surskit_Text_0
# 539 "data/maps/TARC3_base/scripts.pory"
	callnative GetCurrentTransformationSpecies
# 540 "data/maps/TARC3_base/scripts.pory"
	switch VAR_RESULT
# 542 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_SUNNY, TARC3_Surskit_3
# 544 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_RAINY, TARC3_Surskit_4
# 546 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_SNOWY, TARC3_Surskit_5
# 547 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM, TARC3_Surskit_5
TARC3_Surskit_5:
# 549 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Surskit_Text_3
TARC3_Surskit_1:
# 551 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Surskit_3:
# 543 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Surskit_Text_1
	goto TARC3_Surskit_1

TARC3_Surskit_4:
# 545 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Surskit_Text_2
	goto TARC3_Surskit_1


TARC3_Vulpix_Post::
# 556 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_VULPIX, CRY_MODE_NORMAL
# 558 "data/maps/TARC3_base/scripts.pory"
	callnative GetCurrentTransformationSpecies
# 559 "data/maps/TARC3_base/scripts.pory"
	switch VAR_RESULT
# 562 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Vulpix_Post_Text_0
# 564 "data/maps/TARC3_base/scripts.pory"
	release
	end


TARC3_Dewpider_Post::
# 569 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_DEWPIDER, CRY_MODE_NORMAL
# 571 "data/maps/TARC3_base/scripts.pory"
	callnative GetCurrentTransformationSpecies
# 572 "data/maps/TARC3_base/scripts.pory"
	switch VAR_RESULT
# 574 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_SUNNY, TARC3_Dewpider_Post_3
# 577 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Dewpider_Post_Text_1
TARC3_Dewpider_Post_1:
# 579 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Dewpider_Post_3:
# 575 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Dewpider_Post_Text_0
	goto TARC3_Dewpider_Post_1


TARC3_Munchlax_Post::
# 584 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_MUNCHLAX, CRY_MODE_NORMAL
# 586 "data/maps/TARC3_base/scripts.pory"
	callnative GetCurrentTransformationSpecies
# 587 "data/maps/TARC3_base/scripts.pory"
	switch VAR_RESULT
# 590 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Munchlax_Post_Text_0
# 592 "data/maps/TARC3_base/scripts.pory"
	release
	end


TARC3_Combusken_Post::
# 597 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_COMBUSKEN, CRY_MODE_NORMAL
# 599 "data/maps/TARC3_base/scripts.pory"
	callnative GetCurrentTransformationSpecies
# 600 "data/maps/TARC3_base/scripts.pory"
	switch VAR_RESULT
# 602 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_RAINY, TARC3_Combusken_Post_3
# 605 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Combusken_Post_Text_1
TARC3_Combusken_Post_1:
# 607 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Combusken_Post_3:
# 603 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Combusken_Post_Text_0
	goto TARC3_Combusken_Post_1


TARC3_Torkoal_Post::
# 612 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_TORKOAL, CRY_MODE_NORMAL
# 614 "data/maps/TARC3_base/scripts.pory"
	callnative GetCurrentTransformationSpecies
# 615 "data/maps/TARC3_base/scripts.pory"
	switch VAR_RESULT
# 617 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_RAINY, TARC3_Torkoal_Post_3
# 620 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Torkoal_Post_Text_1
TARC3_Torkoal_Post_1:
# 622 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Torkoal_Post_3:
# 618 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Torkoal_Post_Text_0
	goto TARC3_Torkoal_Post_1


TARC3_Toxicroak_Post::
# 627 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_TOXICROAK, CRY_MODE_NORMAL
# 629 "data/maps/TARC3_base/scripts.pory"
	callnative GetCurrentTransformationSpecies
# 630 "data/maps/TARC3_base/scripts.pory"
	switch VAR_RESULT
# 633 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Toxicroak_Post_Text_0
# 635 "data/maps/TARC3_base/scripts.pory"
	release
	end


TARC3_Gastrodon_Post::
# 640 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_GASTRODON, CRY_MODE_NORMAL
# 642 "data/maps/TARC3_base/scripts.pory"
	callnative GetCurrentTransformationSpecies
# 643 "data/maps/TARC3_base/scripts.pory"
	switch VAR_RESULT
# 646 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Gastrodon_Post_Text_0
# 648 "data/maps/TARC3_base/scripts.pory"
	release
	end


TARC3_Flygon_Post::
# 653 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_FLYGON, CRY_MODE_NORMAL
# 655 "data/maps/TARC3_base/scripts.pory"
	callnative GetCurrentTransformationSpecies
# 656 "data/maps/TARC3_base/scripts.pory"
	switch VAR_RESULT
# 659 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Flygon_Post_Text_0
# 660 "data/maps/TARC3_base/scripts.pory"
	checkitem ITEM_STARDUST, 9
# 661 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Flygon_Post_4
# 665 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Azure_Flygon_Text_5
TARC3_Flygon_Post_1:
# 668 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Flygon_Post_4:
# 662 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Azure_Flygon_Text_4
	goto TARC3_Flygon_Post_1


TARC3_Whimsicott::
# 673 "data/maps/TARC3_base/scripts.pory"
	lock
# 674 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 675 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Whimsicott_Text_0
# 677 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_WHIMSICOTT_GAVE_SEED, TARC3_Whimsicott_2
# 683 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Whimsicott_Text_2
# 684 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_WHIMSICOTT, CRY_MODE_NORMAL
# 685 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 686 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 687 "data/maps/TARC3_base/scripts.pory"
	giveitem ITEM_WEPEAR_BERRY, 1
# 688 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_WHIMSICOTT_GAVE_SEED
# 689 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Whimsicott_Text_1
TARC3_Whimsicott_1:
# 691 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Whimsicott_2:
# 679 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Whimsicott_Text_1
	goto TARC3_Whimsicott_1


TARC3_Feebas::
# 696 "data/maps/TARC3_base/scripts.pory"
	lock
# 697 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 698 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Feebas_Text_0
# 700 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_FEEBAS, CRY_MODE_NORMAL
# 701 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Feebas_Text_1
# 702 "data/maps/TARC3_base/scripts.pory"
	release
	end


TARC3_Chatot1::
# 707 "data/maps/TARC3_base/scripts.pory"
	lock
# 708 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 709 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Chatot1_Text_0
# 711 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_CHATOT, CRY_MODE_NORMAL
# 712 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Chatot1_Text_1
# 713 "data/maps/TARC3_base/scripts.pory"
	release
	end


TARC3_Chatot2::
# 718 "data/maps/TARC3_base/scripts.pory"
	lock
# 719 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 720 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Chatot1_Text_0
# 722 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_CHATOT, CRY_MODE_NORMAL
# 723 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Chatot2_Text_0
# 724 "data/maps/TARC3_base/scripts.pory"
	release
	end


TARC3_Audino::
# 729 "data/maps/TARC3_base/scripts.pory"
	lock
# 730 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 731 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Audino_Text_0
# 733 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_AUDINO, CRY_MODE_NORMAL
# 734 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_AUDINO_GAVE_HERBICIDE, TARC3_Audino_1
# 738 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Audino_Text_1
# 739 "data/maps/TARC3_base/scripts.pory"
	giveitem ITEM_HYPER_POTION
# 740 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_AUDINO_GAVE_HERBICIDE
# 741 "data/maps/TARC3_base/scripts.pory"
	goto TARC3_Audino_Post
	return

TARC3_Audino_1:
# 735 "data/maps/TARC3_base/scripts.pory"
	goto TARC3_Audino_Post
	return


TARC3_Audino_Post::
# 746 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Audino_Post_Text_0
# 747 "data/maps/TARC3_base/scripts.pory"
	release
	end


TARC3_Minccino::
# 752 "data/maps/TARC3_base/scripts.pory"
	lock
# 753 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 754 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Minccino_Text_0
# 756 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_MINCCINO, CRY_MODE_NORMAL
# 757 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Minccino_Text_1
# 758 "data/maps/TARC3_base/scripts.pory"
	release
	end


TARC3_Smeargle::
# 763 "data/maps/TARC3_base/scripts.pory"
	lock
# 764 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 765 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Smeargle_Text_0
# 767 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_SMEARGLE, CRY_MODE_NORMAL
# 768 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Smeargle_Text_1
# 769 "data/maps/TARC3_base/scripts.pory"
	release
	end


TARC3_Nosepass::
# 774 "data/maps/TARC3_base/scripts.pory"
	lock
# 775 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 776 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Nosepass_Text_0
# 778 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_NOSEPASS, CRY_MODE_NORMAL
# 779 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Nosepass_Text_1
# 780 "data/maps/TARC3_base/scripts.pory"
	release
	end


TARC3_Ducklett::
# 785 "data/maps/TARC3_base/scripts.pory"
	lock
# 786 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 787 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Ducklett_Text_0
# 789 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_DUCKLETT, CRY_MODE_NORMAL
# 790 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Ducklett_Text_1
# 791 "data/maps/TARC3_base/scripts.pory"
	release
	end


TARC3_Sliggoo::
# 796 "data/maps/TARC3_base/scripts.pory"
	lock
# 797 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 798 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Sliggoo_Text_0
# 800 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_SLIGGOO, CRY_MODE_NORMAL
# 801 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Sliggoo_Text_1
# 802 "data/maps/TARC3_base/scripts.pory"
	release
	end


TARC3_Goodra::
# 807 "data/maps/TARC3_base/scripts.pory"
	lock
# 808 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 809 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Goodra_Text_0
# 811 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_GOODRA, CRY_MODE_NORMAL
# 812 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_GOODRA_GAVE_ITEM, TARC3_Goodra_2
# 816 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Goodra_Text_2
# 817 "data/maps/TARC3_base/scripts.pory"
	giveitem ITEM_STARDUST
# 818 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_GOODRA_GAVE_ITEM
# 819 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Goodra_Text_1
TARC3_Goodra_1:
# 821 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Goodra_2:
# 813 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Goodra_Text_1
	goto TARC3_Goodra_1


TARC3_Lapras1_Source::
# 826 "data/maps/TARC3_base/scripts.pory"
	lock
# 827 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 828 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Lapras1_Source_Text_0
# 830 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_LAPRAS, CRY_MODE_NORMAL
# 831 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Lapras1_Source_Text_1
# 832 "data/maps/TARC3_base/scripts.pory"
	applymovement VAR_LAST_TALKED, TARC3_Lapras1_Source_Movement_0
# 837 "data/maps/TARC3_base/scripts.pory"
	waitmovement 0
# 838 "data/maps/TARC3_base/scripts.pory"
	removeobject VAR_LAST_TALKED
# 839 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_LAPRAS1_SOURCE_INVISIBLE
# 840 "data/maps/TARC3_base/scripts.pory"
	clearflag FLAG_LAPRAS1_DEST_INVISIBLE
# 841 "data/maps/TARC3_base/scripts.pory"
	release
	end


TARC3_Lapras2_Source::
# 846 "data/maps/TARC3_base/scripts.pory"
	lock
# 847 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 848 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Lapras1_Source_Text_0
# 850 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_LAPRAS, CRY_MODE_NORMAL
# 851 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Lapras2_Source_Text_0
# 852 "data/maps/TARC3_base/scripts.pory"
	applymovement VAR_LAST_TALKED, TARC3_Lapras2_Source_Movement_0
# 863 "data/maps/TARC3_base/scripts.pory"
	waitmovement 0
# 864 "data/maps/TARC3_base/scripts.pory"
	removeobject VAR_LAST_TALKED
# 865 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_LAPRAS2_SOURCE_INVISIBLE
# 866 "data/maps/TARC3_base/scripts.pory"
	clearflag FLAG_LAPRAS2_DEST_INVISIBLE
# 867 "data/maps/TARC3_base/scripts.pory"
	release
	end


TARC3_Sign_TreeOfLife::
# 872 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Sign_TreeOfLife_Text_0, MSGBOX_SIGN
	end


TARC3_Sign_ApricornTree::
# 877 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Sign_ApricornTree_Text_0, MSGBOX_SIGN
	end


TARC3_Find_IceClimb::
# 882 "data/maps/TARC3_base/scripts.pory"
	finditem ITEM_TM01, 1
	end


TARC3_Dummy_Start_Amber::
# 887 "data/maps/TARC3_base/scripts.pory"
	lockall
# 888 "data/maps/TARC3_base/scripts.pory"
	setvar VAR_CASTFORM_PHASE, 1
# 889 "data/maps/TARC3_base/scripts.pory"
	setvar VAR_TRIGGER_XATU_EVENT, 1
# 890 "data/maps/TARC3_base/scripts.pory"
	finditem ITEM_HEAT_ROCK, 1
# 891 "data/maps/TARC3_base/scripts.pory"
	givemon SPECIES_CASTFORM_SUNNY, 25
# 892 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_ITEM_AMBER_SHARD
# 893 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_RUN_XATU_AMBER
# 894 "data/maps/TARC3_base/scripts.pory"
	releaseall
# 895 "data/maps/TARC3_base/scripts.pory"
	warp MAP_TARC3_WEATHER_INSTITUTE_2F, 9, 8
# 896 "data/maps/TARC3_base/scripts.pory"
	waitstate
	end


# 151 "data/maps/TARC3_base/scripts.pory"
TARC3_Amber_Munchlax_Movement_0:
# 152 "data/maps/TARC3_base/scripts.pory"
	walk_up
# 152 "data/maps/TARC3_base/scripts.pory"
	walk_up
# 153 "data/maps/TARC3_base/scripts.pory"
	face_down
	step_end

# 160 "data/maps/TARC3_base/scripts.pory"
TARC3_Amber_Munchlax_Movement_1:
# 161 "data/maps/TARC3_base/scripts.pory"
	walk_left
# 162 "data/maps/TARC3_base/scripts.pory"
	face_right
	step_end

# 165 "data/maps/TARC3_base/scripts.pory"
TARC3_Amber_Munchlax_Movement_2:
# 166 "data/maps/TARC3_base/scripts.pory"
	walk_left
# 166 "data/maps/TARC3_base/scripts.pory"
	walk_left
# 167 "data/maps/TARC3_base/scripts.pory"
	face_right
	step_end

# 832 "data/maps/TARC3_base/scripts.pory"
TARC3_Lapras1_Source_Movement_0:
# 833 "data/maps/TARC3_base/scripts.pory"
	walk_down
# 833 "data/maps/TARC3_base/scripts.pory"
	walk_down
# 833 "data/maps/TARC3_base/scripts.pory"
	walk_down
# 834 "data/maps/TARC3_base/scripts.pory"
	walk_right
# 834 "data/maps/TARC3_base/scripts.pory"
	walk_right
# 835 "data/maps/TARC3_base/scripts.pory"
	walk_down
# 835 "data/maps/TARC3_base/scripts.pory"
	walk_down
# 835 "data/maps/TARC3_base/scripts.pory"
	walk_down
	step_end

# 852 "data/maps/TARC3_base/scripts.pory"
TARC3_Lapras2_Source_Movement_0:
# 853 "data/maps/TARC3_base/scripts.pory"
	walk_right
# 853 "data/maps/TARC3_base/scripts.pory"
	walk_right
# 853 "data/maps/TARC3_base/scripts.pory"
	walk_right
# 853 "data/maps/TARC3_base/scripts.pory"
	walk_right
# 853 "data/maps/TARC3_base/scripts.pory"
	walk_right
# 854 "data/maps/TARC3_base/scripts.pory"
	walk_up
# 855 "data/maps/TARC3_base/scripts.pory"
	walk_right
# 856 "data/maps/TARC3_base/scripts.pory"
	walk_up
# 857 "data/maps/TARC3_base/scripts.pory"
	walk_right
# 858 "data/maps/TARC3_base/scripts.pory"
	walk_up
# 859 "data/maps/TARC3_base/scripts.pory"
	walk_right
# 860 "data/maps/TARC3_base/scripts.pory"
	walk_up
# 861 "data/maps/TARC3_base/scripts.pory"
	walk_right
	step_end

TARC3_Base_Paras_Text_0:
# 45 "data/maps/TARC3_base/scripts.pory"
	.string "Paras$"

TARC3_Base_Paras_Text_1:
# 54 "data/maps/TARC3_base/scripts.pory"
	.string "Weather Shards?\nI only heard of fungal spores.\pDoes that help?$"

TARC3_Base_Vulpix_Text_0:
# 77 "data/maps/TARC3_base/scripts.pory"
	.string "Vulpix$"

TARC3_Base_Vulpix_Text_1:
# 86 "data/maps/TARC3_base/scripts.pory"
	.string "I don't care about the weather.\pFor me the sun is always shining!$"

TARC3_Base_Dewpider_Text_0:
# 109 "data/maps/TARC3_base/scripts.pory"
	.string "Dewpider$"

TARC3_Base_Dewpider_Text_1:
# 118 "data/maps/TARC3_base/scripts.pory"
	.string "There is a strange rock at the\nTree of Life.\pIt feels dangerous to the life\nat the pond\pYou must not touch it!$"

TARC3_Amber_Munchlax_Text_0:
# 141 "data/maps/TARC3_base/scripts.pory"
	.string "Munchlax$"

TARC3_Amber_Munchlax_Text_1:
# 150 "data/maps/TARC3_base/scripts.pory"
	.string "It's too hot to battle!$"

TARC3_Amber_Munchlax_Text_2:
# 179 "data/maps/TARC3_base/scripts.pory"
	.string "Do you have some berries for me?\nI am hungry!$"

TARC3_Amber_Combusken_Text_0:
# 202 "data/maps/TARC3_base/scripts.pory"
	.string "Combusken$"

TARC3_Amber_Combusken_Text_1:
# 212 "data/maps/TARC3_base/scripts.pory"
	.string "What are you doing here\nin my territory?\pYou think you can handle me?\nThe sun is on my side, too!$"

TARC3_Amber_Observer_Text_0:
# 234 "data/maps/TARC3_base/scripts.pory"
	.string "Fomantis$"

TARC3_Amber_Observer_Text_1:
# 238 "data/maps/TARC3_base/scripts.pory"
	.string "We're cool again!$"

TARC3_Amber_Observer_Text_2:
# 243 "data/maps/TARC3_base/scripts.pory"
	.string "This HELIOPTILE is so mean!\pCan you help me scaring it away?$"

TARC3_Amber_Observer_Text_3:
# 254 "data/maps/TARC3_base/scripts.pory"
	.string "Thank you for helping me!$"

TARC3_Amber_Torkoal_Text_0:
# 287 "data/maps/TARC3_base/scripts.pory"
	.string "Torkoal$"

TARC3_Amber_Torkoal_Text_1:
# 297 "data/maps/TARC3_base/scripts.pory"
	.string "Who dares to bother me during my nap?\p...\pAre you after that stone?\pYou cannot have it, it's dangerous!\nIt will turn the world into endless rain!$"

TARC3_Amber_Torkoal_Text_2:
# 310 "data/maps/TARC3_base/scripts.pory"
	.string "Defeated. Like it was nothing.\pMaybe you are able to save us\nfrom the chaos!\pHere, I found it behind the lava pool!$"

TARC3_Azure_Toxicroak_Text_0:
# 331 "data/maps/TARC3_base/scripts.pory"
	.string "Toxicroak$"

TARC3_Azure_Toxicroak_Text_1:
# 345 "data/maps/TARC3_base/scripts.pory"
	.string "This heat is miserable!\nIt burns my skin!$"

TARC3_Azure_Toxicroak_Text_2:
# 347 "data/maps/TARC3_base/scripts.pory"
	.string "Heh... Now THIS is my kind of weather!\nCome on, then. Try your best!$"

TARC3_Azure_Toxicroak_Text_3:
# 349 "data/maps/TARC3_base/scripts.pory"
	.string "You are playing with the weather?\pLet's see who is making the rules!$"

TARC3_Azure_Gastrodon_Text_0:
# 372 "data/maps/TARC3_base/scripts.pory"
	.string "Gastrodon$"

TARC3_Azure_Gastrodon_Text_1:
# 386 "data/maps/TARC3_base/scripts.pory"
	.string "Trying to dry me out?\pIt'll take more than sunshine\nto pass me!$"

TARC3_Azure_Gastrodon_Text_2:
# 388 "data/maps/TARC3_base/scripts.pory"
	.string "Oh? You brought me even more water?\pLet's go, I take as much as you give!$"

TARC3_Azure_Gastrodon_Text_3:
# 390 "data/maps/TARC3_base/scripts.pory"
	.string "I don't care much about\nthe weather!\pBut this is my domain and you\nare trespassing!$"

TARC3_Azure_Observer_Text_0:
# 413 "data/maps/TARC3_base/scripts.pory"
	.string "Drampa$"

TARC3_Azure_Observer_Text_1:
# 422 "data/maps/TARC3_base/scripts.pory"
	.string "This SLOWKING is so toxic!\pIt behaves like a king that\nguards its treasure.\pI wonder what's up there.$"

TARC3_Azure_Observer_Text_2:
# 433 "data/maps/TARC3_base/scripts.pory"
	.string "Thanks for having my back!\pI need to go now, find the\nbully's house and burn it\lto the ground.$"

TARC3_Azure_Flygon_Text_0:
# 466 "data/maps/TARC3_base/scripts.pory"
	.string "Flygon$"

TARC3_Azure_Flygon_Text_1:
# 475 "data/maps/TARC3_base/scripts.pory"
	.string "The worst in the world is\nsnow and ice.\pI will keep you from\ncontrolling it!$"

TARC3_Azure_Flygon_Text_2:
# 489 "data/maps/TARC3_base/scripts.pory"
	.string "You are trying to restore the\nbalance of the weather again?\pWell that sounds like an\nhonorable path.\pI guess you can have this then.$"

TARC3_Azure_Flygon_Text_3:
# 496 "data/maps/TARC3_base/scripts.pory"
	.string "...\p...\pThis is the end of this beta.\pThe final release will feature another\nsegment with snowy weather,\lnew puzzles and a final boss fight.$"

TARC3_Azure_Flygon_Text_4:
# 499 "data/maps/TARC3_base/scripts.pory"
	.string "You have found all nine\nSTARDUSTS already!\pGreat job!\nThis is all for now.$"

TARC3_Azure_Flygon_Text_5:
# 502 "data/maps/TARC3_base/scripts.pory"
	.string "There is nine STARDUSTS\nto be found.\lKeep looking!$"

TARC3_Paras_Post_Text_0:
# 522 "data/maps/TARC3_base/scripts.pory"
	.string "I am enjoying the warmth!\pJust keep any Fire Types away!$"

TARC3_Paras_Post_Text_1:
# 525 "data/maps/TARC3_base/scripts.pory"
	.string "What's this weather?\pThis is miserable, I can't stand it!$"

TARC3_Paras_Post_Text_2:
# 528 "data/maps/TARC3_base/scripts.pory"
	.string "Noticed that the icon above my\nhead is gone now?\pIt shows if a Pokémon wants to fight.$"

TARC3_Surskit_Text_0:
# 538 "data/maps/TARC3_base/scripts.pory"
	.string "Surskit$"

TARC3_Surskit_Text_1:
# 543 "data/maps/TARC3_base/scripts.pory"
	.string "My pond!\nWhere did it go???$"

TARC3_Surskit_Text_2:
# 545 "data/maps/TARC3_base/scripts.pory"
	.string "You made this rain?\pI LOVE IT!\nPlease never make it stop.$"

TARC3_Surskit_Text_3:
# 549 "data/maps/TARC3_base/scripts.pory"
	.string "The weather has been crazy lately!\pI hope it calms down soon.$"

TARC3_Vulpix_Post_Text_0:
# 562 "data/maps/TARC3_base/scripts.pory"
	.string "You transformed and even\nchanged your moveset?\pThat is so cool!\nHow did you do that?$"

TARC3_Dewpider_Post_Text_0:
# 575 "data/maps/TARC3_base/scripts.pory"
	.string "What did you do???\pWhere did my home go???$"

TARC3_Dewpider_Post_Text_1:
# 577 "data/maps/TARC3_base/scripts.pory"
	.string "Please be careful!$"

TARC3_Munchlax_Post_Text_0:
# 590 "data/maps/TARC3_base/scripts.pory"
	.string "I heard there is a mysterious\nobject on top of the mountain.\pThey say it can make it rain.\pAnd rain makes berries grow.\nYummy!$"

TARC3_Combusken_Post_Text_0:
# 603 "data/maps/TARC3_base/scripts.pory"
	.string "Now this is unfair!$"

TARC3_Combusken_Post_Text_1:
# 605 "data/maps/TARC3_base/scripts.pory"
	.string "I clearly should have won!$"

TARC3_Torkoal_Post_Text_0:
# 618 "data/maps/TARC3_base/scripts.pory"
	.string "Woah! I didn't know you could\nturn the lava into stone!$"

TARC3_Torkoal_Post_Text_1:
# 620 "data/maps/TARC3_base/scripts.pory"
	.string "Please help us bring back normality!$"

TARC3_Toxicroak_Post_Text_0:
# 633 "data/maps/TARC3_base/scripts.pory"
	.string "You used the water against me?\pThat's embarrassing!$"

TARC3_Gastrodon_Post_Text_0:
# 646 "data/maps/TARC3_base/scripts.pory"
	.string "I've seen a hidden cave\nentrance when I was roaming\lthe riverbed.\pMaybe there is a way for you\nto get there?$"

TARC3_Flygon_Post_Text_0:
# 659 "data/maps/TARC3_base/scripts.pory"
	.string "...\p...\pThis is the end of this beta.\pThe final release will feature\nanother segment with snowy weather,\lnew puzzles and a final boss fight.$"

TARC3_Whimsicott_Text_0:
# 675 "data/maps/TARC3_base/scripts.pory"
	.string "Whimsicott$"

TARC3_Whimsicott_Text_1:
# 679 "data/maps/TARC3_base/scripts.pory"
	.string "When you plant and water it,\nit will grow!\pBut don't expect much from these\nApricorn trees.\lThey haven't changed in ages.$"

TARC3_Whimsicott_Text_2:
# 683 "data/maps/TARC3_base/scripts.pory"
	.string "Hi there, glad you found me!\pMy name is Whimsicott and\nI am the gardener of this town.\pHere, you can have a seed, too.$"

TARC3_Feebas_Text_0:
# 698 "data/maps/TARC3_base/scripts.pory"
	.string "Feebas$"

TARC3_Feebas_Text_1:
# 701 "data/maps/TARC3_base/scripts.pory"
	.string "If you ever get stuck,\nswim on the river and\lswitch to your Base form.\pThis will respawn you in front\nof the institute.$"

TARC3_Chatot1_Text_0:
# 709 "data/maps/TARC3_base/scripts.pory"
	.string "Chatot$"

TARC3_Chatot1_Text_1:
# 712 "data/maps/TARC3_base/scripts.pory"
	.string "Have you met Whimsicott, yet?\pShe is really friendly and\nprovides the town with crops.$"

TARC3_Chatot2_Text_0:
# 723 "data/maps/TARC3_base/scripts.pory"
	.string "Remember, if you get stuck,\nswim on the river and\lswitch to your Base form.\pRIP$"

TARC3_Audino_Text_0:
# 731 "data/maps/TARC3_base/scripts.pory"
	.string "Audino$"

TARC3_Audino_Text_1:
# 738 "data/maps/TARC3_base/scripts.pory"
	.string "Whimsicott taught me how to\nreverse-grow plants.\pBut I am no gardener myself.\nYou can have this.$"

TARC3_Audino_Post_Text_0:
# 746 "data/maps/TARC3_base/scripts.pory"
	.string "If you interact with withered plants\nyou can finish them off with it.$"

TARC3_Minccino_Text_0:
# 754 "data/maps/TARC3_base/scripts.pory"
	.string "Minccino$"

TARC3_Minccino_Text_1:
# 757 "data/maps/TARC3_base/scripts.pory"
	.string "The top of the volcano is hard\nto reach.\pI tried it before, but it was\ntoo steep and slippery.$"

TARC3_Smeargle_Text_0:
# 765 "data/maps/TARC3_base/scripts.pory"
	.string "Smeargle$"

TARC3_Smeargle_Text_1:
# 768 "data/maps/TARC3_base/scripts.pory"
	.string "Did you notice the palette changes\nduring sunny weather?\pThat's me recoloring everything\nin an instant!$"

TARC3_Nosepass_Text_0:
# 776 "data/maps/TARC3_base/scripts.pory"
	.string "Nosepass$"

TARC3_Nosepass_Text_1:
# 779 "data/maps/TARC3_base/scripts.pory"
	.string "I tried this shortcut,\nbut it didn't work out.$"

TARC3_Ducklett_Text_0:
# 787 "data/maps/TARC3_base/scripts.pory"
	.string "Ducklett$"

TARC3_Ducklett_Text_1:
# 790 "data/maps/TARC3_base/scripts.pory"
	.string "Well done!\nI don't get many visitors here.\pThe way you got here will open\nmany more hidden paths for you.$"

TARC3_Sliggoo_Text_0:
# 798 "data/maps/TARC3_base/scripts.pory"
	.string "Sliggoo$"

TARC3_Sliggoo_Text_1:
# 801 "data/maps/TARC3_base/scripts.pory"
	.string "Heya, guess what level I am now!\pIt's already 69, but I just don't\nevolve.\pSo sad...$"

TARC3_Goodra_Text_0:
# 809 "data/maps/TARC3_base/scripts.pory"
	.string "Goodra$"

TARC3_Goodra_Text_1:
# 813 "data/maps/TARC3_base/scripts.pory"
	.string "I tried evolving for so long,\nbut I had no idea how...$"

TARC3_Goodra_Text_2:
# 816 "data/maps/TARC3_base/scripts.pory"
	.string "You made it rain.\nThat was it!\pThank you so much for the help!\pHere, takes this.$"

TARC3_Lapras1_Source_Text_0:
# 828 "data/maps/TARC3_base/scripts.pory"
	.string "Lapras$"

TARC3_Lapras1_Source_Text_1:
# 831 "data/maps/TARC3_base/scripts.pory"
	.string "Hello my friend!\nYou are trying to save us all?\pIf you find me and my friend\nwe might be able to assist\lyou on the mission.$"

TARC3_Lapras2_Source_Text_0:
# 851 "data/maps/TARC3_base/scripts.pory"
	.string "Yay, a new friend!\pLet's meet at the little island\nWEST from here.$"

TARC3_Sign_TreeOfLife_Text_0:
# 872 "data/maps/TARC3_base/scripts.pory"
	.string "Tree of Life\pOnly Arceus may enter.$"

TARC3_Sign_ApricornTree_Text_0:
# 877 "data/maps/TARC3_base/scripts.pory"
	.string "An Apricorn Tree blocks\nthe entrance.\pPost game area.$"
