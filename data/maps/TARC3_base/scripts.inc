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
# 48 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_START
# 50 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Base_Paras_Text_0
# 51 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_PARAS_BEATEN, TARC3_Base_Paras_2
# 57 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Base_Paras_Text_1
# 58 "data/maps/TARC3_base/scripts.pory"
	setwildbattle SPECIES_PARAS, 25
# 59 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_PARAS, CRY_MODE_ENCOUNTER
# 60 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 61 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 62 "data/maps/TARC3_base/scripts.pory"
	dowildbattle
# 63 "data/maps/TARC3_base/scripts.pory"
	callnative WasBattleWon
# 64 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Base_Paras_5
TARC3_Base_Paras_1:
# 70 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Base_Paras_2:
# 53 "data/maps/TARC3_base/scripts.pory"
	goto TARC3_Paras_Post
	goto TARC3_Base_Paras_1

TARC3_Base_Paras_5:
# 66 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_BASE_PARAS_BEATEN
# 67 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_START
	goto TARC3_Base_Paras_1


TARC3_Base_Vulpix::
# 75 "data/maps/TARC3_base/scripts.pory"
	cant_see_if_set FLAG_BASE_VULPIX_BEATEN
# 76 "data/maps/TARC3_base/scripts.pory"
	lock
# 77 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 79 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_VULPIX
# 81 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Base_Vulpix_Text_0
# 82 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_VULPIX_BEATEN, TARC3_Base_Vulpix_2
# 88 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Base_Vulpix_Text_1
# 89 "data/maps/TARC3_base/scripts.pory"
	setwildbattle SPECIES_VULPIX, 25
# 90 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_VULPIX, CRY_MODE_ENCOUNTER
# 91 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 92 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 93 "data/maps/TARC3_base/scripts.pory"
	dowildbattle
# 94 "data/maps/TARC3_base/scripts.pory"
	callnative WasBattleWon
# 95 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Base_Vulpix_5
TARC3_Base_Vulpix_1:
# 101 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Base_Vulpix_2:
# 84 "data/maps/TARC3_base/scripts.pory"
	goto TARC3_Vulpix_Post
	goto TARC3_Base_Vulpix_1

TARC3_Base_Vulpix_5:
# 97 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_BASE_VULPIX_BEATEN
# 98 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_START
	goto TARC3_Base_Vulpix_1


TARC3_Base_Dewpider::
# 106 "data/maps/TARC3_base/scripts.pory"
	cant_see_if_set FLAG_BASE_DEWPIDER_BEATEN
# 107 "data/maps/TARC3_base/scripts.pory"
	lock
# 108 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_DEWPIDER
# 109 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 112 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Base_Dewpider_Text_0
# 113 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_DEWPIDER_BEATEN, TARC3_Base_Dewpider_2
# 119 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Base_Dewpider_Text_1
# 120 "data/maps/TARC3_base/scripts.pory"
	setwildbattle SPECIES_DEWPIDER, 25
# 121 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_DEWPIDER, CRY_MODE_ENCOUNTER
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
	goto_if_eq TARC3_Base_Dewpider_5
TARC3_Base_Dewpider_1:
# 132 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Base_Dewpider_2:
# 115 "data/maps/TARC3_base/scripts.pory"
	goto TARC3_Dewpider_Post
	goto TARC3_Base_Dewpider_1

TARC3_Base_Dewpider_5:
# 128 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_BASE_DEWPIDER_BEATEN
# 129 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_START
	goto TARC3_Base_Dewpider_1


TARC3_Base_Wooper_backup::
# 137 "data/maps/TARC3_base/scripts.pory"
	cant_see_if_set FLAG_BASE_WOOPER_BEATEN
# 138 "data/maps/TARC3_base/scripts.pory"
	lock
# 139 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 142 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Base_Wooper_backup_Text_0
# 143 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_WOOPER_BEATEN, TARC3_Base_Wooper_backup_2
# 149 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Base_Wooper_backup_Text_2
# 150 "data/maps/TARC3_base/scripts.pory"
	setwildbattle SPECIES_WOOPER, 25
# 151 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_WOOPER, CRY_MODE_ENCOUNTER
# 152 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 153 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 154 "data/maps/TARC3_base/scripts.pory"
	dowildbattle
# 155 "data/maps/TARC3_base/scripts.pory"
	callnative WasBattleWon
# 156 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Base_Wooper_backup_5
TARC3_Base_Wooper_backup_1:
# 162 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Base_Wooper_backup_2:
# 145 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Base_Wooper_backup_Text_1
	goto TARC3_Base_Wooper_backup_1

TARC3_Base_Wooper_backup_5:
# 158 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_BASE_WOOPER_BEATEN
# 159 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_START
	goto TARC3_Base_Wooper_backup_1


TARC3_Amber_Munchlax_Left::
	end


TARC3_Amber_Munchlax_Right::
	end


TARC3_Amber_Munchlax::
# 176 "data/maps/TARC3_base/scripts.pory"
	cant_see_if_set FLAG_BASE_MUNCHLAX_BEATEN
# 177 "data/maps/TARC3_base/scripts.pory"
	lock
# 178 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 180 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_MUNCHLAX
# 182 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Amber_Munchlax_Text_0
# 183 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_MUNCHLAX_BEATEN, TARC3_Amber_Munchlax_2
# 189 "data/maps/TARC3_base/scripts.pory"
	compare VAR_TRANSFORM_MON, SPECIES_CASTFORM_SUNNY
	goto_if_eq TARC3_Amber_Munchlax_5
# 202 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Amber_Munchlax_Text_2
# 203 "data/maps/TARC3_base/scripts.pory"
	setwildbattle SPECIES_MUNCHLAX, 25
# 204 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_MUNCHLAX, CRY_MODE_ENCOUNTER
# 205 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 206 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 207 "data/maps/TARC3_base/scripts.pory"
	dowildbattle
# 208 "data/maps/TARC3_base/scripts.pory"
	callnative WasBattleWon
# 209 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Amber_Munchlax_8
TARC3_Amber_Munchlax_1:
# 216 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Amber_Munchlax_2:
# 185 "data/maps/TARC3_base/scripts.pory"
	goto TARC3_Munchlax_Post
	goto TARC3_Amber_Munchlax_1

TARC3_Amber_Munchlax_5:
# 191 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Amber_Munchlax_Text_1
# 192 "data/maps/TARC3_base/scripts.pory"
	applymovement LOCALID_PLAYER, TARC3_Amber_Munchlax_Movement_0
# 196 "data/maps/TARC3_base/scripts.pory"
	waitmovement 0
# 197 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Amber_Munchlax_8:
# 211 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_BASE_MUNCHLAX_BEATEN
# 212 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_START
	goto TARC3_Amber_Munchlax_1


TARC3_Amber_Combusken::
# 221 "data/maps/TARC3_base/scripts.pory"
	cant_see_if_set FLAG_BASE_COMBUSKEN_BEATEN
# 222 "data/maps/TARC3_base/scripts.pory"
	lock
# 223 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 225 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_COMBUSKEN
# 226 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Amber_Combusken_Text_0
# 228 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_COMBUSKEN_BEATEN, TARC3_Amber_Combusken_2
# 234 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Amber_Combusken_Text_1
# 235 "data/maps/TARC3_base/scripts.pory"
	setwildbattle SPECIES_COMBUSKEN, 25
# 236 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_COMBUSKEN, CRY_MODE_ENCOUNTER
# 237 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 238 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 239 "data/maps/TARC3_base/scripts.pory"
	dowildbattle
# 240 "data/maps/TARC3_base/scripts.pory"
	callnative WasBattleWon
# 241 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Amber_Combusken_5
TARC3_Amber_Combusken_1:
# 247 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Amber_Combusken_2:
# 230 "data/maps/TARC3_base/scripts.pory"
	goto TARC3_Combusken_Post
	goto TARC3_Amber_Combusken_1

TARC3_Amber_Combusken_5:
# 243 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_BASE_COMBUSKEN_BEATEN
# 244 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_START
	goto TARC3_Amber_Combusken_1


TARC3_Amber_Observer::
# 252 "data/maps/TARC3_base/scripts.pory"
	cant_see_if_set FLAG_BASE_HELIOPTILE_BEATEN
# 253 "data/maps/TARC3_base/scripts.pory"
	lock
# 254 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 256 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_HELIOPTILE
# 257 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Amber_Observer_Text_0
# 259 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_HELIOPTILE_BEATEN, TARC3_Amber_Observer_2
# 265 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Amber_Observer_Text_2
# 266 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_HELIOPTILE, CRY_MODE_ENCOUNTER
# 267 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 268 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 269 "data/maps/TARC3_base/scripts.pory"
	ai_vs_ai_wild_battle SPECIES_FOMANTIS, SPECIES_HELIOPTILE, 25
# 270 "data/maps/TARC3_base/scripts.pory"
	callnative WasBattleWon
# 271 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Amber_Observer_5
TARC3_Amber_Observer_1:
# 285 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Amber_Observer_2:
# 261 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Amber_Observer_Text_1
	goto TARC3_Amber_Observer_1

TARC3_Amber_Observer_5:
# 273 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_BASE_HELIOPTILE_BEATEN
# 274 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_START
# 275 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Amber_Observer_Text_3
# 276 "data/maps/TARC3_base/scripts.pory"
	fadescreen FADE_TO_BLACK
# 277 "data/maps/TARC3_base/scripts.pory"
	special HealPlayerParty
# 278 "data/maps/TARC3_base/scripts.pory"
	removeobject 34
# 279 "data/maps/TARC3_base/scripts.pory"
	removeobject 35
# 280 "data/maps/TARC3_base/scripts.pory"
	delay 60
# 281 "data/maps/TARC3_base/scripts.pory"
	fadescreen FADE_FROM_BLACK
	goto TARC3_Amber_Observer_1


TARC3_Amber_Torkoal::
# 290 "data/maps/TARC3_base/scripts.pory"
	cant_see_if_set FLAG_BASE_TORKOAL_BEATEN
# 291 "data/maps/TARC3_base/scripts.pory"
	lock
# 292 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 294 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_TORKOAL
# 295 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Amber_Torkoal_Text_0
# 297 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_TORKOAL_BEATEN, TARC3_Amber_Torkoal_2
# 303 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Amber_Torkoal_Text_1
# 304 "data/maps/TARC3_base/scripts.pory"
	setwildbattle SPECIES_TORKOAL, 25
# 305 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_TORKOAL, CRY_MODE_ENCOUNTER
# 306 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 307 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 308 "data/maps/TARC3_base/scripts.pory"
	dowildbattle
# 309 "data/maps/TARC3_base/scripts.pory"
	callnative WasBattleWon
# 310 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Amber_Torkoal_5
TARC3_Amber_Torkoal_1:
# 328 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Amber_Torkoal_2:
# 299 "data/maps/TARC3_base/scripts.pory"
	goto TARC3_Torkoal_Post
	goto TARC3_Amber_Torkoal_1

TARC3_Amber_Torkoal_5:
# 312 "data/maps/TARC3_base/scripts.pory"
	lock
# 313 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 314 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_BASE_TORKOAL_BEATEN
# 315 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_START
# 316 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Amber_Torkoal_Text_2
# 317 "data/maps/TARC3_base/scripts.pory"
	setvar VAR_CASTFORM_PHASE, 2
# 318 "data/maps/TARC3_base/scripts.pory"
	setvar VAR_TRIGGER_XATU_EVENT, 1
# 319 "data/maps/TARC3_base/scripts.pory"
	finditem ITEM_DAMP_ROCK, 1
# 320 "data/maps/TARC3_base/scripts.pory"
	givemon SPECIES_CASTFORM_RAINY, 25
# 321 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_ITEM_AZURE_SHARD
# 322 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_RUN_XATU_AZURE
# 323 "data/maps/TARC3_base/scripts.pory"
	releaseall
# 324 "data/maps/TARC3_base/scripts.pory"
	warp MAP_TARC3_WEATHER_INSTITUTE_2F, 9, 8
# 325 "data/maps/TARC3_base/scripts.pory"
	waitstate
	goto TARC3_Amber_Torkoal_1


TARC3_Azure_Toxicroak::
# 333 "data/maps/TARC3_base/scripts.pory"
	cant_see_if_set FLAG_BASE_TOXICROAK_BEATEN
# 334 "data/maps/TARC3_base/scripts.pory"
	lock
# 335 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 337 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Azure_Toxicroak_Text_0
# 338 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_TOXICROAK
# 340 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_TOXICROAK_BEATEN, TARC3_Azure_Toxicroak_2
# 346 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Azure_Toxicroak_Text_2
# 347 "data/maps/TARC3_base/scripts.pory"
	setwildbattle SPECIES_TOXICROAK, 25
# 348 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_TOXICROAK, CRY_MODE_ENCOUNTER
# 349 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 350 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 351 "data/maps/TARC3_base/scripts.pory"
	dowildbattle
# 352 "data/maps/TARC3_base/scripts.pory"
	callnative WasBattleWon
# 353 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Azure_Toxicroak_5
TARC3_Azure_Toxicroak_1:
# 359 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Azure_Toxicroak_2:
# 342 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Azure_Toxicroak_Text_1
	goto TARC3_Azure_Toxicroak_1

TARC3_Azure_Toxicroak_5:
# 355 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_BASE_TOXICROAK_BEATEN
# 356 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_START
	goto TARC3_Azure_Toxicroak_1


TARC3_Azure_Gastrodon::
# 364 "data/maps/TARC3_base/scripts.pory"
	cant_see_if_set FLAG_BASE_GASTRODON_BEATEN
# 365 "data/maps/TARC3_base/scripts.pory"
	lock
# 366 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 368 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Azure_Gastrodon_Text_0
# 369 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_GASTRODON
# 371 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_GASTRODON_BEATEN, TARC3_Azure_Gastrodon_2
# 377 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Azure_Gastrodon_Text_1
# 378 "data/maps/TARC3_base/scripts.pory"
	setwildbattle SPECIES_GASTRODON, 25
# 379 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_GASTRODON, CRY_MODE_ENCOUNTER
# 380 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 381 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 382 "data/maps/TARC3_base/scripts.pory"
	dowildbattle
# 383 "data/maps/TARC3_base/scripts.pory"
	callnative WasBattleWon
# 384 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Azure_Gastrodon_5
TARC3_Azure_Gastrodon_1:
# 390 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Azure_Gastrodon_2:
# 373 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Azure_Toxicroak_Text_1
	goto TARC3_Azure_Gastrodon_1

TARC3_Azure_Gastrodon_5:
# 386 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_BASE_GASTRODON_BEATEN
# 387 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_START
	goto TARC3_Azure_Gastrodon_1


TARC3_Azure_Observer::
# 395 "data/maps/TARC3_base/scripts.pory"
	cant_see_if_set FLAG_BASE_SLOWKING_BEATEN
# 396 "data/maps/TARC3_base/scripts.pory"
	lock
# 397 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 399 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Azure_Observer_Text_0
# 400 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_SLOWKING
# 402 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_SLOWKING_BEATEN, TARC3_Azure_Observer_2
# 408 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Azure_Observer_Text_1
# 409 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_SLOWKING, CRY_MODE_ENCOUNTER
# 410 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 411 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 412 "data/maps/TARC3_base/scripts.pory"
	ai_vs_ai_wild_battle SPECIES_DRAMPA, SPECIES_SLOWKING, 25
# 413 "data/maps/TARC3_base/scripts.pory"
	callnative WasBattleWon
# 414 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Azure_Observer_5
TARC3_Azure_Observer_1:
# 420 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Azure_Observer_2:
# 404 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Amber_Observer_Text_1
	goto TARC3_Azure_Observer_1

TARC3_Azure_Observer_5:
# 416 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_BASE_SLOWKING_BEATEN
# 417 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_START
	goto TARC3_Azure_Observer_1


TARC3_Azure_Flygon::
# 425 "data/maps/TARC3_base/scripts.pory"
	cant_see_if_set FLAG_BASE_FLYGON_BEATEN
# 426 "data/maps/TARC3_base/scripts.pory"
	lock
# 427 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 429 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Azure_Flygon_Text_0
# 430 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_FLYGON
# 432 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_FLYGON_BEATEN, TARC3_Azure_Flygon_2
# 438 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Azure_Flygon_Text_1
# 439 "data/maps/TARC3_base/scripts.pory"
	setwildbattle SPECIES_FLYGON, 25
# 440 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_FLYGON, CRY_MODE_ENCOUNTER
# 441 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 442 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 443 "data/maps/TARC3_base/scripts.pory"
	dowildbattle
# 444 "data/maps/TARC3_base/scripts.pory"
	callnative WasBattleWon
# 445 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Azure_Flygon_5
TARC3_Azure_Flygon_1:
# 451 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Azure_Flygon_2:
# 434 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Azure_Toxicroak_Text_1
	goto TARC3_Azure_Flygon_1

TARC3_Azure_Flygon_5:
# 447 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_BASE_FLYGON_BEATEN
# 448 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_START
	goto TARC3_Azure_Flygon_1


TARC3_Paras_Post::
# 458 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_SURSKIT, CRY_MODE_NORMAL
# 460 "data/maps/TARC3_base/scripts.pory"
	callnative GetCurrentTransformationSpecies
# 461 "data/maps/TARC3_base/scripts.pory"
	switch VAR_RESULT
# 463 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_SUNNY, TARC3_Paras_Post_3
# 465 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_RAINY, TARC3_Paras_Post_4
# 466 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_SNOWY, TARC3_Paras_Post_4
# 468 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM, TARC3_Paras_Post_5
TARC3_Paras_Post_5:
# 470 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Paras_Post_Text_2
TARC3_Paras_Post_1:
# 472 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Paras_Post_3:
# 464 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Paras_Post_Text_0
	goto TARC3_Paras_Post_1

TARC3_Paras_Post_4:
# 467 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Paras_Post_Text_1
	goto TARC3_Paras_Post_1


TARC3_Surskit::
# 477 "data/maps/TARC3_base/scripts.pory"
	lock
# 478 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 479 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_SURSKIT, CRY_MODE_NORMAL
# 480 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Surskit_Text_0
# 481 "data/maps/TARC3_base/scripts.pory"
	callnative GetCurrentTransformationSpecies
# 482 "data/maps/TARC3_base/scripts.pory"
	switch VAR_RESULT
# 484 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_SUNNY, TARC3_Surskit_3
# 486 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_RAINY, TARC3_Surskit_4
# 488 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_SNOWY, TARC3_Surskit_5
# 489 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM, TARC3_Surskit_5
TARC3_Surskit_5:
# 491 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Surskit_Text_3
TARC3_Surskit_1:
# 493 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Surskit_3:
# 485 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Surskit_Text_1
	goto TARC3_Surskit_1

TARC3_Surskit_4:
# 487 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Surskit_Text_2
	goto TARC3_Surskit_1


TARC3_Vulpix_Post::
# 498 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_VULPIX, CRY_MODE_NORMAL
# 500 "data/maps/TARC3_base/scripts.pory"
	callnative GetCurrentTransformationSpecies
# 501 "data/maps/TARC3_base/scripts.pory"
	switch VAR_RESULT
# 504 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Vulpix_Post_Text_0
# 506 "data/maps/TARC3_base/scripts.pory"
	release
	end


TARC3_Dewpider_Post::
# 511 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_DEWPIDER, CRY_MODE_NORMAL
# 513 "data/maps/TARC3_base/scripts.pory"
	callnative GetCurrentTransformationSpecies
# 514 "data/maps/TARC3_base/scripts.pory"
	switch VAR_RESULT
# 516 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_SUNNY, TARC3_Dewpider_Post_3
# 519 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Dewpider_Post_Text_1
TARC3_Dewpider_Post_1:
# 521 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Dewpider_Post_3:
# 517 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Dewpider_Post_Text_0
	goto TARC3_Dewpider_Post_1


TARC3_Munchlax_Post::
# 526 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_MUNCHLAX, CRY_MODE_NORMAL
# 528 "data/maps/TARC3_base/scripts.pory"
	callnative GetCurrentTransformationSpecies
# 529 "data/maps/TARC3_base/scripts.pory"
	switch VAR_RESULT
# 532 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Munchlax_Post_Text_0
# 534 "data/maps/TARC3_base/scripts.pory"
	release
	end


TARC3_Combusken_Post::
# 539 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_COMBUSKEN, CRY_MODE_NORMAL
# 541 "data/maps/TARC3_base/scripts.pory"
	callnative GetCurrentTransformationSpecies
# 542 "data/maps/TARC3_base/scripts.pory"
	switch VAR_RESULT
# 544 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_RAINY, TARC3_Combusken_Post_3
# 547 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Combusken_Post_Text_1
TARC3_Combusken_Post_1:
# 549 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Combusken_Post_3:
# 545 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Combusken_Post_Text_0
	goto TARC3_Combusken_Post_1


TARC3_Torkoal_Post::
# 554 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_TORKOAL, CRY_MODE_NORMAL
# 556 "data/maps/TARC3_base/scripts.pory"
	callnative GetCurrentTransformationSpecies
# 557 "data/maps/TARC3_base/scripts.pory"
	switch VAR_RESULT
# 559 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_RAINY, TARC3_Torkoal_Post_3
# 562 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Torkoal_Post_Text_1
TARC3_Torkoal_Post_1:
# 564 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Torkoal_Post_3:
# 560 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Torkoal_Post_Text_0
	goto TARC3_Torkoal_Post_1


TARC3_Whimsicott::
# 569 "data/maps/TARC3_base/scripts.pory"
	lock
# 570 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 571 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Whimsicott_Text_0
# 573 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_WHIMSICOTT_GAVE_SEED, TARC3_Whimsicott_2
# 579 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Whimsicott_Text_2
# 580 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_WHIMSICOTT, CRY_MODE_NORMAL
# 581 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 582 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 583 "data/maps/TARC3_base/scripts.pory"
	giveitem ITEM_WEPEAR_BERRY, 1
# 584 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_WHIMSICOTT_GAVE_SEED
# 585 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Whimsicott_Text_1
TARC3_Whimsicott_1:
# 587 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Whimsicott_2:
# 575 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Whimsicott_Text_1
	goto TARC3_Whimsicott_1


TARC3_Feebas::
# 592 "data/maps/TARC3_base/scripts.pory"
	lock
# 593 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 594 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Feebas_Text_0
# 596 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_FEEBAS, CRY_MODE_NORMAL
# 597 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Feebas_Text_1
# 598 "data/maps/TARC3_base/scripts.pory"
	release
	end


TARC3_Chatot1::
# 603 "data/maps/TARC3_base/scripts.pory"
	lock
# 604 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 605 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Chatot1_Text_0
# 607 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_CHATOT, CRY_MODE_NORMAL
# 608 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Chatot1_Text_1
# 609 "data/maps/TARC3_base/scripts.pory"
	release
	end


TARC3_Chatot2::
# 614 "data/maps/TARC3_base/scripts.pory"
	lock
# 615 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 616 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Chatot1_Text_0
# 618 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_CHATOT, CRY_MODE_NORMAL
# 619 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Chatot2_Text_0
# 620 "data/maps/TARC3_base/scripts.pory"
	release
	end


TARC3_Audino::
# 625 "data/maps/TARC3_base/scripts.pory"
	lock
# 626 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 627 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Audino_Text_0
# 629 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_AUDINO, CRY_MODE_NORMAL
# 630 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_AUDINO_GAVE_HERBICIDE, TARC3_Audino_1
# 634 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Audino_Text_1
# 635 "data/maps/TARC3_base/scripts.pory"
	giveitem ITEM_HYPER_POTION
# 636 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_AUDINO_GAVE_HERBICIDE
# 637 "data/maps/TARC3_base/scripts.pory"
	goto TARC3_Audino_Post
	return

TARC3_Audino_1:
# 631 "data/maps/TARC3_base/scripts.pory"
	goto TARC3_Audino_Post
	return


TARC3_Audino_Post::
# 642 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Audino_Post_Text_0
# 643 "data/maps/TARC3_base/scripts.pory"
	release
	end


TARC3_Minccino::
# 648 "data/maps/TARC3_base/scripts.pory"
	lock
# 649 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 650 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Minccino_Text_0
# 652 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_MINCCINO, CRY_MODE_NORMAL
# 653 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Minccino_Text_1
# 654 "data/maps/TARC3_base/scripts.pory"
	release
	end


TARC3_Smeargle::
# 659 "data/maps/TARC3_base/scripts.pory"
	lock
# 660 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 661 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Smeargle_Text_0
# 663 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_SMEARGLE, CRY_MODE_NORMAL
# 664 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Smeargle_Text_1
# 665 "data/maps/TARC3_base/scripts.pory"
	release
	end


TARC3_Nosepass::
# 670 "data/maps/TARC3_base/scripts.pory"
	lock
# 671 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 672 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Nosepass_Text_0
# 674 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_NOSEPASS, CRY_MODE_NORMAL
# 675 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Nosepass_Text_1
# 676 "data/maps/TARC3_base/scripts.pory"
	release
	end


TARC3_Sliggoo::
# 681 "data/maps/TARC3_base/scripts.pory"
	lock
# 682 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 683 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Sliggoo_Text_0
# 685 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_SLIGGOO, CRY_MODE_NORMAL
# 686 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Sliggoo_Text_1
# 687 "data/maps/TARC3_base/scripts.pory"
	release
	end


TARC3_Goodra::
# 692 "data/maps/TARC3_base/scripts.pory"
	lock
# 693 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 694 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Goodra_Text_0
# 696 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_GOODRA, CRY_MODE_NORMAL
# 697 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_GOODRA_GAVE_ITEM, TARC3_Goodra_2
# 701 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Goodra_Text_2
# 702 "data/maps/TARC3_base/scripts.pory"
	giveitem ITEM_MIRACLE_SEED
# 703 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_GOODRA_GAVE_ITEM
# 704 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Goodra_Text_1
TARC3_Goodra_1:
# 706 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Goodra_2:
# 698 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Goodra_Text_1
	goto TARC3_Goodra_1


TARC3_Lapras1_Source::
# 711 "data/maps/TARC3_base/scripts.pory"
	lock
# 712 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 713 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Lapras1_Source_Text_0
# 715 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_LAPRAS, CRY_MODE_NORMAL
# 716 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Lapras1_Source_Text_1
# 717 "data/maps/TARC3_base/scripts.pory"
	applymovement VAR_LAST_TALKED, TARC3_Lapras1_Source_Movement_0
# 722 "data/maps/TARC3_base/scripts.pory"
	waitmovement 0
# 723 "data/maps/TARC3_base/scripts.pory"
	removeobject VAR_LAST_TALKED
# 724 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_LAPRAS1_SOURCE_INVISIBLE
# 725 "data/maps/TARC3_base/scripts.pory"
	clearflag FLAG_LAPRAS1_DEST_INVISIBLE
# 726 "data/maps/TARC3_base/scripts.pory"
	release
	end


TARC3_Lapras2_Source::
# 731 "data/maps/TARC3_base/scripts.pory"
	lock
# 732 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 733 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Lapras1_Source_Text_0
# 735 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_LAPRAS, CRY_MODE_NORMAL
# 736 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Lapras2_Source_Text_0
# 737 "data/maps/TARC3_base/scripts.pory"
	applymovement VAR_LAST_TALKED, TARC3_Lapras2_Source_Movement_0
# 748 "data/maps/TARC3_base/scripts.pory"
	waitmovement 0
# 749 "data/maps/TARC3_base/scripts.pory"
	removeobject VAR_LAST_TALKED
# 750 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_LAPRAS2_SOURCE_INVISIBLE
# 751 "data/maps/TARC3_base/scripts.pory"
	clearflag FLAG_LAPRAS2_DEST_INVISIBLE
# 752 "data/maps/TARC3_base/scripts.pory"
	release
	end


TARC3_Sign_TreeOfLife::
# 757 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Sign_TreeOfLife_Text_0, MSGBOX_SIGN
	end


TARC3_Sign_ApricornTree::
# 762 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Sign_ApricornTree_Text_0, MSGBOX_SIGN
	end


TARC3_Find_IceClimb::
# 767 "data/maps/TARC3_base/scripts.pory"
	finditem ITEM_TM01, 1
	end


TARC3_Dummy_Start_Amber::
# 772 "data/maps/TARC3_base/scripts.pory"
	lockall
# 773 "data/maps/TARC3_base/scripts.pory"
	setvar VAR_CASTFORM_PHASE, 1
# 774 "data/maps/TARC3_base/scripts.pory"
	setvar VAR_TRIGGER_XATU_EVENT, 1
# 775 "data/maps/TARC3_base/scripts.pory"
	finditem ITEM_HEAT_ROCK, 1
# 776 "data/maps/TARC3_base/scripts.pory"
	givemon SPECIES_CASTFORM_SUNNY, 25
# 777 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_ITEM_AMBER_SHARD
# 778 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_RUN_XATU_AMBER
# 779 "data/maps/TARC3_base/scripts.pory"
	releaseall
# 780 "data/maps/TARC3_base/scripts.pory"
	warp MAP_TARC3_WEATHER_INSTITUTE_2F, 9, 8
# 781 "data/maps/TARC3_base/scripts.pory"
	waitstate
	end


# 192 "data/maps/TARC3_base/scripts.pory"
TARC3_Amber_Munchlax_Movement_0:
# 193 "data/maps/TARC3_base/scripts.pory"
	walk_up
# 193 "data/maps/TARC3_base/scripts.pory"
	walk_up
# 194 "data/maps/TARC3_base/scripts.pory"
	face_down
	step_end

# 717 "data/maps/TARC3_base/scripts.pory"
TARC3_Lapras1_Source_Movement_0:
# 718 "data/maps/TARC3_base/scripts.pory"
	walk_down
# 718 "data/maps/TARC3_base/scripts.pory"
	walk_down
# 718 "data/maps/TARC3_base/scripts.pory"
	walk_down
# 719 "data/maps/TARC3_base/scripts.pory"
	walk_right
# 719 "data/maps/TARC3_base/scripts.pory"
	walk_right
# 720 "data/maps/TARC3_base/scripts.pory"
	walk_down
# 720 "data/maps/TARC3_base/scripts.pory"
	walk_down
# 720 "data/maps/TARC3_base/scripts.pory"
	walk_down
	step_end

# 737 "data/maps/TARC3_base/scripts.pory"
TARC3_Lapras2_Source_Movement_0:
# 738 "data/maps/TARC3_base/scripts.pory"
	walk_right
# 738 "data/maps/TARC3_base/scripts.pory"
	walk_right
# 738 "data/maps/TARC3_base/scripts.pory"
	walk_right
# 738 "data/maps/TARC3_base/scripts.pory"
	walk_right
# 738 "data/maps/TARC3_base/scripts.pory"
	walk_right
# 739 "data/maps/TARC3_base/scripts.pory"
	walk_up
# 740 "data/maps/TARC3_base/scripts.pory"
	walk_right
# 741 "data/maps/TARC3_base/scripts.pory"
	walk_up
# 742 "data/maps/TARC3_base/scripts.pory"
	walk_right
# 743 "data/maps/TARC3_base/scripts.pory"
	walk_up
# 744 "data/maps/TARC3_base/scripts.pory"
	walk_right
# 745 "data/maps/TARC3_base/scripts.pory"
	walk_up
# 746 "data/maps/TARC3_base/scripts.pory"
	walk_right
	step_end

TARC3_Base_Paras_Text_0:
# 50 "data/maps/TARC3_base/scripts.pory"
	.string "Paras$"

TARC3_Base_Paras_Text_1:
# 57 "data/maps/TARC3_base/scripts.pory"
	.string "Weather Shards?\nI only heard of fungal spores.\pDoes that help?$"

TARC3_Base_Vulpix_Text_0:
# 81 "data/maps/TARC3_base/scripts.pory"
	.string "Vulpix$"

TARC3_Base_Vulpix_Text_1:
# 88 "data/maps/TARC3_base/scripts.pory"
	.string "I don't care about the weather.\pFor me the sun is always shining!$"

TARC3_Base_Dewpider_Text_0:
# 112 "data/maps/TARC3_base/scripts.pory"
	.string "Dewpider$"

TARC3_Base_Dewpider_Text_1:
# 119 "data/maps/TARC3_base/scripts.pory"
	.string "There is a strange rock at the\nTree of Life.\pIt feels dangerous to the life\nat the pond\pYou must not touch it!$"

TARC3_Base_Wooper_backup_Text_0:
# 142 "data/maps/TARC3_base/scripts.pory"
	.string "Wooper$"

TARC3_Base_Wooper_backup_Text_1:
# 145 "data/maps/TARC3_base/scripts.pory"
	.string "Hey, my berry!$"

TARC3_Base_Wooper_backup_Text_2:
# 149 "data/maps/TARC3_base/scripts.pory"
	.string "Hi, I'm WOOPER.\nLet's battle!$"

TARC3_Amber_Munchlax_Text_0:
# 182 "data/maps/TARC3_base/scripts.pory"
	.string "Munchlax$"

TARC3_Amber_Munchlax_Text_1:
# 191 "data/maps/TARC3_base/scripts.pory"
	.string "It's too hot to battle!$"

TARC3_Amber_Munchlax_Text_2:
# 202 "data/maps/TARC3_base/scripts.pory"
	.string "Do you have some berries for me?\nI am hungry!$"

TARC3_Amber_Combusken_Text_0:
# 226 "data/maps/TARC3_base/scripts.pory"
	.string "Combusken$"

TARC3_Amber_Combusken_Text_1:
# 234 "data/maps/TARC3_base/scripts.pory"
	.string "What are you doing here\nin my territory?\pYou think you can handle me?\nThe sun is on my side, too!$"

TARC3_Amber_Observer_Text_0:
# 257 "data/maps/TARC3_base/scripts.pory"
	.string "Fomantis$"

TARC3_Amber_Observer_Text_1:
# 261 "data/maps/TARC3_base/scripts.pory"
	.string "We're cool again!$"

TARC3_Amber_Observer_Text_2:
# 265 "data/maps/TARC3_base/scripts.pory"
	.string "This HELIOPTILE is so mean!\pCan you help me scaring it away?$"

TARC3_Amber_Observer_Text_3:
# 275 "data/maps/TARC3_base/scripts.pory"
	.string "Thank you for helping me!$"

TARC3_Amber_Torkoal_Text_0:
# 295 "data/maps/TARC3_base/scripts.pory"
	.string "Torkoal$"

TARC3_Amber_Torkoal_Text_1:
# 303 "data/maps/TARC3_base/scripts.pory"
	.string "Who dares to bother me during my nap?\p...\pAre you after that stone?\pYou cannot have it, it's dangerous!\nIt will turn the world into endless rain!$"

TARC3_Amber_Torkoal_Text_2:
# 316 "data/maps/TARC3_base/scripts.pory"
	.string "Defeated. Like it was nothing.\pMaybe you are able to save us\nfrom the chaos!\pHere, I found it behind the lava pool!$"

TARC3_Azure_Toxicroak_Text_0:
# 337 "data/maps/TARC3_base/scripts.pory"
	.string "Toxicroak$"

TARC3_Azure_Toxicroak_Text_1:
# 342 "data/maps/TARC3_base/scripts.pory"
	.string "I still like you!$"

TARC3_Azure_Toxicroak_Text_2:
# 346 "data/maps/TARC3_base/scripts.pory"
	.string "Hi, I'm TOXICROAK.\nLet's battle!$"

TARC3_Azure_Gastrodon_Text_0:
# 368 "data/maps/TARC3_base/scripts.pory"
	.string "Gastrodon$"

TARC3_Azure_Gastrodon_Text_1:
# 377 "data/maps/TARC3_base/scripts.pory"
	.string "Hi, I'm GASTRODON.\nLet's battle!$"

TARC3_Azure_Observer_Text_0:
# 399 "data/maps/TARC3_base/scripts.pory"
	.string "Drampa$"

TARC3_Azure_Observer_Text_1:
# 408 "data/maps/TARC3_base/scripts.pory"
	.string "Hi, I'm DRAMPA.\nPlease help me!$"

TARC3_Azure_Flygon_Text_0:
# 429 "data/maps/TARC3_base/scripts.pory"
	.string "Flygon$"

TARC3_Azure_Flygon_Text_1:
# 438 "data/maps/TARC3_base/scripts.pory"
	.string "Hi, I'm FLYGON.\nLet's battle!$"

TARC3_Paras_Post_Text_0:
# 464 "data/maps/TARC3_base/scripts.pory"
	.string "I am enjoying the warmth!\pJust keep any Fire Types away!$"

TARC3_Paras_Post_Text_1:
# 467 "data/maps/TARC3_base/scripts.pory"
	.string "What's this weather?\pThis is miserable, I can't stand it!$"

TARC3_Paras_Post_Text_2:
# 470 "data/maps/TARC3_base/scripts.pory"
	.string "You can make it sunny?\pI am rooting for you!$"

TARC3_Surskit_Text_0:
# 480 "data/maps/TARC3_base/scripts.pory"
	.string "Surskit$"

TARC3_Surskit_Text_1:
# 485 "data/maps/TARC3_base/scripts.pory"
	.string "My pond!\nWhere did it go???$"

TARC3_Surskit_Text_2:
# 487 "data/maps/TARC3_base/scripts.pory"
	.string "You made this rain?\pI LOVE IT!\nPlease never make it stop.$"

TARC3_Surskit_Text_3:
# 491 "data/maps/TARC3_base/scripts.pory"
	.string "The weather has been crazy lately!\pI hope it calms down soon.$"

TARC3_Vulpix_Post_Text_0:
# 504 "data/maps/TARC3_base/scripts.pory"
	.string "You transformed and even\nchanged your moveset?\pThat is so cool!\nHow did you do that?$"

TARC3_Dewpider_Post_Text_0:
# 517 "data/maps/TARC3_base/scripts.pory"
	.string "What did you do???\pWhere did my home go???$"

TARC3_Dewpider_Post_Text_1:
# 519 "data/maps/TARC3_base/scripts.pory"
	.string "Please be careful!$"

TARC3_Munchlax_Post_Text_0:
# 532 "data/maps/TARC3_base/scripts.pory"
	.string "I heard there is a mysterious\nobject on top of the mountain.\pThey say it can make it rain.\pAnd rain makes berries grow.\nYummy!$"

TARC3_Combusken_Post_Text_0:
# 545 "data/maps/TARC3_base/scripts.pory"
	.string "Now this is unfair!$"

TARC3_Combusken_Post_Text_1:
# 547 "data/maps/TARC3_base/scripts.pory"
	.string "I clearly should have won!$"

TARC3_Torkoal_Post_Text_0:
# 560 "data/maps/TARC3_base/scripts.pory"
	.string "Woah! I didn't know you could\nturn the lava into stone!$"

TARC3_Torkoal_Post_Text_1:
# 562 "data/maps/TARC3_base/scripts.pory"
	.string "Please help us bring back normality!$"

TARC3_Whimsicott_Text_0:
# 571 "data/maps/TARC3_base/scripts.pory"
	.string "Whimsicott$"

TARC3_Whimsicott_Text_1:
# 575 "data/maps/TARC3_base/scripts.pory"
	.string "When you plant and water it,\nit will grow!\pBut don't expect much from these\nApricorn trees.\lThey haven't changed in ages.$"

TARC3_Whimsicott_Text_2:
# 579 "data/maps/TARC3_base/scripts.pory"
	.string "Hi there, glad you found me!\pMy name is Whimsicott and\nI am the gardener of this town.\pHere, you can have a seed, too.$"

TARC3_Feebas_Text_0:
# 594 "data/maps/TARC3_base/scripts.pory"
	.string "Feebas$"

TARC3_Feebas_Text_1:
# 597 "data/maps/TARC3_base/scripts.pory"
	.string "If you ever get stuck,\nswim on the river and\lswitch to your Base form.\pThis will respawn you in front\nof the institute.$"

TARC3_Chatot1_Text_0:
# 605 "data/maps/TARC3_base/scripts.pory"
	.string "Chatot$"

TARC3_Chatot1_Text_1:
# 608 "data/maps/TARC3_base/scripts.pory"
	.string "Have you met Whimsicott, yet?\pShe is really friendly and\nprovides the town with crops.$"

TARC3_Chatot2_Text_0:
# 619 "data/maps/TARC3_base/scripts.pory"
	.string "Remember, if you get stuck,\nswim on the river and\lswitch to your Base form.\pRIP$"

TARC3_Audino_Text_0:
# 627 "data/maps/TARC3_base/scripts.pory"
	.string "Audino$"

TARC3_Audino_Text_1:
# 634 "data/maps/TARC3_base/scripts.pory"
	.string "Whimsicott taught me how to\nreverse-grow plants.\pBut I am no gardener myself.\nYou can have this.$"

TARC3_Audino_Post_Text_0:
# 642 "data/maps/TARC3_base/scripts.pory"
	.string "You can use this on grown vines.$"

TARC3_Minccino_Text_0:
# 650 "data/maps/TARC3_base/scripts.pory"
	.string "Minccino$"

TARC3_Minccino_Text_1:
# 653 "data/maps/TARC3_base/scripts.pory"
	.string "The top of the volcano is hard\nto reach.\pI tried it before, but it was\ntoo steep and slippery.$"

TARC3_Smeargle_Text_0:
# 661 "data/maps/TARC3_base/scripts.pory"
	.string "Smeargle$"

TARC3_Smeargle_Text_1:
# 664 "data/maps/TARC3_base/scripts.pory"
	.string "Did you notice the palette changes\nduring sunny weather?\pThat's me recoloring everything\nin an instant!$"

TARC3_Nosepass_Text_0:
# 672 "data/maps/TARC3_base/scripts.pory"
	.string "Nosepass$"

TARC3_Nosepass_Text_1:
# 675 "data/maps/TARC3_base/scripts.pory"
	.string "I tried this shortcut,\nbut it didn't work out.$"

TARC3_Sliggoo_Text_0:
# 683 "data/maps/TARC3_base/scripts.pory"
	.string "Sliggoo$"

TARC3_Sliggoo_Text_1:
# 686 "data/maps/TARC3_base/scripts.pory"
	.string "Heya, guess what level I am now!\pIt's already 69, but I just don't\nevolve.\pSo sad...$"

TARC3_Goodra_Text_0:
# 694 "data/maps/TARC3_base/scripts.pory"
	.string "Goodra$"

TARC3_Goodra_Text_1:
# 698 "data/maps/TARC3_base/scripts.pory"
	.string "I tried evolving for so long,\nbut I had no idea how...$"

TARC3_Goodra_Text_2:
# 701 "data/maps/TARC3_base/scripts.pory"
	.string "You made it rain.\nThat was it!\pThank you so much for the help!\pHere, takes this.$"

TARC3_Lapras1_Source_Text_0:
# 713 "data/maps/TARC3_base/scripts.pory"
	.string "Lapras$"

TARC3_Lapras1_Source_Text_1:
# 716 "data/maps/TARC3_base/scripts.pory"
	.string "Hello my friend!\nYou are trying to save us all?\pIf you find me and my friend\nwe might be able to assist\lyou on the mission.$"

TARC3_Lapras2_Source_Text_0:
# 736 "data/maps/TARC3_base/scripts.pory"
	.string "Yay, a new friend!\pLet's meet at the little island\nWEST from here.$"

TARC3_Sign_TreeOfLife_Text_0:
# 757 "data/maps/TARC3_base/scripts.pory"
	.string "Tree of Life\pOnly Arceus may enter.$"

TARC3_Sign_ApricornTree_Text_0:
# 762 "data/maps/TARC3_base/scripts.pory"
	.string "An Apricorn Tree blocks\nthe entrance.\pPost game area.$"
