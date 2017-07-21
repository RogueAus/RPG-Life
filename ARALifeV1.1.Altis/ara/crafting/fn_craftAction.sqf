/*
    File: fn_craftAction.sqf
    Author: EdgeKiller
    Description:
    Master handling for crafting an item.
    Source: https://altisdev.com/topic/860/syst%C3%A8me-de-craft-par-edgekiller
    ------------------------
    Overhauled by B4v4r!4n_Str!k3r (julianbauer@cationstudio.com)
    Licence: THE OVERHAULED LINES ARE THE MINDSET OF CATIONSTUDIO
             AND ONLY AUTHORIZED PEOPLE/SERVERS ARE ALLOWED TO USE IT.
*/
private["_duration","_tN","_f","_textureName","_flag","_colorIndex","_c","_vehicle","_spawnPoint","_exit","_pos","_dialog","_item","_itemInfo","_oldItem","_newItem","_upp","_itemName","_ui","_progress","_pgText","_cP","_allMaterial","_matsNeed","_invSize","_handledItem","_itemFilter","_backpackOldItems","_weight","_weightUsedItems","_category","_vItem"];
if (isNull player || !alive player || (player getVariable ["restrained",false]) || (player getVariable ["Escorting",false]) || life_istazed || life_action_inUse) exitWith {}; //If null / dead exit menu
if ((getNumber(missionConfigFile >> "Cation_Crafting" >> "version_4_4")) isEqualTo 1) then {
    if ((player getVariable ["playerSurrender",false]) || life_isknocked) exitWith {};
};
disableSerialization;
_dialog = findDisplay 666;
_spawnPoint = _dialog getVariable ["spawn",""];
if ((lbCurSel 669) == -1) exitWith {hint format[(getText(missionConfigFile >> "Cation_Crafting" >> "SelectItemFirst"))];};
_item = lbData[669,(lbCurSel 669)];
_allMaterial = true;
_itemFilter = lbData[673,(lbCurSel 673)];
_matsNeed = 0;
_pos = getPos player;
_exit = false;
_vItem = -1;
_duration = (getNumber(missionConfigFile >> "Cation_Crafting" >> "duration"));
if (_duration <= 0 || _duration > 10) then {
    _duration = 0.3;
};
if (player distance _pos > 10) exitWith {};
_category = (getArray(missionConfigFile >> "Cation_Crafting" >> "category"));
_config = [];
{
    if (_itemFilter isEqualTo (_x select 0)) then {
        for "_i" from 2 to (count _x) do {
            _config pushBack (_x select _i);
        };
    };
} forEach _category;

life_action_inUse = true;//Lock out other actions during processing.

{
    if (_item == _x select 0)then {
        _matsNeed = _x select 2;
        _tN = _x select 3;
        _f = _x select 4;
        _invSize = count _matsNeed;
        for [{_i=0},{_i<_invSize-1},{_i=_i+2}] do {
            _matsNum = _matsNeed select _i+1;
            if ((missionNamespace getVariable [format["life_inv_%1",(getText(missionConfigFile >> "VirtualItems" >> (_matsNeed select _i) >> "variable"))],0]) < _matsNum) then {_allMaterial = false;};           
        };
        _vItem = _x select 5;
    };
} foreach (_config);
_newItem = _item;
if (!_allMaterial) exitWith {hint format[(getText(missionConfigFile >> "Cation_Crafting" >> "NoMaterial"))]; life_action_inUse = false;};
//Some checks
if ((count _matsNeed) == 0) exitWith {life_action_inUse = false;};
switch (_itemFilter) do {
    case "backpack": {
        if (!(player canAdd _newItem)) then {
            if (!(backpack player isEqualTo "")) exitWith {
                hint format[(getText(missionConfigFile >> "Cation_Crafting" >> "NotificationBackpack"))];
                _exit = true;
            };
        };
    };
    case "vest": {
        if (!(player canAdd _newItem)) then {
            if (!(vest player isEqualTo "")) exitWith {
                hint format[(getText(missionConfigFile >> "Cation_Crafting" >> "NotificationVest"))];
                _exit = true;
            };
        };
    };
    case "uniform": {
        if (!(player canAdd _newItem)) then {
            if (!(uniform player isEqualTo "")) exitWith {
                hint format[(getText(missionConfigFile >> "Cation_Crafting" >> "NotificationUnifrom"))];
                _exit = true;
            };
        };
    };
    case "weapon": {
        switch (getNumber(configFile >> "CfgWeapons" >> _newItem >> "type")) do {
            case 1: {
                if (!(primaryWeapon player isEqualTo "")) then {
                    if (!(player canAdd _newItem)) then {
                        _exit = true;
                        hint format[(getText(missionConfigFile >> "Cation_Crafting" >> "NoRoom"))];
                    };
                };
            };
            case 2: {
                if (!(handGunWeapon player isEqualTo "")) then {
                    if (!(player canAdd _newItem)) then {
                        _exit = true;
                        hint format[(getText(missionConfigFile >> "Cation_Crafting" >> "NoRoom"))];
                    };
                };
            };
            case 4: {
                if (!(secondaryWeapon player isEqualTo "")) then {
                    if (!(player canAdd _newItem)) then {
                        _exit = true;
                        hint format[(getText(missionConfigFile >> "Cation_Crafting" >> "NoRoom"))];
                    };
                };
            };
        };
    };
    default {
        if (_vItem isEqualTo 1) then {
            _weight = [_item] call life_fnc_itemWeight;
            _weightUsedItems = 0;
            for [{_i=0},{_i<(count _matsNeed)-1},{_i=_i+2}] do {
                _matsNum = _matsNeed select _i+1;
                _weightUsedItems = _weightUsedItems + (([(_matsNeed select _i)] call life_fnc_itemWeight) * _matsNum);
            };
            if ((life_carryWeight - _weightUsedItems + _weight) > life_maxWeight) exitWith {
                hint localize "STR_NOTF_NoRoom";
                _exit = true;
            };
        } else {
            if (!(player canAdd _newItem)) exitWith {
                hint format[(getText(missionConfigFile >> "Cation_Crafting" >> "NoRoom"))];
                _exit = true;
            };
        };
    };
};
if (_exit) exitWith {
    life_action_inUse = false;
};
_oldItem = _matsNeed;

if (_itemFilter == "item") then {
    _itemName = localize getText(missionConfigFile >> "VirtualItems" >> _newItem >> "displayName");
} else {
	_itemInfo = [_newItem] call life_fnc_fetchCfgDetails;
	_itemName = _itemInfo select 1;
};

life_is_processing = true;
_upp = format["%1 %2 - %3",(getText(missionConfigFile >> "Cation_Crafting" >> "Craft")),_itemName,_tN];
closeDialog 0;
//Setup our progress bar.
disableSerialization;
5 cutRsc ["life_progress","PLAIN"];
_ui = uiNameSpace getVariable "life_progress";
_progress = _ui displayCtrl 38201;
_pgText = _ui displayCtrl 38202;
_pgText ctrlSetText format["%2 (1%1)...","%",_upp];
_progress progressSetPosition 0.01;
_cP = 0.01;
_removeItemSuccess = true;
_invSize = count _oldItem;
for [{_i=0},{_i<_invSize-1},{_i=_i+2}] do {
    _handledItem = (_oldItem select _i);
    if (!([false,_handledItem,_oldItem select _i+1] call life_fnc_handleInv)) exitWith {_removeItemSuccess = false;};
};
if (!_removeItemSuccess) exitWith {5 cutText ["","PLAIN"]; life_is_processing = false; life_action_inUse = false;};

for "_i" from 0 to 1 step 0 do {
    sleep _duration;
    _cP = _cP + 0.01;
    _progress progressSetPosition _cP;
    _pgText ctrlSetText format["%3 (%1%2)...",round(_cP * 100),"%",_upp];
    if(_cP >= 1) exitWith {};
    if (isNull player || !alive player || (player getVariable ["restrained",false]) || (player getVariable ["Escorting",false]) || life_istazed) exitWith {}; //If null / dead exit menu
    if ((getNumber(missionConfigFile >> "Cation_Crafting" >> "version_4_4")) isEqualTo 1) then {
        if ((player getVariable ["playerSurrender",false]) || life_isknocked) exitWith {};
    };
    if (player distance _pos > 10) exitWith {};
};
if (player distance _pos > 10) exitWith {
    hint format[(getText(missionConfigFile >> "Cation_Crafting" >> "Process_Stay"))]; 5 cutText ["","PLAIN"]; life_is_processing = false; life_action_inUse = false;
    for [{_i=0},{_i<_invSize-1},{_i=_i+2}] do {
        _handledItem = (_oldItem select _i);
        [true,_handledItem,_oldItem select _i+1] call life_fnc_handleInv;
    };
    life_is_processing = false;  
    life_action_inUse = false;
};
if (isNull player || !alive player || (player getVariable ["restrained",false]) || (player getVariable ["Escorting",false]) || life_istazed) exitWith {
    for [{_i=0},{_i<_invSize-1},{_i=_i+2}] do {
        _handledItem = (_oldItem select _i);
        [true,_handledItem,_oldItem select _i+1] call life_fnc_handleInv;
    };
    life_is_processing = false;
    life_action_inUse = false;
}; //If null / dead exit menu
if ((getNumber(missionConfigFile >> "Cation_Crafting" >> "version_4_4")) isEqualTo 1) then {
    if ((player getVariable ["playerSurrender",false]) || life_isknocked) exitWith {
        for [{_i=0},{_i<_invSize-1},{_i=_i+2}] do {
            _handledItem = (_oldItem select _i);
            [true,_handledItem,_oldItem select _i+1] call life_fnc_handleInv;
        };
        life_is_processing = false;
        life_action_inUse = false;
    };
};
_exit = false;
switch (_itemFilter) do {
    case "backpack": {
        if (player canAdd _newItem) then {
            player addItem _newItem;
        } else {
            if (backpack player isEqualTo "") then {
                player addBackpack _newItem;
            } else {
                hint format[(getText(missionConfigFile >> "Cation_Crafting" >> "NotificationBackpack"))];
                _exit = true;
            };
        };
    };
    case "vest": {
        if (player canAdd _newItem) then {
            player addItem _newItem;
        } else {
            if (vest player isEqualTo "") then {
                player addVest _newItem;
            } else {
                hint format[(getText(missionConfigFile >> "Cation_Crafting" >> "NotificationVest"))];
                _exit = true;
            };
        };
    };
    case "uniform": {
        if (player canAdd _newItem) then {
            player addItem _newItem;
        } else {
            if (uniform player isEqualTo "") then {
                player addUniform _newItem;
            } else {
                hint format[(getText(missionConfigFile >> "Cation_Crafting" >> "NotificationUnifrom"))];
                _exit = true;
            };
        };
    };
    case "weapon": {
        switch (getNumber(configFile >> "CfgWeapons" >> _newItem >> "type")) do {
            case 1: {
               if (primaryWeapon player isEqualTo "") then {
                    player addWeapon _newItem;
                } else {
                    if (player canAdd _newItem) then {
                        player addItem _newItem;
                    } else {
                        _exit = true;
                        hint format[(getText(missionConfigFile >> "Cation_Crafting" >> "NoRoom"))];
                    };
                };
            };
            case 2: {
                if (handGunWeapon player isEqualTo "") then {
                    player addWeapon _newItem;
                } else {
                    if (player canAdd _newItem) then {
                        player addItem _newItem;
                    } else {
                        _exit = true;
                        hint format[(getText(missionConfigFile >> "Cation_Crafting" >> "NoRoom"))];
                    };
                };
            };
            case 4: {
                if (secondaryWeapon player isEqualTo "") then {
                    player addWeapon _newItem;
                } else {
                    if (player canAdd _newItem) then {
                        player addItem _newItem;
                    } else {
                        _exit = true;
                        hint format[(getText(missionConfigFile >> "Cation_Crafting" >> "NoRoom"))];
                    };
                };
            };
        };
    };
    default {
        if (_vItem isEqualTo 1) then {
            _handledItem = _newItem;
	    if (!([true,_handledItem,1] call life_fnc_handleInv)) then { _exit = true; };
        } else {
            if (player canAdd _newItem) then {
                player addItem _newItem;
            } else {
                hint format[(getText(missionConfigFile >> "Cation_Crafting" >> "NoRoom"))];
                _exit = true;
            };
        };
    };
};
if (_exit) exitWith {
    for [{_i=0},{_i<_invSize-1},{_i=_i+2}] do {
        _handledItem = (_oldItem select _i);
        [true,_handledItem,_oldItem select _i+1] call life_fnc_handleInv;
    };
    5 cutText ["","PLAIN"];
    [0] call SOCK_fnc_updatePartial;
    life_is_processing = false;
    life_action_inUse = false;
};
5 cutText ["","PLAIN"];
titleText[format["%1 %2",(getText(missionConfigFile >> "Cation_Crafting" >> "Process")),_itemName],"PLAIN"]; 
[0] call SOCK_fnc_updatePartial;
life_is_processing = false;
life_action_inUse = false;