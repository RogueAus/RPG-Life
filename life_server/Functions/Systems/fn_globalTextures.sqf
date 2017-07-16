/*
    File: fn_globalTextures.sqf
    Author: Rogue
    Sets Global Textures for objects e.g. infostands
*/

private _marker = (getMarkerPos "globalTextures");
private _infostands = nearestObjects [_marker, "Land_InfoStand_V2_F", 17500, true];

{
    _x setObjectTextureGlobal [0,"textures\InfoStand.jpg"];
} forEach _infoStands;