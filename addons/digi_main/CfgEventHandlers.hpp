class Extended_PreInit_EventHandlers {
	class digi_medical_preInit {
		init = "call digi_fnc_registerSettings";
	};
};

class Extended_postInit_EventHandlers {
	class digi_medical_postInit {
		init = "call digi_fnc_postInit";
	};
};
/*
class Extended_InitPost_EventHandlers 
{
	class CAManBase
	{
		class digi_init
		{
			init="call digi_fnc_init";
		};
	};
};
*/
