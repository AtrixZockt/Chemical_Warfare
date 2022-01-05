class CfgAmmo {
	class SmokeShell;

	class DIGI_G_M7A3: SmokeShell 
	{
		digi_csGas = 1;
		model = "DiGi_ACE_Extension_gas_more\addons\digi_grenades\ui\m7a3_throw.p3d";
		dangerRadiusHit = -1;
        suppressionRadiusHit = 20;
        typicalSpeed = 22;
        cost = 40;
        explosive = 1E-7;
        deflecting = 15;
        explosionTime = 4;
        timeToLive = 20;
        grenadeBurningSound[] = {};
        aiAmmoUsageFlags = "64"; // infantry
        smokeColor[] = {0,0,0,0};
        effectsSmoke = "ACE_M84FlashbangEffect";
        whistleDist = 0;
		grenadeFireSound[] = {};
	};
};