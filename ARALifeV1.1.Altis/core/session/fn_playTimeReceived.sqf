#include "..\..\script_macros.hpp"
/*
    File: fn_playTimeReceived.sqf
    Author: Toby "Rogue" Clark

    Description:
    Called by the server saying that we have a response so let's
    sort through the information, validate it and if all valid
    set the client up.
*/
switch (playerSide) do {
    case west: {
        life_copTime = ((_this select 11) select 0);
        life_indTime = ((_this select 11) select 1);
        life_civTime = ((_this select 11) select 2);
        life_playTime = life_copTime + life_civTime + life_indTime;
    };

    case civilian: {
        life_copTime = ((_this select 12) select 0);
        life_indTime = ((_this select 12) select 1);
        life_civTime = ((_this select 12) select 2);
        life_playTime = life_copTime + life_civTime + life_indTime;
    };

    case independent: {
        life_copTime = ((_this select 10) select 0);
        life_indTime = ((_this select 10) select 1);
        life_civTime = ((_this select 10) select 2);
        life_playTime = life_copTime + life_civTime + life_indTime;
    };
};