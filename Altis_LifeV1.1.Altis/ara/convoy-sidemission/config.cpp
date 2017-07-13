/*
	Author: Maverick Applications
	Convoy sidemission for Altis Life servers
*/

class Maverick_ConvoySidemission
{
	class Config
	{
		ConfigPool[] 							= {"GoldBarTransport","WeaponTransport"};
		ForceConfigAtIndex 						= -1;
		SleepTime								= 990;
		MakePlayersHostileFor					= 180;
		SidesNotAttackable[]					= {"WEST"};
		AIDifficulty[] = {
												{"aimingAccuracy", 1},
												{"aimingShake", 1},
												{"aimingSpeed", 1},
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
												"H_HelmetB_light_grass", // Headgear
												"", // Glasses
												"U_B_CombatUniform_mcam_tshirt", // Uniform
												"V_PlateCarrierL_CTRG", // Vest
												"", // Backpack
												{"srifle_EBR_MRCO_pointer_F", "20Rnd_762x51_Mag", 5}, // Primary weapon, ammo and how many magazines
												{"", "", 5}, // Secondary weapon, ammo and how many magazines
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
				stoppedAnnouncementHeader		= "Gold Transport Stopped";
				stoppedAnnouncementDescription	= "The Gold Transport has been stopped!";

				// Mission completed announcement
				endAnnouncementHeader			= "Gold Transport Complete";
				endAnnouncementDescription  	= "Gold Transport has completed.";
			};

			class Vehicles
			{
				// Vehicle configuration
				vehiclesInOrder[]				= {"B_MRAP_01_F","O_Truck_03_ammo_F","B_MRAP_01_F"};
				vehiclesSpawnMarkersInOrder[]	= {"ara_convoy_spawn1","ara_convoy_spawn2","ara_convoy_spawn3"};
				vehiclesInheritDirection		= 1;
				mainVehicleAtIndex				= 1;
				maxSpeed						= 60;
				removeVehiclesAfterSeconds		= 600;
				additionalUnitsAmount			= 10;
			};

			class Route
			{
				// Route configuration
				markers[] 						= {"ara_convoy_waypoint1","ara_convoy_waypoint2","ara_convoy_waypoint3","ara_convoy_waypoint4","ara_convoy_waypoint5","ara_convoy_waypoint6","ara_convoy_waypoint7","ara_convoy_waypoint8","ara_convoy_waypoint10","ara_convoy_waypoint11","ara_convoy_waypoint12","ara_convoy_waypoint13"};
			};

			class Loot
			{
				type 							= "virtual";
				container						= "Land_CargoBox_V1_F";
				data[] = {
												{"goldbar", 10}
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
												{"", "", 5}, // Secondary weapon, ammo and how many magazines
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
				vehiclesInOrder[]				= {"O_T_LSV_02_armed_F","O_MRAP_02_F","O_Truck_02_Ammo_F","O_MRAP_02_F"};
				vehiclesSpawnMarkersInOrder[]	= {"ara_convoy_spawn1","ara_convoy_spawn2","ara_convoy_spawn3","ara_convoy_spawn4"};
				vehiclesInheritDirection		= 1;
				mainVehicleAtIndex				= 2;
				maxSpeed						= 60;
				removeVehiclesAfterSeconds		= 600;
				additionalUnitsAmount			= 10;
			};

			class Route
			{
				// Route configuration
				markers[] 						= {"ara_convoy_waypoint1","ara_convoy_waypoint2","ara_convoy_waypoint3","ara_convoy_waypoint4","ara_convoy_waypoint5","ara_convoy_waypoint6","ara_convoy_waypoint7","ara_convoy_waypoint8","ara_convoy_waypoint10","ara_convoy_waypoint11","ara_convoy_waypoint12","ara_convoy_waypoint13"};
			};

			class Loot
			{
				type 							= "real";
				container						= "B_supplyCrate_F";
				data[] = {
												{"srifle_DMR_01_F", 1, "WEAPON"},
												{"optic_SOS", 1, "ITEM"},
												{"10Rnd_762x54_Mag", 1, "MAGAZINE"},
												{"B_Kitbag_mcamo", 1, "BACKPACK"}
				};
			};
		};
	};
};