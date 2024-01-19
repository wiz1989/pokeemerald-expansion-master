FortreeCity_House1_MapScripts::
	.byte 0

FortreeCity_House1_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_NHML3_NPC_TRADE1_COMPLETED, FortreeCity_House1_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_PLUSLE
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox FortreeCity_House1_Text_YouWillTradeWontYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, FortreeCity_House1_EventScript_DeclineTrade
	//msgbox FortreeCity_House1_Text_AreYouSure, MSGBOX_YESNO
	//goto_if_eq VAR_RESULT, NO, FortreeCity_House1_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, FortreeCity_House1_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, FortreeCity_House1_EventScript_NotRequestedMon
	specialvar VAR_RESULT, HasMonHeldItem
	goto_if_eq VAR_RESULT, 1, FortreeCity_House1_EventScript_NotWithHeldItem
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox FortreeCity_House1_Text_MonYouTakeCare, MSGBOX_DEFAULT
	setflag FLAG_NHML3_NPC_TRADE1_COMPLETED
	clearflag FLAG_NHML3_NPC_TRADE2_COMPLETED
	release
	end

FortreeCity_House1_EventScript_Trader2::
	lock
	faceplayer
	goto_if_set FLAG_NHML3_NPC_TRADE2_COMPLETED, FortreeCity_House1_EventScript_TradeCompleted2
	setvar VAR_0x8008, INGAME_TRADE_HORSEA //
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox FortreeCity_House1_Text_YouWillTradeWontYou2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, FortreeCity_House1_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, FortreeCity_House1_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, FortreeCity_House1_EventScript_NotRequestedMon
	specialvar VAR_RESULT, HasMonHeldItem
	goto_if_eq VAR_RESULT, 1, FortreeCity_House1_EventScript_NotWithHeldItem
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox FortreeCity_House1_Text_MonYouTakeCare, MSGBOX_DEFAULT
	setflag FLAG_NHML3_NPC_TRADE2_COMPLETED
	clearflag FLAG_NHML3_NPC_TRADE1_COMPLETED
	release
	end

FortreeCity_House1_EventScript_Trader3::
	lock
	faceplayer
	goto_if_set FLAG_NHML3_NPC_TRADE3_COMPLETED, FortreeCity_House1_EventScript_TradeCompleted3
	setvar VAR_0x8008, INGAME_TRADE_MEOWTH
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox FortreeCity_House1_Text_YouWillTradeWontYou3, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, FortreeCity_House1_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, FortreeCity_House1_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, FortreeCity_House1_EventScript_NotRequestedMon
	specialvar VAR_RESULT, HasMonHeldItem
	goto_if_eq VAR_RESULT, 1, FortreeCity_House1_EventScript_NotWithHeldItem
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox FortreeCity_House1_Text_MonYouTakeCare, MSGBOX_DEFAULT
	setflag FLAG_NHML3_NPC_TRADE3_COMPLETED
	release
	end

FortreeCity_House1_EventScript_DeclineTrade::
	msgbox FortreeCity_House1_Text_YouWontTradeMe, MSGBOX_DEFAULT
	release
	end

FortreeCity_House1_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox FortreeCity_House1_Text_ThisIsntAMon, MSGBOX_DEFAULT
	release
	end

FortreeCity_House1_EventScript_NotWithHeldItem::
	msgbox FortreeCity_House1_Text_NotWithHeldItem, MSGBOX_DEFAULT
	release
	end

FortreeCity_House1_EventScript_TradeCompleted::
	msgbox FortreeCity_House1_Text_Trade1, MSGBOX_DEFAULT
	release
	end

FortreeCity_House1_EventScript_TradeCompleted2::
	msgbox FortreeCity_House1_Text_Trade2, MSGBOX_DEFAULT
	release
	end

FortreeCity_House1_EventScript_TradeCompleted3::
	msgbox FortreeCity_House1_Text_Trade3, MSGBOX_DEFAULT
	release
	end

FortreeCity_House1_EventScript_ExpertF::
	msgbox FortreeCity_House1_Text_TradingMemoriesWithOthers, MSGBOX_NPC
	end

FortreeCity_House1_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox FortreeCity_House1_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FortreeCity_House1_Text_YouWillTradeWontYou:
	.string "Whoooaaaa! I need it!\n"
	.string "I have to get me a {STR_VAR_1}!\l"
	.string "It's my absolute favorite!\p"
	.string "Are you willing to trade your\n"
	.string "{STR_VAR_1} for my {STR_VAR_2}?$"

FortreeCity_House1_Text_AreYouSure:
	.string "Are you sure you want to make\n"
	.string "this trade already?$"

FortreeCity_House1_Text_YouWillTradeWontYou2:
	.string "Whoooaaaa! I need it!\n"
	.string "I have to get me a {STR_VAR_1}!\l"
	.string "It's my absolute favorite!\p"
	.string "Are you willing to trade your\n"
	.string "{STR_VAR_1} for my {STR_VAR_2}?$"

FortreeCity_House1_Text_YouWillTradeWontYou3:
	.string "Such an inspirational place!\p"
	.string "Could it be? Do you have an\l"
	.string "{STR_VAR_1}?\p"
	.string "Are you willing to trade your\n"
	.string "{STR_VAR_1} for my {STR_VAR_2}?$"

FortreeCity_House1_Text_MonYouTakeCare:
	.string "Oh, yeah, right on!\p"
	.string "{STR_VAR_1}, welcome!\n"
	.string "{STR_VAR_2}, you take care!$"

FortreeCity_House1_Text_ThisIsntAMon:
	.string "Uh, no, I don't think so.\n"
	.string "That isn't a {STR_VAR_1}.$"

FortreeCity_House1_Text_YouWontTradeMe:
	.string "No? You won't trade me?\n"
	.string "Even after I bared my heart to you?$"

FortreeCity_House1_Text_Trade1:
	.string "I will always be here looking\n"
	.string "for MUNCHLAX!$"

FortreeCity_House1_Text_Trade2:
	.string "I will always be here looking\n"
	.string "for YAMASK!$"

FortreeCity_House1_Text_Trade3:
	.string "So inspirational!\p"
	.string "I always wanted to paint a\n"
	.string "prehistoric creature.$"

FortreeCity_House1_Text_TradingMemoriesWithOthers:
	.string "Trading POKéMON with others…\p"
	.string "It's as if you're trading your own\n"
	.string "memories with other people.$"

FortreeCity_House1_Text_Zigzagoon:
	.string "ZIGZAGOON: Gumomoh?$"

FortreeCity_House1_Text_NotWithHeldItem:
	.string "Oh, your Pokémon is still holding\p"
	.string "an item. I don't want to steal\n"
	.string "any of your precious goods.$"
