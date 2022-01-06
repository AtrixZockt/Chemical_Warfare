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
};