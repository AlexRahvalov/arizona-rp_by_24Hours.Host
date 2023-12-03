#define FILTERSCRIPT
#pragma 									tabsize 4
#include 									a_samp
#include									Pawn.RakNet
#include 									Pawn.CMD
#include									mapandreas
#include 									file
#include									mxINI
#include									sscanf2
#include 									LauncherAddon
#define public:%0(%1)					forward %0(%1); public %0(%1)
//ОБНОВЛЯТЬ В МОДЕ ПРИ ДОБАВЛЕНИИ НОВОГО ПУНКТА!!!
static const 
	ac_code_name[][15+10] =
{
	{"Обход Аутентификации"},
	{"isvalid packet"},
	{"Unoccupied Bypasser"}, 
	{"fmop"},
	{"AirBreak"},
	{"teleport on foot"},
	{"dgun"},
	{"nop resetweapon"},
	{"damager"},
	{"nop position"},
	{"flood auto-callable func"},
	{"flood many requests"},
	{"teleport with car"},
	{"speedhack with car"},
	{"Fast Walk"}
},
	UnicalDostup[][] = 
{
	{"Martys_Mcfly"},
	{"Andrey_Sotov"},
	{"NoName"}
},
	ac_tick_callback[][] =
{
	{90, 12}, //EnterVehicle - ID: 26
	{90, 12}, //ExitVehicle - ID: 154
	{300, 3}, //VehicleDestroyed - ID: 136
	{700, 9}, //SendSpawn - ID: 52
	{700, 4}, //DeathNotification - ID: 53
	{140, 17} //DialogResponse - ID: 62
},
	uf_VehicleSpeeds[] =
{
	160, 160, 200, 120, 150, 165, 110, 170, 110, 180, 160, 240, 160, 160, 140,
	230, 155, 200, 150, 160, 180, 180, 165, 145, 170, 200, 200, 170, 170, 200,
	190, 130, 800, 180, 200, 120, 160, 160, 160, 160, 160, 750, 150, 150, 110,
	165, 190, 200, 190, 150, 120, 240, 190, 190, 190, 140, 160, 160, 165, 160,
	200, 190, 260, 190, 750, 750, 160, 160, 190, 200, 170, 160, 190, 190, 160,
	160, 200, 200, 150, 165, 200, 120, 150, 120, 190, 160, 100, 200, 200, 170,
	170, 160, 160, 190, 220, 170, 200, 200, 140, 140, 160, 750, 260, 260, 160,
	260, 230, 165, 140, 120, 140, 200, 200, 200, 120, 120, 165, 165, 160, 340,
	340, 190, 190, 190, 110, 160, 160, 160, 170, 160, 600, 700, 140, 200, 160,
	160, 160, 110, 110, 150, 160, 230, 160, 165, 260, 160, 160, 160, 200, 160,
	160, 165, 160, 200, 170, 180, 110, 110, 200, 200, 200, 200, 200, 200, 750,
	200, 160, 160, 170, 110, 110, 900, 600, 110, 600, 160, 160, 200, 110, 160,
	165, 190, 160, 170, 120, 165, 260, 200, 140, 200, 260, 120, 200, 200, 600,
	190, 200, 200, 200, 160, 165, 110, 200, 200, 260, 260, 160, 160, 160, 140,
	160, 260
};
/*
update
вставить в мод
|
	|
	ЕСЛИ УЖЕ В МОДЕ ЕСТЬ - ЗАМЕНИТЬ
	ЕСЛИ ЕСТЬ АНТИ ЧИТЫ СТОРОННИЕ - УДАЛИТЬ
	
	static const ac_code_name[][15+10] =
	{
		{"Обход Аутентификации"},
		{"isvalid packet"},
		{"Unoccupied Bypasser"}, 
		{"fmop"},
		{"AirBreak"},
		{"teleport on foot"},
		{"dgun"},
		{"nop resetweapon"},
		{"damager"},
		{"nop position"},
		{"flood auto-callable func"},
		{"flood many requests"},
		{"teleport with car"},
		{"speedhack with car"},
		{"Fast Walk"}
	};
	public: OnCheatDetected(playerid, code, type)
	{
		if(!IsPlayerConnected(playerid)) return 1;
		//
		if(IsPlayerLogged{playerid} != false && !code) return -1;
		switch(code)
		{
			case 3..5,9,12,13: if(PI[playerid][pAdmin] > 5) return -2;
		}
		switch(type)
		{
			case 1:
			{
				//warning
				SendAdminsMessagef(0xD2B88FFF, "[XXL Guard] %s[%i] подозревается в использовании чит-программ: %s [code: %03i].", PN(playerid), playerid, ac_code_name[code], code + 100);
				printf("[XXL Guard] %s[%i] подозревается в использовании чит-программ: %s [code: %03i].", PN(playerid), playerid, ac_code_name[code], code + 100);
				//continue
			}
			case 2:
			{
				//kick
				SendAdminsMessagef(0xD2B88FFF, "[XXL Guard] %s[%i] был кикнут по подозрению в использовании чит-программ: %s [code: %03i].", PN(playerid), playerid, ac_code_name[code], code + 100);
				printf("[XXL Guard] %s[%i] был кикнут по подозрению в использовании чит-программ: %s [code: %03i].", PN(playerid), playerid, ac_code_name[code], code + 100);
				ToCheat(playerid, code);
			}
		}
		//end
		return 1;
	}
	stock ToCheat(playerid, code)
	{
		static hour, minute, day, month, year;
		gettime(hour, minute);
		getdate(year, month, day);
		str_2[0] = EOS, f(str_2, sizeof(str_2), "\n\n{FF6347}Вы были кикнуты за подозрение в читерстве\n\
		Чтобы избежать подобных ситуаций в будущем\n\
		удалите все клео и другие модификации для игры.\n\n\
		{FFFFFF}Аккаунт: %s\n\
		Код причины: %s(%i / 1)\n\
		NetStat: %i(%.2f%%)\n\n\
		Для выхода из игры используйте /q(uit)\n\
		В распозновании был применён XXL Guard", PN(playerid), ac_code_name[code], code+100, GetPlayerPing(playerid), NetStats_PacketLossPercent(playerid));
		str_1[0] = EOS, f(str_1, sizeof(str_1), "%02i:%02i %02i.%02i.%i", hour, minute, day, month, year);
		SPD(playerid, 0, 0, str_1, str_2, !"X", !"");
		Kick(playerid);
	}
	|
|
end
*/
new
	player_VehicleID[MAX_PLAYERS] = {-1, ...},
	vehicle_DriveID[MAX_VEHICLES] = {-1, ...},
	player_DamagerTrigger[MAX_PLAYERS char],
	Float:player_PositionFromZ[MAX_PLAYERS],
	bool:is_acPlayerReturn[MAX_PLAYERS],
	player_LastSpeedinVehicle[MAX_PLAYERS],
	player_WarningSpeedinVehicle[MAX_PLAYERS],
	player_SetVehiclePos_tick[MAX_PLAYERS],
	player_SetVehicleVelocity[MAX_PLAYERS],
	bool:nopSetVehiclePos[MAX_PLAYERS],
	nopSetVehiclePos_tick[MAX_PLAYERS],
	Float:nopSetVehiclePos_Sync[MAX_PLAYERS][3],
	player_CountRequestPervSecond[MAX_PLAYERS],
	player_floodCallableCount[MAX_PLAYERS][sizeof(ac_tick_callback)],
	player_floodCallableTick[MAX_PLAYERS][sizeof(ac_tick_callback)],
	player_Name[MAX_PLAYERS][24],
	player_IP[MAX_PLAYERS][17],
	bool:player_IsDebugSync[MAX_PLAYERS],
	bool:player_acKick[MAX_PLAYERS char],
	bool:player_acAntiFlood[MAX_PLAYERS char],
	acStatus[sizeof(ac_code_name)] = {2, ...},
	acCountTrigger[sizeof(ac_code_name)],
	player_Weapon[MAX_PLAYERS][13],
	player_Ammo[MAX_PLAYERS][13],
	tick_SetPlayerWeapon[MAX_PLAYERS],
	count_SetPlayerWeapon[MAX_PLAYERS],
	player_IsAFKCount[MAX_PLAYERS],
	player_LastVehicleSpeed[MAX_PLAYERS],
	//
	bool:nopResetPlayerWeapons[MAX_PLAYERS],
	nopResetPlayerWeapons_tick[MAX_PLAYERS],
//	Float:aimPlayer_origin[MAX_PLAYERS][3],
	player_LastTakeDamageID[MAX_PLAYERS] = {INVALID_PLAYER_ID, ...},
	player_LastTickDamage[MAX_PLAYERS],
	bool:nopSetPlayerPos[MAX_PLAYERS],
	player_SetPosition[MAX_PLAYERS] = {-1, ...},
	nopSetPlayerPos_tick[MAX_PLAYERS],
	Float:nopSetPlayerPos_Sync[MAX_PLAYERS][3],
	//bool:nopRemovePlayerFromVehicle[MAX_PLAYERS],
	//nopRemovePlayerFromVehicle_tick[MAX_PLAYERS],
	//
	Float:player_PositionDelay[MAX_PLAYERS][3],
	Float:player_PositionUnoccupied[MAX_PLAYERS][3],
	Float:player_PositionSync[MAX_PLAYERS][3],
	fmop_warning[MAX_PLAYERS char],
	airbreak_warning[MAX_PLAYERS char],
	fastwalk_warning[MAX_PLAYERS char],
	player_acUpdate[MAX_PLAYERS] = {-1, ...},
	player_acAnim[MAX_PLAYERS],
	bool:player_isSurfingAuto[MAX_PLAYERS], //я знаю чо char можно но мне пох
	player_acAnimFlag[MAX_PLAYERS],
	player_acTickOnFoot[MAX_PLAYERS],
	str_1[4096],
	player_IsLogged[MAX_PLAYERS char];
#define f 								format
#define SCM 							SendClientMessage
#define SCMf(%0,%1,%2,%3)                           str_1[0] = EOS, f(str_1, sizeof(str_1), %2, %3) && SendClientMessage(%0,%1,str_1)
//
stock GetPlayerVehicleSpeed(playerid)
{
    if(!IsPlayerInAnyVehicle(playerid)) return 1;
    new Float:X, Float:Y, Float:Z;
	GetVehicleVelocity(GetPlayerVehicleID(playerid),X,Y,Z);
	return floatround( floatsqroot( X * X + Y * Y + Z * Z ) * 190.0 );
}
stock GetPlayerSpeed(playerid)
{
    new Float:ST[4];
    if(IsPlayerInAnyVehicle(playerid))GetVehicleVelocity(GetPlayerVehicleID(playerid),ST[0],ST[1],ST[2]);
    else GetPlayerVelocity(playerid,ST[0],ST[1],ST[2]);
    ST[3] = floatsqroot(floatpower(floatabs(ST[0]), 2.0) + floatpower(floatabs(ST[1]), 2.0) + floatpower(floatabs(ST[2]), 2.0)) * 150.0;
    return floatround(ST[3]);
}
const timer_ac_tick = 700;
public OnFilterScriptInit(){
	ac_LoadConfig();
	MapAndreas_Init(MAP_ANDREAS_MODE_MINIMAL);
	return 1;
}
public OnFilterScriptExit()
{
    print("\n----------------[XXL GUARD]----------------------");
	for(new i; i < MAX_PLAYERS; i++)
	{
		if(i < sizeof(ac_code_name)) printf("%s >- detect %i, status %i", ac_code_name[i], acCountTrigger[i], acStatus[i]);
		ac_ResetPlayerStats(i);
	}
    print("--------------------------------------\n");
    return 1;
}
stock ac_ResetPlayerStats(playerid)
{
	for(new i; i < sizeof(ac_tick_callback); i++)
	{
		player_floodCallableTick[playerid][i] = 0;
		player_floodCallableCount[playerid][i] = 0;
	}
	for(new i; i < 13; i++)
	{
		if(i < 3)
		{
			nopSetPlayerPos_Sync[playerid][i] = 0.0;
			player_PositionDelay[playerid][i] = 0.0;
			player_PositionUnoccupied[playerid][i] = 0.0;
			player_PositionSync[playerid][i] = 0.0;
			nopSetVehiclePos_Sync[playerid][i] = 0.0;
		}
		if(!i)
		{
			is_acPlayerReturn[playerid] = false;
			player_PositionFromZ[playerid] = 0.0;
			player_DamagerTrigger{playerid} = 0;
			player_VehicleID[playerid] = -1;
			player_SetVehiclePos_tick[playerid] = GetTickCount();
			nopSetVehiclePos_tick[playerid] = GetTickCount();
			player_SetVehicleVelocity[playerid] = GetTickCount();
			nopSetVehiclePos[playerid] = false;
			player_IsDebugSync[playerid] = false;
			player_acKick{playerid} = false;
			player_acAntiFlood{playerid} = false;
			tick_SetPlayerWeapon[playerid] = GetTickCount();
			count_SetPlayerWeapon[playerid] = 0;
			player_LastSpeedinVehicle[playerid] = 0;
			player_WarningSpeedinVehicle[playerid] = 0;
			player_IsAFKCount[playerid] = 0;
			player_CountRequestPervSecond[playerid] = 0;
			player_LastVehicleSpeed[playerid] = 0;
			nopResetPlayerWeapons[playerid] = false;
			nopResetPlayerWeapons_tick[playerid] = GetTickCount();
			player_LastTakeDamageID[playerid] = INVALID_PLAYER_ID;
			player_LastTickDamage[playerid] = GetTickCount();
			nopSetPlayerPos[playerid] = false;
			nopSetPlayerPos_tick[playerid] = GetTickCount();

			fmop_warning{playerid} = 0;
			airbreak_warning{playerid} = 0;
			fastwalk_warning{playerid} = 0;
			player_acAnim[playerid] = 0;
			player_isSurfingAuto[playerid] = false;
			player_acAnimFlag[playerid] = 0;
			player_acTickOnFoot[playerid] = GetTickCount();
			player_IsLogged{playerid} = 0;
			if(player_acUpdate[playerid] != -1) KillTimer(player_acUpdate[playerid]), player_acUpdate[playerid] = -1;
			if(player_SetPosition[playerid] != -1) KillTimer(player_SetPosition[playerid]), player_SetPosition[playerid] = -1;
		}
		player_Weapon[playerid][i] = 0;
		player_Ammo[playerid][i] = 0;
	}
}
public OnPlayerConnect(playerid)
{
	GetPlayerName(playerid, player_Name[playerid], 24);
	GetPlayerIp(playerid, player_IP[playerid], 17);
	ac_ResetPlayerStats(playerid);
	player_acUpdate[playerid] = SetTimerEx("acUpdatePlayer", timer_ac_tick, 1, "i", playerid);
	player_IsLogged{playerid} = 0;
	return 1;
}
public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	switch(dialogid)
	{
		case 8788:
		{
			if(!response) return 0;
			if(acStatus[listitem] > 1) acStatus[listitem] = 0;
			else acStatus[listitem]++;
			callcmd::xxl_settings(playerid);
			ac_SaveConfig();
			return 0;
		}
	}
	return 1;
}
public OnPlayerDisconnect(playerid, reason)
{
	ac_ResetPlayerStats(playerid);
	player_acKick{playerid} = true;
	player_acTickOnFoot{playerid} = 0;
	player_IsLogged{playerid} = 0;
	return 1;
}
public OnPlayerDeath(playerid, killerid, reason)
{
	return 1;
}
stock CheckFloodCallback(playerid, id)
{
	if(GetTickCount()-player_floodCallableTick[playerid][id] < ac_tick_callback[id][0])
	{
		player_floodCallableCount[playerid][id]++;
		if(player_floodCallableCount[playerid][id] > ac_tick_callback[id][1]) 
		{
			printf("xxl guard debug -> %s[%i], count packets only 1 sec %i, id rpc flood %i, code 10", \
					player_Name[playerid], playerid, NetStats_MessagesRecvPerSecond(playerid), id);
			CallOnPlayerAC(playerid, 10);
		}
	}
	player_floodCallableTick[playerid][id] = GetTickCount();
	return 1;
}
public: acUpdatePlayer(playerid)
{
	player_IsAFKCount[playerid]++;
	if(player_IsAFKCount[playerid] < 5) //isafk ? true
	{
		//if(playerid == 1) printf("%i", player_CountRequestPervSecond[playerid]);
		//SCMf(playerid, -1, "%i", NetStats_MessagesRecvPerSecond(playerid)-player_CountRequestPervSecond[playerid]);
		for(new i; i < sizeof(ac_tick_callback); i++)
		{
			if(player_floodCallableCount[playerid][i] > 0) player_floodCallableCount[playerid][i]--;
		}
		if(player_acAntiFlood[playerid] != false) player_acAntiFlood{playerid} = false;
		if(nopSetVehiclePos[playerid] != false)
		{
			if(nopSetVehiclePos_tick[playerid] - GetTickCount() > 0)
			{
				new Float:dist = DistancePointToPoint(player_PositionSync[playerid][0], player_PositionSync[playerid][1], player_PositionSync[playerid][2], nopSetVehiclePos_Sync[playerid][0], nopSetVehiclePos_Sync[playerid][1], nopSetVehiclePos_Sync[playerid][2]);
				//SCMf(playerid, -1, "%f++", dist);
				if(dist > 300)
				{
					nopSetVehiclePos[playerid] = false;
					if(nopSetVehiclePos_Sync[playerid][0] != 0.0)
					{
						printf("xxl guard debug -> %s[%i], %f dist [new: %f %f %f] [old: %f %f %f], code 12", \
							player_Name[playerid], playerid, dist,\
							player_PositionSync[playerid][0], player_PositionSync[playerid][1], player_PositionSync[playerid][2], nopSetVehiclePos_Sync[playerid][0], nopSetVehiclePos_Sync[playerid][1], nopSetVehiclePos_Sync[playerid][2]);
						CallOnPlayerAC(playerid, 12);
					}
				}
			}
			else nopSetVehiclePos[playerid] = false;
		}
		if(nopResetPlayerWeapons[playerid] != false)
		{
			if(nopResetPlayerWeapons_tick[playerid] - GetTickCount() > 0)
			{
				nopResetPlayerWeapons[playerid] = false;
				for(new i; i < 13; i++)
				{
					new weaponid, amount;
					GetPlayerWeaponData(playerid, i, weaponid, amount);
					if(weaponid == 46) continue;
					if(weaponid != 0 && amount != 0) CallOnPlayerAC(playerid, 7); //nop
				}
			}
		}
		if(tick_SetPlayerWeapon[playerid] - GetTickCount() < 0)
		{
			//SCMf(playerid, -1, "%i", GetPlayerWeapon(playerid));
			for(new i; i < 13; i++)
			{
				new weaponid, amount;
				GetPlayerWeaponData(playerid, i, weaponid, amount);
				if(ac_IsPlayerHaveWeapon(playerid, weaponid) == -1) 
				{
					count_SetPlayerWeapon[playerid] += 2;
					if(weaponid == 46) continue;
					if(count_SetPlayerWeapon[playerid] > 2) CallOnPlayerAC(playerid, 6);
				}
			}
			if(count_SetPlayerWeapon[playerid] > 0) count_SetPlayerWeapon[playerid]--;
		}
		new Float:ppos[4];
		for(new i; i < 3; i++) ppos[i] = player_PositionSync[playerid][i];
		//ppos[2] = sync & ppos[3] = real
		MapAndreas_FindZ_For2DCoord(ppos[0], ppos[1], ppos[3]);
		player_PositionFromZ[playerid] = ppos[2]-ppos[3];
		switch(GetPlayerState(playerid))
		{
			case PLAYER_STATE_ONFOOT:
			{
				//player_acTickOnFoot[playerid] = GetTickCount()+GetPlayerPing(playerid)+3000;
				if(player_acTickOnFoot[playerid] - GetTickCount() < 0)
				{
					if(player_LastSpeedinVehicle[playerid] != 0) player_LastSpeedinVehicle[playerid] = 0;
					if(nopSetPlayerPos[playerid] != false)
					{
						if(nopSetPlayerPos_tick[playerid] - GetTickCount() > 0)
						{
							new Float:dist = DistancePointToPoint(player_PositionSync[playerid][0], player_PositionSync[playerid][1], player_PositionSync[playerid][2], nopSetPlayerPos_Sync[playerid][0], nopSetPlayerPos_Sync[playerid][1], nopSetPlayerPos_Sync[playerid][2]);
							if(dist > 300)
							{
								nopSetPlayerPos[playerid] = false;
								if(nopSetPlayerPos_Sync[playerid][0] != 0.0)
								{
									printf("xxl guard debug -> %s[%i], %f dist [new: %f %f %f] [old: %f %f %f], code 9", \
										player_Name[playerid], playerid, dist,\
										player_PositionSync[playerid][0], player_PositionSync[playerid][1], player_PositionSync[playerid][2], nopSetPlayerPos_Sync[playerid][0], nopSetPlayerPos_Sync[playerid][1], nopSetPlayerPos_Sync[playerid][2]);
									CallOnPlayerAC(playerid, 9);
								}
							}
						}
						else nopSetPlayerPos[playerid] = false;
					}
					if(!GetPlayerVirtualWorld(playerid) && !GetPlayerInterior(playerid) && player_PositionDelay[playerid][0] != 0.0)
					{
						//airbreak or click warp or teleport
						if(GetPlayerSpeed(playerid) < 1000)
						{
							new Float:dist = DistancePointToPoint(player_PositionSync[playerid][0], player_PositionSync[playerid][1], player_PositionSync[playerid][2], player_PositionDelay[playerid][0], player_PositionDelay[playerid][1], player_PositionDelay[playerid][2]);
							//SCMf(playerid, -1, "%f dist onfoot & %i speed", dist, GetPlayerSpeed(playerid));
							if(dist > 250)
							{
								printf("xxl guard debug -> %s[%i], %f dist [new: %f %f %f] [old: %f %f %f], code 5", \
										player_Name[playerid], playerid, dist,\
										player_PositionSync[playerid][0], player_PositionSync[playerid][1], player_PositionSync[playerid][2], player_PositionDelay[playerid][0], player_PositionDelay[playerid][1], player_PositionDelay[playerid][2]);
								CallOnPlayerAC(playerid, 5);
							}
							//SCMf(playerid, -1, "%f %f %i", player_PositionFromZ[playerid], dist, airbreak_warning{playerid});
							if(dist > 30)
							{
								if(airbreak_warning{playerid} > 2)
								{
									if(player_PositionFromZ[playerid] > 4 || player_PositionFromZ[playerid] < -4)
									{
										printf("xxl guard debug -> %s[%i], %f dist [new: %f %f %f] [old: %f %f %f], code 4", \
												player_Name[playerid], playerid, dist,\
												player_PositionSync[playerid][0], player_PositionSync[playerid][1], player_PositionSync[playerid][2], player_PositionDelay[playerid][0], player_PositionDelay[playerid][1], player_PositionDelay[playerid][2]);
										CallOnPlayerAC(playerid, 4);
										airbreak_warning{playerid} = 0;
									}
									else if(airbreak_warning{playerid} > 0) airbreak_warning{playerid}--;
								}
								airbreak_warning{playerid}++;
								for(new i; i < 3; i++) 
								{
									player_PositionSync[playerid][i] = player_PositionDelay[playerid][i];
									player_PositionDelay[playerid][i] = player_PositionSync[playerid][i];
								}
							}
							else if(airbreak_warning{playerid} > 0) airbreak_warning{playerid}--;
						
							if(GetPlayerSpeed(playerid) > 45 && dist > 35 && player_isSurfingAuto[playerid] != true)
							{
								if(fastwalk_warning{playerid} > 1)
								{
									if((player_PositionFromZ[playerid]) < 7)
									{
										printf("xxl guard debug -> %s[%i], %f dist & %i speed [new: %f %f %f] [old: %f %f %f], code 14", \
												player_Name[playerid], playerid, dist, GetPlayerSpeed(playerid),\
												player_PositionSync[playerid][0], player_PositionSync[playerid][1], player_PositionSync[playerid][2], player_PositionDelay[playerid][0], player_PositionDelay[playerid][1], player_PositionDelay[playerid][2]);
										CallOnPlayerAC(playerid, 14);
										fastwalk_warning{playerid} = 0;
									}
									else fastwalk_warning{playerid}--;
								}
								fastwalk_warning{playerid}++;
							}
							else if(fastwalk_warning{playerid} > 0) fastwalk_warning{playerid}--;
						}
						//fly hack
						if(player_PositionSync[playerid][2] > 1)
						{
							if(GetPlayerSpeed(playerid) > 20 && GetPlayerSpeed(playerid) < 50)
							{
								//SCMf(playerid, -1, "sync %f & real %f & speed %i", ppos[2], ppos[3], GetPlayerSpeed(playerid));
								if(ppos[3]+7 < ppos[2])
								{
									if(player_PositionDelay[playerid][2]-1 < player_PositionSync[playerid][2])
									{
										if(fmop_warning{playerid} > 3) CallOnPlayerAC(playerid, 3);
										fmop_warning{playerid}+=2;
									}
								}
								else if(fmop_warning{playerid} > 0) fmop_warning{playerid}--;
							}
						}
					}
				}
			}
			case PLAYER_STATE_DRIVER:
			{
				if(player_PositionDelay[playerid][0] != 0.0)
				{
					if(nopSetPlayerPos[playerid] != false) nopSetPlayerPos[playerid] = false;
					if(player_SetVehiclePos_tick[playerid] - GetTickCount() < 0)
					{
						nopSetVehiclePos[playerid] = false;
						new Float:dist = DistancePointToPoint(player_PositionSync[playerid][0], player_PositionSync[playerid][1], player_PositionSync[playerid][2], player_PositionDelay[playerid][0], player_PositionDelay[playerid][1], player_PositionDelay[playerid][2]);
						//SCMf(playerid, -1, "%f dist", dist);
						if(dist > 500) 
						{
							printf("xxl guard debug -> %s[%i], %f dist [new: %f %f %f] [old: %f %f %f], code 12", \
									player_Name[playerid], playerid, dist,\
									player_PositionSync[playerid][0], player_PositionSync[playerid][1], player_PositionSync[playerid][2], player_PositionDelay[playerid][0], player_PositionDelay[playerid][1], player_PositionDelay[playerid][2]);
							CallOnPlayerAC(playerid, 12);
						}
					}
				}
				new diff = GetPlayerVehicleSpeed(playerid)-player_LastSpeedinVehicle[playerid];
				if(player_SetVehicleVelocity[playerid] - GetTickCount() < 0)
				{
					if(player_PositionFromZ[playerid] < 30)
					{
						new model = GetVehicleModel(GetPlayerVehicleID(playerid));
						//SCM(playerid, -1,"++");
						if(model < 612)
						{
							new diff_model = GetModelMaxSpeed(model);
							//SCMf(playerid, -1, "%i/%i & diff %i", (GetPlayerVehicleSpeed(playerid)), diff_model, diff)
							if(GetPlayerVehicleSpeed(playerid) > diff_model+40)
							{
								printf("xxl guard debug -> %s[%i], [new: %f %f %f] [old: %f %f %f] [diff model %i & %i/%i], code 13", \
										player_Name[playerid], playerid,\
										player_PositionSync[playerid][0], player_PositionSync[playerid][1], player_PositionSync[playerid][2], player_PositionDelay[playerid][0], player_PositionDelay[playerid][1], player_PositionDelay[playerid][2],\
										diff_model, player_LastSpeedinVehicle[playerid], GetPlayerVehicleSpeed(playerid));

								CallOnPlayerAC(playerid, 13);
								player_WarningSpeedinVehicle[playerid] = 0;
							}
							new max_diff;
							switch(model)
							{
								case 430, 446, 452, 453, 454, 472, 473, 484, 493, 417, 425, 447, 460, 469, 476, 487, 488, 497, 511, 512, 513, 519, 520, 548, 553,\
								563, 577, 592, 593, 441,464,465,501,564, 581, 522, 461, 521, 523, 463, 468, 471, 586: max_diff = 42;
								case 509, 481, 510: max_diff = 35;
								case 462,448: max_diff = 26;
								default: max_diff = 40;
							}
							if(diff > max_diff)
							{
								//SCMf(playerid, -1, "%f %i", player_PositionFromZ[playerid], diff);
								if(player_WarningSpeedinVehicle[playerid] > 7)
								{
									printf("xxl guard debug -> %s[%i], [new: %f %f %f] [old: %f %f %f] [diff %i/%i], code 13", \
											player_Name[playerid], playerid,\
											player_PositionSync[playerid][0], player_PositionSync[playerid][1], player_PositionSync[playerid][2], player_PositionDelay[playerid][0], player_PositionDelay[playerid][1], player_PositionDelay[playerid][2],\
											player_LastSpeedinVehicle[playerid], GetPlayerVehicleSpeed(playerid));

									CallOnPlayerAC(playerid, 13);
									player_WarningSpeedinVehicle[playerid] = 0;
								}
								else player_WarningSpeedinVehicle[playerid]+=2;
							}
							else if(player_WarningSpeedinVehicle[playerid] > 0) player_WarningSpeedinVehicle[playerid]--;
						}
						else
						{
							if(diff > 80)
							{
								printf("xxl guard debug -> %s[%i], %f dist [new: %f %f %f] [old: %f %f %f] [diff %i/%i] > 60, code 13", \
										player_Name[playerid], playerid,\
										player_PositionSync[playerid][0], player_PositionSync[playerid][1], player_PositionSync[playerid][2], player_PositionDelay[playerid][0], player_PositionDelay[playerid][1], player_PositionDelay[playerid][2],\
										player_LastSpeedinVehicle[playerid], GetPlayerVehicleSpeed(playerid));

								CallOnPlayerAC(playerid, 13);
								player_WarningSpeedinVehicle[playerid] = 0;
							}
						}
					}
				}
				if(diff > 150)
				{
					printf("xxl guard debug -> %s[%i], %f dist [new: %f %f %f] [old: %f %f %f] [diff %i/%i] > 150, code 13", \
							player_Name[playerid], playerid,\
							player_PositionSync[playerid][0], player_PositionSync[playerid][1], player_PositionSync[playerid][2], player_PositionDelay[playerid][0], player_PositionDelay[playerid][1], player_PositionDelay[playerid][2],\
							player_LastSpeedinVehicle[playerid], GetPlayerVehicleSpeed(playerid));

					CallOnPlayerAC(playerid, 13);
					player_WarningSpeedinVehicle[playerid] = 0;
				}
				player_LastSpeedinVehicle[playerid] = GetPlayerVehicleSpeed(playerid);
			}
			case PLAYER_STATE_PASSENGER:
			{

			}
		}
	}
	else
	{
		//afk
		for(new i; i < 3; i++) player_PositionSync[playerid][i] = player_PositionDelay[playerid][i];
		if(player_acTickOnFoot[playerid] - GetTickCount() > 0) player_acTickOnFoot[playerid] += timer_ac_tick+100;
		if(player_SetVehicleVelocity[playerid] - GetTickCount() < 0) player_SetVehicleVelocity[playerid] += timer_ac_tick+100;
		if(nopSetVehiclePos_tick[playerid] - GetTickCount() < 0) nopSetVehiclePos_tick[playerid] += timer_ac_tick+100;
		if(player_SetVehiclePos_tick[playerid] - GetTickCount() > 0) player_SetVehiclePos_tick[playerid] += timer_ac_tick+100;
		if(nopSetPlayerPos_tick[playerid] - GetTickCount() > 0) nopSetPlayerPos_tick[playerid] += timer_ac_tick+100;
		if(tick_SetPlayerWeapon[playerid] - GetTickCount() < 0) tick_SetPlayerWeapon[playerid] += timer_ac_tick+100;
		if(nopResetPlayerWeapons_tick[playerid] - GetTickCount() > 0) nopResetPlayerWeapons_tick[playerid] += timer_ac_tick+100;
	}
	for(new i; i < 3; i++) player_PositionDelay[playerid][i] = player_PositionSync[playerid][i];
	return 1;
}
public OnIncomingConnection(playerid,ip_address[],port)
{
	/*if(GetString(ip_address, Flood_ip[playerid]))
	{
		if(GetTickCount() - Flood_time[playerid] < 1000) BlockIpAddress(ip_address,5*1000);
	}
	Flood_time[playerid] = GetTickCount();*/
	return 1;
}
stock GetString(const param1[], const param2[]) return !strcmp(param1, param2, false);
public OnPlayerUpdate(playerid)
{
	player_IsAFKCount[playerid] = 0;
	static Float:ppos[3];
	GetPlayerPos(playerid, ppos[0], ppos[1], ppos[2]);
	for(new i; i < 3; i++) player_PositionSync[playerid][i] = ppos[i];
	if((NetStats_MessagesRecvPerSecond(playerid)-player_CountRequestPervSecond[playerid]) > 100 || NetStats_MessagesRecvPerSecond(playerid) > 300) 
	{
		printf("xxl guard debug -> %s[%i], count only request %i and old %i, code 11", \
				player_Name[playerid], playerid, NetStats_MessagesRecvPerSecond(playerid), player_CountRequestPervSecond[playerid]);
		CallOnPlayerAC(playerid, 11);
	}
	player_CountRequestPervSecond[playerid] = NetStats_MessagesRecvPerSecond(playerid);
	return 1;
}
stock ac_IsValidFloat(Float:value) return (value == value && value != Float:0x7F800000 && value != Float:0xFF800000);
stock CallOnPlayerAC(playerid, code)
{
	//if(is_acPlayerReturn[playerid] != false) return 0;
	new type = acStatus[code];
	if(!type) return 0;
	//ac anti flood
	if(player_acAntiFlood[playerid] != false) return 0;
	player_acAntiFlood{playerid} = true;

	//is player kick?
	if(player_acKick{playerid} != false) return 0;
	if(type == 2) player_acKick{playerid} = true;

	/*
		type
		0 off
		1 warning
		2 kick
	*/
	acCountTrigger[code]++;
	printf("[xxl guard detect] %i playerid | code %i | type %i [request]", playerid, code, type);
	new request = CallRemoteFunction("OnCheatDetected", "iii", playerid, code, type);
	if(request == -1 && !code)
	{
		player_IsLogged{playerid} = 2;
		player_acKick{playerid} = false;
	}
	else if(request == -2) is_acPlayerReturn[playerid] = true;
	return 1;
}
public OnIncomingPacket(playerid, packetid, BitStream:bs)
{
	/*if(!Iter_Contains(Player, playerid)) 
	{
		printf("playerid %i packetid %i", playerid, packetid);
		return 1;
	}*/
	if(player_acKick{playerid} != false) return 0;
	switch(packetid)
	{
		case 207: //onfoot
		{
			if(!IsPlayerLogged(playerid)) return CallOnPlayerAC(playerid, 0);
			new onFootData[PR_OnFootSync];
			BS_IgnoreBits(bs, 8);
			BS_ReadOnFootSync(bs, onFootData);
			/*if(playerid == 0)
			{
				//printf("xxl guard debug info ->\
				//		playerid onfoot %i ==> [position: x %f y %f z %f] [quaternion %f %f %f %f] [SA %i]",\
				//		playerid, onFootData[PR_position][0], onFootData[PR_position][1], onFootData[PR_position][2],\
				//		onFootData[PR_quaternion][0], onFootData[PR_quaternion][1], onFootData[PR_quaternion][2], onFootData[PR_quaternion][3],\
				//		onFootData[PR_specialAction]);
				SCMf(playerid, -1, "xxl guard debug info 2 ->\
						playerid onfoot %i ==> [velocity: x %f y %f z %f] [animationId %i] [animationFlags %i]",\
						playerid, onFootData[PR_velocity][0], onFootData[PR_velocity][1], onFootData[PR_velocity][2],\
						onFootData[PR_animationId], onFootData[PR_animationFlags]);
			}*/
			new bool:recoil;
			//
			if(onFootData[PR_specialAction] == SPECIAL_ACTION_NONE && \
				(onFootData[PR_quaternion][0] * onFootData[PR_quaternion][0]) - (onFootData[PR_quaternion][1] * onFootData[PR_quaternion][1]) -
				(onFootData[PR_quaternion][2] * onFootData[PR_quaternion][2]) + (onFootData[PR_quaternion][3] * onFootData[PR_quaternion][3]) > 70.0)
			{
				printf("xxl guard -> playerid(%i), code(onfoot0Za)", playerid);
				recoil = true;
			}
			else if(!ac_IsValidFloat(onFootData[PR_surfingOffsets][0]) ||
				!ac_IsValidFloat(onFootData[PR_surfingOffsets][1]) ||
				!ac_IsValidFloat(onFootData[PR_surfingOffsets][2]))
			{
				onFootData[PR_surfingOffsets][0] =
				onFootData[PR_surfingOffsets][1] =
				onFootData[PR_surfingOffsets][2] = 0.0;
				onFootData[PR_surfingVehicleId] = 0;
				BS_SetWriteOffset(bs, 8);
				BS_WriteOnFootSync(bs, onFootData);
				recoil = true;
			}
			else if(onFootData[PR_surfingVehicleId] != 0 &&
				onFootData[PR_surfingOffsets][0] == 0.0 && onFootData[PR_surfingOffsets][1] == 0.0 &&
				onFootData[PR_surfingOffsets][2] == 0.0)
			{
				onFootData[PR_surfingVehicleId] = 0;
				BS_SetWriteOffset(bs, 8);
				BS_WriteOnFootSync(bs, onFootData);
				recoil = true;
			}

			//fmop fix
			player_acAnim[playerid] = onFootData[PR_animationId];
			player_acAnimFlag[playerid] = onFootData[PR_animationFlags];
			if(onFootData[PR_surfingVehicleId]) player_isSurfingAuto[playerid] = true;
			else player_isSurfingAuto[playerid] = false;

			if((onFootData[PR_velocity][0] > 0.3 && onFootData[PR_velocity][0] < -0.3) ||
				(onFootData[PR_velocity][1] > 0.3 && onFootData[PR_velocity][1] < -0.3))
			{
				if(!onFootData[PR_surfingVehicleId] && player_PositionFromZ[playerid] < 10) recoil = true;
			}
			if((onFootData[PR_velocity][2] >= 0.13 || onFootData[PR_velocity][2] <= -0.13) && player_PositionFromZ[playerid] < 10) recoil = true;
			else if(GetPlayerSpeed(playerid) > 250) recoil = true;

			if(recoil != false)
			{
				onFootData[PR_velocity][0] =
				onFootData[PR_velocity][1] =
				onFootData[PR_velocity][2] = 0.0;
				BS_SetWriteOffset(bs, 8);
				BS_WriteOnFootSync(bs, onFootData);
				printf("xxl guard -> playerid(%i), code(onfoota)z", playerid);
				return 0;
			}
			/*
				StreamInfo[][10+10] = {
	{"репорта"}, 0
	{"админ-чата"}, 1
	{"админ-действий"}, 2
	{"новых подключений"}, 3
	{"убийств"}, 4
	{"IP адресов"} 5
};
			//rvanka for arz
			//printf("%i %f %f %f", GetPlayerSpeed(playerid), onFootData[PR_velocity][0], onFootData[PR_velocity][1], onFootData[PR_velocity][2]);
			{
				new count_warning;
				for(new i; i < 3; i++)
				{
					if((player_PositionDelay[playerid][i]+1.1 >= player_PositionUnoccupied[playerid][i] &&
					player_PositionDelay[playerid][i] <= player_PositionUnoccupied[playerid][i]+1.1) || 
					(player_PositionDelay[playerid][i]-1.1 >= player_PositionUnoccupied[playerid][i] &&
					player_PositionDelay[playerid][i] <= player_PositionUnoccupied[playerid][i]-1.1)) count_warning++;
				}
				if(count_warning == 3)
				{
					recoil = true;
					CallOnPlayerAC(playerid, 2);
				}
			}*/
		}
		case 200: //drive
		{
			if(!IsPlayerLogged(playerid)) return CallOnPlayerAC(playerid, 0);
			new onVehicleData[PR_InCarSync];
			BS_IgnoreBits(bs, 8);
			BS_ReadInCarSync(bs, onVehicleData);
			if(!ac_IsValidFloat(onVehicleData[PR_quaternion][0]) || !ac_IsValidFloat(onVehicleData[PR_quaternion][1]) ||
				!ac_IsValidFloat(onVehicleData[PR_quaternion][2]) || !ac_IsValidFloat(onVehicleData[PR_quaternion][3])) return 0;
			//if(player_IsDebugSync[playerid] != false)
			//{
			//if(playerid == 1)
		//	{
			//	printf("xxl guard debug info ->\
			//			%i playerid & vehicleid %i ==> [position: x %f y %f z %f] [quaternion %f %f %f %f] [trailer speed %f]",\
			//			playerid, onVehicleData[PR_vehicleId], onVehicleData[PR_position][0], onVehicleData[PR_position][1], onVehicleData[PR_position][2],\
			//			onVehicleData[PR_quaternion][0], onVehicleData[PR_quaternion][1], onVehicleData[PR_quaternion][2], onVehicleData[PR_quaternion][3],\
			//			onVehicleData[PR_trainSpeed]);
			//SCMf(playerid, -1, "xxl guard debug info 2 ->\
			//		%i playerid & vehicleid %i ==> [velocity: x %f y %f z %f] [old speed %i & new speed %i]",\
			//		playerid, onVehicleData[PR_vehicleId], onVehicleData[PR_velocity][0], onVehicleData[PR_velocity][1], onVehicleData[PR_velocity][2], player_LastSpeedinVehicle[playerid], GetPlayerVehicleSpeed(playerid));
			//}

			new bool:recoil;

			if(GetPlayerVehicleSpeed(playerid) > 350) recoil = true, printf("xxl guard -> playerid(%i), code(DASCZXada;DZz)", playerid);
			else if(player_PositionFromZ[playerid] < 15)
			{
				recoil = true;
				if(onVehicleData[PR_velocity][2] >= 0.4 || onVehicleData[PR_velocity][2] <= -0.4) 
				{
					printf("xxl guard -> playerid(%i), code(inVehicle > 0.4 z and Z normal)", playerid);
				}
				else if((onVehicleData[PR_velocity][0] >= 0.18 && onVehicleData[PR_velocity][0] <= -0.18) ||
					(onVehicleData[PR_velocity][1] >= 0.18 && onVehicleData[PR_velocity][1] <= -0.18))
				{
					printf("xxl guard -> playerid(%i), code(inVehicle > 0.18 xy and Z normal)", playerid);
				}
				else if(player_LastSpeedinVehicle[playerid] == GetPlayerVehicleSpeed(playerid) && 
					(onVehicleData[PR_quaternion][0] == 1.0 || onVehicleData[PR_quaternion][0] == 0.0) &&
					(onVehicleData[PR_quaternion][1] == 1.0 || onVehicleData[PR_quaternion][1] == 0.0) &&
					(onVehicleData[PR_quaternion][2] == 1.0 || onVehicleData[PR_quaternion][2] == 0.0) &&
					(onVehicleData[PR_quaternion][3] == 1.0 || onVehicleData[PR_quaternion][3] == 0.0)) printf("xxl guard -> playerid(%i), code(dfasa;DZzDZX)", playerid);
				else recoil = false;
			}

			if(recoil != false)
			{
				for(new i; i < 4; i++)
				{
					if(i == 3) onVehicleData[PR_quaternion][i] = 0.0;
					else
					{
						onVehicleData[PR_velocity][i] = 0.0;
						onVehicleData[PR_quaternion][i] = 0.0;
					}
				}
				BS_SetWriteOffset(bs, 8); 
				BS_WriteInCarSync(bs, onVehicleData);
				printf("xxl guard -> playerid(%i), code(vehioczDz)", playerid);
				return 0;
			}
		}
		case 209: //out
		{
			if(!IsPlayerLogged(playerid)) return CallOnPlayerAC(playerid, 0);
			new onVehicleData[PR_UnoccupiedSync];
			BS_IgnoreBits(bs, 8);
			BS_ReadUnoccupiedSync(bs, onVehicleData);
			/*new str[144];
			format(str, sizeof(str), "onfoot(car) (PR_roll %f %f %f) (PR_direction %f %f %f) (PR_position %f %f %f)",\
            onVehicleData[PR_roll][0], onVehicleData[PR_roll][1], onVehicleData[PR_roll][2],\
            onVehicleData[PR_direction][0],onVehicleData[PR_direction][1],onVehicleData[PR_direction][2],\
            onVehicleData[PR_position][0],onVehicleData[PR_position][1],onVehicleData[PR_position][2]);
			SendClientMessage(playerid, -1, str);*/
			//printf("velocity %f %f %f | velocity 2 %f %f %f",onVehicleData[PR_velocity][0],onVehicleData[PR_velocity][1], onVehicleData[PR_velocity][2],\
			//onVehicleData[PR_angularVelocity][0],onVehicleData[PR_angularVelocity][1], onVehicleData[PR_angularVelocity][2]);
			if((onVehicleData[PR_velocity][0] > 0.18 && onVehicleData[PR_velocity][0] < -0.18) ||
				(onVehicleData[PR_velocity][1] > 0.18 && onVehicleData[PR_velocity][1] < -0.18))
			{

				for(new i; i < 3; i++) 
				{
					onVehicleData[PR_velocity][i] = 0.0;
					onVehicleData[PR_angularVelocity][i] = 0.0;
				}
				BS_SetWriteOffset(bs, 8); 
				BS_WriteUnoccupiedSync(bs, onVehicleData);
				printf("xxl guard -> playerid(%i), code(high speed unoccupiedsync)", playerid);
				return 0;
			}
			for(new i; i < 3; i++) player_PositionUnoccupied[playerid][i] = onVehicleData[PR_position][i];
		}
		case 211:
		{
			if(!IsPlayerLogged(playerid)) return CallOnPlayerAC(playerid, 0);
			new onVehicleData[PR_PassengerSync];
			BS_IgnoreBits(bs, 8);
			BS_ReadPassengerSync(bs, onVehicleData);
			if(onVehicleData[PR_seatId] < 1 || !(1 <= onVehicleData[PR_vehicleId] < MAX_VEHICLES))
			{
				printf("xxl guard -> playerid(%i), code(seat id invalid)", playerid);
				return 0;
			}
			//UpdatePlayerPosition(playerid, ac_pData[PR_position]);
			if(!(vehicle_DriveID[ onVehicleData[PR_vehicleId] ] > 0)) //в машине нету водителя
			{

			}
			//SCMf(playerid, -1, "%i %i %i", onVehicleData[PR_driveBy], onVehicleData[PR_seatId], GetPlayerVehicleSpeed(playerid));
		}
	}
	return 1;
}
stock CheckFloat(Float:data)
{
	if(floatcmp(data, data) != 0 || floatcmp(data, 0x7F800000) == 0 || floatcmp(data, 0xFF800000) == 0) return 1;
	return 0;
}
IPacket:209(playerid, BitStream:bs)
{
	new UNOCCUPIED[PR_UnoccupiedSync];
	BS_ReadUint8(bs, 8);
	BS_ReadUnoccupiedSync(bs, UNOCCUPIED);
	if(!(-1.0 <= UNOCCUPIED[PR_roll][0] <= 1.00000)
	|| !(-1.0 <= UNOCCUPIED[PR_roll][1] <= 1.00000)
	|| !(-1.0 <= UNOCCUPIED[PR_direction][0] <= 1.00000)
	|| !(-1.0 <= UNOCCUPIED[PR_roll][2] <= 1.00000)
	|| !(-1.0 <= UNOCCUPIED[PR_direction][1] <= 1.00000)
	|| !(-1.0 <= UNOCCUPIED[PR_direction][2] <= 1.00000)
	|| !(-20000.0 <= UNOCCUPIED[PR_position][0] <= 20000.00000)
	|| !(-20000.0 <= UNOCCUPIED[PR_position][1] <= 20000.00000)
	|| !(-20000.0 <= UNOCCUPIED[PR_position][2] <= 20000.00000)
	|| !(-1.00000 <= UNOCCUPIED[PR_angularVelocity][0] <= 1.00000)
	|| !(-1.00000 <= UNOCCUPIED[PR_angularVelocity][1] <= 1.00000)
	|| !(-1.00000 <= UNOCCUPIED[PR_angularVelocity][2] <= 1.00000)
	|| !(-100.00000 <= UNOCCUPIED[PR_velocity][0] <= 100.00000)
	|| !(-100.00000 <= UNOCCUPIED[PR_velocity][1] <= 100.00000)
	|| !(-100.00000 <= UNOCCUPIED[PR_velocity][2] <= 100.00000)) return 0;
	return 1;
}
IRPC:136(playerid, BitStream:bs)
{
	new vehicleid;
	BS_ReadValue(bs, PR_UINT16, vehicleid);
	if(vehicleid == 0) return 0;
	return 1;
}
ORPC:12(playerid, BitStream:bs) //setplayerpos
{
	//printf("xxl guard request orpc -> 12 %f %f %f [old state]", nopSetPlayerPos_Sync[playerid][0], nopSetPlayerPos_Sync[playerid][1], nopSetPlayerPos_Sync[playerid][2]);
	if(player_SetPosition[playerid] == -1)
	{
		BS_ReadValue(bs,\
					PR_FLOAT, nopSetPlayerPos_Sync[playerid][0],\
					PR_FLOAT, nopSetPlayerPos_Sync[playerid][1],\
					PR_FLOAT, nopSetPlayerPos_Sync[playerid][2]);
		//printf("xxl guard request orpc -> 12 %f %f %f [new state]", nopSetPlayerPos_Sync[playerid][0], nopSetPlayerPos_Sync[playerid][1], nopSetPlayerPos_Sync[playerid][2]);
		player_SetPosition[playerid] = SetTimerEx("acUpdatePosition", GetPlayerDelay(playerid), 0, "i", playerid);
		return 0;
	}
	UpdatePlayerPosition(playerid, nopSetPlayerPos_Sync[playerid]);
	nopSetPlayerPos_tick[playerid] = GetTickCount()+GetPlayerPing(playerid)+3000;
	player_acTickOnFoot[playerid] = GetTickCount()+GetPlayerPing(playerid)+2000;
	player_SetPosition[playerid] = -1;
	nopSetPlayerPos[playerid] = true;
	return 1;
}
ORPC:13(playerid, BitStream:bs) //setplayerposz
{
	if(player_SetPosition[playerid] == -1)
	{
		//printf("xxl guard request orpc -> 13 %f %f %f [old state]", nopSetPlayerPos_Sync[playerid][0], nopSetPlayerPos_Sync[playerid][1], nopSetPlayerPos_Sync[playerid][2]);
		BS_ReadValue(bs,\
					PR_FLOAT, nopSetPlayerPos_Sync[playerid][0],\
					PR_FLOAT, nopSetPlayerPos_Sync[playerid][1],\
					PR_FLOAT, nopSetPlayerPos_Sync[playerid][2]);
		//printf("xxl guard request orpc -> 13 %f %f %f [new state]", nopSetPlayerPos_Sync[playerid][0], nopSetPlayerPos_Sync[playerid][1], nopSetPlayerPos_Sync[playerid][2]);
		player_SetPosition[playerid] = SetTimerEx("acUpdatePosition", GetPlayerDelay(playerid), 0, "i", playerid);
		return 0;
	}
	UpdatePlayerPosition(playerid, nopSetPlayerPos_Sync[playerid]);
	nopSetPlayerPos_tick[playerid] = GetTickCount()+GetPlayerPing(playerid)+3000;
	player_acTickOnFoot[playerid] = GetTickCount()+GetPlayerPing(playerid)+2000;
	player_SetPosition[playerid] = -1;
	nopSetPlayerPos[playerid] = true;
	return 1;
}
ORPC:68(playerid, BitStream:bs) //setspawninfo
{
	//printf("xxl guard request orpc -> 68 %f %f %f [old state]", nopSetPlayerPos_Sync[playerid][0], nopSetPlayerPos_Sync[playerid][1], nopSetPlayerPos_Sync[playerid][2]);
	static var;
	BS_ReadValue(bs,\
				PR_UINT8, var,
				PR_UINT32, var,
				PR_UINT8, var,
				PR_FLOAT, nopSetPlayerPos_Sync[playerid][0],\
				PR_FLOAT, nopSetPlayerPos_Sync[playerid][1],\
				PR_FLOAT, nopSetPlayerPos_Sync[playerid][2]);
	//printf("xxl guard request orpc -> 68 %f %f %f [new state]", nopSetPlayerPos_Sync[playerid][0], nopSetPlayerPos_Sync[playerid][1], nopSetPlayerPos_Sync[playerid][2]);
	UpdatePlayerPosition(playerid, nopSetPlayerPos_Sync[playerid]);
	nopSetPlayerPos_tick[playerid] = GetTickCount()+GetPlayerPing(playerid)+3000;
	player_acTickOnFoot[playerid] = GetTickCount()+GetPlayerPing(playerid)+2000;
	nopSetPlayerPos[playerid] = true;
	return 1;
}
ORPC:128(playerid, BitStream:bs) //requestclass
{
	//printf("xxl guard request orpc -> 128 %f %f %f [old state]", nopSetPlayerPos_Sync[playerid][0], nopSetPlayerPos_Sync[playerid][1], nopSetPlayerPos_Sync[playerid][2]);
	static var;
	BS_ReadValue(bs,\
				PR_UINT8, var,
				PR_UINT8, var,
				PR_UINT32, var,
				PR_UINT8, var,
				PR_FLOAT, nopSetPlayerPos_Sync[playerid][0],\
				PR_FLOAT, nopSetPlayerPos_Sync[playerid][1],\
				PR_FLOAT, nopSetPlayerPos_Sync[playerid][2]);
	//printf("xxl guard request orpc -> 128 %f %f %f [new state]", nopSetPlayerPos_Sync[playerid][0], nopSetPlayerPos_Sync[playerid][1], nopSetPlayerPos_Sync[playerid][2]);
	UpdatePlayerPosition(playerid, nopSetPlayerPos_Sync[playerid]);
	nopSetPlayerPos_tick[playerid] = GetTickCount()+GetPlayerPing(playerid)+3000;
	player_acTickOnFoot[playerid] = GetTickCount()+GetPlayerPing(playerid)+2000;
	nopSetPlayerPos[playerid] = true;
	return 1;
}
ORPC:124(playerid, BitStream:bs) //change spectating
{
	player_acTickOnFoot[playerid] = GetTickCount()+GetPlayerPing(playerid)+2000;
	new spectating;
	BS_ReadValue(bs, PR_UINT32,spectating);
	if(player_IsLogged{playerid} != 2)
	{
		if(spectating == 1 && !player_IsLogged{playerid}) player_IsLogged{playerid} = 1;
		else if(spectating == 0 && player_IsLogged{playerid} == 1) player_IsLogged{playerid} = 2;
	}
	return 1; 
}
stock IsPlayerLogged(playerid)
{
	if(playerid > MAX_PLAYERS || playerid < 0) return 0;
	if(player_IsLogged{playerid} == 2) return 1;
	return 0;
}
IPacket:212(playerid, BitStream:bs) //spectate packet
{
	new spectatingData[PR_SpectatingSync];
	BS_IgnoreBits(bs, 8);
	BS_ReadSpectatingSync(bs, spectatingData);
	for(new x; x < 3; x++) if(CheckFloat(spectatingData[PR_position][x]) || floatabs(spectatingData[PR_position][x]) > 20000.0) return 0;
	return 1;
}
const ID_AIM_SYNC = 203; //ID пакета
IPacket:ID_AIM_SYNC(playerid, BitStream:bs)
{
	new AIMSYNC[PR_AimSync];

	BS_IgnoreBits(bs, 8); //Игнорируем биты
	BS_ReadAimSync(bs, AIMSYNC);//Считываем информацию
	if(GetPlayerWeapon(playerid) == 40 && AIMSYNC[PR_camMode] != 4) return 0;
	if(!(0 <= AIMSYNC[PR_camMode] <= 65))
	{
		printf("xxl guard -> playerid(%i), code(x10301ZDz)", playerid);
		return 0;
	}
	else
	{
		switch(AIMSYNC[PR_camMode])
		{
			case 0..2, 5, 6, 9..13, 17, 19..21, 23..28, 30..45, 48..50, 52, 54, 60, 61, 65: 
			{
				printf("xxl guard -> playerid(%i), code(x10301ZD)", playerid);
				return 0;
			}
		}
	}
	if(!ac_IsValidFloat(AIMSYNC[PR_aimZ]))
	{
		AIMSYNC[PR_aimZ] = 0.0;
		BS_SetWriteOffset(bs, 8);
		BS_WriteAimSync(bs, AIMSYNC);
	}
  	//Выполняем проверку
 	if(AIMSYNC[PR_camFrontVec][0] != AIMSYNC[PR_camFrontVec][0] || floatcmp(floatabs(AIMSYNC[PR_camFrontVec][0]), 1.0000) == 1
		|| AIMSYNC[PR_camFrontVec][1] != AIMSYNC[PR_camFrontVec][1] || floatcmp(floatabs(AIMSYNC[PR_camFrontVec][1]), 1.0000) == 1
		|| AIMSYNC[PR_camFrontVec][2] != AIMSYNC[PR_camFrontVec][2] || floatcmp(floatabs(AIMSYNC[PR_camFrontVec][2]), 1.0000) == 1
		|| AIMSYNC[PR_camPos][0] != AIMSYNC[PR_camPos][0] || floatcmp(floatabs(AIMSYNC[PR_camPos][0]), 3500.0000) == 1
		|| AIMSYNC[PR_camPos][1] != AIMSYNC[PR_camPos][1] || floatcmp(floatabs(AIMSYNC[PR_camPos][1]), 3500.0000) == 1
		|| AIMSYNC[PR_camPos][2] != AIMSYNC[PR_camPos][2] || floatcmp(floatabs(AIMSYNC[PR_camPos][2]), 3500.0000) == 1)
	{
		printf("xxl guard -> playerid(%i), code(da;DZz)", playerid);
        return 0;
	}
    return 1;
}
public: OnOutgoingPacket(playerid, packetid, BitStream:bs)
{
	if(playerid == -1) return 0;
	//printf("OnOutgoingPacket %i", packetid);
	//if(player_acKick{playerid} != false) return 0;
	return 1;
}
public: OnOutgoingRPC(playerid, rpcid, BitStream:bs)
{
	if(playerid == -1) return 0;
	//printf("OnOutgoingRPC %i", rpcid);
	//if(player_acKick{playerid} != false) return 0;
	switch(rpcid)
	{
		case 159: //setvehiclepos
		{
			player_SetVehiclePos_tick[playerid] = GetTickCount()+GetPlayerPing(playerid)+2000;
			nopSetPlayerPos[playerid] = false;
			static id;
			BS_ReadValue(bs,
					PR_UINT16, id,\
					PR_FLOAT, nopSetVehiclePos_Sync[playerid][0],\
					PR_FLOAT, nopSetVehiclePos_Sync[playerid][1],\
					PR_FLOAT, nopSetVehiclePos_Sync[playerid][2]);
			//printf("dodozzz %f %f %f", nopSetVehiclePos_Sync[playerid][0], nopSetVehiclePos_Sync[playerid][1], nopSetVehiclePos_Sync[playerid][2]);
			nopSetVehiclePos_tick[playerid] += GetTickCount()+GetPlayerPing(playerid)+2000;
			nopSetVehiclePos[playerid] = true;
			UpdatePlayerPosition(playerid, nopSetVehiclePos_Sync[playerid]);
		}
		case 91: //setvehiclevelocity
		{
			player_SetVehicleVelocity[playerid] = GetTickCount()+GetPlayerPing(playerid)+2200;
		}
	}
	return 1;
}
public: OnIncomingInternalPacket(playerid, packetid, BitStream:bs)
{
	//printf("OnIncomingInternalPacket %i", packetid);
	return 1;
}
public: OnOutgoingInternalPacket(playerid, packetid, BitStream:bs)
{
	//printf("OnOutgoingInternalPacket %i", packetid);
	//if(player_acKick{playerid} != false) return 0;
	if(packetid == 32) 
	{
		if(player_acKick{playerid} != false) 
		{
			player_acKick{playerid} = false;
			BlockIpAddress(player_IP[playerid], 2000);
		}
	}
	return 1;
}
public OnIncomingRPC(playerid, rpcid, BitStream:bs)
{
	if(player_acKick{playerid} != false && rpcid != 25) return 0;
	switch(rpcid)
	{
		case 26: CheckFloodCallback(playerid, 0);
		case 154: CheckFloodCallback(playerid, 1);
		case 136: CheckFloodCallback(playerid, 2);
		case 52: CheckFloodCallback(playerid, 3);
		case 53: CheckFloodCallback(playerid, 4);
		case 62: CheckFloodCallback(playerid, 5);
	}
	//else if(rpcid == 101) return 0;
	return 1;
}
IPacket:206(playerid, BitStream:bs)
{
	new ac_bData[PR_BulletSync];
	BS_IgnoreBits(bs, 8);
	BS_ReadBulletSync(bs, ac_bData);
//	if(ac_bData[PR_hitType] != BULLET_HIT_TYPE_NONE && (floatabs(fX) >= 1000.0 || floatabs(fY) >= 1000.0 || floatabs(fZ) >= 1000.0)) { CheatDetected(playerid, AC_CRASH1); return 0; }
	new slot = ac_IsPlayerHaveWeapon(playerid, ac_bData[PR_weaponId]);
	if(slot != -1) 
	{
		player_Ammo[playerid][slot]--;
		if(!player_Ammo[playerid][slot]) player_Ammo[playerid][slot] = 0;
	}
	switch(ac_bData[PR_hitType])
	{
		case BULLET_HIT_TYPE_PLAYER:
		{
			if(ac_bData[PR_hitId] == playerid ||
			floatabs(ac_bData[PR_offsets][0]) > 10.0 ||
			floatabs(ac_bData[PR_offsets][1]) > 10.0 ||
			floatabs(ac_bData[PR_offsets][2]) > 10.0) 
			{
				printf("xxl guard -> playerid(%i), code(da;z)F", playerid);
				return 0;
			}
			/*new count_warning;
			for(new i; i < 3; i++) 
			{
				if(aimPlayer_origin[playerid][i] == ac_bData[PR_origin][i]) count_warning++;
				aimPlayer_origin[playerid][i] = ac_bData[PR_origin][i];
			}
			if(count_warning == 2) 
			{
				printf("xxl guard -> playerid(%i), AIM OR DAMAGER", playerid);
				return 0;
			}*/
		}
		case BULLET_HIT_TYPE_VEHICLE:
		{
			if(floatabs(ac_bData[PR_offsets][0]) > 300.0 ||
			floatabs(ac_bData[PR_offsets][1]) > 300.0 ||
			floatabs(ac_bData[PR_offsets][2]) > 300.0) 
			{
				printf("xxl guard -> playerid(%i), code(da;z)D", playerid);
				return 0;
			}
		}
		case BULLET_HIT_TYPE_OBJECT, BULLET_HIT_TYPE_PLAYER_OBJECT:
		{
			if(floatabs(ac_bData[PR_offsets][0]) > 1000.0 ||
			floatabs(ac_bData[PR_offsets][1]) > 1000.0 ||
			floatabs(ac_bData[PR_offsets][2]) > 1000.0) 
			{
				printf("xxl guard -> playerid(%i), code(da;zA)", playerid);
				return 0;
			}
		}
		default:
		{
			if(floatabs(ac_bData[PR_offsets][0]) > 20000.0 ||
			floatabs(ac_bData[PR_offsets][1]) > 20000.0 ||
			floatabs(ac_bData[PR_offsets][2]) > 20000.0) 
			{
				printf("xxl guard -> playerid(%i), code(da;z)", playerid);
				return 0;
			}
		}
	}
	return 1;
}
ORPC:21(playerid, BitStream:bs) //reset weapons
{
	for(new i; i < 13; i++)
	{
		player_Weapon[playerid][i] = 0;
		player_Ammo[playerid][i] = 0;
	}
	nopResetPlayerWeapons[playerid] = true;
	tick_SetPlayerWeapon[playerid] = GetTickCount()+GetPlayerPing(playerid)+2000;
	nopResetPlayerWeapons_tick[playerid] = GetTickCount()+GetPlayerPing(playerid)+2000;
	return 1;
}
ORPC:22(playerid, BitStream:bs) //add weapon
{
	new weaponid, count;
	BS_ReadValue(bs,\
			PR_UINT32, weaponid,
			PR_UINT32, count);
	if(!ac_SetPlayerWeapon(playerid, weaponid, count)) return 0;
	nopResetPlayerWeapons[playerid] = false;
	return 1;
}
ORPC:145(playerid, BitStream:bs) //set weapon ammo
{
	new weaponid, count;
	BS_ReadValue(bs,\
			PR_UINT8, weaponid,
			PR_UINT16, count);
	if(!ac_SetPlayerWeapon(playerid, weaponid, count)) return 0;
	nopResetPlayerWeapons[playerid] = false;
	return 1;
}
/*ORPC:71(playerid, BitStream:bs) //removeplayerfromvehicle
{
	nopRemovePlayerFromVehicle[playerid] = true,
	nopRemovePlayerFromVehicle_tick[playerid] = GetTickCount()+GetPlayerPing(playerid)+500;
	return 1;
}
IRPC:26(playerid, BitStream:bs) //player enter
{
	nopRemovePlayerFromVehicle[playerid] = false;
	return 1;
}
IRPC:70(playerid, BitStream:bs) //putvehicle
{
	nopRemovePlayerFromVehicle[playerid] = false;
	return 1;
}*/
//system damage
stock default_tick_shot(weaponid)
{
	new TIME_SHOT;
	switch(weaponid)
	{
		case 0..8, 10..15: 		TIME_SHOT = 170;
		case 9: 				TIME_SHOT = 30;
		case 19..20:			TIME_SHOT = 20;
		case 22:				TIME_SHOT = 160;
		case 23..24:			TIME_SHOT = 120;
		case 25:				TIME_SHOT = 700;
		case 26..27:			TIME_SHOT = 120;
		case 28:				TIME_SHOT = 50;
		case 29..31:			TIME_SHOT = 60;
		case 32:				TIME_SHOT = 50;
		case 33..34:			TIME_SHOT = 700;
		case 38:				TIME_SHOT = 20;
		case 39..40:			TIME_SHOT = 0;
		case 41..42:			TIME_SHOT = 10;
		case 48:				TIME_SHOT = 400;
		default:			TIME_SHOT = 0;
	}
	return TIME_SHOT;
}
stock ac_IsValidDamageReason(weaponid) return (0 <= weaponid <= 18 || 22 <= weaponid <= 46 || 49 <= weaponid <= 54);
IRPC:115(playerid, BitStream:bs)
{
	new bGiveOrTake, issuerid, Float: amount, weaponid, bodypart;
	BS_ReadValue(bs, PR_BOOL, bGiveOrTake, PR_UINT16, issuerid, PR_FLOAT, amount, PR_UINT32, weaponid, PR_UINT32, bodypart);
	//next
	//playerid наносит урон
	if(!IsPlayerLogged(playerid) || !IsPlayerLogged(issuerid)) return 0;
	if(weaponid < 0 || weaponid >= 38) return 0;
	if(!IsPlayerStreamedIn(playerid, issuerid) || !IsPlayerStreamedIn(issuerid, playerid)) return 0;
	if((amount < 0.0 || issuerid != INVALID_PLAYER_ID && !(0 <= issuerid < MAX_PLAYERS) || !(3 <= bodypart <= 9) || !ac_IsValidDamageReason(weaponid))) return 0;
	if(!bGiveOrTake)
	{
		//SCM(playerid, -1, "playerid ++"); //наносит урон
		//SCM(issuerid, -1, "issuerid ++"); //получает урон
		if(player_LastTakeDamageID[issuerid] == playerid)
		{
			if(!(default_tick_shot(weaponid) < GetTickCount() - player_LastTickDamage[issuerid]))
			{
				if(player_DamagerTrigger{playerid} > 0)
				{
					player_DamagerTrigger{playerid} = 0;

					printf("xxl guard debug -> %s[%i], [weaponid %i & tick %i], code 8", player_Name[playerid], playerid, weaponid, GetTickCount() - player_LastTickDamage[issuerid]);
					CallOnPlayerAC(playerid, 8);
					return 0;
				}
				player_DamagerTrigger{playerid}++;
			}
			else if(player_DamagerTrigger{playerid} > 0) player_DamagerTrigger{playerid}--;
		}
		else if(player_DamagerTrigger{playerid} > 0) player_DamagerTrigger{playerid}--;

		player_LastTakeDamageID[issuerid] = playerid;
		player_LastTickDamage[issuerid] = GetTickCount();
	}
	else return 0;
	return 1;
}
CMD:xxl_settings(playerid)
{
	if(!IsPlayerUnicalDostup(playerid) || !IsPlayerLogged(playerid)) return 0;
	str_1 = "{c0c0c0}Название\t{c0c0c0}Наказание\t{c0c0c0}Сработал\n";
	for(new i; i < sizeof(ac_code_name); i++)
	{
		static str_local[17];
		str_local[0] = EOS;
		switch(acStatus[i])
		{
			case 0: str_local = "{a45052}Отключен";
			case 1: str_local = "{cbb796}Сообщать";
			case 2: str_local = "{c87349}Кикнуть";
		}
		f(str_1, sizeof(str_1), "%s{FFFFFF}[%i] %s\t%s\t{cbb796}[на %i игроков]\n", str_1, 100+i, ac_code_name[i], str_local, acCountTrigger[i]);
	}
	ShowPlayerDialog(playerid, 8788, DIALOG_STYLE_TABLIST_HEADERS, !"xxl guard settings", str_1, !"Выбор", !"Отмена");
	return 1;
}
CMD:debug_targetid(playerid, get[])
{
	if(!IsPlayerConnected(playerid) || !IsPlayerUnicalDostup(playerid)) return 0;
	extract get -> new player:id; else return SCM(playerid, -1, !"id");
	player_IsDebugSync[id] = !player_IsDebugSync[id];
	SCMf(playerid, -1, "debug from %i -> status %s", id, player_IsDebugSync[id] != false ? "on" : "off");
	return 1;
}
CMD:detect_ac(playerid, get[])
{
	if(!IsPlayerConnected(playerid) || !IsPlayerUnicalDostup(playerid)) return 0;
	extract get -> new player:id, code; else return SCM(playerid, -1, !"id player + code");
	CallOnPlayerAC(id, code);
	return 1;
}
stock ac_IsPlayerHaveWeapon(playerid, gunid)
{
	for(new i; i < 13; i++) if(player_Weapon[playerid][i] == gunid) return i;
	return -1;
}
stock ac_SetPlayerWeapon(playerid, gunid, count)
{
	if(!gunid) return 1;
	if(count > 10000) count = 9000;
	new slot = GetWeaponSlot(gunid);
	if(slot == -1) return 1;
	if(player_Weapon[playerid][slot] == gunid) player_Ammo[playerid][slot] += count;
	else
	{
		if(count < 0) count = 0;
		player_Ammo[playerid][slot] = count;
		player_Weapon[playerid][slot] = gunid;
	}
	tick_SetPlayerWeapon[playerid] = GetTickCount()+GetPlayerPing(playerid)+2000;
	return 1;
}
stock GetWeaponSlot(weaponid)
{
    switch(weaponid)
    {
        case 1: return 0;
        case 2..9: return 1;
        case 22..24: return 2;
        case 25..27: return 3;
        case 28, 29, 32: return 4;
        case 30, 31: return 5;
        case 33, 34: return 6;
        case 35..38: return 7;
        case 16..18, 39: return 8;
        case 41..43: return 9;
        case 10..15: return 10;
        case 44..46: return 11;
        case 40: return 12;
    }
    return -1;
}
stock ac_LoadConfig()
{
	new uid = ini_openFile("ac_config.ini");
	if(uid >= 0)
	{
		for(new i; i < sizeof(ac_code_name); i++)
		{
			str_1[0] = EOS, f(str_1, sizeof(str_1), "code%i", i);
			ini_getInteger(uid, str_1, acStatus[i]);
		}
	}
	else print("xxl guard load -> error");
	ini_closeFile(uid);
	return 1;
}
stock ac_SaveConfig()
{
	new uid = ini_openFile("ac_config.ini");
	if(uid >= 0)
	{
		for(new i; i < sizeof(ac_code_name); i++)
		{
			str_1[0] = EOS, f(str_1, sizeof(str_1), "code%i", i);
			ini_setInteger(uid, str_1, acStatus[i]);
		}
		ini_closeFile(uid);
	}
	else print("xxl guard save -> error");
	return 1;
}
stock IsPlayerUnicalDostup(playerid)
{
	for(new i; i < sizeof UnicalDostup; i++) if(GetString(player_Name[playerid], UnicalDostup[i])) return 1;
	return 0;
}
stock UpdatePlayerPosition(playerid, const Float:info_position[])
{
	for(new i; i < 3; i++) 
	{
		nopSetPlayerPos_Sync[playerid][i] = info_position[i];
		player_PositionDelay[playerid][i] = info_position[i];
		player_PositionUnoccupied[playerid][i] = info_position[i];
		player_PositionSync[playerid][i] = info_position[i];
		nopSetVehiclePos_Sync[playerid][i] = info_position[i];
	}
	return 1;
}
stock GetModelMaxSpeed(modelid)
{
	if(IsValidVehicleModel(modelid)) return uf_VehicleSpeeds[modelid - 400];
	return 0;
}
stock IsValidVehicleModel(const modelid) return (399 < modelid < 612);
stock DistancePointToPoint(Float: x, Float: y, Float: z, Float: fx, Float:fy, Float: fz) return floatround(floatsqroot(floatpower(fx - x, 2) + floatpower(fy - y, 2) + floatpower(fz - z, 2)));
public: acUpdatePosition(playerid)
{
	//printf("%f %f %f", nopSetPlayerPos_Sync[playerid][0], nopSetPlayerPos_Sync[playerid][1], nopSetPlayerPos_Sync[playerid][2]);
	SetPlayerPos(playerid, nopSetPlayerPos_Sync[playerid][0], nopSetPlayerPos_Sync[playerid][1], nopSetPlayerPos_Sync[playerid][2]);
	return 1;
}
stock GetPlayerDelay(playerid)
{
	new count = GetPlayerPing(playerid);
	if(count > 500) count = 500;
	else if(count < 120) count = 120;
	return count;
}
public OnPlayerStateChange(playerid, newstate, oldstate)
{
	if(newstate == 2) 
	{
		player_VehicleID[playerid] = GetPlayerVehicleID(playerid);
		if(player_VehicleID[playerid] > 0) vehicle_DriveID[ player_VehicleID[playerid] ] = playerid;
		else player_VehicleID[playerid] = -1;
	}
	else if(oldstate == 2) 
	{
		if(player_VehicleID[playerid] > 0) vehicle_DriveID[ player_VehicleID[playerid] ] = -1;
	}
	return 1;
}
