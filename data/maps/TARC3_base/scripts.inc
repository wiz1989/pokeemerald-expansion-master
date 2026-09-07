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
# 300 "data/maps/TARC3_base/scripts.pory"
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
# 279 "data/maps/TARC3_base/scripts.pory"
	callnative GetCurrentTransformationSpecies
# 280 "data/maps/TARC3_base/scripts.pory"
	switch VAR_RESULT
# 282 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM, TARC3_Amber_Observer_9
# 285 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_RAINY, TARC3_Amber_Observer_10
# 288 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_SUNNY, TARC3_Amber_Observer_11
# 291 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_SNOWY, TARC3_Amber_Observer_12
TARC3_Amber_Observer_7:
# 295 "data/maps/TARC3_base/scripts.pory"
	delay 60
# 296 "data/maps/TARC3_base/scripts.pory"
	fadescreen FADE_FROM_BLACK
	goto TARC3_Amber_Observer_1

TARC3_Amber_Observer_9:
# 283 "data/maps/TARC3_base/scripts.pory"
	removeobject LOCALID_BASE_FOMANTIS
# 284 "data/maps/TARC3_base/scripts.pory"
	removeobject LOCALID_BASE_HELIOPTILE
	goto TARC3_Amber_Observer_7

TARC3_Amber_Observer_10:
# 286 "data/maps/TARC3_base/scripts.pory"
	removeobject LOCALID_RAINY_FOMANTIS
# 287 "data/maps/TARC3_base/scripts.pory"
	removeobject LOCALID_RAINY_HELIOPTILE
	goto TARC3_Amber_Observer_7

TARC3_Amber_Observer_11:
# 289 "data/maps/TARC3_base/scripts.pory"
	removeobject LOCALID_SUNNY_FOMANTIS
# 290 "data/maps/TARC3_base/scripts.pory"
	removeobject LOCALID_SUNNY_HELIOPTILE
	goto TARC3_Amber_Observer_7

TARC3_Amber_Observer_12:
# 292 "data/maps/TARC3_base/scripts.pory"
	removeobject LOCALID_SNOWY_FOMANTIS
# 293 "data/maps/TARC3_base/scripts.pory"
	removeobject LOCALID_SNOWY_HELIOPTILE
	goto TARC3_Amber_Observer_7


TARC3_Amber_Torkoal::
# 305 "data/maps/TARC3_base/scripts.pory"
	cant_see_if_set FLAG_BASE_TORKOAL_BEATEN
# 306 "data/maps/TARC3_base/scripts.pory"
	lock
# 307 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 309 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_TORKOAL
# 310 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Amber_Torkoal_Text_0
# 312 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_TORKOAL_BEATEN, TARC3_Amber_Torkoal_2
# 318 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Amber_Torkoal_Text_1
# 319 "data/maps/TARC3_base/scripts.pory"
	setwildbattle SPECIES_TORKOAL, 25
# 320 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_TORKOAL, CRY_MODE_ENCOUNTER
# 321 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 322 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 323 "data/maps/TARC3_base/scripts.pory"
	dowildbattle
# 324 "data/maps/TARC3_base/scripts.pory"
	callnative WasBattleWon
# 325 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Amber_Torkoal_5
TARC3_Amber_Torkoal_1:
# 343 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Amber_Torkoal_2:
# 314 "data/maps/TARC3_base/scripts.pory"
	goto TARC3_Torkoal_Post
	goto TARC3_Amber_Torkoal_1

TARC3_Amber_Torkoal_5:
# 327 "data/maps/TARC3_base/scripts.pory"
	lock
# 328 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 329 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_BASE_TORKOAL_BEATEN
# 330 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_START
# 331 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Amber_Torkoal_Text_2
# 332 "data/maps/TARC3_base/scripts.pory"
	setvar VAR_CASTFORM_PHASE, 2
# 333 "data/maps/TARC3_base/scripts.pory"
	setvar VAR_TRIGGER_XATU_EVENT, 1
# 334 "data/maps/TARC3_base/scripts.pory"
	finditem ITEM_DAMP_ROCK, 1
# 335 "data/maps/TARC3_base/scripts.pory"
	givemon SPECIES_CASTFORM_RAINY, 25
# 336 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_ITEM_AZURE_SHARD
# 337 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_RUN_XATU_AZURE
# 338 "data/maps/TARC3_base/scripts.pory"
	releaseall
# 339 "data/maps/TARC3_base/scripts.pory"
	warp MAP_TARC3_WEATHER_INSTITUTE_2F, 9, 8
# 340 "data/maps/TARC3_base/scripts.pory"
	waitstate
	goto TARC3_Amber_Torkoal_1


TARC3_Azure_Toxicroak::
# 348 "data/maps/TARC3_base/scripts.pory"
	cant_see_if_set FLAG_BASE_TOXICROAK_BEATEN
# 349 "data/maps/TARC3_base/scripts.pory"
	lock
# 350 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 352 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Azure_Toxicroak_Text_0
# 353 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_TOXICROAK
# 355 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_TOXICROAK_BEATEN, TARC3_Azure_Toxicroak_2
# 361 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Azure_Toxicroak_Text_2
# 362 "data/maps/TARC3_base/scripts.pory"
	setwildbattle SPECIES_TOXICROAK, 25
# 363 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_TOXICROAK, CRY_MODE_ENCOUNTER
# 364 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 365 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 366 "data/maps/TARC3_base/scripts.pory"
	dowildbattle
# 367 "data/maps/TARC3_base/scripts.pory"
	callnative WasBattleWon
# 368 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Azure_Toxicroak_5
TARC3_Azure_Toxicroak_1:
# 374 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Azure_Toxicroak_2:
# 357 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Azure_Toxicroak_Text_1
	goto TARC3_Azure_Toxicroak_1

TARC3_Azure_Toxicroak_5:
# 370 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_BASE_TOXICROAK_BEATEN
# 371 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_START
	goto TARC3_Azure_Toxicroak_1


TARC3_Azure_Gastrodon::
# 379 "data/maps/TARC3_base/scripts.pory"
	cant_see_if_set FLAG_BASE_GASTRODON_BEATEN
# 380 "data/maps/TARC3_base/scripts.pory"
	lock
# 381 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 383 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Azure_Gastrodon_Text_0
# 384 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_GASTRODON
# 386 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_GASTRODON_BEATEN, TARC3_Azure_Gastrodon_2
# 392 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Azure_Gastrodon_Text_1
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
	goto_if_eq TARC3_Azure_Gastrodon_5
TARC3_Azure_Gastrodon_1:
# 405 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Azure_Gastrodon_2:
# 388 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Azure_Toxicroak_Text_1
	goto TARC3_Azure_Gastrodon_1

TARC3_Azure_Gastrodon_5:
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
# 415 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_SLOWKING
# 417 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_SLOWKING_BEATEN, TARC3_Azure_Observer_2
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
# 435 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Azure_Observer_2:
# 419 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Amber_Observer_Text_1
	goto TARC3_Azure_Observer_1

TARC3_Azure_Observer_5:
# 431 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_BASE_SLOWKING_BEATEN
# 432 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_START
	goto TARC3_Azure_Observer_1


TARC3_Azure_Flygon::
# 440 "data/maps/TARC3_base/scripts.pory"
	cant_see_if_set FLAG_BASE_FLYGON_BEATEN
# 441 "data/maps/TARC3_base/scripts.pory"
	lock
# 442 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 444 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Azure_Flygon_Text_0
# 445 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_FLYGON
# 447 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_FLYGON_BEATEN, TARC3_Azure_Flygon_2
# 453 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Azure_Flygon_Text_1
# 454 "data/maps/TARC3_base/scripts.pory"
	setwildbattle SPECIES_FLYGON, 25
# 455 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_FLYGON, CRY_MODE_ENCOUNTER
# 456 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 457 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 458 "data/maps/TARC3_base/scripts.pory"
	dowildbattle
# 459 "data/maps/TARC3_base/scripts.pory"
	callnative WasBattleWon
# 460 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Azure_Flygon_5
TARC3_Azure_Flygon_1:
# 466 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Azure_Flygon_2:
# 449 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Azure_Toxicroak_Text_1
	goto TARC3_Azure_Flygon_1

TARC3_Azure_Flygon_5:
# 462 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_BASE_FLYGON_BEATEN
# 463 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_START
	goto TARC3_Azure_Flygon_1


TARC3_Paras_Post::
# 473 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_SURSKIT, CRY_MODE_NORMAL
# 475 "data/maps/TARC3_base/scripts.pory"
	callnative GetCurrentTransformationSpecies
# 476 "data/maps/TARC3_base/scripts.pory"
	switch VAR_RESULT
# 478 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_SUNNY, TARC3_Paras_Post_3
# 480 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_RAINY, TARC3_Paras_Post_4
# 481 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_SNOWY, TARC3_Paras_Post_4
# 483 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM, TARC3_Paras_Post_5
TARC3_Paras_Post_5:
# 485 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Paras_Post_Text_2
TARC3_Paras_Post_1:
# 487 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Paras_Post_3:
# 479 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Paras_Post_Text_0
	goto TARC3_Paras_Post_1

TARC3_Paras_Post_4:
# 482 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Paras_Post_Text_1
	goto TARC3_Paras_Post_1


TARC3_Surskit::
# 492 "data/maps/TARC3_base/scripts.pory"
	lock
# 493 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 494 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_SURSKIT, CRY_MODE_NORMAL
# 495 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Surskit_Text_0
# 496 "data/maps/TARC3_base/scripts.pory"
	callnative GetCurrentTransformationSpecies
# 497 "data/maps/TARC3_base/scripts.pory"
	switch VAR_RESULT
# 499 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_SUNNY, TARC3_Surskit_3
# 501 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_RAINY, TARC3_Surskit_4
# 503 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_SNOWY, TARC3_Surskit_5
# 504 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM, TARC3_Surskit_5
TARC3_Surskit_5:
# 506 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Surskit_Text_3
TARC3_Surskit_1:
# 508 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Surskit_3:
# 500 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Surskit_Text_1
	goto TARC3_Surskit_1

TARC3_Surskit_4:
# 502 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Surskit_Text_2
	goto TARC3_Surskit_1


TARC3_Vulpix_Post::
# 513 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_VULPIX, CRY_MODE_NORMAL
# 515 "data/maps/TARC3_base/scripts.pory"
	callnative GetCurrentTransformationSpecies
# 516 "data/maps/TARC3_base/scripts.pory"
	switch VAR_RESULT
# 519 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Vulpix_Post_Text_0
# 521 "data/maps/TARC3_base/scripts.pory"
	release
	end


TARC3_Dewpider_Post::
# 526 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_DEWPIDER, CRY_MODE_NORMAL
# 528 "data/maps/TARC3_base/scripts.pory"
	callnative GetCurrentTransformationSpecies
# 529 "data/maps/TARC3_base/scripts.pory"
	switch VAR_RESULT
# 531 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_SUNNY, TARC3_Dewpider_Post_3
# 534 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Dewpider_Post_Text_1
TARC3_Dewpider_Post_1:
# 536 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Dewpider_Post_3:
# 532 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Dewpider_Post_Text_0
	goto TARC3_Dewpider_Post_1


TARC3_Munchlax_Post::
# 541 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_MUNCHLAX, CRY_MODE_NORMAL
# 543 "data/maps/TARC3_base/scripts.pory"
	callnative GetCurrentTransformationSpecies
# 544 "data/maps/TARC3_base/scripts.pory"
	switch VAR_RESULT
# 547 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Munchlax_Post_Text_0
# 549 "data/maps/TARC3_base/scripts.pory"
	release
	end


TARC3_Combusken_Post::
# 554 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_COMBUSKEN, CRY_MODE_NORMAL
# 556 "data/maps/TARC3_base/scripts.pory"
	callnative GetCurrentTransformationSpecies
# 557 "data/maps/TARC3_base/scripts.pory"
	switch VAR_RESULT
# 559 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_RAINY, TARC3_Combusken_Post_3
# 562 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Combusken_Post_Text_1
TARC3_Combusken_Post_1:
# 564 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Combusken_Post_3:
# 560 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Combusken_Post_Text_0
	goto TARC3_Combusken_Post_1


TARC3_Torkoal_Post::
# 569 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_TORKOAL, CRY_MODE_NORMAL
# 571 "data/maps/TARC3_base/scripts.pory"
	callnative GetCurrentTransformationSpecies
# 572 "data/maps/TARC3_base/scripts.pory"
	switch VAR_RESULT
# 574 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_RAINY, TARC3_Torkoal_Post_3
# 577 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Torkoal_Post_Text_1
TARC3_Torkoal_Post_1:
# 579 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Torkoal_Post_3:
# 575 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Torkoal_Post_Text_0
	goto TARC3_Torkoal_Post_1


TARC3_Whimsicott::
# 584 "data/maps/TARC3_base/scripts.pory"
	lock
# 585 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 586 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Whimsicott_Text_0
# 588 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_WHIMSICOTT_GAVE_SEED, TARC3_Whimsicott_2
# 594 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Whimsicott_Text_2
# 595 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_WHIMSICOTT, CRY_MODE_NORMAL
# 596 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 597 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 598 "data/maps/TARC3_base/scripts.pory"
	giveitem ITEM_WEPEAR_BERRY, 1
# 599 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_WHIMSICOTT_GAVE_SEED
# 600 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Whimsicott_Text_1
TARC3_Whimsicott_1:
# 602 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Whimsicott_2:
# 590 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Whimsicott_Text_1
	goto TARC3_Whimsicott_1


TARC3_Feebas::
# 607 "data/maps/TARC3_base/scripts.pory"
	lock
# 608 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 609 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Feebas_Text_0
# 611 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_FEEBAS, CRY_MODE_NORMAL
# 612 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Feebas_Text_1
# 613 "data/maps/TARC3_base/scripts.pory"
	release
	end


TARC3_Chatot1::
# 618 "data/maps/TARC3_base/scripts.pory"
	lock
# 619 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 620 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Chatot1_Text_0
# 622 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_CHATOT, CRY_MODE_NORMAL
# 623 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Chatot1_Text_1
# 624 "data/maps/TARC3_base/scripts.pory"
	release
	end


TARC3_Chatot2::
# 629 "data/maps/TARC3_base/scripts.pory"
	lock
# 630 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 631 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Chatot1_Text_0
# 633 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_CHATOT, CRY_MODE_NORMAL
# 634 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Chatot2_Text_0
# 635 "data/maps/TARC3_base/scripts.pory"
	release
	end


TARC3_Audino::
# 640 "data/maps/TARC3_base/scripts.pory"
	lock
# 641 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 642 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Audino_Text_0
# 644 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_AUDINO, CRY_MODE_NORMAL
# 645 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_AUDINO_GAVE_HERBICIDE, TARC3_Audino_1
# 649 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Audino_Text_1
# 650 "data/maps/TARC3_base/scripts.pory"
	giveitem ITEM_HYPER_POTION
# 651 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_AUDINO_GAVE_HERBICIDE
# 652 "data/maps/TARC3_base/scripts.pory"
	goto TARC3_Audino_Post
	return

TARC3_Audino_1:
# 646 "data/maps/TARC3_base/scripts.pory"
	goto TARC3_Audino_Post
	return


TARC3_Audino_Post::
# 657 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Audino_Post_Text_0
# 658 "data/maps/TARC3_base/scripts.pory"
	release
	end


TARC3_Minccino::
# 663 "data/maps/TARC3_base/scripts.pory"
	lock
# 664 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 665 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Minccino_Text_0
# 667 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_MINCCINO, CRY_MODE_NORMAL
# 668 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Minccino_Text_1
# 669 "data/maps/TARC3_base/scripts.pory"
	release
	end


TARC3_Smeargle::
# 674 "data/maps/TARC3_base/scripts.pory"
	lock
# 675 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 676 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Smeargle_Text_0
# 678 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_SMEARGLE, CRY_MODE_NORMAL
# 679 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Smeargle_Text_1
# 680 "data/maps/TARC3_base/scripts.pory"
	release
	end


TARC3_Nosepass::
# 685 "data/maps/TARC3_base/scripts.pory"
	lock
# 686 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 687 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Nosepass_Text_0
# 689 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_NOSEPASS, CRY_MODE_NORMAL
# 690 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Nosepass_Text_1
# 691 "data/maps/TARC3_base/scripts.pory"
	release
	end


TARC3_Sliggoo::
# 696 "data/maps/TARC3_base/scripts.pory"
	lock
# 697 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 698 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Sliggoo_Text_0
# 700 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_SLIGGOO, CRY_MODE_NORMAL
# 701 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Sliggoo_Text_1
# 702 "data/maps/TARC3_base/scripts.pory"
	release
	end


TARC3_Goodra::
# 707 "data/maps/TARC3_base/scripts.pory"
	lock
# 708 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 709 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Goodra_Text_0
# 711 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_GOODRA, CRY_MODE_NORMAL
# 712 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_GOODRA_GAVE_ITEM, TARC3_Goodra_2
# 716 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Goodra_Text_2
# 717 "data/maps/TARC3_base/scripts.pory"
	giveitem ITEM_MIRACLE_SEED
# 718 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_GOODRA_GAVE_ITEM
# 719 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Goodra_Text_1
TARC3_Goodra_1:
# 721 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Goodra_2:
# 713 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Goodra_Text_1
	goto TARC3_Goodra_1


TARC3_Lapras1_Source::
# 726 "data/maps/TARC3_base/scripts.pory"
	lock
# 727 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 728 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Lapras1_Source_Text_0
# 730 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_LAPRAS, CRY_MODE_NORMAL
# 731 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Lapras1_Source_Text_1
# 732 "data/maps/TARC3_base/scripts.pory"
	applymovement VAR_LAST_TALKED, TARC3_Lapras1_Source_Movement_0
# 737 "data/maps/TARC3_base/scripts.pory"
	waitmovement 0
# 738 "data/maps/TARC3_base/scripts.pory"
	removeobject VAR_LAST_TALKED
# 739 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_LAPRAS1_SOURCE_INVISIBLE
# 740 "data/maps/TARC3_base/scripts.pory"
	clearflag FLAG_LAPRAS1_DEST_INVISIBLE
# 741 "data/maps/TARC3_base/scripts.pory"
	release
	end


TARC3_Lapras2_Source::
# 746 "data/maps/TARC3_base/scripts.pory"
	lock
# 747 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 748 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Lapras1_Source_Text_0
# 750 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_LAPRAS, CRY_MODE_NORMAL
# 751 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Lapras2_Source_Text_0
# 752 "data/maps/TARC3_base/scripts.pory"
	applymovement VAR_LAST_TALKED, TARC3_Lapras2_Source_Movement_0
# 763 "data/maps/TARC3_base/scripts.pory"
	waitmovement 0
# 764 "data/maps/TARC3_base/scripts.pory"
	removeobject VAR_LAST_TALKED
# 765 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_LAPRAS2_SOURCE_INVISIBLE
# 766 "data/maps/TARC3_base/scripts.pory"
	clearflag FLAG_LAPRAS2_DEST_INVISIBLE
# 767 "data/maps/TARC3_base/scripts.pory"
	release
	end


TARC3_Sign_TreeOfLife::
# 772 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Sign_TreeOfLife_Text_0, MSGBOX_SIGN
	end


TARC3_Sign_ApricornTree::
# 777 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Sign_ApricornTree_Text_0, MSGBOX_SIGN
	end


TARC3_Find_IceClimb::
# 782 "data/maps/TARC3_base/scripts.pory"
	finditem ITEM_TM01, 1
	end


TARC3_Dummy_Start_Amber::
# 787 "data/maps/TARC3_base/scripts.pory"
	lockall
# 788 "data/maps/TARC3_base/scripts.pory"
	setvar VAR_CASTFORM_PHASE, 1
# 789 "data/maps/TARC3_base/scripts.pory"
	setvar VAR_TRIGGER_XATU_EVENT, 1
# 790 "data/maps/TARC3_base/scripts.pory"
	finditem ITEM_HEAT_ROCK, 1
# 791 "data/maps/TARC3_base/scripts.pory"
	givemon SPECIES_CASTFORM_SUNNY, 25
# 792 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_ITEM_AMBER_SHARD
# 793 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_RUN_XATU_AMBER
# 794 "data/maps/TARC3_base/scripts.pory"
	releaseall
# 795 "data/maps/TARC3_base/scripts.pory"
	warp MAP_TARC3_WEATHER_INSTITUTE_2F, 9, 8
# 796 "data/maps/TARC3_base/scripts.pory"
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

# 732 "data/maps/TARC3_base/scripts.pory"
TARC3_Lapras1_Source_Movement_0:
# 733 "data/maps/TARC3_base/scripts.pory"
	walk_down
# 733 "data/maps/TARC3_base/scripts.pory"
	walk_down
# 733 "data/maps/TARC3_base/scripts.pory"
	walk_down
# 734 "data/maps/TARC3_base/scripts.pory"
	walk_right
# 734 "data/maps/TARC3_base/scripts.pory"
	walk_right
# 735 "data/maps/TARC3_base/scripts.pory"
	walk_down
# 735 "data/maps/TARC3_base/scripts.pory"
	walk_down
# 735 "data/maps/TARC3_base/scripts.pory"
	walk_down
	step_end

# 752 "data/maps/TARC3_base/scripts.pory"
TARC3_Lapras2_Source_Movement_0:
# 753 "data/maps/TARC3_base/scripts.pory"
	walk_right
# 753 "data/maps/TARC3_base/scripts.pory"
	walk_right
# 753 "data/maps/TARC3_base/scripts.pory"
	walk_right
# 753 "data/maps/TARC3_base/scripts.pory"
	walk_right
# 753 "data/maps/TARC3_base/scripts.pory"
	walk_right
# 754 "data/maps/TARC3_base/scripts.pory"
	walk_up
# 755 "data/maps/TARC3_base/scripts.pory"
	walk_right
# 756 "data/maps/TARC3_base/scripts.pory"
	walk_up
# 757 "data/maps/TARC3_base/scripts.pory"
	walk_right
# 758 "data/maps/TARC3_base/scripts.pory"
	walk_up
# 759 "data/maps/TARC3_base/scripts.pory"
	walk_right
# 760 "data/maps/TARC3_base/scripts.pory"
	walk_up
# 761 "data/maps/TARC3_base/scripts.pory"
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
# 310 "data/maps/TARC3_base/scripts.pory"
	.string "Torkoal$"

TARC3_Amber_Torkoal_Text_1:
# 318 "data/maps/TARC3_base/scripts.pory"
	.string "Who dares to bother me during my nap?\p...\pAre you after that stone?\pYou cannot have it, it's dangerous!\nIt will turn the world into endless rain!$"

TARC3_Amber_Torkoal_Text_2:
# 331 "data/maps/TARC3_base/scripts.pory"
	.string "Defeated. Like it was nothing.\pMaybe you are able to save us\nfrom the chaos!\pHere, I found it behind the lava pool!$"

TARC3_Azure_Toxicroak_Text_0:
# 352 "data/maps/TARC3_base/scripts.pory"
	.string "Toxicroak$"

TARC3_Azure_Toxicroak_Text_1:
# 357 "data/maps/TARC3_base/scripts.pory"
	.string "I still like you!$"

TARC3_Azure_Toxicroak_Text_2:
# 361 "data/maps/TARC3_base/scripts.pory"
	.string "Hi, I'm TOXICROAK.\nLet's battle!$"

TARC3_Azure_Gastrodon_Text_0:
# 383 "data/maps/TARC3_base/scripts.pory"
	.string "Gastrodon$"

TARC3_Azure_Gastrodon_Text_1:
# 392 "data/maps/TARC3_base/scripts.pory"
	.string "Hi, I'm GASTRODON.\nLet's battle!$"

TARC3_Azure_Observer_Text_0:
# 414 "data/maps/TARC3_base/scripts.pory"
	.string "Drampa$"

TARC3_Azure_Observer_Text_1:
# 423 "data/maps/TARC3_base/scripts.pory"
	.string "Hi, I'm DRAMPA.\nPlease help me!$"

TARC3_Azure_Flygon_Text_0:
# 444 "data/maps/TARC3_base/scripts.pory"
	.string "Flygon$"

TARC3_Azure_Flygon_Text_1:
# 453 "data/maps/TARC3_base/scripts.pory"
	.string "Hi, I'm FLYGON.\nLet's battle!$"

TARC3_Paras_Post_Text_0:
# 479 "data/maps/TARC3_base/scripts.pory"
	.string "I am enjoying the warmth!\pJust keep any Fire Types away!$"

TARC3_Paras_Post_Text_1:
# 482 "data/maps/TARC3_base/scripts.pory"
	.string "What's this weather?\pThis is miserable, I can't stand it!$"

TARC3_Paras_Post_Text_2:
# 485 "data/maps/TARC3_base/scripts.pory"
	.string "You can make it sunny?\pI am rooting for you!$"

TARC3_Surskit_Text_0:
# 495 "data/maps/TARC3_base/scripts.pory"
	.string "Surskit$"

TARC3_Surskit_Text_1:
# 500 "data/maps/TARC3_base/scripts.pory"
	.string "My pond!\nWhere did it go???$"

TARC3_Surskit_Text_2:
# 502 "data/maps/TARC3_base/scripts.pory"
	.string "You made this rain?\pI LOVE IT!\nPlease never make it stop.$"

TARC3_Surskit_Text_3:
# 506 "data/maps/TARC3_base/scripts.pory"
	.string "The weather has been crazy lately!\pI hope it calms down soon.$"

TARC3_Vulpix_Post_Text_0:
# 519 "data/maps/TARC3_base/scripts.pory"
	.string "You transformed and even\nchanged your moveset?\pThat is so cool!\nHow did you do that?$"

TARC3_Dewpider_Post_Text_0:
# 532 "data/maps/TARC3_base/scripts.pory"
	.string "What did you do???\pWhere did my home go???$"

TARC3_Dewpider_Post_Text_1:
# 534 "data/maps/TARC3_base/scripts.pory"
	.string "Please be careful!$"

TARC3_Munchlax_Post_Text_0:
# 547 "data/maps/TARC3_base/scripts.pory"
	.string "I heard there is a mysterious\nobject on top of the mountain.\pThey say it can make it rain.\pAnd rain makes berries grow.\nYummy!$"

TARC3_Combusken_Post_Text_0:
# 560 "data/maps/TARC3_base/scripts.pory"
	.string "Now this is unfair!$"

TARC3_Combusken_Post_Text_1:
# 562 "data/maps/TARC3_base/scripts.pory"
	.string "I clearly should have won!$"

TARC3_Torkoal_Post_Text_0:
# 575 "data/maps/TARC3_base/scripts.pory"
	.string "Woah! I didn't know you could\nturn the lava into stone!$"

TARC3_Torkoal_Post_Text_1:
# 577 "data/maps/TARC3_base/scripts.pory"
	.string "Please help us bring back normality!$"

TARC3_Whimsicott_Text_0:
# 586 "data/maps/TARC3_base/scripts.pory"
	.string "Whimsicott$"

TARC3_Whimsicott_Text_1:
# 590 "data/maps/TARC3_base/scripts.pory"
	.string "When you plant and water it,\nit will grow!\pBut don't expect much from these\nApricorn trees.\lThey haven't changed in ages.$"

TARC3_Whimsicott_Text_2:
# 594 "data/maps/TARC3_base/scripts.pory"
	.string "Hi there, glad you found me!\pMy name is Whimsicott and\nI am the gardener of this town.\pHere, you can have a seed, too.$"

TARC3_Feebas_Text_0:
# 609 "data/maps/TARC3_base/scripts.pory"
	.string "Feebas$"

TARC3_Feebas_Text_1:
# 612 "data/maps/TARC3_base/scripts.pory"
	.string "If you ever get stuck,\nswim on the river and\lswitch to your Base form.\pThis will respawn you in front\nof the institute.$"

TARC3_Chatot1_Text_0:
# 620 "data/maps/TARC3_base/scripts.pory"
	.string "Chatot$"

TARC3_Chatot1_Text_1:
# 623 "data/maps/TARC3_base/scripts.pory"
	.string "Have you met Whimsicott, yet?\pShe is really friendly and\nprovides the town with crops.$"

TARC3_Chatot2_Text_0:
# 634 "data/maps/TARC3_base/scripts.pory"
	.string "Remember, if you get stuck,\nswim on the river and\lswitch to your Base form.\pRIP$"

TARC3_Audino_Text_0:
# 642 "data/maps/TARC3_base/scripts.pory"
	.string "Audino$"

TARC3_Audino_Text_1:
# 649 "data/maps/TARC3_base/scripts.pory"
	.string "Whimsicott taught me how to\nreverse-grow plants.\pBut I am no gardener myself.\nYou can have this.$"

TARC3_Audino_Post_Text_0:
# 657 "data/maps/TARC3_base/scripts.pory"
	.string "You can use this on grown vines.$"

TARC3_Minccino_Text_0:
# 665 "data/maps/TARC3_base/scripts.pory"
	.string "Minccino$"

TARC3_Minccino_Text_1:
# 668 "data/maps/TARC3_base/scripts.pory"
	.string "The top of the volcano is hard\nto reach.\pI tried it before, but it was\ntoo steep and slippery.$"

TARC3_Smeargle_Text_0:
# 676 "data/maps/TARC3_base/scripts.pory"
	.string "Smeargle$"

TARC3_Smeargle_Text_1:
# 679 "data/maps/TARC3_base/scripts.pory"
	.string "Did you notice the palette changes\nduring sunny weather?\pThat's me recoloring everything\nin an instant!$"

TARC3_Nosepass_Text_0:
# 687 "data/maps/TARC3_base/scripts.pory"
	.string "Nosepass$"

TARC3_Nosepass_Text_1:
# 690 "data/maps/TARC3_base/scripts.pory"
	.string "I tried this shortcut,\nbut it didn't work out.$"

TARC3_Sliggoo_Text_0:
# 698 "data/maps/TARC3_base/scripts.pory"
	.string "Sliggoo$"

TARC3_Sliggoo_Text_1:
# 701 "data/maps/TARC3_base/scripts.pory"
	.string "Heya, guess what level I am now!\pIt's already 69, but I just don't\nevolve.\pSo sad...$"

TARC3_Goodra_Text_0:
# 709 "data/maps/TARC3_base/scripts.pory"
	.string "Goodra$"

TARC3_Goodra_Text_1:
# 713 "data/maps/TARC3_base/scripts.pory"
	.string "I tried evolving for so long,\nbut I had no idea how...$"

TARC3_Goodra_Text_2:
# 716 "data/maps/TARC3_base/scripts.pory"
	.string "You made it rain.\nThat was it!\pThank you so much for the help!\pHere, takes this.$"

TARC3_Lapras1_Source_Text_0:
# 728 "data/maps/TARC3_base/scripts.pory"
	.string "Lapras$"

TARC3_Lapras1_Source_Text_1:
# 731 "data/maps/TARC3_base/scripts.pory"
	.string "Hello my friend!\nYou are trying to save us all?\pIf you find me and my friend\nwe might be able to assist\lyou on the mission.$"

TARC3_Lapras2_Source_Text_0:
# 751 "data/maps/TARC3_base/scripts.pory"
	.string "Yay, a new friend!\pLet's meet at the little island\nWEST from here.$"

TARC3_Sign_TreeOfLife_Text_0:
# 772 "data/maps/TARC3_base/scripts.pory"
	.string "Tree of Life\pOnly Arceus may enter.$"

TARC3_Sign_ApricornTree_Text_0:
# 777 "data/maps/TARC3_base/scripts.pory"
	.string "An Apricorn Tree blocks\nthe entrance.\pPost game area.$"
