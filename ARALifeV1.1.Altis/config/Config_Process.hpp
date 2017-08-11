/*
*   class:
*       MaterialsReq (Needed to process) = Array - Format -> {{"ITEM CLASS",HOWMANY}}
*       MaterialsGive (Returned items) = Array - Format -> {{"ITEM CLASS",HOWMANY}}
*       Text (Progess Bar Text) = Localised String
*       NoLicenseCost (Cost to process w/o license) = Scalar
*
*   Example for multiprocess:
*
*   class Example {
*       MaterialsReq[] = {{"cocaine_processed",1},{"heroin_processed",1}};
*       MaterialsGive[] = {{"diamond_cut",1}};
*       Text = "STR_Process_Example";
*       //ScrollText = "Process Example";
*       NoLicenseCost = 4000;
*   };
*/

class ProcessAction {

//// Custom ////

   //// Weapons Components ////
    class rifleBody {
        MaterialsReq[] = {{"steelIngot",25},{"copper_refined",15}};
        MaterialsGive[] = {{"rifleBody",1}};
        Text = "STR_Process_rifleBody";// Todo: Localize
        //ScrollText = "Create Rifle Body";
        NoLicneseCost = -1;
    };

    class rifleStock {
        MaterialsReq[] = {{"steelIngot",10},{"copper_refined",5},{"wood_plank",10}};
        MaterialsGive[] = {{"rifleStock",1}};
        Text = "STR_Process_rifleStock";// Todo: Localize
        //ScrollText = "Create Rifle Stock";
        NoLicenseCost = -1;
    };

    class rifleBarrel {
        MaterialsReq[] = {{"steelIngot",15}, {"copper_refined",7}};
        MaterialsGive[] = {{"rifleBarrel",1}};
        Text = "STR_Process_rifleBarrel";// Todo: Localize
        //ScrollText = "Create Rifle Barrel";
        NoLicenseCost = -1;
    };

    class LmgBody {
        MaterialsReq[] = {{"steelIngot",35},{"copper_refined",20}};
        MaterialsGive[] = {{"LmgBody",1}};
        Text = "STR_Process_LmgBody";// Todo: Localize
        //ScrollText = "Create Lmg Body";
        NoLicenseCost = -1;
    };

    class LmgStock {
        MaterialsReq[] = {{"steelIngot",20},{"copper_refined",12},{"wood_plank",15}};
        MaterialsGive[] = {{"LmgStock",1}};
        Text = "STR_Process_LmgStock";// Todo: Localize
        //ScrollText = "Create Lmg Stock";
        NoLicenseCost = -1;
    };

    class LmgBarrel {
        MaterialsReq[] = {{"steelIngot",20},{"copper_refined",15}};
        MaterialsGive[] = {{"LmgBarrel",1}};
        Text = "STR_Process_LmgBarrel";// Todo: Localize
        //ScrollText = "Create Lmg Barrel";
        NoLicenseCost = -1;
    };

    class sniperBody {
        MaterialsReq[] = {{"steelIngot",30},{"copper_refined",20}};
        MaterialsGive[] = {{"sniperBody",1}};
        Text = "STR_Processs_sniperBody";// Todo: Localize
        //ScrollText = "Create Sniper Body";
        NoLicenseCost = -1;
    };

    class sniperStock {
        MaterialsReq[] = {{"steelIngot",20},{"copper_refined",15},{"wood_plank",20}};
        MaterialsGive[] = {{"sniperStock",1}};
        Text = "STR_Process_sniperStock";// Todo: Localize
        //ScrollText = "Create Sniper Stock";
        NoLicenseCost = -1;
    };

    class sniperBarrel {
        MaterialsReq[] = {{"steelIngot",25},{"copper_refined",20}};
        MaterialsGive[] = {{"sniperBarrel",1}};
        Text = "STR_Process_sniperBarrel";// Todo: Localize
        //ScrollText = "Create Sniper Barrel";
        NoLicenseCost = -1;
    };

    class steel {
        MaterialsReq[] = {{"iron_refined",1},{"copper_refined",1}};
        MaterialsGive[] = {{"steelIngot",1}};
        Text = "STR_Process_Steel";
        //ScrollText = "Smelt Steel";
        NoLicenseCost = 2100;
    };

    //// Mined ////
    class coal {
        MaterialsReq[] = {{"coal",1}};
        MaterialsGive[] = {{"pureCoal",1}};
        Text = "STR_Process_Coal";
        //ScrollText = "Purify Coal";
        NoLicenseCost = 1000;
    };
	
	class wood {
		MaterialsReq[] = {{"wood_log",1}};
		MaterialsGive[] = {{"wood_plank",1}};
		text = "STR_Process_Wood";
		//ScrollText = "Saw Wood";
		NoLicenseCost = 1350;
	};
		

//// End Custom ////
    class oil {
        MaterialsReq[] = {{"oil_unprocessed",1}};
        MaterialsGive[] = {{"oil_processed",1}};
        Text = "STR_Process_Oil";
        //ScrollText = "Process Oil";
        NoLicenseCost = 1200;
    };

    class diamond {
        MaterialsReq[] = {{"diamond_uncut",1}};
        MaterialsGive[] = {{"diamond_cut",1}};
        Text = "STR_Process_Diamond";
        //ScrollText = "Cut Diamonds";
        NoLicenseCost = 1350;
    };

    class heroin {
        MaterialsReq[] = {{"heroin_unprocessed",1}};
        MaterialsGive[] = {{"heroin_processed",1}};
        Text = "STR_Process_Heroin";
        //ScrollText = "Process Heroin";
        NoLicenseCost = 1750;
    };

    class copper {
        MaterialsReq[] = {{"copper_unrefined",1}};
        MaterialsGive[] = {{"copper_refined",1}};
        Text = "STR_Process_Copper";
        //ScrollText = "Refine Copper";
        NoLicenseCost = 750;
    };

    class iron {
        MaterialsReq[] = {{"iron_unrefined",1}};
        MaterialsGive[] = {{"iron_refined",1}};
        Text = "STR_Process_Iron";
        //ScrollText = "Refine Iron";
        NoLicenseCost = 1120;
    };

    class sand {
        MaterialsReq[] = {{"sand",1}};
        MaterialsGive[] = {{"glass",1}};
        Text = "STR_Process_Sand";
        //ScrollText = "Melt Sand into Glass";
        NoLicenseCost = 650;
    };

    class salt {
        MaterialsReq[] = {{"salt_unrefined",1}};
        MaterialsGive[] = {{"salt_refined",1}};
        Text = "STR_Process_Salt";
        //ScrollText = "Refine Salt";
        NoLicenseCost = 450;
    };

    class cocaine {
        MaterialsReq[] = {{"cocaine_unprocessed",1}};
        MaterialsGive[] = {{"cocaine_processed",1}};
        Text = "STR_Process_Cocaine";
        //ScrollText = "Process Cocaine";
        NoLicenseCost = 1500;
    };

    class marijuana {
        MaterialsReq[] = {{"cannabis",1}};
        MaterialsGive[] = {{"marijuana",1}};
        Text = "STR_Process_Marijuana";
        //ScrollText = "Harvest Marijuana";
        NoLicenseCost = 500;
    };

    class cement {
        MaterialsReq[] = {{"rock",1}};
        MaterialsGive[] = {{"cement",1}};
        Text = "STR_Process_Cement";
        //ScrollText = "Mix Cement";
        NoLicenseCost = 350;
    };
};
