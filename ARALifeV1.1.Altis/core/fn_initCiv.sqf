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

if (!(str(player) in ["civ_1","civ_2","civ_3","civ_4","civ_5","civ_6","civ_7","civ_8","civ_9","civ_10","civ_11","civ_12","civ_13","civ_14","civ_15","civ_16","civ_17","civ_18","civ_19","civ_20","civ_21","civ_22","civ_23","civ_24","civ_25","civ_26","civ_27","civ_28","civ_29","civ_30","civ_31","civ_32","civ_33","civ_34","civ_35","civ_36","civ_37","civ_38","civ_39","civ_40","civ_41","civ_42","civ_43","civ_44","civ_45","civ_46","civ_47","civ_48","civ_49","civ_50"])) then {
    if ((FETCH_CONST(life_donorlevel) isEqualTo 0) && (FETCH_CONST(life_adminlevel) isEqualTo 0)) then {
        ["NotDonor",false,true] call BIS_fnc_endMission;
        sleep 35;
    };
};

if (str(player) in ["civ_1","civ_2","civ_3","civ_4","civ_5","civ_6","civ_7","civ_8","civ_9","civ_10","civ_11","civ_12","civ_13","civ_14","civ_15","civ_16","civ_17","civ_18","civ_19","civ_20","civ_21","civ_22","civ_23","civ_24","civ_25","civ_26","civ_27","civ_28","civ_29","civ_30","civ_31","civ_32","civ_33","civ_34","civ_35","civ_36","civ_37","civ_38","civ_39","civ_40","civ_41","civ_42","civ_43","civ_44","civ_45","civ_46","civ_47","civ_48","civ_49","civ_50"]) then {
    if ((FETCH_CONST(life_donorlevel) > 0) && (FETCH_CONST(life_adminlevel) isEqualTo 0)) then {
        ["NotFree",false,true] call BIS_fnc_endMission;
        sleep 35;
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