

["Mortar_01_base_F", "fired", {call digi_mortar_fnc_handleFired}] call CBA_fnc_addClassEventHandler;


DIGI_ProjectileChache = ("([_x, 'DiGi_porjectile', 0] call BIS_fnc_returnConfigEntry) != 0" configClasses (configFile >> "cfgAmmo")) apply {configName _x};