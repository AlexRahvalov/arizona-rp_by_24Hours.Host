#if defined _fixobject_included
	#endinput
#endif
#define _fixobject_included

stock ffo_SetObjectMaterial(objectid, materialindex, modelid, txdname[], texturename[], materialcolor = 0) return SetObjectMaterial(objectid, materialindex, modelid, txdname, texturename, materialcolor);
stock ffo_SetPlayerObjectMaterial(playerid, objectid, materialindex, modelid, txdname[], texturename[], materialcolor = 0) return SetPlayerObjectMaterial(playerid, objectid, materialindex, modelid, txdname, texturename, materialcolor);
stock GetDynamicObjectModel(objectid) return Streamer_GetIntData(STREAMER_TYPE_OBJECT, objectid, E_STREAMER_MODEL_ID);
stock fo_CreateDynamicObject(modelid, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz, worldid = -1, interiorid = -1, playerid = -1, Float:streamdistance = 300.0, Float:drawdistance = 300.0, areaid = -1, priority = 0)
{
    if(streamdistance < 100.0) streamdistance = 100.0;
	else if(streamdistance > 600.0) streamdistance = 600.0;
	/*if(x == 0.0 && y == 0.0 && z == 0.0) 
	{
		print(!"Streamer warning: trying to create an object, it was unsuccessful");
		return -1;
	}*/
    return CreateDynamicObject(modelid, x, y, z, rx, ry, rz, worldid, interiorid, playerid, streamdistance, drawdistance, areaid, priority);
}
stock CreateDynamicObject_Fix(modelid, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz, worldid = -1, interiorid = -1, playerid = -1, Float:streamdistance = 300.0, Float:drawdistance = 300.0, areaid = -1, priority = 0)
{
    if(streamdistance < 100.0) streamdistance = 100.0;
	else if(streamdistance > 600.0) streamdistance = 600.0;
	/*if(x == 0.0 && y == 0.0 && z == 0.0) 
	{
		print(!"Streamer warning: trying to create an object, it was unsuccessful");
		return -1;
	}
	new Float:x2,
		Float:y2,
		Float:z2;
	for(new i=end_OBJECT; i < TOTAL_OBJECT+end_OBJECT; i++)
	{
		if(modelid != GetDynamicObjectModel(i)) continue;
		GetDynamicObjectPos(i, x2, y2, z2);
		if(x2 == x && y2 == y && z2 == z) 
		{
			delete_OBJECT++;
			return -1;
		}
	}
	TOTAL_OBJECT += 2;
	if(delete_OBJECT > 1) printf("Streamer warning: trying to create an object, it was unsuccessful, count %i", delete_OBJECT);
    new id = CreateDynamicObject(modelid, x, y, z, rx, ry, rz, worldid, interiorid, playerid, streamdistance, drawdistance, areaid, priority);
	if(!end_OBJECT) end_OBJECT = id;*/
	return CreateDynamicObject(modelid, x, y, z, rx, ry, rz, worldid, interiorid, playerid, streamdistance, drawdistance, areaid, priority);
}
#if defined _ALS_CreateDynamicObject
	#undef CreateDynamicObject
#else
	#define _ALS_CreateDynamicObject
#endif
#define CreateDynamicObject fo_CreateDynamicObject

stock fo_CreateDynamicObjectEx(modelid, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz, Float:streamdistance = 300.0, Float:drawdistance = 300.0, worlds[] = { -1 }, interiors[] = { -1 }, players[] = { -1 }, areas[] = { -1 }, priority = 0, maxworlds = sizeof worlds, maxinteriors = sizeof interiors, maxplayers = sizeof players, maxareas = sizeof areas)
{
    if(streamdistance < 100.0) streamdistance = 100.0;
	else if(streamdistance > 600.0) streamdistance = 600.0;
	return CreateDynamicObjectEx(modelid, x, y, z, rx, ry, rz, streamdistance, drawdistance, worlds, interiors, players, areas, priority, maxworlds, maxinteriors, maxplayers, maxareas);
}
#if defined _ALS_CreateDynamicObjectEx
	#undef CreateDynamicObjectEx
#else
	#define _ALS_CreateDynamicObjectEx
#endif
#define CreateDynamicObjectEx fo_CreateDynamicObjectEx
stock fo_DestroyObject(objectid) return DestroyDynamicObject(objectid);
#if defined _ALS_DestroyObject
	#undef DestroyObject
#else
	#define _ALS_DestroyObject
#endif
#define DestroyObject fo_DestroyObject

stock fo_SetObjectMaterialText(objectid, text[], materialindex = 0, materialsize = OBJECT_MATERIAL_SIZE_256x128, fontface[] = "Arial", fontsize = 24, bold = 1, fontcolor = 0xFFFFFFFF, backcolor = 0, textalignment = 0) return SetDynamicObjectMaterialText(objectid, materialindex, text, materialsize, fontface, fontsize, bold, fontcolor, backcolor, textalignment);
#if defined _ALS_SetObjectMaterialText
	#undef SetObjectMaterialText
#else
	#define _ALS_SetObjectMaterialText
#endif
#define SetObjectMaterialText fo_SetObjectMaterialText

stock fo_GetObjectModel(objectid) return Streamer_GetIntData(STREAMER_TYPE_OBJECT, objectid, E_STREAMER_MODEL_ID);
#if defined _ALS_GetObjectModel
	#undef GetObjectModel
#else
	#define _ALS_GetObjectModel
#endif
#define GetObjectModel fo_GetObjectModel

#if defined _ALS_AttachObjectToVehicle
	#undef AttachObjectToVehicle
#else
	#define _ALS_AttachObjectToVehicle
#endif
#define AttachObjectToVehicle AttachDynamicObjectToVehicle

#if defined _ALS_AttachObjectToObject
	#undef AttachObjectToObject
#else
	#define _ALS_AttachObjectToObject
#endif
#define AttachObjectToObject AttachDynamicObjectToObject

#if defined _ALS_AttachObjectToPlayer
	#undef AttachObjectToPlayer
#else
	#define _ALS_AttachObjectToPlayer
#endif
#define AttachObjectToPlayer AttachDynamicObjectToPlayer

#if defined _ALS_SetObjectPos
	#undef SetObjectPos
#else
	#define _ALS_SetObjectPos
#endif
#define SetObjectPos SetDynamicObjectPos

#if defined _ALS_GetObjectPos
	#undef GetObjectPos
#else
	#define _ALS_GetObjectPos
#endif
#define GetObjectPos GetDynamicObjectPos

#if defined _ALS_SetObjectRot
	#undef SetObjectRot
#else
	#define _ALS_SetObjectRot
#endif
#define SetObjectRot SetDynamicObjectRot

#if defined _ALS_GetObjectRot
	#undef GetObjectRot
#else
	#define _ALS_GetObjectRot
#endif
#define GetObjectRot GetDynamicObjectRot

#if defined _ALS_SetObjectNoCameraCol
	#undef SetObjectNoCameraCol
#else
	#define _ALS_SetObjectNoCameraCol
#endif
#define SetObjectNoCameraCol SetDynamicObjectNoCameraCol

#if defined _ALS_IsValidObject
	#undef IsValidObject
#else
	#define _ALS_IsValidObject
#endif
#define IsValidObject IsValidDynamicObject

#if defined _ALS_MoveObject
	#undef MoveObject
#else
	#define _ALS_MoveObject
#endif
#define MoveObject MoveDynamicObject

#if defined _ALS_StopObject
	#undef StopObject
#else
	#define _ALS_StopObject
#endif
#define StopObject StopDynamicObject

#if defined _ALS_IsObjectMoving
	#undef IsObjectMoving
#else
	#define _ALS_IsObjectMoving
#endif
#define IsObjectMoving IsDynamicObjectMoving

#if defined _ALS_EditObject
	#undef EditObject
#else
	#define _ALS_EditObject
#endif
#define EditObject EditDynamicObject

#if defined _ALS_SetObjectMaterial
	#undef SetObjectMaterial
#else
	#define _ALS_SetObjectMaterial
#endif
#define SetObjectMaterial SetDynamicObjectMaterial

public OnDynamicObjectMoved(objectid)
{
	#if defined fo_OnObjectMoved
	    fo_OnObjectMoved(objectid);
	#endif
	#if defined fo_OnDynamicObjectMoved
	    fo_OnDynamicObjectMoved(objectid);
	#endif
	return 1;
}
#if defined _ALS_OnObjectMoved
	#undef OnObjectMoved
#else
	#define _ALS_OnObjectMoved
#endif
#if defined _ALS_OnDynamicObjectMoved
	#undef OnDynamicObjectMoved
#else
	#define _ALS_OnDynamicObjectMoved
#endif
#if defined fo_OnObjectMoved
	forward fo_OnObjectMoved(objectid);
#endif
#if defined fo_OnDynamicObjectMoved
	forward fo_OnDynamicObjectMoved(objectid);
#endif
#define OnObjectMoved fo_OnObjectMoved
#define OnDynamicObjectMoved fo_OnDynamicObjectMoved
public OnPlayerSelectObject(playerid, type, objectid, modelid, Float:fX, Float:fY, Float:fZ)
{
    #if defined fo_OnPlayerSelectObject
		if(type == 2) fo_OnPlayerSelectObject(playerid, 2, objectid, modelid, fX, fY, fZ);
	#endif
	return 1;
}
public OnPlayerSelectDynamicObject(playerid, objectid, modelid, Float:x, Float:y, Float:z)
{
    #if defined fo_OnPlayerSelectObject
		fo_OnPlayerSelectObject(playerid, 1, objectid, modelid, x, y, z);
	#endif
	#if defined fo_OnPlayerSelectDynamicObj
	    fo_OnPlayerSelectDynamicObj(playerid, objectid, modelid, x, y, z);
	#endif
	return 1;
}
#if defined _ALS_OnPlayerSelectObject
	#undef OnPlayerSelectObject
#else
	#define _ALS_OnPlayerSelectObject
#endif
#if defined _ALS_OnPlayerSelectDynamicObj
	#undef OnPlayerSelectDynamicObj
#else
	#define _ALS_OnPlayerSelectDynamicObj
#endif
#if defined fo_OnPlayerSelectObject
	forward fo_OnPlayerSelectObject(playerid, type, objectid, modelid, Float:fX, Float:fY, Float:fZ);
#endif
#if defined fo_OnPlayerSelectDynamicObj
    forward fo_OnPlayerSelectDynamicObj(playerid, objectid, modelid, Float:x, Float:y, Float:z);
#endif
#define OnPlayerSelectObject fo_OnPlayerSelectObject
#define OnPlayerSelectDynamicObject fo_OnPlayerSelectDynamicObj

public OnGameModeInit()
{
    Streamer_SetVisibleItems(STREAMER_TYPE_OBJECT, 1000);
    #if defined fo_OnGameModeInit
		return fo_OnGameModeInit();
	#else
	    return 1;
	#endif
}
#if defined _ALS_OnGameModeInit
    #undef OnGameModeInit
#else
    #define _ALS_OnGameModeInit
#endif
#if defined fo_OnGameModeInit
	forward fo_OnGameModeInit();
#endif
#define OnGameModeInit fo_OnGameModeInit

public OnFilterScriptInit()
{
    Streamer_SetVisibleItems(STREAMER_TYPE_OBJECT, 1000);
    #if defined fo_OnFilterScriptInit
		return fo_OnFilterScriptInit();
	#else
	    return 1;
	#endif
}
#if defined _ALS_OnFilterScriptInit
	#undef OnFilterScriptInit
#else
	#define _ALS_OnFilterScriptInit
#endif
#if defined fo_OnFilterScriptInit
	forward fo_OnFilterScriptInit();
#endif
#define OnFilterScriptInit fo_OnFilterScriptInit
