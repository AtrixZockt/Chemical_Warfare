#include "BIS_AddonInfo.hpp"
class CfgPatches
{
    class digi_explosives
    {
        units[] = {
            "DIGI_Gas_TripWireMine"
		};
        weapons[] = { 
            "DIGI_CAS_M43_Bomb"
		};
        ammo[] = {
            "DIGI_Gas_TripWireMine_Ammo",
            "DIGI_GASTripEffect",
            "DIGI_GASTrip_SmokeEffect",
            "DIGI_CAS_M43_Ammo",
            "DIGI_CAS_M43_Ammo_sub"
        };
        magazines[]= {
            "DIGI_CAS_M43_Mag"
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

//#include "CfgEventHandlers.hpp"
#include "CfgAmmo.hpp"
#include "CfgMagazines.hpp"
#include "CfgVehicles.hpp"
#include "CfgCloudlets.hpp"
#include "CfgWeapons.hpp"

class CfgFunctions {
    class digi_explosives {
        tag ="digi_explosives";
        class main {
            file = "DiGi_ACE_Extension_gas_more\addons\digi_explosives\functions";
            class GasTripEffect {};
            class spawnSmoke {};
            class CASCreateGas {};
        };
    };
};


