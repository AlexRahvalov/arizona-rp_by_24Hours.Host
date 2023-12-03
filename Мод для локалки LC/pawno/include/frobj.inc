#if defined _frobj_included
	#endinput
#endif
#define _frobj_included

static playerNewTimer[MAX_PLAYERS];
static playerDelTimer[MAX_PLAYERS];
static playerSupObject0[MAX_PLAYERS];
static playerSupObject1[MAX_PLAYERS];

static stock SetPlayerPosN(playerid, Float:pos_x, Float:pos_y, Float:pos_z, suppobj, type)
{
    if(!IsPlayerConnected(playerid) || pos_z < 200) return 0;
	if(!suppobj)
	{
	    if(!type) SetPlayerPos(playerid, pos_x, pos_y, pos_z);
		else SetPlayerPosFindZ(playerid, pos_x, pos_y, pos_z);
		return 1;
	}
	TogglePlayerControllable(playerid, 0);
	SetPlayerObjectPos(playerid, playerSupObject0[playerid], pos_x, pos_y, (pos_z - 1.15));
	
	new ping = GetPlayerPing(playerid);
	if(ping > 1000) ping = 1000;
	if(playerDelTimer[playerid]) KillTimer(playerDelTimer[playerid]);
	new ping_custom = (ping * 10) + 1000;
	if(pos_z > 300) ping_custom += 2000;
	playerDelTimer[playerid] = SetTimerEx("fr_NextDel", ping_custom, 0, "ii", playerid, 0);
	
	if(playerNewTimer[playerid]) KillTimer(playerNewTimer[playerid]);
	playerNewTimer[playerid] = SetTimerEx("fr_NextTp", ping_custom, 0, "iifff", playerid, type, pos_x, pos_y, pos_z);
	return 1;
}

forward fr_NextDel(playerid, objmod);
public fr_NextDel(playerid, objmod)
{
    playerDelTimer[playerid] = 0;
    TogglePlayerControllable(playerid, 1);
    
    new Float:pos_x, Float:pos_y, Float:pos_z;
    if(!objmod)
    {
    	GetPlayerObjectPos(playerid, playerSupObject0[playerid], pos_x, pos_y, pos_z);
		SetPlayerObjectPos(playerid, playerSupObject0[playerid], 5000.0, 5000.0, 5000.0);
	}
    else
	{
	    GetPlayerObjectPos(playerid, playerSupObject1[playerid], pos_x, pos_y, pos_z);
		SetPlayerObjectPos(playerid, playerSupObject1[playerid], 5000.0, 5000.0, 5000.0);
	}
	if(pos_x != 5000.0) SetPlayerPos(playerid, pos_x, pos_y, (pos_z + 2.15));
}

forward fr_NextTp(playerid, type, Float:pos_x, Float:pos_y, Float:pos_z);
public fr_NextTp(playerid, type, Float:pos_x, Float:pos_y, Float:pos_z)
{
    playerNewTimer[playerid] = 0;
	if(!type) SetPlayerPos(playerid, pos_x, pos_y, pos_z);
	else SetPlayerPosFindZ(playerid, pos_x, pos_y, pos_z);
}

public OnPlayerConnect(playerid)
{
    playerDelTimer[playerid] = 0;
    playerNewTimer[playerid] = 0;
 	playerSupObject0[playerid] = CreatePlayerObject(playerid, 19374, 5000.0, 5000.0, 5000.0, 0.0, 90.0, 0.0, 20000.0);
	playerSupObject1[playerid] = CreatePlayerObject(playerid, 19374, 5000.0, 5000.0, 5000.0, 0.0, 90.0, 0.0, 20000.0);
	#if defined fr_OnPlayerConnect
		return fr_OnPlayerConnect(playerid);
	#else
		return 1;
    #endif
}
#if defined _ALS_OnPlayerConnect
	#undef OnPlayerConnect
#else
	#define	_ALS_OnPlayerConnect
#endif
#define OnPlayerConnect fr_OnPlayerConnect
#if defined fr_OnPlayerConnect
	forward fr_OnPlayerConnect(playerid);
#endif

public OnPlayerDisconnect(playerid, reason)
{
	if(playerDelTimer[playerid]) KillTimer(playerDelTimer[playerid]);
	if(playerNewTimer[playerid]) KillTimer(playerNewTimer[playerid]);
    #if defined fr_OnPlayerDisconnect
    	return fr_OnPlayerDisconnect(playerid, reason);
	#else
	    return 1;
	#endif
}
#if defined _ALS_OnPlayerDisconnect
	#undef OnPlayerDisconnect
#else
	#define _ALS_OnPlayerDisconnect
#endif
#if defined fr_OnPlayerDisconnect
	forward fr_OnPlayerDisconnect(playerid, reason);
#endif
#define OnPlayerDisconnect fr_OnPlayerDisconnect
stock fr_SetSpawnInfo(playerid, team, skin, Float:pos_x, Float:pos_y, Float:pos_z, Float:pos_a, weap0, ammo0, weap1, ammo1, weap2, ammo2)
{
    if(!IsPlayerConnected(playerid)) return 0;
    SetPlayerObjectPos(playerid, playerSupObject1[playerid], pos_x, pos_y, (pos_z - 1.15));
    return SetSpawnInfo(playerid, team, skin, pos_x, pos_y, pos_z, pos_a, weap0, ammo0, weap1, ammo1, weap2, ammo2);
}
#if defined _ALS_SetSpawnInfo
	#undef SetSpawnInfo
#else
	#define	_ALS_SetSpawnInfo
#endif
#define SetSpawnInfo fr_SetSpawnInfo

stock fr_SetPlayerPos(playerid, Float:pos_x, Float:pos_y, Float:pos_z, suppobj = 1) return SetPlayerPosN(playerid, pos_x, pos_y, pos_z, suppobj, 0);
#if defined _ALS_SetPlayerPos
	#undef SetPlayerPos
#else
	#define	_ALS_SetPlayerPos
#endif
#define SetPlayerPos fr_SetPlayerPos

stock fr_SetPlayerPosFindZ(playerid, Float:pos_x, Float:pos_y, Float:pos_z, suppobj = 1) return SetPlayerPosN(playerid, pos_x, pos_y, pos_z, suppobj, 1);
#if defined _ALS_SetPlayerPosFindZ
	#undef SetPlayerPosFindZ
#else
	#define	_ALS_SetPlayerPosFindZ
#endif
#define SetPlayerPosFindZ fr_SetPlayerPosFindZ
