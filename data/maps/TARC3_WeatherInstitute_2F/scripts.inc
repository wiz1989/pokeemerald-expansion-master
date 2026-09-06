TARC3_WeatherInstitute_2F_MapScripts::
	.byte 0


TARC3_Lab_F2_Psyduck::
# 7 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	lock
# 8 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	faceplayer
# 9 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	playmoncry SPECIES_PSYDUCK, CRY_MODE_NORMAL
# 10 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	setspeaker TARC3_Lab_F2_Psyduck_Text_0
# 11 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	msgbox TARC3_Lab_F2_Psyduck_Text_1
# 12 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	release
	end


TARC3_Lab_F2_Porygon::
# 17 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	lock
# 18 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	faceplayer
# 19 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	playmoncry SPECIES_PORYGON, CRY_MODE_NORMAL
# 20 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	setspeaker TARC3_Lab_F2_Porygon_Text_0
# 21 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	msgbox TARC3_Lab_F2_Porygon_Text_1
# 22 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	release
	end


TARC3_Lab_F2_Xatu::
# 27 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	lock
# 28 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	faceplayer
# 29 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	playmoncry SPECIES_XATU, CRY_MODE_NORMAL
# 30 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	setspeaker TARC3_Lab_F2_Xatu_Text_0
# 31 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	msgbox TARC3_Lab_F2_Xatu_Text_1
# 32 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	release
	end


TARC3_Lab_F2_Psyduck_Text_0:
# 10 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	.string "Psyduck$"

TARC3_Lab_F2_Psyduck_Text_1:
# 11 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	.string "Oh no oh no oh no...$"

TARC3_Lab_F2_Porygon_Text_0:
# 20 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	.string "Porygon Z$"

TARC3_Lab_F2_Porygon_Text_1:
# 21 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	.string "The professor is acting dubious.\pI don't understand the issue.\pLife is a simulation anyways.$"

TARC3_Lab_F2_Xatu_Text_0:
# 30 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	.string "Prof. Xatu$"

TARC3_Lab_F2_Xatu_Text_1:
# 31 "data/maps/TARC3_WeatherInstitute_2F/scripts.pory"
	.string "Please help us find the missing\nweather shards!\pYou are our only help!$"
