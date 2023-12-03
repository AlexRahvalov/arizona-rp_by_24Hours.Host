stock ShowBalloonTD(playerid)
{
    ProgressBalloonTD[playerid][0] = 40.0, ProgressBalloonTD[playerid][1] = 256.0;
    GlobalTDPlayer[playerid][0] = CreatePlayerTextDraw(playerid, 224.1110, 156.1324, "Box");
    PlayerTextDrawLetterSize(playerid, GlobalTDPlayer[playerid][0], 0.0051, 11.8741);
    PlayerTextDrawTextSize(playerid, GlobalTDPlayer[playerid][0], 407.0000, 0.0000);
    PlayerTextDrawAlignment(playerid, GlobalTDPlayer[playerid][0], 1);
    PlayerTextDrawColor(playerid, GlobalTDPlayer[playerid][0], -505290241);
    PlayerTextDrawUseBox(playerid, GlobalTDPlayer[playerid][0], 1);
    PlayerTextDrawBoxColor(playerid, GlobalTDPlayer[playerid][0], 437918463);
    PlayerTextDrawBackgroundColor(playerid, GlobalTDPlayer[playerid][0], 255);
    PlayerTextDrawFont(playerid, GlobalTDPlayer[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, GlobalTDPlayer[playerid][0], 1);
    PlayerTextDrawSetShadow(playerid, GlobalTDPlayer[playerid][0], 0);

    GlobalTDPlayer[playerid][1] = CreatePlayerTextDraw(playerid, 222.2176, 226.2870, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, GlobalTDPlayer[playerid][1], 187.0000, 30.0000);
    PlayerTextDrawAlignment(playerid, GlobalTDPlayer[playerid][1], 1);
    PlayerTextDrawColor(playerid, GlobalTDPlayer[playerid][1], InvColor[PI[playerid][pInvColor]][2]);
    PlayerTextDrawBackgroundColor(playerid, GlobalTDPlayer[playerid][1], 255);
    PlayerTextDrawFont(playerid, GlobalTDPlayer[playerid][1], 4);
    PlayerTextDrawSetProportional(playerid, GlobalTDPlayer[playerid][1], 0);
    PlayerTextDrawSetShadow(playerid, GlobalTDPlayer[playerid][1], 0);

    GlobalTDPlayer[playerid][2] = CreatePlayerTextDraw(playerid, 237.9761, 160.2001, "YOUR_PROGRESS");
    PlayerTextDrawLetterSize(playerid, GlobalTDPlayer[playerid][2], 0.1037, 1.0774);
    PlayerTextDrawAlignment(playerid, GlobalTDPlayer[playerid][2], 1);
    PlayerTextDrawColor(playerid, GlobalTDPlayer[playerid][2], -2139062017);
    PlayerTextDrawBackgroundColor(playerid, GlobalTDPlayer[playerid][2], 255);
    PlayerTextDrawFont(playerid, GlobalTDPlayer[playerid][2], 2);
    PlayerTextDrawSetProportional(playerid, GlobalTDPlayer[playerid][2], 1);
    PlayerTextDrawSetShadow(playerid, GlobalTDPlayer[playerid][2], 0);

    GlobalTDPlayer[playerid][3] = CreatePlayerTextDraw(playerid, 234.4705, 170.1665, "20%_TO_COMPILE");
    PlayerTextDrawLetterSize(playerid, GlobalTDPlayer[playerid][3], 0.1457, 1.0283);
    PlayerTextDrawAlignment(playerid, GlobalTDPlayer[playerid][3], 1);
    PlayerTextDrawColor(playerid, GlobalTDPlayer[playerid][3], -1);
    PlayerTextDrawBackgroundColor(playerid, GlobalTDPlayer[playerid][3], 255);
    PlayerTextDrawFont(playerid, GlobalTDPlayer[playerid][3], 2);
    PlayerTextDrawSetProportional(playerid, GlobalTDPlayer[playerid][3], 1);
    PlayerTextDrawSetShadow(playerid, GlobalTDPlayer[playerid][3], 0);

    if(ProgressBalloon[playerid] == 1) GlobalTDPlayer[playerid][4] = CreatePlayerTextDraw(playerid, 357.0639, 231.0335, "PRESSED_[~b~_H_~s~]");
    else if(ProgressBalloon[playerid] == 2) GlobalTDPlayer[playerid][4] = CreatePlayerTextDraw(playerid, 357.0639, 231.0335, "PRESSED_[~b~_L.ALT_~s~]");
    else if(ProgressBalloon[playerid] == 3) GlobalTDPlayer[playerid][4] = CreatePlayerTextDraw(playerid, 357.0639, 231.0335, "PRESSED_[~b~_SPACE_~s~]");
    PlayerTextDrawLetterSize(playerid, GlobalTDPlayer[playerid][4], 0.3463, 1.9899);
    PlayerTextDrawTextSize(playerid, GlobalTDPlayer[playerid][4], -11.0000, 0.0000);
    PlayerTextDrawAlignment(playerid, GlobalTDPlayer[playerid][4], 3);
    PlayerTextDrawColor(playerid, GlobalTDPlayer[playerid][4], -1);
    PlayerTextDrawBackgroundColor(playerid, GlobalTDPlayer[playerid][4], 255);
    PlayerTextDrawFont(playerid, GlobalTDPlayer[playerid][4], 1);
    PlayerTextDrawSetProportional(playerid, GlobalTDPlayer[playerid][4], 1);
    PlayerTextDrawSetShadow(playerid, GlobalTDPlayer[playerid][4], 0);

    GlobalTDPlayer[playerid][5] = CreatePlayerTextDraw(playerid, 235.3528, 191.1666, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, GlobalTDPlayer[playerid][5], 160.0000, 22.9299);
    PlayerTextDrawAlignment(playerid, GlobalTDPlayer[playerid][5], 1);
    PlayerTextDrawColor(playerid, GlobalTDPlayer[playerid][5], InvColor[PI[playerid][pInvColor]][2]);
    PlayerTextDrawBackgroundColor(playerid, GlobalTDPlayer[playerid][5], 0);
    PlayerTextDrawFont(playerid, GlobalTDPlayer[playerid][5], 4);
    PlayerTextDrawSetProportional(playerid, GlobalTDPlayer[playerid][5], 0);
    PlayerTextDrawSetShadow(playerid, GlobalTDPlayer[playerid][5], 0);

    GlobalTDPlayer[playerid][6] = CreatePlayerTextDraw(playerid, 377.3706, 184.7500, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, GlobalTDPlayer[playerid][6], 34.0000, 35.9701);
    PlayerTextDrawAlignment(playerid, GlobalTDPlayer[playerid][6], 1);
    PlayerTextDrawColor(playerid, GlobalTDPlayer[playerid][6], InvColor[PI[playerid][pInvColor]][2]);
    PlayerTextDrawBackgroundColor(playerid, GlobalTDPlayer[playerid][6], 0);
    PlayerTextDrawFont(playerid, GlobalTDPlayer[playerid][6], 4);
    PlayerTextDrawSetProportional(playerid, GlobalTDPlayer[playerid][6], 0);
    PlayerTextDrawSetShadow(playerid, GlobalTDPlayer[playerid][6], 0);

    GlobalTDPlayer[playerid][7] = CreatePlayerTextDraw(playerid, 221.6059, 185.1333, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, GlobalTDPlayer[playerid][7], 31.0000, 35.3199);
    PlayerTextDrawAlignment(playerid, GlobalTDPlayer[playerid][7], 1);
    PlayerTextDrawColor(playerid, GlobalTDPlayer[playerid][7], InvColor[PI[playerid][pInvColor]][1]);
    PlayerTextDrawBackgroundColor(playerid, GlobalTDPlayer[playerid][7], 255);
    PlayerTextDrawFont(playerid, GlobalTDPlayer[playerid][7], 4);
    PlayerTextDrawSetProportional(playerid, GlobalTDPlayer[playerid][7], 0);
    PlayerTextDrawSetShadow(playerid, GlobalTDPlayer[playerid][7], 0);

    GlobalTDPlayer[playerid][8] = CreatePlayerTextDraw(playerid, 235.3528, 191.1666, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, GlobalTDPlayer[playerid][8], ProgressBalloonTD[playerid][0], 22.9299);
    PlayerTextDrawAlignment(playerid, GlobalTDPlayer[playerid][8], 1);
    PlayerTextDrawColor(playerid, GlobalTDPlayer[playerid][8], InvColor[PI[playerid][pInvColor]][1]);
    PlayerTextDrawBackgroundColor(playerid, GlobalTDPlayer[playerid][8], 255);
    PlayerTextDrawFont(playerid, GlobalTDPlayer[playerid][8], 4);
    PlayerTextDrawSetProportional(playerid, GlobalTDPlayer[playerid][8], 0);
    PlayerTextDrawSetShadow(playerid, GlobalTDPlayer[playerid][8], 0);

    GlobalTDPlayer[playerid][9] = CreatePlayerTextDraw(playerid, ProgressBalloonTD[playerid][1], 185.0500, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, GlobalTDPlayer[playerid][9], 33.6300, 35.3799);
    PlayerTextDrawAlignment(playerid, GlobalTDPlayer[playerid][9], 1);
    PlayerTextDrawColor(playerid, GlobalTDPlayer[playerid][9], InvColor[PI[playerid][pInvColor]][1]);
    PlayerTextDrawBackgroundColor(playerid, GlobalTDPlayer[playerid][9], 255);
    PlayerTextDrawFont(playerid, GlobalTDPlayer[playerid][9], 4);
    PlayerTextDrawSetProportional(playerid, GlobalTDPlayer[playerid][9], 0);
    PlayerTextDrawSetShadow(playerid, GlobalTDPlayer[playerid][9], 0);

    for(new i; i < 10; i++) PlayerTextDrawShow(playerid, GlobalTDPlayer[playerid][i]);
    BalloonTimer[playerid] = SetTimerEx("BalloonTime", 200, 1, "d", playerid);
    return 1;
}