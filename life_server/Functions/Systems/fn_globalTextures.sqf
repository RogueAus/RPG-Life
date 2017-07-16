/*
    File: fn_globalTextures.sqf
    Author: Rogue
    Sets Global Textures for objects e.g. infostands
*/
private _center = getArray(configFile >> "CfgWorlds" >> worldName >> "centerPosition");
private _infostands = _center nearObjects ["Land_InfoStand_V2_F", 20000];
{
    _x setObjectTextureGlobal [0,"textures\InfoStand.jpg"];
} forEach _infoStands;