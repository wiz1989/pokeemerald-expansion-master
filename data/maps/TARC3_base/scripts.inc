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
# 29 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM, TARC3_Base_OnResume_6
TARC3_Base_OnResume_6:
# 31 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_HIDE_ITEM_UNDERWATER
# 32 "data/maps/TARC3_base/scripts.pory"
	clearflag FLAG_LAPRAS1_SOURCE_INVISIBLE
# 33 "data/maps/TARC3_base/scripts.pory"
	clearflag FLAG_LAPRAS2_SOURCE_INVISIBLE
# 34 "data/maps/TARC3_base/scripts.pory"
	clearflag FLAG_LAPRAS1_DEST_INVISIBLE
# 35 "data/maps/TARC3_base/scripts.pory"
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
	clearflag FLAG_HIDE_ITEM_UNDERWATER
# 25 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_LAPRAS1_SOURCE_INVISIBLE
# 26 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_LAPRAS2_SOURCE_INVISIBLE
# 27 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_LAPRAS1_DEST_INVISIBLE
# 28 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_LAPRAS2_DEST_INVISIBLE
	goto TARC3_Base_OnResume_1


TARC3_Base_Sunkern::
# 43 "data/maps/TARC3_base/scripts.pory"
	goto TARC3_Base_Paras
	return


TARC3_Base_Wooper::
# 47 "data/maps/TARC3_base/scripts.pory"
	goto TARC3_Base_Dewpider
	return


TARC3_Base_Torkoal::
# 51 "data/maps/TARC3_base/scripts.pory"
	goto TARC3_Amber_Torkoal
	return


TARC3_Base_Paras::
# 58 "data/maps/TARC3_base/scripts.pory"
	cant_see_if_set FLAG_BASE_PARAS_BEATEN
# 59 "data/maps/TARC3_base/scripts.pory"
	lock
# 60 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 62 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_START
# 64 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Base_Paras_Text_0
# 65 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_PARAS_BEATEN, TARC3_Base_Paras_2
# 71 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Base_Paras_Text_1
# 72 "data/maps/TARC3_base/scripts.pory"
	setwildbattle SPECIES_PARAS, 25
# 73 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_PARAS, CRY_MODE_ENCOUNTER
# 74 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 75 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 76 "data/maps/TARC3_base/scripts.pory"
	dowildbattle
# 77 "data/maps/TARC3_base/scripts.pory"
	callnative WasBattleWon
# 78 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Base_Paras_5
TARC3_Base_Paras_1:
# 84 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Base_Paras_2:
# 67 "data/maps/TARC3_base/scripts.pory"
	goto TARC3_Paras_Post
	goto TARC3_Base_Paras_1

TARC3_Base_Paras_5:
# 80 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_BASE_PARAS_BEATEN
# 81 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_START
	goto TARC3_Base_Paras_1


TARC3_Base_Vulpix::
# 89 "data/maps/TARC3_base/scripts.pory"
	cant_see_if_set FLAG_BASE_VULPIX_BEATEN
# 90 "data/maps/TARC3_base/scripts.pory"
	lock
# 91 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 93 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_VULPIX
# 95 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Base_Vulpix_Text_0
# 96 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_VULPIX_BEATEN, TARC3_Base_Vulpix_2
# 102 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Base_Vulpix_Text_1
# 103 "data/maps/TARC3_base/scripts.pory"
	setwildbattle SPECIES_VULPIX, 25
# 104 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_VULPIX, CRY_MODE_ENCOUNTER
# 105 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 106 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 107 "data/maps/TARC3_base/scripts.pory"
	dowildbattle
# 108 "data/maps/TARC3_base/scripts.pory"
	callnative WasBattleWon
# 109 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Base_Vulpix_5
TARC3_Base_Vulpix_1:
# 115 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Base_Vulpix_2:
# 98 "data/maps/TARC3_base/scripts.pory"
	goto TARC3_Vulpix_Post
	goto TARC3_Base_Vulpix_1

TARC3_Base_Vulpix_5:
# 111 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_BASE_VULPIX_BEATEN
# 112 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_START
	goto TARC3_Base_Vulpix_1


TARC3_Base_Dewpider::
# 120 "data/maps/TARC3_base/scripts.pory"
	cant_see_if_set FLAG_BASE_DEWPIDER_BEATEN
# 121 "data/maps/TARC3_base/scripts.pory"
	lock
# 122 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_DEWPIDER
# 123 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 126 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Base_Dewpider_Text_0
# 127 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_DEWPIDER_BEATEN, TARC3_Base_Dewpider_2
# 133 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Base_Dewpider_Text_1
# 134 "data/maps/TARC3_base/scripts.pory"
	setwildbattle SPECIES_DEWPIDER, 25
# 135 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_DEWPIDER, CRY_MODE_ENCOUNTER
# 136 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 137 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 138 "data/maps/TARC3_base/scripts.pory"
	dowildbattle
# 139 "data/maps/TARC3_base/scripts.pory"
	callnative WasBattleWon
# 140 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Base_Dewpider_5
TARC3_Base_Dewpider_1:
# 146 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Base_Dewpider_2:
# 129 "data/maps/TARC3_base/scripts.pory"
	goto TARC3_Dewpider_Post
	goto TARC3_Base_Dewpider_1

TARC3_Base_Dewpider_5:
# 142 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_BASE_DEWPIDER_BEATEN
# 143 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_START
	goto TARC3_Base_Dewpider_1


TARC3_Base_Wooper_backup::
# 151 "data/maps/TARC3_base/scripts.pory"
	cant_see_if_set FLAG_BASE_WOOPER_BEATEN
# 152 "data/maps/TARC3_base/scripts.pory"
	lock
# 153 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 156 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Base_Wooper_backup_Text_0
# 157 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_WOOPER_BEATEN, TARC3_Base_Wooper_backup_2
# 163 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Base_Wooper_backup_Text_2
# 164 "data/maps/TARC3_base/scripts.pory"
	setwildbattle SPECIES_WOOPER, 25
# 165 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_WOOPER, CRY_MODE_ENCOUNTER
# 166 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 167 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 168 "data/maps/TARC3_base/scripts.pory"
	dowildbattle
# 169 "data/maps/TARC3_base/scripts.pory"
	callnative WasBattleWon
# 170 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Base_Wooper_backup_5
TARC3_Base_Wooper_backup_1:
# 176 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Base_Wooper_backup_2:
# 159 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Base_Wooper_backup_Text_1
	goto TARC3_Base_Wooper_backup_1

TARC3_Base_Wooper_backup_5:
# 172 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_BASE_WOOPER_BEATEN
# 173 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_START
	goto TARC3_Base_Wooper_backup_1


TARC3_Amber_Munchlax::
# 182 "data/maps/TARC3_base/scripts.pory"
	cant_see_if_set FLAG_BASE_MUNCHLAX_BEATEN
# 183 "data/maps/TARC3_base/scripts.pory"
	lock
# 184 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 186 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_MUNCHLAX
# 188 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Amber_Munchlax_Text_0
# 189 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_MUNCHLAX_BEATEN, TARC3_Amber_Munchlax_2
# 195 "data/maps/TARC3_base/scripts.pory"
	compare VAR_TRANSFORM_MON, SPECIES_CASTFORM_SUNNY
	goto_if_eq TARC3_Amber_Munchlax_5
# 203 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Amber_Munchlax_Text_3
# 204 "data/maps/TARC3_base/scripts.pory"
	setwildbattle SPECIES_MUNCHLAX, 25
# 205 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_MUNCHLAX, CRY_MODE_ENCOUNTER
# 206 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 207 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 208 "data/maps/TARC3_base/scripts.pory"
	dowildbattle
# 209 "data/maps/TARC3_base/scripts.pory"
	callnative WasBattleWon
# 210 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Amber_Munchlax_8
TARC3_Amber_Munchlax_1:
# 217 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Amber_Munchlax_2:
# 191 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Amber_Munchlax_Text_1
	goto TARC3_Amber_Munchlax_1

TARC3_Amber_Munchlax_5:
# 197 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Amber_Munchlax_Text_2
# 198 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Amber_Munchlax_8:
# 212 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_BASE_MUNCHLAX_BEATEN
# 213 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_START
	goto TARC3_Amber_Munchlax_1


TARC3_Amber_Combusken::
# 222 "data/maps/TARC3_base/scripts.pory"
	cant_see_if_set FLAG_BASE_COMBUSKEN_BEATEN
# 223 "data/maps/TARC3_base/scripts.pory"
	lock
# 224 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 226 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_COMBUSKEN
# 227 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Amber_Combusken_Text_0
# 229 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_COMBUSKEN_BEATEN, TARC3_Amber_Combusken_2
# 235 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Amber_Combusken_Text_1
# 236 "data/maps/TARC3_base/scripts.pory"
	setwildbattle SPECIES_COMBUSKEN, 25
# 237 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_COMBUSKEN, CRY_MODE_ENCOUNTER
# 238 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 239 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 240 "data/maps/TARC3_base/scripts.pory"
	dowildbattle
# 241 "data/maps/TARC3_base/scripts.pory"
	callnative WasBattleWon
# 242 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Amber_Combusken_5
TARC3_Amber_Combusken_1:
# 248 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Amber_Combusken_2:
# 231 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Amber_Munchlax_Text_1
	goto TARC3_Amber_Combusken_1

TARC3_Amber_Combusken_5:
# 244 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_BASE_COMBUSKEN_BEATEN
# 245 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_START
	goto TARC3_Amber_Combusken_1


TARC3_Amber_Observer::
# 253 "data/maps/TARC3_base/scripts.pory"
	cant_see_if_set FLAG_BASE_HELIOPTILE_BEATEN
# 254 "data/maps/TARC3_base/scripts.pory"
	lock
# 255 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 257 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_HELIOPTILE
# 258 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Amber_Observer_Text_0
# 260 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_HELIOPTILE_BEATEN, TARC3_Amber_Observer_2
# 266 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Amber_Observer_Text_2
# 267 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_HELIOPTILE, CRY_MODE_ENCOUNTER
# 268 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 269 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 270 "data/maps/TARC3_base/scripts.pory"
	ai_vs_ai_wild_battle SPECIES_FOMANTIS, SPECIES_HELIOPTILE, 25
# 271 "data/maps/TARC3_base/scripts.pory"
	callnative WasBattleWon
# 272 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Amber_Observer_5
TARC3_Amber_Observer_1:
# 278 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Amber_Observer_2:
# 262 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Amber_Observer_Text_1
	goto TARC3_Amber_Observer_1

TARC3_Amber_Observer_5:
# 274 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_BASE_HELIOPTILE_BEATEN
# 275 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_START
	goto TARC3_Amber_Observer_1


TARC3_Amber_Torkoal::
# 283 "data/maps/TARC3_base/scripts.pory"
	cant_see_if_set FLAG_BASE_TORKOAL_BEATEN
# 284 "data/maps/TARC3_base/scripts.pory"
	lock
# 285 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 287 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_TORKOAL
# 288 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Amber_Torkoal_Text_0
# 290 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_TORKOAL_BEATEN, TARC3_Amber_Torkoal_2
# 296 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Amber_Torkoal_Text_1
# 297 "data/maps/TARC3_base/scripts.pory"
	setwildbattle SPECIES_TORKOAL, 25
# 298 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_TORKOAL, CRY_MODE_ENCOUNTER
# 299 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 300 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 301 "data/maps/TARC3_base/scripts.pory"
	dowildbattle
# 302 "data/maps/TARC3_base/scripts.pory"
	callnative WasBattleWon
# 303 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Amber_Torkoal_5
TARC3_Amber_Torkoal_1:
# 309 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Amber_Torkoal_2:
# 292 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Amber_Munchlax_Text_1
	goto TARC3_Amber_Torkoal_1

TARC3_Amber_Torkoal_5:
# 305 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_BASE_TORKOAL_BEATEN
# 306 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_START
	goto TARC3_Amber_Torkoal_1


TARC3_Azure_Toxicroak::
# 314 "data/maps/TARC3_base/scripts.pory"
	cant_see_if_set FLAG_BASE_TOXICROAK_BEATEN
# 315 "data/maps/TARC3_base/scripts.pory"
	lock
# 316 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 318 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Azure_Toxicroak_Text_0
# 319 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_TOXICROAK
# 321 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_TOXICROAK_BEATEN, TARC3_Azure_Toxicroak_2
# 327 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Azure_Toxicroak_Text_1
# 328 "data/maps/TARC3_base/scripts.pory"
	setwildbattle SPECIES_TOXICROAK, 25
# 329 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_TOXICROAK, CRY_MODE_ENCOUNTER
# 330 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 331 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 332 "data/maps/TARC3_base/scripts.pory"
	dowildbattle
# 333 "data/maps/TARC3_base/scripts.pory"
	callnative WasBattleWon
# 334 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Azure_Toxicroak_5
TARC3_Azure_Toxicroak_1:
# 340 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Azure_Toxicroak_2:
# 323 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Amber_Munchlax_Text_1
	goto TARC3_Azure_Toxicroak_1

TARC3_Azure_Toxicroak_5:
# 336 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_BASE_TOXICROAK_BEATEN
# 337 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_START
	goto TARC3_Azure_Toxicroak_1


TARC3_Azure_Gastrodon::
# 345 "data/maps/TARC3_base/scripts.pory"
	cant_see_if_set FLAG_BASE_GASTRODON_BEATEN
# 346 "data/maps/TARC3_base/scripts.pory"
	lock
# 347 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 349 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Azure_Gastrodon_Text_0
# 350 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_GASTRODON
# 352 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_GASTRODON_BEATEN, TARC3_Azure_Gastrodon_2
# 358 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Azure_Gastrodon_Text_1
# 359 "data/maps/TARC3_base/scripts.pory"
	setwildbattle SPECIES_GASTRODON, 25
# 360 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_GASTRODON, CRY_MODE_ENCOUNTER
# 361 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 362 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 363 "data/maps/TARC3_base/scripts.pory"
	dowildbattle
# 364 "data/maps/TARC3_base/scripts.pory"
	callnative WasBattleWon
# 365 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Azure_Gastrodon_5
TARC3_Azure_Gastrodon_1:
# 371 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Azure_Gastrodon_2:
# 354 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Amber_Munchlax_Text_1
	goto TARC3_Azure_Gastrodon_1

TARC3_Azure_Gastrodon_5:
# 367 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_BASE_GASTRODON_BEATEN
# 368 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_START
	goto TARC3_Azure_Gastrodon_1


TARC3_Azure_Observer::
# 376 "data/maps/TARC3_base/scripts.pory"
	cant_see_if_set FLAG_BASE_SLOWKING_BEATEN
# 377 "data/maps/TARC3_base/scripts.pory"
	lock
# 378 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 380 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Azure_Observer_Text_0
# 381 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_SLOWKING
# 383 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_SLOWKING_BEATEN, TARC3_Azure_Observer_2
# 389 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Azure_Observer_Text_1
# 390 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_SLOWKING, CRY_MODE_ENCOUNTER
# 391 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 392 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 393 "data/maps/TARC3_base/scripts.pory"
	ai_vs_ai_wild_battle SPECIES_DRAMPA, SPECIES_SLOWKING, 25
# 394 "data/maps/TARC3_base/scripts.pory"
	callnative WasBattleWon
# 395 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Azure_Observer_5
TARC3_Azure_Observer_1:
# 401 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Azure_Observer_2:
# 385 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Amber_Observer_Text_1
	goto TARC3_Azure_Observer_1

TARC3_Azure_Observer_5:
# 397 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_BASE_SLOWKING_BEATEN
# 398 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_START
	goto TARC3_Azure_Observer_1


TARC3_Azure_Flygon::
# 406 "data/maps/TARC3_base/scripts.pory"
	cant_see_if_set FLAG_BASE_FLYGON_BEATEN
# 407 "data/maps/TARC3_base/scripts.pory"
	lock
# 408 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 410 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Azure_Flygon_Text_0
# 411 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_FLYGON
# 413 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_FLYGON_BEATEN, TARC3_Azure_Flygon_2
# 419 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Azure_Flygon_Text_1
# 420 "data/maps/TARC3_base/scripts.pory"
	setwildbattle SPECIES_FLYGON, 25
# 421 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_FLYGON, CRY_MODE_ENCOUNTER
# 422 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 423 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 424 "data/maps/TARC3_base/scripts.pory"
	dowildbattle
# 425 "data/maps/TARC3_base/scripts.pory"
	callnative WasBattleWon
# 426 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Azure_Flygon_5
TARC3_Azure_Flygon_1:
# 432 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Azure_Flygon_2:
# 415 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Amber_Munchlax_Text_1
	goto TARC3_Azure_Flygon_1

TARC3_Azure_Flygon_5:
# 428 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_BASE_FLYGON_BEATEN
# 429 "data/maps/TARC3_base/scripts.pory"
	setrespawn HEAL_LOCATION_TARC3_START
	goto TARC3_Azure_Flygon_1


TARC3_Paras_Post::
# 439 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_SURSKIT, CRY_MODE_NORMAL
# 441 "data/maps/TARC3_base/scripts.pory"
	callnative GetCurrentTransformationSpecies
# 442 "data/maps/TARC3_base/scripts.pory"
	switch VAR_RESULT
# 444 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_SUNNY, TARC3_Paras_Post_3
# 446 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_RAINY, TARC3_Paras_Post_4
# 447 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_SNOWY, TARC3_Paras_Post_4
# 449 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM, TARC3_Paras_Post_5
TARC3_Paras_Post_5:
# 451 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Paras_Post_Text_2
TARC3_Paras_Post_1:
# 453 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Paras_Post_3:
# 445 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Paras_Post_Text_0
	goto TARC3_Paras_Post_1

TARC3_Paras_Post_4:
# 448 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Paras_Post_Text_1
	goto TARC3_Paras_Post_1


TARC3_Surskit::
# 458 "data/maps/TARC3_base/scripts.pory"
	lock
# 459 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 460 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_SURSKIT, CRY_MODE_NORMAL
# 461 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Surskit_Text_0
# 462 "data/maps/TARC3_base/scripts.pory"
	callnative GetCurrentTransformationSpecies
# 463 "data/maps/TARC3_base/scripts.pory"
	switch VAR_RESULT
# 465 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_SUNNY, TARC3_Surskit_3
# 467 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_RAINY, TARC3_Surskit_4
# 469 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_SNOWY, TARC3_Surskit_5
# 470 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM, TARC3_Surskit_5
TARC3_Surskit_5:
# 472 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Surskit_Text_3
TARC3_Surskit_1:
# 474 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Surskit_3:
# 466 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Surskit_Text_1
	goto TARC3_Surskit_1

TARC3_Surskit_4:
# 468 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Surskit_Text_2
	goto TARC3_Surskit_1


TARC3_Vulpix_Post::
# 479 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_VULPIX, CRY_MODE_NORMAL
# 481 "data/maps/TARC3_base/scripts.pory"
	callnative GetCurrentTransformationSpecies
# 482 "data/maps/TARC3_base/scripts.pory"
	switch VAR_RESULT
# 485 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Vulpix_Post_Text_0
# 487 "data/maps/TARC3_base/scripts.pory"
	release
	end


TARC3_Dewpider_Post::
# 492 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_DEWPIDER, CRY_MODE_NORMAL
# 494 "data/maps/TARC3_base/scripts.pory"
	callnative GetCurrentTransformationSpecies
# 495 "data/maps/TARC3_base/scripts.pory"
	switch VAR_RESULT
# 497 "data/maps/TARC3_base/scripts.pory"
	case SPECIES_CASTFORM_SUNNY, TARC3_Dewpider_Post_3
# 500 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Dewpider_Post_Text_1
TARC3_Dewpider_Post_1:
# 502 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Dewpider_Post_3:
# 498 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Dewpider_Post_Text_0
	goto TARC3_Dewpider_Post_1


TARC3_Whimsicott::
# 507 "data/maps/TARC3_base/scripts.pory"
	lock
# 508 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 509 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Whimsicott_Text_0
# 511 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_WHIMSICOTT_GAVE_SEED, TARC3_Whimsicott_2
# 517 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Whimsicott_Text_2
# 518 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_WHIMSICOTT, CRY_MODE_NORMAL
# 519 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 520 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 521 "data/maps/TARC3_base/scripts.pory"
	giveitem ITEM_WEPEAR_BERRY, 1
# 522 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_WHIMSICOTT_GAVE_SEED
# 523 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Whimsicott_Text_1
TARC3_Whimsicott_1:
# 525 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Whimsicott_2:
# 513 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Whimsicott_Text_1
	goto TARC3_Whimsicott_1


TARC3_Sign_TreeOfLife::
# 530 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Sign_TreeOfLife_Text_0, MSGBOX_SIGN
	end


TARC3_Sign_ApricornTree::
# 535 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Sign_ApricornTree_Text_0, MSGBOX_SIGN
	end


TARC3_Find_IceClimb::
# 540 "data/maps/TARC3_base/scripts.pory"
	finditem ITEM_TM01, 1
	end


TARC3_Dummy_Start_Amber::
# 545 "data/maps/TARC3_base/scripts.pory"
	lockall
# 546 "data/maps/TARC3_base/scripts.pory"
	setvar VAR_CASTFORM_PHASE, 1
# 547 "data/maps/TARC3_base/scripts.pory"
	setvar VAR_TRIGGER_XATU_EVENT, 1
# 548 "data/maps/TARC3_base/scripts.pory"
	finditem ITEM_HEAT_ROCK, 1
# 549 "data/maps/TARC3_base/scripts.pory"
	givemon SPECIES_CASTFORM_SUNNY, 25
# 550 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_ITEM_AMBER_SHARD
# 551 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_RUN_XATU_AMBER
# 552 "data/maps/TARC3_base/scripts.pory"
	releaseall
# 553 "data/maps/TARC3_base/scripts.pory"
	warp MAP_TARC3_WEATHER_INSTITUTE_2F, 9, 8
# 554 "data/maps/TARC3_base/scripts.pory"
	waitstate
	end


TARC3_Base_Paras_Text_0:
# 64 "data/maps/TARC3_base/scripts.pory"
	.string "Paras$"

TARC3_Base_Paras_Text_1:
# 71 "data/maps/TARC3_base/scripts.pory"
	.string "Weather Shards?\nI only heard of fungal spores.\pDoes that help?$"

TARC3_Base_Vulpix_Text_0:
# 95 "data/maps/TARC3_base/scripts.pory"
	.string "Vulpix$"

TARC3_Base_Vulpix_Text_1:
# 102 "data/maps/TARC3_base/scripts.pory"
	.string "I don't care about the weather.\pFor me the sun is always shining!$"

TARC3_Base_Dewpider_Text_0:
# 126 "data/maps/TARC3_base/scripts.pory"
	.string "Dewpider$"

TARC3_Base_Dewpider_Text_1:
# 133 "data/maps/TARC3_base/scripts.pory"
	.string "There is a strange rock at the\nTree of Life.\pIt feels dangerous to the life\nat the pond\pYou must not touch it!$"

TARC3_Base_Wooper_backup_Text_0:
# 156 "data/maps/TARC3_base/scripts.pory"
	.string "Wooper$"

TARC3_Base_Wooper_backup_Text_1:
# 159 "data/maps/TARC3_base/scripts.pory"
	.string "Hey, my berry!$"

TARC3_Base_Wooper_backup_Text_2:
# 163 "data/maps/TARC3_base/scripts.pory"
	.string "Hi, I'm WOOPER.\nLet's battle!$"

TARC3_Amber_Munchlax_Text_0:
# 188 "data/maps/TARC3_base/scripts.pory"
	.string "Munchlax$"

TARC3_Amber_Munchlax_Text_1:
# 191 "data/maps/TARC3_base/scripts.pory"
	.string "I still like you!$"

TARC3_Amber_Munchlax_Text_2:
# 197 "data/maps/TARC3_base/scripts.pory"
	.string "It's too hot to battle!$"

TARC3_Amber_Munchlax_Text_3:
# 203 "data/maps/TARC3_base/scripts.pory"
	.string "Hi, I'm MUNCHLAX.\nLet's battle!$"

TARC3_Amber_Combusken_Text_0:
# 227 "data/maps/TARC3_base/scripts.pory"
	.string "Combusken$"

TARC3_Amber_Combusken_Text_1:
# 235 "data/maps/TARC3_base/scripts.pory"
	.string "Hi, I'm COMBUSKEN.\nLet's battle!$"

TARC3_Amber_Observer_Text_0:
# 258 "data/maps/TARC3_base/scripts.pory"
	.string "Helioptile$"

TARC3_Amber_Observer_Text_1:
# 262 "data/maps/TARC3_base/scripts.pory"
	.string "We're cool again!$"

TARC3_Amber_Observer_Text_2:
# 266 "data/maps/TARC3_base/scripts.pory"
	.string "Hi, I'm HELIOPTILE.\nLet's battle!$"

TARC3_Amber_Torkoal_Text_0:
# 288 "data/maps/TARC3_base/scripts.pory"
	.string "Torkoal$"

TARC3_Amber_Torkoal_Text_1:
# 296 "data/maps/TARC3_base/scripts.pory"
	.string "Hi, I'm TORKOAL.\nLet's battle!$"

TARC3_Azure_Toxicroak_Text_0:
# 318 "data/maps/TARC3_base/scripts.pory"
	.string "Toxicroak$"

TARC3_Azure_Toxicroak_Text_1:
# 327 "data/maps/TARC3_base/scripts.pory"
	.string "Hi, I'm TOXICROAK.\nLet's battle!$"

TARC3_Azure_Gastrodon_Text_0:
# 349 "data/maps/TARC3_base/scripts.pory"
	.string "Gastrodon$"

TARC3_Azure_Gastrodon_Text_1:
# 358 "data/maps/TARC3_base/scripts.pory"
	.string "Hi, I'm GASTRODON.\nLet's battle!$"

TARC3_Azure_Observer_Text_0:
# 380 "data/maps/TARC3_base/scripts.pory"
	.string "Drampa$"

TARC3_Azure_Observer_Text_1:
# 389 "data/maps/TARC3_base/scripts.pory"
	.string "Hi, I'm DRAMPA.\nPlease help me!$"

TARC3_Azure_Flygon_Text_0:
# 410 "data/maps/TARC3_base/scripts.pory"
	.string "Flygon$"

TARC3_Azure_Flygon_Text_1:
# 419 "data/maps/TARC3_base/scripts.pory"
	.string "Hi, I'm FLYGON.\nLet's battle!$"

TARC3_Paras_Post_Text_0:
# 445 "data/maps/TARC3_base/scripts.pory"
	.string "I am enjoying the warmth!\pJust keep any Fire Types away!$"

TARC3_Paras_Post_Text_1:
# 448 "data/maps/TARC3_base/scripts.pory"
	.string "What's this weather?\pThis is miserable, I can't stand it!$"

TARC3_Paras_Post_Text_2:
# 451 "data/maps/TARC3_base/scripts.pory"
	.string "You can make it sunny?\pI am rooting for you!$"

TARC3_Surskit_Text_0:
# 461 "data/maps/TARC3_base/scripts.pory"
	.string "Surskit$"

TARC3_Surskit_Text_1:
# 466 "data/maps/TARC3_base/scripts.pory"
	.string "My pond!\nWhere did it go???$"

TARC3_Surskit_Text_2:
# 468 "data/maps/TARC3_base/scripts.pory"
	.string "You made this rain?\pI LOVE IT!\nPlease never make it stop.$"

TARC3_Surskit_Text_3:
# 472 "data/maps/TARC3_base/scripts.pory"
	.string "The weather has been crazy lately!\pI hope it calms down soon.$"

TARC3_Vulpix_Post_Text_0:
# 485 "data/maps/TARC3_base/scripts.pory"
	.string "You transformed and even\nchanged your moveset?\pThat is so cool!\nHow did you do that?$"

TARC3_Dewpider_Post_Text_0:
# 498 "data/maps/TARC3_base/scripts.pory"
	.string "What did you do???\pWhere did my home go???$"

TARC3_Dewpider_Post_Text_1:
# 500 "data/maps/TARC3_base/scripts.pory"
	.string "Please be careful!$"

TARC3_Whimsicott_Text_0:
# 509 "data/maps/TARC3_base/scripts.pory"
	.string "Whimsicott$"

TARC3_Whimsicott_Text_1:
# 513 "data/maps/TARC3_base/scripts.pory"
	.string "When you plant and water it,\nit will grow!$"

TARC3_Whimsicott_Text_2:
# 517 "data/maps/TARC3_base/scripts.pory"
	.string "Hi, I'm WHIMSICOTT.\nTake this seed!$"

TARC3_Sign_TreeOfLife_Text_0:
# 530 "data/maps/TARC3_base/scripts.pory"
	.string "Tree of Life\pOnly Arceus may enter.$"

TARC3_Sign_ApricornTree_Text_0:
# 535 "data/maps/TARC3_base/scripts.pory"
	.string "An Apricorn Tree blocks\nthe entrance.\pPost game area.$"
