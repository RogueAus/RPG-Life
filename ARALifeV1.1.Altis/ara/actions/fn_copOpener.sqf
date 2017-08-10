/*
 File: fn_copOpener.sqf
     Author: Rogue & Killer

     Description:
     Opens the Gates on key press for Cops.
*/
// bargate
{
    if (!(playerSide isEqualTo west)) exitWith {};
    _phase = _x animationPhase "Door_1_rot";
    if (_phase == 0) then {
        _x animate ["Door_1_rot",1];
    } else {
        _x animate ["Door_1_rot",0];
    };
} forEach nearestObjects [player,["Land_BarGate_F"],30];//TODO Remove BackAlley gate from here



{
    if (life_inv_copRemote < 1) then {
        hintSilent "You must have a remote to open the gate!";
    } else {
        _phase = _x animationPhase "Door_1_move";
        if (_phase == 0) then {
            _x animate ["Door_1_move",1];
        } else {
            _x animate ["Door_1_move",0];
        };
    };
} forEach nearestObjects [player,["Land_ConcreteWall_01_l_gate_F","Land_ConcreteWall_01_m_gate_F"],30];

