#include "..\script_macros.hpp"
/////////////////////
//[] spawn digi_fnc_handleGasMaskDur;
/////////////////////
uiSleep 5;
waitUntil{!isNil "digi_medical_avail_gasmask" && player getVariable ["digi_medical_enteredPoisen", false]};

if(player getVariable ["digi_medical_enteredPoisen", false] && goggles player in DIGI_AVAIL_GASMASK) then {
	private _timeEntered = CBA_missionTime;
	private _maxTime = missionNamespace getVariable["digi_medical_gasmask_durability",900];
	private _maxDura = 10;
	private _currentDura = player getVariable["digi_gasmask_durability",10];
	[{
		params["_param","_handler"];
		_param params["_player","_timeEntered","_maxTime","_maxDura","_currentDura"];
		private _currentDura = player getVariable["digi_gasmask_durability",10];

		if (player getVariable ["digi_gasmask_durability_reset",false]) then {
			player setVariable ["digi_gasmask_durability_reset",false,true];
			[_handler] call CBA_fnc_removePerFrameHandler;
			[] spawn digi_fnc_handleGasMaskDur;
		};

		private _timeLeft = _maxTime - (CBA_missionTime - _timeEntered);
		private _prozent = round((10/_maxTime)*_timeLeft);
		
		if(_currentDura != _prozent) then {
			player setVariable["digi_gasmask_durability",_prozent];
		};
 
		if(_currentDura <= 0 || _prozent <= 0 || !(alive _player)) exitWith {
			[_handler] call CBA_fnc_removePerFrameHandler;
			player setVariable["digi_gasmask_durability",0];
			[] spawn digi_fnc_handleGasMaskDur;
		};

		if !(player getVariable ["digi_medical_enteredPoisen", false]) exitWith{
			[_handler] call CBA_fnc_removePerFrameHandler;
			[] spawn digi_fnc_handleGasMaskDur;
		};

	},1,[player,_timeEntered,_maxTime,_maxDura,_currentDura]] call CBA_fnc_addPerFrameHandler;
} else {
	waitUntil{!(player getVariable ["digi_medical_enteredPoisen", false]) || goggles player in DIGI_AVAIL_GASMASK};
	[] spawn digi_fnc_handleGasMaskDur;
}

