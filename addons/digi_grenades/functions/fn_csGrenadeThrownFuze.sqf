params ["_projectile"];

if (alive _projectile) then {
	playSound3D ["A3\Sounds_F\weapons\Explosion\explosion_mine_1.wss", _projectile, false, getPosASL _projectile, 1, 1.2, 400];

	private _lifetime = 60 + random[-5,0,9];

	[getPosASL _projectile,_lifetime,6,1] call digi_mortar_fnc_createZone;
};