class moreAppsAdmin {
    idd = 3003;
    movingEnable = 1;
    enableSimulation = 1;

    class controlsBackground {
        class Life_RscTitleBackground: Life_RscPicture {
            idc = -1;
            text = "textures\moreAppsAdmin1.paa";
            x = 0.293784 * safezoneW + safezoneX;
            y = 0.159126 * safezoneH + safezoneY;
            w = 0.412431 * safezoneW;
            h = 0.70374 * safezoneH;
        };
	};
	    class controls {
        class ButtonCrafting: Life_RscPictureButtonMenu {
            idc = 7001;
            //shortcuts[] = {0x00050000 + 2};
            onButtonClick = "closeDialog 0; [""craftingItems""] spawn cat_crafting_fnc_craft;";
            x = 0.391896 * safezoneW + safezoneX;
            y = 0.371923 * safezoneH + safezoneY;
            w = 0.0280877 * safezoneW;
            h = 0.0419919 * safezoneH;
            colorBackground[] = {0,0,0,0};
			tooltip = "Craft Menu";
        };

        class ButtonMarket : Life_RscPictureButtonMenu {
            idc = 3025;
            onButtonClick = "createDialog ""life_dynmarket_prices"";";
            x = 0.340896 * safezoneW + safezoneX;
            y = 0.371923 * safezoneH + safezoneY;
            w = 0.0280877 * safezoneW;
            h = 0.0419919 * safezoneH;
            colorBackground[] = {0,0,0,0};
			tooltip = "Market Prices";
        };
		
		class ButtonAdminMenu: Life_RscPictureButtonMenu {
            idc = 2021;
            onButtonClick = "closeDialog 0; createDialog ""life_admin_menu"";";
            x = 0.443896 * safezoneW + safezoneX;
            y = 0.373923 * safezoneH + safezoneY;
            w = 0.0280877 * safezoneW;
            h = 0.0419919 * safezoneH;
            colorBackground[] = {0,0,0,0};
            tooltip = "Admin Menu";
        };
		
	    class ButtonGoBack : Life_RscPictureButtonMenu {
            idc = 3026;
            onButtonClick = "closeDialog 0; [] spawn life_fnc_p_openMenu;";
            x = 0.337896 * safezoneW + safezoneX;
            y = 0.636923 * safezoneH + safezoneY;
            w = 0.0280877 * safezoneW;
            h = 0.0419919 * safezoneH;
            colorBackground[] = {0,0,0,0};
			tooltip = "Go Back";
        };
    };
};