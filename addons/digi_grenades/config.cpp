#include "BIS_AddonInfo.hpp"
class CfgPatches
{
    class digi_grenades
    {
        units[] = {
		};
        weapons[] = {
            "DIGI_M7A3"
		};
        requiredVersion = 1.88;
        requiredAddons[] = {
			"digi_main"
		};
		version = "1";
		versionStr = "1";
		author = "DiGii";
		authorUrl = "";
    };
};

#include "CfgEventHandlers.hpp"
#include "CfgAmmo.hpp"
#include "CfgMagazines.hpp"
#include "CfgWeapons.hpp"

class CfgFunctions {
    class digi_grenades {
        tag ="digi_grenades";
        class main {
            file = "DiGi_ACE_Extension_gas_more\addons\digi_grenades\functions";
            class postInit {};
            class throwGrenade {};
            class csGrenadeThrownFuze {};
        };
    };
};


