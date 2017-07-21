class life_bounty_menu {
    idd = 7400;
    name= "life_bounty_menu";
    movingEnable = false;
    enableSimulation = true;
    //onLoad = "[] spawn life_fnc_wantedadd2;";

    class controlsBackground {
        class Life_RscTitleBackground: Life_RscText {
            colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", "(profilenamespace getvariable ['GUI_BCG_RGB_A',0.7])"};
            idc = -1;
            x = 0.1;
            y = 0.2;
            w = 0.6;
            h = (1 / 25);
        };

        class MainBackground: Life_RscText {
            colorBackground[] = {0, 0, 0, 0.7};
            idc = -1;
            x = 0.1;
            y = 0.2 + (11 / 250);
            w = 0.6;
            h = 0.6 - (22 / 250);
        };
    };

    class controls {
        class Title: Life_RscTitle {
            colorBackground[] = {0, 0, 0, 0};
            idc = -1;
            text = "$STR_Wanted_Title";
            x = 0.1;
            y = 0.2;
            w = 0.6;
            h = (1 / 25);
        };

        class WantedConnection: Title {
            idc = 7404;
            style = 1;
            text = "";
        };

        class WantedList: Life_RscListBox {
            idc = 7401;
            text = "";
            sizeEx = 0.035;
            onLBSelChanged = "[] spawn life_fnc_bountyGrab";
            x = 0.12;
            y = 0.28;
            w = 0.2;
            h = 0.3;
        };

        class PlayerList: Life_RscListBox {
            idc = 7406;
            text = "";
            sizeEx = 0.035;
            //colorBackground[] = {0,0,0,0};
            onLBSelChanged = "";
            x = 0.34;
            y = 0.28;
            w = 0.2;
            h = 0.3;
        };

        class WantedDetails: Life_RscListBox {
            idc = 7402;
            text = "";
            sizeEx = 0.035;
            colorBackground[] = {0, 0, 0, 0};
            x = 0.12;
            y = 0.62;
            w = 0.48;
            h = 0.12;
        };

        class BountyPrice: Life_RscText    {
            idc = 7403;
            text = "";
            x = 0.12;
            y = 0.30;
            w = 0.6;
            h = 0.6;
        };

        class WantedAddL: Life_RscCombo    {
            idc = 7407;
            x = 0.542;
            y = 0.28;
            w = (8 / 52);
            h = 0.03;
        };

        class CloseButtonKey: Life_RscButtonMenu {
            idc = -1;
            text = "$STR_Global_Close";
            onButtonClick = "closeDialog 0;";
            x = -0.06 + (6.25 / 40) + (1 / 250 / (safezoneW / safezoneH));
            y = 0.8 - (1 / 25);
            w = (6.25 / 40);
            h = (1 / 25);
        };

        class PardonButtonKey: Life_RscButtonMenu {
            idc = 7405;
            text = "$STR_Wanted_Pardon";
            onButtonClick = "[] call life_fnc_pardon; closeDialog 0;";
            x = 0.1 + (6.25 / 40) + (1 / 250 / (safezoneW / safezoneH));
            y = 0.8 - (1 / 25);
            w = (6.25 / 40);
            h = (1 / 25);
        };

        class wantedText: Life_RscText {
            idc = 7408;
            text = "$STR_Wanted_People";
            x = 0.12;
            y = 0.11;
            w = 0.2;
            h = 0.3;
        };

        class citizensText: Life_RscText {
            idc = 1001;
            text = "$STR_Wanted_Citizens";
            x = 0.34;
            y = 0.11;
            w = 0.2;
            h = 0.3;
        };

        class crimesText: Life_RscText {
            idc = 1002;
            text = "$STR_Wanted_Crimes";
            x = 0.542;
            y = 0.245;
            w = (8 / 52);
            h = 0.03;
        };
    };
};