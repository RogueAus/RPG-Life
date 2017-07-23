#include "..\..\script_macros.hpp"
/*
    File: fn_playTimeReceived.sqf
    Author: Toby "Rogue" Clark

    Description:
    Called by the server to return playtime.
*/
life_copTime = ((_this select 0) select 0);
life_indTime = ((_this select 0) select 1);
life_civTime = ((_this select 0) select 2);
life_playTime = life_copTime + life_civTime + life_indTime;