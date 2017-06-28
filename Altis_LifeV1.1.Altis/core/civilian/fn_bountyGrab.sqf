#include "..\..\script_macros.hpp"
/*
    File: fn_wantedGrab.sqf
    Author: ColinM

    Description:
    Prepare the array to query the crimes.
*/
private ["_display","_tab","_criminal"];
disableSerialization;
_display = findDisplay 7400;
_tab = _display displayCtrl 7402;
_criminal = lbData[7401,(lbCurSel 7401)];
_criminal = call compile format ["%1", _criminal];
if (isNil "_criminal") exitWith {};

if (life_HC_isActive) then {
    [player,_criminal] remoteExec ["HC_fnc_bountyCrimes",HC_Life];
} else {
    [player,_criminal] remoteExec ["life_fnc_bountyCrimes",RSERV];
};
