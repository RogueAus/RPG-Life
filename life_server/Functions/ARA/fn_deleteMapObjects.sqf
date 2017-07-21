/*
    File: fn_deleteMapObjects.sqf
    Author: Rogue & KillerAussie

    Description:
    Removes Map Objects .
*/
private _posID = [
    //Kavala HQ
    [[x,y,0], [1119925,1119930,1119944,1119943,1119454,1119419,1119417,1119485,1119960,1119956,1119955,1119957,1119959,1119995,1119994,1119696,1119724,1119723,1119725,1119492]],
    //Athira carShop
    [[x,y,0], [447339,447445,447098,447099,447148,447324,447341,447366,447063]],
    //Sofia Garage
    [[x,y,0], [1574798,1574800,1574807,51278,1574797,51277]]
];

{
    private _pos = (_x select 0);
    (_pos nearestObject (_x select 1)) hideObjectGlobal true;
} forEach _posID;
