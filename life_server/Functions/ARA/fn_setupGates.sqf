#include "\life_server\script_macros.hpp"
/*
    File: fn_setupGates.sqf
    Author: Rogue & KillerAussie

    Description:
    Initialize gates for Jail & Cop Locations.
*/
//Police Gates
private _police = [[3357.32,12965.7,0],[3221.68,12935.1,0]];//Array of locked door positions
{
    private _gate = nearestObject [_x,"Land_ConcreteWall_01_l_gate_F"];
    _gate setVariable ["bis_disabled_Door_1",1,true];
    _gate animateSource ["Door_1_source",0];
    _gate setVariable ["locked",true,true];
} forEach _police;

//Jail Gates & Doors
private _jail = [];
{
    private _gate = nearestObject [_x,"Land_ConcreteWall_01_l_gate_F"];
    _gate setVariable ["bis_disabled_Door_1",1,true];
    _gate animateSource ["Door_1_source",0];
    _gate setVariable ["locked",true,true];
    private _door = nearestObject [_x,""];
    _door setVariable ["bis_disabled_Door_1",1,true];
    _door animateSource ["Door_1_source",0];
    _door setVariable ["locked",true,true];
    private _cell = nearestObject [_x,""];
    _cell setVariable ["bis_disabled_Door_1",1,true];
    _cell animateSource ["Door_1_source",0];
    _cell setVariable ["locked",true,true];
} forEach _jail;
