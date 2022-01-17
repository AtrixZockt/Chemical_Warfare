class CfgAmmo {

    class APERSTripMine_Wire_Ammo;
    class DIGI_Gas_TripWireMine_Ammo: APERSTripMine_Wire_Ammo {
        SoundSetExplosion[] = {};
        defaultMagazine = "DIGI_Gas_TripWireMine_Mag"; //Mag that gets dropped after defuse
        hit = 0;
        indirectHit = 0;
        indirectHitRange = 0;
        soundHit[] = {"A3\Sounds_F\weapons\smokeshell\smoke_3",1.25893,1,100};
        explosionEffects = "DIGI_GASTripEffect"; 
        CraterEffects = "";
        soundTrigger[] = {"",1,1};
        class CamShakeExplode {
            power = 0;
            duration = 0;
            frequency = 0;
            distance = 0;
        };
    };

    class SmokeShell;
    class DIGI_GASTrip_SmokeEffect: SmokeShell {
        triggerTime = 0.1;
        ace_explosives_size = 0;
        smokeColor[] = {0.671, 0.765, 0.184,1};
    };

    class BombCore;
	//class Bo_GBU12_LGB;
    class BombCluster_01_Ammo_F;
    class DIGI_CAS_M43_Ammo: BombCluster_01_Ammo_F {
		aiAmmoUsageFlags = "64 + 128 + 512";
		allowAgainstInfantry = 1;
		autoSeekTarget = 1;
		canLock=1;
		cameraViewAvailable = 1;
		CraterEffects = "BombCrater";
		CraterWaterEffects = "ImpactEffectsWaterExplosion";
		cost = 0.1;
		explosionTime = 2;
		explosionForceCoef = 5;
		explosive = 0.95;
		ExplosionEffects = "BombExplosion"; 
		flightProfiles[] = {"LoalAltitude"};
		hit = 0;
		indirectHit = 0;
		indirectHitRange = 0;
		irLock = 0;
		laserLock = 1;
		lightColor[] = {1, 0.15, 0, 1};
		maneuvrability = 16;
		model = "\A3\Weapons_F\Ammo\Bomb_01_fly_F";
		nvLock = 1;
		simulation = "shotMissile";
		soundFly[] = {"A3\Sounds_F\arsenal\weapons\Launchers\RPG32\Fly_RPG32",1,1,500};
		weaponLockSystem = 4;
		weaponType = "Default";
        triggerDistance = 250;
        triggerSpeedCoef[] = {0.8,1};
        submunitionAmmo="DIGI_CAS_M43_Ammo_sub";
		class CamShakeExplode
		{
			power = 20;
			duration = 2;
			frequency = 5;
			distance = 250;
		};

        
    };
    class Mo_cluster_Bomb_01_F;
    class DIGI_CAS_M43_Ammo_sub: Mo_cluster_Bomb_01_F {
        hit = 0;
        indirectHit = 0;
        indirectHitRange = 0;
        explosionEffects = "DIGI_GAS_ClusterExplosion"; 
    };

    class R_80mm_HE;
    class DIGI_CAS_R_80mm_GAS_AMMO: R_80mm_HE {
        hit = 0;
        indirectHit = 0;
        indirectHitRange = 0;
        explosionEffects = "DIGI_CAS_R_HYDRA_Explosion"; //HERocketExplosion
    };
}; 



