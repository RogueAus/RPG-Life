#include "\life_server\script_macros.hpp"
/*
    File: fn_setupGates.sqf
    Author: Rogue & KillerAussie

    Description:
    Initialize gates for Jail & Cop Locations.
*/
//Police Gates
private _police = [[3357.32,12965.7,0],[3221.68,12935.1,0]];//Array of gate positions
{
    _gate = nearestObject [_x,"Land_ConcreteWall_01_l_gate_F"];
    _gate setVariable ["bis_disabled_Door_1",1,true];
    _gate animateSource ["Door_1_source",0];
    _gate setVariable ["locked",true,true];
} forEach _police;