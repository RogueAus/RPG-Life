#include "..\..\script_macros.hpp"
/*
    File: fn_truckJobs.sqf
    Author: Rogue

    Description:
    Basically runs the Truck Missions.
*/

_playerPos = (getPos player);

//[0) Title, 1)Amount Paid Per KM, 2)Vehicle Spawned, 3) Array Of Objects Attached & Their Pos, 4) Min Distance, 5) Max Distance]
//Example of 3 [Class,Left/Right,Back/Forward,Up/Down,Direction]
private _jobArray = [
//["Job Title",Dollaz,"Vehicle_Class",[["Object_Class",0,-0.7,-0.5],["Object_Class",0,0.8,-0.4,260],["Object_Class",0,-0.9,-0.3]],100,2000],
];

private _DeliveryPoints = [
    getMarkerPos "example1",getMarkerPos "example2"
];

private _jobDepots = [
    getMarkerPos "example1",getMarkerPos "example2"
];