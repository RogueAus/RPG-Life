#include "player_sys.sqf"

class playerSettings {
    idd = playersys_DIALOG;
    movingEnable = 1;
    enableSimulation = 1;

    class controlsBackground {
        class Life_RscTitleBackground: Life_RscPicture {
            idc = -1;
            text = "textures\YMenu.paa";
            x = 0;
            y = -0.12;
            w = 1;
            h = 1.28;
        };

        class Title: Life_RscTitle {
            colorBackground[] = {0, 0, 0, 0};
            idc = -1;
            text = "$STR_PM_Title";
            x = 0.335028 * safezoneW + safezoneX;
            y = 0.324065 * safezoneH + safezoneY;
            w = 0.329945 * safezoneW;
            h = 0.0219919 * safezoneH;
        };

        class moneyStatusInfo: Life_RscStructuredText {
            idc = 2015;
            sizeEx = 0.020;
            text = "";
            x = 0.33544 * safezoneW + safezoneX;
            y = 0.384103 * safezoneH + safezoneY;
            w = 0.123729 * safezoneW;
            h = 0.329878 * safezoneH;
        };

        class PlayersName: Title {
            idc = carry_weight;
            style = 1;
            text = "";
        };
    };

    class controls {
        class itemHeader: Life_RscText {
            idc = -1;
            colorBackground[] = {0,0,0,0};
            text = "$STR_PM_cItems";
            sizeEx = 0.04;
            x = 0.551554 * safezoneW + safezoneX;
            y = 0.357053 * safezoneH + safezoneY;
            w = 0.113419 * safezoneW;
            h = 0.0219919 * safezoneH;
        };

        class licenseHeader: Life_RscText {
            idc = -1;
            colorBackground[] = {0,0,0,0};
            text = "$STR_PM_Licenses";
            sizeEx = 0.04;
            x = 0.427825 * safezoneW + safezoneX;
            y = 0.357053 * safezoneH + safezoneY;
            w = 0.113419 * safezoneW;
            h = 0.0219919 * safezoneH;
        };

        class moneySHeader: Life_RscText {
            idc = -1;
            colorBackground[] = {0,0,0,0};
            text = "$STR_PM_MoneyStats";
            sizeEx = 0.04;
            x = 0.333378 * safezoneW + safezoneX;
            y = 0.357053 * safezoneH + safezoneY;
            w = 0.0903224 * safezoneW;
            h = 0.0219919 * safezoneH;
        };

        class itemList: Life_RscListBox {
            idc = item_list;
            sizeEx = 0.030;
            x = 0.549595 * safezoneW + safezoneX;
            y = 0.383003 * safezoneH + safezoneY;
            w = 0.117543 * safezoneW;
            h = 0.153943 * safezoneH;
        };

        class moneyEdit: Life_RscEdit {
            idc = 2018;
            text = "1";
            sizeEx = 0.030;
            x = 0.340183 * safezoneW + safezoneX;
            y = 0.456016 * safezoneH + safezoneY;
            w = 0.0742376 * safezoneW;
            h = 0.0164939 * safezoneH;
        };

        class NearPlayers: Life_RscCombo {
            idc = 2022;
            x = 0.340183 * safezoneW + safezoneX;
            y = 0.478008 * safezoneH + safezoneY;
            w = 0.0742376 * safezoneW;
            h = 0.0164939 * safezoneH;
        };

        class moneyDrop: Life_RscButtonMenu {
            idc = 2001;
            text = "$STR_Global_Give";
            colorBackground[] = {0,0,0,0.5};
            onButtonClick = "[] call life_fnc_giveMoney";
            sizeEx = 0.025;
            x = 0.345338 * safezoneW + safezoneX;
            y = 0.5 * safezoneH + safezoneY;
            w = 0.053616 * safezoneW;
            h = 0.0197927 * safezoneH;
        };

        class itemEdit: Life_RscEdit {
            idc = item_edit;
            text = "1";
            sizeEx = 0.030;
            x = 0.54997 * safezoneW + safezoneX;
            y = 0.542236 * safezoneH + safezoneY;
            w = 0.117543 * safezoneW;
            h = 0.0219919 * safezoneH;
        };

        class iNearPlayers: Life_RscCombo {
            idc = 2023;
            x = 0.549182 * safezoneW + safezoneX;
            y = 0.569934 * safezoneH + safezoneY;
            w = 0.118574 * safezoneW;
            h = 0.0219919 * safezoneH;
        };

        class DropButton: Life_RscButtonMenu {
            idc = 2002;
            text = "$STR_Global_Give";
            colorBackground[] = {0,0,0,0.5};
            onButtonClick = "[] call life_fnc_giveItem;";
            x = 0.613419 * safezoneW + safezoneX;
            y = 0.598964 * safezoneH + safezoneY;
            w = 0.0541316 * safezoneW;
            h = 0.0219919 * safezoneH;
        };

        class UseButton: Life_RscButtonMenu {
            text = "$STR_Global_Use";
            colorBackground[] = {0,0,0,0.5};
            onButtonClick = "[] call life_fnc_useItem;";
            x = 0.556156 * safezoneW + safezoneX;
            y = 0.598964 * safezoneH + safezoneY;
            w = 0.0541316 * safezoneW;
            h = 0.0219919 * safezoneH;
        };

        class RemoveButton: Life_RscButtonMenu {
            text = "$STR_Global_Remove";
            colorBackground[] = {0,0,0,0.5};
            onButtonClick = "[] call life_fnc_removeItem;";
            x = 0.5 * safezoneW + safezoneX;
            y = 0.598964 * safezoneH + safezoneY;
            w = 0.0541316 * safezoneW;
            h = 0.0219919 * safezoneH;
        };

        class ButtonClose: Life_RscPictureButtonMenu {
            idc = -1;
            //shortcuts[] = {0x00050000 + 2};
            onButtonClick = "closeDialog 0;";
            x = 0.683532 * safezoneW + safezoneX;
            y = 0.5011 * safezoneH + safezoneY;
            w = 0.0103108 * safezoneW;
            h = 0.0219919 * safezoneH;
            colorBackground[] = {0,0,0,0};
        };

        class ButtonSettings: Life_RscPictureButtonMenu {
            idc = -1;
            onButtonClick = "[] call life_fnc_settingsMenu;";
            x = 0.340183 * safezoneW + safezoneX;
            y = 0.626453 * safezoneH + safezoneY;
            w = 0.0288702 * safezoneW;
            h = 0.0494817 * safezoneH;
            colorBackground[] = {0,0,0,0};
        };

        class ButtonMyGang: Life_RscPictureButtonMenu {
            idc = 2011;
            onButtonClick = "if (isNil ""life_action_gangInUse"") then {if (isNil {(group player) getVariable ""gang_owner""}) then {createDialog ""Life_Create_Gang_Diag"";} else {[] spawn life_fnc_gangMenu;};};";
            x = 0.437104 * safezoneW + safezoneX;
            y = 0.626453 * safezoneH + safezoneY;
            w = 0.0288702 * safezoneW;
            h = 0.0494817 * safezoneH;
            colorBackground[] = {0,0,0,0};
        };

        class Licenses_Menu : Life_RscControlsGroup {
            idc = -1;
            x = 0.427825 * safezoneW + safezoneX;
            y = 0.379045 * safezoneH + safezoneY;
            w = 0.119605 * safezoneW;
            h = 0.208923 * safezoneH;

            class Controls {
                class Life_Licenses: Life_RscStructuredText {
                    idc = 2014;
                    sizeEx = 0.020;
                    text = "";
                    x = 0;
                    y = 0;
                    w = 0.27;
                    h = 0.65;
                };
            };
        };

        class ButtonGangList: Life_RscPictureButtonMenu {
            idc = 2012;
            onButtonClick = "[] call life_fnc_wantedMenu";
            x = 0.437104 * safezoneW + safezoneX;
            y = 0.626453 * safezoneH + safezoneY;
            w = 0.0288702 * safezoneW;
            h = 0.0494817 * safezoneH;
            colorBackground[] = {0,0,0,0};
        };

        class ButtonKeys: Life_RscPictureButtonMenu {
            idc = 2013;
            onButtonClick = "createDialog ""Life_key_management"";";
            x = 0.534026 * safezoneW + safezoneX;
            y = 0.626453 * safezoneH + safezoneY;
            w = 0.0288702 * safezoneW;
            h = 0.0494817 * safezoneH;
            colorBackground[] = {0,0,0,0};
        };

        class ButtonCell: Life_RscPictureButtonMenu {
            idc = 2014;
            onButtonClick = "createDialog ""Life_cell_phone"";";
            x = 0.582486 * safezoneW + safezoneX;
            y = 0.626453 * safezoneH + safezoneY;
            w = 0.0288702 * safezoneW;
            h = 0.0494817 * safezoneH;
            colorBackground[] = {0,0,0,0};
        };

        class ButtonAdminMenu: Life_RscPictureButtonMenu {
            idc = 2021;
            onButtonClick = "closeDialog 0; createDialog ""life_admin_menu"";";
            x = 0.629916 * safezoneW + safezoneX;
            y = 0.626453 * safezoneH + safezoneY;
            w = 0.0288702 * safezoneW;
            h = 0.0494817 * safezoneH;
            colorBackground[] = {0,0,0,0};
        };

        class ButtonSyncData: Life_RscPictureButtonMenu {
            idc = -1;
            //shortcuts[] = {0x00050000 + 2};
            onButtonClick = "[] call SOCK_fnc_syncData;";
            x = 0.388644 * safezoneW + safezoneX;
            y = 0.626453 * safezoneH + safezoneY;
            w = 0.0288702 * safezoneW;
            h = 0.0494817 * safezoneH;
            colorBackground[] = {0,0,0,0};
        };

        class ButtonCrafting: Life_RscButtonMenu {
            idc = 7001;
            //shortcuts[] = {0x00050000 + 2};
            text = "Craft";
            onButtonClick = "closeDialog 0; [""craftingItems""] spawn cat_crafting_fnc_craft;";
            x = 0.324717 * safezoneW + safezoneX;
            y = 0.708923 * safezoneH + safezoneY;
            w = 0.0644423 * safezoneW;
            h = 0.0219919 * safezoneH;
            colorBackground[] = {0,0,0,0};
        };
    };
};
