params ["_posX","_posY","_posZ"]; 

private _smoke = "DIGI_GASTrip_SmokeEffect" createVehicle [_posX,_posY,_posZ];
hideObjectGlobal _smoke;
[_smoke,0,["ACE_MainActions","ACTION"]] call ace_interact_menu_fnc_removeActionFromObject;

private _pos = [_posX,_posY,_posZ];

[_pos,240,5,0] spawn digi_mortar_fnc_createZone;

["digi_tripGasTriggered", [_smoke, [_posX,_posY,_posZ]]] call CBA_fnc_globalEvent;
nil