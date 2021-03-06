/*
	Author: Maverick Applications
	Convoy sidemission for Altis Life servers
	TODO Add proper configs and redo paths
*/

class Maverick_ConvoySidemission
{
	class Config
	{
		ConfigPool[] 							= {"GoldBarTransport","WeaponTransport"};
		ForceConfigAtIndex 						= -1;
		SleepTime								= 1800;
		MakePlayersHostileFor					= 60;
		TimeoutBetweenMarkers					= 600;
		SidesNotAttackable[]					= {"WEST","Independent"};
		AIDifficulty[] = {
												{"aimingAccuracy", 0.8},
												{"aimingShake", 0.9},
												{"aimingSpeed", 0.9},
												{"endurance", 1},
												{"spotDistance", 1},
												{"spotTime", 1},
												{"courage", 1},
												{"reloadSpeed", 1},
												{"commanding", 1},
												{"general", 1}
		};
	};
	class ConvoyConfigurationsPool
	{
		/*********************** EXAMPLE TRANSPORT FOR VIRTUAL ITEMS ***********************/
		class GoldBarTransport
		{
			class MapConfiguration
			{
				showMapMarker					= 1;
				text							= "Gold Transport";
			};

			class AIUnits
			{
				gear[] = {
												"H_MilCap_gen_F", // Headgear
												"", // Glasses
												"U_B_GEN_Soldier_F", // Uniform
												"V_TacVest_gen_F", // Vest
												"", // Backpack
												{"arifle_SPAR_01_blk_F", "30Rnd_556x45_Stanag", 5}, // Primary weapon, ammo and how many magazines
												{"", "", 5} // Secondary weapon, ammo and how many magazines
				};
			};

			class Messages
			{
				// Enable messages?
				enabled							= 1;

				// Mission started announcement
				startAnnouncementHeader			= "Gold Transport";
				startAnnouncementDescription	= "A guarded convoy is currently moving large amounts of Federal Gold.";

				// Mission objective completed
				stoppedAnnouncementHeader		= "Gold Transport stopped";
				stoppedAnnouncementDescription	= "The Gold Transport has been stopped!";

				// Mission completed announcement
				endAnnouncementHeader			= "Gold Transport Complete";
				endAnnouncementDescription  	= "Gold Transport has completed.";
			};

			class Vehicles
			{
				// Vehicle configuration
				vehiclesInOrder[]				= {"O_T_LSV_02_armed_F","O_T_Truck_03_ammo_ghex_F","O_T_LSV_02_unarmed_F"};
				vehiclesSpawnMarkersInOrder[]	= {"aug_convoy_spawn1","aug_convoy_spawn2","aug_convoy_spawn3"};
				vehiclesInheritDirection		= 1;
				mainVehicleAtIndex				= 1;
				maxSpeed						= 60;
				removeVehiclesAfterSeconds		= 600;
				additionalUnitsAmount			= 10;
			};

			class Route
			{
				// Route configuration
				markers[] 						= {"aug_convoy_waypoint1","aug_convoy_waypoint2","aug_convoy_waypoint3","aug_convoy_waypoint4","aug_convoy_waypoint5","aug_convoy_waypoint6","aug_convoy_waypoint7","aug_convoy_waypoint8","aug_convoy_waypoint9","aug_convoy_waypoint10","aug_convoy_waypoint11","aug_convoy_waypoint12","aug_convoy_waypoint13"};
			};

			class Loot
			{
				type 							= "virtual";
				container						= "Land_CargoBox_V1_F";
				data[] = {
												{"goldbar", 20}
				};
			};
		};


		/*********************** EXAMPLE TRANSPORT FOR REAL ITEMS ***********************/
		class WeaponTransport
		{
			class MapConfiguration
			{
				showMapMarker					= 1;
				text							= "Weapon Transport";
			};

			class AIUnits
			{
				gear[] = {
												"H_MilCap_gen_F", // Headgear
												"", // Glasses
												"U_B_GEN_Soldier_F", // Uniform
												"V_TacVest_gen_F", // Vest
												"", // Backpack
												{"arifle_SPAR_01_blk_F", "30Rnd_556x45_Stanag", 5}, // Primary weapon, ammo and how many magazines
												{"", "", 5} // Secondary weapon, ammo and how many magazines
				};
			};

			class Messages
			{
				// Enable messages?
				enabled							= 1;

				// Mission started announcement
				startAnnouncementHeader			= "Weapon Transport";
				startAnnouncementDescription	= "Local Armed Forces are currently shipping large amounts of weapons around Altis.";

				// Mission objective completed
				stoppedAnnouncementHeader		= "Weapon Transport Stopped";
				stoppedAnnouncementDescription	= "The Weapon Transport has been stopped!.";

				// Mission completed announcement
				endAnnouncementHeader			= "Weapon Transport Complete";
				endAnnouncementDescription  	= "Weapon Transport has completed.";
			};

			class Vehicles
			{
				// Vehicle configuration
				vehiclesInOrder[]				= {"O_T_LSV_02_armed_F","O_T_Truck_03_ammo_ghex_F","O_T_LSV_02_unarmed_F"};
				vehiclesSpawnMarkersInOrder[]	= {"aug_convoy_spawn1","aug_convoy_spawn2","aug_convoy_spawn3"};
				vehiclesInheritDirection		= 1;
				mainVehicleAtIndex				= 1;
				maxSpeed						= 60;
				removeVehiclesAfterSeconds		= 600;
				additionalUnitsAmount			= 10;
			};

			class Route
			{
				// Route configuration
				markers[] 						= {"aug_convoy_waypoint1","aug_convoy_waypoint2","aug_convoy_waypoint3","aug_convoy_waypoint4","aug_convoy_waypoint5","aug_convoy_waypoint6","aug_convoy_waypoint7","aug_convoy_waypoint8","aug_convoy_waypoint9","aug_convoy_waypoint10","aug_convoy_waypoint11","aug_convoy_waypoint12","aug_convoy_waypoint13"};
			};

			class Loot
			{
				type 							= "real";
				container						= "B_CargoNet_01_ammo_F";
				data[] = {
												{"srifle_DMR_01_F", 1, "WEAPON"},
												{"10Rnd_762x54_Mag", 3, "MAGAZINE"},
												{"arifle_Katiba_F", 1, "WEAPON"},
												{"30Rnd_65x39_caseless_green", 3, "MAGAZINE"},
												{"srifle_EBR_F", 1, "WEAPON"},
												{"20Rnd_762x51_Mag", 3, "MAGAZINE"},
												{"SMG_01_F", 1, "WEAPON"},
												{"30Rnd_45ACP_Mag_SMG_01", 3, "MAGAZINE"},
												{"optic_SOS", 1, "ITEM"},
												{"optic_Aco", 1, "ITEM"},
												{"optic_Arco", 1, "ITEM"},
												{"optic_MRCO", 1, "ITEM"},
												{"B_Kitbag_mcamo", 1, "BACKPACK"}
				};
			};
		};
	};
};