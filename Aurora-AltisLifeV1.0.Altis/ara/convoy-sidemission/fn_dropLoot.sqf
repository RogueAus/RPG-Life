scriptName "fn_dropLoot";
/*--------------------------------------------------------------------
	Author: Maverick (ofpectag: MAV)
    File: fn_dropLoot.sqf

	<Maverick Applications>
    Written by Maverick Applications (www.maverick-apps.de)
    You're not allowed to use this file without permission from the author!
--------------------------------------------------------------------*/
#define __filename "fn_dropLoot.sqf"

// Fetch container name from config // Deprecated
//_containerClass = getText(missionConfigFile >> "Maverick_ConvoySidemission" >> "ConvoyConfigurationsPool" >> mav_convoy_class >> "Loot" >> "container");

mav_convoy_mainVehicle setVehicleLock "UNLOCKED";
//[mav_convoy_mainVehicle,{life_vehicles pushBack _this}] remoteExec ["BIS_fnc_spawn"];
[mav_convoy_mainVehicle] remoteExec ["mav_convoy_fnc_addVehicleToChain", -2];

// Fetch loot type from config
_lootType = getText(missionConfigFile >> "Maverick_ConvoySidemission" >> "ConvoyConfigurationsPool" >> mav_convoy_class >> "Loot" >> "type");

// Fetch loot from config
_loot = getArray(missionConfigFile >> "Maverick_ConvoySidemission" >> "ConvoyConfigurationsPool" >> mav_convoy_class >> "Loot" >> "data");

// Fill container with loot
if (_lootType == "virtual") exitWith {
	mav_convoy_mainVehicle setVariable ["Trunk",[_loot,5000],true];
};
if (_lootType == "real") exitWith {
	{
		diag_log "droploot";
		if ((_x select 2) == "WEAPON") then {
			mav_convoy_mainVehicle addWeaponCargoGlobal [_x select 0, _x select 1];
		};
		if ((_x select 2) == "MAGAZINE") then {
			mav_convoy_mainVehicle addMagazineCargoGlobal [_x select 0, _x select 1];
		};
		if ((_x select 2) == "ITEM") then {
			mav_convoy_mainVehicle addItemCargoGlobal [_x select 0, _x select 1];
		};
		if ((_x select 2) == "BACKPACK") then {
			mav_convoy_mainVehicle addBackpackCargoGlobal [_x select 0, _x select 1];
		};
	} forEach _loot;
};