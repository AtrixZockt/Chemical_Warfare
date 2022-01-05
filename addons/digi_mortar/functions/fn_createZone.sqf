#include "..\script_macros.hpp"
/////////////////////////////

/////////////////////////////
params["_pos","_lifetime","_radius","_gasLvL"];


private _logic = "ACE_LogicDummy" createVehicle _pos;


private _gastype = "";
    switch (_gasLvL) do {
        case 1: { //CS
            _gastype = "CS";
        }; 
        default { //toxic gas (standart)
            _gastype = "Toxic";
        };
    };
if(_gastype == "CS") then {[getPosASL _logic, _radius, _lifetime] call digi_fnc_spawnGasSmoke;};
    
[_logic,_pos,_radius,0,_gastype] call digi_fnc_gasCheck;
private _currentTime = CBA_missionTime;


[{
	//condition
	(CBA_missionTime - (_this select 2)) > (_this select 1)
},
{
	//code
	private _logic = _this select 0;
	_logic setVariable ["digi_gas_active",false,true];
	deleteVehicle _logic;
},[_logic,_lifetime,_currentTime]]call CBA_fnc_waitUntilAndExecute;
