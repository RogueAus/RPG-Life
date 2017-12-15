scriptName "fn_startConvoy";
/*--------------------------------------------------------------------
	Author: Maverick (ofpectag: MAV)
    File: fn_startConvoy.sqf

	<Maverick Applications>
    Written by Maverick Applications (www.maverick-apps.de)
    You're not allowed to use this file without permission from the author!
--------------------------------------------------------------------*/
#define __filename "fn_startConvoy.sqf"

_class = param[0,"",[""]];

// Exception
if (_class == "") exitWith {};

// Markers
mav_convoy_markersleft = (getArray(missionConfigFile >> "Maverick_ConvoySidemission" >> "ConvoyConfigurationsPool" >> _class >> "Route" >> "markers"));

// Make current class public
mav_convoy_class = _class;

// Basic var
mav_convoy_inAttack = false;

// Get vehicles
mav_convoy_vehicles = [];
mav_convoy_vehiclesArray = getArray(missionConfigFile >> "Maverick_ConvoySidemission" >> "ConvoyConfigurationsPool" >> _class >> "Vehicles" >> "vehiclesInOrder");
{
	_marker = (getArray(missionConfigFile >> "Maverick_ConvoySidemission" >> "ConvoyConfigurationsPool" >> _class >> "Vehicles" >> "vehiclesSpawnMarkersInOrder")) select _forEachIndex;
	_dir = if (getNumber(missionConfigFile >> "Maverick_ConvoySidemission" >> "ConvoyConfigurationsPool" >> _class >> "Vehicles" >> "vehiclesInheritDirection") == 1) then {
		markerDir _marker
	} else {
		0
	};
	_v = ([getMarkerPos _marker, _dir, _x, WEST] call BIS_fnc_spawnVehicle) select 0;
	
	clearItemCargoGlobal _v;
	clearWeaponCargoGlobal _v;
	clearMagazineCargoGlobal _v;
	clearBackpackCargoGlobal _v;
	
	mav_convoy_vehicles pushBack _v;
} forEach mav_convoy_vehiclesArray;

// Clear vehicle inventories
{clearItemCargo _x; clearWeaponCargo _x; clearMagazineCargo _x} forEach mav_convoy_vehicles;

// Display messages?
if ((getNumber(missionConfigFile >> "Maverick_ConvoySidemission" >> "ConvoyConfigurationsPool" >> _class >> "Messages" >> "enabled")) == 1) then {
	_header = getText(missionConfigFile >> "Maverick_ConvoySidemission" >> "ConvoyConfigurationsPool" >> _class >> "Messages" >> "startAnnouncementHeader");
	_text = getText(missionConfigFile >> "Maverick_ConvoySidemission" >> "ConvoyConfigurationsPool" >> _class >> "Messages" >> "startAnnouncementDescription");
	(parseText format ["<t color='#ff0000' size='1.4' shadow='2' align='center'>%1</t><br/><br/>%2", _header, _text]) remoteExec ["hint"];
};

// Fetch main vehicle
mav_convoy_mainVehicleIndex = (getNumber(missionConfigFile >> "Maverick_ConvoySidemission" >> "ConvoyConfigurationsPool" >> _class >> "Vehicles" >> "mainVehicleAtIndex"));
mav_convoy_mainVehicle = mav_convoy_vehicles select mav_convoy_mainVehicleIndex;

// Create marker if necessary
if ((getNumber(missionConfigFile >> "Maverick_ConvoySidemission" >> "ConvoyConfigurationsPool" >> _class >> "MapConfiguration" >> "showMapMarker")) == 1) then {
	[mav_convoy_mainVehicle] spawn mav_convoy_fnc_createMarker;
};

// Fetch all mission objects and lock vehicles for players
mav_convoy_allMissionObjects = mav_convoy_vehicles;
{
	mav_convoy_allMissionObjects = mav_convoy_allMissionObjects + (crew _x);
	_x setVehicleLock "LOCKEDPLAYER";
} forEach mav_convoy_vehicles;

// Fetch how many additional units there should be, put them in their vehicles and give them their gear
_unitCount = getNumber(missionConfigFile >> "Maverick_ConvoySidemission" >> "ConvoyConfigurationsPool" >> mav_convoy_class >> "Vehicles" >> "additionalUnitsAmount");
{
	while {_unitCount > 0 AND (_x emptyPositions "Cargo") > 0} do {
		_unit = (group _x) createUnit ["B_Competitor_F", position _x, [], 0, "FORM"];
		_unit moveInCargo _x;
		_unitCount = _unitCount - 1;
		mav_convoy_allMissionObjects pushBack _unit;
	};
} forEach mav_convoy_vehicles;

// Fetch max speed
mav_convoy_maxSpeed = getNumber(missionConfigFile >> "Maverick_ConvoySidemission" >> "ConvoyConfigurationsPool" >> _class >> "Vehicles" >> "maxSpeed");

// Fetch max overall distance
mav_convoy_maxLeadingAndMainVehDistance = if (mav_convoy_mainVehicleIndex > 0) then {mav_convoy_mainVehicleIndex * 100} else {100};

// Give all units their skill level
_skillArray = getArray(missionConfigFile >> "Maverick_ConvoySidemission" >> "Config" >> "AIDifficulty");
{
	if (_x isKindOf "Man") then {
		_man = _x;
		{
			_man setSkill _x;
		} forEach _skillArray;

		// Give unit loadout
		[_man] call mav_convoy_fnc_giveUnitLoadout;
		
		// Make all units not road-kill-able
		_man addEventHandler ["HandleDamage", {
			_source = _this select 3;
			_damage = _this select 2;
			
			if ((vehicle _source) != _source && _source isKindOf "Man") then {
				_damage = 0;
			};
			
			_damage
		}];
	};
} forEach mav_convoy_allMissionObjects;

// If this client has the indicator scripts, enable the warn indicators
if (isClass (missionConfigFile >> "Maverick_Indicators")) then {
	{
		[_x, "warn"] remoteExec ["mav_indicator_fnc_enableIndicator"];
	} forEach mav_convoy_vehicles;
};

// Enable handlers for all players that make the AI go attack them
{
	_x addMPEventHandler ["MPHit",{[_this select 1] spawn mav_convoy_fnc_checkUnit;}];
} forEach mav_convoy_allMissionObjects;

// JIP proximity check
[mav_convoy_mainVehicle] remoteExec ["mav_convoy_fnc_proximityCheck", 0, mav_convoy_mainVehicle];

// If this convoy holds more than one vehicle, make all groups join the group of the leading vehicle
if (count mav_convoy_vehicles > 1) then {
	_leaderFirstVehicle = leader (group (mav_convoy_vehicles select 0));
	(group _leaderFirstVehicle) setFormation "FILE";
	for "_i" from 1 to (count mav_convoy_vehicles - 1) step 1 do
	{
		(crew (mav_convoy_vehicles select _i)) join _leaderFirstVehicle;
	};

	// Make driver of first vehicle the leader
	_firstVehicle = mav_convoy_vehicles select 0;
	(group _firstVehicle) selectLeader (driver _firstVehicle);

	while {behaviour (leader (group _firstVehicle)) != "CARELESS"} do {
		(group _firstVehicle) setBehaviour "CARELESS";
	};
};

// Thread that handles waypoints
[] spawn {
	_timeout = getNumber(missionConfigFile >> "Maverick_ConvoySidemission" >> "Config" >> "TimeoutBetweenMarkers");
	_timeRemaining = _timeout;

	while {!isNull mav_convoy_mainVehicle && (count mav_convoy_vehicles > 0) && (count mav_convoy_markersleft > 0)} do {
		sleep 1;

		if (!mav_convoy_inAttack) then {
			_timeRemaining = _timeRemaining - 1;
		};

		// Timeout
		if (_timeRemaining <= 0) exitWith {};

		_leadingVehicle = mav_convoy_vehicles select 0;
		
		if (isNil "_leadingvehicle") then {
			diag_log format ["Convoy: Cannot find leading vehicle in array %1", mav_convoy_vehicles];
		};
		
		if (_leadingVehicle distance (getMarkerPos (mav_convoy_markersleft select 0)) < 25) then {
			mav_convoy_markersleft deleteAt 0;
			systemChat "Marker reached";

			// Time remaining
			_timeRemaining = _timeout;
		};
	};

	// Mission over
	[0] spawn mav_convoy_fnc_removal;
};

// Make leading vehicle follow the waypoints
[mav_convoy_vehicles select 0] spawn mav_convoy_fnc_followTrack;

// Init follow script
/*_vehicleBeforeMe = objNull;
_firstVeh = true;
{
	diag_log "mejm";
	if (_firstVeh) then {
		_thread = [_x,objNull] spawn mav_convoy_fnc_follow;
		_x setVariable ["mav_convoy_vehiclethread",_thread];
		_vehicleBeforeMe = _x;
		_firstVeh = false;
	} else {
		_thread = [_x, _vehicleBeforeMe] spawn mav_convoy_fnc_follow;
		_x setVariable ["mav_convoy_vehiclethread",_thread];
		_vehicleBeforeMe = _x;
	};
} forEach mav_convoy_vehicles;*/

// Init main script
mav_convoy_currentscriptthread = [mav_convoy_vehicles, mav_convoy_markersleft] spawn mav_convoy_fnc_move;