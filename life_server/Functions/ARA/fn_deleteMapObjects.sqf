/*
    File: fn_deleteMapObjects.sqf
    Author: Rogue & KillerAussie

    Description:
    Removes Map Objects .
*/
private _posID = [
    //[[posX,posY,0],[Map ID's e.g. 1234,5324,2552,3123]]
    //Kavala HQ
    [[3280.92,12942.9,0], [1119925,1119930,1119944,1119943,1119454,1119419,1119417,1119485,1119960,1119956,1119955,1119957,1119959,1119995,1119994,1119696,1119724,1119723,1119725,1119492,1119407,1119696,111972412,1119726]],
    //Athira carShop
    [[14030.9,18738.4,0], [447339,447445,447098,447099,447148,447324,447341,447366,447063]],
    //Sofia Garage
    [[25815.2,21485.6,0], [1574798,1574800,1574807,51278,1574797,51277]]
];

{
    private _pos = (_x select 0);
    private _objArray = (_x select 1);
    {
        (_pos nearestObject _x) hideObjectGlobal true;
    } forEach _objArray;
} forEach _posID;