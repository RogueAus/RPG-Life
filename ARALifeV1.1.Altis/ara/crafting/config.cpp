/*
    File: config.cpp
    Author: B4v4r!4n_Str!k3r (julianbauer@cationstudio.com)
    Licence: THIS FILE AND EXTRACTS OF IT IS THE MINDSET OF CATIONSTUDIO
             AND ONLY AUTHORIZED PEOPLE/SERVERS ARE ALLOWED TO USE IT.
    Description: Master config for crafting system.
*/
#include "dialog\craft.hpp"
class Cation_Crafting {

    version_4_4 = 1; // version 3.x - 4.3 -> 0 | version 4.4+ -> 1
    duration = 0.3; //Duration in crafting process for 1% in seconds (Possible values ​​between 0.1 and 10)

    //Texte
    Craftingmenu = "Crafting Menu";
    CraftStats = "Craftable Items";
    CraftingMaterials = "Required Components";
    CraftButton = "Craft Item!";
    Close = "Close";
    Craft = "Craft";
    NoMaterial = "You don't have the Required Components!";
    Process = "You have crafted the following:";
    Process_Stay = "You have to stay within 10m to craft.";
    NotificationBackpack = "You already have a Backpack! Remove the old one first.";
    NotificationVest = "You already have a Vest! Remove the old one first.";
    NotificationUnifrom = "You already have something on! Remove your Uniform and try again.";
    SelectItemFirst = "You must select an item first!";
    NothingNeeded = "Nothing is required!";
    NoRoom = "You do not have the inventory space for the item.";
    Veh_Block = "A vehicle is currently blocking the spawn point";
    NoSpawnpoint = "No Spawnpoint Available";
    Color = "Paint";

    category[] = { //Category TODO Put together crafting system configs for various activities
        {
            "weapon", //Variable
            "Weapon", //Text
            {"LMG_Zafir_F","",{"LmgBody",1,"LmgStock",1,"LmgBarrel",1,"goldBar",9},"","",0},
            {"MMG_02_sand_F","",{"LmgBody",1,"LmgStock",1,"LmgBarrel",1,"goldBar",12},"","",0},
            {"MMG_01_tan_F","",{"LmgBody",1,"LmgStock",1,"LmgBarrel",1,"goldBar",14},"","",0},
            {"srifle_DMR_02_sniper_F","",{"sniperBody",1,"sniperStock",1,"sniperBarrel",1,"goldBar",6},"","",0},
            {"srifle_DMR_05_tan_f","",{"sniperBody",1,"sniperStock",1,"sniperBarrel",1,"goldBar",8},"","",0},
            {"srifle_LRR_F","",{"sniperBody",1,"sniperStock",1,"sniperBarrel",1,"goldBar",13},"","",0},
            {"srifle_GM6_F","",{"sniperBody",1,"sniperStock",1,"sniperBarrel",1,"goldBar",16},"","",0}


        }, //Komma
        {
            "uniform",
            "Uniform",
            //{"U_IG_Guerilla1_1","",{"copper_refined",1},"","",0}
        },
        {
            "backpack",
            "Backpack",
            //{"B_Carryall_oli","",{"diamond_cut",1},"","",0}
        },
        {
            "vest",
            "Vest",
            //{"V_Press_F","",{"copper_refined",1},"","",0}
        },
        {
            "item",
            "Items",
            {"rifleBody","",{"steelIngot",10},"","",1},
            {"rifleStock","",{"steelIngot",5,"wood_plank",10},"","",1},
            {"rifleBarrel","",{"steelIngot",5},"","",1},
            {"LmgBody","",{"steelIngot",10,"copper_refined",5},"","",1},
            {"LmgStock","",{"steelIngot",7,"copper_refined",5,"wood_plank",15},"","",1},
            {"LmgBarrel","",{"steelIngot",10,"copper_refined",5},"","",1},
            {"sniperBody","",{"steelIngot",15,"copper_refined",10},"","",1},
            {"sniperStock","",{"steelIngot",10,"copper_refined",5,"wood_plank",15},"","",1},
            {"sniperBarrel","",{"steelIngot",15,"copper_refined",10},"","",1}
        } //No Comma at Last
    };
/*
    In order to create crafting stations the following must be added to the  desired objects init:

    this addAction["Station Name",{["variableName"] spawn cat_crafting_fnc_craft}];

*/
    craftingStations[] = { // available categories at different crafting stations
        {
            "craftingItems", //Variable name
            "craftingItemsMarker", // name of the spawn marker on the map (must exist in the mission.sqm)
            {"item", "weapon"} //Variables of available categories
        }, //Comma
        {
            "craftingClothes", //Variablenname
            "craftingClothesMarker",
            {"uniform","backpack","vest"} //Variablennamen der verfügbaren Kategorien
        } //No comma at last
    };
};