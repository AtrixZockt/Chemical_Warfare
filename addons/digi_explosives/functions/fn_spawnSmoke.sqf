params ["_posX","_posY","_posZ"]; 

private _smoke = "DIGI_GASTrip_SmokeEffect" createVehicle [_posX,_posY,_posZ];
hideObjectGlobal _smoke;

private _pos = [_posX,_posY,_posZ];

[_pos,240,5,0] spawn digi_mortar_fnc_createZone;

["digi_tripGasTriggered", [_smoke, [_posX,_posY,_posZ]]] call CBA_fnc_globalEvent;
nil