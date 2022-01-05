


// Register fired event handlers
["ace_firedPlayer", {_this spawn digi_grenades_fnc_throwGrenade}] call CBA_fnc_addEventHandler;
["ace_firedPlayerNonLocal", {_this spawn digi_grenades_fnc_throwGrenade}] call CBA_fnc_addEventHandler;
["ace_firedNonPlayer", {_this spawn digi_grenades_fnc_throwGrenade}] call CBA_fnc_addEventHandler;