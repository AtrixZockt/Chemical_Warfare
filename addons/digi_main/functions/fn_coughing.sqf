#include "..\script_macros.hpp"
///////////////////////////////

///////////////////////////////


waitUntil{ player getVariable["digi_medical_airPoisend",false] };

	private _lastcought = 0;
	while {player getVariable["digi_medical_airPoisend",false]} do {
		if(!(player getVariable ["ACE_isUnconscious",false]) && alive player) then {
			private _nextcought = random [20,50,80];
			waitUntil{(CBA_missionTime - _lastcought) > _nextcought};
			if (player getVariable["digi_medical_airPoisend",false]) then {
				_lastcought = CBA_missionTime;
				player say3D "cough_1";
				addCamShake [3, 4, 0];

				private _effect = ppEffectCreate ["ChromAberration",2005];
				DIGI_PAIN_EFFECT = _effect;
				player setVariable ["Digi_pain_effect",DIGI_PAIN_EFFECT,true];
				DIGI_PAIN_EFFECT ppEffectAdjust [0, 0, false];
				DIGI_PAIN_EFFECT ppEffectCommit 0;
				DIGI_PAIN_EFFECT ppEffectEnable true;
				private _intensity     = linearConversion [0, 1, 0.5, 0, 0.06, true];
				private _initialAdjust = [_intensity       , _intensity       , true];
				private _delayedAdjust = [_intensity * 0.15, _intensity * 0.15, true];
				DIGI_PAIN_EFFECT ppEffectAdjust _initialAdjust;
				DIGI_PAIN_EFFECT ppEffectCommit 0.3;

				[{
					params ["_adjust"];
					DIGI_PAIN_EFFECT ppEffectAdjust _adjust;
					DIGI_PAIN_EFFECT ppEffectCommit 0.7;
				}, [_delayedAdjust], 3] call CBA_fnc_waitAndExecute;
			};
		};
		uiSleep 5;
	};

if(player getVariable["digi_medical_airPoisend",false]) exitWith {};
[] spawn digi_fnc_coughing;


