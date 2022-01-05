#include "BIS_AddonInfo.hpp"
class CfgPatches
{
    class digi_mortar
    {
        units[] = {
		};
        weapons[] = {
            "ACE_mortar_82mm"
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
#include "CfgMagazineGroups.hpp"

class CfgFunctions {
    class digi_mortar {
        tag ="digi_mortar";
        class main {
            file = "DiGi_ACE_Extension_gas_more\addons\digi_mortar\functions";
            class postInit {};
            class addLoadAction {};
            class handleFired {};
            class createZone {};
        };
    };
};



class cfgWeapons
{
    class CannonCore;
	class mortar_82mm: CannonCore
	{
		magazines[]+=
		{
			"DIGI_1Rnd_82mm_Mo_Type0",
            "DIGI_5Rnd_82mm_Mo_Type0_AI",
            "DIGI_1Rnd_82mm_Mo_TypeCS",
            "DIGI_3Rnd_82mm_Mo_TypeCS_AI"
		};
	};
	class ACE_mortar_82mm: mortar_82mm
	{
		magazines[] +=
		{
			"DIGI_1Rnd_82mm_Mo_Type0",
            "DIGI_5Rnd_82mm_Mo_Type0_AI",
            "DIGI_1Rnd_82mm_Mo_TypeCS",
            "DIGI_3Rnd_82mm_Mo_TypeCS_AI"
		};
	};
};


class cfgMagazines
{
	class ACE_1Rnd_82mm_Mo_HE;
	class DIGI_1Rnd_82mm_Mo_Type0: ACE_1Rnd_82mm_Mo_HE
	{
		author="DiGii";
		ammo="Sh_82mm_AMOS_Type0";
		displayNameMFDFormat="Toxic gas";
		displayNameShort="Toxic gas";
		displayName="82mm Toxic Gas Round";
	};
    class DIGI_5Rnd_82mm_Mo_Type0_AI: DIGI_1Rnd_82mm_Mo_Type0
    {
        scope = 1;
        count = 5;
    };
    class DIGI_1Rnd_82mm_Mo_TypeCS: ACE_1Rnd_82mm_Mo_HE 
    {
        author="DiGii";
		ammo="Sh_82mm_AMOS_TypeCS";
		displayNameMFDFormat="CS-Gas";
		displayNameShort="CS-Gas";
		displayName="82mm CS-Gas Round";
    };
    class DIGI_3Rnd_82mm_Mo_TypeCS_AI: DIGI_1Rnd_82mm_Mo_TypeCS 
    {
        scope = 1;
        count = 3;
    };
};

class cfgAmmo
{
    class Smoke_82mm_AMOS_White;
    class SmokeShellArty;
    class Digi_SmokeShellArty: SmokeShellArty{
        smokeColor[] = {0,0,0,0};
    };
    class Sh_82mm_AMOS_Type0: Smoke_82mm_AMOS_White 
    {
        DiGi_porjectile = 1;
        DiGi_lifetime = 90;
        DiGi_radius = 10;
        DiGi_toxicLvL = 0;
        soundFakeFall[] = {"soundFakeFall0",0.25,"soundFakeFall1",0.25,"soundFakeFall2",0.25,"soundFakeFall3",0.25};
        soundFakeFall0[] = {"a3\Sounds_F\weapons\falling_bomb\fall_01",3.16228,1,1000};
        soundFakeFall1[] = {"a3\Sounds_F\weapons\falling_bomb\fall_02",3.16228,1,1000};
        soundFakeFall2[] = {"a3\Sounds_F\weapons\falling_bomb\fall_03",3.16228,1,1000};
        soundFakeFall3[] = {"a3\Sounds_F\weapons\falling_bomb\fall_04",3.16228,1,1000};
        whistleDist = 20;
        whistleOnFire = 2;
        submunitionAmmo = "Digi_SmokeShellArty";
    };
    class Sh_82mm_AMOS_TypeCS: Sh_82mm_AMOS_Type0
    {
        DiGi_porjectile = 1;
        DiGi_lifetime = 60;
        DiGi_radius = 10;
        DiGi_toxicLvL = 1; //cs
    };
};

#define MACRO_ADDMAGAZINE(MAGAZINE,COUNT) class _xx_##MAGAZINE { \
    magazine = #MAGAZINE; \
    count = COUNT; \
}

class CfgVehicles {
    class LandVehicle;
    class StaticWeapon: LandVehicle {
        class Turrets {
            class MainTurret;
        };
    };
    class StaticMortar: StaticWeapon {
        class Turrets: Turrets {
            class MainTurret: MainTurret {};
        };
    };
    class Mortar_01_base_F: StaticMortar {
        class Turrets: Turrets {
            class MainTurret: MainTurret {
                magazines[] += {"DIGI_5Rnd_82mm_Mo_Type0_AI","DIGI_5Rnd_82mm_Mo_Type0_AI","DIGI_5Rnd_82mm_Mo_Type0_AI","DIGI_5Rnd_82mm_Mo_Type0_AI","DIGI_3Rnd_82mm_Mo_TypeCS_AI","DIGI_3Rnd_82mm_Mo_TypeCS_AI","DIGI_3Rnd_82mm_Mo_TypeCS_AI"};
            };
        };
    };


    class Box_NATO_AmmoOrd_F;
    class ACE_Box_82mm_Mo_HE: Box_NATO_AmmoOrd_F {
        class TransportMagazines;
    };
    class ACE_Box_82mm_Mo_Combo: ACE_Box_82mm_Mo_HE {
        class TransportMagazines: TransportMagazines {
            MACRO_ADDMAGAZINE(DIGI_1Rnd_82mm_Mo_Type0,8);
            MACRO_ADDMAGAZINE(DIGI_1Rnd_82mm_Mo_TypeCS,8);
        };
    };
    class ACE_Box_82mm_Mo_Gas: ACE_Box_82mm_Mo_HE {
        displayName = "$STR_ACE_Mk6Mortar_GASBox_DisplayName";
        class TransportMagazines {
            MACRO_ADDMAGAZINE(DIGI_1Rnd_82mm_Mo_Type0,8);
            MACRO_ADDMAGAZINE(DIGI_1Rnd_82mm_Mo_TypeCS,8);
        };
    };

};