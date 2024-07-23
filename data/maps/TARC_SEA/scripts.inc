TARC_SEA_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, TARC_Sea_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, TARC_Sea_OnTransition
	.byte 0


TARC_Sea_OnResume::
	setvar VAR_TEMP_2, 0
	return


TARC_Sea_OnTransition::
	setrespawn HEAL_LOCATION_TARC_ISLAND
	return

