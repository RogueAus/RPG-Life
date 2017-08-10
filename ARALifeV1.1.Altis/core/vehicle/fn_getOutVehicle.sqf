/*
	fn_getOutVehicle.sqf
	manual getin to replace with new getin in 1.58
*/
if(!isNil "life_curWep_h" && {!(life_curWep_h isEqualTo "")})then
{
	player action ["SwitchWeapon", player, player, 100];
};

if (hasInterface) then {
        life_seatbelt = false;
        //[] call life_fnc_hudUpdate; //--Enable if you are putting a hud option to display when your seatbelt is on
};