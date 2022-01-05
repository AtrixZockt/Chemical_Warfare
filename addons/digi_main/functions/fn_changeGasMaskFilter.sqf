#include "..\script_macros.hpp"
///////////////////////////////

///////////////////////////////

params ["_player"];
//Remove item

[_player, "AinvPknlMstpSlayWlnrDnon_medicOther"] call ace_common_fnc_doAnimation;
_player removeItem "digi_gasmaskFilter";

_player setVariable ["digi_gasmask_durability",10,true];

_player setVariable ["digi_gasmask_durability_reset", true, true];
