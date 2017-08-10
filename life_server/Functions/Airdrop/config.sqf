/*
	@file Version: 1.0.0.0
	@file Author: RYN_Ryan
	@file edit: 20.01.2015
	Copyright � 2015 Ryan Torzynski, All rights reserved
	All servers are allowed to use this code, modify and publish it. Every modified release of this script must contain "Original by RTT"
*/
airdrop_helicopter_main = "B_Heli_Transport_03_unarmed_F";
airdrop_helicopter_scnd = "B_Heli_Attack_01_F";
airdrop_chance = 100;
//Cords Of Were To Do The Drops
airdrop_positions = [[5228.49,12576.7,0],[5560.94,14875.2,0],[7138.13,13083,0],[5863.29,10692.5,0]];
_airdrop_time_interval = [1,4]; //Hour Intervals 1=60min

// Do not modify the following code
airdrop_time_min = _airdrop_time_interval select 0;
airdrop_time_max = _airdrop_time_interval select 1;
airdrop_time_min = airdrop_time_min*3600;
airdrop_time_max = airdrop_time_max*3600;

if (airdrop_time_min>=airdrop_time_max) exitWith {airdrop_enable=false;};
airdrop_enable=true;
airdrop_goingon=false;