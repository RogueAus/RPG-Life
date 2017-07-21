/*
	fn_getInVehicle.sqf
	manual getin to replace with new getin in 1.58
*/
if(!(currentWeapon player isEqualTo ""))then{life_curWep_h = nil;};

if (hasInterface) then {
        life_seatbelt = false;
        //[] call life_fnc_hudUpdate; //--Enable if you are putting a hud option to display when your seatbelt is on
};