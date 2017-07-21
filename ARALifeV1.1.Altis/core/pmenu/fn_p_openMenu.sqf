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
        ctrlShow[7002,false];//Disable Bounty
        ctrlShow[3025,false];//Disable Market
    };

    case civilian: {
        ctrlShow[2012,false];//Disable Wanted List
    };

    case independent: {
        ctrlShow[2012,false];
        ctrlShow[2011,false];
        ctrlShow[7001,false];//Disable Crafting
        ctrlShow[7002,false];//Disable Bounty
        ctrlShow[2012,false];//Disable Wanted List
        ctrlShow[2011,false];//Disable Gang
        ctrlShow[7001,false];//Disable Crafting
        ctrlShow[3025,false];//Disable Market
    };
};

if (FETCH_CONST(life_adminlevel) < 1) then {
    ctrlShow[2021,false];//Disable Admin
};

[] call life_fnc_p_updateMenu;
