Common_EventScript_FindItem::
	callnative GetItemBallIdAndAmountFromTemplate
	finditem VAR_RESULT VAR_0x8009
	end

Common_EventScript_PlaySpeciesCry::
	callnative GetObjectEventSpecies
	copyvar VAR_0x8005, VAR_RESULT
	compare VAR_0x8005, SPECIES_NONE
	goto_if_eq Common_EventScript_PlaySpeciesCry_End
	playmoncry VAR_0x8005, CRY_MODE_NORMAL
	waitmoncry
Common_EventScript_PlaySpeciesCry_End::
	end

Common_EventScript_PlaySpeciesCry_Return::
	callnative GetObjectEventSpecies
	copyvar VAR_0x8005, VAR_RESULT
	compare VAR_0x8005, SPECIES_NONE
	goto_if_eq Common_EventScript_PlaySpeciesCry_Ret
	playmoncry VAR_0x8005, CRY_MODE_NORMAL
	waitmoncry
Common_EventScript_PlaySpeciesCry_Ret::
	return
