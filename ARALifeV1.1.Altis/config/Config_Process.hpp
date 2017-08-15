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
		Text = "STR_Process_Wood";
		//ScrollText = "Saw Wood";
		NoLicenseCost = 1350;
	};

	class cCoal {
	    MaterialsReq[] = {{"wood_log",1}};
	    MaterialsGive[] = {{"cCoal",2}};
	    Text = "STR_Process_cCoal";
	    //ScrollText = "Burn Wood";
	    NoLicenseCost = 1200;
	};

    class caliche {
       MaterialsReq[] = {{"calicheOre",1}};
       MaterialsGive[] = {{"pNitrate",1}};
       Text = "STR_Process_Caliche";
       //ScrollText = "Extract Potassium";
       NoLicenseCost = 2000;
    };

	class gunPowder {
	    MaterialsReq[] = {{"pNitrate",1},{"cCoal",1},{"sulfur",1}};
	    MaterialsGive[] = {{"gunPowder",1}};
	    Text = "STR_Process_gunPowder";
	    //ScrollText = "Mix Ingredients";
	    NoLicenseCost = 2000;
	};

	class brass {
	    MaterialsReq[] = {{"zinc",1},{"copper_refined",1}};
	    MaterialsGive[] = {{"brass",1}};
	    Text = "STR_Process_brass";
	    //ScrollText = "Smelt Brass";
	    NoLicenseCost = 2100;
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
        //ScrollText = "Pocess Cannabis";
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
