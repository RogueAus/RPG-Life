#include "..\..\script_macros.hpp"
/*
    File: fn_pulloutAction.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Pulls civilians out of a car if it's stopped.
*/
private ["_crew","_vehicle"];
_crew = crew cursorObject;
_vehicle = cursorObject;

if(player distance _vehicle > 5) exitWith {hint "You're not near the vehicle"};
{
    if !(side _x isEqualTo west) then {
        _x setVariable ["transporting",false,true]; _x setVariable ["Escorting",false,true];
        [_x] remoteExecCall ["life_fnc_pulloutVeh",_x];
    };
} forEach _crew;
