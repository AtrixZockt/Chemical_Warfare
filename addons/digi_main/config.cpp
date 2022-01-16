//#include "BIS_AddonInfo.hpp"
class CfgPatches
{
    class digi_main
    {
        units[] = {
			"digi_Antidot_Item",
            "digi_sealant_Item",
            "digi_module_gas",
            "digi_module_zeus_gas"
		};
        weapons[] = {
			"digi_Antidot",
            "digi_sealant",
            "digi_gasmaskFilter"
		};
        requiredVersion = 1.88;
        requiredAddons[] = {
			"ace_medical"
			,"cba_settings"
		};
		version = "1";
		versionStr = "1";
		author = "DiGii";
		authorUrl = "";
    };
};

#include "CfgEventHandlers.hpp"
#include "CfgUIGrids.hpp"
#include "CfgWeapons.hpp"
#include "CfgVehicles.hpp"
#include "ui\RscAttributes.hpp"
#include "ACE_Medical_Treatment.hpp"
#include "ACE_Medical_Treatment_Actions.hpp"

class CfgFunctions {
    class digi_ace {
        tag ="digi";
        class main {
            file = "DiGi_ACE_Extension_gas_more\addons\digi_main\functions";
            class registerSettings {};
            class postInit {};
            class init {postInit = 1;};
            class medication {};
            class medicationLocal {};
            class gasCheck {};
            class gasCheckLocal {};
            class getList {};
            class coughing {};
            class handlePoisenDamage {};
            class handleRespawn {};
            class gasmodule {};
            class initModule {};
            class ui_gasModul {};
            class canPutGasMask {};
            class hasGasmask {};
            class giveUnitGasMask {};
            class createSealAction {};
            class gasAI {};
            class chemDetector {};
            class handleCSGas {};
            class spawnGasSmoke {};
            class checkGasMaskDur {};
            class displayGasMaskDur {};
            class handleGasMaskDur {};
            class changeGasMaskFilter {};
            class breathing {};
        };
    };

    class digi_ui {
        tag = "digi_ui";
        class main {
            file = "DiGi_ACE_Extension_gas_more\addons\digi_main\ui";
            class AttributeRadius {};
        };
    };

    class digi_aceMedical_Menu
	{
		tag="ace_medical_gui";
		class ace_medical_gui
		{
			class updateInjuryList
			{
				file="DiGi_ACE_Extension_gas_more\addons\digi_main\functions\fnc_updateInjuryList.sqf";
			};
		};
	};

    class digi_aceMedical_BodyUpdate
    {
        tag="ace_medical_gui";
        class ace_medical_gui
        {
            class updateBodyImage
            {
                file="DiGi_ACE_Extension_gas_more\addons\digi_main\functions\fnc_updateBodyImage.sqf";
            };
        };
    };

    class overwrite_medicalTreatment {
        tag = "ace_medical_treatment";
        class ace_medical_treatment {
            class fullHealLocal {
                file = "DiGi_ACE_Extension_gas_more\addons\digi_main\functions\fnc_fullHealLocal.sqf";
            };
        };
    };
};


class CfgFactionClasses {
    class NO_CATEGORY;
    class DIGI_missionModules: NO_CATEGORY {
        displayName = "DiGii Missions Module";
    };
};


class CfgSounds {
    class cough_1 {
        name = "cough_1";
        sound[] = 
        {
            "DiGi_ACE_Extension_gas_more\addons\digi_main\sounds\cough_1.ogg",
            2,
            1,
            100
        };
        titles[] = {};
    };

    class mask_breath_1 {
        name = "mask_breath_1";
        sound[] =
        {
            "DiGi_ACE_Extension_gas_more\addons\digi_main\sounds\breath1.ogg",
            4,
            1.0,
            10
        };
        titles[] = {};
    };

    class mask_breath_2 {
        name = "mask_breath_2";
        sound[] =
        {
            "DiGi_ACE_Extension_gas_more\addons\digi_main\sounds\breath2.ogg",
            4,
            1.0,
            10
        };
        titles[] = {};
    };

    class mask_breath_heavy {
        name = "mask_breath_heavy";
        sound[] =
        {
            "DiGi_ACE_Extension_gas_more\addons\digi_main\sounds\heavyBreath.ogg",
            4,
            1.0,
            10
        };
        titles[] = {};
    };

};




