stock SetEngineStatus(carid, bool:status, playerid)
{
    new engine,lights,alarm,doors,bonnet,boot,objective;
    GetVehicleParamsEx(carid,engine,lights,alarm,doors,bonnet,boot,objective);
    SetVehicleParamsEx(carid,status,lights,alarm,doors,bonnet,boot,objective);
    vTemp[carid][vEngine] = status;
    if(!status) Iter_Remove(EngineON_Vehicle, carid);
    else Iter_Add(EngineON_Vehicle, carid);
    if(!IsPlayerConnectEx(playerid)) return 1;
    if(IsPlayerInitCef(playerid) == 1) return 1;
    if(!status)
    {
        SetLightsStatus(carid, false, playerid != -1? playerid: -1);
        if(!IsAVelik(carid) && !IsAPlane(carid) && GetPVarInt(playerid, !"pSpeed"))
        {
            PlayerTextDrawSetString(playerid, speeddraw[playerid][4], "000");
            PlayerTextDrawSetString(playerid, speeddraw[playerid][3], "_");
        }
    }
    if(!IsAVelik(carid) && !IsAPlane(carid) && GetPlayerState(playerid)==2 && GetPVarInt(playerid, !"pSpeed"))
    {
        if(PI[playerid][pCustomInterface] != 0 && IsPlayerLauncher(playerid) != 0) return 1;
        if(!PI[playerid][pTypeSpeed])
        {
            if(IsPlayerTextDrawVisible(playerid, speeddraw[playerid][2])) DestroyPlayerTD(playerid, speeddraw[playerid][2]);
            speeddraw[playerid][2] = CreatePlayerTextDraw(playerid, 603.0, 396.0, "eng"); //????????? ??? ??
            PlayerTextDrawAlignment(playerid, speeddraw[playerid][2], 2);
            PlayerTextDrawBackgroundColor(playerid, speeddraw[playerid][2], 255);
            PlayerTextDrawFont(playerid, speeddraw[playerid][2], 2);
            PlayerTextDrawLetterSize(playerid, speeddraw[playerid][2], 0.259999, 1.600000);
            PlayerTextDrawColor(playerid, speeddraw[playerid][2], -1);
            PlayerTextDrawSetOutline(playerid, speeddraw[playerid][2], 0);
            PlayerTextDrawSetProportional(playerid, speeddraw[playerid][2], 1);
            PlayerTextDrawSetShadow(playerid, speeddraw[playerid][2], 1);
            PlayerTextDrawUseBox(playerid, speeddraw[playerid][2], 1);
            PlayerTextDrawBoxColor(playerid, speeddraw[playerid][2], (vTemp[carid][vEngine])?576000767:-1407312129);
            PlayerTextDrawTextSize(playerid, speeddraw[playerid][2], 241.0, 28.0);
            PlayerTextDrawSetSelectable(playerid, speeddraw[playerid][2], 0);
            PlayerTextDrawShow(playerid, speeddraw[playerid][2]);
        }
        else
        {
            new number = GetVehicleID(carid);
            if(!vTemp[carid][vEngine])
            {
                for(new i = 22; i < 25; i++) if(IsPlayerTextDrawVisible(playerid, speed_prodvin[playerid][i])) DestroyPlayerTD(playerid, speed_prodvin[playerid][i]);

                speed_prodvin[playerid][24] = CreatePlayerTextDraw(playerid, 582.432983, 394.403503, "o");
                PlayerTextDrawLetterSize(playerid, speed_prodvin[playerid][24], -0.256300, 0.952700);
                PlayerTextDrawTextSize(playerid, speed_prodvin[playerid][24], 1280.0, 1280.0);
                PlayerTextDrawAlignment(playerid, speed_prodvin[playerid][24], 2);
                PlayerTextDrawColor(playerid, speed_prodvin[playerid][24], 0x282828FF);
                PlayerTextDrawUseBox(playerid, speed_prodvin[playerid][24], 0);
                PlayerTextDrawBoxColor(playerid, speed_prodvin[playerid][24], 0x80808080);
                PlayerTextDrawSetShadow(playerid, speed_prodvin[playerid][24], 0);
                PlayerTextDrawSetOutline(playerid, speed_prodvin[playerid][24], 0);
                PlayerTextDrawBackgroundColor(playerid, speed_prodvin[playerid][24], 0x000000FF);
                PlayerTextDrawFont(playerid, speed_prodvin[playerid][24], 2);
                PlayerTextDrawSetProportional(playerid, speed_prodvin[playerid][24], 1);
                PlayerTextDrawSetSelectable(playerid, speed_prodvin[playerid][24], 0);

                speed_prodvin[playerid][23] = CreatePlayerTextDraw(playerid, 582.632996, 392.155304, "C");
                PlayerTextDrawLetterSize(playerid, speed_prodvin[playerid][23], -0.198300, 0.824100);
                PlayerTextDrawTextSize(playerid, speed_prodvin[playerid][23], 1280.0, 1280.0);
                PlayerTextDrawAlignment(playerid, speed_prodvin[playerid][23], 2);
                PlayerTextDrawColor(playerid, speed_prodvin[playerid][23], 0x282828FF);
                PlayerTextDrawUseBox(playerid, speed_prodvin[playerid][23], 0);
                PlayerTextDrawBoxColor(playerid, speed_prodvin[playerid][23], 0x80808080);
                PlayerTextDrawSetShadow(playerid, speed_prodvin[playerid][23], 0);
                PlayerTextDrawSetOutline(playerid, speed_prodvin[playerid][23], 0);
                PlayerTextDrawBackgroundColor(playerid, speed_prodvin[playerid][23], 0x000000FF);
                PlayerTextDrawFont(playerid, speed_prodvin[playerid][23], 2);
                PlayerTextDrawSetProportional(playerid, speed_prodvin[playerid][23], 1);
                PlayerTextDrawSetSelectable(playerid, speed_prodvin[playerid][23], 0);

                speed_prodvin[playerid][22] = CreatePlayerTextDraw(playerid, 583.033325, 393.021912, ".");
                PlayerTextDrawLetterSize(playerid, speed_prodvin[playerid][22], 0.167300, 1.010900);
                PlayerTextDrawTextSize(playerid, speed_prodvin[playerid][22], 1280.0, 1280.0);
                PlayerTextDrawAlignment(playerid, speed_prodvin[playerid][22], 2);
                PlayerTextDrawColor(playerid, speed_prodvin[playerid][22], 0x282828FF);
                PlayerTextDrawUseBox(playerid, speed_prodvin[playerid][22], 0);
                PlayerTextDrawBoxColor(playerid, speed_prodvin[playerid][22], 0x80808080);
                PlayerTextDrawSetShadow(playerid, speed_prodvin[playerid][22], 0);
                PlayerTextDrawSetOutline(playerid, speed_prodvin[playerid][22], 0);
                PlayerTextDrawBackgroundColor(playerid, speed_prodvin[playerid][22], 0x000000FF);
                PlayerTextDrawFont(playerid, speed_prodvin[playerid][22], 2);
                PlayerTextDrawSetProportional(playerid, speed_prodvin[playerid][22], 1);
                PlayerTextDrawSetSelectable(playerid, speed_prodvin[playerid][22], 0);
                for(new i = 22; i < 25; i++) PlayerTextDrawShow(playerid, speed_prodvin[playerid][i]);
            }
            else
            {
                for(new i = 22; i < 25; i++) if(IsPlayerTextDrawVisible(playerid, speed_prodvin[playerid][i])) DestroyPlayerTD(playerid, speed_prodvin[playerid][i]);

                speed_prodvin[playerid][24] = CreatePlayerTextDraw(playerid, 582.432983, 394.403503, "o");
                PlayerTextDrawLetterSize(playerid, speed_prodvin[playerid][24], -0.256300, 0.952700);
                PlayerTextDrawTextSize(playerid, speed_prodvin[playerid][24], 1280.0, 1280.0);
                PlayerTextDrawAlignment(playerid, speed_prodvin[playerid][24], 2);
                if(IsAOwnableCar(carid))PlayerTextDrawColor(playerid, speed_prodvin[playerid][24], (CarInfo[number][cLock])?0xFFFFFFF:0x14DB43FF);
                else if(!IsAOwnableCar(carid) && vTemp[carid][vJob] == 0 && !IsAArendCar(carid)) PlayerTextDrawColor(playerid, speed_prodvin[playerid][24], (vTemp[carid][vEngine])?0x282828FF:0x14DB43FF);
                else if(vTemp[carid][vJob]!=0 || IsAArendCar(carid)) PlayerTextDrawColor(playerid, speed_prodvin[playerid][24], (vTemp[carid][vLock])?0xFFFFFFF:0x14DB43FF);
                PlayerTextDrawUseBox(playerid, speed_prodvin[playerid][24], 0);
                PlayerTextDrawBoxColor(playerid, speed_prodvin[playerid][24], 0x80808080);
                PlayerTextDrawSetShadow(playerid, speed_prodvin[playerid][24], 0);
                PlayerTextDrawSetOutline(playerid, speed_prodvin[playerid][24], 0);
                PlayerTextDrawBackgroundColor(playerid, speed_prodvin[playerid][24], 0x000000FF);
                PlayerTextDrawFont(playerid, speed_prodvin[playerid][24], 2);
                PlayerTextDrawSetProportional(playerid, speed_prodvin[playerid][24], 1);
                PlayerTextDrawSetSelectable(playerid, speed_prodvin[playerid][24], 0);

                speed_prodvin[playerid][23] = CreatePlayerTextDraw(playerid, 582.632996, 392.155304, "C");
                PlayerTextDrawLetterSize(playerid, speed_prodvin[playerid][23], -0.198300, 0.824100);
                PlayerTextDrawTextSize(playerid, speed_prodvin[playerid][23], 1280.0, 1280.0);
                PlayerTextDrawAlignment(playerid, speed_prodvin[playerid][23], 2);
                if(IsAOwnableCar(carid))PlayerTextDrawColor(playerid, speed_prodvin[playerid][23], (CarInfo[number][cLock])?0xFFFFFFF:0x14DB43FF);
                else if(!IsAOwnableCar(carid) && vTemp[carid][vJob] == 0 && !IsAArendCar(carid)) PlayerTextDrawColor(playerid, speed_prodvin[playerid][23], (vTemp[carid][vEngine])?0x282828FF:0x14DB43FF);
                else if(vTemp[carid][vJob]!=0 || IsAArendCar(carid)) PlayerTextDrawColor(playerid, speed_prodvin[playerid][23], (vTemp[carid][vLock])?0xFFFFFFF:0x14DB43FF);
                PlayerTextDrawUseBox(playerid, speed_prodvin[playerid][23], 0);
                PlayerTextDrawBoxColor(playerid, speed_prodvin[playerid][23], 0x80808080);
                PlayerTextDrawSetShadow(playerid, speed_prodvin[playerid][23], 0);
                PlayerTextDrawSetOutline(playerid, speed_prodvin[playerid][23], 0);
                PlayerTextDrawBackgroundColor(playerid, speed_prodvin[playerid][23], 0x000000FF);
                PlayerTextDrawFont(playerid, speed_prodvin[playerid][23], 2);
                PlayerTextDrawSetProportional(playerid, speed_prodvin[playerid][23], 1);
                PlayerTextDrawSetSelectable(playerid, speed_prodvin[playerid][23], 0);

                speed_prodvin[playerid][22] = CreatePlayerTextDraw(playerid, 583.033325, 393.021912, ".");
                PlayerTextDrawLetterSize(playerid, speed_prodvin[playerid][22], 0.167300, 1.010900);
                PlayerTextDrawTextSize(playerid, speed_prodvin[playerid][22], 1280.0, 1280.0);
                PlayerTextDrawAlignment(playerid, speed_prodvin[playerid][22], 2);
                if(IsAOwnableCar(carid))PlayerTextDrawColor(playerid, speed_prodvin[playerid][22], (CarInfo[number][cLock])?0xFFFFFFF:0x14DB43FF);
                else if(!IsAOwnableCar(carid) && vTemp[carid][vJob] == 0 && !IsAArendCar(carid)) PlayerTextDrawColor(playerid, speed_prodvin[playerid][22], (vTemp[carid][vEngine])?0x282828FF:0x14DB43FF);
                else if(vTemp[carid][vJob]!=0 || IsAArendCar(carid)) PlayerTextDrawColor(playerid, speed_prodvin[playerid][22], (vTemp[carid][vLock])?0xFFFFFFF:0x14DB43FF);
                PlayerTextDrawUseBox(playerid, speed_prodvin[playerid][22], 0);
                PlayerTextDrawBoxColor(playerid, speed_prodvin[playerid][22], 0x80808080);
                PlayerTextDrawSetShadow(playerid, speed_prodvin[playerid][22], 0);
                PlayerTextDrawSetOutline(playerid, speed_prodvin[playerid][22], 0);
                PlayerTextDrawBackgroundColor(playerid, speed_prodvin[playerid][22], 0x000000FF);
                PlayerTextDrawFont(playerid, speed_prodvin[playerid][22], 2);
                PlayerTextDrawSetProportional(playerid, speed_prodvin[playerid][22], 1);
                PlayerTextDrawSetSelectable(playerid, speed_prodvin[playerid][22], 0);
                for(new i = 22; i < 25; i++) PlayerTextDrawShow(playerid, speed_prodvin[playerid][i]);
            }

            if(IsPlayerTextDrawVisible(playerid, speed_prodvin[playerid][33])) DestroyPlayerTD(playerid, speed_prodvin[playerid][33]);
            speed_prodvin[playerid][33] = CreatePlayerTextDraw(playerid, 540.133301, 394.433105, "000");
            PlayerTextDrawLetterSize(playerid, speed_prodvin[playerid][33], 0.244200, 1.873700);
            PlayerTextDrawTextSize(playerid, speed_prodvin[playerid][33], 1280.0, 1280.0);
            PlayerTextDrawAlignment(playerid, speed_prodvin[playerid][33], 2);
            PlayerTextDrawColor(playerid, speed_prodvin[playerid][33], (vTemp[carid][vEngine])?0xA52A2AFF:0x282828FF);
            PlayerTextDrawUseBox(playerid, speed_prodvin[playerid][33], 0);
            PlayerTextDrawBoxColor(playerid, speed_prodvin[playerid][33], 0x80808080);
            PlayerTextDrawSetShadow(playerid, speed_prodvin[playerid][33], 0);
            PlayerTextDrawSetOutline(playerid, speed_prodvin[playerid][33], 1);
            PlayerTextDrawBackgroundColor(playerid, speed_prodvin[playerid][33], 0x00000015);
            PlayerTextDrawFont(playerid, speed_prodvin[playerid][33], 2);
            PlayerTextDrawSetProportional(playerid, speed_prodvin[playerid][33], 1);
            PlayerTextDrawSetSelectable(playerid, speed_prodvin[playerid][33], 0);
            PlayerTextDrawShow(playerid, speed_prodvin[playerid][33]);
            //ôàðû
            for(new i = 27; i < 30; i++) if(IsPlayerTextDrawVisible(playerid, speed_prodvin[playerid][i])) DestroyPlayerTD(playerid, speed_prodvin[playerid][i]);

            speed_prodvin[playerid][29] = CreatePlayerTextDraw(playerid, 565.433228, 390.829498, "D");
            PlayerTextDrawLetterSize(playerid, speed_prodvin[playerid][29], -0.185200, 1.367599);
            PlayerTextDrawTextSize(playerid, speed_prodvin[playerid][29], 1280.0, 1280.0);
            PlayerTextDrawAlignment(playerid, speed_prodvin[playerid][29], 1);
            PlayerTextDrawColor(playerid, speed_prodvin[playerid][29], (vTemp[carid][vEngine])?0xA52A2AFF:0x282828FF);
            PlayerTextDrawUseBox(playerid, speed_prodvin[playerid][29], 0);
            PlayerTextDrawBoxColor(playerid, speed_prodvin[playerid][29], 0x80808080);
            PlayerTextDrawSetShadow(playerid, speed_prodvin[playerid][29], 0);
            PlayerTextDrawSetOutline(playerid, speed_prodvin[playerid][29], 0);
            PlayerTextDrawBackgroundColor(playerid, speed_prodvin[playerid][29], 0x000000FF);
            PlayerTextDrawFont(playerid, speed_prodvin[playerid][29], 2);
            PlayerTextDrawSetProportional(playerid, speed_prodvin[playerid][29], 1);
            PlayerTextDrawSetSelectable(playerid, speed_prodvin[playerid][29], 0);

            speed_prodvin[playerid][28] = CreatePlayerTextDraw(playerid, 565.766602, 390.362915, "=");
            PlayerTextDrawLetterSize(playerid, speed_prodvin[playerid][28], 0.197300, 1.180899);
            PlayerTextDrawTextSize(playerid, speed_prodvin[playerid][28], 1280.0, 1280.0);
            PlayerTextDrawAlignment(playerid, speed_prodvin[playerid][28], 1);
            PlayerTextDrawColor(playerid, speed_prodvin[playerid][28], (vTemp[carid][vEngine])?0xA52A2AFF:0x282828FF);
            PlayerTextDrawUseBox(playerid, speed_prodvin[playerid][28], 0);
            PlayerTextDrawBoxColor(playerid, speed_prodvin[playerid][28], 0x80808080);
            PlayerTextDrawSetShadow(playerid, speed_prodvin[playerid][28], 0);
            PlayerTextDrawSetOutline(playerid, speed_prodvin[playerid][28], 0);
            PlayerTextDrawBackgroundColor(playerid, speed_prodvin[playerid][28], 0x000000FF);
            PlayerTextDrawFont(playerid, speed_prodvin[playerid][28], 1);
            PlayerTextDrawSetProportional(playerid, speed_prodvin[playerid][28], 1);
            PlayerTextDrawSetSelectable(playerid, speed_prodvin[playerid][28], 0);

            speed_prodvin[playerid][27] = CreatePlayerTextDraw(playerid, 565.566528, 394.362915, "=");
            PlayerTextDrawLetterSize(playerid, speed_prodvin[playerid][27], 0.201900, 1.156100);
            PlayerTextDrawTextSize(playerid, speed_prodvin[playerid][27], 1280.0, 1280.0);
            PlayerTextDrawAlignment(playerid, speed_prodvin[playerid][27], 1);
            PlayerTextDrawColor(playerid, speed_prodvin[playerid][27], (vTemp[carid][vEngine])?0xA52A2AFF:0x282828FF);
            PlayerTextDrawUseBox(playerid, speed_prodvin[playerid][27], 0);
            PlayerTextDrawBoxColor(playerid, speed_prodvin[playerid][27], 0x80808080);
            PlayerTextDrawSetShadow(playerid, speed_prodvin[playerid][27], 0);
            PlayerTextDrawSetOutline(playerid, speed_prodvin[playerid][27], 0);
            PlayerTextDrawBackgroundColor(playerid, speed_prodvin[playerid][27], 0x000000FF);
            PlayerTextDrawFont(playerid, speed_prodvin[playerid][27], 1);
            PlayerTextDrawSetProportional(playerid, speed_prodvin[playerid][27], 1);
            PlayerTextDrawSetSelectable(playerid, speed_prodvin[playerid][27], 0);
            for(new i = 27; i < 30; i++) PlayerTextDrawShow(playerid, speed_prodvin[playerid][i]);

            static temptext[16];
            DestroyPlayerTD(playerid, speed_prodvin[playerid][12]);
            if(IsAOwnableCar(carid)) format(temptext, sizeof(temptext), "%08.0f", CarInfo[number][cMilage]);
            else format(temptext, sizeof(temptext), "00000000");
            speed_prodvin[playerid][12] = CreatePlayerTextDraw(playerid, 608.833618, 408.877594, temptext);
            PlayerTextDrawLetterSize(playerid, speed_prodvin[playerid][12], 0.149499, 0.948700);
            PlayerTextDrawTextSize(playerid, speed_prodvin[playerid][12], 1280.0, 1280.0);
            PlayerTextDrawAlignment(playerid, speed_prodvin[playerid][12], 2);
            PlayerTextDrawColor(playerid, speed_prodvin[playerid][12], (vTemp[carid][vEngine])?0xA52A2AFF:0x282828FF);
            PlayerTextDrawUseBox(playerid, speed_prodvin[playerid][12], 0);
            PlayerTextDrawBoxColor(playerid, speed_prodvin[playerid][12], 0x80808080);
            PlayerTextDrawSetShadow(playerid, speed_prodvin[playerid][12], 0);
            PlayerTextDrawSetOutline(playerid, speed_prodvin[playerid][12], 0);
            PlayerTextDrawBackgroundColor(playerid, speed_prodvin[playerid][12], 0x000000FF);
            PlayerTextDrawFont(playerid, speed_prodvin[playerid][12], 2);
            PlayerTextDrawSetProportional(playerid, speed_prodvin[playerid][12], 1);
            PlayerTextDrawSetSelectable(playerid, speed_prodvin[playerid][12], 0);
            PlayerTextDrawShow(playerid, speed_prodvin[playerid][12]);
            //fuel
            for(new i = 3; i < 9; i++) if(IsPlayerTextDrawVisible(playerid, speed_prodvin[playerid][i])) DestroyPlayerTD(playerid, speed_prodvin[playerid][i]);
            speed_prodvin[playerid][8] = CreatePlayerTextDraw(playerid, 529.766602, 429.755188, "O");
            PlayerTextDrawLetterSize(playerid, speed_prodvin[playerid][8], 0.183300, 0.753700);
            PlayerTextDrawTextSize(playerid, speed_prodvin[playerid][8], 1280.0, 1280.0);
            PlayerTextDrawAlignment(playerid, speed_prodvin[playerid][8], 2);
            PlayerTextDrawColor(playerid, speed_prodvin[playerid][8], (vTemp[carid][vEngine])?0x14DB43FF:0x808080FF);
            PlayerTextDrawUseBox(playerid, speed_prodvin[playerid][8], 0);
            PlayerTextDrawBoxColor(playerid, speed_prodvin[playerid][8], 0x80808080);
            PlayerTextDrawSetShadow(playerid, speed_prodvin[playerid][8], 0);
            PlayerTextDrawSetOutline(playerid, speed_prodvin[playerid][8], 0);
            PlayerTextDrawBackgroundColor(playerid, speed_prodvin[playerid][8], 0x000000FF);
            PlayerTextDrawFont(playerid, speed_prodvin[playerid][8], 3);
            PlayerTextDrawSetProportional(playerid, speed_prodvin[playerid][8], 1);
            PlayerTextDrawSetSelectable(playerid, speed_prodvin[playerid][8], 0);

            speed_prodvin[playerid][7] = CreatePlayerTextDraw(playerid, 530.099915, 425.854889, "O");
            PlayerTextDrawLetterSize(playerid, speed_prodvin[playerid][7], 0.144899, 0.679000);
            PlayerTextDrawTextSize(playerid, speed_prodvin[playerid][7], 1280.0, 1280.0);
            PlayerTextDrawAlignment(playerid, speed_prodvin[playerid][7], 2);
            PlayerTextDrawColor(playerid, speed_prodvin[playerid][7], (vTemp[carid][vEngine])?0x14DB43FF:0x808080FF);
            PlayerTextDrawUseBox(playerid, speed_prodvin[playerid][7], 0);
            PlayerTextDrawBoxColor(playerid, speed_prodvin[playerid][7], 0x80808080);
            PlayerTextDrawSetShadow(playerid, speed_prodvin[playerid][7], 0);
            PlayerTextDrawSetOutline(playerid, speed_prodvin[playerid][7], 0);
            PlayerTextDrawBackgroundColor(playerid, speed_prodvin[playerid][7], 0x000000FF);
            PlayerTextDrawFont(playerid, speed_prodvin[playerid][7], 2);
            PlayerTextDrawSetProportional(playerid, speed_prodvin[playerid][7], 1);
            PlayerTextDrawSetSelectable(playerid, speed_prodvin[playerid][7], 0);

            speed_prodvin[playerid][6] = CreatePlayerTextDraw(playerid, 532.799805, 427.299408, "S");
            PlayerTextDrawLetterSize(playerid, speed_prodvin[playerid][6], 0.157000, 0.998399);
            PlayerTextDrawTextSize(playerid, speed_prodvin[playerid][6], 1280.0, 1280.0);
            PlayerTextDrawAlignment(playerid, speed_prodvin[playerid][6], 2);
            PlayerTextDrawColor(playerid, speed_prodvin[playerid][6], (vTemp[carid][vEngine])?0x14DB43FF:0x808080FF);
            PlayerTextDrawUseBox(playerid, speed_prodvin[playerid][6], 0);
            PlayerTextDrawBoxColor(playerid, speed_prodvin[playerid][6], 0x80808080);
            PlayerTextDrawSetShadow(playerid, speed_prodvin[playerid][6], 0);
            PlayerTextDrawSetOutline(playerid, speed_prodvin[playerid][6], 0);
            PlayerTextDrawBackgroundColor(playerid, speed_prodvin[playerid][6], 0x000000FF);
            PlayerTextDrawFont(playerid, speed_prodvin[playerid][6], 1);
            PlayerTextDrawSetProportional(playerid, speed_prodvin[playerid][6], 1);
            PlayerTextDrawSetSelectable(playerid, speed_prodvin[playerid][6], 0);

            speed_prodvin[playerid][5] = CreatePlayerTextDraw(playerid, 536.133301, 429.577606, "LD_SPAC:white");
            PlayerTextDrawLetterSize(playerid, speed_prodvin[playerid][5], 0.0, 0.0);
            PlayerTextDrawTextSize(playerid, speed_prodvin[playerid][5], 80.0, 4.0);
            PlayerTextDrawAlignment(playerid, speed_prodvin[playerid][5], 1);
            PlayerTextDrawColor(playerid, speed_prodvin[playerid][5], 0x282828FF);
            PlayerTextDrawUseBox(playerid, speed_prodvin[playerid][5], 0);
            PlayerTextDrawBoxColor(playerid, speed_prodvin[playerid][5], 0x80808080);
            PlayerTextDrawSetShadow(playerid, speed_prodvin[playerid][5], 0);
            PlayerTextDrawSetOutline(playerid, speed_prodvin[playerid][5], 0);
            PlayerTextDrawBackgroundColor(playerid, speed_prodvin[playerid][5], 0x000000FF);
            PlayerTextDrawFont(playerid, speed_prodvin[playerid][5], 4);
            PlayerTextDrawSetProportional(playerid, speed_prodvin[playerid][5], 0);
            PlayerTextDrawSetSelectable(playerid, speed_prodvin[playerid][5], 0);

            speed_prodvin[playerid][4] = CreatePlayerTextDraw(playerid, 536.133301, 429.577606, "LD_SPAC:white");
            PlayerTextDrawLetterSize(playerid, speed_prodvin[playerid][4], 0.0, 0.0);
            PlayerTextDrawTextSize(playerid, speed_prodvin[playerid][4], vTemp[carid][Fuel]/1.25, 3.940000);
            PlayerTextDrawAlignment(playerid, speed_prodvin[playerid][4], 1);
            PlayerTextDrawColor(playerid, speed_prodvin[playerid][4], (vTemp[carid][vEngine])?0x14DB43FF:0x808080FF);
            PlayerTextDrawUseBox(playerid, speed_prodvin[playerid][4], 0);
            PlayerTextDrawBoxColor(playerid, speed_prodvin[playerid][4], 0x80808080);
            PlayerTextDrawSetShadow(playerid, speed_prodvin[playerid][4], 0);
            PlayerTextDrawSetOutline(playerid, speed_prodvin[playerid][4], 0);
            PlayerTextDrawBackgroundColor(playerid, speed_prodvin[playerid][4], 0x000000FF);
            PlayerTextDrawFont(playerid, speed_prodvin[playerid][4], 4);
            PlayerTextDrawSetProportional(playerid, speed_prodvin[playerid][4], 0);
            PlayerTextDrawSetSelectable(playerid, speed_prodvin[playerid][4], 0);

            speed_prodvin[playerid][3] = CreatePlayerTextDraw(playerid, 622.033203, 427.384613, "99%");
            PlayerTextDrawLetterSize(playerid, speed_prodvin[playerid][3], 0.116300, 0.820100);
            PlayerTextDrawTextSize(playerid, speed_prodvin[playerid][3], 1280.0, 1280.0);
            PlayerTextDrawAlignment(playerid, speed_prodvin[playerid][3], 2);
            PlayerTextDrawColor(playerid, speed_prodvin[playerid][3], (vTemp[carid][vEngine])?0x14DB43FF:0x808080FF);
            PlayerTextDrawUseBox(playerid, speed_prodvin[playerid][3], 0);
            PlayerTextDrawBoxColor(playerid, speed_prodvin[playerid][3], 0x80808080);
            PlayerTextDrawSetShadow(playerid, speed_prodvin[playerid][3], 0);
            PlayerTextDrawSetOutline(playerid, speed_prodvin[playerid][3], 0);
            PlayerTextDrawBackgroundColor(playerid, speed_prodvin[playerid][3], 0x000000FF);
            PlayerTextDrawFont(playerid, speed_prodvin[playerid][3], 2);
            PlayerTextDrawSetProportional(playerid, speed_prodvin[playerid][3], 1);
            PlayerTextDrawSetSelectable(playerid, speed_prodvin[playerid][3], 0);
            for(new i = 3; i < 9; i++) PlayerTextDrawShow(playerid, speed_prodvin[playerid][i]);
        }
    }
    return 1;
}
stock SetLightsStatus(carid,status, playerid=-1)
{
    new engine,lights,alarm,doors,bonnet,boot,objective;
    GetVehicleParamsEx(carid,engine,lights,alarm,doors,bonnet,boot,objective);
    SetVehicleParamsEx(carid,engine,status,alarm,doors,bonnet,boot,objective);
    vTemp[carid][vLights] = status;
    if(!IsPlayerConnectEx(playerid)) return 1;
    if(IsPlayerInitCef(playerid) == 1) return 1;
    if(!IsAVelik(carid) && !IsAPlane(carid) && GetPlayerState(playerid)==2 && GetPVarInt(playerid, !"pSpeed"))
    {
        if(PI[playerid][pCustomInterface] != 0 && IsPlayerLauncher(playerid) != 0) return 1;
        if(!PI[playerid][pTypeSpeed])
        {
            if(IsPlayerTextDrawVisible(playerid, speeddraw[playerid][1])) DestroyPlayerTD(playerid, speeddraw[playerid][1]);
            speeddraw[playerid][1] = CreatePlayerTextDraw(playerid, 567.0, 396.0, "light"); //????
            PlayerTextDrawAlignment(playerid, speeddraw[playerid][1], 2);
            PlayerTextDrawBackgroundColor(playerid, speeddraw[playerid][1], 255);
            PlayerTextDrawFont(playerid, speeddraw[playerid][1], 2);
            PlayerTextDrawLetterSize(playerid, speeddraw[playerid][1], 0.229999, 1.600000);
            PlayerTextDrawColor(playerid, speeddraw[playerid][1], -1);
            PlayerTextDrawSetOutline(playerid, speeddraw[playerid][1], 0);
            PlayerTextDrawSetProportional(playerid, speeddraw[playerid][1], 1);
            PlayerTextDrawSetShadow(playerid, speeddraw[playerid][1], 1);
            PlayerTextDrawUseBox(playerid, speeddraw[playerid][1], 1);
            PlayerTextDrawBoxColor(playerid, speeddraw[playerid][1], (vTemp[carid][vLights])?-949019137:0x848482FF);
            PlayerTextDrawTextSize(playerid, speeddraw[playerid][1], 241.0, 30.0);
            PlayerTextDrawSetSelectable(playerid, speeddraw[playerid][1], 0);
            PlayerTextDrawShow(playerid, speeddraw[playerid][1]);
        }
        else
        {
            for(new i = 27; i < 30; i++) if(IsPlayerTextDrawVisible(playerid, speed_prodvin[playerid][i])) DestroyPlayerTD(playerid, speed_prodvin[playerid][i]);
            speed_prodvin[playerid][29] = CreatePlayerTextDraw(playerid, 565.433228, 390.829498, "D");
            PlayerTextDrawLetterSize(playerid, speed_prodvin[playerid][29], -0.185200, 1.367599);
            PlayerTextDrawTextSize(playerid, speed_prodvin[playerid][29], 1280.0, 1280.0);
            PlayerTextDrawAlignment(playerid, speed_prodvin[playerid][29], 1);
            PlayerTextDrawColor(playerid, speed_prodvin[playerid][29], (vTemp[carid][vLights])?0xFFFFFFF:0xA52A2AFF);
            PlayerTextDrawUseBox(playerid, speed_prodvin[playerid][29], 0);
            PlayerTextDrawBoxColor(playerid, speed_prodvin[playerid][29], 0x80808080);
            PlayerTextDrawSetShadow(playerid, speed_prodvin[playerid][29], 0);
            PlayerTextDrawSetOutline(playerid, speed_prodvin[playerid][29], 0);
            PlayerTextDrawBackgroundColor(playerid, speed_prodvin[playerid][29], 0x000000FF);
            PlayerTextDrawFont(playerid, speed_prodvin[playerid][29], 2);
            PlayerTextDrawSetProportional(playerid, speed_prodvin[playerid][29], 1);
            PlayerTextDrawSetSelectable(playerid, speed_prodvin[playerid][29], 0);

            speed_prodvin[playerid][28] = CreatePlayerTextDraw(playerid, 565.766602, 390.362915, "=");
            PlayerTextDrawLetterSize(playerid, speed_prodvin[playerid][28], 0.197300, 1.180899);
            PlayerTextDrawTextSize(playerid, speed_prodvin[playerid][28], 1280.0, 1280.0);
            PlayerTextDrawAlignment(playerid, speed_prodvin[playerid][28], 1);
            PlayerTextDrawColor(playerid, speed_prodvin[playerid][28], (vTemp[carid][vLights])?0xFFFFFFF:0xA52A2AFF);
            PlayerTextDrawUseBox(playerid, speed_prodvin[playerid][28], 0);
            PlayerTextDrawBoxColor(playerid, speed_prodvin[playerid][28], 0x80808080);
            PlayerTextDrawSetShadow(playerid, speed_prodvin[playerid][28], 0);
            PlayerTextDrawSetOutline(playerid, speed_prodvin[playerid][28], 0);
            PlayerTextDrawBackgroundColor(playerid, speed_prodvin[playerid][28], 0x000000FF);
            PlayerTextDrawFont(playerid, speed_prodvin[playerid][28], 1);
            PlayerTextDrawSetProportional(playerid, speed_prodvin[playerid][28], 1);
            PlayerTextDrawSetSelectable(playerid, speed_prodvin[playerid][28], 0);

            speed_prodvin[playerid][27] = CreatePlayerTextDraw(playerid, 565.566528, 394.362915, "=");
            PlayerTextDrawLetterSize(playerid, speed_prodvin[playerid][27], 0.201900, 1.156100);
            PlayerTextDrawTextSize(playerid, speed_prodvin[playerid][27], 1280.0, 1280.0);
            PlayerTextDrawAlignment(playerid, speed_prodvin[playerid][27], 1);
            PlayerTextDrawColor(playerid, speed_prodvin[playerid][27], (vTemp[carid][vLights])?0xFFFFFFF:0xA52A2AFF);
            PlayerTextDrawUseBox(playerid, speed_prodvin[playerid][27], 0);
            PlayerTextDrawBoxColor(playerid, speed_prodvin[playerid][27], 0x80808080);
            PlayerTextDrawSetShadow(playerid, speed_prodvin[playerid][27], 0);
            PlayerTextDrawSetOutline(playerid, speed_prodvin[playerid][27], 0);
            PlayerTextDrawBackgroundColor(playerid, speed_prodvin[playerid][27], 0x000000FF);
            PlayerTextDrawFont(playerid, speed_prodvin[playerid][27], 1);
            PlayerTextDrawSetProportional(playerid, speed_prodvin[playerid][27], 1);
            PlayerTextDrawSetSelectable(playerid, speed_prodvin[playerid][27], 0);
            for(new i = 27; i < 30; i++) PlayerTextDrawShow(playerid, speed_prodvin[playerid][i]);
        }
    }
    return 1;
}
stock SetDoorsStatus(carid,status, playerid = -1)
{
    new engine,lights,alarm,doors,bonnet,boot,objective;
    GetVehicleParamsEx(carid,engine,lights,alarm,doors,bonnet,boot,objective);
    SetVehicleParamsEx(carid,engine,lights,alarm,status,bonnet,boot,objective);
    if(!IsPlayerConnectEx(playerid)) return 1;
    if(IsPlayerInitCef(playerid) == 1) return 1;
    if(GetPlayerState(playerid)==2 && !IsAVelik(carid) && !IsAPlane(carid) && GetPVarInt(playerid, !"pSpeed"))
    {
        if(PI[playerid][pCustomInterface] != 0 && IsPlayerLauncher(playerid) != 0) return 1;
        new number = GetVehicleID(carid);
        if(!PI[playerid][pTypeSpeed])
        {
            if(IsPlayerTextDrawVisible(playerid, speeddraw[playerid][0])) DestroyPlayerTD(playerid, speeddraw[playerid][0]);
            speeddraw[playerid][0] = CreatePlayerTextDraw(playerid, 531.0, 396.0, "lock");
            PlayerTextDrawAlignment(playerid, speeddraw[playerid][0], 2);
            PlayerTextDrawBackgroundColor(playerid, speeddraw[playerid][0], 255);
            PlayerTextDrawFont(playerid, speeddraw[playerid][0], 2);
            PlayerTextDrawLetterSize(playerid, speeddraw[playerid][0], 0.239998, 1.600000);
            PlayerTextDrawColor(playerid, speeddraw[playerid][0], -1);
            PlayerTextDrawSetOutline(playerid, speeddraw[playerid][0], 0);
            PlayerTextDrawSetProportional(playerid, speeddraw[playerid][0], 1);
            PlayerTextDrawSetShadow(playerid, speeddraw[playerid][0], 1);
            PlayerTextDrawUseBox(playerid, speeddraw[playerid][0], 1);
            if(IsAOwnableCar(number))PlayerTextDrawBoxColor(playerid, speeddraw[playerid][0], (CarInfo[number][cLock])?-1407312129:576000767);
            else if(vTemp[carid][vJob] !=0 || IsAArendCar(carid)) PlayerTextDrawBoxColor(playerid, speeddraw[playerid][0], (vTemp[carid][vLock])?-1407312129:576000767);
            PlayerTextDrawTextSize(playerid, speeddraw[playerid][0], 241.0, 28.0);
            PlayerTextDrawSetSelectable(playerid, speeddraw[playerid][0], 0);
            PlayerTextDrawShow(playerid, speeddraw[playerid][0]);
        }
        else
        {
            if(!vTemp[carid][vEngine]) return 1;
            for(new i = 22; i < 25; i++) if(IsPlayerTextDrawVisible(playerid, speed_prodvin[playerid][i])) DestroyPlayerTD(playerid, speed_prodvin[playerid][i]);
            speed_prodvin[playerid][24] = CreatePlayerTextDraw(playerid, 582.432983, 394.403503, "o");
            PlayerTextDrawLetterSize(playerid, speed_prodvin[playerid][24], -0.256300, 0.952700);
            PlayerTextDrawTextSize(playerid, speed_prodvin[playerid][24], 1280.0, 1280.0);
            PlayerTextDrawAlignment(playerid, speed_prodvin[playerid][24], 2);
            if(IsAOwnableCar(carid))PlayerTextDrawColor(playerid, speed_prodvin[playerid][24], (CarInfo[number][cLock])?0xFFFFFFF:0x14DB43FF);
            else if(!IsAOwnableCar(carid) && vTemp[carid][vJob] == 0 && !IsAArendCar(carid)) PlayerTextDrawColor(playerid, speed_prodvin[playerid][24], (vTemp[carid][vEngine])?0x282828FF:0x14DB43FF);
            else if(vTemp[carid][vJob] !=0 || IsAArendCar(carid)) PlayerTextDrawColor(playerid, speed_prodvin[playerid][24], (vTemp[carid][vLock])?0xFFFFFFF:0x14DB43FF);
            PlayerTextDrawUseBox(playerid, speed_prodvin[playerid][24], 0);
            PlayerTextDrawBoxColor(playerid, speed_prodvin[playerid][24], 0x80808080);
            PlayerTextDrawSetShadow(playerid, speed_prodvin[playerid][24], 0);
            PlayerTextDrawSetOutline(playerid, speed_prodvin[playerid][24], 0);
            PlayerTextDrawBackgroundColor(playerid, speed_prodvin[playerid][24], 0x000000FF);
            PlayerTextDrawFont(playerid, speed_prodvin[playerid][24], 2);
            PlayerTextDrawSetProportional(playerid, speed_prodvin[playerid][24], 1);
            PlayerTextDrawSetSelectable(playerid, speed_prodvin[playerid][24], 0);

            speed_prodvin[playerid][23] = CreatePlayerTextDraw(playerid, 582.632996, 392.155304, "C");
            PlayerTextDrawLetterSize(playerid, speed_prodvin[playerid][23], -0.198300, 0.824100);
            PlayerTextDrawTextSize(playerid, speed_prodvin[playerid][23], 1280.0, 1280.0);
            PlayerTextDrawAlignment(playerid, speed_prodvin[playerid][23], 2);
            if(IsAOwnableCar(carid))PlayerTextDrawColor(playerid, speed_prodvin[playerid][23], (CarInfo[number][cLock])?0xFFFFFFF:0x14DB43FF);
            else if(!IsAOwnableCar(carid) && vTemp[carid][vJob] == 0 && !IsAArendCar(carid)) PlayerTextDrawColor(playerid, speed_prodvin[playerid][23], (vTemp[carid][vEngine])?0x282828FF:0x14DB43FF);
            else if(vTemp[carid][vJob] !=0 || IsAArendCar(carid)) PlayerTextDrawColor(playerid, speed_prodvin[playerid][23], (vTemp[carid][vLock])?0xFFFFFFF:0x14DB43FF);
            PlayerTextDrawUseBox(playerid, speed_prodvin[playerid][23], 0);
            PlayerTextDrawBoxColor(playerid, speed_prodvin[playerid][23], 0x80808080);
            PlayerTextDrawSetShadow(playerid, speed_prodvin[playerid][23], 0);
            PlayerTextDrawSetOutline(playerid, speed_prodvin[playerid][23], 0);
            PlayerTextDrawBackgroundColor(playerid, speed_prodvin[playerid][23], 0x000000FF);
            PlayerTextDrawFont(playerid, speed_prodvin[playerid][23], 2);
            PlayerTextDrawSetProportional(playerid, speed_prodvin[playerid][23], 1);
            PlayerTextDrawSetSelectable(playerid, speed_prodvin[playerid][23], 0);

            speed_prodvin[playerid][22] = CreatePlayerTextDraw(playerid, 583.033325, 393.021912, ".");
            PlayerTextDrawLetterSize(playerid, speed_prodvin[playerid][22], 0.167300, 1.010900);
            PlayerTextDrawTextSize(playerid, speed_prodvin[playerid][22], 1280.0, 1280.0);
            PlayerTextDrawAlignment(playerid, speed_prodvin[playerid][22], 2);
            if(IsAOwnableCar(carid))PlayerTextDrawColor(playerid, speed_prodvin[playerid][22], (CarInfo[number][cLock])?0xFFFFFFF:0x14DB43FF);
            else if(!IsAOwnableCar(carid) && vTemp[carid][vJob] == 0 && !IsAArendCar(carid)) PlayerTextDrawColor(playerid, speed_prodvin[playerid][22], (vTemp[carid][vEngine])?0x282828FF:0x14DB43FF);
            else if(vTemp[carid][vJob] !=0 || IsAArendCar(carid)) PlayerTextDrawColor(playerid, speed_prodvin[playerid][22], (vTemp[carid][vLock])?0xFFFFFFF:0x14DB43FF);
            PlayerTextDrawUseBox(playerid, speed_prodvin[playerid][22], 0);
            PlayerTextDrawBoxColor(playerid, speed_prodvin[playerid][22], 0x80808080);
            PlayerTextDrawSetShadow(playerid, speed_prodvin[playerid][22], 0);
            PlayerTextDrawSetOutline(playerid, speed_prodvin[playerid][22], 0);
            PlayerTextDrawBackgroundColor(playerid, speed_prodvin[playerid][22], 0x000000FF);
            PlayerTextDrawFont(playerid, speed_prodvin[playerid][22], 2);
            PlayerTextDrawSetProportional(playerid, speed_prodvin[playerid][22], 1);
            PlayerTextDrawSetSelectable(playerid, speed_prodvin[playerid][22], 0);
            for(new i = 22; i < 25; i++) PlayerTextDrawShow(playerid, speed_prodvin[playerid][i]);
        }
    }
    return 1;
}