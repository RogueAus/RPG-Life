#include "\life_server\script_macros.hpp"
/*
    File: fn_setupGates.sqf
    Author: Rogue & KillerAussie

    Description:
    Initialize gates for Jail & Cop Locations.
*/
//Single Doors and Gates
//Police Gates
private _policePos = [[3357.32,12965.7,0],[3221.68,12935.1,0],[14354.9,18066.4,0],[14389,18078.7,0],[14391.8,18062,0]];//Array of locked object positions
private _policeArray = ["Land_ConcreteWall_01_l_gate_F"];//Array of locked object Class Names
{
    _pos = _x;
    {
        private _gate = nearestObject [_pos, format ["%1",_x]];
        _gate setVariable ["bis_disabled_Door_1",1,true];
        _gate animateSource ["Door_1_source",0];
        _gate setVariable ["locked",true,true];
    } forEach _policeArray;
} forEach _policePos;

//Jail Gates & Doors
private _jailPos = [[15938.8,20815.7,0],[15960.6,20837.8,0],[15956,20815.1,0],[15945.4,20788.8,0],[3191.94,12866.9,0],[3274.48,12929.4,0]];
private _jailArray = ["Land_ConcreteWall_01_l_gate_F","Land_BackAlley_01_l_gate_F"];
{
    _pos = _x;
    {
        private _gate = nearestObject [_pos, format ["%1",_x]];
        _gate setVariable ["bis_disabled_Door_1",1,true];
        _gate animateSource ["Door_1_source",0];
        _gate setVariable ["locked",true,true];
    } forEach _jailArray;
} forEach _jailPos;

//Buildings - THIS HAS TO BE DONE SEPARATELY
