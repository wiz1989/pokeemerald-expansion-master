Elemental_Gym_MapScripts::
	.byte 0


ElementalGym_R1_ExitDoor::
	lock
	msgbox ElementalGym_R1_ExitDoor_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq ElementalGym_R1_ExitDoor_2
ElementalGym_R1_ExitDoor_1:
	waitmessage
	release
	end

ElementalGym_R1_ExitDoor_2:
	warp MAP_ELEMENTAL_GYM, 14, 66
	setvar VAR_UNUSED_0x40F7, 0
	setvar VAR_UNUSED_0x40F8, 1
	goto ElementalGym_R1_ExitDoor_1


ElementalGym_R2_ExitDoor::
	lock
	checktrainerflag TRAINER_ARCHIE
	goto_if 1, ElementalGym_R2_ExitDoor_2
ElementalGym_R2_ExitDoor_1:
	release
	end

ElementalGym_R2_ExitDoor_2:
	msgbox ElementalGym_R1_ExitDoor_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq ElementalGym_R2_ExitDoor_5
ElementalGym_R2_ExitDoor_4:
	waitmessage
	goto ElementalGym_R2_ExitDoor_1

ElementalGym_R2_ExitDoor_5:
	warp MAP_ELEMENTAL_GYM, 7, 54
	setvar VAR_UNUSED_0x40F7, 0
	setvar VAR_UNUSED_0x40F8, 1
	goto ElementalGym_R2_ExitDoor_4


ElementalGym_R3_ExitDoor::
	lock
	msgbox ElementalGym_R1_ExitDoor_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq ElementalGym_R3_ExitDoor_2
ElementalGym_R3_ExitDoor_1:
	waitmessage
	release
	end

ElementalGym_R3_ExitDoor_2:
	warp MAP_ELEMENTAL_GYM, 14, 50
	goto ElementalGym_R3_ExitDoor_1


ElementalGym_R2_Warpback::
	lock
	msgbox ElementalGym_R2_Warpback_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq ElementalGym_R2_Warpback_2
ElementalGym_R2_Warpback_1:
	waitmessage
	setvar VAR_UNUSED_0x40F7, 0
	setvar VAR_UNUSED_0x40F8, 1
	cleartrainerflag TRAINER_ARCHIE
	cleartrainerflag TRAINER_MAXIE_MOSSDEEP
	release
	end

ElementalGym_R2_Warpback_2:
	warp MAP_ELEMENTAL_GYM, 14, 74
	goto ElementalGym_R2_Warpback_1


ElementalGym_R2_ResetWarpback::
	setvar VAR_UNUSED_0x40F7, 1
	setvar VAR_UNUSED_0x40F8, 0
	end


ElementalGym_R3_Warpback::
	lock
	setvar VAR_UNUSED_0x40F7, 0
	setvar VAR_UNUSED_0x40F8, 1
	warp MAP_ELEMENTAL_GYM, 7, 62
	release
	end


ElementalGym_R3_ResetWarpback::
	setvar VAR_UNUSED_0x40F7, 1
	setvar VAR_UNUSED_0x40F8, 0
	end


ElementalGym_R1_Man01::
	lock
	faceplayer
	msgbox ElementalGym_R1_Man01_Text_0
	waitmessage
	msgbox ElementalGym_R1_Man01_Text_1, MSGBOX_DEFAULT
	waitmessage
	givemon SPECIES_CASTFORM, 100
	release
	end


ElementalGym_R2_Archie04::
	setvar VAR_TEMP_F, WEATHER_RAIN
	faceplayer
	trainerbattle_single TRAINER_ARCHIE, ElementalGym_R2_Archie04_Text_0, ElementalGym_R2_Archie04_Text_1
	lock
	msgbox ElementalGym_R2_Archie04_Text_2, MSGBOX_AUTOCLOSE
	release
	end


ElementalGym_R3_Maxie05::
	setvar VAR_TEMP_F, WEATHER_SUNNY
	faceplayer
	trainerbattle_single TRAINER_MAXIE_MOSSDEEP, ElementalGym_R3_Maxie05_Text_0, ElementalGym_R3_Maxie05_Text_1
	lock
	msgbox ElementalGym_R3_Maxie05_Text_2, MSGBOX_AUTOCLOSE
	release
	end


ElementalGym_Nurse::
	lock
	faceplayer
	msgbox ElementalGym_Nurse_Text_0
	waitmessage
	special HealPlayerParty
	release
	end


ElementalGym_R1_ExitDoor_Text_0:
	.string "Do you want to enter the next room?$"

ElementalGym_R2_Warpback_Text_0:
	.string "Do you really want to exit the gym\n"
	.string "battles? If so, you will have to start\l"
	.string "all over again.$"

ElementalGym_R1_Man01_Text_0:
	.string "Welcome {PLAYER} to the Elemental\n"
	.string "Gym.\p"
	.string "You will have to battle all the trainers\n"
	.string "here in order to reach the gym leader.$"

ElementalGym_R1_Man01_Text_1:
	.string "If you decide to leave the gym you will\n"
	.string "have to start all over again.\p"
	.string "You will have the opportunity to heal\n"
	.string "your team in every room.\p"
	.string "Still, make sure to bring the right team\n"
	.string "to conquer this challenge.\p"
	.string "Good luck!$"

ElementalGym_R2_Archie04_Text_0:
	.string "Feel the wrath of the sea!$"

ElementalGym_R2_Archie04_Text_1:
	.string "It's all Pawkkie's fault!$"

ElementalGym_R2_Archie04_Text_2:
	.string "May the tides be on your side.$"

ElementalGym_R3_Maxie05_Text_0:
	.string "I will burn you to ashes!$"

ElementalGym_R3_Maxie05_Text_1:
	.string "I got my fingers burned.$"

ElementalGym_R3_Maxie05_Text_2:
	.string "A fire is burning inside you.$"

ElementalGym_Nurse_Text_0:
	.string "Hello {PLAYER}, I just healed your\n"
	.string "party. Good luck!$"
