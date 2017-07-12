/*
*    FORMAT:
*        STRING (Conditions) - Must return boolean :
*            String can contain any amount of conditions, aslong as the entire
*            string returns a boolean. This allows you to check any levels, licenses etc,
*            in any combination. For example:
*                "call life_coplevel && license_civ_someLicense"
*            This will also let you call any other function.
*            
*
*    ARRAY FORMAT:
*        0: STRING (Classname): Item Classname
*        1: STRING (Nickname): Nickname that will appear purely in the shop dialog
*        2: SCALAR (Buy price)
*        3: SCALAR (Sell price): To disable selling, this should be -1
*        4: STRING (Conditions): Same as above conditions string
*
*    Weapon classnames can be found here: https://community.bistudio.com/wiki/Arma_3_CfgWeapons_Weapons
*    Item classnames can be found here: https://community.bistudio.com/wiki/Arma_3_CfgWeapons_Items
*
*/
class WeaponShops {
    //Armory Shops
    class gun {
        name = "Billy Joe's Firearms";
        side = "civ";
        conditions = "license_civ_gun";
        items[] = {
            { "hgun_Rook40_F", "", 6500, 3250, "" },
            { "hgun_Pistol_01_F", "", 7000, 3500, "" }, //Apex DLC
            { "hgun_Pistol_heavy_02_F", "", 9850, 4925, "" },
            { "hgun_ACPC2_F", "", 11500, 5750, "" },
            { "SMG_05_F", "", 18000, 9000, "" }, //Apex DLC
            { "hgun_PDW2000_F", "", 20000, 10000, "" }
        };
        mags[] = {
            { "16Rnd_9x21_Mag", "", 125, 60, "" },
            { "6Rnd_45ACP_Cylinder", "", 150, 75, "" },
            { "9Rnd_45ACP_Mag", "", 200, 100, "" },
            { "30Rnd_9x21_Mag", "", 250, 125, "" },
            { "30Rnd_9x21_Mag_SMG_02", "", 250, 125, "" }, //Apex DLC
            { "10Rnd_9x21_Mag", "", 250, 125, "" } //Apex DLC
        };
        accs[] = {
            { "optic_ACO_grn_smg", "", 2500, 1250, "" }
        };
    };

    class rebel {
        name = "Mohammed's Jihadi Shop";
        side = "civ";
        conditions = "license_civ_rebel";
        items[] = {
			{ "hgun_Rook40_F", "", 5000, 1500, "" }, // Rook-40 9mm
			{ "hgun_Pistol_01_F", "", 5000, 1500, "" }, // PM 9mm // APEX DLC
			{ "hgun_ACPC2_F", "", 6500, 3000, "" }, // ACP-C2 45.
			{ "hgun_Pistol_heavy_01_F", "", 7000, 3500, "" }, // 4-Five
			{ "hgun_Pistol_heavy_02_F", "", 9000, 4500, "" }, // Zubr
            { "arifle_TRG20_F", "", 30000, 12500, "" }, // TRG
			{ "arifle_MK20_plain_F", "", 40000, 14000, "" }, // Mk20
			{ "arifle_CTAR_blk_F", "", 55000, 22500, "" }, // Car-95 // APEX DLC
            { "arifle_Katiba_F", "", 60000, 22500, "" }, // Katiba
			{ "arifle_ARX_blk_F", "", 85000, 25000, "" }, // Type-115 // APEX DLC
            { "arifle_AK12_F", "", 90000, 32500, "" }, // AK-12 // APEX DLC
			{ "arifle_MX_SW_F", "", 120000, 60000, "" }, // MX-SW
			{ "LMG_03_F", "", 215000, 90000, "" }, // LIM - 85 // APEX DLC
			{ "srifle_DMR_01_F", "", 80000, 35000, "" }, // Rahim
			{ "srifle_DMR_07_blk_F", "", 95000, 40000, "" }, // CMR-76 // APEX DLC
			{ "srifle_DMR_03_F", "", 175000, 80000, "" }, // Mk1 EMR
			{ "srifle_EBR_F", "", 175000, 80000, "" } // Mk 18

				
        };
        mags[] = {
			{"30Rnd_9x21_Mag", "", 500, 150, "" }, // Pistol/PDW Ammo - 9mm
			{"30Rnd_556x45_Stanag", "", 350, 150, "" }, // TRG/Mk20 Ammo - 5.56
			{"30Rnd_65x39_caseless_mag", "", 450, 200, "" }, // Type-115/Katiba Ammo - 6.5mm
			{"30Rnd_580x42_Mag_F", "", 400, 150, "" }, // Car-95 Ammo - 5.8mm
			{"30Rnd_762x39_Mag_F", "", 500, 250, "" }, // AK-12 Ammo - 7.62
			{"30Rnd_65x39_caseless_green", "", 450, 200, "" }, // Type-115/Katiba Ammo - 6.5mm green trasers
			{"100Rnd_65x39_caseless_mag", "", 1200, 350, "" }, // MX-SW Ammo - 6.5mm 100rnd
			{"200Rnd_556x45_Box_F", "", 3500, 2000, "" }, // LIM-85 Ammo - 5.56 200rnd // APEX DLC
			{"10Rnd_762x54_Mag", "", 600, 250, "" }, // Rahim Ammo - 7.62
			{"20Rnd_650x39_Cased_Mag_F", "", 850, 465, "" }, // CMR-76 - 6.5mm // APEX DLC
			{"20Rnd_762x51_Mag", "", 1100, 600, "" }, // Mk1 EMR/ Mk 18 Ammo - 7.62
			{"11Rnd_45ACP_Mag", "", 200, 100, "" }, // 4-Five Ammo - 45. ACP
			{"6Rnd_45ACP_Cylinder", "", 250, 200, "" }, // Zubr Ammo - 45. ACP
			{"10Rnd_9x21_Mag", "", 150, 75, "" }, // PM Ammo - 9mm // APEX DLC
			{"16Rnd_9x21_Mag", "", 150, 75, "" }, // Rook-40 Ammo - 9mm
			{"9Rnd_45ACP_Mag", "", 175, 100, "" } // ACP-C2 Ammo - 45. ACP
        };
        accs[] = {
            { "optic_Holosight", "", 250, 50, "" },
            { "optic_Holosight_blk_F", "", 250, 50, "" },
            { "optic_ACO_grn", "", 500, 150, "" },
            { "optic_Aco", "", 500, 150, "" },
			{ "optic_Arco", "", 1500, 250, "" },
			{ "optic_Arco_blk_F", "", 1500, 250, "" },
			{ "optic_Hamr", "", 2250, 350, "" },
			{ "optic_ERCO_blk_F", "", 2250, 350, "" }, // APEX DLC
			{ "optic_ERCO_snd_F", "", 2250, 350, "" }, // APEX DLC
			{ "optic_SOS", "", 4235, 550, "" },
			{ "optic_DMS", "", 5000, 620, "" },
			{ "optic_KHS_tan", "", 7320, 1250, "" },
			{ "optic_KHS_blk", "", 7320, 1250, "" },
			{ "optic_AMS_snd", "", 8750, 1500, "" },
			{ "optic_AMS", "", 8750, 1500, "" },
			{ "optic_NVS", "", 12500, 2200, "" },
			{ "bipod_01_F_snd", "", 1500, 350, "" },
			{ "bipod_01_F_blk", "", 1500, 350, "" }
        };
    };

    class gang {
        name = "Hideout Armament";
        side = "civ";
        conditions = "";
        items[] = {
            { "hgun_Rook40_F", "", 1500, 750, "" },
            { "hgun_Pistol_heavy_02_F", "", 2500, 1250, "" },
            { "hgun_ACPC2_F", "", 4500, 2250, "" },
            { "hgun_PDW2000_F", "", 9500, 4750, "" }
        };
        mags[] = {
            { "16Rnd_9x21_Mag", "", 125, 60, "" },
            { "6Rnd_45ACP_Cylinder", "", 150, 75, "" },
            { "9Rnd_45ACP_Mag", "", 200, 100, "" },
            { "30Rnd_9x21_Mag", "", 250, 125, "" }
        };
        accs[] = {
            { "optic_ACO_grn_smg", "", 950, 475, "" }
        };
    };

    //Basic Shops
    class genstore {
        name = "Altis General Store";
        side = "civ";
        conditions = "";
        items[] = {
            { "Binocular", "", 150, 75, "" },
            { "ItemGPS", "", 100, 50, "" },
            { "ItemMap", "", 50, 25, "" },
            { "ItemCompass", "", 50, 25, "" },
            { "ItemWatch", "", 50, 25, "" },
            { "FirstAidKit", "", 150, 75, "" },
            { "NVGoggles", "", 2000, 1000, "" },
            { "Chemlight_red", "", 300, 150, "" },
            { "Chemlight_yellow", "", 300, 150, "" },
            { "Chemlight_green", "", 300, 150, "" },
            { "Chemlight_blue", "", 300, 150, "" }
        };
        mags[] = {};
        accs[] = {};
    };

    class f_station_store {
        name = "Altis Fuel Station Store";
        side = "";
        conditions = "";
        items[] = {
            { "Binocular", "", 750, 75, "" },
            { "ItemGPS", "", 500, 50, "" },
            { "ItemMap", "", 250, 25, "" },
            { "ItemCompass", "", 250, 25, "" },
            { "ItemWatch", "", 250, 25, "" },
            { "FirstAidKit", "", 750, 75, "" },
            { "NVGoggles", "", 10000, 1000, "" },
            { "Chemlight_red", "", 1500, 150, "" },
            { "Chemlight_yellow", "", 1500, 150, "" },
            { "Chemlight_green", "", 1500, 150, "" },
            { "Chemlight_blue", "", 1500, 150, "" }
        };
        mags[] = {};
        accs[] = {};
    };

    //Cop Shops
    class cop_basic {
        name = "Altis Cop Shop";
        side = "cop";
        conditions = "";
        items[] = {
            { "Binocular", "", 150, 75, "" },
            { "ItemGPS", "", 100, 50, "" },
            { "FirstAidKit", "", 150, 75, "" },
            { "NVGoggles", "", 2000, 1000, "" },
            { "HandGrenade_Stone", $STR_W_items_Flashbang, 1700, 850, "" },
            { "hgun_P07_snds_F", $STR_W_items_StunPistol, 2000, 1000, "" },
            { "arifle_SDAR_F", $STR_W_items_TaserRifle, 20000, 10000, "" },
            { "hgun_P07_F", "", 7500, 3750, "" },
            { "hgun_P07_khk_F", "", 7500, 3750, "" }, //Apex DLC
            { "hgun_Pistol_heavy_01_F", "", 9500, 4750, "call life_coplevel >= 1" },
	    { "arifle_SPAR_01_blk_F","", 5000, 5000, "call life_coplevel >= 2" },
	    { "arifle_Mk20_plain_F", "", 5000, 5000, "call life_coplevel >= 2"},
	    { "arifle_CTAR_blk_F", "", 5000,5000, "call life_coplevel >= 2"},
            { "SMG_02_ACO_F", "", 30000, 15000, "call life_coplevel >= 2" },
            { "arifle_MX_F", "", 35000, 17500, "call life_coplevel >= 3" },
            { "hgun_ACPC2_F", "", 17500, 8750, "call life_coplevel >= 3" },
            { "arifle_MXC_F", "", 30000, 15000, "call life_coplevel >= 3" },
            { "arifle_MXM_Black_F", "", 30000, 15000, "call life_coplevel >= 4"},
	    { "arifle_ARX_blk_F", "", 25000, 12500, "call life_coplevel >= 4"},
            { "srifle_DMR_07_blk_F", "", 32000, 16000, "call life_coplevel >= 4" }, //Apex DLC Sniper
	    { "arifle_MX_SW_Black_F", "", 60000, 30000, "call life_coplevel >= 5"},
	    { "launch_B_Titan_F", "", 50000, 25000, "call life_coplevel >= 7"},
	    { "srifle_EBR_F", "", 25000, 12500, "call life_coplevel >= 7"},
	    { "arifle_SPAR_03_blk_F", "", 25000, 12500, "call life_coplevel >= 7"},
	    {"LMG_Mk200_pointer_F", "", 300000, 15000, "call life_coplevel >= 7"}
        };
        mags[] = {
            { "16Rnd_9x21_Mag", "", 125, 60, "" },
            { "20Rnd_556x45_UW_mag", $STR_W_mags_TaserRifle, 125, 60, "" },
            { "11Rnd_45ACP_Mag", "", 130, 65, "call life_coplevel >= 1" },
            { "30Rnd_65x39_caseless_mag", "", 130, 65, "call life_coplevel >= 2" },
            { "30Rnd_9x21_Mag", "", 250, 125, "call life_coplevel >= 2" },
            { "9Rnd_45ACP_Mag", "", 200, 100, "call life_coplevel >= 3" },
            { "20Rnd_650x39_Cased_Mag_F", "", 200, 100, "call life_coplevel >= 3" },  //Apex DLC
	    { "30Rnd_556x45_Stanag", "", 250, 100, "call life_coplevel >= 2"},
	    { "30Rnd_580x42_Mag_F", "", 250, 100, "call life_coplevel >= 2"},
	    { "30Rnd_65x39_caseless_mag", "", 250, 100, "call life_coplevel >= 3"},
	    { "30Rnd_65x39_caseless_green", "", 250, 100, "call life_coplevel >= 3"},
	    { "100Rnd_65x39_caseless_mag", "", 250, 100, "call life_coplevel >= 5"},
	    { "Titan_AA", "", 250, 100, "call life_coplevel >= 7"},
	    { "20Rnd_762x51_Mag", "", 250, 100, "call life_coplevel >= 7"},
	    { "20Rnd_762x51_Mag", "", 250, 100, "call life_coplevel >= 7"},
	    { "200Rnd_65x39_cased_Box", "", 250, 100, "call life_coplevel >= 7"}
        };
        accs[] = {
            { "muzzle_snds_L", "", 650, 325, "" },
            { "optic_MRD", "", 2750, 1375, "call life_coplevel >= 1" },
            { "acc_flashlight", "", 750, 375, "call life_coplevel >= 2" },
            { "optic_Holosight", "", 1200, 600, "call life_coplevel >= 2" },
            { "optic_Arco", "", 2500, 1250, "call life_coplevel >= 2" },
            { "muzzle_snds_H", "", 2750, 1375, "call life_coplevel >= 2" },
	    { "optic_MRCO", "", 100, 50, "call life_coplevel >= 3"},
	    { "optic_Hamr", "", 100, 50, "call life_coplevel >= 3"},
	    { "optic_DMS", "", 100, 50, "call life_coplevel >= 4"},
	    { "optic_KHS_blk", "", 100, 50, "call life_coplevel >= 5"},
	    { "optic_AMS", "", 100, 50, "call life_coplevel >= 6"},
	    { "optic_LRPS", "", 100, 50, "call life_coplevel >= 6"}
        };
    };

    //Medic Shops
    class med_basic {
        name = "store";
        side = "med";
        conditions = "";
        items[] = {
            { "ItemGPS", "", 100, 50, "" },
            { "Binocular", "", 150, 75, "" },
            { "FirstAidKit", "", 150, 75, "" },
            { "NVGoggles", "", 1200, 600, "" }
        };
        mags[] = {};
        accs[] = {};
    };
};
