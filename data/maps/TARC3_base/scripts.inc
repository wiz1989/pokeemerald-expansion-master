TARC3_base_MapScripts::
	.byte 0


TARC3_Base_Sunkern::
# 6 "data/maps/TARC3_base/scripts.pory"
	lock
# 7 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 8 "data/maps/TARC3_base/scripts.pory"
	setwildbattle SPECIES_SUNKERN, 25
# 9 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_SUNKERN, CRY_MODE_ENCOUNTER
# 10 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 11 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 12 "data/maps/TARC3_base/scripts.pory"
	dowildbattle
# 13 "data/maps/TARC3_base/scripts.pory"
	release
	end


TARC3_Base_Wooper::
# 18 "data/maps/TARC3_base/scripts.pory"
	lock
# 19 "data/maps/TARC3_base/scripts.pory"
	faceplayer
# 20 "data/maps/TARC3_base/scripts.pory"
	setwildbattle SPECIES_WOOPER, 25
# 21 "data/maps/TARC3_base/scripts.pory"
	playmoncry SPECIES_WOOPER, CRY_MODE_ENCOUNTER
# 22 "data/maps/TARC3_base/scripts.pory"
	delay 40
# 23 "data/maps/TARC3_base/scripts.pory"
	waitmoncry
# 24 "data/maps/TARC3_base/scripts.pory"
	dowildbattle
# 25 "data/maps/TARC3_base/scripts.pory"
	release
	end

