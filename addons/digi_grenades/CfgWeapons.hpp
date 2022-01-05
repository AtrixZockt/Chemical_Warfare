class CfgWeapons {
	class GrenadeLauncher;
	class Throw: GrenadeLauncher {
		muzzles[] += {ACE_M7A3Muzzle};

		class ThrowMuzzle;
		class ACE_M7A3Muzzle: ThrowMuzzle {
            magazines[] = {"DIGI_M7A3"};
        };
	};
};