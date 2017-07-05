#include "..\script_macros.hpp"
/*
    File: fn_initCiv.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Initializes the civilian.
*/
private _altisArray = ["Land_i_Shop_01_V1_F","Land_i_Shop_01_V2_F","Land_i_Shop_01_V3_F","Land_i_Shop_02_V1_F","Land_i_Shop_02_V2_F","Land_i_Shop_02_V3_F"];
private _tanoaArray = ["Land_House_Small_01_F"];
private _spawnBuildings = [[["Altis", _altisArray], ["Tanoa", _tanoaArray]]] call TON_fnc_terrainSort;

civ_spawn_1 = nearestObjects[getMarkerPos  "civ_spawn_1", _spawnBuildings,350];
civ_spawn_2 = nearestObjects[getMarkerPos  "civ_spawn_2", _spawnBuildings,350];
civ_spawn_3 = nearestObjects[getMarkerPos  "civ_spawn_3", _spawnBuildings,350];
civ_spawn_4 = nearestObjects[getMarkerPos  "civ_spawn_4", _spawnBuildings,350];

for "_i" from 51 to 100 do {
    if (!(str(player) in ["civ_%1",_i])) then {
        if ((FETCH_CONST(life_donorlevel) isEqualTo 0) && (FETCH_CONST(life_adminlevel) isEqualTo 0)) then {
            ["NotWhitelisted",false,true] call BIS_fnc_endMission;
            sleep 35;
        };
    };
};

waitUntil {!(isNull (findDisplay 46))};
if (life_is_alive && !life_is_arrested) then {
    /* Spawn at our last position */
    player setVehiclePosition [life_civ_position, [], 0, "CAN_COLLIDE"];
} else {
    if (!life_is_alive && !life_is_arrested) then {
        if (LIFE_SETTINGS(getNumber,"save_civilian_positionStrict") isEqualTo 1) then {
            _handle = [] spawn life_fnc_civLoadout;
            waitUntil {scriptDone _handle};
            CASH = 0;
            [0] call SOCK_fnc_updatePartial;
        };
        [] call life_fnc_spawnMenu;
        waitUntil{!isNull (findDisplay 38500)}; //Wait for the spawn selection to be open.
        waitUntil{isNull (findDisplay 38500)}; //Wait for the spawn selection to be done.
    } else {
        if (life_is_arrested) then {
            life_is_arrested = false;
            [player,true] spawn life_fnc_jail;
        };
    };
};
life_is_alive = true;
player addRating 9999999;
