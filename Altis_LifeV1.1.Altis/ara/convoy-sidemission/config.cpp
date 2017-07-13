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
				startAnnouncementDescription	= "Der bewachte Transporter der Zentralbank bewegt derzeit größere Mengen an Gold.";

				// Mission objective completed
				stoppedAnnouncementHeader		= "Gold Transporter ausgeschaltet";
				stoppedAnnouncementDescription	= "Der Goldtransporter wurde ausgeschaltet.";

				// Mission completed announcement
				endAnnouncementHeader			= "Gold Transport beendet";
				endAnnouncementDescription  	= "Die Mission wurde beendet.";
			};

			class Vehicles
			{
				// Vehicle configuration
				vehiclesInOrder[]				= {"B_MRAP_01_F","O_Truck_03_ammo_F","B_MRAP_01_F"};
				vehiclesSpawnMarkersInOrder[]	= {"fritzi_convoy_spawn1","fritzi_convoy_spawn2","fritzi_convoy_spawn3"};
				vehiclesInheritDirection		= 1;
				mainVehicleAtIndex				= 1;
				maxSpeed						= 60;
				removeVehiclesAfterSeconds		= 600;
				additionalUnitsAmount			= 10;
			};

			class Route
			{
				// Route configuration
				markers[] 						= {"fritzi_convoy_waypoint1","fritzi_convoy_waypoint2","fritzi_convoy_waypoint3","fritzi_convoy_waypoint4","fritzi_convoy_waypoint5","fritzi_convoy_waypoint6","fritzi_convoy_waypoint7","fritzi_convoy_waypoint8","fritzi_convoy_waypoint10","fritzi_convoy_waypoint11","fritzi_convoy_waypoint12","fritzi_convoy_waypoint13"};
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
				startAnnouncementHeader			= "Waffentransport";
				startAnnouncementDescription	= "Die Armee transportiert derzeit größere Mengen an Waffen durch Altis.";

				// Mission objective completed
				stoppedAnnouncementHeader		= "Waffentransporter ausgeschaltet";
				stoppedAnnouncementDescription	= "Der Waffentransporter wurde ausgeschaltet.";

				// Mission completed announcement
				endAnnouncementHeader			= "Waffentransport beendet";
				endAnnouncementDescription  	= "Die Mission wurde beendet.";
			};

			class Vehicles
			{
				// Vehicle configuration
				vehiclesInOrder[]				= {"O_T_LSV_02_armed_F","O_MRAP_02_F","O_Truck_02_Ammo_F","O_MRAP_02_F"};
				vehiclesSpawnMarkersInOrder[]	= {"fritzi_convoy_spawn1","fritzi_convoy_spawn2","fritzi_convoy_spawn3","fritzi_convoy_spawn4"};
				vehiclesInheritDirection		= 1;
				mainVehicleAtIndex				= 2;
				maxSpeed						= 60;
				removeVehiclesAfterSeconds		= 600;
				additionalUnitsAmount			= 10;
			};

			class Route
			{
				// Route configuration
				markers[] 						= {"fritzi_convoy_waypoint1","fritzi_convoy_waypoint2","fritzi_convoy_waypoint3","fritzi_convoy_waypoint4","fritzi_convoy_waypoint5","fritzi_convoy_waypoint6","fritzi_convoy_waypoint7","fritzi_convoy_waypoint8","fritzi_convoy_waypoint10","fritzi_convoy_waypoint11","fritzi_convoy_waypoint12","fritzi_convoy_waypoint13"};
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