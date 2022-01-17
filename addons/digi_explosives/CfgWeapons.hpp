class CfgWeapons
{
    class Default;
	class Put: Default
	{
		muzzles[]+=
		{
			"ace_explosives_muzzle"
		};
		class PutMuzzle: Default
		{
		};
		class ace_explosives_muzzle: PutMuzzle
		{
			magazines[]+=
			{
				"DIGI_Gas_TripWireMine_Mag"
			};
		};
	};

	class weapon_GBU12Launcher;
	class DIGI_CAS_M43_Bomb: weapon_GBU12Launcher {
		author = "DiGii";
		canLock = 2;
		scope=2;
		displayName = "M43 BZ LGB";
		maxRange = 5000;
		maxRangeProbab = 0.8;
		midRange = 2000;
		midRangeProbab = 0.85;
		minRange = 150;
		minRangeProbab = 0.6;
		magazines[] = {"DIGI_CAS_M43_Mag","DIGI_CAS_M43_Mag_x2"};
		maxControlRange = 8000;
		weaponLockDelay = 3;
		weaponLockSystem = 4;
	};

	class rockets_Skyfire;
	class DIGI_CAS_R_80mm_GAS_POD: rockets_Skyfire {
		displayName = "Hydra GAS 19x";
		magazines[] = {"DIGI_CAS_R_80mm_GAS_MAG"};
		scope=2;
	};
	
};