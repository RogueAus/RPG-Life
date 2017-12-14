#include "..\..\script_macros.hpp"

/*
    Author: KillerAussie
	
    Description:
	Updates current owners of captured hideout

*/
private _hideoutVar = vehicleVarName _hideout;
private _hideoutOwner = _hideout getVariable "GangOwner";
private _gangName = _hideoutOwner getVariable "gang_name";
private _hideoutName = "";

switch (_hideoutVar) do {
    
	case "gang_flag_1": {
	    _hideoutName = "Gang Hideout 1";
		hint _hideoutName;
	};
	
	case "gang_flag_2": {
	    _hideoutName = "Gang Hideout 2";
		hint _hideoutName;
	};
	
	case "gang_flag_3": {
	    _hideoutName = "Gang Hideout 3";
		hint _hideoutName;
	};
};