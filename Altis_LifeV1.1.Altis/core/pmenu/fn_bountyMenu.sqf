#include "..\..\script_macros.hpp"
/*
    File: fn_wantedMenu.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Opens the Wanted menu and connects to the APD.
*/
disableSerialization;

if !(playerSide isEqualTo civilian) exitWith {}; // Only for civs open this menu
if (license_civ_rebel) exitWith {hint "You have an Illegal License! You can't be a Bounty Hunter!"};
if (license_civ_marijuana) exitWith {hint "You have an Illegal License! You can't be a Bounty Hunter!"};
if (license_civ_heroin) exitWith {hint "You have an Illegal License! You can't be a Bounty Hunter!"};
if (license_civ_cocaine) exitWith {hint "You have an Illegal License! You can't be a Bounty Hunter!"};
//if (!license_civ_bounty) exitWith {hint "You must have a Bounty Hunting License to do this."};
createDialog "life_bounty_menu";

private _display = findDisplay 7400;
private _list = _display displayCtrl 7401;
private _players = _display displayCtrl 7406;
private _units = [];

lbClear _list;
lbClear _players;

{
    private _side = switch (side _x) do {case west: {"Cop"}; case civilian : {"Civ"}; default {"Unknown"};};
    _players lbAdd format ["%1 - %2", name _x,_side];
    _players lbSetdata [(lbSize _players)-1,str(_x)];
} forEach playableUnits;

private _list2 = CONTROL(7400,7407);
lbClear _list2; //Purge the list

private _crimes = LIFE_SETTINGS(getArray,"crimes");
{
  if (isLocalized (_x select 0)) then {
    _list2 lbAdd format ["%1 - $%2 (%3)",localize (_x select 0),(_x select 1),(_x select 2)];
  } else {
    _list2 lbAdd format ["%1 - $%2 (%3)",(_x select 0),(_x select 1),(_x select 2)];
  };
    _list2 lbSetData [(lbSize _list2)-1,(_x select 2)];
} forEach _crimes;

ctrlSetText[7404,"Establishing connection..."];


ctrlShow[7405,false];


if (life_HC_isActive) then {
    [player] remoteExec ["HC_fnc_bountyFetch",HC_Life];
} else {
    [player] remoteExec ["life_fnc_bountyFetch",RSERV];
};