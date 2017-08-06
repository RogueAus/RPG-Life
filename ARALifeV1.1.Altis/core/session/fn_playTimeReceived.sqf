#include "..\..\script_macros.hpp"
/*
    File: fn_playTimeReceived.sqf
    Author: Toby "Rogue" Clark

    Description:
    Called by the server to return playtime.
*/
life_copTime = (_this select 0);
life_indTime = (_this select 1);
life_civTime = (_this select 2);
switch (playerSide) do {
    case west: {
        life_sideTime = life_copTime;
    };
    case civilian: {
        life_sideTime = life_civTime;
    };
    case independent: {
        life_sideTime = life_indTime;
    };
};
life_playTime = life_copTime + life_civTime + life_indTime;