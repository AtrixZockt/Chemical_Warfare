params ["_unit", "_weapon", "_muzzle", "_mode", "_ammo", "_magazine", "_projectile"];


private _config = configFile >> "CfgAmmo" >> _ammo;
if(getNumber (_config >> "digi_csGas") != 1) exitWith {};
if!(local _unit) exitWith {};


private _fuzeTimeBase = getNumber (_config >> "explosionTime");

private _fuzeTime = _fuzeTimeBase + random[-0.8,0,1.2];
private _currenTime = CBA_missionTime;
waitUntil{(CBA_missionTime - _currenTime) > _fuzeTime};
[_projectile] call digi_grenades_fnc_csGrenadeThrownFuze;

