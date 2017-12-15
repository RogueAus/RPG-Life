#include "..\..\script_macros.hpp"
/*
    File: fn_onFired.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Handles various different ammo types being fired.
*/
private ["_unit","_weapon","_ammoType","_magType","_projectile"];
_unit = _this select 0;
_weapon = _this select 1;
_ammoType = _this select 4;
_magType = _this select 5;
_projectile = _this select 6;

if (_ammoType isEqualTo "GrenadeHand_stone") then {
    _projectile spawn {
        private "_position";
        while {!isNull _this} do {
            _position = ASLtoATL (visiblePositionASL _this);
            sleep 0.1;
        };
        [_position] remoteExec ["life_fnc_flashbang",RCLIENT];
    };
};

if(playerSide isEqualTo west) then {
   if(_weapon in ["hgun_P07_snds_F","arifle_SDAR_F"] && _projectile in ["B_9x21_Ball","B_556x45_dual"]) then {
       _unit spawn {
            player setAmmo [currentWeapon player, 0];
            sleep 2;
            player setAmmo [currentWeapon player, 1];
       }
   };
};

if((!(playerSide isEqualTo west))&&(player inArea "safezone_kav"))then {
    deleteVehicle _projectile;

    if(aug_shot_safezone > 4)exitWith {
        aug_shot_safezone = 0;
        removeAllWeapons player;

        titleText ["Your weapons have been removed for shooting in the safezone","PLAIN DOWN"];
        hint "Your weapons have been removed for shooting in the safezone";
    };

    aug_shot_safezone = aug_shot_safezone + 1;
    hint format ["Stop shooting in the safezone! \n(Warning %1 / 5)",aug_shot_safezone];
};
