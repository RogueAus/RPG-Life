#include "..\..\script_macros.hpp"
/*
    File: fn_onFired.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Handles various different ammo types being fired.
*/
private ["_ammoType","_projectile"];
_ammoType = _this select 4;
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

if((!(playerSide isEqualTo west))&&(player inArea "safezone_kav"))then {
    deleteVehicle _projectile;

    if(ARA_shot_safezone > 4)exitWith {
        ARA_shot_safezone = 0;
        removeAllWeapons player;

        titleText ["Your weapons have been removed for shooting in the safezone","PLAIN DOWN"];
        hint "Your weapons have been removed for shooting in the safezone";
    };

    ARA_shot_safezone = ARA_shot_safezone + 1;
    hint format ["Stop shooting in the safezone!! \n(Warning %1 / 5)",ARA_shot_safezone];
};
