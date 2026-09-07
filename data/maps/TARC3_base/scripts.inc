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
# 17 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_SNOWY, TARC3_Base_OnResume_4
# 23 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_SUNNY, TARC3_Base_OnResume_5
# 31 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM, TARC3_Base_OnResume_6
TARC3_Base_OnResume_6:
# 33 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_HIDE_ITEM_UNDERWATER
# 34 "data/maps/TARC3_base/scripts.pory"
	clearflag FLAG_LAPRAS1_SOURCE_INVISIBLE
# 35 "data/maps/TARC3_base/scripts.pory"
	clearflag FLAG_LAPRAS2_SOURCE_INVISIBLE
# 36 "data/maps/TARC3_base/scripts.pory"
	clearflag FLAG_LAPRAS1_DEST_INVISIBLE
# 37 "data/maps/TARC3_base/scripts.pory"
	clearflag FLAG_LAPRAS2_DEST_INVISIBLE
TARC3_Base_OnResume_1:
	end

TARC3_Base_OnResume_3:
# 12 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_HIDE_ITEM_UNDERWATER
# 13 "data/maps/TARC3_base/scripts.pory"
	clearflag FLAG_LAPRAS1_SOURCE_INVISIBLE
# 14 "data/maps/TARC3_base/scripts.pory"
	clearflag FLAG_LAPRAS2_SOURCE_INVISIBLE
# 15 "data/maps/TARC3_base/scripts.pory"
	clearflag FLAG_LAPRAS1_DEST_INVISIBLE
# 16 "data/maps/TARC3_base/scripts.pory"
	clearflag FLAG_LAPRAS2_DEST_INVISIBLE
	goto TARC3_Base_OnResume_1

TARC3_Base_OnResume_4:
# 18 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_HIDE_ITEM_UNDERWATER
# 19 "data/maps/TARC3_base/scripts.pory"
	clearflag FLAG_LAPRAS1_SOURCE_INVISIBLE
# 20 "data/maps/TARC3_base/scripts.pory"
	clearflag FLAG_LAPRAS2_SOURCE_INVISIBLE
# 21 "data/maps/TARC3_base/scripts.pory"
	clearflag FLAG_LAPRAS1_DEST_INVISIBLE
# 22 "data/maps/TARC3_base/scripts.pory"
	clearflag FLAG_LAPRAS2_DEST_INVISIBLE
	goto TARC3_Base_OnResume_1

TARC3_Base_OnResume_5:
# 24 "data/maps/TARC3_base/scripts.pory"
	goto_if_unset FLAG_ITEM_COLLECTIBLE_2, TARC3_Base_OnResume_8
TARC3_Base_OnResume_7:
# 27 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_LAPRAS1_SOURCE_INVISIBLE
# 28 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_LAPRAS2_SOURCE_INVISIBLE
# 29 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_LAPRAS1_DEST_INVISIBLE
# 30 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_LAPRAS2_DEST_INVISIBLE
	goto TARC3_Base_OnResume_1

TARC3_Base_OnResume_8:
# 25 "data/maps/TARC3_base/scripts.pory"
	clearflag FLAG_HIDE_ITEM_UNDERWATER
	goto TARC3_Base_OnResume_7


TARC3_Base_Sunkern::
# 45 "data/maps/TARC3_base/scripts.pory"
	goto TARC3_Base_Paras
	return


TARC3_Base_Wooper::
# 49 "data/maps/TARC3_base/scripts.pory"
	goto TARC3_Base_Dewpider
	return


TARC3_Base_Torkoal::
# 53 "data/maps/TARC3_base/scripts.pory"
	goto TARC3_Amber_Torkoal
	return


TARC3_Base_Paras::
# 60 "data/maps/TARC3_base/scripts.pory"
	cant_see_if_set FLAG_BASE_PARAS_BEATEN
# 61 "data/maps/TARC3_base/scripts.pory"
	lock
# 62 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 64 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_START
# 66 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Base_Paras_Text_0
# 67 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_PARAS_BEATEN, TARC3_Base_Paras_2
# 73 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Base_Paras_Text_1
# 74 "data/maps/TARC3_base/scripts.pory"
	setwildbattle SPECIES_PARAS, 25
# 75 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_PARAS, CRY_MODE_ENCOUNTER
# 76 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 77 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 78 "data/maps/TARC3_base/scripts.pory"
	dowildbattle
# 79 "data/maps/TARC3_base/scripts.pory"
	callnative WasBattleWon
# 80 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Base_Paras_5
TARC3_Base_Paras_1:
# 86 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Base_Paras_2:
# 69 "data/maps/TARC3_base/scripts.pory"
	goto TARC3_Paras_Post
	goto TARC3_Base_Paras_1

TARC3_Base_Paras_5:
# 82 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_BASE_PARAS_BEATEN
# 83 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_START
	goto TARC3_Base_Paras_1


TARC3_Base_Vulpix::
# 91 "data/maps/TARC3_base/scripts.pory"
	cant_see_if_set FLAG_BASE_VULPIX_BEATEN
# 92 "data/maps/TARC3_base/scripts.pory"
	lock
# 93 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 95 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_VULPIX
# 97 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Base_Vulpix_Text_0
# 98 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_VULPIX_BEATEN, TARC3_Base_Vulpix_2
# 104 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Base_Vulpix_Text_1
# 105 "data/maps/TARC3_base/scripts.pory"
	setwildbattle SPECIES_VULPIX, 25
# 106 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_VULPIX, CRY_MODE_ENCOUNTER
# 107 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 108 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 109 "data/maps/TARC3_base/scripts.pory"
	dowildbattle
# 110 "data/maps/TARC3_base/scripts.pory"
	callnative WasBattleWon
# 111 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Base_Vulpix_5
TARC3_Base_Vulpix_1:
# 117 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Base_Vulpix_2:
# 100 "data/maps/TARC3_base/scripts.pory"
	goto TARC3_Vulpix_Post
	goto TARC3_Base_Vulpix_1

TARC3_Base_Vulpix_5:
# 113 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_BASE_VULPIX_BEATEN
# 114 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_START
	goto TARC3_Base_Vulpix_1


TARC3_Base_Dewpider::
# 122 "data/maps/TARC3_base/scripts.pory"
	cant_see_if_set FLAG_BASE_DEWPIDER_BEATEN
# 123 "data/maps/TARC3_base/scripts.pory"
	lock
# 124 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_DEWPIDER
# 125 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 128 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Base_Dewpider_Text_0
# 129 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_DEWPIDER_BEATEN, TARC3_Base_Dewpider_2
# 135 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Base_Dewpider_Text_1
# 136 "data/maps/TARC3_base/scripts.pory"
	setwildbattle SPECIES_DEWPIDER, 25
# 137 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_DEWPIDER, CRY_MODE_ENCOUNTER
# 138 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 139 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 140 "data/maps/TARC3_base/scripts.pory"
	dowildbattle
# 141 "data/maps/TARC3_base/scripts.pory"
	callnative WasBattleWon
# 142 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Base_Dewpider_5
TARC3_Base_Dewpider_1:
# 148 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Base_Dewpider_2:
# 131 "data/maps/TARC3_base/scripts.pory"
	goto TARC3_Dewpider_Post
	goto TARC3_Base_Dewpider_1

TARC3_Base_Dewpider_5:
# 144 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_BASE_DEWPIDER_BEATEN
# 145 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_START
	goto TARC3_Base_Dewpider_1


TARC3_Base_Wooper_backup::
# 153 "data/maps/TARC3_base/scripts.pory"
	cant_see_if_set FLAG_BASE_WOOPER_BEATEN
# 154 "data/maps/TARC3_base/scripts.pory"
	lock
# 155 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 158 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Base_Wooper_backup_Text_0
# 159 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_WOOPER_BEATEN, TARC3_Base_Wooper_backup_2
# 165 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Base_Wooper_backup_Text_2
# 166 "data/maps/TARC3_base/scripts.pory"
	setwildbattle SPECIES_WOOPER, 25
# 167 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_WOOPER, CRY_MODE_ENCOUNTER
# 168 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 169 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 170 "data/maps/TARC3_base/scripts.pory"
	dowildbattle
# 171 "data/maps/TARC3_base/scripts.pory"
	callnative WasBattleWon
# 172 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Base_Wooper_backup_5
TARC3_Base_Wooper_backup_1:
# 178 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Base_Wooper_backup_2:
# 161 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Base_Wooper_backup_Text_1
	goto TARC3_Base_Wooper_backup_1

TARC3_Base_Wooper_backup_5:
# 174 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_BASE_WOOPER_BEATEN
# 175 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_START
	goto TARC3_Base_Wooper_backup_1


TARC3_Amber_Munchlax_Left::
	end


TARC3_Amber_Munchlax_Right::
	end


TARC3_Amber_Munchlax::
# 192 "data/maps/TARC3_base/scripts.pory"
	cant_see_if_set FLAG_BASE_MUNCHLAX_BEATEN
# 193 "data/maps/TARC3_base/scripts.pory"
	lock
# 194 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 196 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_MUNCHLAX
# 198 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Amber_Munchlax_Text_0
# 199 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_MUNCHLAX_BEATEN, TARC3_Amber_Munchlax_2
# 205 "data/maps/TARC3_base/scripts.pory"
	compare VAR_TRANSFORM_MON, SPECIES_CASTFORM_SUNNY
	goto_if_eq TARC3_Amber_Munchlax_5
# 218 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Amber_Munchlax_Text_2
# 219 "data/maps/TARC3_base/scripts.pory"
	setwildbattle SPECIES_MUNCHLAX, 25
# 220 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_MUNCHLAX, CRY_MODE_ENCOUNTER
# 221 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 222 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 223 "data/maps/TARC3_base/scripts.pory"
	dowildbattle
# 224 "data/maps/TARC3_base/scripts.pory"
	callnative WasBattleWon
# 225 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Amber_Munchlax_8
TARC3_Amber_Munchlax_1:
# 232 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Amber_Munchlax_2:
# 201 "data/maps/TARC3_base/scripts.pory"
	goto TARC3_Munchlax_Post
	goto TARC3_Amber_Munchlax_1

TARC3_Amber_Munchlax_5:
# 207 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Amber_Munchlax_Text_1
# 208 "data/maps/TARC3_base/scripts.pory"
	applymovement LOCALID_PLAYER, TARC3_Amber_Munchlax_Movement_0
# 212 "data/maps/TARC3_base/scripts.pory"
	waitmovement 0
# 213 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Amber_Munchlax_8:
# 227 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_BASE_MUNCHLAX_BEATEN
# 228 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_START
	goto TARC3_Amber_Munchlax_1


TARC3_Amber_Combusken::
# 237 "data/maps/TARC3_base/scripts.pory"
	cant_see_if_set FLAG_BASE_COMBUSKEN_BEATEN
# 238 "data/maps/TARC3_base/scripts.pory"
	lock
# 239 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 241 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_COMBUSKEN
# 242 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Amber_Combusken_Text_0
# 244 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_COMBUSKEN_BEATEN, TARC3_Amber_Combusken_2
# 250 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Amber_Combusken_Text_1
# 251 "data/maps/TARC3_base/scripts.pory"
	setwildbattle SPECIES_COMBUSKEN, 25
# 252 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_COMBUSKEN, CRY_MODE_ENCOUNTER
# 253 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 254 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 255 "data/maps/TARC3_base/scripts.pory"
	dowildbattle
# 256 "data/maps/TARC3_base/scripts.pory"
	callnative WasBattleWon
# 257 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Amber_Combusken_5
TARC3_Amber_Combusken_1:
# 263 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Amber_Combusken_2:
# 246 "data/maps/TARC3_base/scripts.pory"
	goto TARC3_Combusken_Post
	goto TARC3_Amber_Combusken_1

TARC3_Amber_Combusken_5:
# 259 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_BASE_COMBUSKEN_BEATEN
# 260 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_START
	goto TARC3_Amber_Combusken_1


TARC3_Amber_Observer::
# 268 "data/maps/TARC3_base/scripts.pory"
	cant_see_if_set FLAG_BASE_HELIOPTILE_BEATEN
# 269 "data/maps/TARC3_base/scripts.pory"
	lock
# 270 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 272 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_HELIOPTILE
# 273 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Amber_Observer_Text_0
# 275 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_HELIOPTILE_BEATEN, TARC3_Amber_Observer_2
# 281 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Amber_Observer_Text_2
# 282 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_HELIOPTILE, CRY_MODE_ENCOUNTER
# 283 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 284 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 285 "data/maps/TARC3_base/scripts.pory"
	ai_vs_ai_wild_battle SPECIES_FOMANTIS, SPECIES_HELIOPTILE, 25
# 286 "data/maps/TARC3_base/scripts.pory"
	callnative WasBattleWon
# 287 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Amber_Observer_5
TARC3_Amber_Observer_1:
# 301 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Amber_Observer_2:
# 277 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Amber_Observer_Text_1
	goto TARC3_Amber_Observer_1

TARC3_Amber_Observer_5:
# 289 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_BASE_HELIOPTILE_BEATEN
# 290 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_START
# 291 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Amber_Observer_Text_3
# 292 "data/maps/TARC3_base/scripts.pory"
	fadescreen FADE_TO_BLACK
# 293 "data/maps/TARC3_base/scripts.pory"
	special HealPlayerParty
# 294 "data/maps/TARC3_base/scripts.pory"
	removeobject 34
# 295 "data/maps/TARC3_base/scripts.pory"
	removeobject 35
# 296 "data/maps/TARC3_base/scripts.pory"
	delay 60
# 297 "data/maps/TARC3_base/scripts.pory"
	fadescreen FADE_FROM_BLACK
	goto TARC3_Amber_Observer_1


TARC3_Amber_Torkoal::
# 306 "data/maps/TARC3_base/scripts.pory"
	cant_see_if_set FLAG_BASE_TORKOAL_BEATEN
# 307 "data/maps/TARC3_base/scripts.pory"
	lock
# 308 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 310 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_TORKOAL
# 311 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Amber_Torkoal_Text_0
# 313 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_TORKOAL_BEATEN, TARC3_Amber_Torkoal_2
# 319 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Amber_Torkoal_Text_1
# 320 "data/maps/TARC3_base/scripts.pory"
	setwildbattle SPECIES_TORKOAL, 25
# 321 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_TORKOAL, CRY_MODE_ENCOUNTER
# 322 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 323 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 324 "data/maps/TARC3_base/scripts.pory"
	dowildbattle
# 325 "data/maps/TARC3_base/scripts.pory"
	callnative WasBattleWon
# 326 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Amber_Torkoal_5
TARC3_Amber_Torkoal_1:
# 344 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Amber_Torkoal_2:
# 315 "data/maps/TARC3_base/scripts.pory"
	goto TARC3_Torkoal_Post
	goto TARC3_Amber_Torkoal_1

TARC3_Amber_Torkoal_5:
# 328 "data/maps/TARC3_base/scripts.pory"
	lock
# 329 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 330 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_BASE_TORKOAL_BEATEN
# 331 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_START
# 332 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Amber_Torkoal_Text_2
# 333 "data/maps/TARC3_base/scripts.pory"
	setvar VAR_CASTFORM_PHASE, 2
# 334 "data/maps/TARC3_base/scripts.pory"
	setvar VAR_TRIGGER_XATU_EVENT, 1
# 335 "data/maps/TARC3_base/scripts.pory"
	finditem ITEM_DAMP_ROCK, 1
# 336 "data/maps/TARC3_base/scripts.pory"
	givemon SPECIES_CASTFORM_RAINY, 25
# 337 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_ITEM_AZURE_SHARD
# 338 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_RUN_XATU_AZURE
# 339 "data/maps/TARC3_base/scripts.pory"
	releaseall
# 340 "data/maps/TARC3_base/scripts.pory"
	warp MAP_TARC3_WEATHER_INSTITUTE_2F, 9, 8
# 341 "data/maps/TARC3_base/scripts.pory"
	waitstate
	goto TARC3_Amber_Torkoal_1


TARC3_Azure_Toxicroak::
# 349 "data/maps/TARC3_base/scripts.pory"
	cant_see_if_set FLAG_BASE_TOXICROAK_BEATEN
# 350 "data/maps/TARC3_base/scripts.pory"
	lock
# 351 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 353 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Azure_Toxicroak_Text_0
# 354 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_TOXICROAK
# 356 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_TOXICROAK_BEATEN, TARC3_Azure_Toxicroak_2
# 362 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Azure_Toxicroak_Text_2
# 363 "data/maps/TARC3_base/scripts.pory"
	setwildbattle SPECIES_TOXICROAK, 25
# 364 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_TOXICROAK, CRY_MODE_ENCOUNTER
# 365 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 366 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 367 "data/maps/TARC3_base/scripts.pory"
	dowildbattle
# 368 "data/maps/TARC3_base/scripts.pory"
	callnative WasBattleWon
# 369 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Azure_Toxicroak_5
TARC3_Azure_Toxicroak_1:
# 375 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Azure_Toxicroak_2:
# 358 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Azure_Toxicroak_Text_1
	goto TARC3_Azure_Toxicroak_1

TARC3_Azure_Toxicroak_5:
# 371 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_BASE_TOXICROAK_BEATEN
# 372 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_START
	goto TARC3_Azure_Toxicroak_1


TARC3_Azure_Gastrodon::
# 380 "data/maps/TARC3_base/scripts.pory"
	cant_see_if_set FLAG_BASE_GASTRODON_BEATEN
# 381 "data/maps/TARC3_base/scripts.pory"
	lock
# 382 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 384 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Azure_Gastrodon_Text_0
# 385 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_GASTRODON
# 387 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_GASTRODON_BEATEN, TARC3_Azure_Gastrodon_2
# 393 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Azure_Gastrodon_Text_1
# 394 "data/maps/TARC3_base/scripts.pory"
	setwildbattle SPECIES_GASTRODON, 25
# 395 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_GASTRODON, CRY_MODE_ENCOUNTER
# 396 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 397 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 398 "data/maps/TARC3_base/scripts.pory"
	dowildbattle
# 399 "data/maps/TARC3_base/scripts.pory"
	callnative WasBattleWon
# 400 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Azure_Gastrodon_5
TARC3_Azure_Gastrodon_1:
# 406 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Azure_Gastrodon_2:
# 389 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Azure_Toxicroak_Text_1
	goto TARC3_Azure_Gastrodon_1

TARC3_Azure_Gastrodon_5:
# 402 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_BASE_GASTRODON_BEATEN
# 403 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_START
	goto TARC3_Azure_Gastrodon_1


TARC3_Azure_Observer::
# 411 "data/maps/TARC3_base/scripts.pory"
	cant_see_if_set FLAG_BASE_SLOWKING_BEATEN
# 412 "data/maps/TARC3_base/scripts.pory"
	lock
# 413 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 415 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Azure_Observer_Text_0
# 416 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_SLOWKING
# 418 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_SLOWKING_BEATEN, TARC3_Azure_Observer_2
# 424 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Azure_Observer_Text_1
# 425 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_SLOWKING, CRY_MODE_ENCOUNTER
# 426 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 427 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 428 "data/maps/TARC3_base/scripts.pory"
	ai_vs_ai_wild_battle SPECIES_DRAMPA, SPECIES_SLOWKING, 25
# 429 "data/maps/TARC3_base/scripts.pory"
	callnative WasBattleWon
# 430 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Azure_Observer_5
TARC3_Azure_Observer_1:
# 436 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Azure_Observer_2:
# 420 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Amber_Observer_Text_1
	goto TARC3_Azure_Observer_1

TARC3_Azure_Observer_5:
# 432 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_BASE_SLOWKING_BEATEN
# 433 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_START
	goto TARC3_Azure_Observer_1


TARC3_Azure_Flygon::
# 441 "data/maps/TARC3_base/scripts.pory"
	cant_see_if_set FLAG_BASE_FLYGON_BEATEN
# 442 "data/maps/TARC3_base/scripts.pory"
	lock
# 443 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 445 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Azure_Flygon_Text_0
# 446 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_FLYGON
# 448 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_FLYGON_BEATEN, TARC3_Azure_Flygon_2
# 454 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Azure_Flygon_Text_1
# 455 "data/maps/TARC3_base/scripts.pory"
	setwildbattle SPECIES_FLYGON, 25
# 456 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_FLYGON, CRY_MODE_ENCOUNTER
# 457 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 458 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 459 "data/maps/TARC3_base/scripts.pory"
	dowildbattle
# 460 "data/maps/TARC3_base/scripts.pory"
	callnative WasBattleWon
# 461 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Azure_Flygon_5
TARC3_Azure_Flygon_1:
# 467 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Azure_Flygon_2:
# 450 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Azure_Toxicroak_Text_1
	goto TARC3_Azure_Flygon_1

TARC3_Azure_Flygon_5:
# 463 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_BASE_FLYGON_BEATEN
# 464 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_START
	goto TARC3_Azure_Flygon_1


TARC3_Paras_Post::
# 474 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_SURSKIT, CRY_MODE_NORMAL
# 476 "data/maps/TARC3_base/scripts.pory"
	callnative GetCurrentTransformationSpecies
# 477 "data/maps/TARC3_base/scripts.pory"
	switch VAR_RESULT
# 479 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_SUNNY, TARC3_Paras_Post_3
# 481 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_RAINY, TARC3_Paras_Post_4
# 482 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_SNOWY, TARC3_Paras_Post_4
# 484 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM, TARC3_Paras_Post_5
TARC3_Paras_Post_5:
# 486 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Paras_Post_Text_2
TARC3_Paras_Post_1:
# 488 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Paras_Post_3:
# 480 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Paras_Post_Text_0
	goto TARC3_Paras_Post_1

TARC3_Paras_Post_4:
# 483 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Paras_Post_Text_1
	goto TARC3_Paras_Post_1


TARC3_Surskit::
# 493 "data/maps/TARC3_base/scripts.pory"
	lock
# 494 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 495 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_SURSKIT, CRY_MODE_NORMAL
# 496 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Surskit_Text_0
# 497 "data/maps/TARC3_base/scripts.pory"
	callnative GetCurrentTransformationSpecies
# 498 "data/maps/TARC3_base/scripts.pory"
	switch VAR_RESULT
# 500 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_SUNNY, TARC3_Surskit_3
# 502 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_RAINY, TARC3_Surskit_4
# 504 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_SNOWY, TARC3_Surskit_5
# 505 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM, TARC3_Surskit_5
TARC3_Surskit_5:
# 507 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Surskit_Text_3
TARC3_Surskit_1:
# 509 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Surskit_3:
# 501 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Surskit_Text_1
	goto TARC3_Surskit_1

TARC3_Surskit_4:
# 503 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Surskit_Text_2
	goto TARC3_Surskit_1


TARC3_Vulpix_Post::
# 514 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_VULPIX, CRY_MODE_NORMAL
# 516 "data/maps/TARC3_base/scripts.pory"
	callnative GetCurrentTransformationSpecies
# 517 "data/maps/TARC3_base/scripts.pory"
	switch VAR_RESULT
# 520 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Vulpix_Post_Text_0
# 522 "data/maps/TARC3_base/scripts.pory"
	release
	end


TARC3_Dewpider_Post::
# 527 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_DEWPIDER, CRY_MODE_NORMAL
# 529 "data/maps/TARC3_base/scripts.pory"
	callnative GetCurrentTransformationSpecies
# 530 "data/maps/TARC3_base/scripts.pory"
	switch VAR_RESULT
# 532 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_SUNNY, TARC3_Dewpider_Post_3
# 535 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Dewpider_Post_Text_1
TARC3_Dewpider_Post_1:
# 537 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Dewpider_Post_3:
# 533 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Dewpider_Post_Text_0
	goto TARC3_Dewpider_Post_1


TARC3_Munchlax_Post::
# 542 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_MUNCHLAX, CRY_MODE_NORMAL
# 544 "data/maps/TARC3_base/scripts.pory"
	callnative GetCurrentTransformationSpecies
# 545 "data/maps/TARC3_base/scripts.pory"
	switch VAR_RESULT
# 548 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Munchlax_Post_Text_0
# 550 "data/maps/TARC3_base/scripts.pory"
	release
	end


TARC3_Combusken_Post::
# 555 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_COMBUSKEN, CRY_MODE_NORMAL
# 557 "data/maps/TARC3_base/scripts.pory"
	callnative GetCurrentTransformationSpecies
# 558 "data/maps/TARC3_base/scripts.pory"
	switch VAR_RESULT
# 560 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_RAINY, TARC3_Combusken_Post_3
# 563 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Combusken_Post_Text_1
TARC3_Combusken_Post_1:
# 565 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Combusken_Post_3:
# 561 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Combusken_Post_Text_0
	goto TARC3_Combusken_Post_1


TARC3_Torkoal_Post::
# 570 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_TORKOAL, CRY_MODE_NORMAL
# 572 "data/maps/TARC3_base/scripts.pory"
	callnative GetCurrentTransformationSpecies
# 573 "data/maps/TARC3_base/scripts.pory"
	switch VAR_RESULT
# 575 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_RAINY, TARC3_Torkoal_Post_3
# 578 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Torkoal_Post_Text_1
TARC3_Torkoal_Post_1:
# 580 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Torkoal_Post_3:
# 576 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Torkoal_Post_Text_0
	goto TARC3_Torkoal_Post_1


TARC3_Whimsicott::
# 585 "data/maps/TARC3_base/scripts.pory"
	lock
# 586 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 587 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Whimsicott_Text_0
# 589 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_WHIMSICOTT_GAVE_SEED, TARC3_Whimsicott_2
# 595 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Whimsicott_Text_2
# 596 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_WHIMSICOTT, CRY_MODE_NORMAL
# 597 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 598 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 599 "data/maps/TARC3_base/scripts.pory"
	giveitem ITEM_WEPEAR_BERRY, 1
# 600 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_WHIMSICOTT_GAVE_SEED
# 601 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Whimsicott_Text_1
TARC3_Whimsicott_1:
# 603 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Whimsicott_2:
# 591 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Whimsicott_Text_1
	goto TARC3_Whimsicott_1


TARC3_Feebas::
# 608 "data/maps/TARC3_base/scripts.pory"
	lock
# 609 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 610 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Feebas_Text_0
# 612 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_FEEBAS, CRY_MODE_NORMAL
# 613 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Feebas_Text_1
# 614 "data/maps/TARC3_base/scripts.pory"
	release
	end


TARC3_Chatot1::
# 619 "data/maps/TARC3_base/scripts.pory"
	lock
# 620 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 621 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Chatot1_Text_0
# 623 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_CHATOT, CRY_MODE_NORMAL
# 624 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Chatot1_Text_1
# 625 "data/maps/TARC3_base/scripts.pory"
	release
	end


TARC3_Chatot2::
# 630 "data/maps/TARC3_base/scripts.pory"
	lock
# 631 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 632 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Chatot1_Text_0
# 634 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_CHATOT, CRY_MODE_NORMAL
# 635 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Chatot2_Text_0
# 636 "data/maps/TARC3_base/scripts.pory"
	release
	end


TARC3_Audino::
# 641 "data/maps/TARC3_base/scripts.pory"
	lock
# 642 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 643 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Audino_Text_0
# 645 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_AUDINO, CRY_MODE_NORMAL
# 646 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Audino_Text_1
# 647 "data/maps/TARC3_base/scripts.pory"
	release
	end


TARC3_Minccino::
# 652 "data/maps/TARC3_base/scripts.pory"
	lock
# 653 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 654 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Minccino_Text_0
# 656 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_MINCCINO, CRY_MODE_NORMAL
# 657 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Minccino_Text_1
# 658 "data/maps/TARC3_base/scripts.pory"
	release
	end


TARC3_Smeargle::
# 663 "data/maps/TARC3_base/scripts.pory"
	lock
# 664 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 665 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Smeargle_Text_0
# 667 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_SMEARGLE, CRY_MODE_NORMAL
# 668 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Smeargle_Text_1
# 669 "data/maps/TARC3_base/scripts.pory"
	release
	end


TARC3_Nosepass::
# 674 "data/maps/TARC3_base/scripts.pory"
	lock
# 675 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 676 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Nosepass_Text_0
# 678 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_NOSEPASS, CRY_MODE_NORMAL
# 679 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Nosepass_Text_1
# 680 "data/maps/TARC3_base/scripts.pory"
	release
	end


TARC3_Sign_TreeOfLife::
# 685 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Sign_TreeOfLife_Text_0, MSGBOX_SIGN
	end


TARC3_Sign_ApricornTree::
# 690 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Sign_ApricornTree_Text_0, MSGBOX_SIGN
	end


TARC3_Find_IceClimb::
# 695 "data/maps/TARC3_base/scripts.pory"
	finditem ITEM_TM01, 1
	end


TARC3_Dummy_Start_Amber::
# 700 "data/maps/TARC3_base/scripts.pory"
	lockall
# 701 "data/maps/TARC3_base/scripts.pory"
	setvar VAR_CASTFORM_PHASE, 1
# 702 "data/maps/TARC3_base/scripts.pory"
	setvar VAR_TRIGGER_XATU_EVENT, 1
# 703 "data/maps/TARC3_base/scripts.pory"
	finditem ITEM_HEAT_ROCK, 1
# 704 "data/maps/TARC3_base/scripts.pory"
	givemon SPECIES_CASTFORM_SUNNY, 25
# 705 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_ITEM_AMBER_SHARD
# 706 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_RUN_XATU_AMBER
# 707 "data/maps/TARC3_base/scripts.pory"
	releaseall
# 708 "data/maps/TARC3_base/scripts.pory"
	warp MAP_TARC3_WEATHER_INSTITUTE_2F, 9, 8
# 709 "data/maps/TARC3_base/scripts.pory"
	waitstate
	end


# 208 "data/maps/TARC3_base/scripts.pory"
TARC3_Amber_Munchlax_Movement_0:
# 209 "data/maps/TARC3_base/scripts.pory"
	walk_up
# 209 "data/maps/TARC3_base/scripts.pory"
	walk_up
# 210 "data/maps/TARC3_base/scripts.pory"
	face_down
	step_end

TARC3_Base_Paras_Text_0:
# 66 "data/maps/TARC3_base/scripts.pory"
	.string "Paras$"

TARC3_Base_Paras_Text_1:
# 73 "data/maps/TARC3_base/scripts.pory"
	.string "Weather Shards?\nI only heard of fungal spores.\pDoes that help?$"

TARC3_Base_Vulpix_Text_0:
# 97 "data/maps/TARC3_base/scripts.pory"
	.string "Vulpix$"

TARC3_Base_Vulpix_Text_1:
# 104 "data/maps/TARC3_base/scripts.pory"
	.string "I don't care about the weather.\pFor me the sun is always shining!$"

TARC3_Base_Dewpider_Text_0:
# 128 "data/maps/TARC3_base/scripts.pory"
	.string "Dewpider$"

TARC3_Base_Dewpider_Text_1:
# 135 "data/maps/TARC3_base/scripts.pory"
	.string "There is a strange rock at the\nTree of Life.\pIt feels dangerous to the life\nat the pond\pYou must not touch it!$"

TARC3_Base_Wooper_backup_Text_0:
# 158 "data/maps/TARC3_base/scripts.pory"
	.string "Wooper$"

TARC3_Base_Wooper_backup_Text_1:
# 161 "data/maps/TARC3_base/scripts.pory"
	.string "Hey, my berry!$"

TARC3_Base_Wooper_backup_Text_2:
# 165 "data/maps/TARC3_base/scripts.pory"
	.string "Hi, I'm WOOPER.\nLet's battle!$"

TARC3_Amber_Munchlax_Text_0:
# 198 "data/maps/TARC3_base/scripts.pory"
	.string "Munchlax$"

TARC3_Amber_Munchlax_Text_1:
# 207 "data/maps/TARC3_base/scripts.pory"
	.string "It's too hot to battle!$"

TARC3_Amber_Munchlax_Text_2:
# 218 "data/maps/TARC3_base/scripts.pory"
	.string "Do you have some berries for me?\nI am hungry!$"

TARC3_Amber_Combusken_Text_0:
# 242 "data/maps/TARC3_base/scripts.pory"
	.string "Combusken$"

TARC3_Amber_Combusken_Text_1:
# 250 "data/maps/TARC3_base/scripts.pory"
	.string "What are you doing here\nin my territory?\pYou think you can handle me?\nThe sun is on my side, too!$"

TARC3_Amber_Observer_Text_0:
# 273 "data/maps/TARC3_base/scripts.pory"
	.string "Fomantis$"

TARC3_Amber_Observer_Text_1:
# 277 "data/maps/TARC3_base/scripts.pory"
	.string "We're cool again!$"

TARC3_Amber_Observer_Text_2:
# 281 "data/maps/TARC3_base/scripts.pory"
	.string "This HELIOPTILE is so mean!\pCan you help me scaring it away?$"

TARC3_Amber_Observer_Text_3:
# 291 "data/maps/TARC3_base/scripts.pory"
	.string "Thank you for helping me!$"

TARC3_Amber_Torkoal_Text_0:
# 311 "data/maps/TARC3_base/scripts.pory"
	.string "Torkoal$"

TARC3_Amber_Torkoal_Text_1:
# 319 "data/maps/TARC3_base/scripts.pory"
	.string "Who dares to bother me during my nap?\p...\pAre you after that stone?\pYou cannot have it, it's dangerous!\nIt will turn the world into endless rain!$"

TARC3_Amber_Torkoal_Text_2:
# 332 "data/maps/TARC3_base/scripts.pory"
	.string "Defeated. Like it was nothing.\pMaybe you are able to save us\nfrom the chaos!\pHere, I found it behind the lava pool!$"

TARC3_Azure_Toxicroak_Text_0:
# 353 "data/maps/TARC3_base/scripts.pory"
	.string "Toxicroak$"

TARC3_Azure_Toxicroak_Text_1:
# 358 "data/maps/TARC3_base/scripts.pory"
	.string "I still like you!$"

TARC3_Azure_Toxicroak_Text_2:
# 362 "data/maps/TARC3_base/scripts.pory"
	.string "Hi, I'm TOXICROAK.\nLet's battle!$"

TARC3_Azure_Gastrodon_Text_0:
# 384 "data/maps/TARC3_base/scripts.pory"
	.string "Gastrodon$"

TARC3_Azure_Gastrodon_Text_1:
# 393 "data/maps/TARC3_base/scripts.pory"
	.string "Hi, I'm GASTRODON.\nLet's battle!$"

TARC3_Azure_Observer_Text_0:
# 415 "data/maps/TARC3_base/scripts.pory"
	.string "Drampa$"

TARC3_Azure_Observer_Text_1:
# 424 "data/maps/TARC3_base/scripts.pory"
	.string "Hi, I'm DRAMPA.\nPlease help me!$"

TARC3_Azure_Flygon_Text_0:
# 445 "data/maps/TARC3_base/scripts.pory"
	.string "Flygon$"

TARC3_Azure_Flygon_Text_1:
# 454 "data/maps/TARC3_base/scripts.pory"
	.string "Hi, I'm FLYGON.\nLet's battle!$"

TARC3_Paras_Post_Text_0:
# 480 "data/maps/TARC3_base/scripts.pory"
	.string "I am enjoying the warmth!\pJust keep any Fire Types away!$"

TARC3_Paras_Post_Text_1:
# 483 "data/maps/TARC3_base/scripts.pory"
	.string "What's this weather?\pThis is miserable, I can't stand it!$"

TARC3_Paras_Post_Text_2:
# 486 "data/maps/TARC3_base/scripts.pory"
	.string "You can make it sunny?\pI am rooting for you!$"

TARC3_Surskit_Text_0:
# 496 "data/maps/TARC3_base/scripts.pory"
	.string "Surskit$"

TARC3_Surskit_Text_1:
# 501 "data/maps/TARC3_base/scripts.pory"
	.string "My pond!\nWhere did it go???$"

TARC3_Surskit_Text_2:
# 503 "data/maps/TARC3_base/scripts.pory"
	.string "You made this rain?\pI LOVE IT!\nPlease never make it stop.$"

TARC3_Surskit_Text_3:
# 507 "data/maps/TARC3_base/scripts.pory"
	.string "The weather has been crazy lately!\pI hope it calms down soon.$"

TARC3_Vulpix_Post_Text_0:
# 520 "data/maps/TARC3_base/scripts.pory"
	.string "You transformed and even\nchanged your moveset?\pThat is so cool!\nHow did you do that?$"

TARC3_Dewpider_Post_Text_0:
# 533 "data/maps/TARC3_base/scripts.pory"
	.string "What did you do???\pWhere did my home go???$"

TARC3_Dewpider_Post_Text_1:
# 535 "data/maps/TARC3_base/scripts.pory"
	.string "Please be careful!$"

TARC3_Munchlax_Post_Text_0:
# 548 "data/maps/TARC3_base/scripts.pory"
	.string "I heard there is a mysterious\nobject on top of the mountain.\pThey say it can make it rain.\pAnd rain makes berries grow\nYummy!$"

TARC3_Combusken_Post_Text_0:
# 561 "data/maps/TARC3_base/scripts.pory"
	.string "Now this is unfair!$"

TARC3_Combusken_Post_Text_1:
# 563 "data/maps/TARC3_base/scripts.pory"
	.string "I clearly should have won!$"

TARC3_Torkoal_Post_Text_0:
# 576 "data/maps/TARC3_base/scripts.pory"
	.string "Woah! I didn't know you could\nturn the lava into stone!$"

TARC3_Torkoal_Post_Text_1:
# 578 "data/maps/TARC3_base/scripts.pory"
	.string "Please help us bring back normality!$"

TARC3_Whimsicott_Text_0:
# 587 "data/maps/TARC3_base/scripts.pory"
	.string "Whimsicott$"

TARC3_Whimsicott_Text_1:
# 591 "data/maps/TARC3_base/scripts.pory"
	.string "When you plant and water it,\nit will grow!\pBut don't expect much from these\nApricorn trees.\lThey haven't changed in ages.$"

TARC3_Whimsicott_Text_2:
# 595 "data/maps/TARC3_base/scripts.pory"
	.string "Hi there, glad you found me!\pMy name is Whimsicott and\nI am the gardener of this town.\pHere, you can have a seed, too.$"

TARC3_Feebas_Text_0:
# 610 "data/maps/TARC3_base/scripts.pory"
	.string "Feebas$"

TARC3_Feebas_Text_1:
# 613 "data/maps/TARC3_base/scripts.pory"
	.string "If you ever get stuck,\nswim on the river and\lswitch to your Base form.\pThis will respawn you in front\nof the institute.$"

TARC3_Chatot1_Text_0:
# 621 "data/maps/TARC3_base/scripts.pory"
	.string "Chatot$"

TARC3_Chatot1_Text_1:
# 624 "data/maps/TARC3_base/scripts.pory"
	.string "Have you met Whimsicott, yet?\pShe is really friendly and\nprovides the town with crops.$"

TARC3_Chatot2_Text_0:
# 635 "data/maps/TARC3_base/scripts.pory"
	.string "Remember, if you get stuck,\nswim on the river and\lswitch to your Base form.\pRIP$"

TARC3_Audino_Text_0:
# 643 "data/maps/TARC3_base/scripts.pory"
	.string "Audino$"

TARC3_Audino_Text_1:
# 646 "data/maps/TARC3_base/scripts.pory"
	.string "Isn't our town pretty?$"

TARC3_Minccino_Text_0:
# 654 "data/maps/TARC3_base/scripts.pory"
	.string "Minccino$"

TARC3_Minccino_Text_1:
# 657 "data/maps/TARC3_base/scripts.pory"
	.string "The top of the volcano is hard\nto reach.\pI tried it before, but it was\ntoo steep and slippery.$"

TARC3_Smeargle_Text_0:
# 665 "data/maps/TARC3_base/scripts.pory"
	.string "Smeargle$"

TARC3_Smeargle_Text_1:
# 668 "data/maps/TARC3_base/scripts.pory"
	.string "Did you notice the palette changes\nduring sunny weather?\pThat's me recoloring everything\nin an instant!$"

TARC3_Nosepass_Text_0:
# 676 "data/maps/TARC3_base/scripts.pory"
	.string "Nosepass$"

TARC3_Nosepass_Text_1:
# 679 "data/maps/TARC3_base/scripts.pory"
	.string "I tried this shortcut, but it didn't work out.$"

TARC3_Sign_TreeOfLife_Text_0:
# 685 "data/maps/TARC3_base/scripts.pory"
	.string "Tree of Life\pOnly Arceus may enter.$"

TARC3_Sign_ApricornTree_Text_0:
# 690 "data/maps/TARC3_base/scripts.pory"
	.string "An Apricorn Tree blocks\nthe entrance.\pPost game area.$"
