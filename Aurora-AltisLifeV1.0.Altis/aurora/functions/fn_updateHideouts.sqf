#include "..\..\script_macros.hpp"

/*
    Author: KillerAussie
	
    Description:
	Updates current owners of all hideouts. If no owner, sets to 'Not Owned'.

	Returns:
	Array of current hideout owners.

	0: Gang Hideout 1
	1: Gang Hideout 2
	2: Gang Hideout 3

*/
private _hideoutList = [gang_flag_1,gang_flag_2,gang_flag_3];
private _gangName = "";
private _hideoutOwners = [];

{
    _gangName = (_x getVariable ["gangOwner",objNull]) getVariable ["gang_name",""];
    if (_gangName isEqualTo "") then {
        _gangName = "Not Owned";
    };
    _hideoutOwners pushBack _gangName;

}forEach _hideoutList;

_hideoutOwners