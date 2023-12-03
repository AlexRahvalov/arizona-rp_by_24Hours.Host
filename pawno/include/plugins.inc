#tryinclude										fixtd
#include 										bcrypt

/*--------[Launcher]--------*/
native SetLauncherStatus(playerid, bool:status);
native GetLauncherStatus(playerid);
/*--------[Interface]--------*/
enum
{
	Arz_Speedometer, /*Спидометр | 0 - выключен, 1 - первый тип, 2 - второй тип*/
	Arz_Hud, /*Худ | 0 - выключен, 1 - первый тип, 2 - второй тип*/
	Arz_Radar, /*Радар | 0 - выключен, 1 - первый тип, 2 - второй тип*/
	Arz_Fuel, /*Бензин*/
	Arz_Hunger, /*Голод*/
	Arz_Hints, /*Подсказки | 0 - показано, 1 - скрыто (Не работает)*/
	Arz_TransparentChat, /*Прозрачный чат | 0 - выключен, 1 - включен*/
	Arz_SaveDialog, /*Сохранение диалога | 0 - выключен, 1 - включен*/
	Arz_NewNametag, /*Новый нэймтег | 0 - выключен, 1 - включен*/
	Arz_Snow, /*Снег | 0 - выключен, 1 - включен*/
	Arz_RenderDialog /*Рендер диалогов  | 0 - полная, 1 - упрощенный, 2 - простой*/
};
native Interface_Arizona(playerid, interface_id, type);

native SetVehicleVelocity(vehicleid, Float:X, Float:Y, Float:Z);

/*//#tryinclude 									profiler
//disable ysf

//
new player_weapon_id[MAX_PLAYERS][13],
    player_weapon_ammo[MAX_PLAYERS][13],
    player_weapon_tick[MAX_PLAYERS];
static const GetWeaponSlot[] = {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 10, 10, 10, 10, 10,10, 8, 8, 8, 0, 0, 0, 2, 2, 2, 3, 3, 3, 4, 4, 5, 5, 4, 6, 6, 7, 7, 7, 7, 8, 12, 9, 9, 9, 11, 11, 11};
stock GivePlayerGun(playerid, weaponid, ammo)
{
	new slot = GetWeaponSlot[weaponid];
	switch(weaponid)
	{
        case 0..15,40,46: player_weapon_ammo[playerid][slot] = 1;
	    default: player_weapon_ammo[playerid][slot] += ammo;
	}
	new weap = player_weapon_id[playerid][slot];
	player_weapon_id[playerid][slot] = weaponid;
	if (weap != weaponid)
	{
		player_weapon_ammo[playerid][slot] = ammo;
		GivePlayerWeapon(playerid,weaponid,ammo);
		SetPlayerAmmo(playerid,weaponid,ammo);
	}
    else GivePlayerWeapon(playerid,weaponid,ammo);
    player_weapon_tick[playerid] = GetTickCount() + 2850;
    return 1;
}
#if defined _ALS_GivePlayerWeapon
	#undef GivePlayerWeapon
#else
	#define _ALS_GivePlayerWeapon
#endif
#define GivePlayerWeapon GivePlayerGun
stock GetWeapon(playerid,x)
{
	if(player_weapon_id[playerid][x] > 0 && player_weapon_ammo[playerid][x] > 0) return 1;
	return 0;
}

stock ClearWeaponSlot(playerid,slot)
{
    if(!GetWeapon(playerid,slot)) ClearSlot(playerid,slot);
	return 1;
}
stock ClearSlot(playerid,slot)
{
    player_weapon_ammo[playerid][slot] = 0;
	player_weapon_id[playerid][slot] = 0;
    Set_Weapon(playerid);
	return SetPlayerArmedWeapon(playerid,0);
}
stock GetWeaponClear(playerid)
{
	for(new x; x < 13; x++) ClearWeaponSlot(playerid,x);
	Set_Weapon(playerid);
    player_weapon_tick[playerid] = GetTickCount() + 2850;
	return 1;
}
stock Set_Weapon(playerid)
{
	ResetPlayerWeapons(playerid);
	new ammo[13],weaponid[13];
	for(new i; i < 13; i++)
	{
		if(GetWeapon(playerid,i))
		{
		    weaponid[i] = player_weapon_id[playerid][i];
	     	ammo[i] =  player_weapon_ammo[playerid][i];
	     	player_weapon_ammo[playerid][i] = 0;
	    	player_weapon_id[playerid][i] = 0;
			GivePlayerWeaponEx(playerid,  weaponid[x], ammo[i]);
		}
	}
	return 1;
}
stock ResetGun(playerid)
{
    ResetPlayerWeapons(playerid);
	for(new i; i < 13; i++) player_weapon_id[playerid][i] = player_weapon_ammo[playerid][i] = 0;
	player_weapon_tick[playerid] = GetTickCount() + 2850;
	return 1;
}
#if defined _ALS_ResetPlayerWeapons
	#undef ResetPlayerWeapons
#else
	#define _ALS_ResetPlayerWeapons
#endif

#define ResetPlayerWeapons ResetGun*/
