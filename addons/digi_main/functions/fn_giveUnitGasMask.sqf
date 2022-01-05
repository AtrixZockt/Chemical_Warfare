#include "..\script_macros.hpp"
//////////////////////////

//////////////////////////

params ["_medic", "_patient"];

private _itemArr = _medic call ace_common_fnc_uniqueItems;
private _playerhasGasmask = false;
private _playerGasMask = "";
{ if(_x in DIGI_AVAIL_GASMASK) then {_playerhasGasmask = true; _playerGasMask = _x} } forEach _itemArr;

private _fnc_replaceItem = {
	params["_medic","_patient","_playerGasMask"];
	if(goggles _patient == "") then {
		_patient linkItem _playerGasMask;
	} else { 
		private _pCurGoggles = goggles _patient;
		if(_patient canAdd _pCurGoggles) then{ 
			_patient addItem _pCurGoggles 
		} else {
			if(_medic canAdd _pCurGoggles) then { _medic addItem _pCurGoggles} else {
				private _weaponHolder = createVehicle ["Weapon_Empty", getPosATL player, [], 0, "CAN_COLLIDE"];
				_weaponHolder addItemCargo [_pCurGoggles, 1];
			}; 
		};
		_patient linkItem _playerGasMask;
	};
};

if(_playerhasGasmask) then {
	[_medic,_playerGasMask] call ace_common_fnc_useItem;
	[_medic,_patient,_playerGasMask] call _fnc_replaceItem;
} else {
	_itemArr = _patient call ace_common_fnc_uniqueItems;
	{ if(_x in DIGI_AVAIL_GASMASK) then {_playerGasMask = _x} } forEach _itemArr;
	[_medic,_patient,_playerGasMask] call _fnc_replaceItem;
};