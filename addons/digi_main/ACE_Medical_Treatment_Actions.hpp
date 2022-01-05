class ACE_Medical_Treatment_Actions {
    class Morphine;
    class Antidot : Morphine {
        displayName = "$STR_DIGI_Medical_AntidotItem_action";
        displayNameProgress = "$STR_DIGI_Medical_AntidotItem_action_progress";
        callbackSuccess = "digi_fnc_medication";
        items[] = {"digi_Antidot"};
        litter[] = {{"ACE_MedicalLitter_antidot"}};
        
    };

    class PoisenBP {
        displayName = "";
        displayNameProgress = "";
        callbackSuccess = "";
        items[] = {};
        litter[] = {{"ACE_MedicalLitter_PoisenBP"}};
        animationMedic = "";
        sounds[] = {};
    };
 
    class Diagnose;
    class putonGasMask: Diagnose {
        displayName = "$STR_DIGI_Medical_giveGasMask_action";
        displayNameProgress = "$STR_DIGI_Medical_giveGasMask_progress";
        allowedSelections[] = {"Head"};
        allowSelfTreatment = 0;
        callbackSuccess = "digi_fnc_giveUnitGasMask";
        condition = "digi_fnc_canPutGasMask";
    };
};