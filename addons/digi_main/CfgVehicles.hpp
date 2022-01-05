class cfgVehicles {
    class Man;
    class CAManBase: Man {
        class ACE_SelfActions {
            class ACE_Equipment {
                class DiGi_CheckGasMaskDur {
                    displayName = "$STR_DIGI_Medical_CheckGasMaskDurability";
                    condition = "goggles _player in DIGI_AVAIL_GASMASK";
                    exceptions[] = {"isNotSwimming", "isNotInside", "isNotSitting"};
                    statement = "_this call digi_fnc_checkGasMaskDur";
                    showDisabled = 0;
                    icon = "\DiGi_ACE_Extension_gas_more\addons\digi_main\ui\digi_Gasmask_icon";
                };
                class DiGi_ChangeGasMaskFilter {
                    displayName = "$STR_DIGI_Medical_ChangeGasMaskFilter";
                    condition = "goggles _player in DIGI_AVAIL_GASMASK && 'digi_gasmaskFilter' in items _player";
                    exceptions[] = {"isNotSwimming", "isNotInside", "isNotSitting"};
                    statement = "_this call digi_fnc_changeGasMaskFilter";
                    showDisabled = 0;
                    icon = "\DiGi_ACE_Extension_gas_more\addons\digi_main\ui\gasmaskfilter_ca";
                };
            }; 
        };
    };


    class Thing;
    class ACE_MedicalLitter_antidot: Thing {
        scope = 1;
        scopeCurator = 0;
        displayName = " ";
        destrType = "DestructNo";
        model = "DiGi_ACE_Extension_gas_more\addons\digi_main\data\littergeneric_antidote";
    };
    class ACE_MedicalLitter_PoisenBP: Thing {
        scope = 1;
        scopeCurator = 0;
        displayName = " ";
        destrType = "DestructNo";
        model = "";
    };

    class Item_Base_F;

    class digi_Antidot_Item: Item_Base_F {
        scope = 2;
        scopeCurator = 2;
        displayName = "$STR_DIGI_Medical_AntidotItem";
        author = "DiGii";
        vehicleClass = "Items";
        editorCategory = "EdCat_Equipment";
        editorSubcategory = "EdSubcat_InventoryItems";
        class TransportItems {
            class _xx_digi_Antidot {
                name = "digi_Antidot";
                count = 1;
            };
        };
    };

    class digi_sealant_Item: Item_Base_F {
        scope = 2;
        scopeCurator = 2;
        displayName = "$STR_DIGI_Medical_sealantItem";
        author = "DiGii";
        vehicleClass = "Items";
        editorCategory = "EdCat_Equipment";
        editorSubcategory = "EdSubcat_InventoryItems";
        class TransportItems {
            class _xx_digi_sealant {
                name = "digi_sealant";
                count = 1;
            };
        };
    };

    class digi_gasmaskFilter_Item: Item_Base_F {
        scope = 2;
        scopeCurator = 2;
        displayName = "$STR_DIGI_Medical_GasFilterItem";
        author = "DiGii";
        vehicleClass = "Items";
        editorCategory = "EdCat_Equipment";
        editorSubcategory = "EdSubcat_InventoryItems";
        class TransportItems {
            class _xx_digi_gasmaskFilter {
                name = "digi_gasmaskFilter";
                count = 1;
            };
        };
    };



    class Logic;
    class Module_F: Logic
	{
		class AttributesBase
		{
            class Default;
			class Edit;					// Default edit box (i.e., text input field)
			class Combo;				// Default combo box (i.e., drop-down menu)
			class Checkbox;				// Default checkbox (returned value is Boolean)
			class CheckboxNumber;		// Default checkbox (returned value is Number)
			class ModuleDescription;	// Module description
			class Units;	
		};
        class ModuleDescription;
	};

    class digi_module_gas: Module_F
    {
        scope = 2;
        side=7;
        displayName = "$STR_DIGI_Medical_GasModule_Displayname";
        category = "DIGI_missionModules";
        function = "digi_fnc_gasmodule";
    	isTriggerActivated = 0;
        functionPriority = 1;
        isGlobal = 1;

        class Arguments: AttributesBase
        {
            class Raduis_MAX 
            {
                displayName = "Maximum Range: ";
                tooltip = "$STR_DIGI_Medical_GasModule_max_radius_dcs";
                typeName = "NUMBER";
                defaultValue = 20;
            };
            class Raduis_MIN
            {
                displayName = "Minimal Range: ";
                tooltip = "$STR_DIGI_Medical_GasModule_min_radius_dcs";
                typeName = "NUMBER";
                defaultValue = 10;
            };
            class GAS_Type
            {
                displayName = "Gas Type: ";
                typeName = "STRING";
                class values {
                    class toxicgas {
                        name = "Toxic gas (Level 1)";
                        value = "Toxic";
                        default = 1;
                    };
                   /* class csgas {
                        name = "CS-Gas (Level 2)";
                        value = "CS";
                    };*/
                };
            };
            class ISSealabe
            {
                displayName = "Is sealable";
                toolTip = "ONLY WORKS IF LOGIC IS SYNCED WITH AN OBJECT!";
                typeName = "BOOL";
                defaultValue = 0;
            };
        };

        class ModuleDescription: ModuleDescription {
            description = "$STR_DIGI_Medical_GasModule_description";
            sync[] = {"LocationArea_F"};

            class LocationArea_F {
                position = 0;
                optional = 0;
                duplicate = 1;
                synced[] = {"Anything"};
            };
        };
    };

    class digi_module_zeus_gas: Module_F
    {
        scope = 1;
        scopeCurator = 2;
        side=7;
        curatorCanAttach = 1;
        displayName = "$STR_DIGI_Medical_GasModule_Displayname";
        category = "DIGI_missionModules";
        curatorInfoType = "digi_RscGasModul";
    	isTriggerActivated = 0;
        functionPriority = 1;
        isGlobal = 1;
    };
};