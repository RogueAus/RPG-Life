/*
	Author: Maverick Applications
	Indicator script for ground vehicles
*/

class Maverick_Indicators
{
	// Base configuration
	class IndicatorVehicle_Base
	{
		blinkInterval = 0.8;
	};

	// Vehicle configuration
	class Vehicles
	{
		class C_Van_01_fuel_F : IndicatorVehicle_Base
		{
			positions[] = {{-0.754883, 1.8252, -0.395264},{0.693359, 1.84277, -0.399658},{-0.722656, -3.11133, -0.880493},{0.674805, -3.11133, -0.872131}};
		};
		class C_Van_01_transport_F : C_Van_01_fuel_F { };
		class C_Van_01_box_F : C_Van_01_fuel_F { };
		class C_Hatchback_01_F : IndicatorVehicle_Base
		{
			positions[] = {{-0.776367, 1.63477, -0.508896},{0.717773, 1.60645, -0.510963},{-0.768555, -2.19238, -0.290642},{0.702148, -2.18457, -0.296135}};
		};
		class C_Hatchback_01_sport_F : C_Hatchback_01_F { };
		class C_Offroad_02_unarmed_F : IndicatorVehicle_Base
		{
			positions[] = {{-0.552734, 2.07617, -0.600739},{0.472656, 2.07715, -0.605408},{-0.827148, -1.50684, -0.361725},{0.732422, -1.52344, -0.362213}};
		};
		class C_Offroad_01_F : IndicatorVehicle_Base
		{
			positions[] = {{-0.751953, 2.10547, -0.35965},{0.678711, 2.14453, -0.389404},{-0.902344, -2.87793, -0.219238},{0.832031, -2.90332, -0.216797}};
		};
		class C_Offroad_01_repair_F : C_Offroad_01_F { };
		class C_Quadbike_01_F : IndicatorVehicle_Base
		{
			positions[] = {{-0.387695, 0.90332, -0.6521},{0.329102, 0.90625, -0.640503},{-0.439453, -1.1084, -0.587646},{0.408203, -1.09863, -0.579346}};
		};
		class C_SUV_01_F : IndicatorVehicle_Base
		{
			positions[] = {{-0.793945, 2.02051, -0.457886},{0.783203, 2.03516, -0.441772},{-0.849609, -2.82227, -0.135132},{0.844727, -2.77246, -0.161255}};
		};
		class C_Truck_02_fuel_F : IndicatorVehicle_Base
		{
			positions[] = {{-0.850586, 3.85059, -1.24097},{0.80957, 3.85059, -1.22485},{-0.820313, -3.51465, -1.21997},{0.77832, -3.51465, -1.22778}};
		};
		class C_Truck_02_covered_F : C_Truck_02_fuel_F { };
		class C_Truck_02_transport_F : C_Truck_02_fuel_F { };
		class B_T_LSV_01_unarmed_F : IndicatorVehicle_Base
		{
			positions[] = {{-0.686523, 2.10205, -0.922165},{0.765625, 2.09863, -0.924149},{-0.708008, -2.06055, -0.783508},{0.774414, -2.06055, -0.78199}};
		};
		class B_T_LSV_01_armed_F : B_T_LSV_01_unarmed_F { };
		class O_T_LSV_02_unarmed_F : B_T_LSV_01_unarmed_F
		{
			positions[] = {{-0.97168, 2.09277, -0.434784},{0.642578, 2.08789, -0.429565},{-1.05176, -2.39063, -0.515137},{0.742188, -2.39063, -0.516571}};
		};
		class O_T_LSV_02_armed_F : O_T_LSV_02_unarmed_F { };
		class B_Truck_01_mover_F : IndicatorVehicle_Base
		{
			positions[] = {{-0.756836, 4.72534, -0.141126},{0.821777, 4.72534, -0.138716},{-0.234863, -4.18286, -0.678508},{0.280762, -4.18286, -0.672035}};
		};
		class B_Truck_01_ammo_F : B_Truck_01_mover_F { };
		class B_Truck_01_box_F : B_Truck_01_mover_F { };
		class B_Truck_01_medical_F : IndicatorVehicle_Base
		{
			positions[] = {{-0.927734, 5.04974, -0.450584},{0.631348, 5.0498, -0.464461},{-1.26953, -4.96259, -0.629445},{0.980957, -4.96252, -0.629724}};
		};
		class B_Truck_01_transport_F : B_Truck_01_medical_F { };
		class B_Truck_01_covered_F : B_Truck_01_medical_F { };
		class B_MRAP_01_F : IndicatorVehicle_Base
		{
			positions[] = {{-1.06543, 1.37158, -0.622296},{1.08057, 1.39832, -0.615966},{-1.11182, -4.21765, -0.799682},{1.12451, -4.21765, -0.797184}};
		};
		class B_Quadbike_01_F : IndicatorVehicle_Base
		{
			positions[] = {{-0.381348, 0.903931, -0.653458},{0.349609, 0.901001, -0.6339},{-0.438965, -1.10059, -0.580696},{0.433105, -1.10114, -0.581131}};
		};
		class O_MRAP_02_F : IndicatorVehicle_Base
		{
			positions[] = {{-0.747559, 1.44635, -1.08238},{0.763184, 1.44031, -1.0917},{0.650391, -4.48956, -1.29296},{-0.635254, -4.48944, -1.28916}};
		};
		class O_MRAP_02_gmg_F : O_MRAP_02_F { };
		class O_MRAP_02_hmg_F : O_MRAP_02_F { };
		class O_Quadbike_01_F : B_Quadbike_01_F { };
		class O_Truck_03_device_F : IndicatorVehicle_Base
		{
			positions[] = {{-0.776855, 3.07214, -0.77243},{0.890625, 3.1012, -0.74369},{-1.02148, -4.98438, -0.911415},{1.13428, -4.98755, -0.909679}};
		};
		class O_Truck_03_ammo_F : O_Truck_03_device_F { };
		class O_Truck_03_repair_F : O_Truck_03_device_F { };
		class O_Truck_03_medical_F : O_Truck_03_device_F { };
		class O_Truck_03_covered_F : O_Truck_03_device_F { };
		class O_Truck_03_fuel_F : IndicatorVehicle_Base
		{
			positions[] = {{-0.762207, 3.13025, -0.787334},{0.866699, 3.14465, -0.772987},{-0.994629, -4.90967, -0.910524},{1.14893, -4.91821, -0.903164}};
		};
		class O_Truck_02_Ammo_F : C_Truck_02_fuel_F { };
		class O_Truck_02_fuel_F : C_Truck_02_fuel_F { };
		class I_Quadbike_01_F : B_Quadbike_01_F { };
		class I_MRAP_03_F : IndicatorVehicle_Base
		{
			positions[] = {{-0.953125, 2.14294, -0.828428},{0.944336, 2.14624, -0.817188},{-1.19141, -2.75183, -0.684544},{1.17871, -2.7688, -0.713373}};
		};
		class I_MRAP_03_gmg_F : I_MRAP_03_F { };
		class I_MRAP_03_hmg_F : I_MRAP_03_F { };
		class I_Truck_02_transport_F : C_Truck_02_fuel_F { };
	};
};