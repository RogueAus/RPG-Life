#include "\life_hc\hc_macros.hpp"
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

_query = switch (_side) do {
    // West - 11 entries returned
    case west: {format ["SELECT pid, name, cash, bankacc, adminlevel, donorlevel, cop_licenses, coplevel, cop_gear, blacklist, cop_stats, playtime FROM players WHERE pid='%1'",_uid];};
    // Civilian - 12 entries returned
    case civilian: {format ["SELECT pid, name, cash, bankacc, adminlevel, donorlevel, civ_licenses, arrested, civ_gear, civ_stats, civ_alive, civ_position, playtime FROM players WHERE pid='%1'",_uid];};
    // Independent - 10 entries returned
    case independent: {format ["SELECT pid, name, cash, bankacc, adminlevel, donorlevel, med_licenses, mediclevel, med_gear, med_stats, playtime FROM players WHERE pid='%1'",_uid];};
};

_queryResult = [_query,2] call HC_fnc_asyncCall;

switch (_side) do {
    case west: {
        //Playtime
        _new = [(_queryResult select 11)] call HC_fnc_mresToArray;
        if (_new isEqualType "") then {_new = call compile format ["%1", _new];};
        _queryResult set[11,_new];
    };

    case civilian: {
        //Playtime
        _new = [(_queryResult select 12)] call HC_fnc_mresToArray;
        if (_new isEqualType "") then {_new = call compile format ["%1", _new];};
        _queryResult set[12,_new];
    };

    case independent: {
        //Playtime
        _new = [(_queryResult select 10)] call HC_fnc_mresToArray;
        if (_new isEqualType "") then {_new = call compile format ["%1", _new];};
        _queryResult set[10,_new];
    };
};

_queryResult remoteExec ["SOCK_fnc_playTimeReceived",_ownerID];