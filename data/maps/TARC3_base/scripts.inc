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


TARC3_Base_Wooper_backup::
	end


TARC3_Amber_Munchlax_Left::
	end


TARC3_Amber_Munchlax_Right::
	end


TARC3_Amber_Munchlax::
# 149 "data/maps/TARC3_base/scripts.pory"
	cant_see_if_set FLAG_BASE_MUNCHLAX_BEATEN
# 150 "data/maps/TARC3_base/scripts.pory"
	lock
# 151 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 154 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Amber_Munchlax_Text_0
# 155 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_MUNCHLAX_BEATEN, TARC3_Amber_Munchlax_2
# 161 "data/maps/TARC3_base/scripts.pory"
	compare VAR_TRANSFORM_MON, SPECIES_CASTFORM_SUNNY
	goto_if_eq TARC3_Amber_Munchlax_5
# 174 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_MUNCHLAX
# 175 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Amber_Munchlax_Text_0
# 176 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Amber_Munchlax_Text_2
# 177 "data/maps/TARC3_base/scripts.pory"
	setwildbattle SPECIES_MUNCHLAX, 25
# 178 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_MUNCHLAX, CRY_MODE_ENCOUNTER
# 179 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 180 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 181 "data/maps/TARC3_base/scripts.pory"
	dowildbattle
# 182 "data/maps/TARC3_base/scripts.pory"
	callnative WasBattleWon
# 183 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Amber_Munchlax_8
TARC3_Amber_Munchlax_1:
# 190 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Amber_Munchlax_2:
# 157 "data/maps/TARC3_base/scripts.pory"
	goto TARC3_Munchlax_Post
	goto TARC3_Amber_Munchlax_1

TARC3_Amber_Munchlax_5:
# 163 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Amber_Munchlax_Text_1
# 164 "data/maps/TARC3_base/scripts.pory"
	applymovement LOCALID_PLAYER, TARC3_Amber_Munchlax_Movement_0
# 168 "data/maps/TARC3_base/scripts.pory"
	waitmovement 0
# 169 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Amber_Munchlax_8:
# 185 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_BASE_MUNCHLAX_BEATEN
# 186 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_START
	goto TARC3_Amber_Munchlax_1


TARC3_Amber_Combusken::
# 195 "data/maps/TARC3_base/scripts.pory"
	cant_see_if_set FLAG_BASE_COMBUSKEN_BEATEN
# 196 "data/maps/TARC3_base/scripts.pory"
	lock
# 197 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 199 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Amber_Combusken_Text_0
# 201 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_COMBUSKEN_BEATEN, TARC3_Amber_Combusken_2
# 207 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_COMBUSKEN
# 208 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Amber_Combusken_Text_0
# 209 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Amber_Combusken_Text_1
# 210 "data/maps/TARC3_base/scripts.pory"
	setwildbattle SPECIES_COMBUSKEN, 25
# 211 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_COMBUSKEN, CRY_MODE_ENCOUNTER
# 212 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 213 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 214 "data/maps/TARC3_base/scripts.pory"
	dowildbattle
# 215 "data/maps/TARC3_base/scripts.pory"
	callnative WasBattleWon
# 216 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Amber_Combusken_5
TARC3_Amber_Combusken_1:
# 222 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Amber_Combusken_2:
# 203 "data/maps/TARC3_base/scripts.pory"
	goto TARC3_Combusken_Post
	goto TARC3_Amber_Combusken_1

TARC3_Amber_Combusken_5:
# 218 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_BASE_COMBUSKEN_BEATEN
# 219 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_START
	goto TARC3_Amber_Combusken_1


TARC3_Amber_Observer::
# 227 "data/maps/TARC3_base/scripts.pory"
	cant_see_if_set FLAG_BASE_HELIOPTILE_BEATEN
# 228 "data/maps/TARC3_base/scripts.pory"
	lock
# 229 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 231 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Amber_Observer_Text_0
# 233 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_HELIOPTILE_BEATEN, TARC3_Amber_Observer_2
# 239 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_HELIOPTILE
# 240 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Amber_Observer_Text_2
# 241 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_HELIOPTILE, CRY_MODE_ENCOUNTER
# 242 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 243 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 244 "data/maps/TARC3_base/scripts.pory"
	ai_vs_ai_wild_battle SPECIES_FOMANTIS, SPECIES_HELIOPTILE, 25
# 245 "data/maps/TARC3_base/scripts.pory"
	callnative WasBattleWon
# 246 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Amber_Observer_5
TARC3_Amber_Observer_1:
# 275 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Amber_Observer_2:
# 235 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Amber_Observer_Text_1
	goto TARC3_Amber_Observer_1

TARC3_Amber_Observer_5:
# 248 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_BASE_HELIOPTILE_BEATEN
# 249 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_START
# 250 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Amber_Observer_Text_0
# 251 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Amber_Observer_Text_3
# 252 "data/maps/TARC3_base/scripts.pory"
	fadescreen FADE_TO_BLACK
# 253 "data/maps/TARC3_base/scripts.pory"
	special HealPlayerParty
# 255 "data/maps/TARC3_base/scripts.pory"
	callnative GetCurrentTransformationSpecies
# 256 "data/maps/TARC3_base/scripts.pory"
	switch VAR_RESULT
# 258 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM, TARC3_Amber_Observer_9
# 261 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_RAINY, TARC3_Amber_Observer_10
# 264 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_SUNNY, TARC3_Amber_Observer_11
# 267 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_SNOWY, TARC3_Amber_Observer_12
TARC3_Amber_Observer_7:
# 271 "data/maps/TARC3_base/scripts.pory"
	delay 60
# 272 "data/maps/TARC3_base/scripts.pory"
	fadescreen FADE_FROM_BLACK
	goto TARC3_Amber_Observer_1

TARC3_Amber_Observer_9:
# 259 "data/maps/TARC3_base/scripts.pory"
	removeobject LOCALID_BASE_FOMANTIS
# 260 "data/maps/TARC3_base/scripts.pory"
	removeobject LOCALID_BASE_HELIOPTILE
	goto TARC3_Amber_Observer_7

TARC3_Amber_Observer_10:
# 262 "data/maps/TARC3_base/scripts.pory"
	removeobject LOCALID_RAINY_FOMANTIS
# 263 "data/maps/TARC3_base/scripts.pory"
	removeobject LOCALID_RAINY_HELIOPTILE
	goto TARC3_Amber_Observer_7

TARC3_Amber_Observer_11:
# 265 "data/maps/TARC3_base/scripts.pory"
	removeobject LOCALID_SUNNY_FOMANTIS
# 266 "data/maps/TARC3_base/scripts.pory"
	removeobject LOCALID_SUNNY_HELIOPTILE
	goto TARC3_Amber_Observer_7

TARC3_Amber_Observer_12:
# 268 "data/maps/TARC3_base/scripts.pory"
	removeobject LOCALID_SNOWY_FOMANTIS
# 269 "data/maps/TARC3_base/scripts.pory"
	removeobject LOCALID_SNOWY_HELIOPTILE
	goto TARC3_Amber_Observer_7


TARC3_Amber_Torkoal::
# 280 "data/maps/TARC3_base/scripts.pory"
	cant_see_if_set FLAG_BASE_TORKOAL_BEATEN
# 281 "data/maps/TARC3_base/scripts.pory"
	lock
# 282 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 284 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Amber_Torkoal_Text_0
# 286 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_TORKOAL_BEATEN, TARC3_Amber_Torkoal_2
# 292 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_TORKOAL
# 293 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Amber_Torkoal_Text_0
# 294 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Amber_Torkoal_Text_1
# 295 "data/maps/TARC3_base/scripts.pory"
	setwildbattle SPECIES_TORKOAL, 25
# 296 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_TORKOAL, CRY_MODE_ENCOUNTER
# 297 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 298 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 299 "data/maps/TARC3_base/scripts.pory"
	dowildbattle
# 300 "data/maps/TARC3_base/scripts.pory"
	callnative WasBattleWon
# 301 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Amber_Torkoal_5
TARC3_Amber_Torkoal_1:
# 319 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Amber_Torkoal_2:
# 288 "data/maps/TARC3_base/scripts.pory"
	goto TARC3_Torkoal_Post
	goto TARC3_Amber_Torkoal_1

TARC3_Amber_Torkoal_5:
# 303 "data/maps/TARC3_base/scripts.pory"
	lock
# 304 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 305 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_BASE_TORKOAL_BEATEN
# 306 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_START
# 307 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Amber_Torkoal_Text_2
# 308 "data/maps/TARC3_base/scripts.pory"
	setvar VAR_CASTFORM_PHASE, 2
# 309 "data/maps/TARC3_base/scripts.pory"
	setvar VAR_TRIGGER_XATU_EVENT, 1
# 310 "data/maps/TARC3_base/scripts.pory"
	giveitem ITEM_DAMP_ROCK, 1
# 311 "data/maps/TARC3_base/scripts.pory"
	givemon SPECIES_CASTFORM_RAINY, 25
# 312 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_ITEM_AZURE_SHARD
# 313 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_RUN_XATU_AZURE
# 314 "data/maps/TARC3_base/scripts.pory"
	releaseall
# 315 "data/maps/TARC3_base/scripts.pory"
	warp MAP_TARC3_WEATHER_INSTITUTE_2F, 9, 8
# 316 "data/maps/TARC3_base/scripts.pory"
	waitstate
	goto TARC3_Amber_Torkoal_1


TARC3_Azure_Toxicroak::
# 324 "data/maps/TARC3_base/scripts.pory"
	cant_see_if_set FLAG_BASE_TOXICROAK_BEATEN
# 325 "data/maps/TARC3_base/scripts.pory"
	lock
# 326 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 328 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Azure_Toxicroak_Text_0
# 330 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_TOXICROAK_BEATEN, TARC3_Azure_Toxicroak_2
# 336 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_TOXICROAK
# 337 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Azure_Toxicroak_Text_0
# 338 "data/maps/TARC3_base/scripts.pory"
	callnative GetCurrentTransformationSpecies
# 339 "data/maps/TARC3_base/scripts.pory"
	switch VAR_RESULT
# 341 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_SUNNY, TARC3_Azure_Toxicroak_7
# 343 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_RAINY, TARC3_Azure_Toxicroak_8
# 346 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Azure_Toxicroak_Text_3
TARC3_Azure_Toxicroak_5:
# 348 "data/maps/TARC3_base/scripts.pory"
	setwildbattle SPECIES_TOXICROAK, 25
# 349 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_TOXICROAK, CRY_MODE_ENCOUNTER
# 350 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 351 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 352 "data/maps/TARC3_base/scripts.pory"
	dowildbattle
# 353 "data/maps/TARC3_base/scripts.pory"
	callnative WasBattleWon
# 354 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Azure_Toxicroak_10
TARC3_Azure_Toxicroak_1:
# 360 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Azure_Toxicroak_2:
# 332 "data/maps/TARC3_base/scripts.pory"
	goto TARC3_Toxicroak_Post
	goto TARC3_Azure_Toxicroak_1

TARC3_Azure_Toxicroak_7:
# 342 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Azure_Toxicroak_Text_1
	goto TARC3_Azure_Toxicroak_5

TARC3_Azure_Toxicroak_8:
# 344 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Azure_Toxicroak_Text_2
	goto TARC3_Azure_Toxicroak_5

TARC3_Azure_Toxicroak_10:
# 356 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_BASE_TOXICROAK_BEATEN
# 357 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_START
	goto TARC3_Azure_Toxicroak_1


TARC3_Azure_Gastrodon::
# 365 "data/maps/TARC3_base/scripts.pory"
	cant_see_if_set FLAG_BASE_GASTRODON_BEATEN
# 366 "data/maps/TARC3_base/scripts.pory"
	lock
# 367 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 369 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Azure_Gastrodon_Text_0
# 371 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_GASTRODON_BEATEN, TARC3_Azure_Gastrodon_2
# 377 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_GASTRODON
# 378 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Azure_Gastrodon_Text_0
# 379 "data/maps/TARC3_base/scripts.pory"
	callnative GetCurrentTransformationSpecies
# 380 "data/maps/TARC3_base/scripts.pory"
	switch VAR_RESULT
# 382 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_SUNNY, TARC3_Azure_Gastrodon_7
# 384 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_RAINY, TARC3_Azure_Gastrodon_8
# 387 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Azure_Gastrodon_Text_3
TARC3_Azure_Gastrodon_5:
# 389 "data/maps/TARC3_base/scripts.pory"
	setwildbattle SPECIES_GASTRODON, 25
# 390 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_GASTRODON, CRY_MODE_ENCOUNTER
# 391 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 392 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 393 "data/maps/TARC3_base/scripts.pory"
	dowildbattle
# 394 "data/maps/TARC3_base/scripts.pory"
	callnative WasBattleWon
# 395 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Azure_Gastrodon_10
TARC3_Azure_Gastrodon_1:
# 401 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Azure_Gastrodon_2:
# 373 "data/maps/TARC3_base/scripts.pory"
	goto TARC3_Gastrodon_Post
	goto TARC3_Azure_Gastrodon_1

TARC3_Azure_Gastrodon_7:
# 383 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Azure_Gastrodon_Text_1
	goto TARC3_Azure_Gastrodon_5

TARC3_Azure_Gastrodon_8:
# 385 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Azure_Gastrodon_Text_2
	goto TARC3_Azure_Gastrodon_5

TARC3_Azure_Gastrodon_10:
# 397 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_BASE_GASTRODON_BEATEN
# 398 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_START
	goto TARC3_Azure_Gastrodon_1


TARC3_Azure_Observer::
# 406 "data/maps/TARC3_base/scripts.pory"
	cant_see_if_set FLAG_BASE_SLOWKING_BEATEN
# 407 "data/maps/TARC3_base/scripts.pory"
	lock
# 408 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 410 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Azure_Observer_Text_0
# 412 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_SLOWKING_BEATEN, TARC3_Azure_Observer_2
# 418 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_SLOWKING
# 419 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Azure_Observer_Text_1
# 420 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_SLOWKING, CRY_MODE_ENCOUNTER
# 421 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 422 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 423 "data/maps/TARC3_base/scripts.pory"
	ai_vs_ai_wild_battle SPECIES_DRAMPA, SPECIES_SLOWKING, 25
# 424 "data/maps/TARC3_base/scripts.pory"
	callnative WasBattleWon
# 425 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Azure_Observer_5
TARC3_Azure_Observer_1:
# 454 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Azure_Observer_2:
# 414 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Amber_Observer_Text_1
	goto TARC3_Azure_Observer_1

TARC3_Azure_Observer_5:
# 427 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_BASE_SLOWKING_BEATEN
# 428 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_START
# 429 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Azure_Observer_Text_0
# 430 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Azure_Observer_Text_2
# 431 "data/maps/TARC3_base/scripts.pory"
	fadescreen FADE_TO_BLACK
# 432 "data/maps/TARC3_base/scripts.pory"
	special HealPlayerParty
# 434 "data/maps/TARC3_base/scripts.pory"
	callnative GetCurrentTransformationSpecies
# 435 "data/maps/TARC3_base/scripts.pory"
	switch VAR_RESULT
# 437 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM, TARC3_Azure_Observer_9
# 440 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_RAINY, TARC3_Azure_Observer_10
# 443 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_SUNNY, TARC3_Azure_Observer_11
# 446 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_SNOWY, TARC3_Azure_Observer_12
TARC3_Azure_Observer_7:
# 450 "data/maps/TARC3_base/scripts.pory"
	delay 60
# 451 "data/maps/TARC3_base/scripts.pory"
	fadescreen FADE_FROM_BLACK
	goto TARC3_Azure_Observer_1

TARC3_Azure_Observer_9:
# 438 "data/maps/TARC3_base/scripts.pory"
	removeobject LOCALID_BASE_DRAMPA
# 439 "data/maps/TARC3_base/scripts.pory"
	removeobject LOCALID_BASE_SLOWKING
	goto TARC3_Azure_Observer_7

TARC3_Azure_Observer_10:
# 441 "data/maps/TARC3_base/scripts.pory"
	removeobject LOCALID_RAINY_DRAMPA
# 442 "data/maps/TARC3_base/scripts.pory"
	removeobject LOCALID_RAINY_SLOWKING
	goto TARC3_Azure_Observer_7

TARC3_Azure_Observer_11:
# 444 "data/maps/TARC3_base/scripts.pory"
	removeobject LOCALID_SUNNY_DRAMPA
# 445 "data/maps/TARC3_base/scripts.pory"
	removeobject LOCALID_SUNNY_SLOWKING
	goto TARC3_Azure_Observer_7

TARC3_Azure_Observer_12:
# 447 "data/maps/TARC3_base/scripts.pory"
	removeobject LOCALID_SNOWY_DRAMPA
# 448 "data/maps/TARC3_base/scripts.pory"
	removeobject LOCALID_SNOWY_SLOWKING
	goto TARC3_Azure_Observer_7


TARC3_Azure_Flygon::
# 459 "data/maps/TARC3_base/scripts.pory"
	cant_see_if_set FLAG_BASE_FLYGON_BEATEN
# 460 "data/maps/TARC3_base/scripts.pory"
	lock
# 461 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 463 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Azure_Flygon_Text_0
# 465 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_FLYGON_BEATEN, TARC3_Azure_Flygon_2
# 471 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_FLYGON
# 472 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Azure_Flygon_Text_1
# 473 "data/maps/TARC3_base/scripts.pory"
	setwildbattle SPECIES_FLYGON, 25
# 474 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_FLYGON, CRY_MODE_ENCOUNTER
# 475 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 476 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 477 "data/maps/TARC3_base/scripts.pory"
	dowildbattle
# 478 "data/maps/TARC3_base/scripts.pory"
	callnative WasBattleWon
# 479 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Azure_Flygon_5
TARC3_Azure_Flygon_1:
# 506 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Azure_Flygon_2:
# 467 "data/maps/TARC3_base/scripts.pory"
	goto TARC3_Flygon_Post
	goto TARC3_Azure_Flygon_1

TARC3_Azure_Flygon_5:
# 481 "data/maps/TARC3_base/scripts.pory"
	lock
# 482 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 483 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_BASE_FLYGON_BEATEN
# 484 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_START
# 485 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Azure_Flygon_Text_0
# 486 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Azure_Flygon_Text_2
# 489 "data/maps/TARC3_base/scripts.pory"
	giveitem ITEM_ICY_ROCK, 1
# 491 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_ITEM_GLACIAL_SHARD
# 493 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Azure_Flygon_Text_3
# 494 "data/maps/TARC3_base/scripts.pory"
	checkitem ITEM_STARDUST, 9
# 495 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Azure_Flygon_8
# 499 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Azure_Flygon_Text_5
TARC3_Azure_Flygon_7:
# 501 "data/maps/TARC3_base/scripts.pory"
	releaseall
	goto TARC3_Azure_Flygon_1

TARC3_Azure_Flygon_8:
# 496 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Azure_Flygon_Text_4
	goto TARC3_Azure_Flygon_7


TARC3_Paras_Post::
# 513 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_SURSKIT, CRY_MODE_NORMAL
# 515 "data/maps/TARC3_base/scripts.pory"
	callnative GetCurrentTransformationSpecies
# 516 "data/maps/TARC3_base/scripts.pory"
	switch VAR_RESULT
# 518 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_SUNNY, TARC3_Paras_Post_3
# 520 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_RAINY, TARC3_Paras_Post_4
# 521 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_SNOWY, TARC3_Paras_Post_4
# 523 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM, TARC3_Paras_Post_5
TARC3_Paras_Post_5:
# 525 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Paras_Post_Text_2
TARC3_Paras_Post_1:
# 527 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Paras_Post_3:
# 519 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Paras_Post_Text_0
	goto TARC3_Paras_Post_1

TARC3_Paras_Post_4:
# 522 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Paras_Post_Text_1
	goto TARC3_Paras_Post_1


TARC3_Surskit::
# 532 "data/maps/TARC3_base/scripts.pory"
	lock
# 533 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 534 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_SURSKIT, CRY_MODE_NORMAL
# 535 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Surskit_Text_0
# 536 "data/maps/TARC3_base/scripts.pory"
	callnative GetCurrentTransformationSpecies
# 537 "data/maps/TARC3_base/scripts.pory"
	switch VAR_RESULT
# 539 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_SUNNY, TARC3_Surskit_3
# 541 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_RAINY, TARC3_Surskit_4
# 543 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_SNOWY, TARC3_Surskit_5
# 544 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM, TARC3_Surskit_5
TARC3_Surskit_5:
# 546 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Surskit_Text_3
TARC3_Surskit_1:
# 548 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Surskit_3:
# 540 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Surskit_Text_1
	goto TARC3_Surskit_1

TARC3_Surskit_4:
# 542 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Surskit_Text_2
	goto TARC3_Surskit_1


TARC3_Vulpix_Post::
# 553 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_VULPIX, CRY_MODE_NORMAL
# 555 "data/maps/TARC3_base/scripts.pory"
	callnative GetCurrentTransformationSpecies
# 556 "data/maps/TARC3_base/scripts.pory"
	switch VAR_RESULT
# 559 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Vulpix_Post_Text_0
# 561 "data/maps/TARC3_base/scripts.pory"
	release
	end


TARC3_Dewpider_Post::
# 566 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_DEWPIDER, CRY_MODE_NORMAL
# 568 "data/maps/TARC3_base/scripts.pory"
	callnative GetCurrentTransformationSpecies
# 569 "data/maps/TARC3_base/scripts.pory"
	switch VAR_RESULT
# 571 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_SUNNY, TARC3_Dewpider_Post_3
# 574 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Dewpider_Post_Text_1
TARC3_Dewpider_Post_1:
# 576 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Dewpider_Post_3:
# 572 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Dewpider_Post_Text_0
	goto TARC3_Dewpider_Post_1


TARC3_Munchlax_Post::
# 581 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_MUNCHLAX, CRY_MODE_NORMAL
# 583 "data/maps/TARC3_base/scripts.pory"
	callnative GetCurrentTransformationSpecies
# 584 "data/maps/TARC3_base/scripts.pory"
	switch VAR_RESULT
# 587 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Munchlax_Post_Text_0
# 589 "data/maps/TARC3_base/scripts.pory"
	release
	end


TARC3_Combusken_Post::
# 594 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_COMBUSKEN, CRY_MODE_NORMAL
# 596 "data/maps/TARC3_base/scripts.pory"
	callnative GetCurrentTransformationSpecies
# 597 "data/maps/TARC3_base/scripts.pory"
	switch VAR_RESULT
# 599 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_RAINY, TARC3_Combusken_Post_3
# 602 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Combusken_Post_Text_1
TARC3_Combusken_Post_1:
# 604 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Combusken_Post_3:
# 600 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Combusken_Post_Text_0
	goto TARC3_Combusken_Post_1


TARC3_Torkoal_Post::
# 609 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_TORKOAL, CRY_MODE_NORMAL
# 611 "data/maps/TARC3_base/scripts.pory"
	callnative GetCurrentTransformationSpecies
# 612 "data/maps/TARC3_base/scripts.pory"
	switch VAR_RESULT
# 614 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_RAINY, TARC3_Torkoal_Post_3
# 617 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Torkoal_Post_Text_1
TARC3_Torkoal_Post_1:
# 619 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Torkoal_Post_3:
# 615 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Torkoal_Post_Text_0
	goto TARC3_Torkoal_Post_1


TARC3_Toxicroak_Post::
# 624 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_TOXICROAK, CRY_MODE_NORMAL
# 626 "data/maps/TARC3_base/scripts.pory"
	callnative GetCurrentTransformationSpecies
# 627 "data/maps/TARC3_base/scripts.pory"
	switch VAR_RESULT
# 630 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Toxicroak_Post_Text_0
# 632 "data/maps/TARC3_base/scripts.pory"
	release
	end


TARC3_Gastrodon_Post::
# 637 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_GASTRODON, CRY_MODE_NORMAL
# 639 "data/maps/TARC3_base/scripts.pory"
	callnative GetCurrentTransformationSpecies
# 640 "data/maps/TARC3_base/scripts.pory"
	switch VAR_RESULT
# 643 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Gastrodon_Post_Text_0
# 645 "data/maps/TARC3_base/scripts.pory"
	release
	end


TARC3_Flygon_Post::
# 650 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_FLYGON, CRY_MODE_NORMAL
# 652 "data/maps/TARC3_base/scripts.pory"
	callnative GetCurrentTransformationSpecies
# 653 "data/maps/TARC3_base/scripts.pory"
	switch VAR_RESULT
# 656 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Flygon_Post_Text_0
# 657 "data/maps/TARC3_base/scripts.pory"
	checkitem ITEM_STARDUST, 9
# 658 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Flygon_Post_4
# 662 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Azure_Flygon_Text_5
TARC3_Flygon_Post_1:
# 665 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Flygon_Post_4:
# 659 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Azure_Flygon_Text_4
	goto TARC3_Flygon_Post_1


TARC3_Whimsicott::
# 670 "data/maps/TARC3_base/scripts.pory"
	lock
# 671 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 672 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Whimsicott_Text_0
# 674 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_WHIMSICOTT_GAVE_SEED, TARC3_Whimsicott_2
# 680 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Whimsicott_Text_2
# 681 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_WHIMSICOTT, CRY_MODE_NORMAL
# 682 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 683 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 684 "data/maps/TARC3_base/scripts.pory"
	giveitem ITEM_WEPEAR_BERRY, 1
# 685 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_WHIMSICOTT_GAVE_SEED
# 686 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Whimsicott_Text_1
TARC3_Whimsicott_1:
# 688 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Whimsicott_2:
# 676 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Whimsicott_Text_1
	goto TARC3_Whimsicott_1


TARC3_Feebas::
# 693 "data/maps/TARC3_base/scripts.pory"
	lock
# 694 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 695 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Feebas_Text_0
# 697 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_FEEBAS, CRY_MODE_NORMAL
# 698 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Feebas_Text_1
# 699 "data/maps/TARC3_base/scripts.pory"
	release
	end


TARC3_Chatot1::
# 704 "data/maps/TARC3_base/scripts.pory"
	lock
# 705 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 706 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Chatot1_Text_0
# 708 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_CHATOT, CRY_MODE_NORMAL
# 709 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Chatot1_Text_1
# 710 "data/maps/TARC3_base/scripts.pory"
	release
	end


TARC3_Chatot2::
# 715 "data/maps/TARC3_base/scripts.pory"
	lock
# 716 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 717 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Chatot1_Text_0
# 719 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_CHATOT, CRY_MODE_NORMAL
# 720 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Chatot2_Text_0
# 721 "data/maps/TARC3_base/scripts.pory"
	release
	end


TARC3_Audino::
# 726 "data/maps/TARC3_base/scripts.pory"
	lock
# 727 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 728 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Audino_Text_0
# 730 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_AUDINO, CRY_MODE_NORMAL
# 731 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_AUDINO_GAVE_HERBICIDE, TARC3_Audino_1
# 735 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Audino_Text_1
# 736 "data/maps/TARC3_base/scripts.pory"
	giveitem ITEM_HYPER_POTION
# 737 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_AUDINO_GAVE_HERBICIDE
# 738 "data/maps/TARC3_base/scripts.pory"
	goto TARC3_Audino_Post
	return

TARC3_Audino_1:
# 732 "data/maps/TARC3_base/scripts.pory"
	goto TARC3_Audino_Post
	return


TARC3_Audino_Post::
# 743 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Audino_Post_Text_0
# 744 "data/maps/TARC3_base/scripts.pory"
	release
	end


TARC3_Minccino::
# 749 "data/maps/TARC3_base/scripts.pory"
	lock
# 750 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 751 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Minccino_Text_0
# 753 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_MINCCINO, CRY_MODE_NORMAL
# 754 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Minccino_Text_1
# 755 "data/maps/TARC3_base/scripts.pory"
	release
	end


TARC3_Smeargle::
# 760 "data/maps/TARC3_base/scripts.pory"
	lock
# 761 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 762 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Smeargle_Text_0
# 764 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_SMEARGLE, CRY_MODE_NORMAL
# 765 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Smeargle_Text_1
# 766 "data/maps/TARC3_base/scripts.pory"
	release
	end


TARC3_Nosepass::
# 771 "data/maps/TARC3_base/scripts.pory"
	lock
# 772 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 773 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Nosepass_Text_0
# 775 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_NOSEPASS, CRY_MODE_NORMAL
# 776 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Nosepass_Text_1
# 777 "data/maps/TARC3_base/scripts.pory"
	release
	end


TARC3_Ducklett::
# 782 "data/maps/TARC3_base/scripts.pory"
	lock
# 783 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 784 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Ducklett_Text_0
# 786 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_DUCKLETT, CRY_MODE_NORMAL
# 787 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Ducklett_Text_1
# 788 "data/maps/TARC3_base/scripts.pory"
	release
	end


TARC3_Sliggoo::
# 793 "data/maps/TARC3_base/scripts.pory"
	lock
# 794 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 795 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Sliggoo_Text_0
# 797 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_SLIGGOO, CRY_MODE_NORMAL
# 798 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Sliggoo_Text_1
# 799 "data/maps/TARC3_base/scripts.pory"
	release
	end


TARC3_Goodra::
# 804 "data/maps/TARC3_base/scripts.pory"
	lock
# 805 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 806 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Goodra_Text_0
# 808 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_GOODRA, CRY_MODE_NORMAL
# 809 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_GOODRA_GAVE_ITEM, TARC3_Goodra_2
# 813 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Goodra_Text_2
# 814 "data/maps/TARC3_base/scripts.pory"
	giveitem ITEM_STARDUST
# 815 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_GOODRA_GAVE_ITEM
# 816 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Goodra_Text_1
TARC3_Goodra_1:
# 818 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Goodra_2:
# 810 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Goodra_Text_1
	goto TARC3_Goodra_1


TARC3_Lapras1_Source::
# 823 "data/maps/TARC3_base/scripts.pory"
	lock
# 824 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 825 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Lapras1_Source_Text_0
# 827 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_LAPRAS, CRY_MODE_NORMAL
# 828 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Lapras1_Source_Text_1
# 829 "data/maps/TARC3_base/scripts.pory"
	applymovement VAR_LAST_TALKED, TARC3_Lapras1_Source_Movement_0
# 834 "data/maps/TARC3_base/scripts.pory"
	waitmovement 0
# 835 "data/maps/TARC3_base/scripts.pory"
	removeobject VAR_LAST_TALKED
# 836 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_LAPRAS1_SOURCE_INVISIBLE
# 837 "data/maps/TARC3_base/scripts.pory"
	clearflag FLAG_LAPRAS1_DEST_INVISIBLE
# 838 "data/maps/TARC3_base/scripts.pory"
	release
	end


TARC3_Lapras2_Source::
# 843 "data/maps/TARC3_base/scripts.pory"
	lock
# 844 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 845 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Lapras1_Source_Text_0
# 847 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_LAPRAS, CRY_MODE_NORMAL
# 848 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Lapras2_Source_Text_0
# 849 "data/maps/TARC3_base/scripts.pory"
	applymovement VAR_LAST_TALKED, TARC3_Lapras2_Source_Movement_0
# 860 "data/maps/TARC3_base/scripts.pory"
	waitmovement 0
# 861 "data/maps/TARC3_base/scripts.pory"
	removeobject VAR_LAST_TALKED
# 862 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_LAPRAS2_SOURCE_INVISIBLE
# 863 "data/maps/TARC3_base/scripts.pory"
	clearflag FLAG_LAPRAS2_DEST_INVISIBLE
# 864 "data/maps/TARC3_base/scripts.pory"
	release
	end


TARC3_Sign_TreeOfLife::
# 869 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Sign_TreeOfLife_Text_0, MSGBOX_SIGN
	end


TARC3_Sign_ApricornTree::
# 874 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Sign_ApricornTree_Text_0, MSGBOX_SIGN
	end


TARC3_Find_IceClimb::
# 879 "data/maps/TARC3_base/scripts.pory"
	finditem ITEM_TM01, 1
	end


TARC3_Dummy_Start_Amber::
# 884 "data/maps/TARC3_base/scripts.pory"
	lockall
# 885 "data/maps/TARC3_base/scripts.pory"
	setvar VAR_CASTFORM_PHASE, 1
# 886 "data/maps/TARC3_base/scripts.pory"
	setvar VAR_TRIGGER_XATU_EVENT, 1
# 887 "data/maps/TARC3_base/scripts.pory"
	finditem ITEM_HEAT_ROCK, 1
# 888 "data/maps/TARC3_base/scripts.pory"
	givemon SPECIES_CASTFORM_SUNNY, 25
# 889 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_ITEM_AMBER_SHARD
# 890 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_RUN_XATU_AMBER
# 891 "data/maps/TARC3_base/scripts.pory"
	releaseall
# 892 "data/maps/TARC3_base/scripts.pory"
	warp MAP_TARC3_WEATHER_INSTITUTE_2F, 9, 8
# 893 "data/maps/TARC3_base/scripts.pory"
	waitstate
	end


# 164 "data/maps/TARC3_base/scripts.pory"
TARC3_Amber_Munchlax_Movement_0:
# 165 "data/maps/TARC3_base/scripts.pory"
	walk_up
# 165 "data/maps/TARC3_base/scripts.pory"
	walk_up
# 166 "data/maps/TARC3_base/scripts.pory"
	face_down
	step_end

# 829 "data/maps/TARC3_base/scripts.pory"
TARC3_Lapras1_Source_Movement_0:
# 830 "data/maps/TARC3_base/scripts.pory"
	walk_down
# 830 "data/maps/TARC3_base/scripts.pory"
	walk_down
# 830 "data/maps/TARC3_base/scripts.pory"
	walk_down
# 831 "data/maps/TARC3_base/scripts.pory"
	walk_right
# 831 "data/maps/TARC3_base/scripts.pory"
	walk_right
# 832 "data/maps/TARC3_base/scripts.pory"
	walk_down
# 832 "data/maps/TARC3_base/scripts.pory"
	walk_down
# 832 "data/maps/TARC3_base/scripts.pory"
	walk_down
	step_end

# 849 "data/maps/TARC3_base/scripts.pory"
TARC3_Lapras2_Source_Movement_0:
# 850 "data/maps/TARC3_base/scripts.pory"
	walk_right
# 850 "data/maps/TARC3_base/scripts.pory"
	walk_right
# 850 "data/maps/TARC3_base/scripts.pory"
	walk_right
# 850 "data/maps/TARC3_base/scripts.pory"
	walk_right
# 850 "data/maps/TARC3_base/scripts.pory"
	walk_right
# 851 "data/maps/TARC3_base/scripts.pory"
	walk_up
# 852 "data/maps/TARC3_base/scripts.pory"
	walk_right
# 853 "data/maps/TARC3_base/scripts.pory"
	walk_up
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
# 154 "data/maps/TARC3_base/scripts.pory"
	.string "Munchlax$"

TARC3_Amber_Munchlax_Text_1:
# 163 "data/maps/TARC3_base/scripts.pory"
	.string "It's too hot to battle!$"

TARC3_Amber_Munchlax_Text_2:
# 176 "data/maps/TARC3_base/scripts.pory"
	.string "Do you have some berries for me?\nI am hungry!$"

TARC3_Amber_Combusken_Text_0:
# 199 "data/maps/TARC3_base/scripts.pory"
	.string "Combusken$"

TARC3_Amber_Combusken_Text_1:
# 209 "data/maps/TARC3_base/scripts.pory"
	.string "What are you doing here\nin my territory?\pYou think you can handle me?\nThe sun is on my side, too!$"

TARC3_Amber_Observer_Text_0:
# 231 "data/maps/TARC3_base/scripts.pory"
	.string "Fomantis$"

TARC3_Amber_Observer_Text_1:
# 235 "data/maps/TARC3_base/scripts.pory"
	.string "We're cool again!$"

TARC3_Amber_Observer_Text_2:
# 240 "data/maps/TARC3_base/scripts.pory"
	.string "This HELIOPTILE is so mean!\pCan you help me scaring it away?$"

TARC3_Amber_Observer_Text_3:
# 251 "data/maps/TARC3_base/scripts.pory"
	.string "Thank you for helping me!$"

TARC3_Amber_Torkoal_Text_0:
# 284 "data/maps/TARC3_base/scripts.pory"
	.string "Torkoal$"

TARC3_Amber_Torkoal_Text_1:
# 294 "data/maps/TARC3_base/scripts.pory"
	.string "Who dares to bother me during my nap?\p...\pAre you after that stone?\pYou cannot have it, it's dangerous!\nIt will turn the world into endless rain!$"

TARC3_Amber_Torkoal_Text_2:
# 307 "data/maps/TARC3_base/scripts.pory"
	.string "Defeated. Like it was nothing.\pMaybe you are able to save us\nfrom the chaos!\pHere, I found it behind the lava pool!$"

TARC3_Azure_Toxicroak_Text_0:
# 328 "data/maps/TARC3_base/scripts.pory"
	.string "Toxicroak$"

TARC3_Azure_Toxicroak_Text_1:
# 342 "data/maps/TARC3_base/scripts.pory"
	.string "This heat is miserable!\nIt burns my skin!$"

TARC3_Azure_Toxicroak_Text_2:
# 344 "data/maps/TARC3_base/scripts.pory"
	.string "Heh... Now THIS is my kind of weather!\nCome on, then. Try your best!$"

TARC3_Azure_Toxicroak_Text_3:
# 346 "data/maps/TARC3_base/scripts.pory"
	.string "You are playing with the weather?\pLet's see who is making the rules!$"

TARC3_Azure_Gastrodon_Text_0:
# 369 "data/maps/TARC3_base/scripts.pory"
	.string "Gastrodon$"

TARC3_Azure_Gastrodon_Text_1:
# 383 "data/maps/TARC3_base/scripts.pory"
	.string "Trying to dry me out?\pIt'll take more than sunshine\nto pass me!$"

TARC3_Azure_Gastrodon_Text_2:
# 385 "data/maps/TARC3_base/scripts.pory"
	.string "Oh? You brought me even more water?\pLet's go, I take as much as you give!$"

TARC3_Azure_Gastrodon_Text_3:
# 387 "data/maps/TARC3_base/scripts.pory"
	.string "I don't care much about\nthe weather!\pBut this is my domain and you\nare trespassing!$"

TARC3_Azure_Observer_Text_0:
# 410 "data/maps/TARC3_base/scripts.pory"
	.string "Drampa$"

TARC3_Azure_Observer_Text_1:
# 419 "data/maps/TARC3_base/scripts.pory"
	.string "This SLOWKING is so toxic!\pIt behaves like a king that\nguards its treasure.\pI wonder what's up there.$"

TARC3_Azure_Observer_Text_2:
# 430 "data/maps/TARC3_base/scripts.pory"
	.string "Thanks for having my back!\pI need to go now, find the\nbully's house and burn it\lto the ground.$"

TARC3_Azure_Flygon_Text_0:
# 463 "data/maps/TARC3_base/scripts.pory"
	.string "Flygon$"

TARC3_Azure_Flygon_Text_1:
# 472 "data/maps/TARC3_base/scripts.pory"
	.string "The worst in the world is\nsnow and ice.\pI will keep you from\ncontrolling it!$"

TARC3_Azure_Flygon_Text_2:
# 486 "data/maps/TARC3_base/scripts.pory"
	.string "You are trying to restore the\nbalance of the weather again?\pWell that sounds like an\nhonorable path.\pI guess you can have this then.$"

TARC3_Azure_Flygon_Text_3:
# 493 "data/maps/TARC3_base/scripts.pory"
	.string "...\p...\pThis is the end of this beta.\pThe final release will feature another\nsegment with snowy weather,\lnew puzzles and a final boss fight.$"

TARC3_Azure_Flygon_Text_4:
# 496 "data/maps/TARC3_base/scripts.pory"
	.string "You have found all nine\nSTARDUSTS already!\pGreat job!\nThis is all for now.$"

TARC3_Azure_Flygon_Text_5:
# 499 "data/maps/TARC3_base/scripts.pory"
	.string "There is nine STARDUSTS\nto be found.\lKeep looking!$"

TARC3_Paras_Post_Text_0:
# 519 "data/maps/TARC3_base/scripts.pory"
	.string "I am enjoying the warmth!\pJust keep any Fire Types away!$"

TARC3_Paras_Post_Text_1:
# 522 "data/maps/TARC3_base/scripts.pory"
	.string "What's this weather?\pThis is miserable, I can't stand it!$"

TARC3_Paras_Post_Text_2:
# 525 "data/maps/TARC3_base/scripts.pory"
	.string "Noticed that the icon above my\nhead is gone now?\pIt shows if a Pokémon wants to fight.$"

TARC3_Surskit_Text_0:
# 535 "data/maps/TARC3_base/scripts.pory"
	.string "Surskit$"

TARC3_Surskit_Text_1:
# 540 "data/maps/TARC3_base/scripts.pory"
	.string "My pond!\nWhere did it go???$"

TARC3_Surskit_Text_2:
# 542 "data/maps/TARC3_base/scripts.pory"
	.string "You made this rain?\pI LOVE IT!\nPlease never make it stop.$"

TARC3_Surskit_Text_3:
# 546 "data/maps/TARC3_base/scripts.pory"
	.string "The weather has been crazy lately!\pI hope it calms down soon.$"

TARC3_Vulpix_Post_Text_0:
# 559 "data/maps/TARC3_base/scripts.pory"
	.string "You transformed and even\nchanged your moveset?\pThat is so cool!\nHow did you do that?$"

TARC3_Dewpider_Post_Text_0:
# 572 "data/maps/TARC3_base/scripts.pory"
	.string "What did you do???\pWhere did my home go???$"

TARC3_Dewpider_Post_Text_1:
# 574 "data/maps/TARC3_base/scripts.pory"
	.string "Please be careful!$"

TARC3_Munchlax_Post_Text_0:
# 587 "data/maps/TARC3_base/scripts.pory"
	.string "I heard there is a mysterious\nobject on top of the mountain.\pThey say it can make it rain.\pAnd rain makes berries grow.\nYummy!$"

TARC3_Combusken_Post_Text_0:
# 600 "data/maps/TARC3_base/scripts.pory"
	.string "Now this is unfair!$"

TARC3_Combusken_Post_Text_1:
# 602 "data/maps/TARC3_base/scripts.pory"
	.string "I clearly should have won!$"

TARC3_Torkoal_Post_Text_0:
# 615 "data/maps/TARC3_base/scripts.pory"
	.string "Woah! I didn't know you could\nturn the lava into stone!$"

TARC3_Torkoal_Post_Text_1:
# 617 "data/maps/TARC3_base/scripts.pory"
	.string "Please help us bring back normality!$"

TARC3_Toxicroak_Post_Text_0:
# 630 "data/maps/TARC3_base/scripts.pory"
	.string "You used the water against me?\pThat's embarrassing!$"

TARC3_Gastrodon_Post_Text_0:
# 643 "data/maps/TARC3_base/scripts.pory"
	.string "I've seen a hidden cave\nentrance when I was roaming\lthe riverbed.\pMaybe there is a way for you\nto get there?$"

TARC3_Flygon_Post_Text_0:
# 656 "data/maps/TARC3_base/scripts.pory"
	.string "...\p...\pThis is the end of this beta.\pThe final release will feature\nanother segment with snowy weather,\lnew puzzles and a final boss fight.$"

TARC3_Whimsicott_Text_0:
# 672 "data/maps/TARC3_base/scripts.pory"
	.string "Whimsicott$"

TARC3_Whimsicott_Text_1:
# 676 "data/maps/TARC3_base/scripts.pory"
	.string "When you plant and water it,\nit will grow!\pBut don't expect much from these\nApricorn trees.\lThey haven't changed in ages.$"

TARC3_Whimsicott_Text_2:
# 680 "data/maps/TARC3_base/scripts.pory"
	.string "Hi there, glad you found me!\pMy name is Whimsicott and\nI am the gardener of this town.\pHere, you can have a seed, too.$"

TARC3_Feebas_Text_0:
# 695 "data/maps/TARC3_base/scripts.pory"
	.string "Feebas$"

TARC3_Feebas_Text_1:
# 698 "data/maps/TARC3_base/scripts.pory"
	.string "If you ever get stuck,\nswim on the river and\lswitch to your Base form.\pThis will respawn you in front\nof the institute.$"

TARC3_Chatot1_Text_0:
# 706 "data/maps/TARC3_base/scripts.pory"
	.string "Chatot$"

TARC3_Chatot1_Text_1:
# 709 "data/maps/TARC3_base/scripts.pory"
	.string "Have you met Whimsicott, yet?\pShe is really friendly and\nprovides the town with crops.$"

TARC3_Chatot2_Text_0:
# 720 "data/maps/TARC3_base/scripts.pory"
	.string "Remember, if you get stuck,\nswim on the river and\lswitch to your Base form.\pRIP$"

TARC3_Audino_Text_0:
# 728 "data/maps/TARC3_base/scripts.pory"
	.string "Audino$"

TARC3_Audino_Text_1:
# 735 "data/maps/TARC3_base/scripts.pory"
	.string "Whimsicott taught me how to\nreverse-grow plants.\pBut I am no gardener myself.\nYou can have this.$"

TARC3_Audino_Post_Text_0:
# 743 "data/maps/TARC3_base/scripts.pory"
	.string "If you interact with withered plants\nyou can finish them off with it.$"

TARC3_Minccino_Text_0:
# 751 "data/maps/TARC3_base/scripts.pory"
	.string "Minccino$"

TARC3_Minccino_Text_1:
# 754 "data/maps/TARC3_base/scripts.pory"
	.string "The top of the volcano is hard\nto reach.\pI tried it before, but it was\ntoo steep and slippery.$"

TARC3_Smeargle_Text_0:
# 762 "data/maps/TARC3_base/scripts.pory"
	.string "Smeargle$"

TARC3_Smeargle_Text_1:
# 765 "data/maps/TARC3_base/scripts.pory"
	.string "Did you notice the palette changes\nduring sunny weather?\pThat's me recoloring everything\nin an instant!$"

TARC3_Nosepass_Text_0:
# 773 "data/maps/TARC3_base/scripts.pory"
	.string "Nosepass$"

TARC3_Nosepass_Text_1:
# 776 "data/maps/TARC3_base/scripts.pory"
	.string "I tried this shortcut,\nbut it didn't work out.$"

TARC3_Ducklett_Text_0:
# 784 "data/maps/TARC3_base/scripts.pory"
	.string "Ducklett$"

TARC3_Ducklett_Text_1:
# 787 "data/maps/TARC3_base/scripts.pory"
	.string "Well done!\nI don't get many visitors here.\pThe way you got here will open\nmany more hidden paths for you.$"

TARC3_Sliggoo_Text_0:
# 795 "data/maps/TARC3_base/scripts.pory"
	.string "Sliggoo$"

TARC3_Sliggoo_Text_1:
# 798 "data/maps/TARC3_base/scripts.pory"
	.string "Heya, guess what level I am now!\pIt's already 69, but I just don't\nevolve.\pSo sad...$"

TARC3_Goodra_Text_0:
# 806 "data/maps/TARC3_base/scripts.pory"
	.string "Goodra$"

TARC3_Goodra_Text_1:
# 810 "data/maps/TARC3_base/scripts.pory"
	.string "I tried evolving for so long,\nbut I had no idea how...$"

TARC3_Goodra_Text_2:
# 813 "data/maps/TARC3_base/scripts.pory"
	.string "You made it rain.\nThat was it!\pThank you so much for the help!\pHere, takes this.$"

TARC3_Lapras1_Source_Text_0:
# 825 "data/maps/TARC3_base/scripts.pory"
	.string "Lapras$"

TARC3_Lapras1_Source_Text_1:
# 828 "data/maps/TARC3_base/scripts.pory"
	.string "Hello my friend!\nYou are trying to save us all?\pIf you find me and my friend\nwe might be able to assist\lyou on the mission.$"

TARC3_Lapras2_Source_Text_0:
# 848 "data/maps/TARC3_base/scripts.pory"
	.string "Yay, a new friend!\pLet's meet at the little island\nWEST from here.$"

TARC3_Sign_TreeOfLife_Text_0:
# 869 "data/maps/TARC3_base/scripts.pory"
	.string "Tree of Life\pOnly Arceus may enter.$"

TARC3_Sign_ApricornTree_Text_0:
# 874 "data/maps/TARC3_base/scripts.pory"
	.string "An Apricorn Tree blocks\nthe entrance.\pPost game area.$"
