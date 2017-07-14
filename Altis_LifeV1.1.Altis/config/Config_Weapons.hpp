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
            { "hgun_Rook40_F", "", 7500, 3250, "" }, // Rook-40 9mm
            { "hgun_Pistol_01_F", "", 7500, 3500, "" }, // PM 9mm //APEX DLC
			{ "hgun_ACPC2_F", "", 11500, 5750, "" }, // ACP-C2 .45
			{ "hgun_Pistol_heavy_02_F", "", 13500, 11000, "" }, // Zubr .45
            { "SMG_05_F", "", 15000, 9000, "license_civ_ACW" }, // Protector 9mm //APEX DLC
            { "hgun_PDW2000_F", "", 16000, 10000, "license_civ_ACW" }, // PDW2000 9mm
			{ "SMG_02_F", "", 19500, 13500, "license_civ_ACW"}, // Sting 9mm
			{ "SMG_01_F", "", 23000, 16000, "license_civ_ACW"}, // Vermin .45
			{ "arifle_SPAR_01_snd_F", "", 35000, 19500, "license_civ_ACW"}, // Spar-16 5.56 // APEX DLC
			{ "arifle_Mk20_plain_F", "", 35000, 19500, "license_civ_ACW"} // Mk20 5.56
			};
        mags[] = {
            { "16Rnd_9x21_Mag", "", 175, 60, "" }, // Rook-40 Ammo - 9mm
            { "6Rnd_45ACP_Cylinder", "", 150, 75, "" }, // Zubr Ammo - .45
            { "9Rnd_45ACP_Mag", "", 250, 100, "" }, // ACP-C2 Ammo - .45
            { "30Rnd_9x21_Mag", "", 350, 125, "license_civ_ACW" }, // PDW2000 SMG Ammo - 9mm
            { "30Rnd_9x21_Mag_SMG_02", "", 350, 125, "license_civ_ACW" }, // Sting/Protector SMG Ammo - 9mm
            { "10Rnd_9x21_Mag", "", 175, 125, "" }, // PM 9mm Ammo - 9mm //APEX DLC
			{ "30Rnd_45ACP_Mag_SMG_01", "", 400, 150, "license_civ_ACW" }, // Vermin SMG Ammo - .45
			{ "30Rnd_556x45_Stanag", "", 575, 250, "license_civ_ACW" } // Spar-16/Mk20 Ammo - 5.56
        };
        accs[] = {
            { "optic_ACO_grn_smg", "", 1200, 600, "license_civ_ACW" }, // ACO (Green)
			{ "optic_Aco_smg", "", 1200, 600, "license_civ_ACW" }, // ACO
			{ "optic_Holosight", "", 1350, 800, "license_civ_ACW" }, // Holosight
			{ "optic_Holosight_blk_F", "", 1350, 800, "license_civ_ACW" }, // Holosight (Black) // APEX DLC
			{ "optic_Hamr", "", 2750, 1250, "license_civ_ACW" }, // RCO
			{ "optic_Arco", "", 2750, 1250, "license_civ_ACW" } // ARCO
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
            { "arifle_TRG20_F", "", 30000, 12500, "" }, // TRG-20
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
			{"30Rnd_9x21_Mag", "", 500, 150, "" }, // Rook-40/PDW Ammo - 9mm
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
            { "optic_Holosight", "", 250, 50, "" }, // Holosight
            { "optic_Holosight_blk_F", "", 250, 50, "" }, // Holosight (Black)
            { "optic_ACO_grn", "", 500, 150, "" }, // ACO (Green)
            { "optic_Aco", "", 500, 150, "" }, // ACO
			{ "optic_Arco", "", 1500, 250, "" }, // ARCO
			{ "optic_Arco_blk_F", "", 1500, 250, "" }, // ARCO (Black)
			{ "optic_Hamr", "", 2250, 350, "" }, // RCO
			{ "optic_ERCO_blk_F", "", 2250, 350, "" }, // ERCO (Black) // APEX DLC
			{ "optic_ERCO_snd_F", "", 2250, 350, "" }, // ERCO (Sand) // APEX DLC
			{ "optic_SOS", "", 4235, 550, "" }, // MOS
			{ "optic_DMS", "", 5000, 620, "" }, // DMS
			{ "optic_KHS_tan", "", 7320, 1250, "" }, // Kahlia (Tan)
			{ "optic_KHS_blk", "", 7320, 1250, "" }, // Kahlia (Black)
			{ "optic_AMS_snd", "", 8750, 1500, "" }, // AMS (Sand)
			{ "optic_AMS", "", 8750, 1500, "" }, // AMS
			{ "optic_NVS", "", 12500, 2200, "" }, // NVS
			{ "bipod_01_F_snd", "", 1500, 350, "" }, // Bipod (Sand)
			{ "bipod_01_F_blk", "", 1500, 350, "" } // Bipod (Black)
        };
    };

    class gang {
        name = "Hideout Armament";
        side = "civ";
        conditions = "";
        items[] = {
            { "hgun_Rook40_F", "", 4000, 1200, "" }, // Roook-40 9mm
			{ "hgun_ACPC2_F", "", 7500, 2250, "" }, // ACP-C2 .45
			{ "hgun_Pistol_heavy_01_F", "", 11000, 5500, "" }, // 4-Five .45
            { "hgun_Pistol_heavy_02_F", "", 12500, 7500, "" }, // Zubr .45
            { "hgun_PDW2000_F", "", 19500, 14750, "" }, // PDW2000 9mm
			{ "SMG_01_F", "", 25250, 16000, ""}, // Vermin .45
			{ "arifle_TRG20_F", "", 55000, 22500, "" } // TRG-20 5.56
        };
        mags[] = {
			{ "11Rnd_45ACP_Mag", "", 200, 100, "" }, // 4-Five Ammo - 45. ACP
			{ "30Rnd_556x45_Stanag", "", 550, 150, "" }, // TRG-20 Ammo - 5.56
			{ "30Rnd_45ACP_Mag_SMG_01", "", 400, 150, "" }, // Vermin SMG Ammo - .45
            { "16Rnd_9x21_Mag", "", 125, 60, "" }, // Rook-40 Ammo - 9mm
            { "6Rnd_45ACP_Cylinder", "", 150, 75, "" }, // Zubr Ammo - .45
            { "9Rnd_45ACP_Mag", "", 200, 100, "" }, // ACP-C2 Ammo - .45
            { "30Rnd_9x21_Mag", "", 250, 125, "" } // PDW2000 Ammo - 9mm
        };
        accs[] = {
            { "optic_ACO_grn", "", 1700, 450, "" }, // ACO (Green)
            { "optic_Aco", "", 1700, 450, "" }, // ACO
			{ "optic_Arco", "", 4500, 1850, "" }, // ARCO
			{ "optic_Hamr", "", 4500, 1850, "" } // RCO
			
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
	    { "M320 LRR .408", "", 40000, 20000, "call life_coplevel >= 5"},
	    { "srifle_DMR_03_F", "", 325000, 8000, "" }, // Mk1 EMR
	    { "launch_B_Titan_F", "", 50000, 25000, "call life_coplevel >= 7"},
	    { "srifle_EBR_F", "", 25000, 12500, "call life_coplevel >= 7"},
	    { "arifle_SPAR_03_blk_F", "", 25000, 12500, "call life_coplevel >= 7"},
	    { "LMG_Mk200_pointer_F", "", 300000, 15000, "call life_coplevel >= 7"}
        };
        mags[] = {
            { "16Rnd_9x21_Mag", "", 125, 60, "" },
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
	    {"7Rnd_408_Mag", "", 250, 125, "call life_coplevel >= 5"},
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
	
	//SERT Shops
	class sert_basic {
	name = "STR_Shops_W_SERT";
	side = "cop";
	conditions = "license_cop_SERT";
	items[] = {
	{ "hgun_P07_F", "", 7500, 3750, "" }	
	};
	mags[] = {};
	accs[] = {};
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
