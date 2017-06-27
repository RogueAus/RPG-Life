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
    Color = "Farbe";

    category[] = { //Category
        {
            "weapon", //Variable
            "Weapon", //Text
            {"hgun_P07_F","",{"diamond_cut",2,"copper_refined",1},"","",0}, // {Item 1, Condition (default: ""), {Required Item1, Required Number of Item1, Required Item2, Required Number of Item2}, Skinname, Skin Page only | 1 for all other items)},
            {"SMG_01_F","(call life_adminlevel) > 0",{"copper_refined",3,"iron_refined",3,"diamond_cut",1},"","",0} // {Item 2, Condition (default: ""), {Required Item1, Required Number of Item1, Required Item2, Required Number of Item2}, Skinname, Skin Page only | 1 for all other items)} No comma at last!
        }, //Komma
        {
            "uniform",
            "Uniform",
            {"U_IG_Guerilla1_1","",{"copper_refined",1},"","",0}
        },
        {
            "backpack",
            "Backpack",
            {"B_Carryall_oli","",{"diamond_cut",1},"","",0}
        },
        {
            "vest",
            "Vest",
            {"V_Press_F","",{"copper_refined",1},"","",0}
        },
        {
            "item",
            "Items",
            {"iron_refined","",{"copper_refined",2},"","",1},
            {"diamond_cut","",{"copper_refined",1,"iron_refined",1},"","",1}
        } //No Comma at Last
    };

    craftingStations[] = { // available categories at different crafting stations
        {
            "craftingItems", //Variable name
            "craftingItemsMarker", // name of the spawn marker on the map (must exist in the mission.sqm)
            {"item","weapon"} //Variables of available categories
        }, //Comma
        {
            "craftingClothes", //Variablenname
            "craftingClothesMarker",
            {"uniform","backpack","vest"} //Variablennamen der verfügbaren Kategorien
        } //No comma at last
    };
};