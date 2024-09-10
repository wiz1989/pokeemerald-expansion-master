TARC_AQUA_HIDEOUT_MapScripts::
	.byte 0


TARC_AQUA_ChangeParty::
	lockall
	faceplayer
	goto_if_unset FLAG_TALKED_TO_GRUNT, TARC_AQUA_ChangeParty_2
TARC_AQUA_ChangeParty_1:
	msgbox TARC_AQUA_ChangeParty_Text_2, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq TARC_AQUA_ChangeParty_5
	msgbox TARC_AQUA_ChangeParty_Text_5
	waitmessage
TARC_AQUA_ChangeParty_4:
	releaseall
	return

TARC_AQUA_ChangeParty_2:
	msgbox TARC_AQUA_ChangeParty_Text_0
	waitmessage
	msgbox TARC_AQUA_ChangeParty_Text_1
	waitmessage
	setflag FLAG_TALKED_TO_GRUNT
	goto TARC_AQUA_ChangeParty_1

TARC_AQUA_ChangeParty_5:
	setflag FLAG_AQUA_CHANGED_PARTY
	getpartymonslot SPECIES_PORYGON
	special DeletePartyMon
	getpartymonslot SPECIES_CUBONE
	special DeletePartyMon
	getpartymonslot SPECIES_FARFETCHD
	special DeletePartyMon
	givemon SPECIES_GYARADOS, 30, nature = NATURE_CALM, abilityNum = 2, hpEv = 252, spDefEv = 252, hpIv = 31, atkIv = 0, defIv = 31, speedIv = 31, spAtkIv = 0, spDefIv = 31, move1 = MOVE_STRENGTH, move2 = MOVE_WATERFALL, move3 = MOVE_ROAR, move4 = MOVE_PROTECT
	givemon SPECIES_WEEZING, 30, nature = NATURE_CAREFUL, abilityNum = 0, hpEv = 252, atkEv = 4, spDefEv = 252, hpIv = 31, atkIv = 31, defIv = 31, speedIv = 31, spAtkIv = 0, spDefIv = 31, move1 = MOVE_SLUDGE, move2 = MOVE_FLAMETHROWER, move3 = MOVE_SELF_DESTRUCT, move4 = MOVE_NONE
	msgbox TARC_AQUA_ChangeParty_Text_3
	waitmessage
	closemessage
	msgbox TARC_AQUA_ChangeParty_Text_4, MSGBOX_AUTOCLOSE
	applymovement OBJ_EVENT_ID_PLAYER, Move_exclmark
	compare VAR_FACING, DIR_NORTH
	goto_if_eq TARC_AQUA_ChangeParty_8
	applymovement 1, Move_Grunt
	waitmovement 0
	removeobject 1
	goto TARC_AQUA_ChangeParty_4

TARC_AQUA_ChangeParty_8:
	applymovement 1, Move_Grunt_around
	waitmovement 0
	removeobject 1
	goto TARC_AQUA_ChangeParty_4


TARC_AQUA_ItemBall::
	lock
	removeobject 2, MAP_TARC_AQUA_HIDEOUT
	finditem ITEM_MEGA_RING, 1
	release
	return


Move_Grunt:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	jump_down
	step_end

Move_Grunt_around:
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	jump_down
	step_end

TARC_AQUA_ChangeParty_Text_0:
	.string "Archie has gone mad!\p"
	.string "He and Maxie met on this island before\n"
	.string "they founded their competing\l"
	.string "organizations.\p"
	.string "And now Archie wants to build the new\n"
	.string "Hideout exactly here.\p"
	.string "But why?\p"
	.string "I'd rather have a nice casino and a bar\n"
	.string "next door than living on this god\l"
	.string "forsaken rock.$"

TARC_AQUA_ChangeParty_Text_1:
	.string "Let me help you out to dissuade him\n"
	.string "from his obscure intentions.$"

TARC_AQUA_ChangeParty_Text_2:
	.string "I have two special Pokémon with me that\n"
	.string "might be able to get you the win.\p"
	.string "But I would need your party for it\n"
	.string "instead.\p"
	.string "I'm Team Aqua after all...\p"
	.string "You can keep your Surfing buddy\n"
	.string "though.\p"
	.string "I am not a monster.\p"
	.string "Deal?$"

TARC_AQUA_ChangeParty_Text_3:
	.string "{PLAYER} acquired two Pokéballs from\n"
	.string "Team Aqua.\p"
	.string "Was that worth it...?$"

TARC_AQUA_ChangeParty_Text_4:
	.string "Hehehe...$"

TARC_AQUA_ChangeParty_Text_5:
	.string "You'll be coming back.$"
