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


TARC3_Base_Torkoal::
# 37 "data/maps/TARC3_base/scripts.pory"
	goto TARC3_Amber_Torkoal
	return


TARC3_Base_Paras::
# 44 "data/maps/TARC3_base/scripts.pory"
	cant_see_if_set FLAG_BASE_PARAS_BEATEN
# 45 "data/maps/TARC3_base/scripts.pory"
	lock
# 46 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 49 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Base_Paras_Text_0
# 50 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_PARAS_BEATEN, TARC3_Base_Paras_2
# 56 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_START
# 57 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Base_Paras_Text_0
# 58 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Base_Paras_Text_1
# 59 "data/maps/TARC3_base/scripts.pory"
	setwildbattle SPECIES_PARAS, 25
# 60 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_PARAS, CRY_MODE_ENCOUNTER
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
	goto_if_eq TARC3_Base_Paras_5
TARC3_Base_Paras_1:
# 71 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Base_Paras_2:
# 52 "data/maps/TARC3_base/scripts.pory"
	goto TARC3_Paras_Post
	goto TARC3_Base_Paras_1

TARC3_Base_Paras_5:
# 67 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_BASE_PARAS_BEATEN
# 68 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_START
	goto TARC3_Base_Paras_1


TARC3_Base_Vulpix::
# 76 "data/maps/TARC3_base/scripts.pory"
	cant_see_if_set FLAG_BASE_VULPIX_BEATEN
# 77 "data/maps/TARC3_base/scripts.pory"
	lock
# 78 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 81 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Base_Vulpix_Text_0
# 82 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_VULPIX_BEATEN, TARC3_Base_Vulpix_2
# 88 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_VULPIX
# 89 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Base_Vulpix_Text_0
# 90 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Base_Vulpix_Text_1
# 91 "data/maps/TARC3_base/scripts.pory"
	setwildbattle SPECIES_VULPIX, 25
# 92 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_VULPIX, CRY_MODE_ENCOUNTER
# 93 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 94 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 95 "data/maps/TARC3_base/scripts.pory"
	dowildbattle
# 96 "data/maps/TARC3_base/scripts.pory"
	callnative WasBattleWon
# 97 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Base_Vulpix_5
TARC3_Base_Vulpix_1:
# 103 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Base_Vulpix_2:
# 84 "data/maps/TARC3_base/scripts.pory"
	goto TARC3_Vulpix_Post
	goto TARC3_Base_Vulpix_1

TARC3_Base_Vulpix_5:
# 99 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_BASE_VULPIX_BEATEN
# 100 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_START
	goto TARC3_Base_Vulpix_1


TARC3_Base_Dewpider::
# 108 "data/maps/TARC3_base/scripts.pory"
	cant_see_if_set FLAG_BASE_DEWPIDER_BEATEN
# 109 "data/maps/TARC3_base/scripts.pory"
	lock
# 110 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 113 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Base_Dewpider_Text_0
# 114 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_DEWPIDER_BEATEN, TARC3_Base_Dewpider_2
# 120 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_DEWPIDER
# 121 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Base_Dewpider_Text_0
# 122 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Base_Dewpider_Text_1
# 123 "data/maps/TARC3_base/scripts.pory"
	setwildbattle SPECIES_DEWPIDER, 25
# 124 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_DEWPIDER, CRY_MODE_ENCOUNTER
# 125 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 126 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 127 "data/maps/TARC3_base/scripts.pory"
	dowildbattle
# 128 "data/maps/TARC3_base/scripts.pory"
	callnative WasBattleWon
# 129 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Base_Dewpider_5
TARC3_Base_Dewpider_1:
# 135 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Base_Dewpider_2:
# 116 "data/maps/TARC3_base/scripts.pory"
	goto TARC3_Dewpider_Post
	goto TARC3_Base_Dewpider_1

TARC3_Base_Dewpider_5:
# 131 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_BASE_DEWPIDER_BEATEN
# 132 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_START
	goto TARC3_Base_Dewpider_1


TARC3_Base_Wooper_backup::
	end


TARC3_Amber_Munchlax_Left::
	end


TARC3_Amber_Munchlax_Right::
	end


TARC3_Amber_Munchlax::
# 153 "data/maps/TARC3_base/scripts.pory"
	cant_see_if_set FLAG_BASE_MUNCHLAX_BEATEN
# 154 "data/maps/TARC3_base/scripts.pory"
	lock
# 155 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 158 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Amber_Munchlax_Text_0
# 159 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_MUNCHLAX_BEATEN, TARC3_Amber_Munchlax_2
# 165 "data/maps/TARC3_base/scripts.pory"
	compare VAR_TRANSFORM_MON, SPECIES_CASTFORM_SUNNY
	goto_if_eq TARC3_Amber_Munchlax_5
# 178 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_MUNCHLAX
# 179 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Amber_Munchlax_Text_0
# 180 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Amber_Munchlax_Text_2
# 181 "data/maps/TARC3_base/scripts.pory"
	setwildbattle SPECIES_MUNCHLAX, 25
# 182 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_MUNCHLAX, CRY_MODE_ENCOUNTER
# 183 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 184 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 185 "data/maps/TARC3_base/scripts.pory"
	dowildbattle
# 186 "data/maps/TARC3_base/scripts.pory"
	callnative WasBattleWon
# 187 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Amber_Munchlax_8
TARC3_Amber_Munchlax_1:
# 194 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Amber_Munchlax_2:
# 161 "data/maps/TARC3_base/scripts.pory"
	goto TARC3_Munchlax_Post
	goto TARC3_Amber_Munchlax_1

TARC3_Amber_Munchlax_5:
# 167 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Amber_Munchlax_Text_1
# 168 "data/maps/TARC3_base/scripts.pory"
	applymovement LOCALID_PLAYER, TARC3_Amber_Munchlax_Movement_0
# 172 "data/maps/TARC3_base/scripts.pory"
	waitmovement 0
# 173 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Amber_Munchlax_8:
# 189 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_BASE_MUNCHLAX_BEATEN
# 190 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_START
	goto TARC3_Amber_Munchlax_1


TARC3_Amber_Combusken::
# 199 "data/maps/TARC3_base/scripts.pory"
	cant_see_if_set FLAG_BASE_COMBUSKEN_BEATEN
# 200 "data/maps/TARC3_base/scripts.pory"
	lock
# 201 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 203 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Amber_Combusken_Text_0
# 205 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_COMBUSKEN_BEATEN, TARC3_Amber_Combusken_2
# 211 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_COMBUSKEN
# 212 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Amber_Combusken_Text_0
# 213 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Amber_Combusken_Text_1
# 214 "data/maps/TARC3_base/scripts.pory"
	setwildbattle SPECIES_COMBUSKEN, 25
# 215 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_COMBUSKEN, CRY_MODE_ENCOUNTER
# 216 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 217 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 218 "data/maps/TARC3_base/scripts.pory"
	dowildbattle
# 219 "data/maps/TARC3_base/scripts.pory"
	callnative WasBattleWon
# 220 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Amber_Combusken_5
TARC3_Amber_Combusken_1:
# 226 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Amber_Combusken_2:
# 207 "data/maps/TARC3_base/scripts.pory"
	goto TARC3_Combusken_Post
	goto TARC3_Amber_Combusken_1

TARC3_Amber_Combusken_5:
# 222 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_BASE_COMBUSKEN_BEATEN
# 223 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_START
	goto TARC3_Amber_Combusken_1


TARC3_Amber_Observer::
# 231 "data/maps/TARC3_base/scripts.pory"
	cant_see_if_set FLAG_BASE_HELIOPTILE_BEATEN
# 232 "data/maps/TARC3_base/scripts.pory"
	lock
# 233 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 235 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Amber_Observer_Text_0
# 237 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_HELIOPTILE_BEATEN, TARC3_Amber_Observer_2
# 243 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_HELIOPTILE
# 244 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Amber_Observer_Text_2
# 245 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_HELIOPTILE, CRY_MODE_ENCOUNTER
# 246 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 247 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 248 "data/maps/TARC3_base/scripts.pory"
	ai_vs_ai_wild_battle SPECIES_FOMANTIS, SPECIES_HELIOPTILE, 25
# 249 "data/maps/TARC3_base/scripts.pory"
	callnative WasBattleWon
# 250 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Amber_Observer_5
TARC3_Amber_Observer_1:
# 279 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Amber_Observer_2:
# 239 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Amber_Observer_Text_1
	goto TARC3_Amber_Observer_1

TARC3_Amber_Observer_5:
# 252 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_BASE_HELIOPTILE_BEATEN
# 253 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_START
# 254 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Amber_Observer_Text_0
# 255 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Amber_Observer_Text_3
# 256 "data/maps/TARC3_base/scripts.pory"
	fadescreen FADE_TO_BLACK
# 257 "data/maps/TARC3_base/scripts.pory"
	special HealPlayerParty
# 259 "data/maps/TARC3_base/scripts.pory"
	callnative GetCurrentTransformationSpecies
# 260 "data/maps/TARC3_base/scripts.pory"
	switch VAR_RESULT
# 262 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM, TARC3_Amber_Observer_9
# 265 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_RAINY, TARC3_Amber_Observer_10
# 268 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_SUNNY, TARC3_Amber_Observer_11
# 271 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_SNOWY, TARC3_Amber_Observer_12
TARC3_Amber_Observer_7:
# 275 "data/maps/TARC3_base/scripts.pory"
	delay 60
# 276 "data/maps/TARC3_base/scripts.pory"
	fadescreen FADE_FROM_BLACK
	goto TARC3_Amber_Observer_1

TARC3_Amber_Observer_9:
# 263 "data/maps/TARC3_base/scripts.pory"
	removeobject LOCALID_BASE_FOMANTIS
# 264 "data/maps/TARC3_base/scripts.pory"
	removeobject LOCALID_BASE_HELIOPTILE
	goto TARC3_Amber_Observer_7

TARC3_Amber_Observer_10:
# 266 "data/maps/TARC3_base/scripts.pory"
	removeobject LOCALID_RAINY_FOMANTIS
# 267 "data/maps/TARC3_base/scripts.pory"
	removeobject LOCALID_RAINY_HELIOPTILE
	goto TARC3_Amber_Observer_7

TARC3_Amber_Observer_11:
# 269 "data/maps/TARC3_base/scripts.pory"
	removeobject LOCALID_SUNNY_FOMANTIS
# 270 "data/maps/TARC3_base/scripts.pory"
	removeobject LOCALID_SUNNY_HELIOPTILE
	goto TARC3_Amber_Observer_7

TARC3_Amber_Observer_12:
# 272 "data/maps/TARC3_base/scripts.pory"
	removeobject LOCALID_SNOWY_FOMANTIS
# 273 "data/maps/TARC3_base/scripts.pory"
	removeobject LOCALID_SNOWY_HELIOPTILE
	goto TARC3_Amber_Observer_7


TARC3_Amber_Torkoal::
# 284 "data/maps/TARC3_base/scripts.pory"
	cant_see_if_set FLAG_BASE_TORKOAL_BEATEN
# 285 "data/maps/TARC3_base/scripts.pory"
	lock
# 286 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 288 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Amber_Torkoal_Text_0
# 290 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_TORKOAL_BEATEN, TARC3_Amber_Torkoal_2
# 296 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_TORKOAL
# 297 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Amber_Torkoal_Text_0
# 298 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Amber_Torkoal_Text_1
# 299 "data/maps/TARC3_base/scripts.pory"
	setwildbattle SPECIES_TORKOAL, 25
# 300 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_TORKOAL, CRY_MODE_ENCOUNTER
# 301 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 302 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 303 "data/maps/TARC3_base/scripts.pory"
	dowildbattle
# 304 "data/maps/TARC3_base/scripts.pory"
	callnative WasBattleWon
# 305 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Amber_Torkoal_5
TARC3_Amber_Torkoal_1:
# 323 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Amber_Torkoal_2:
# 292 "data/maps/TARC3_base/scripts.pory"
	goto TARC3_Torkoal_Post
	goto TARC3_Amber_Torkoal_1

TARC3_Amber_Torkoal_5:
# 307 "data/maps/TARC3_base/scripts.pory"
	lock
# 308 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 309 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_BASE_TORKOAL_BEATEN
# 310 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_START
# 311 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Amber_Torkoal_Text_2
# 312 "data/maps/TARC3_base/scripts.pory"
	setvar VAR_CASTFORM_PHASE, 2
# 313 "data/maps/TARC3_base/scripts.pory"
	setvar VAR_TRIGGER_XATU_EVENT, 1
# 314 "data/maps/TARC3_base/scripts.pory"
	giveitem ITEM_DAMP_ROCK, 1
# 315 "data/maps/TARC3_base/scripts.pory"
	givemon SPECIES_CASTFORM_RAINY, 25
# 316 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_ITEM_AZURE_SHARD
# 317 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_RUN_XATU_AZURE
# 318 "data/maps/TARC3_base/scripts.pory"
	releaseall
# 319 "data/maps/TARC3_base/scripts.pory"
	warp MAP_TARC3_WEATHER_INSTITUTE_2F, 9, 8
# 320 "data/maps/TARC3_base/scripts.pory"
	waitstate
	goto TARC3_Amber_Torkoal_1


TARC3_Azure_Toxicroak::
# 328 "data/maps/TARC3_base/scripts.pory"
	cant_see_if_set FLAG_BASE_TOXICROAK_BEATEN
# 329 "data/maps/TARC3_base/scripts.pory"
	lock
# 330 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 332 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Azure_Toxicroak_Text_0
# 334 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_TOXICROAK_BEATEN, TARC3_Azure_Toxicroak_2
# 340 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_TOXICROAK
# 341 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Azure_Toxicroak_Text_0
# 342 "data/maps/TARC3_base/scripts.pory"
	callnative GetCurrentTransformationSpecies
# 343 "data/maps/TARC3_base/scripts.pory"
	switch VAR_RESULT
# 345 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_SUNNY, TARC3_Azure_Toxicroak_7
# 347 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_RAINY, TARC3_Azure_Toxicroak_8
# 350 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Azure_Toxicroak_Text_3
TARC3_Azure_Toxicroak_5:
# 352 "data/maps/TARC3_base/scripts.pory"
	setwildbattle SPECIES_TOXICROAK, 25
# 353 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_TOXICROAK, CRY_MODE_ENCOUNTER
# 354 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 355 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 356 "data/maps/TARC3_base/scripts.pory"
	dowildbattle
# 357 "data/maps/TARC3_base/scripts.pory"
	callnative WasBattleWon
# 358 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Azure_Toxicroak_10
TARC3_Azure_Toxicroak_1:
# 364 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Azure_Toxicroak_2:
# 336 "data/maps/TARC3_base/scripts.pory"
	goto TARC3_Toxicroak_Post
	goto TARC3_Azure_Toxicroak_1

TARC3_Azure_Toxicroak_7:
# 346 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Azure_Toxicroak_Text_1
	goto TARC3_Azure_Toxicroak_5

TARC3_Azure_Toxicroak_8:
# 348 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Azure_Toxicroak_Text_2
	goto TARC3_Azure_Toxicroak_5

TARC3_Azure_Toxicroak_10:
# 360 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_BASE_TOXICROAK_BEATEN
# 361 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_START
	goto TARC3_Azure_Toxicroak_1


TARC3_Azure_Gastrodon::
# 369 "data/maps/TARC3_base/scripts.pory"
	cant_see_if_set FLAG_BASE_GASTRODON_BEATEN
# 370 "data/maps/TARC3_base/scripts.pory"
	lock
# 371 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 373 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Azure_Gastrodon_Text_0
# 375 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_GASTRODON_BEATEN, TARC3_Azure_Gastrodon_2
# 381 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_GASTRODON
# 382 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Azure_Gastrodon_Text_0
# 383 "data/maps/TARC3_base/scripts.pory"
	callnative GetCurrentTransformationSpecies
# 384 "data/maps/TARC3_base/scripts.pory"
	switch VAR_RESULT
# 386 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_SUNNY, TARC3_Azure_Gastrodon_7
# 388 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_RAINY, TARC3_Azure_Gastrodon_8
# 391 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Azure_Gastrodon_Text_3
TARC3_Azure_Gastrodon_5:
# 393 "data/maps/TARC3_base/scripts.pory"
	setwildbattle SPECIES_GASTRODON, 25
# 394 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_GASTRODON, CRY_MODE_ENCOUNTER
# 395 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 396 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 397 "data/maps/TARC3_base/scripts.pory"
	dowildbattle
# 398 "data/maps/TARC3_base/scripts.pory"
	callnative WasBattleWon
# 399 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Azure_Gastrodon_10
TARC3_Azure_Gastrodon_1:
# 405 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Azure_Gastrodon_2:
# 377 "data/maps/TARC3_base/scripts.pory"
	goto TARC3_Gastrodon_Post
	goto TARC3_Azure_Gastrodon_1

TARC3_Azure_Gastrodon_7:
# 387 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Azure_Gastrodon_Text_1
	goto TARC3_Azure_Gastrodon_5

TARC3_Azure_Gastrodon_8:
# 389 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Azure_Gastrodon_Text_2
	goto TARC3_Azure_Gastrodon_5

TARC3_Azure_Gastrodon_10:
# 401 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_BASE_GASTRODON_BEATEN
# 402 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_START
	goto TARC3_Azure_Gastrodon_1


TARC3_Azure_Observer::
# 410 "data/maps/TARC3_base/scripts.pory"
	cant_see_if_set FLAG_BASE_SLOWKING_BEATEN
# 411 "data/maps/TARC3_base/scripts.pory"
	lock
# 412 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 414 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Azure_Observer_Text_0
# 416 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_SLOWKING_BEATEN, TARC3_Azure_Observer_2
# 422 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_SLOWKING
# 423 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Azure_Observer_Text_1
# 424 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_SLOWKING, CRY_MODE_ENCOUNTER
# 425 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 426 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 427 "data/maps/TARC3_base/scripts.pory"
	ai_vs_ai_wild_battle SPECIES_DRAMPA, SPECIES_SLOWKING, 25
# 428 "data/maps/TARC3_base/scripts.pory"
	callnative WasBattleWon
# 429 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Azure_Observer_5
TARC3_Azure_Observer_1:
# 458 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Azure_Observer_2:
# 418 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Amber_Observer_Text_1
	goto TARC3_Azure_Observer_1

TARC3_Azure_Observer_5:
# 431 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_BASE_SLOWKING_BEATEN
# 432 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_START
# 433 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Azure_Observer_Text_0
# 434 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Azure_Observer_Text_2
# 435 "data/maps/TARC3_base/scripts.pory"
	fadescreen FADE_TO_BLACK
# 436 "data/maps/TARC3_base/scripts.pory"
	special HealPlayerParty
# 438 "data/maps/TARC3_base/scripts.pory"
	callnative GetCurrentTransformationSpecies
# 439 "data/maps/TARC3_base/scripts.pory"
	switch VAR_RESULT
# 441 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM, TARC3_Azure_Observer_9
# 444 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_RAINY, TARC3_Azure_Observer_10
# 447 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_SUNNY, TARC3_Azure_Observer_11
# 450 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_SNOWY, TARC3_Azure_Observer_12
TARC3_Azure_Observer_7:
# 454 "data/maps/TARC3_base/scripts.pory"
	delay 60
# 455 "data/maps/TARC3_base/scripts.pory"
	fadescreen FADE_FROM_BLACK
	goto TARC3_Azure_Observer_1

TARC3_Azure_Observer_9:
# 442 "data/maps/TARC3_base/scripts.pory"
	removeobject LOCALID_BASE_DRAMPA
# 443 "data/maps/TARC3_base/scripts.pory"
	removeobject LOCALID_BASE_SLOWKING
	goto TARC3_Azure_Observer_7

TARC3_Azure_Observer_10:
# 445 "data/maps/TARC3_base/scripts.pory"
	removeobject LOCALID_RAINY_DRAMPA
# 446 "data/maps/TARC3_base/scripts.pory"
	removeobject LOCALID_RAINY_SLOWKING
	goto TARC3_Azure_Observer_7

TARC3_Azure_Observer_11:
# 448 "data/maps/TARC3_base/scripts.pory"
	removeobject LOCALID_SUNNY_DRAMPA
# 449 "data/maps/TARC3_base/scripts.pory"
	removeobject LOCALID_SUNNY_SLOWKING
	goto TARC3_Azure_Observer_7

TARC3_Azure_Observer_12:
# 451 "data/maps/TARC3_base/scripts.pory"
	removeobject LOCALID_SNOWY_DRAMPA
# 452 "data/maps/TARC3_base/scripts.pory"
	removeobject LOCALID_SNOWY_SLOWKING
	goto TARC3_Azure_Observer_7


TARC3_Azure_Flygon::
# 463 "data/maps/TARC3_base/scripts.pory"
	cant_see_if_set FLAG_BASE_FLYGON_BEATEN
# 464 "data/maps/TARC3_base/scripts.pory"
	lock
# 465 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 467 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Azure_Flygon_Text_0
# 469 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_FLYGON_BEATEN, TARC3_Azure_Flygon_2
# 475 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_FLYGON
# 476 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Azure_Flygon_Text_1
# 477 "data/maps/TARC3_base/scripts.pory"
	setwildbattle SPECIES_FLYGON, 25
# 478 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_FLYGON, CRY_MODE_ENCOUNTER
# 479 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 480 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 481 "data/maps/TARC3_base/scripts.pory"
	dowildbattle
# 482 "data/maps/TARC3_base/scripts.pory"
	callnative WasBattleWon
# 483 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Azure_Flygon_5
TARC3_Azure_Flygon_1:
# 510 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Azure_Flygon_2:
# 471 "data/maps/TARC3_base/scripts.pory"
	goto TARC3_Flygon_Post
	goto TARC3_Azure_Flygon_1

TARC3_Azure_Flygon_5:
# 485 "data/maps/TARC3_base/scripts.pory"
	lock
# 486 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 487 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_BASE_FLYGON_BEATEN
# 488 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_START
# 489 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Azure_Flygon_Text_0
# 490 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Azure_Flygon_Text_2
# 493 "data/maps/TARC3_base/scripts.pory"
	giveitem ITEM_ICY_ROCK, 1
# 495 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_ITEM_GLACIAL_SHARD
# 497 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Azure_Flygon_Text_3
# 498 "data/maps/TARC3_base/scripts.pory"
	checkitem ITEM_MIRACLE_SEED, 8
# 499 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Azure_Flygon_8
# 503 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Azure_Flygon_Text_5
TARC3_Azure_Flygon_7:
# 505 "data/maps/TARC3_base/scripts.pory"
	releaseall
	goto TARC3_Azure_Flygon_1

TARC3_Azure_Flygon_8:
# 500 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Azure_Flygon_Text_4
	goto TARC3_Azure_Flygon_7


TARC3_Paras_Post::
# 517 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_SURSKIT, CRY_MODE_NORMAL
# 519 "data/maps/TARC3_base/scripts.pory"
	callnative GetCurrentTransformationSpecies
# 520 "data/maps/TARC3_base/scripts.pory"
	switch VAR_RESULT
# 522 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_SUNNY, TARC3_Paras_Post_3
# 524 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_RAINY, TARC3_Paras_Post_4
# 525 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_SNOWY, TARC3_Paras_Post_4
# 527 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM, TARC3_Paras_Post_5
TARC3_Paras_Post_5:
# 529 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Paras_Post_Text_2
TARC3_Paras_Post_1:
# 531 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Paras_Post_3:
# 523 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Paras_Post_Text_0
	goto TARC3_Paras_Post_1

TARC3_Paras_Post_4:
# 526 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Paras_Post_Text_1
	goto TARC3_Paras_Post_1


TARC3_Surskit::
# 536 "data/maps/TARC3_base/scripts.pory"
	lock
# 537 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 538 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_SURSKIT, CRY_MODE_NORMAL
# 539 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Surskit_Text_0
# 540 "data/maps/TARC3_base/scripts.pory"
	callnative GetCurrentTransformationSpecies
# 541 "data/maps/TARC3_base/scripts.pory"
	switch VAR_RESULT
# 543 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_SUNNY, TARC3_Surskit_3
# 545 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_RAINY, TARC3_Surskit_4
# 547 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_SNOWY, TARC3_Surskit_5
# 548 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM, TARC3_Surskit_5
TARC3_Surskit_5:
# 550 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Surskit_Text_3
TARC3_Surskit_1:
# 552 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Surskit_3:
# 544 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Surskit_Text_1
	goto TARC3_Surskit_1

TARC3_Surskit_4:
# 546 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Surskit_Text_2
	goto TARC3_Surskit_1


TARC3_Vulpix_Post::
# 557 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_VULPIX, CRY_MODE_NORMAL
# 559 "data/maps/TARC3_base/scripts.pory"
	callnative GetCurrentTransformationSpecies
# 560 "data/maps/TARC3_base/scripts.pory"
	switch VAR_RESULT
# 563 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Vulpix_Post_Text_0
# 565 "data/maps/TARC3_base/scripts.pory"
	release
	end


TARC3_Dewpider_Post::
# 570 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_DEWPIDER, CRY_MODE_NORMAL
# 572 "data/maps/TARC3_base/scripts.pory"
	callnative GetCurrentTransformationSpecies
# 573 "data/maps/TARC3_base/scripts.pory"
	switch VAR_RESULT
# 575 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_SUNNY, TARC3_Dewpider_Post_3
# 578 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Dewpider_Post_Text_1
TARC3_Dewpider_Post_1:
# 580 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Dewpider_Post_3:
# 576 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Dewpider_Post_Text_0
	goto TARC3_Dewpider_Post_1


TARC3_Munchlax_Post::
# 585 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_MUNCHLAX, CRY_MODE_NORMAL
# 587 "data/maps/TARC3_base/scripts.pory"
	callnative GetCurrentTransformationSpecies
# 588 "data/maps/TARC3_base/scripts.pory"
	switch VAR_RESULT
# 591 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Munchlax_Post_Text_0
# 593 "data/maps/TARC3_base/scripts.pory"
	release
	end


TARC3_Combusken_Post::
# 598 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_COMBUSKEN, CRY_MODE_NORMAL
# 600 "data/maps/TARC3_base/scripts.pory"
	callnative GetCurrentTransformationSpecies
# 601 "data/maps/TARC3_base/scripts.pory"
	switch VAR_RESULT
# 603 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_RAINY, TARC3_Combusken_Post_3
# 606 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Combusken_Post_Text_1
TARC3_Combusken_Post_1:
# 608 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Combusken_Post_3:
# 604 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Combusken_Post_Text_0
	goto TARC3_Combusken_Post_1


TARC3_Torkoal_Post::
# 613 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_TORKOAL, CRY_MODE_NORMAL
# 615 "data/maps/TARC3_base/scripts.pory"
	callnative GetCurrentTransformationSpecies
# 616 "data/maps/TARC3_base/scripts.pory"
	switch VAR_RESULT
# 618 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_RAINY, TARC3_Torkoal_Post_3
# 621 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Torkoal_Post_Text_1
TARC3_Torkoal_Post_1:
# 623 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Torkoal_Post_3:
# 619 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Torkoal_Post_Text_0
	goto TARC3_Torkoal_Post_1


TARC3_Toxicroak_Post::
# 628 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_TOXICROAK, CRY_MODE_NORMAL
# 630 "data/maps/TARC3_base/scripts.pory"
	callnative GetCurrentTransformationSpecies
# 631 "data/maps/TARC3_base/scripts.pory"
	switch VAR_RESULT
# 634 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Toxicroak_Post_Text_0
# 636 "data/maps/TARC3_base/scripts.pory"
	release
	end


TARC3_Gastrodon_Post::
# 641 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_GASTRODON, CRY_MODE_NORMAL
# 643 "data/maps/TARC3_base/scripts.pory"
	callnative GetCurrentTransformationSpecies
# 644 "data/maps/TARC3_base/scripts.pory"
	switch VAR_RESULT
# 647 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Gastrodon_Post_Text_0
# 649 "data/maps/TARC3_base/scripts.pory"
	release
	end


TARC3_Flygon_Post::
# 654 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_FLYGON, CRY_MODE_NORMAL
# 656 "data/maps/TARC3_base/scripts.pory"
	callnative GetCurrentTransformationSpecies
# 657 "data/maps/TARC3_base/scripts.pory"
	switch VAR_RESULT
# 660 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Flygon_Post_Text_0
# 661 "data/maps/TARC3_base/scripts.pory"
	checkitem ITEM_MIRACLE_SEED, 8
# 662 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Flygon_Post_4
# 666 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Azure_Flygon_Text_5
TARC3_Flygon_Post_1:
# 669 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Flygon_Post_4:
# 663 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Azure_Flygon_Text_4
	goto TARC3_Flygon_Post_1


TARC3_Whimsicott::
# 674 "data/maps/TARC3_base/scripts.pory"
	lock
# 675 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 676 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Whimsicott_Text_0
# 678 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_WHIMSICOTT_GAVE_SEED, TARC3_Whimsicott_2
# 684 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Whimsicott_Text_2
# 685 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_WHIMSICOTT, CRY_MODE_NORMAL
# 686 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 687 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 688 "data/maps/TARC3_base/scripts.pory"
	giveitem ITEM_WEPEAR_BERRY, 1
# 689 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_WHIMSICOTT_GAVE_SEED
# 690 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Whimsicott_Text_1
TARC3_Whimsicott_1:
# 692 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Whimsicott_2:
# 680 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Whimsicott_Text_1
	goto TARC3_Whimsicott_1


TARC3_Feebas::
# 697 "data/maps/TARC3_base/scripts.pory"
	lock
# 698 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 699 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Feebas_Text_0
# 701 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_FEEBAS, CRY_MODE_NORMAL
# 702 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Feebas_Text_1
# 703 "data/maps/TARC3_base/scripts.pory"
	release
	end


TARC3_Chatot1::
# 708 "data/maps/TARC3_base/scripts.pory"
	lock
# 709 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 710 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Chatot1_Text_0
# 712 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_CHATOT, CRY_MODE_NORMAL
# 713 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Chatot1_Text_1
# 714 "data/maps/TARC3_base/scripts.pory"
	release
	end


TARC3_Chatot2::
# 719 "data/maps/TARC3_base/scripts.pory"
	lock
# 720 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 721 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Chatot1_Text_0
# 723 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_CHATOT, CRY_MODE_NORMAL
# 724 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Chatot2_Text_0
# 725 "data/maps/TARC3_base/scripts.pory"
	release
	end


TARC3_Audino::
# 730 "data/maps/TARC3_base/scripts.pory"
	lock
# 731 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 732 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Audino_Text_0
# 734 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_AUDINO, CRY_MODE_NORMAL
# 735 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_AUDINO_GAVE_HERBICIDE, TARC3_Audino_1
# 739 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Audino_Text_1
# 740 "data/maps/TARC3_base/scripts.pory"
	giveitem ITEM_HYPER_POTION
# 741 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_AUDINO_GAVE_HERBICIDE
# 742 "data/maps/TARC3_base/scripts.pory"
	goto TARC3_Audino_Post
	return

TARC3_Audino_1:
# 736 "data/maps/TARC3_base/scripts.pory"
	goto TARC3_Audino_Post
	return


TARC3_Audino_Post::
# 747 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Audino_Post_Text_0
# 748 "data/maps/TARC3_base/scripts.pory"
	release
	end


TARC3_Minccino::
# 753 "data/maps/TARC3_base/scripts.pory"
	lock
# 754 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 755 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Minccino_Text_0
# 757 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_MINCCINO, CRY_MODE_NORMAL
# 758 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Minccino_Text_1
# 759 "data/maps/TARC3_base/scripts.pory"
	release
	end


TARC3_Smeargle::
# 764 "data/maps/TARC3_base/scripts.pory"
	lock
# 765 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 766 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Smeargle_Text_0
# 768 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_SMEARGLE, CRY_MODE_NORMAL
# 769 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Smeargle_Text_1
# 770 "data/maps/TARC3_base/scripts.pory"
	release
	end


TARC3_Nosepass::
# 775 "data/maps/TARC3_base/scripts.pory"
	lock
# 776 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 777 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Nosepass_Text_0
# 779 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_NOSEPASS, CRY_MODE_NORMAL
# 780 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Nosepass_Text_1
# 781 "data/maps/TARC3_base/scripts.pory"
	release
	end


TARC3_Ducklett::
# 786 "data/maps/TARC3_base/scripts.pory"
	lock
# 787 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 788 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Ducklett_Text_0
# 790 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_DUCKLETT, CRY_MODE_NORMAL
# 791 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Ducklett_Text_1
# 792 "data/maps/TARC3_base/scripts.pory"
	release
	end


TARC3_Sliggoo::
# 797 "data/maps/TARC3_base/scripts.pory"
	lock
# 798 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 799 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Sliggoo_Text_0
# 801 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_SLIGGOO, CRY_MODE_NORMAL
# 802 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Sliggoo_Text_1
# 803 "data/maps/TARC3_base/scripts.pory"
	release
	end


TARC3_Goodra::
# 808 "data/maps/TARC3_base/scripts.pory"
	lock
# 809 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 810 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Goodra_Text_0
# 812 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_GOODRA, CRY_MODE_NORMAL
# 813 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_GOODRA_GAVE_ITEM, TARC3_Goodra_2
# 817 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Goodra_Text_2
# 818 "data/maps/TARC3_base/scripts.pory"
	giveitem ITEM_MIRACLE_SEED
# 819 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_GOODRA_GAVE_ITEM
# 820 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Goodra_Text_1
TARC3_Goodra_1:
# 822 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Goodra_2:
# 814 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Goodra_Text_1
	goto TARC3_Goodra_1


TARC3_Lapras1_Source::
# 827 "data/maps/TARC3_base/scripts.pory"
	lock
# 828 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 829 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Lapras1_Source_Text_0
# 831 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_LAPRAS, CRY_MODE_NORMAL
# 832 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Lapras1_Source_Text_1
# 833 "data/maps/TARC3_base/scripts.pory"
	applymovement VAR_LAST_TALKED, TARC3_Lapras1_Source_Movement_0
# 838 "data/maps/TARC3_base/scripts.pory"
	waitmovement 0
# 839 "data/maps/TARC3_base/scripts.pory"
	removeobject VAR_LAST_TALKED
# 840 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_LAPRAS1_SOURCE_INVISIBLE
# 841 "data/maps/TARC3_base/scripts.pory"
	clearflag FLAG_LAPRAS1_DEST_INVISIBLE
# 842 "data/maps/TARC3_base/scripts.pory"
	release
	end


TARC3_Lapras2_Source::
# 847 "data/maps/TARC3_base/scripts.pory"
	lock
# 848 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 849 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Lapras1_Source_Text_0
# 851 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_LAPRAS, CRY_MODE_NORMAL
# 852 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Lapras2_Source_Text_0
# 853 "data/maps/TARC3_base/scripts.pory"
	applymovement VAR_LAST_TALKED, TARC3_Lapras2_Source_Movement_0
# 864 "data/maps/TARC3_base/scripts.pory"
	waitmovement 0
# 865 "data/maps/TARC3_base/scripts.pory"
	removeobject VAR_LAST_TALKED
# 866 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_LAPRAS2_SOURCE_INVISIBLE
# 867 "data/maps/TARC3_base/scripts.pory"
	clearflag FLAG_LAPRAS2_DEST_INVISIBLE
# 868 "data/maps/TARC3_base/scripts.pory"
	release
	end


TARC3_Sign_TreeOfLife::
# 873 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Sign_TreeOfLife_Text_0, MSGBOX_SIGN
	end


TARC3_Sign_ApricornTree::
# 878 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Sign_ApricornTree_Text_0, MSGBOX_SIGN
	end


TARC3_Find_IceClimb::
# 883 "data/maps/TARC3_base/scripts.pory"
	finditem ITEM_TM01, 1
	end


TARC3_Dummy_Start_Amber::
# 888 "data/maps/TARC3_base/scripts.pory"
	lockall
# 889 "data/maps/TARC3_base/scripts.pory"
	setvar VAR_CASTFORM_PHASE, 1
# 890 "data/maps/TARC3_base/scripts.pory"
	setvar VAR_TRIGGER_XATU_EVENT, 1
# 891 "data/maps/TARC3_base/scripts.pory"
	finditem ITEM_HEAT_ROCK, 1
# 892 "data/maps/TARC3_base/scripts.pory"
	givemon SPECIES_CASTFORM_SUNNY, 25
# 893 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_ITEM_AMBER_SHARD
# 894 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_RUN_XATU_AMBER
# 895 "data/maps/TARC3_base/scripts.pory"
	releaseall
# 896 "data/maps/TARC3_base/scripts.pory"
	warp MAP_TARC3_WEATHER_INSTITUTE_2F, 9, 8
# 897 "data/maps/TARC3_base/scripts.pory"
	waitstate
	end


# 168 "data/maps/TARC3_base/scripts.pory"
TARC3_Amber_Munchlax_Movement_0:
# 169 "data/maps/TARC3_base/scripts.pory"
	walk_up
# 169 "data/maps/TARC3_base/scripts.pory"
	walk_up
# 170 "data/maps/TARC3_base/scripts.pory"
	face_down
	step_end

# 833 "data/maps/TARC3_base/scripts.pory"
TARC3_Lapras1_Source_Movement_0:
# 834 "data/maps/TARC3_base/scripts.pory"
	walk_down
# 834 "data/maps/TARC3_base/scripts.pory"
	walk_down
# 834 "data/maps/TARC3_base/scripts.pory"
	walk_down
# 835 "data/maps/TARC3_base/scripts.pory"
	walk_right
# 835 "data/maps/TARC3_base/scripts.pory"
	walk_right
# 836 "data/maps/TARC3_base/scripts.pory"
	walk_down
# 836 "data/maps/TARC3_base/scripts.pory"
	walk_down
# 836 "data/maps/TARC3_base/scripts.pory"
	walk_down
	step_end

# 853 "data/maps/TARC3_base/scripts.pory"
TARC3_Lapras2_Source_Movement_0:
# 854 "data/maps/TARC3_base/scripts.pory"
	walk_right
# 854 "data/maps/TARC3_base/scripts.pory"
	walk_right
# 854 "data/maps/TARC3_base/scripts.pory"
	walk_right
# 854 "data/maps/TARC3_base/scripts.pory"
	walk_right
# 854 "data/maps/TARC3_base/scripts.pory"
	walk_right
# 855 "data/maps/TARC3_base/scripts.pory"
	walk_up
# 856 "data/maps/TARC3_base/scripts.pory"
	walk_right
# 857 "data/maps/TARC3_base/scripts.pory"
	walk_up
# 858 "data/maps/TARC3_base/scripts.pory"
	walk_right
# 859 "data/maps/TARC3_base/scripts.pory"
	walk_up
# 860 "data/maps/TARC3_base/scripts.pory"
	walk_right
# 861 "data/maps/TARC3_base/scripts.pory"
	walk_up
# 862 "data/maps/TARC3_base/scripts.pory"
	walk_right
	step_end

TARC3_Base_Paras_Text_0:
# 49 "data/maps/TARC3_base/scripts.pory"
	.string "Paras$"

TARC3_Base_Paras_Text_1:
# 58 "data/maps/TARC3_base/scripts.pory"
	.string "Weather Shards?\nI only heard of fungal spores.\pDoes that help?$"

TARC3_Base_Vulpix_Text_0:
# 81 "data/maps/TARC3_base/scripts.pory"
	.string "Vulpix$"

TARC3_Base_Vulpix_Text_1:
# 90 "data/maps/TARC3_base/scripts.pory"
	.string "I don't care about the weather.\pFor me the sun is always shining!$"

TARC3_Base_Dewpider_Text_0:
# 113 "data/maps/TARC3_base/scripts.pory"
	.string "Dewpider$"

TARC3_Base_Dewpider_Text_1:
# 122 "data/maps/TARC3_base/scripts.pory"
	.string "There is a strange rock at the\nTree of Life.\pIt feels dangerous to the life\nat the pond\pYou must not touch it!$"

TARC3_Amber_Munchlax_Text_0:
# 158 "data/maps/TARC3_base/scripts.pory"
	.string "Munchlax$"

TARC3_Amber_Munchlax_Text_1:
# 167 "data/maps/TARC3_base/scripts.pory"
	.string "It's too hot to battle!$"

TARC3_Amber_Munchlax_Text_2:
# 180 "data/maps/TARC3_base/scripts.pory"
	.string "Do you have some berries for me?\nI am hungry!$"

TARC3_Amber_Combusken_Text_0:
# 203 "data/maps/TARC3_base/scripts.pory"
	.string "Combusken$"

TARC3_Amber_Combusken_Text_1:
# 213 "data/maps/TARC3_base/scripts.pory"
	.string "What are you doing here\nin my territory?\pYou think you can handle me?\nThe sun is on my side, too!$"

TARC3_Amber_Observer_Text_0:
# 235 "data/maps/TARC3_base/scripts.pory"
	.string "Fomantis$"

TARC3_Amber_Observer_Text_1:
# 239 "data/maps/TARC3_base/scripts.pory"
	.string "We're cool again!$"

TARC3_Amber_Observer_Text_2:
# 244 "data/maps/TARC3_base/scripts.pory"
	.string "This HELIOPTILE is so mean!\pCan you help me scaring it away?$"

TARC3_Amber_Observer_Text_3:
# 255 "data/maps/TARC3_base/scripts.pory"
	.string "Thank you for helping me!$"

TARC3_Amber_Torkoal_Text_0:
# 288 "data/maps/TARC3_base/scripts.pory"
	.string "Torkoal$"

TARC3_Amber_Torkoal_Text_1:
# 298 "data/maps/TARC3_base/scripts.pory"
	.string "Who dares to bother me during my nap?\p...\pAre you after that stone?\pYou cannot have it, it's dangerous!\nIt will turn the world into endless rain!$"

TARC3_Amber_Torkoal_Text_2:
# 311 "data/maps/TARC3_base/scripts.pory"
	.string "Defeated. Like it was nothing.\pMaybe you are able to save us\nfrom the chaos!\pHere, I found it behind the lava pool!$"

TARC3_Azure_Toxicroak_Text_0:
# 332 "data/maps/TARC3_base/scripts.pory"
	.string "Toxicroak$"

TARC3_Azure_Toxicroak_Text_1:
# 346 "data/maps/TARC3_base/scripts.pory"
	.string "This heat is miserable!\nIt burns my skin!$"

TARC3_Azure_Toxicroak_Text_2:
# 348 "data/maps/TARC3_base/scripts.pory"
	.string "Heh... Now THIS is my kind of weather!\nCome on, then. Try your best!$"

TARC3_Azure_Toxicroak_Text_3:
# 350 "data/maps/TARC3_base/scripts.pory"
	.string "You are playing with the weather?\pLet's see who is making the rules!$"

TARC3_Azure_Gastrodon_Text_0:
# 373 "data/maps/TARC3_base/scripts.pory"
	.string "Gastrodon$"

TARC3_Azure_Gastrodon_Text_1:
# 387 "data/maps/TARC3_base/scripts.pory"
	.string "Trying to dry me out?\pIt'll take more than sunshine\nto pass me!$"

TARC3_Azure_Gastrodon_Text_2:
# 389 "data/maps/TARC3_base/scripts.pory"
	.string "Oh? You brought me even more water?\pLet's go, I take as much as you give!$"

TARC3_Azure_Gastrodon_Text_3:
# 391 "data/maps/TARC3_base/scripts.pory"
	.string "I don't care much about\nthe weather!\pBut this is my domain and you\nare trespassing!$"

TARC3_Azure_Observer_Text_0:
# 414 "data/maps/TARC3_base/scripts.pory"
	.string "Drampa$"

TARC3_Azure_Observer_Text_1:
# 423 "data/maps/TARC3_base/scripts.pory"
	.string "This SLOWKING is so toxic!\pIt behaves like a king that\nguards its treasure.\pI wonder what's up there.$"

TARC3_Azure_Observer_Text_2:
# 434 "data/maps/TARC3_base/scripts.pory"
	.string "Thanks for having my back!\pI need to go now, find the\nbully's house and burn it\lto the ground.$"

TARC3_Azure_Flygon_Text_0:
# 467 "data/maps/TARC3_base/scripts.pory"
	.string "Flygon$"

TARC3_Azure_Flygon_Text_1:
# 476 "data/maps/TARC3_base/scripts.pory"
	.string "The worst in the world is\nsnow and ice.\pI will keep you from\ncontrolling it!$"

TARC3_Azure_Flygon_Text_2:
# 490 "data/maps/TARC3_base/scripts.pory"
	.string "You are trying to restore the\nbalance of the weather again?\pWell that sounds like an\nhonorable path.\pI guess you can have this then.$"

TARC3_Azure_Flygon_Text_3:
# 497 "data/maps/TARC3_base/scripts.pory"
	.string "...\p...\pThis is the end of this beta.\pThe final release will feature another\nsegment with snowy weather,\lnew puzzles and a final boss fight.$"

TARC3_Azure_Flygon_Text_4:
# 500 "data/maps/TARC3_base/scripts.pory"
	.string "You have found all eight\nMIRACLE SEEDS already!\pGreat job!\nThis is all for now.$"

TARC3_Azure_Flygon_Text_5:
# 503 "data/maps/TARC3_base/scripts.pory"
	.string "There is eight MIRACLE SEEDS\nto be found.\lKeep looking!$"

TARC3_Paras_Post_Text_0:
# 523 "data/maps/TARC3_base/scripts.pory"
	.string "I am enjoying the warmth!\pJust keep any Fire Types away!$"

TARC3_Paras_Post_Text_1:
# 526 "data/maps/TARC3_base/scripts.pory"
	.string "What's this weather?\pThis is miserable, I can't stand it!$"

TARC3_Paras_Post_Text_2:
# 529 "data/maps/TARC3_base/scripts.pory"
	.string "You can make it sunny?\pI am rooting for you!$"

TARC3_Surskit_Text_0:
# 539 "data/maps/TARC3_base/scripts.pory"
	.string "Surskit$"

TARC3_Surskit_Text_1:
# 544 "data/maps/TARC3_base/scripts.pory"
	.string "My pond!\nWhere did it go???$"

TARC3_Surskit_Text_2:
# 546 "data/maps/TARC3_base/scripts.pory"
	.string "You made this rain?\pI LOVE IT!\nPlease never make it stop.$"

TARC3_Surskit_Text_3:
# 550 "data/maps/TARC3_base/scripts.pory"
	.string "The weather has been crazy lately!\pI hope it calms down soon.$"

TARC3_Vulpix_Post_Text_0:
# 563 "data/maps/TARC3_base/scripts.pory"
	.string "You transformed and even\nchanged your moveset?\pThat is so cool!\nHow did you do that?$"

TARC3_Dewpider_Post_Text_0:
# 576 "data/maps/TARC3_base/scripts.pory"
	.string "What did you do???\pWhere did my home go???$"

TARC3_Dewpider_Post_Text_1:
# 578 "data/maps/TARC3_base/scripts.pory"
	.string "Please be careful!$"

TARC3_Munchlax_Post_Text_0:
# 591 "data/maps/TARC3_base/scripts.pory"
	.string "I heard there is a mysterious\nobject on top of the mountain.\pThey say it can make it rain.\pAnd rain makes berries grow.\nYummy!$"

TARC3_Combusken_Post_Text_0:
# 604 "data/maps/TARC3_base/scripts.pory"
	.string "Now this is unfair!$"

TARC3_Combusken_Post_Text_1:
# 606 "data/maps/TARC3_base/scripts.pory"
	.string "I clearly should have won!$"

TARC3_Torkoal_Post_Text_0:
# 619 "data/maps/TARC3_base/scripts.pory"
	.string "Woah! I didn't know you could\nturn the lava into stone!$"

TARC3_Torkoal_Post_Text_1:
# 621 "data/maps/TARC3_base/scripts.pory"
	.string "Please help us bring back normality!$"

TARC3_Toxicroak_Post_Text_0:
# 634 "data/maps/TARC3_base/scripts.pory"
	.string "You used the water against me?\pThat's embarrassing!$"

TARC3_Gastrodon_Post_Text_0:
# 647 "data/maps/TARC3_base/scripts.pory"
	.string "I've seen a hidden cave\nentrance when I was roaming\lthe riverbed.\pMaybe there is a way for you\nto get there?$"

TARC3_Flygon_Post_Text_0:
# 660 "data/maps/TARC3_base/scripts.pory"
	.string "...\p...\pThis is the end of this beta.\pThe final release will feature\nanother segment with snowy weather,\lnew puzzles and a final boss fight.$"

TARC3_Whimsicott_Text_0:
# 676 "data/maps/TARC3_base/scripts.pory"
	.string "Whimsicott$"

TARC3_Whimsicott_Text_1:
# 680 "data/maps/TARC3_base/scripts.pory"
	.string "When you plant and water it,\nit will grow!\pBut don't expect much from these\nApricorn trees.\lThey haven't changed in ages.$"

TARC3_Whimsicott_Text_2:
# 684 "data/maps/TARC3_base/scripts.pory"
	.string "Hi there, glad you found me!\pMy name is Whimsicott and\nI am the gardener of this town.\pHere, you can have a seed, too.$"

TARC3_Feebas_Text_0:
# 699 "data/maps/TARC3_base/scripts.pory"
	.string "Feebas$"

TARC3_Feebas_Text_1:
# 702 "data/maps/TARC3_base/scripts.pory"
	.string "If you ever get stuck,\nswim on the river and\lswitch to your Base form.\pThis will respawn you in front\nof the institute.$"

TARC3_Chatot1_Text_0:
# 710 "data/maps/TARC3_base/scripts.pory"
	.string "Chatot$"

TARC3_Chatot1_Text_1:
# 713 "data/maps/TARC3_base/scripts.pory"
	.string "Have you met Whimsicott, yet?\pShe is really friendly and\nprovides the town with crops.$"

TARC3_Chatot2_Text_0:
# 724 "data/maps/TARC3_base/scripts.pory"
	.string "Remember, if you get stuck,\nswim on the river and\lswitch to your Base form.\pRIP$"

TARC3_Audino_Text_0:
# 732 "data/maps/TARC3_base/scripts.pory"
	.string "Audino$"

TARC3_Audino_Text_1:
# 739 "data/maps/TARC3_base/scripts.pory"
	.string "Whimsicott taught me how to\nreverse-grow plants.\pBut I am no gardener myself.\nYou can have this.$"

TARC3_Audino_Post_Text_0:
# 747 "data/maps/TARC3_base/scripts.pory"
	.string "If you interact with withered plants\nyou can finish them off with it.$"

TARC3_Minccino_Text_0:
# 755 "data/maps/TARC3_base/scripts.pory"
	.string "Minccino$"

TARC3_Minccino_Text_1:
# 758 "data/maps/TARC3_base/scripts.pory"
	.string "The top of the volcano is hard\nto reach.\pI tried it before, but it was\ntoo steep and slippery.$"

TARC3_Smeargle_Text_0:
# 766 "data/maps/TARC3_base/scripts.pory"
	.string "Smeargle$"

TARC3_Smeargle_Text_1:
# 769 "data/maps/TARC3_base/scripts.pory"
	.string "Did you notice the palette changes\nduring sunny weather?\pThat's me recoloring everything\nin an instant!$"

TARC3_Nosepass_Text_0:
# 777 "data/maps/TARC3_base/scripts.pory"
	.string "Nosepass$"

TARC3_Nosepass_Text_1:
# 780 "data/maps/TARC3_base/scripts.pory"
	.string "I tried this shortcut,\nbut it didn't work out.$"

TARC3_Ducklett_Text_0:
# 788 "data/maps/TARC3_base/scripts.pory"
	.string "Ducklett$"

TARC3_Ducklett_Text_1:
# 791 "data/maps/TARC3_base/scripts.pory"
	.string "Well done!\nI don't get many visitors here.\pThe way you got here will open\nmany more hidden paths for you.$"

TARC3_Sliggoo_Text_0:
# 799 "data/maps/TARC3_base/scripts.pory"
	.string "Sliggoo$"

TARC3_Sliggoo_Text_1:
# 802 "data/maps/TARC3_base/scripts.pory"
	.string "Heya, guess what level I am now!\pIt's already 69, but I just don't\nevolve.\pSo sad...$"

TARC3_Goodra_Text_0:
# 810 "data/maps/TARC3_base/scripts.pory"
	.string "Goodra$"

TARC3_Goodra_Text_1:
# 814 "data/maps/TARC3_base/scripts.pory"
	.string "I tried evolving for so long,\nbut I had no idea how...$"

TARC3_Goodra_Text_2:
# 817 "data/maps/TARC3_base/scripts.pory"
	.string "You made it rain.\nThat was it!\pThank you so much for the help!\pHere, takes this.$"

TARC3_Lapras1_Source_Text_0:
# 829 "data/maps/TARC3_base/scripts.pory"
	.string "Lapras$"

TARC3_Lapras1_Source_Text_1:
# 832 "data/maps/TARC3_base/scripts.pory"
	.string "Hello my friend!\nYou are trying to save us all?\pIf you find me and my friend\nwe might be able to assist\lyou on the mission.$"

TARC3_Lapras2_Source_Text_0:
# 852 "data/maps/TARC3_base/scripts.pory"
	.string "Yay, a new friend!\pLet's meet at the little island\nWEST from here.$"

TARC3_Sign_TreeOfLife_Text_0:
# 873 "data/maps/TARC3_base/scripts.pory"
	.string "Tree of Life\pOnly Arceus may enter.$"

TARC3_Sign_ApricornTree_Text_0:
# 878 "data/maps/TARC3_base/scripts.pory"
	.string "An Apricorn Tree blocks\nthe entrance.\pPost game area.$"
