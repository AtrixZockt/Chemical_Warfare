#include "..\script_macros.hpp"


private _logic = param [0,objNull,[objNull]];
private _activated = param [2,true,[true]];
private _radius_max = _logic getVariable ["Raduis_MAX",20];
private _radius_min = _logic getVariable ["Raduis_MIN",10];
private _gastype = _logic getVariable ["GAS_Type","Toxic"];
private _isSealable = _logic getVariable ["ISSealabe",false];
 
if (_activated) then {
	if(count synchronizedObjects _logic > 0) then {
		private _object = (synchronizedObjects _logic) select 0;
		private _pos = getPos _object;
		if(_isSealable) then {[_object] call digi_fnc_createSealAction;};
		
		[_object,_pos,_radius_max,_radius_min,_gastype] spawn digi_fnc_gasCheck;
	} else {
		private _pos = getPos _logic;
		[_logic,_pos,_radius_max,_radius_min,_gastype] spawn digi_fnc_gasCheck;
	};
	 
	
};


