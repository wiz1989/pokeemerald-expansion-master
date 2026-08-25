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
	goto TARC3_Base_Paras
	return


TARC3_Base_Wooper::
# 17 "data/maps/TARC3_base/scripts.pory"
	goto TARC3_Base_Dewpider
	return


TARC3_Base_Torkoal::
# 21 "data/maps/TARC3_base/scripts.pory"
	goto TARC3_Amber_Torkoal
	return


TARC3_Base_Paras::
# 28 "data/maps/TARC3_base/scripts.pory"
	cant_see_if_set FLAG_BASE_PARAS_BEATEN
# 29 "data/maps/TARC3_base/scripts.pory"
	lock
# 30 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 31 "data/maps/TARC3_base/scripts.pory"
	createfieldmugshot MUGSHOT_TEST, EMOTE_NORMAL
# 32 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Base_Paras_Text_0
# 33 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_PARAS_BEATEN, TARC3_Base_Paras_2
# 39 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Base_Paras_Text_2
# 40 "data/maps/TARC3_base/scripts.pory"
	setwildbattle SPECIES_PARAS, 25
# 41 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_PARAS, CRY_MODE_ENCOUNTER
# 42 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 43 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 44 "data/maps/TARC3_base/scripts.pory"
	dowildbattle
# 45 "data/maps/TARC3_base/scripts.pory"
	callnative WasBattleWon
# 46 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Base_Paras_5
TARC3_Base_Paras_1:
# 51 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Base_Paras_2:
# 35 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Base_Paras_Text_1
	goto TARC3_Base_Paras_1

TARC3_Base_Paras_5:
# 48 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_BASE_PARAS_BEATEN
	goto TARC3_Base_Paras_1


TARC3_Base_Vulpix::
# 56 "data/maps/TARC3_base/scripts.pory"
	cant_see_if_set FLAG_BASE_VULPIX_BEATEN
# 57 "data/maps/TARC3_base/scripts.pory"
	lock
# 58 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 59 "data/maps/TARC3_base/scripts.pory"
	createfieldmugshot MUGSHOT_TEST, EMOTE_NORMAL
# 60 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Base_Vulpix_Text_0
# 61 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_VULPIX_BEATEN, TARC3_Base_Vulpix_2
# 67 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Base_Vulpix_Text_1
# 68 "data/maps/TARC3_base/scripts.pory"
	setwildbattle SPECIES_VULPIX, 25
# 69 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_VULPIX, CRY_MODE_ENCOUNTER
# 70 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 71 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 72 "data/maps/TARC3_base/scripts.pory"
	dowildbattle
# 73 "data/maps/TARC3_base/scripts.pory"
	callnative WasBattleWon
# 74 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Base_Vulpix_5
TARC3_Base_Vulpix_1:
# 79 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Base_Vulpix_2:
# 63 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Base_Paras_Text_1
	goto TARC3_Base_Vulpix_1

TARC3_Base_Vulpix_5:
# 76 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_BASE_VULPIX_BEATEN
	goto TARC3_Base_Vulpix_1


TARC3_Base_Dewpider::
# 84 "data/maps/TARC3_base/scripts.pory"
	cant_see_if_set FLAG_BASE_DEWPIDER_BEATEN
# 85 "data/maps/TARC3_base/scripts.pory"
	lock
# 86 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 87 "data/maps/TARC3_base/scripts.pory"
	createfieldmugshot MUGSHOT_TEST, EMOTE_NORMAL
# 88 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Base_Dewpider_Text_0
# 89 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_DEWPIDER_BEATEN, TARC3_Base_Dewpider_2
# 95 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Base_Dewpider_Text_1
# 96 "data/maps/TARC3_base/scripts.pory"
	setwildbattle SPECIES_DEWPIDER, 25
# 97 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_DEWPIDER, CRY_MODE_ENCOUNTER
# 98 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 99 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 100 "data/maps/TARC3_base/scripts.pory"
	dowildbattle
# 101 "data/maps/TARC3_base/scripts.pory"
	callnative WasBattleWon
# 102 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Base_Dewpider_5
TARC3_Base_Dewpider_1:
# 107 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Base_Dewpider_2:
# 91 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Base_Paras_Text_1
	goto TARC3_Base_Dewpider_1

TARC3_Base_Dewpider_5:
# 104 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_BASE_DEWPIDER_BEATEN
	goto TARC3_Base_Dewpider_1


TARC3_Base_Wooper_backup::
# 112 "data/maps/TARC3_base/scripts.pory"
	cant_see_if_set FLAG_BASE_WOOPER_BEATEN
# 113 "data/maps/TARC3_base/scripts.pory"
	lock
# 114 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 115 "data/maps/TARC3_base/scripts.pory"
	createfieldmugshot MUGSHOT_WOOPER, EMOTE_NORMAL
# 116 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Base_Wooper_backup_Text_0
# 117 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_WOOPER_BEATEN, TARC3_Base_Wooper_backup_2
# 123 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Base_Wooper_backup_Text_2
# 124 "data/maps/TARC3_base/scripts.pory"
	setwildbattle SPECIES_WOOPER, 25
# 125 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_WOOPER, CRY_MODE_ENCOUNTER
# 126 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 127 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 128 "data/maps/TARC3_base/scripts.pory"
	dowildbattle
# 129 "data/maps/TARC3_base/scripts.pory"
	callnative WasBattleWon
# 130 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Base_Wooper_backup_5
TARC3_Base_Wooper_backup_1:
# 135 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Base_Wooper_backup_2:
# 119 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Base_Wooper_backup_Text_1
	goto TARC3_Base_Wooper_backup_1

TARC3_Base_Wooper_backup_5:
# 132 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_BASE_WOOPER_BEATEN
	goto TARC3_Base_Wooper_backup_1


TARC3_Amber_Munchlax::
# 141 "data/maps/TARC3_base/scripts.pory"
	cant_see_if_set FLAG_BASE_MUNCHLAX_BEATEN
# 142 "data/maps/TARC3_base/scripts.pory"
	lock
# 143 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 144 "data/maps/TARC3_base/scripts.pory"
	createfieldmugshot MUGSHOT_TEST, EMOTE_NORMAL
# 145 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Amber_Munchlax_Text_0
# 146 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_MUNCHLAX_BEATEN, TARC3_Amber_Munchlax_2
# 152 "data/maps/TARC3_base/scripts.pory"
	compare VAR_TRANSFORM_MON, SPECIES_CASTFORM_SUNNY
	goto_if_eq TARC3_Amber_Munchlax_5
# 160 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Amber_Munchlax_Text_2
# 161 "data/maps/TARC3_base/scripts.pory"
	setwildbattle SPECIES_MUNCHLAX, 25
# 162 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_MUNCHLAX, CRY_MODE_ENCOUNTER
# 163 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 164 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 165 "data/maps/TARC3_base/scripts.pory"
	dowildbattle
# 166 "data/maps/TARC3_base/scripts.pory"
	callnative WasBattleWon
# 167 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Amber_Munchlax_8
TARC3_Amber_Munchlax_1:
# 173 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Amber_Munchlax_2:
# 148 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Base_Paras_Text_1
	goto TARC3_Amber_Munchlax_1

TARC3_Amber_Munchlax_5:
# 154 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Amber_Munchlax_Text_1
# 155 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Amber_Munchlax_8:
# 169 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_BASE_MUNCHLAX_BEATEN
	goto TARC3_Amber_Munchlax_1


TARC3_Amber_Combusken::
# 178 "data/maps/TARC3_base/scripts.pory"
	cant_see_if_set FLAG_BASE_COMBUSKEN_BEATEN
# 179 "data/maps/TARC3_base/scripts.pory"
	lock
# 180 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 181 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Amber_Combusken_Text_0
# 182 "data/maps/TARC3_base/scripts.pory"
	createfieldmugshot MUGSHOT_TEST, EMOTE_ALT
# 183 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_COMBUSKEN_BEATEN, TARC3_Amber_Combusken_2
# 189 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Amber_Combusken_Text_1
# 190 "data/maps/TARC3_base/scripts.pory"
	setwildbattle SPECIES_COMBUSKEN, 25
# 191 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_COMBUSKEN, CRY_MODE_ENCOUNTER
# 192 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 193 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 194 "data/maps/TARC3_base/scripts.pory"
	dowildbattle
# 195 "data/maps/TARC3_base/scripts.pory"
	callnative WasBattleWon
# 196 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Amber_Combusken_5
TARC3_Amber_Combusken_1:
# 201 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Amber_Combusken_2:
# 185 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Base_Paras_Text_1
	goto TARC3_Amber_Combusken_1

TARC3_Amber_Combusken_5:
# 198 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_BASE_COMBUSKEN_BEATEN
	goto TARC3_Amber_Combusken_1


TARC3_Amber_Observer::
# 206 "data/maps/TARC3_base/scripts.pory"
	cant_see_if_set FLAG_BASE_HELIOPTILE_BEATEN
# 207 "data/maps/TARC3_base/scripts.pory"
	lock
# 208 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 209 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Amber_Observer_Text_0
# 210 "data/maps/TARC3_base/scripts.pory"
	createfieldmugshot MUGSHOT_TEST, EMOTE_ALT
# 211 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_HELIOPTILE_BEATEN, TARC3_Amber_Observer_2
# 217 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Amber_Observer_Text_2
# 218 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_HELIOPTILE, CRY_MODE_ENCOUNTER
# 219 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 220 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 221 "data/maps/TARC3_base/scripts.pory"
	ai_vs_ai_wild_battle SPECIES_FOMANTIS, SPECIES_HELIOPTILE, 25
# 222 "data/maps/TARC3_base/scripts.pory"
	callnative WasBattleWon
# 223 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Amber_Observer_5
TARC3_Amber_Observer_1:
# 228 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Amber_Observer_2:
# 213 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Amber_Observer_Text_1
	goto TARC3_Amber_Observer_1

TARC3_Amber_Observer_5:
# 225 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_BASE_HELIOPTILE_BEATEN
	goto TARC3_Amber_Observer_1


TARC3_Amber_Torkoal::
# 233 "data/maps/TARC3_base/scripts.pory"
	cant_see_if_set FLAG_BASE_TORKOAL_BEATEN
# 234 "data/maps/TARC3_base/scripts.pory"
	lock
# 235 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 236 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Amber_Torkoal_Text_0
# 237 "data/maps/TARC3_base/scripts.pory"
	createfieldmugshot MUGSHOT_TORKOAL, EMOTE_ALT
# 238 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_TORKOAL_BEATEN, TARC3_Amber_Torkoal_2
# 244 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Amber_Torkoal_Text_1
# 245 "data/maps/TARC3_base/scripts.pory"
	setwildbattle SPECIES_TORKOAL, 25
# 246 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_TORKOAL, CRY_MODE_ENCOUNTER
# 247 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 248 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 249 "data/maps/TARC3_base/scripts.pory"
	dowildbattle
# 250 "data/maps/TARC3_base/scripts.pory"
	callnative WasBattleWon
# 251 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Amber_Torkoal_5
TARC3_Amber_Torkoal_1:
# 256 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Amber_Torkoal_2:
# 240 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Base_Paras_Text_1
	goto TARC3_Amber_Torkoal_1

TARC3_Amber_Torkoal_5:
# 253 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_BASE_TORKOAL_BEATEN
	goto TARC3_Amber_Torkoal_1


TARC3_Azure_Toxicroak::
# 261 "data/maps/TARC3_base/scripts.pory"
	cant_see_if_set FLAG_BASE_TOXICROAK_BEATEN
# 262 "data/maps/TARC3_base/scripts.pory"
	lock
# 263 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 264 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Azure_Toxicroak_Text_0
# 265 "data/maps/TARC3_base/scripts.pory"
	createfieldmugshot MUGSHOT_TEST, EMOTE_ALT
# 266 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_BASE_TOXICROAK_BEATEN, TARC3_Azure_Toxicroak_2
# 272 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Azure_Toxicroak_Text_1
# 273 "data/maps/TARC3_base/scripts.pory"
	setwildbattle SPECIES_TOXICROAK, 25
# 274 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_TOXICROAK, CRY_MODE_ENCOUNTER
# 275 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 276 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 277 "data/maps/TARC3_base/scripts.pory"
	dowildbattle
# 278 "data/maps/TARC3_base/scripts.pory"
	callnative WasBattleWon
# 279 "data/maps/TARC3_base/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TARC3_Azure_Toxicroak_5
TARC3_Azure_Toxicroak_1:
# 284 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Azure_Toxicroak_2:
# 268 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Base_Paras_Text_1
	goto TARC3_Azure_Toxicroak_1

TARC3_Azure_Toxicroak_5:
# 281 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_BASE_TOXICROAK_BEATEN
	goto TARC3_Azure_Toxicroak_1


TARC3_Whimsicott::
# 291 "data/maps/TARC3_base/scripts.pory"
	lock
# 292 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 293 "data/maps/TARC3_base/scripts.pory"
	setspeaker TARC3_Whimsicott_Text_0
# 294 "data/maps/TARC3_base/scripts.pory"
	createfieldmugshot MUGSHOT_WHIMSICOTT, EMOTE_NORMAL
# 295 "data/maps/TARC3_base/scripts.pory"
	goto_if_set FLAG_WHIMSICOTT_GAVE_SEED, TARC3_Whimsicott_2
# 301 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Whimsicott_Text_2
# 302 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_WHIMSICOTT, CRY_MODE_NORMAL
# 303 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 304 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 305 "data/maps/TARC3_base/scripts.pory"
	giveitem ITEM_WEPEAR_BERRY, 1
# 306 "data/maps/TARC3_base/scripts.pory"
	setflag FLAG_WHIMSICOTT_GAVE_SEED
# 307 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Whimsicott_Text_1
TARC3_Whimsicott_1:
# 309 "data/maps/TARC3_base/scripts.pory"
	release
	end

TARC3_Whimsicott_2:
# 297 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Whimsicott_Text_1
	goto TARC3_Whimsicott_1


TARC3_Find_IceClimb::
# 314 "data/maps/TARC3_base/scripts.pory"
	finditem ITEM_TM01, 1
	end


TARC3_Dummy_Start_Amber::
# 319 "data/maps/TARC3_base/scripts.pory"
	lockall
# 320 "data/maps/TARC3_base/scripts.pory"
	setvar VAR_CASTFORM_PHASE, 1
# 321 "data/maps/TARC3_base/scripts.pory"
	finditem ITEM_RED_SHARD, 1
# 322 "data/maps/TARC3_base/scripts.pory"
	givemon SPECIES_CASTFORM_SUNNY, 25
# 323 "data/maps/TARC3_base/scripts.pory"
	msgbox TARC3_Dummy_Start_Amber_Text_0
# 324 "data/maps/TARC3_base/scripts.pory"
	waitmessage
# 325 "data/maps/TARC3_base/scripts.pory"
	warp MAP_TARC3_BASE, 0
# 326 "data/maps/TARC3_base/scripts.pory"
	waitstate
# 327 "data/maps/TARC3_base/scripts.pory"
	releaseall
	end


TARC3_Base_Paras_Text_0:
# 32 "data/maps/TARC3_base/scripts.pory"
	.string "Paras$"

TARC3_Base_Paras_Text_1:
# 35 "data/maps/TARC3_base/scripts.pory"
	.string "I still like you!$"

TARC3_Base_Paras_Text_2:
# 39 "data/maps/TARC3_base/scripts.pory"
	.string "Hi, I'm PARAS.\nLet's battle!$"

TARC3_Base_Vulpix_Text_0:
# 60 "data/maps/TARC3_base/scripts.pory"
	.string "Vulpix$"

TARC3_Base_Vulpix_Text_1:
# 67 "data/maps/TARC3_base/scripts.pory"
	.string "Hi, I'm VULPIX.\nLet's battle!$"

TARC3_Base_Dewpider_Text_0:
# 88 "data/maps/TARC3_base/scripts.pory"
	.string "Dewpider$"

TARC3_Base_Dewpider_Text_1:
# 95 "data/maps/TARC3_base/scripts.pory"
	.string "Hi, I'm DEWPIDER.\nLet's battle!$"

TARC3_Base_Wooper_backup_Text_0:
# 116 "data/maps/TARC3_base/scripts.pory"
	.string "Wooper$"

TARC3_Base_Wooper_backup_Text_1:
# 119 "data/maps/TARC3_base/scripts.pory"
	.string "Hey, my berry!$"

TARC3_Base_Wooper_backup_Text_2:
# 123 "data/maps/TARC3_base/scripts.pory"
	.string "Hi, I'm WOOPER.\nLet's battle!$"

TARC3_Amber_Munchlax_Text_0:
# 145 "data/maps/TARC3_base/scripts.pory"
	.string "Munchlax$"

TARC3_Amber_Munchlax_Text_1:
# 154 "data/maps/TARC3_base/scripts.pory"
	.string "It's too hot to battle!$"

TARC3_Amber_Munchlax_Text_2:
# 160 "data/maps/TARC3_base/scripts.pory"
	.string "Hi, I'm MUNCHLAX.\nLet's battle!$"

TARC3_Amber_Combusken_Text_0:
# 181 "data/maps/TARC3_base/scripts.pory"
	.string "Combusken$"

TARC3_Amber_Combusken_Text_1:
# 189 "data/maps/TARC3_base/scripts.pory"
	.string "Hi, I'm COMBUSKEN.\nLet's battle!$"

TARC3_Amber_Observer_Text_0:
# 209 "data/maps/TARC3_base/scripts.pory"
	.string "Helioptile$"

TARC3_Amber_Observer_Text_1:
# 213 "data/maps/TARC3_base/scripts.pory"
	.string "We're cool again!$"

TARC3_Amber_Observer_Text_2:
# 217 "data/maps/TARC3_base/scripts.pory"
	.string "Hi, I'm HELIOPTILE.\nLet's battle!$"

TARC3_Amber_Torkoal_Text_0:
# 236 "data/maps/TARC3_base/scripts.pory"
	.string "Torkoal$"

TARC3_Amber_Torkoal_Text_1:
# 244 "data/maps/TARC3_base/scripts.pory"
	.string "Hi, I'm TORKOAL.\nLet's battle!$"

TARC3_Azure_Toxicroak_Text_0:
# 264 "data/maps/TARC3_base/scripts.pory"
	.string "Toxicroak$"

TARC3_Azure_Toxicroak_Text_1:
# 272 "data/maps/TARC3_base/scripts.pory"
	.string "Hi, I'm TOXICROAK.\nLet's battle!$"

TARC3_Whimsicott_Text_0:
# 293 "data/maps/TARC3_base/scripts.pory"
	.string "Whimsicott$"

TARC3_Whimsicott_Text_1:
# 297 "data/maps/TARC3_base/scripts.pory"
	.string "You'll be a great gardener!$"

TARC3_Whimsicott_Text_2:
# 301 "data/maps/TARC3_base/scripts.pory"
	.string "Hi, I'm WHIMSICOTT.\nTake this seed!$"

TARC3_Dummy_Start_Amber_Text_0:
# 323 "data/maps/TARC3_base/scripts.pory"
	.string "Base phase completed!\pAmber shard unlocked!\pPress SELECT to change weather.$"
