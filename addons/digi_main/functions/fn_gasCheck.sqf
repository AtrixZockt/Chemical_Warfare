#include "..\script_macros.hpp"
/////////////////////

/////////////////////

params ["_logic","_pos","_radius_max","_radius_min","_gastype"];
if(_gastype == "") then {_gastype = "Toxic"};
if(_radius_min == 0) then {_radius_min = _radius_max / 2};
_logic setVariable ["digi_gas_active", true,true];
_logic setVariable ["digi_gas_playerArr",[],true];
_logic setVariable ["digi_pos",_pos,true];
waitUntil{time > 5};


private _checkplayers = [{
	params ["_vars"];
	_vars params ["_logic","_pos","_radius_max","_radius_min","_gastype"];
	private _playerARR = _logic getVariable ["digi_gas_playerArr",[]];
	private _allUnits = if (missionNamespace getVariable ["digi_medical_affectAI",false]) then {allUnits} else {if(isMultiplayer) then {playableUnits} else {[ACE_Player]};};
	{
		private _posString = toString(_pos);
		private _logicPos = toString(getpos _logic);
		if(_posString != _logicPos) then { _pos = getpos _logic; _logic setVariable ["digi_pos",_pos,true];};
		private _distance = position _x distance _pos;
		if(isPlayer _x) then {

			if (_x getVariable ["digi_isRespawned",false] || _x getVariable ["digi_medical_isThreated",false]) then {
				_x setVariable ["digi_isRespawned",false,true];
				_x setVariable ["digi_medical_isThreated",false];
				private _arr = _playerARR find _x;
				_playerARR deleteAt _arr;
				_logic setVariable ["digi_gas_playerArr",_playerARR,true];
			};
			if(_x in _playerARR && _distance > _radius_max) then {
				private _arr = _playerARR find _x;
				_playerARR deleteAt _arr;
				_logic setVariable ["digi_gas_playerArr",_playerARR,true];
			};
			if (!(_x in _playerARR) && _distance < _radius_max) then {

				_playerARR pushBack _x;			
				_logic setVariable ["digi_gas_playerArr",_playerARR,true];
				["digi_fnc_gas_local", [_x,_logic,_pos,_radius_max,_radius_min,_gastype], _x] call CBA_fnc_targetEvent;
			};
		} else {
			if (_distance < _radius_max && alive _x && !(_x getVariable["digi_medical_enteredPoisen",false])) then {
				["digi_fnc_gas_ai", [_x,_logic,_pos,_radius_max,_gastype], _x] call CBA_fnc_targetEvent;
			};
		};
	} forEach _allUnits;

},3,[_logic,_pos,_radius_max,_radius_min,_gastype]] call CBA_fnc_addPerFrameHandler;



[{
	params["_param","_pfhHandle"];
	_param params["_logic","_checkplayers"];
	if (isNull _logic || !alive _logic || !(_logic getVariable ["digi_gas_active",false])) exitWith {
		_logic setVariable ["digi_gas_active", false, true];
		[_checkplayers] call CBA_fnc_removePerFrameHandler;
		[_pfhHandle] call CBA_fnc_removePerFrameHandler;
	};
},0,[_logic,_checkplayers]]call CBA_fnc_addPerFrameHandler;