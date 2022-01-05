#include "..\script_macros.hpp"

//////////////////////

//////////////////////

params [["_player", objNull, [objNull]],["_patient", objNull, [objNull]]];


private _playerarr = _player call ace_common_fnc_uniqueItems;
private _playerhasGasmask = false;
{ if(_x in DIGI_AVAIL_GASMASK) then {_playerhasGasmask = true} } forEach _playerarr;

private _patientarr = _patient call ace_common_fnc_uniqueItems;
private _patienthasGasmask = false;
{ if(_x in DIGI_AVAIL_GASMASK) then {_patienthasGasmask = true} } forEach _patientarr;

if (!_playerhasGasmask && !_patienthasGasmask) then { false } else { true }