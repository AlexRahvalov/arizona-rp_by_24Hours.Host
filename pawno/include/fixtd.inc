stock DestroyPlayerTD(playerid, &PlayerText:td, bool:status=false)
{
	if(status && !IsPlayerTextDrawVisible(playerid, td)) return 0;
	if(!IsValidPlayerTextDraw(playerid, td)) return 0;
	if(td != PlayerText:INVALID_TEXT_DRAW)
	{
		PlayerTextDrawDestroy(playerid, td);
		td = PlayerText:INVALID_TEXT_DRAW;
	}
	return 1;
}
//
#define PlayerTextDrawDestroy DestroyPlayerTD
stock IsPlayerTextDrawValid(playerid, &PlayerText:td)
{
    if(!IsValidPlayerTextDraw(playerid, td) || td == PlayerText:INVALID_TEXT_DRAW) return 0;
    return 1;
}

//#define DestroyPlayerTD PlayerTextDrawDestroy
stock PlayerTextDrawColorEx(playerid, &PlayerText:td, color)
{
    if(!IsValidPlayerTextDraw(playerid, td)) return 0;
    if(td != PlayerText:INVALID_TEXT_DRAW) PlayerTextDrawColor(playerid, td, color);
    return 1;
}
#define PlayerTextDrawColor PlayerTextDrawColorEx
stock PlayerTextDrawBoxColorEx(playerid, &PlayerText:td, color)
{
    if(!IsValidPlayerTextDraw(playerid, td)) return 0;
    if(td != PlayerText:INVALID_TEXT_DRAW) PlayerTextDrawBoxColor(playerid, td, color);
    return 1;
}
#define PlayerTextDrawBoxColor PlayerTextDrawBoxColorEx
stock PlayerTextDrawBackgroundColorEx(playerid, &PlayerText:td, color)
{
    if(!IsValidPlayerTextDraw(playerid, td)) return 0;
    if(td != PlayerText:INVALID_TEXT_DRAW) PlayerTextDrawBackgroundColor(playerid, td, color);
    return 1;
}
#define PlayerTextDrawBackgroundColor PlayerTextDrawBackgroundColorEx
stock PlayerTextDrawAlignmentEx(playerid, &PlayerText:td, alignment)
{
    if(!IsValidPlayerTextDraw(playerid, td)) return 0;
    if(td != PlayerText:INVALID_TEXT_DRAW) PlayerTextDrawAlignment(playerid, td, alignment);
    return 1;
}
#define PlayerTextDrawAlignment PlayerTextDrawAlignmentEx
stock PlayerTextDrawFontEx(playerid, &PlayerText:td, font)
{
    if(!IsValidPlayerTextDraw(playerid, td)) return 0;
    if(td != PlayerText:INVALID_TEXT_DRAW) PlayerTextDrawFont(playerid, td, font);
    return 1;
}
#define PlayerTextDrawFont PlayerTextDrawFontEx
stock PlayerTextDrawLetterSizeEx(playerid, &PlayerText:td, Float:x, Float:y)
{
    if(!IsValidPlayerTextDraw(playerid, td)) return 0;
    if(td != PlayerText:INVALID_TEXT_DRAW) PlayerTextDrawLetterSize(playerid, td, Float:x, Float:y);
    return 1;
}
#define PlayerTextDrawLetterSize PlayerTextDrawLetterSizeEx
stock PlayerTextDrawTextSizeEx(playerid, &PlayerText:td, Float:x, Float:y)
{
    if(!IsValidPlayerTextDraw(playerid, td)) return 0;
    if(td != PlayerText:INVALID_TEXT_DRAW) PlayerTextDrawTextSize(playerid, td, Float:x, Float:y);
    return 1;
}
#define PlayerTextDrawTextSize PlayerTextDrawTextSizeEx
stock PlayerTextDrawSetOutlineEx(playerid, &PlayerText:td, size)
{
    if(!IsValidPlayerTextDraw(playerid, td)) return 0;
    if(td != PlayerText:INVALID_TEXT_DRAW) PlayerTextDrawSetOutline(playerid, td, size);
    return 1;
}
stock PlayerTextDrawUseBoxEx(playerid, &PlayerText:td, use)
{
    if(!IsValidPlayerTextDraw(playerid, td)) return 0;
    if(td != PlayerText:INVALID_TEXT_DRAW) PlayerTextDrawUseBox(playerid, td, use);
    return 1;
}
#define PlayerTextDrawUseBox PlayerTextDrawUseBoxEx
stock PlayerTextDrawSetShadowEx(playerid, &PlayerText:td, size)
{
    if(!IsValidPlayerTextDraw(playerid, td)) return 0;
    if(td != PlayerText:INVALID_TEXT_DRAW) PlayerTextDrawSetShadow(playerid, td, size);
    return 1;
}
#define PlayerTextDrawSetShadow PlayerTextDrawSetShadowEx
stock PlayerTextDrawSetProportionalEx(playerid, &PlayerText:td, set)
{
    if(!IsValidPlayerTextDraw(playerid, td)) return 0;
    if(td != PlayerText:INVALID_TEXT_DRAW) PlayerTextDrawSetProportional(playerid, td, set);
    return 1;
}
#define PlayerTextDrawSetProportional PlayerTextDrawSetProportionalEx
stock PlayerTextDrawSetSelectableEx(playerid, &PlayerText:td, set)
{
    if(!IsValidPlayerTextDraw(playerid, td)) return 0;
    if(td != PlayerText:INVALID_TEXT_DRAW) PlayerTextDrawSetSelectable(playerid, td, set);
    return 1;
}
#define PlayerTextDrawSetSelectable PlayerTextDrawSetSelectableEx
stock PlayerTextDrawShowEx(playerid, &PlayerText:td)
{
	if(td == PlayerText:INVALID_TEXT_DRAW) return 0;
    if(!IsValidPlayerTextDraw(playerid, td)) return 0;
    PlayerTextDrawShow(playerid, td);
    return 1;
}
#define PlayerTextDrawShow PlayerTextDrawShowEx
stock PlayerTextDrawHideEx(playerid, &PlayerText:td)
{
    if(!IsValidPlayerTextDraw(playerid, td)) return 0;
    if(td != PlayerText:INVALID_TEXT_DRAW) PlayerTextDrawHide(playerid, td);
    return 1;
}
#define PlayerTextDrawHide PlayerTextDrawHideEx
stock PlayerTextDrawSetStringEx(playerid, &PlayerText:td, const string[])
{
    if(!IsValidPlayerTextDraw(playerid, td)) return 0;
    if(td != PlayerText:INVALID_TEXT_DRAW) PlayerTextDrawSetString(playerid, td, string);
    return 1;
}
#define PlayerTextDrawSetString PlayerTextDrawSetStringEx
stock PlayerTextDrawSetPreviewModelEx(playerid, &PlayerText:td, modelindex)
{
    if(!IsValidPlayerTextDraw(playerid, td)) return 0;
    if(td != PlayerText:INVALID_TEXT_DRAW) PlayerTextDrawSetPreviewModel(playerid, td, modelindex);
    return 1;
}
#define PlayerTextDrawSetPreviewModel PlayerTextDrawSetPreviewModelEx
stock PlayerTextDrawSetPreviewRotEx(playerid, &PlayerText:td, Float:fRotX, Float:fRotY, Float:fRotZ, Float:fZoom = 1.0)
{
    if(!IsValidPlayerTextDraw(playerid, td)) return 0;
    if(td != PlayerText:INVALID_TEXT_DRAW) PlayerTextDrawSetPreviewRot(playerid, td, fRotX, fRotY, fRotZ, fZoom);
    return 1;
}
#define PlayerTextDrawSetPreviewRot PlayerTextDrawSetPreviewRotEx
//#define PlayerTextDrawSetPreviewVehCol PlayerTextDrawSetPreviewVehColEx