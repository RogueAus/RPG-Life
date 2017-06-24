#include "..\..\script_macros.hpp"
/*
    File: fn_hudUpdate.sqf
    Author: Daniel Stuart

    Description:
    Updates the HUD when it needs to.
*/
disableSerialization;

if (isNull LIFEdisplay) then {[] call life_fnc_hudSetup;};
LIFEctrl(2200) progressSetPosition (life_hunger / 100);
LIFEctrl(2201) progressSetPosition (1 - (damage player));
LIFEctrl(2202) progressSetPosition (life_thirst / 100);

if(playerSide == civilian) then
{
	if(wanted_status > 0) then
	{
		LIFEctrl(IDC_LIFE_BAR_WANTED) progressSetPosition (100);
		LIFEctrl(IDC_LIFE_BAR_CLEAR) progressSetPosition (0);
		//LIFEctrl(IDC_LIFE_WANTED_TEXT) ctrlSetText format["$%1", ([wanted_status] call life_fnc_numberText)];
		LIFEctrl(IDC_LIFE_WANTED_TEXT) ctrlSetText format["%1", "WANTED"];
		player setVariable ["isWanted", true, true];
	}
	else
	{
		LIFEctrl(IDC_LIFE_BAR_WANTED) progressSetPosition (0);
		LIFEctrl(IDC_LIFE_BAR_CLEAR) progressSetPosition (100);
		LIFEctrl(IDC_LIFE_WANTED_TEXT) ctrlSetText format["%1", "NOT WANTED"];
		player setVariable ["isWanted", false, true];
	};
};
