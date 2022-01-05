#include "..\script_macros.hpp"
//////////////////////////

//////////////////////////

params ["_unit","_logic","_pos","_radius_max","_radius_min","_gastype"];

[
	{
		params["_args","_handler"];
		_args params ["_logic","_unit","_pos"];
		private _posString = toString(_logic getVariable ["digi_pos",[0,0,0]]);
		private _logicPos = toString(getpos _logic);
		if!(_logic getVariable["digi_gas_active",false]) then {
			if(_unit getVariable["digi_medical_enteredPoisen",false]) then {
				_unit setVariable["digi_medical_enteredPoisen",false,true];
				[_handler] call CBA_fnc_removePerFrameHandler;
			};
		};
	},
	3,
	[_logic,_unit,_pos]
]call CBA_fnc_addPerFrameHandler;
 

while{_logic getVariable ["digi_gas_active", false] && !(isNull _logic) && _unit in (_logic getVariable ["digi_gas_playerArr",[]])} do {

	_pos = _logic getVariable ["digi_pos",[0,0,0]];
	if(_unit distance _pos <= _radius_max && !(_unit getVariable["digi_medical_enteredPoisen",false]) && !(_unit getVariable ["ACE_isUnconscious",false])) then {


		_unit setVariable ["digi_medical_enteredPoisen", true, true];
		_unit setVariable ["digi_medical_Poisen_logic",_logic,true];
		private _timeEntered = CBA_missionTime;
		

		_fnc_digi_afterwait = {
			params["_unit","_timeEntered","_logic","_gastype","_radius_max"];
			 
			if(goggles _unit in DIGI_AVAIL_GASMASK) then {

				private _maskTime = missionNamespace getVariable["digi_medical_gasmask_durability",900];
				private _isinGas = true; 
				while {_isinGas} do {
						private _timeleft = _unit getVariable["digi_gasmask_durability",10];
						_pos = _logic getVariable ["digi_pos",[0,0,0]];
						if ( _unit distance _pos > _radius_max || !(_logic getVariable["digi_gas_active",false]) || isNull _logic ) exitWith {
							_unit setVariable["digi_medical_enteredPoisen",false,true];
							_isinGas = false;
						};

						if !(goggles _unit in DIGI_AVAIL_GASMASK && _timeleft > 0) then {
							_unit setVariable ["digi_medical_poisenType",_gastype,true];
							if(_gastype == "Toxic") then {_unit setVariable ["digi_medical_airPoisend",true,true];};
							if(_gastype == "CS") then {_unit setVariable ["digi_medical_CS",true,true]; [_logic,_radius_max] spawn digi_fnc_handleCSGas;};

							_isinGas = false;
						};

						if(_timeleft <= 0 && _unit getVariable ["digi_medical_enteredPoisen",false]) then {
							_unit setVariable ["digi_medical_poisenType",_gastype,true];
							if(_gastype == "Toxic") then {_unit setVariable ["digi_medical_airPoisend",true,true];};
							if(_gastype == "CS") then {_unit setVariable ["digi_medical_CS",true,true]; [_logic,_radius_max] spawn digi_fnc_handleCSGas;};
							_isinGas = false;
						};

						if (!(_unit getVariable ["digi_medical_enteredPoisen",false]) || !(_logic getVariable["digi_gas_active",false])) then {
							
							_isinGas = false;
							_unit setVariable ["digi_medical_enteredPoisen",false];
						};
						uiSleep 1;
				};

			} else {
				if(_unit getVariable ["digi_medical_enteredPoisen",false]) then {
					_unit setVariable ["digi_medical_poisenType",_gastype,true];
					if(_gastype == "Toxic") then {_unit setVariable ["digi_medical_airPoisend",true,true];};
					if(_gastype == "CS") then {_unit setVariable ["digi_medical_CS",true,true]; [_logic,_radius_max] spawn digi_fnc_handleCSGas;};
				};
			};
		};
		//time in gas before something happens (todo: move to addonoptions)
		

			private _prozent = 1;
			for "_i" from 0 to 1 step 0 do {
				_pos = _logic getVariable ["digi_pos",[0,0,0]];
				private _distance = _unit distance _pos;
				private _min_to_max = _radius_max - _radius_min;
				private _dis_to_min = _distance - _radius_min;
				if(_distance > _radius_min) then {
					_prozent = 1-(_dis_to_min/_min_to_max);
					if(_prozent > 1) then {_prozent = 1};
				} else {
					_prozent = 1;
				};
				_unitTime = _unit getVariable ["digi_gas_timeleft",60];
				_unitTime = _unitTime - _prozent;
				_unit setVariable ["digi_gas_timeleft",_unitTime];
				_unit setVariable ["digi_gas_percente",_prozent];
				if(_unitTime <= 0) exitWith {
					[_unit,_timeEntered,_logic,_gastype,_radius_max] spawn _fnc_digi_afterwait;
					_unit setVariable ["digi_gas_timeleft",0];
					_i = 2;
				};

					
				if ( _unit distance _pos > _radius_max || !(_logic getVariable["digi_gas_active",false]) || isNull _logic ) exitWith {
					_unit setVariable["digi_medical_enteredPoisen",false,true];
					_i = 2;
				};

				if(_gastype == "CS") exitWith {
					_i = 2;
					[_unit,_timeEntered,_logic,_gastype,_radius_max] spawn _fnc_digi_afterwait;
				};
				uiSleep 1;
			};

	};
};