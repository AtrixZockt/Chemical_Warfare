



[] spawn { 
	waitUntil {!(isNull player)};	
	player setVariable ["digi_medical_enteredPoisen",false,true];
	player setVariable ["digi_gas_timeleft",missionNamespace getVariable ["digi_medical_infectTime",60],true];
	player setVariable ["digi_medical_poisenType","",true];
	player setVariable ["digi_medical_airPoisend",false,true];
	player setVariable ["digi_medical_CS",false,true];
	player setVariable ["digi_gasmask_durability",10,true];

	"DIGI_CHEM_DETECTOR" cutRsc ["RscWeaponChemicalDetector", "PLAIN", 1, false];
	private _ui = uiNamespace getVariable "RscWeaponChemicalDetector";
	private _obj = _ui displayCtrl 101;
	_obj ctrlAnimateModel ["Threat_Level_Source", 0, true];

	if (player getVariable ["Digi_pain_effect",0] != 0) then {
		DIGI_PAIN_EFFECT ppEffectEnable false;
	};

	player setVariable ["digi_isRespawned",true,true];

	[{
		player setVariable ["digi_isRespawned",false,true];
	},[],10]call CBA_fnc_waitAndExecute;

};