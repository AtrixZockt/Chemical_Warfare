#include "..\script_macros.hpp"
///////////////////

///////////////////

//INIT Gasmasks

[] spawn {
	waitUntil {!isNil "digi_medical_avail_gasmask" && time > 1};
	private _items = missionNamespace getVariable ["digi_medical_avail_gasmask","""G_AirPurifyingRespirator_01_F"""];
	private _item_arr = [_items,"CfgGlasses"] call digi_fnc_getList;
	DIGI_AVAIL_GASMASK = _item_arr;
	publicVariable "DIGI_AVAIL_GASMASK";

	waitUntil {!isNil "digi_medical_affectAI"};
	private _affectAI = missionNamespace getVariable ["digi_medical_affectAI",false];
	DIGI_AFFECT_AI = _affectAI;
	publicVariable "DIGI_AFFECT_AI";
};



if(hasInterface) then {

	[] spawn digi_fnc_coughing;
	[] spawn digi_fnc_handlePoisenDamage;
	[] spawn digi_fnc_handleGasMaskDur;
	[] spawn digi_fnc_chemDetector;
	[player] spawn digi_fnc_breathing;
	DIGI_lastpoisend = 0;
	player addEventHandler ["killed", {call digi_fnc_handleRespawn}];
	[] spawn {
		call digi_fnc_handleRespawn;
	};
	player setVariable["digi_gas_timeleft",missionNamespace getVariable ["digi_medical_infectTime",60],true];
	player setVariable ["digi_medical_enteredPoisen",false,true];
	player setVariable ["digi_gasmask_durability",10,true];
	player setVariable ["digi_gasmask_durability_reset", false, true];
	

	[{
		private _playertime = player getVariable["digi_gas_timeleft",60];
		private _maxtime = missionNamespace getVariable ["digi_medical_infectTime",60];
		if (!(player getVariable["digi_medical_enteredPoisen",false]) ) then {
			if(_playertime < missionNamespace getVariable ["digi_medical_infectTime",60]) then {
				_playertime = _playertime + 1;
				if(_playertime >= _maxtime) then {
					_playertime = _maxtime;
				};
				player setVariable["digi_gas_timeleft",_playertime,true];
			};
		};
	},2,[]]call CBA_fnc_addPerFrameHandler;

	[{
		"DIGI_CHEM_DETECTOR" cutRsc ["RscWeaponChemicalDetector", "PLAIN", 1, false];
		private _ui = uiNamespace getVariable "RscWeaponChemicalDetector";
		private _obj = _ui displayCtrl 101;
		if (!(player getVariable["digi_medical_enteredPoisen",false]) ) then { 
			_obj ctrlAnimateModel ["Threat_Level_Source", 0, true];
		};
	},2,[]]call CBA_fnc_addPerFrameHandler;
};




