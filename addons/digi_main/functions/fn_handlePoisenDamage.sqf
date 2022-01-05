#include "..\script_macros.hpp"
////////////////////////////////

////////////////////////////////


[] spawn { 
	_fnc_airpoisen = {
		player setVariable ["digi_medical_airPoisend",true,true];
		
		[player, "RightArm", "PoisenBP"] call digi_fnc_medicationLocal;
		DIGI_lastpoisend = CBA_missionTime;
		waitUntil {(CBA_missionTime - DIGI_lastpoisend) > 30};
		[] spawn digi_fnc_handlePoisenDamage;
	};
	

	
	waitUntil {!(player getVariable ["ACE_isUnconscious",false]) };
	waitUntil {player getVariable ["digi_medical_airPoisend",false] || player getVariable ["digi_medical_CS",false]};
	if(player getVariable ["digi_medical_airPoisend",false]) then {
		[] spawn _fnc_airpoisen;
	};
};




