#include "..\..\script_macros.hpp"
/*
    File: fn_playTimeQuery.sqf
    Author: Toby "Rogue" Clark

    Description:
    Starts the 'authentication' process and sends a request out to
    the server to check for players time played.
*/
private ["_uid","_side","_sender"];
_sender = player;
_uid = getPlayerUID _sender;
_side = playerSide;

if (life_HC_isActive) then {
    [_uid,_side,_sender] remoteExec ["HC_fnc_queryRequest",HC_Life];
} else {
    [_uid,_side,_sender] remoteExec ["DB_fnc_playTimeRequest",RSERV];
};
