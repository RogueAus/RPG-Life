/*
    File: fn_craft_update.sqf
    Description: Crafting System
    Created by EdgeKiller
    Coder: EdgeKiller
    Source: https://altisdev.com/topic/860/syst%C3%A8me-de-craft-par-edgekiller
    ------------------------
    Overhauled by B4v4r!4n_Str!k3r (julianbauer@cationstudio.com)
    Licence: THE OVERHAULED LINES ARE THE MINDSET OF CATIONSTUDIO
             AND ONLY AUTHORIZED PEOPLE/SERVERS ARE ALLOWED TO USE IT.
*/
private["_dialog","_inv","_mats","_item","_struct","_str","_invSize","_matsNeed","_matsNum","_config","_itemFilter","_category"]; //Declare all private variables
if (isNull player || !alive player || (player getVariable ["restrained",false]) || (player getVariable ["Escorting",false]) || life_istazed || life_action_inUse) exitWith {closeDialog 0;}; //If null / dead exit menu
if ((getNumber(missionConfigFile >> "Cation_Crafting" >> "version_4_4")) isEqualTo 1) then {
    if ((player getVariable ["playerSurrender",false]) || life_isknocked) exitWith {closeDialog 0;};
};
disableSerialization; //Disable Serialization
_dialog = findDisplay 666; //find the craft dialog/window
_inv = _dialog displayCtrl 669; //find the listbox of items can be created
_mats = _dialog displayCtrl 672;
_struct = "";
if ((lbCurSel 669) == -1) exitWith {hint format[(getText(missionConfigFile >> "Cation_Crafting" >> "SelectItemFirst"))];};
_item = lbData[669,(lbCurSel 669)];
_itemFilter = lbData[673,(lbCurSel 673)];
_category = (getArray(missionConfigFile >> "Cation_Crafting" >> "category")); 
_config = [];
{
    if (_itemFilter isEqualTo (_x select 0)) then {
        for "_i" from 2 to (count _x) do {
            _config pushBack (_x select _i);
        };
    };
} forEach _category;
{
    if (_item == _x select 0) then {
        _matsNeed = _x select 2;
        _invSize = count _matsNeed;
        for [{_i = 0},{_i < _invSize - 1},{_i = _i + 2}] do {
            _str = getText(missionConfigFile >> "VirtualItems" >> (_matsNeed select _i) >> "displayName");
            _icon = getText(missionConfigFile >> "VirtualItems" >> (_matsNeed select _i) >> "icon");
            _matsNum = _matsNeed select _i+1;
            _struct = _struct + format["%1x <img image='%3' size='1'></img> %2<br/>",_matsNum,(localize _str),_icon];
        };
    };
} foreach (_config);
if (_struct == "") then {
    _struct = getText(missionConfigFile >> "Cation_Crafting" >> "NothingNeeded");
};
_mats ctrlSetStructuredText parseText format["
<t size='0.8px'>
%1
</t>
",_struct];
