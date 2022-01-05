#include "..\script_macros.hpp"

params["_control"];

private _display = ctrlParent _control;
private _ctrlButtonOK = _display displayCtrl 1;
private _logic = missionNamespace getVariable["BIS_fnc_initCuratorAttributes_target",objNull];


_control ctrlRemoveAllEventHandlers "SetFocus";


private _fnc_onUnload = {
    private _logic = missionNamespace getVariable["BIS_fnc_initCuratorAttributes_target",objNull];
    if (isNull _logic) exitWith {};
    if!(isNull attachedTo _logic) then {
    };
};

scopeName "Main";
private _fnc_errorAndClose = {
    params ["_msg"];
    _display closeDisplay 0;
    deleteVehicle _logic;
    [_msg] call ace_zeus_fnc_showMessage;
    breakOut "Main";
};

if!(isNull attachedTo _logic) then {
    private _object = attachedTo _logic;
    switch (true) do {
        case (isNull _object): {
            ["STR_ACE_Zeus_NothingSelected"] call _fnc_errorAndClose;
        };
        case (isPlayer _object): {
            ["str_a3_cfgvehicles_moduleremotecontrol_f_errorPlayer"] call _fnc_errorAndClose;
        };
        case (!alive _object): {
            ["STR_ACE_Zeus_OnlyAlive"] call _fnc_errorAndClose;
        };
        default {};
    };
    
};

private _fnc_onConfirm = {
    params [["_ctrlButtonOK", controlNull, [controlNull]]];

    private _display = ctrlParent _ctrlButtonOK;
    if (isNull _display) exitWith {};

    private _logic = missionNamespace getVariable["BIS_fnc_initCuratorAttributes_target",objNull];
    if (isNull _logic) exitWith {};

    private _gasTypeValue = _display getVariable["digi_ui_gastype",0];
    private _gastype = "";
    switch (_gasTypeValue) do {
        case 1: { //CS
            _gastype = "CS";
        };
        default { //toxic gas (standart)
            _gastype = "Toxic";
        };
    };

    private _radius_max = _display getVariable["digi_ui_radiusMax", 20];
    private _radius_min = _display getVariable["digi_ui_radiusMin", 10]; 
    if(_radius_min > _radius_max) then {
        ["STR_DIGI_Medical_GasModule_Needbigger"] call ace_zeus_fnc_showMessage;
    } else {
        private _logic = missionNamespace getVariable["BIS_fnc_initCuratorAttributes_target",objNull];
        if (isNull _logic) exitWith {};
        
        
        if!(isNull attachedTo _logic) then {
            private _object = attachedto _logic;
            private _position = getPos _object;
            
            [_logic,_position,_radius_max,_radius_min,_gastype] spawn digi_fnc_gasCheck;

            if(_display getVariable["digi_ui_sealable",false]) then {
                [_object] call digi_fnc_createSealAction;
            };

        } else {
            private _position = getPos _logic;
            [_logic,_position,_radius_max,_radius_min,_gastype] spawn digi_fnc_gasCheck;
        };
    };
};


_display displayAddEventHandler ["unload", _fnc_onUnload];
_ctrlButtonOK ctrlAddEventHandler ["buttonclick", _fnc_onConfirm];


//Acts_carFixingWheel