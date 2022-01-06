class CfgCloudlets {
    class Default;
    class ACE_GasTrip: Default {
        lifeTime = 0;
        beforeDestroyScript = "\DiGi_ACE_Extension_gas_more\addons\digi_explosives\functions\fn_GasTripEffect.sqf";
    };
}; 

class DIGI_GASTripEffect {
    class SpawnFlare {
        simulation = "particles";
        type = "ACE_GasTrip";
        position = "explosionPos";
    };
};