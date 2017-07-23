#include "\life_server\script_macros.hpp"
/*
    File: fn_playTimeRequest.sqf
    Author: Toby "Rogue" Clark

    Description:
    Handles the incoming request and sends an asynchronous query
    request to the database.

    Return:
    ARRAY - If array has 0 elements it should be handled as an error in client-side files.
    STRING - The request had invalid handles or an unknown error and is logged to the RPT.
*/
private ["_uid","_side","_query","_queryResult"];
_uid = [_this,0,"",[""]] call BIS_fnc_param;
_side = [_this,1,sideUnknown,[civilian]] call BIS_fnc_param;
_ownerID = [_this,2,objNull,[objNull]] call BIS_fnc_param;

if (isNull _ownerID) exitWith {};
_ownerID = owner _ownerID;

_query = format ["SELECT playtime FROM players WHERE pid='%1'",_uid];};

_queryResult = [_query,2] call DB_fnc_asyncCall;


_new = [(_queryResult select 0)] call DB_fnc_mresToArray;
if (_new isEqualType "") then {_new = call compile format ["%1", _new];};
_queryResult set[0,_new];


_queryResult remoteExec ["SOCK_fnc_playTimeReceived",_ownerID];