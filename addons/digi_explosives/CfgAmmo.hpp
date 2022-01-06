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
}; 