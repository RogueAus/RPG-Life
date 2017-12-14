#include "..\..\script_macros.hpp"
/*
    File: fn_p_openMenu.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Opens the players virtual inventory menu
*/
if (!alive player || dialog) exitWith {}; //Prevent them from opening this for exploits while dead.
createDialog "playerSettings";
disableSerialization;
switch (playerSide) do {
    case west: {
        ctrlShow[2011,false];//Disable Gang
        ctrlShow[7001,false];//Disable Crafting
        ctrlShow[3025,false];//Disable Market
    };

    case civilian: {
        ctrlShow[2012,false];//Disable Wanted List
    };

    case independent: {
        ctrlShow[2012,false];//Disable Wanted List
        ctrlShow[2011,false];//Disable Gang
        ctrlShow[7001,false];//Disable Crafting
        ctrlShow[3025,false];//Disable Market
    };
};

//Playtime//
private _sTime = floor(life_sideTime / 60);
private _pTime = floor(life_playtime / 60);
switch (playerSide) do {
    case west: {
        ctrlSetText [7005, format["Cop Playtime: %1 Hours",_sTime]];
    };

    case civilian: {
        ctrlSetText [7005, format["Civ Playtime: %1 Hours",_sTime]];
    };

    case independent: {
        ctrlSetText [7005, format["Ind Playtime: %1 Hours",_sTime]];
    };
};
ctrlSetText [7006, format["Total Playtime: %1 Hours",_pTime]];
//Playtime End//

[] call life_fnc_p_updateMenu;
