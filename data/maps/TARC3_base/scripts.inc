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
# 52 "data/maps/TARC3_base/scripts.pory"
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
# 80 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Base_Vulpix_Text_0
# 81 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_VULPIX_BEATEN, TARC3_Base_Vulpix_2
# 87 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_VULPIX
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
# 83 "data/maps/TARC3_base/scripts.pory"
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
	faceplayer
# 111 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Base_Dewpider_Text_0
# 112 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_DEWPIDER_BEATEN, TARC3_Base_Dewpider_2
# 118 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_DEWPIDER
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
# 114 "data/maps/TARC3_base/scripts.pory"
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
# 181 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Amber_Munchlax_Text_0
# 182 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_MUNCHLAX_BEATEN, TARC3_Amber_Munchlax_2
# 188 "data/maps/TARC3_base/scripts.pory"
	compare VAR_TRANSFORM_MON, SPECIES_CASTFORM_SUNNY
	goto_if_eq TARC3_Amber_Munchlax_5
# 201 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_MUNCHLAX
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
# 184 "data/maps/TARC3_base/scripts.pory"
	goto TARC3_Munchlax_Post
	goto TARC3_Amber_Munchlax_1

TARC3_Amber_Munchlax_5:
# 190 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Amber_Munchlax_Text_1
# 191 "data/maps/TARC3_base/scripts.pory"
	applymovement LOCALID_PLAYER, TARC3_Amber_Munchlax_Movement_0
# 195 "data/maps/TARC3_base/scripts.pory"
	waitmovement 0
# 196 "data/maps/TARC3_base/scripts.pory"
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
	setspeaker TARC3_Amber_Combusken_Text_0
# 227 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_COMBUSKEN_BEATEN, TARC3_Amber_Combusken_2
# 233 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_COMBUSKEN
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
# 229 "data/maps/TARC3_base/scripts.pory"
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
	setspeaker TARC3_Amber_Observer_Text_0
# 258 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_HELIOPTILE_BEATEN, TARC3_Amber_Observer_2
# 264 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_HELIOPTILE
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
# 299 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Amber_Observer_2:
# 260 "data/maps/TARC3_base/scripts.pory"
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
# 304 "data/maps/TARC3_base/scripts.pory"
	cant_see_if_set FLAG_BASE_TORKOAL_BEATEN
# 305 "data/maps/TARC3_base/scripts.pory"
	lock
# 306 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 308 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Amber_Torkoal_Text_0
# 310 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_TORKOAL_BEATEN, TARC3_Amber_Torkoal_2
# 316 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_TORKOAL
# 317 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Amber_Torkoal_Text_1
# 318 "data/maps/TARC3_base/scripts.pory"
	setwildbattle SPECIES_TORKOAL, 25
# 319 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_TORKOAL, CRY_MODE_ENCOUNTER
# 320 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 321 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 322 "data/maps/TARC3_base/scripts.pory"
	dowildbattle
# 323 "data/maps/TARC3_base/scripts.pory"
	callnative WasBattleWon
# 324 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Amber_Torkoal_5
TARC3_Amber_Torkoal_1:
# 342 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Amber_Torkoal_2:
# 312 "data/maps/TARC3_base/scripts.pory"
	goto TARC3_Torkoal_Post
	goto TARC3_Amber_Torkoal_1

TARC3_Amber_Torkoal_5:
# 326 "data/maps/TARC3_base/scripts.pory"
	lock
# 327 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 328 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_BASE_TORKOAL_BEATEN
# 329 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_START
# 330 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Amber_Torkoal_Text_2
# 331 "data/maps/TARC3_base/scripts.pory"
	setvar VAR_CASTFORM_PHASE, 2
# 332 "data/maps/TARC3_base/scripts.pory"
	setvar VAR_TRIGGER_XATU_EVENT, 1
# 333 "data/maps/TARC3_base/scripts.pory"
	finditem ITEM_DAMP_ROCK, 1
# 334 "data/maps/TARC3_base/scripts.pory"
	givemon SPECIES_CASTFORM_RAINY, 25
# 335 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_ITEM_AZURE_SHARD
# 336 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_RUN_XATU_AZURE
# 337 "data/maps/TARC3_base/scripts.pory"
	releaseall
# 338 "data/maps/TARC3_base/scripts.pory"
	warp MAP_TARC3_WEATHER_INSTITUTE_2F, 9, 8
# 339 "data/maps/TARC3_base/scripts.pory"
	waitstate
	goto TARC3_Amber_Torkoal_1


TARC3_Azure_Toxicroak::
# 347 "data/maps/TARC3_base/scripts.pory"
	cant_see_if_set FLAG_BASE_TOXICROAK_BEATEN
# 348 "data/maps/TARC3_base/scripts.pory"
	lock
# 349 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 351 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Azure_Toxicroak_Text_0
# 353 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_TOXICROAK_BEATEN, TARC3_Azure_Toxicroak_2
# 359 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_TOXICROAK
# 360 "data/maps/TARC3_base/scripts.pory"
	callnative GetCurrentTransformationSpecies
# 361 "data/maps/TARC3_base/scripts.pory"
	switch VAR_RESULT
# 363 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_SUNNY, TARC3_Azure_Toxicroak_7
# 365 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_RAINY, TARC3_Azure_Toxicroak_8
# 368 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Azure_Toxicroak_Text_3
TARC3_Azure_Toxicroak_5:
# 370 "data/maps/TARC3_base/scripts.pory"
	setwildbattle SPECIES_TOXICROAK, 25
# 371 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_TOXICROAK, CRY_MODE_ENCOUNTER
# 372 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 373 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 374 "data/maps/TARC3_base/scripts.pory"
	dowildbattle
# 375 "data/maps/TARC3_base/scripts.pory"
	callnative WasBattleWon
# 376 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Azure_Toxicroak_10
TARC3_Azure_Toxicroak_1:
# 382 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Azure_Toxicroak_2:
# 355 "data/maps/TARC3_base/scripts.pory"
	goto TARC3_Toxicroak_Post
	goto TARC3_Azure_Toxicroak_1

TARC3_Azure_Toxicroak_7:
# 364 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Azure_Toxicroak_Text_1
	goto TARC3_Azure_Toxicroak_5

TARC3_Azure_Toxicroak_8:
# 366 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Azure_Toxicroak_Text_2
	goto TARC3_Azure_Toxicroak_5

TARC3_Azure_Toxicroak_10:
# 378 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_BASE_TOXICROAK_BEATEN
# 379 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_START
	goto TARC3_Azure_Toxicroak_1


TARC3_Azure_Gastrodon::
# 387 "data/maps/TARC3_base/scripts.pory"
	cant_see_if_set FLAG_BASE_GASTRODON_BEATEN
# 388 "data/maps/TARC3_base/scripts.pory"
	lock
# 389 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 391 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Azure_Gastrodon_Text_0
# 393 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_GASTRODON_BEATEN, TARC3_Azure_Gastrodon_2
# 399 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_GASTRODON
# 400 "data/maps/TARC3_base/scripts.pory"
	callnative GetCurrentTransformationSpecies
# 401 "data/maps/TARC3_base/scripts.pory"
	switch VAR_RESULT
# 403 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_SUNNY, TARC3_Azure_Gastrodon_7
# 405 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_RAINY, TARC3_Azure_Gastrodon_8
# 408 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Azure_Gastrodon_Text_3
TARC3_Azure_Gastrodon_5:
# 410 "data/maps/TARC3_base/scripts.pory"
	setwildbattle SPECIES_GASTRODON, 25
# 411 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_GASTRODON, CRY_MODE_ENCOUNTER
# 412 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 413 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 414 "data/maps/TARC3_base/scripts.pory"
	dowildbattle
# 415 "data/maps/TARC3_base/scripts.pory"
	callnative WasBattleWon
# 416 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Azure_Gastrodon_10
TARC3_Azure_Gastrodon_1:
# 422 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Azure_Gastrodon_2:
# 395 "data/maps/TARC3_base/scripts.pory"
	goto TARC3_Gastrodon_Post
	goto TARC3_Azure_Gastrodon_1

TARC3_Azure_Gastrodon_7:
# 404 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Azure_Gastrodon_Text_1
	goto TARC3_Azure_Gastrodon_5

TARC3_Azure_Gastrodon_8:
# 406 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Azure_Gastrodon_Text_2
	goto TARC3_Azure_Gastrodon_5

TARC3_Azure_Gastrodon_10:
# 418 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_BASE_GASTRODON_BEATEN
# 419 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_START
	goto TARC3_Azure_Gastrodon_1


TARC3_Azure_Observer::
# 427 "data/maps/TARC3_base/scripts.pory"
	cant_see_if_set FLAG_BASE_SLOWKING_BEATEN
# 428 "data/maps/TARC3_base/scripts.pory"
	lock
# 429 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 431 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Azure_Observer_Text_0
# 432 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_SLOWKING
# 434 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_SLOWKING_BEATEN, TARC3_Azure_Observer_2
# 440 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Azure_Observer_Text_1
# 441 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_SLOWKING, CRY_MODE_ENCOUNTER
# 442 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 443 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 444 "data/maps/TARC3_base/scripts.pory"
	ai_vs_ai_wild_battle SPECIES_DRAMPA, SPECIES_SLOWKING, 25
# 445 "data/maps/TARC3_base/scripts.pory"
	callnative WasBattleWon
# 446 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Azure_Observer_5
TARC3_Azure_Observer_1:
# 452 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Azure_Observer_2:
# 436 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Amber_Observer_Text_1
	goto TARC3_Azure_Observer_1

TARC3_Azure_Observer_5:
# 448 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_BASE_SLOWKING_BEATEN
# 449 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_START
	goto TARC3_Azure_Observer_1


TARC3_Azure_Flygon::
# 457 "data/maps/TARC3_base/scripts.pory"
	cant_see_if_set FLAG_BASE_FLYGON_BEATEN
# 458 "data/maps/TARC3_base/scripts.pory"
	lock
# 459 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 461 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Azure_Flygon_Text_0
# 463 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_FLYGON_BEATEN, TARC3_Azure_Flygon_2
# 469 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_FLYGON
# 470 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Azure_Flygon_Text_1
# 471 "data/maps/TARC3_base/scripts.pory"
	setwildbattle SPECIES_FLYGON, 25
# 472 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_FLYGON, CRY_MODE_ENCOUNTER
# 473 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 474 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 475 "data/maps/TARC3_base/scripts.pory"
	dowildbattle
# 476 "data/maps/TARC3_base/scripts.pory"
	callnative WasBattleWon
# 477 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Azure_Flygon_5
TARC3_Azure_Flygon_1:
# 483 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Azure_Flygon_2:
# 465 "data/maps/TARC3_base/scripts.pory"
	goto TARC3_Flygon_Post
	goto TARC3_Azure_Flygon_1

TARC3_Azure_Flygon_5:
# 479 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_BASE_FLYGON_BEATEN
# 480 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_START
	goto TARC3_Azure_Flygon_1


TARC3_Paras_Post::
# 490 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_SURSKIT, CRY_MODE_NORMAL
# 492 "data/maps/TARC3_base/scripts.pory"
	callnative GetCurrentTransformationSpecies
# 493 "data/maps/TARC3_base/scripts.pory"
	switch VAR_RESULT
# 495 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_SUNNY, TARC3_Paras_Post_3
# 497 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_RAINY, TARC3_Paras_Post_4
# 498 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_SNOWY, TARC3_Paras_Post_4
# 500 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM, TARC3_Paras_Post_5
TARC3_Paras_Post_5:
# 502 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Paras_Post_Text_2
TARC3_Paras_Post_1:
# 504 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Paras_Post_3:
# 496 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Paras_Post_Text_0
	goto TARC3_Paras_Post_1

TARC3_Paras_Post_4:
# 499 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Paras_Post_Text_1
	goto TARC3_Paras_Post_1


TARC3_Surskit::
# 509 "data/maps/TARC3_base/scripts.pory"
	lock
# 510 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 511 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_SURSKIT, CRY_MODE_NORMAL
# 512 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Surskit_Text_0
# 513 "data/maps/TARC3_base/scripts.pory"
	callnative GetCurrentTransformationSpecies
# 514 "data/maps/TARC3_base/scripts.pory"
	switch VAR_RESULT
# 516 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_SUNNY, TARC3_Surskit_3
# 518 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_RAINY, TARC3_Surskit_4
# 520 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_SNOWY, TARC3_Surskit_5
# 521 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM, TARC3_Surskit_5
TARC3_Surskit_5:
# 523 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Surskit_Text_3
TARC3_Surskit_1:
# 525 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Surskit_3:
# 517 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Surskit_Text_1
	goto TARC3_Surskit_1

TARC3_Surskit_4:
# 519 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Surskit_Text_2
	goto TARC3_Surskit_1


TARC3_Vulpix_Post::
# 530 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_VULPIX, CRY_MODE_NORMAL
# 532 "data/maps/TARC3_base/scripts.pory"
	callnative GetCurrentTransformationSpecies
# 533 "data/maps/TARC3_base/scripts.pory"
	switch VAR_RESULT
# 536 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Vulpix_Post_Text_0
# 538 "data/maps/TARC3_base/scripts.pory"
	release
	end


TARC3_Dewpider_Post::
# 543 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_DEWPIDER, CRY_MODE_NORMAL
# 545 "data/maps/TARC3_base/scripts.pory"
	callnative GetCurrentTransformationSpecies
# 546 "data/maps/TARC3_base/scripts.pory"
	switch VAR_RESULT
# 548 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_SUNNY, TARC3_Dewpider_Post_3
# 551 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Dewpider_Post_Text_1
TARC3_Dewpider_Post_1:
# 553 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Dewpider_Post_3:
# 549 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Dewpider_Post_Text_0
	goto TARC3_Dewpider_Post_1


TARC3_Munchlax_Post::
# 558 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_MUNCHLAX, CRY_MODE_NORMAL
# 560 "data/maps/TARC3_base/scripts.pory"
	callnative GetCurrentTransformationSpecies
# 561 "data/maps/TARC3_base/scripts.pory"
	switch VAR_RESULT
# 564 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Munchlax_Post_Text_0
# 566 "data/maps/TARC3_base/scripts.pory"
	release
	end


TARC3_Combusken_Post::
# 571 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_COMBUSKEN, CRY_MODE_NORMAL
# 573 "data/maps/TARC3_base/scripts.pory"
	callnative GetCurrentTransformationSpecies
# 574 "data/maps/TARC3_base/scripts.pory"
	switch VAR_RESULT
# 576 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_RAINY, TARC3_Combusken_Post_3
# 579 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Combusken_Post_Text_1
TARC3_Combusken_Post_1:
# 581 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Combusken_Post_3:
# 577 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Combusken_Post_Text_0
	goto TARC3_Combusken_Post_1


TARC3_Torkoal_Post::
# 586 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_TORKOAL, CRY_MODE_NORMAL
# 588 "data/maps/TARC3_base/scripts.pory"
	callnative GetCurrentTransformationSpecies
# 589 "data/maps/TARC3_base/scripts.pory"
	switch VAR_RESULT
# 591 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_RAINY, TARC3_Torkoal_Post_3
# 594 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Torkoal_Post_Text_1
TARC3_Torkoal_Post_1:
# 596 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Torkoal_Post_3:
# 592 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Torkoal_Post_Text_0
	goto TARC3_Torkoal_Post_1


TARC3_Toxicroak_Post::
# 601 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_TOXICROAK, CRY_MODE_NORMAL
# 603 "data/maps/TARC3_base/scripts.pory"
	callnative GetCurrentTransformationSpecies
# 604 "data/maps/TARC3_base/scripts.pory"
	switch VAR_RESULT
# 607 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Toxicroak_Post_Text_0
# 609 "data/maps/TARC3_base/scripts.pory"
	release
	end


TARC3_Gastrodon_Post::
# 614 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_GASTRODON, CRY_MODE_NORMAL
# 616 "data/maps/TARC3_base/scripts.pory"
	callnative GetCurrentTransformationSpecies
# 617 "data/maps/TARC3_base/scripts.pory"
	switch VAR_RESULT
# 620 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Gastrodon_Post_Text_0
# 622 "data/maps/TARC3_base/scripts.pory"
	release
	end


TARC3_Flygon_Post::
# 627 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_FLYGON, CRY_MODE_NORMAL
# 629 "data/maps/TARC3_base/scripts.pory"
	callnative GetCurrentTransformationSpecies
# 630 "data/maps/TARC3_base/scripts.pory"
	switch VAR_RESULT
# 632 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_RAINY, TARC3_Flygon_Post_3
# 635 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Torkoal_Post_Text_1
TARC3_Flygon_Post_1:
# 637 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Flygon_Post_3:
# 633 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Torkoal_Post_Text_0
	goto TARC3_Flygon_Post_1


TARC3_Whimsicott::
# 642 "data/maps/TARC3_base/scripts.pory"
	lock
# 643 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 644 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Whimsicott_Text_0
# 646 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_WHIMSICOTT_GAVE_SEED, TARC3_Whimsicott_2
# 652 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Whimsicott_Text_2
# 653 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_WHIMSICOTT, CRY_MODE_NORMAL
# 654 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 655 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 656 "data/maps/TARC3_base/scripts.pory"
	giveitem ITEM_WEPEAR_BERRY, 1
# 657 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_WHIMSICOTT_GAVE_SEED
# 658 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Whimsicott_Text_1
TARC3_Whimsicott_1:
# 660 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Whimsicott_2:
# 648 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Whimsicott_Text_1
	goto TARC3_Whimsicott_1


TARC3_Feebas::
# 665 "data/maps/TARC3_base/scripts.pory"
	lock
# 666 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 667 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Feebas_Text_0
# 669 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_FEEBAS, CRY_MODE_NORMAL
# 670 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Feebas_Text_1
# 671 "data/maps/TARC3_base/scripts.pory"
	release
	end


TARC3_Chatot1::
# 676 "data/maps/TARC3_base/scripts.pory"
	lock
# 677 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 678 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Chatot1_Text_0
# 680 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_CHATOT, CRY_MODE_NORMAL
# 681 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Chatot1_Text_1
# 682 "data/maps/TARC3_base/scripts.pory"
	release
	end


TARC3_Chatot2::
# 687 "data/maps/TARC3_base/scripts.pory"
	lock
# 688 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 689 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Chatot1_Text_0
# 691 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_CHATOT, CRY_MODE_NORMAL
# 692 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Chatot2_Text_0
# 693 "data/maps/TARC3_base/scripts.pory"
	release
	end


TARC3_Audino::
# 698 "data/maps/TARC3_base/scripts.pory"
	lock
# 699 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 700 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Audino_Text_0
# 702 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_AUDINO, CRY_MODE_NORMAL
# 703 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_AUDINO_GAVE_HERBICIDE, TARC3_Audino_1
# 707 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Audino_Text_1
# 708 "data/maps/TARC3_base/scripts.pory"
	giveitem ITEM_HYPER_POTION
# 709 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_AUDINO_GAVE_HERBICIDE
# 710 "data/maps/TARC3_base/scripts.pory"
	goto TARC3_Audino_Post
	return

TARC3_Audino_1:
# 704 "data/maps/TARC3_base/scripts.pory"
	goto TARC3_Audino_Post
	return


TARC3_Audino_Post::
# 715 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Audino_Post_Text_0
# 716 "data/maps/TARC3_base/scripts.pory"
	release
	end


TARC3_Minccino::
# 721 "data/maps/TARC3_base/scripts.pory"
	lock
# 722 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 723 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Minccino_Text_0
# 725 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_MINCCINO, CRY_MODE_NORMAL
# 726 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Minccino_Text_1
# 727 "data/maps/TARC3_base/scripts.pory"
	release
	end


TARC3_Smeargle::
# 732 "data/maps/TARC3_base/scripts.pory"
	lock
# 733 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 734 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Smeargle_Text_0
# 736 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_SMEARGLE, CRY_MODE_NORMAL
# 737 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Smeargle_Text_1
# 738 "data/maps/TARC3_base/scripts.pory"
	release
	end


TARC3_Nosepass::
# 743 "data/maps/TARC3_base/scripts.pory"
	lock
# 744 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 745 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Nosepass_Text_0
# 747 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_NOSEPASS, CRY_MODE_NORMAL
# 748 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Nosepass_Text_1
# 749 "data/maps/TARC3_base/scripts.pory"
	release
	end


TARC3_Ducklett::
# 754 "data/maps/TARC3_base/scripts.pory"
	lock
# 755 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 756 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Ducklett_Text_0
# 758 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_DUCKLETT, CRY_MODE_NORMAL
# 759 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Ducklett_Text_1
# 760 "data/maps/TARC3_base/scripts.pory"
	release
	end


TARC3_Sliggoo::
# 765 "data/maps/TARC3_base/scripts.pory"
	lock
# 766 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 767 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Sliggoo_Text_0
# 769 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_SLIGGOO, CRY_MODE_NORMAL
# 770 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Sliggoo_Text_1
# 771 "data/maps/TARC3_base/scripts.pory"
	release
	end


TARC3_Goodra::
# 776 "data/maps/TARC3_base/scripts.pory"
	lock
# 777 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 778 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Goodra_Text_0
# 780 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_GOODRA, CRY_MODE_NORMAL
# 781 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_GOODRA_GAVE_ITEM, TARC3_Goodra_2
# 785 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Goodra_Text_2
# 786 "data/maps/TARC3_base/scripts.pory"
	giveitem ITEM_MIRACLE_SEED
# 787 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_GOODRA_GAVE_ITEM
# 788 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Goodra_Text_1
TARC3_Goodra_1:
# 790 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Goodra_2:
# 782 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Goodra_Text_1
	goto TARC3_Goodra_1


TARC3_Lapras1_Source::
# 795 "data/maps/TARC3_base/scripts.pory"
	lock
# 796 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 797 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Lapras1_Source_Text_0
# 799 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_LAPRAS, CRY_MODE_NORMAL
# 800 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Lapras1_Source_Text_1
# 801 "data/maps/TARC3_base/scripts.pory"
	applymovement VAR_LAST_TALKED, TARC3_Lapras1_Source_Movement_0
# 806 "data/maps/TARC3_base/scripts.pory"
	waitmovement 0
# 807 "data/maps/TARC3_base/scripts.pory"
	removeobject VAR_LAST_TALKED
# 808 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_LAPRAS1_SOURCE_INVISIBLE
# 809 "data/maps/TARC3_base/scripts.pory"
	clearflag FLAG_LAPRAS1_DEST_INVISIBLE
# 810 "data/maps/TARC3_base/scripts.pory"
	release
	end


TARC3_Lapras2_Source::
# 815 "data/maps/TARC3_base/scripts.pory"
	lock
# 816 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 817 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Lapras1_Source_Text_0
# 819 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_LAPRAS, CRY_MODE_NORMAL
# 820 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Lapras2_Source_Text_0
# 821 "data/maps/TARC3_base/scripts.pory"
	applymovement VAR_LAST_TALKED, TARC3_Lapras2_Source_Movement_0
# 832 "data/maps/TARC3_base/scripts.pory"
	waitmovement 0
# 833 "data/maps/TARC3_base/scripts.pory"
	removeobject VAR_LAST_TALKED
# 834 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_LAPRAS2_SOURCE_INVISIBLE
# 835 "data/maps/TARC3_base/scripts.pory"
	clearflag FLAG_LAPRAS2_DEST_INVISIBLE
# 836 "data/maps/TARC3_base/scripts.pory"
	release
	end


TARC3_Sign_TreeOfLife::
# 841 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Sign_TreeOfLife_Text_0, MSGBOX_SIGN
	end


TARC3_Sign_ApricornTree::
# 846 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Sign_ApricornTree_Text_0, MSGBOX_SIGN
	end


TARC3_Find_IceClimb::
# 851 "data/maps/TARC3_base/scripts.pory"
	finditem ITEM_TM01, 1
	end


TARC3_Dummy_Start_Amber::
# 856 "data/maps/TARC3_base/scripts.pory"
	lockall
# 857 "data/maps/TARC3_base/scripts.pory"
	setvar VAR_CASTFORM_PHASE, 1
# 858 "data/maps/TARC3_base/scripts.pory"
	setvar VAR_TRIGGER_XATU_EVENT, 1
# 859 "data/maps/TARC3_base/scripts.pory"
	finditem ITEM_HEAT_ROCK, 1
# 860 "data/maps/TARC3_base/scripts.pory"
	givemon SPECIES_CASTFORM_SUNNY, 25
# 861 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_ITEM_AMBER_SHARD
# 862 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_RUN_XATU_AMBER
# 863 "data/maps/TARC3_base/scripts.pory"
	releaseall
# 864 "data/maps/TARC3_base/scripts.pory"
	warp MAP_TARC3_WEATHER_INSTITUTE_2F, 9, 8
# 865 "data/maps/TARC3_base/scripts.pory"
	waitstate
	end


# 191 "data/maps/TARC3_base/scripts.pory"
TARC3_Amber_Munchlax_Movement_0:
# 192 "data/maps/TARC3_base/scripts.pory"
	walk_up
# 192 "data/maps/TARC3_base/scripts.pory"
	walk_up
# 193 "data/maps/TARC3_base/scripts.pory"
	face_down
	step_end

# 801 "data/maps/TARC3_base/scripts.pory"
TARC3_Lapras1_Source_Movement_0:
# 802 "data/maps/TARC3_base/scripts.pory"
	walk_down
# 802 "data/maps/TARC3_base/scripts.pory"
	walk_down
# 802 "data/maps/TARC3_base/scripts.pory"
	walk_down
# 803 "data/maps/TARC3_base/scripts.pory"
	walk_right
# 803 "data/maps/TARC3_base/scripts.pory"
	walk_right
# 804 "data/maps/TARC3_base/scripts.pory"
	walk_down
# 804 "data/maps/TARC3_base/scripts.pory"
	walk_down
# 804 "data/maps/TARC3_base/scripts.pory"
	walk_down
	step_end

# 821 "data/maps/TARC3_base/scripts.pory"
TARC3_Lapras2_Source_Movement_0:
# 822 "data/maps/TARC3_base/scripts.pory"
	walk_right
# 822 "data/maps/TARC3_base/scripts.pory"
	walk_right
# 822 "data/maps/TARC3_base/scripts.pory"
	walk_right
# 822 "data/maps/TARC3_base/scripts.pory"
	walk_right
# 822 "data/maps/TARC3_base/scripts.pory"
	walk_right
# 823 "data/maps/TARC3_base/scripts.pory"
	walk_up
# 824 "data/maps/TARC3_base/scripts.pory"
	walk_right
# 825 "data/maps/TARC3_base/scripts.pory"
	walk_up
# 826 "data/maps/TARC3_base/scripts.pory"
	walk_right
# 827 "data/maps/TARC3_base/scripts.pory"
	walk_up
# 828 "data/maps/TARC3_base/scripts.pory"
	walk_right
# 829 "data/maps/TARC3_base/scripts.pory"
	walk_up
# 830 "data/maps/TARC3_base/scripts.pory"
	walk_right
	step_end

TARC3_Base_Paras_Text_0:
# 49 "data/maps/TARC3_base/scripts.pory"
	.string "Paras$"

TARC3_Base_Paras_Text_1:
# 57 "data/maps/TARC3_base/scripts.pory"
	.string "Weather Shards?\nI only heard of fungal spores.\pDoes that help?$"

TARC3_Base_Vulpix_Text_0:
# 80 "data/maps/TARC3_base/scripts.pory"
	.string "Vulpix$"

TARC3_Base_Vulpix_Text_1:
# 88 "data/maps/TARC3_base/scripts.pory"
	.string "I don't care about the weather.\pFor me the sun is always shining!$"

TARC3_Base_Dewpider_Text_0:
# 111 "data/maps/TARC3_base/scripts.pory"
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
# 181 "data/maps/TARC3_base/scripts.pory"
	.string "Munchlax$"

TARC3_Amber_Munchlax_Text_1:
# 190 "data/maps/TARC3_base/scripts.pory"
	.string "It's too hot to battle!$"

TARC3_Amber_Munchlax_Text_2:
# 202 "data/maps/TARC3_base/scripts.pory"
	.string "Do you have some berries for me?\nI am hungry!$"

TARC3_Amber_Combusken_Text_0:
# 225 "data/maps/TARC3_base/scripts.pory"
	.string "Combusken$"

TARC3_Amber_Combusken_Text_1:
# 234 "data/maps/TARC3_base/scripts.pory"
	.string "What are you doing here\nin my territory?\pYou think you can handle me?\nThe sun is on my side, too!$"

TARC3_Amber_Observer_Text_0:
# 256 "data/maps/TARC3_base/scripts.pory"
	.string "Fomantis$"

TARC3_Amber_Observer_Text_1:
# 260 "data/maps/TARC3_base/scripts.pory"
	.string "We're cool again!$"

TARC3_Amber_Observer_Text_2:
# 265 "data/maps/TARC3_base/scripts.pory"
	.string "This HELIOPTILE is so mean!\pCan you help me scaring it away?$"

TARC3_Amber_Observer_Text_3:
# 275 "data/maps/TARC3_base/scripts.pory"
	.string "Thank you for helping me!$"

TARC3_Amber_Torkoal_Text_0:
# 308 "data/maps/TARC3_base/scripts.pory"
	.string "Torkoal$"

TARC3_Amber_Torkoal_Text_1:
# 317 "data/maps/TARC3_base/scripts.pory"
	.string "Who dares to bother me during my nap?\p...\pAre you after that stone?\pYou cannot have it, it's dangerous!\nIt will turn the world into endless rain!$"

TARC3_Amber_Torkoal_Text_2:
# 330 "data/maps/TARC3_base/scripts.pory"
	.string "Defeated. Like it was nothing.\pMaybe you are able to save us\nfrom the chaos!\pHere, I found it behind the lava pool!$"

TARC3_Azure_Toxicroak_Text_0:
# 351 "data/maps/TARC3_base/scripts.pory"
	.string "Toxicroak$"

TARC3_Azure_Toxicroak_Text_1:
# 364 "data/maps/TARC3_base/scripts.pory"
	.string "This heat is miserable!\nIt burns my skin!$"

TARC3_Azure_Toxicroak_Text_2:
# 366 "data/maps/TARC3_base/scripts.pory"
	.string "Heh... Now THIS is my kind of weather!\nCome on, then. Try your best!$"

TARC3_Azure_Toxicroak_Text_3:
# 368 "data/maps/TARC3_base/scripts.pory"
	.string "You are playing with the weather?\pLet's see who is making the rules!$"

TARC3_Azure_Gastrodon_Text_0:
# 391 "data/maps/TARC3_base/scripts.pory"
	.string "Gastrodon$"

TARC3_Azure_Gastrodon_Text_1:
# 404 "data/maps/TARC3_base/scripts.pory"
	.string "Trying to dry me out?\pIt'll take more than sunshine\nto pass me!$"

TARC3_Azure_Gastrodon_Text_2:
# 406 "data/maps/TARC3_base/scripts.pory"
	.string "Oh? You brought me even more water?\pLet's go, I take as much as you give!$"

TARC3_Azure_Gastrodon_Text_3:
# 408 "data/maps/TARC3_base/scripts.pory"
	.string "I don't care much about\nthe weather!\pBut this is my domain and you\nare trespassing!$"

TARC3_Azure_Observer_Text_0:
# 431 "data/maps/TARC3_base/scripts.pory"
	.string "Drampa$"

TARC3_Azure_Observer_Text_1:
# 440 "data/maps/TARC3_base/scripts.pory"
	.string "Hi, I'm DRAMPA.\nPlease help me!$"

TARC3_Azure_Flygon_Text_0:
# 461 "data/maps/TARC3_base/scripts.pory"
	.string "Flygon$"

TARC3_Azure_Flygon_Text_1:
# 470 "data/maps/TARC3_base/scripts.pory"
	.string "Hi, I'm FLYGON.\nLet's battle!$"

TARC3_Paras_Post_Text_0:
# 496 "data/maps/TARC3_base/scripts.pory"
	.string "I am enjoying the warmth!\pJust keep any Fire Types away!$"

TARC3_Paras_Post_Text_1:
# 499 "data/maps/TARC3_base/scripts.pory"
	.string "What's this weather?\pThis is miserable, I can't stand it!$"

TARC3_Paras_Post_Text_2:
# 502 "data/maps/TARC3_base/scripts.pory"
	.string "You can make it sunny?\pI am rooting for you!$"

TARC3_Surskit_Text_0:
# 512 "data/maps/TARC3_base/scripts.pory"
	.string "Surskit$"

TARC3_Surskit_Text_1:
# 517 "data/maps/TARC3_base/scripts.pory"
	.string "My pond!\nWhere did it go???$"

TARC3_Surskit_Text_2:
# 519 "data/maps/TARC3_base/scripts.pory"
	.string "You made this rain?\pI LOVE IT!\nPlease never make it stop.$"

TARC3_Surskit_Text_3:
# 523 "data/maps/TARC3_base/scripts.pory"
	.string "The weather has been crazy lately!\pI hope it calms down soon.$"

TARC3_Vulpix_Post_Text_0:
# 536 "data/maps/TARC3_base/scripts.pory"
	.string "You transformed and even\nchanged your moveset?\pThat is so cool!\nHow did you do that?$"

TARC3_Dewpider_Post_Text_0:
# 549 "data/maps/TARC3_base/scripts.pory"
	.string "What did you do???\pWhere did my home go???$"

TARC3_Dewpider_Post_Text_1:
# 551 "data/maps/TARC3_base/scripts.pory"
	.string "Please be careful!$"

TARC3_Munchlax_Post_Text_0:
# 564 "data/maps/TARC3_base/scripts.pory"
	.string "I heard there is a mysterious\nobject on top of the mountain.\pThey say it can make it rain.\pAnd rain makes berries grow.\nYummy!$"

TARC3_Combusken_Post_Text_0:
# 577 "data/maps/TARC3_base/scripts.pory"
	.string "Now this is unfair!$"

TARC3_Combusken_Post_Text_1:
# 579 "data/maps/TARC3_base/scripts.pory"
	.string "I clearly should have won!$"

TARC3_Torkoal_Post_Text_0:
# 592 "data/maps/TARC3_base/scripts.pory"
	.string "Woah! I didn't know you could\nturn the lava into stone!$"

TARC3_Torkoal_Post_Text_1:
# 594 "data/maps/TARC3_base/scripts.pory"
	.string "Please help us bring back normality!$"

TARC3_Toxicroak_Post_Text_0:
# 607 "data/maps/TARC3_base/scripts.pory"
	.string "You used the water against me?\pThat's embarrassing!$"

TARC3_Gastrodon_Post_Text_0:
# 620 "data/maps/TARC3_base/scripts.pory"
	.string "I've seen a hidden cave\nentrance when I was roaming\lthe riverbed.\pMaybe there is a way for you\nto get there?$"

TARC3_Whimsicott_Text_0:
# 644 "data/maps/TARC3_base/scripts.pory"
	.string "Whimsicott$"

TARC3_Whimsicott_Text_1:
# 648 "data/maps/TARC3_base/scripts.pory"
	.string "When you plant and water it,\nit will grow!\pBut don't expect much from these\nApricorn trees.\lThey haven't changed in ages.$"

TARC3_Whimsicott_Text_2:
# 652 "data/maps/TARC3_base/scripts.pory"
	.string "Hi there, glad you found me!\pMy name is Whimsicott and\nI am the gardener of this town.\pHere, you can have a seed, too.$"

TARC3_Feebas_Text_0:
# 667 "data/maps/TARC3_base/scripts.pory"
	.string "Feebas$"

TARC3_Feebas_Text_1:
# 670 "data/maps/TARC3_base/scripts.pory"
	.string "If you ever get stuck,\nswim on the river and\lswitch to your Base form.\pThis will respawn you in front\nof the institute.$"

TARC3_Chatot1_Text_0:
# 678 "data/maps/TARC3_base/scripts.pory"
	.string "Chatot$"

TARC3_Chatot1_Text_1:
# 681 "data/maps/TARC3_base/scripts.pory"
	.string "Have you met Whimsicott, yet?\pShe is really friendly and\nprovides the town with crops.$"

TARC3_Chatot2_Text_0:
# 692 "data/maps/TARC3_base/scripts.pory"
	.string "Remember, if you get stuck,\nswim on the river and\lswitch to your Base form.\pRIP$"

TARC3_Audino_Text_0:
# 700 "data/maps/TARC3_base/scripts.pory"
	.string "Audino$"

TARC3_Audino_Text_1:
# 707 "data/maps/TARC3_base/scripts.pory"
	.string "Whimsicott taught me how to\nreverse-grow plants.\pBut I am no gardener myself.\nYou can have this.$"

TARC3_Audino_Post_Text_0:
# 715 "data/maps/TARC3_base/scripts.pory"
	.string "You can use this on grown vines.$"

TARC3_Minccino_Text_0:
# 723 "data/maps/TARC3_base/scripts.pory"
	.string "Minccino$"

TARC3_Minccino_Text_1:
# 726 "data/maps/TARC3_base/scripts.pory"
	.string "The top of the volcano is hard\nto reach.\pI tried it before, but it was\ntoo steep and slippery.$"

TARC3_Smeargle_Text_0:
# 734 "data/maps/TARC3_base/scripts.pory"
	.string "Smeargle$"

TARC3_Smeargle_Text_1:
# 737 "data/maps/TARC3_base/scripts.pory"
	.string "Did you notice the palette changes\nduring sunny weather?\pThat's me recoloring everything\nin an instant!$"

TARC3_Nosepass_Text_0:
# 745 "data/maps/TARC3_base/scripts.pory"
	.string "Nosepass$"

TARC3_Nosepass_Text_1:
# 748 "data/maps/TARC3_base/scripts.pory"
	.string "I tried this shortcut,\nbut it didn't work out.$"

TARC3_Ducklett_Text_0:
# 756 "data/maps/TARC3_base/scripts.pory"
	.string "Ducklett$"

TARC3_Ducklett_Text_1:
# 759 "data/maps/TARC3_base/scripts.pory"
	.string "Well done!\nI don't get many visitors here.\pThe way you got here will open\nmany more hidden paths for you.$"

TARC3_Sliggoo_Text_0:
# 767 "data/maps/TARC3_base/scripts.pory"
	.string "Sliggoo$"

TARC3_Sliggoo_Text_1:
# 770 "data/maps/TARC3_base/scripts.pory"
	.string "Heya, guess what level I am now!\pIt's already 69, but I just don't\nevolve.\pSo sad...$"

TARC3_Goodra_Text_0:
# 778 "data/maps/TARC3_base/scripts.pory"
	.string "Goodra$"

TARC3_Goodra_Text_1:
# 782 "data/maps/TARC3_base/scripts.pory"
	.string "I tried evolving for so long,\nbut I had no idea how...$"

TARC3_Goodra_Text_2:
# 785 "data/maps/TARC3_base/scripts.pory"
	.string "You made it rain.\nThat was it!\pThank you so much for the help!\pHere, takes this.$"

TARC3_Lapras1_Source_Text_0:
# 797 "data/maps/TARC3_base/scripts.pory"
	.string "Lapras$"

TARC3_Lapras1_Source_Text_1:
# 800 "data/maps/TARC3_base/scripts.pory"
	.string "Hello my friend!\nYou are trying to save us all?\pIf you find me and my friend\nwe might be able to assist\lyou on the mission.$"

TARC3_Lapras2_Source_Text_0:
# 820 "data/maps/TARC3_base/scripts.pory"
	.string "Yay, a new friend!\pLet's meet at the little island\nWEST from here.$"

TARC3_Sign_TreeOfLife_Text_0:
# 841 "data/maps/TARC3_base/scripts.pory"
	.string "Tree of Life\pOnly Arceus may enter.$"

TARC3_Sign_ApricornTree_Text_0:
# 846 "data/maps/TARC3_base/scripts.pory"
	.string "An Apricorn Tree blocks\nthe entrance.\pPost game area.$"
