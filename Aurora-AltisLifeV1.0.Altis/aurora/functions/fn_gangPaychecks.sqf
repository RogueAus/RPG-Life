#include "..\..\script_macros.hpp"

/*
    Author: KillerAussie
	
    Description:
	Sets gang hideout owners paychecks relevant to how many hideouts owned.

	Returns:
	Gang bonus

*/
private ["_hideoutOwners","_gangName","_groupMembers","_extraMoney","_ownedHideouts","_gangBonus"];

_hideoutOwners = call aug_fnc_updateHideouts;
_gangName = group player getVariable "gang_name";
_groupMembers = count units group player;
_extraMoney = LIFE_SETTINGS(getNumber,"hideout_bonus");


_ownedHideouts = {_x == _gangName} count _hideoutOwners;

_gangBonus = _extraMoney * _ownedHideouts / _groupMembers;

_gangBonus