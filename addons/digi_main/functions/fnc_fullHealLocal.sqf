#include "..\script_macros.hpp"
/*
 * Author: Glowbal
 * Local callback for fully healing a patient.
 *
 * Arguments:
 * 0: Patient <OBJECT>
 *
 * Return Value:
 * None
 *
 * Example:
 * [player] call ace_medical_treatment_fnc_fullHealLocal
 *
 * Public: No
 */

params ["_patient"]; 
TRACE_1("fullHealLocal",_patient);

if (!alive _patient) exitWith {};

private _state = [_patient,ace_medical_STATE_MACHINE] call CBA_statemachine_fnc_getCurrentState;
TRACE_1("start",_state);

// Treatment conditions would normally limit full heal to non-unconscious units
// However, this may be called externally (through Zeus)
if IN_CRDC_ARRST(_patient) then {
    TRACE_1("Exiting cardiac arrest",_patient);
    ["ace_medical_CPRSucceeded", _patient] call CBA_fnc_localEvent;
    _state = [_patient,ace_medical_STATE_MACHINE] call CBA_statemachine_fnc_getCurrentState;
    TRACE_1("after CPRSucceeded",_state);
};

_patient setVariable [VAR_PAIN, 0, true];
_patient setVariable [VAR_BLOOD_VOL, DEFAULT_BLOOD_VOLUME, true];

// GAS
_patient setVariable ["digi_medical_enteredPoisen",false,true];
_patient setVariable ["digi_medical_airPoisend",false,true];
_patient setVariable ["digi_medical_CS",false,true];
if (_patient getVariable ["Digi_pain_effect",0] != 0) then {
		DIGI_PAIN_EFFECT ppEffectEnable false;
	};

// Tourniquets
_patient setVariable [VAR_TOURNIQUET, DEFAULT_TOURNIQUET_VALUES, true];
_patient setVariable ["ace_medical_treatment_occludedMedications", nil, true];

// Wounds and Injuries
_patient setVariable [VAR_OPEN_WOUNDS, [], true];
_patient setVariable [VAR_BANDAGED_WOUNDS, [], true];
_patient setVariable [VAR_STITCHED_WOUNDS, [], true];
_patient setVariable ["ace_medical_isLimping", false, true];
_patient setVariable [VAR_FRACTURES, DEFAULT_FRACTURE_VALUES, true];

// Update wound bleeding
[_patient] call ace_medical_status_fnc_updateWoundBloodLoss;

// Vitals
_patient setVariable [VAR_HEART_RATE, DEFAULT_HEART_RATE, true];
_patient setVariable [VAR_BLOOD_PRESS, [80, 120], true];
_patient setVariable [VAR_PERIPH_RES, DEFAULT_PERIPH_RES, true];

// IVs
_patient setVariable ["ace_medical_ivBags", nil, true]; 

// Damage storage
_patient setVariable ["ace_medical_bodyPartDamage", [0,0,0,0,0,0], true];

// wakeup needs to be done after achieving stable vitals, but before manually reseting unconc var
if IS_UNCONSCIOUS(_patient) then {
    if (!([_patient] call ace_medical_status_fnc_hasStableVitals)) then { ERROR_2("fullheal [unit %1][state %2] did not restore stable vitals",_patient,_state); };
    TRACE_1("Waking up",_patient);
    ["ace_medical_WakeUp", _patient] call CBA_fnc_localEvent;
    _state = [_patient,ace_medical_STATE_MACHINE] call CBA_statemachine_fnc_getCurrentState;
    TRACE_1("after WakeUp",_state);
    if IS_UNCONSCIOUS(_patient) then { ERROR_2("fullheal [unit %1][state %2] failed to wake up patient",_patient,_state); };
};

// Generic medical admin
// _patient setVariable [VAR_CRDC_ARRST, false, true]; // this should be set by statemachine transition
// _patient setVariable [VAR_UNCON, false, true]; // this should be set by statemachine transition
_patient setVariable [VAR_HEMORRHAGE, 0, true];
_patient setVariable [VAR_IN_PAIN, false, true];
_patient setVariable [VAR_PAIN_SUPP, 0, true];

// Medication
_patient setVariable [VAR_MEDICATIONS, [], true];

// Reset triage card since medication is reset
_patient setVariable ["ace_medical_triageCard", [], true];

[_patient] call ace_medical_engine_fnc_updateDamageEffects;

// Reset damage
_patient setDamage 0;

["ace_medical_FullHeal", _patient] call CBA_fnc_localEvent;
_state = [_patient,ace_medical_STATE_MACHINE] call CBA_statemachine_fnc_getCurrentState;
TRACE_1("after FullHeal",_state);
