#include "..\script_macros.hpp"
//////////////////////////

//////////////////////////

params ["_player", "_patient"];

//abfrage ob gasmaske vorhanden hinzufügen
!(_patient call ACE_common_fnc_isAwake) && ([_player,_patient] call digi_fnc_hasGasmask) && !(goggles _patient in DIGI_AVAIL_GASMASK)
