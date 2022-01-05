/////////////////////

/////////////////////

params ["_vehicle", "", "", "", "_ammo", "_magazine", "_projectile"];

// Large enough distance to not simulate any wind deflection
if (_vehicle distance ACE_player > 8000) exitWith {false};

if !(_ammo in DIGI_ProjectileChache) exitWith {};

private _configClass = (configFile >> "cfgAmmo" >> _ammo);

private _lifetime = [_configClass, "DiGi_lifetime",60] call BIS_fnc_returnConfigEntry;
private _radius = [_configClass, "DiGi_radius",10] call BIS_fnc_returnConfigEntry;
private _gasLvL = [_configClass, "DiGi_toxicLvL",1] call BIS_fnc_returnConfigEntry;

 

[{
	params["_args","_handler"];
	_args params ["_projectile","_posarr","_gasInfo"];
	_gasInfo params ["_lifetime","_radius","_gasLvL"];
	if(!isNull _projectile) exitWith {
		_args set [1, getPos _projectile];
	};

	[_posarr,_lifetime,_radius,_gasLvL] call digi_mortar_fnc_createZone;

	[_handler] call CBA_fnc_removePerFrameHandler;
},0,[_projectile,[0,0,0],[_lifetime,_radius,_gasLvL]]] call CBA_fnc_addPerFrameHandler;
