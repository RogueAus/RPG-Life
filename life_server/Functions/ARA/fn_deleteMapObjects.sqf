private _pos = getArray(configFile >> "CfgWorlds" >> worldName >> "centerPosition");
private _mapID = [1574798,1574800];

 {
        ((getPos _pos) nearestObject _x) hideObjectGlobal true;
 } forEach _mapID;