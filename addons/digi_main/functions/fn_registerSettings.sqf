#define CBA_SETTINGS_DIGI "DIGI Chemical warfare"


missionNamespace setVariable ["digi_medical_avail_gasmask",nil];
[
	"digi_medical_avail_gasmask",
	"EDITBOX",
	["$STR_DIGI_Medical_setting_gasmask_title", "$STR_DIGI_Medical_setting_gasmask_desc"],
	CBA_SETTINGS_DIGI,
	"""G_AirPurifyingRespirator_01_F""",
	true,
	{},
	true
] call CBA_fnc_addSetting;

missionNamespace setVariable ["digi_medical_gasmask_durability",nil];
[
	"digi_medical_gasmask_durability",
	"TIME",
	["$STR_DIGI_Medical_setting_gasmask_durab_title", "$STR_DIGI_Medical_setting_gasmask_durab_desc"],
	CBA_SETTINGS_DIGI,
	[1, 3600, 900],
	true,
	{},
	true
] call CBA_fnc_addSetting;

missionNamespace setVariable ["digi_medical_infectTime",nil];
[
	"digi_medical_infectTime",
	"TIME",
	["$STR_DIGI_Medical_setting_infecttime_title", "$STR_DIGI_Medical_setting_infecttime_desc"],
	CBA_SETTINGS_DIGI,
	[1, 600, 60],
	true,
	{},
	true
] call CBA_fnc_addSetting;


missionNamespace setVariable ["digi_medical_affectAI",nil];
[
	"digi_medical_affectAI",
	"CHECKBOX",
	["$STR_DIGI_Medical_setting_affectAI_title","$STR_DIGI_Medical_setting_affectAI_desc"],
	CBA_SETTINGS_DIGI,
	false,
	true,
	{},
	true
] call CBA_fnc_addSetting;
