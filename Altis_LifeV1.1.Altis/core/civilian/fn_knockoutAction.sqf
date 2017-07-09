#include "..\..\script_macros.hpp"
/*
    File: fn_knockoutAction.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Knocks out the target.
*/
private "_target";
_target = param [0,objNull,[objNull]];

//Error checks
if (isNull _target) exitWith {};
if (!isPlayer _target) exitWith {};
if (player distance _target > 4) exitWith {};
if(player inArea "safezone_kav")exitWith{hint "You can't do that in a Safe Zone!"};
if(player inArea "safezone_kos")exitWith{hint "You can't do that in a Safe Zone!"};
life_knockout = true;
[player,"AwopPercMstpSgthWrflDnon_End2"] remoteExecCall ["life_fnc_animSync",RCLIENT];
sleep 0.08;
[_target,profileName] remoteExec ["life_fnc_knockedOut",_target];

sleep 3;
life_knockout = false;
