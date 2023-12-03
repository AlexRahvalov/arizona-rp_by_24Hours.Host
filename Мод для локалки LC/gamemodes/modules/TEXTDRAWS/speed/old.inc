		for(new i; i<4; i++)TextDrawShowForPlayer(playerid, speedbox[i]);
		new carid = GetPlayerVehicleID(playerid);
		new number = GetVehicleID(carid);
		new color;
		if(IsAOwnableCar(number))
		{
		    if(CarInfo[number][cLock])color=-1407312129;
		    else color=576000767;
		}
		else
		{
		    if(vTemp[carid][vJob]!=0 || IsAArendCar(carid) )
		    {
		        if(vTemp[carid][vLock])color=-1407312129;
		        else color=576000767;
		    }
		    else color=576000767;
		}
		speeddraw[playerid][0] = CreatePlayerTextDraw(playerid, 531.000000, 396.000000, "lock");
		PlayerTextDrawAlignment(playerid, speeddraw[playerid][0], 2);
		PlayerTextDrawBackgroundColor(playerid, speeddraw[playerid][0], 255);
		PlayerTextDrawFont(playerid, speeddraw[playerid][0], 2);
		PlayerTextDrawLetterSize(playerid, speeddraw[playerid][0], 0.239998, 1.600000);
		PlayerTextDrawColor(playerid, speeddraw[playerid][0], -1);
		PlayerTextDrawSetOutline(playerid, speeddraw[playerid][0], 0);
		PlayerTextDrawSetProportional(playerid, speeddraw[playerid][0], 1);
		PlayerTextDrawSetShadow(playerid, speeddraw[playerid][0], 1);
		PlayerTextDrawUseBox(playerid, speeddraw[playerid][0], 1);
		PlayerTextDrawBoxColor(playerid, speeddraw[playerid][0], color);//
		PlayerTextDrawTextSize(playerid, speeddraw[playerid][0], 241.000000, 28.000000);
		PlayerTextDrawSetSelectable(playerid, speeddraw[playerid][0], 0);

		speeddraw[playerid][1] = CreatePlayerTextDraw(playerid, 567.000000, 396.000000, "light");
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
		PlayerTextDrawTextSize(playerid, speeddraw[playerid][1], 241.000000, 30.000000);
		PlayerTextDrawSetSelectable(playerid, speeddraw[playerid][1], 0);

		speeddraw[playerid][2] = CreatePlayerTextDraw(playerid, 603.000000, 396.000000, "eng");
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
		PlayerTextDrawTextSize(playerid, speeddraw[playerid][2], 241.000000, 28.000000);
		PlayerTextDrawSetSelectable(playerid, speeddraw[playerid][2], 0);

		speeddraw[playerid][3] = CreatePlayerTextDraw(playerid, 515.000000, 353.000000, "_");
		PlayerTextDrawBackgroundColor(playerid, speeddraw[playerid][3], 255);
		PlayerTextDrawFont(playerid, speeddraw[playerid][3], 1);
		PlayerTextDrawLetterSize(playerid, speeddraw[playerid][3], 0.660000, 4.099999);
		PlayerTextDrawColor(playerid, speeddraw[playerid][3], -65);
		PlayerTextDrawSetOutline(playerid, speeddraw[playerid][3], 1);
		PlayerTextDrawSetProportional(playerid, speeddraw[playerid][3], 1);
		PlayerTextDrawSetSelectable(playerid, speeddraw[playerid][3], 0);

		speeddraw[playerid][4] = CreatePlayerTextDraw(playerid, 619.000000, 362.000000, "000");
		PlayerTextDrawAlignment(playerid, speeddraw[playerid][4], 3);
		PlayerTextDrawBackgroundColor(playerid, speeddraw[playerid][4], 255);
		PlayerTextDrawFont(playerid, speeddraw[playerid][4], 3);
		PlayerTextDrawLetterSize(playerid, speeddraw[playerid][4], 0.490000, 2.100002);
		PlayerTextDrawColor(playerid, speeddraw[playerid][4], -65);
		PlayerTextDrawSetOutline(playerid, speeddraw[playerid][4], 1);
		PlayerTextDrawSetProportional(playerid, speeddraw[playerid][4], 1);
		PlayerTextDrawSetSelectable(playerid, speeddraw[playerid][4], 0);

		f(str_1, 50, "fuel: %.0f%", vTemp[carid][Fuel]);
		speeddraw[playerid][5] = CreatePlayerTextDraw(playerid, 621.000000, 430.000000, str_1);
		PlayerTextDrawAlignment(playerid, speeddraw[playerid][5], 3);
		PlayerTextDrawBackgroundColor(playerid, speeddraw[playerid][5], 255);
		PlayerTextDrawFont(playerid, speeddraw[playerid][5], 3);
		PlayerTextDrawLetterSize(playerid, speeddraw[playerid][5], 0.270000, 1.500000);
		PlayerTextDrawColor(playerid, speeddraw[playerid][5], -34);
		PlayerTextDrawSetOutline(playerid, speeddraw[playerid][5], 1);
		PlayerTextDrawSetProportional(playerid, speeddraw[playerid][5], 1);
		PlayerTextDrawSetSelectable(playerid, speeddraw[playerid][5], 0);

		static temptext[56];
		if(IsAOwnableCar(number)) f(temptext, sizeof(temptext), "%08.0f", CarInfo[number][cMilage]); f(temptext, sizeof(temptext), "00000000");
		speeddraw[playerid][6] = CreatePlayerTextDraw(playerid, 515.000000, 430.000000, temptext);
		PlayerTextDrawBackgroundColor(playerid, speeddraw[playerid][6], 255);
		PlayerTextDrawFont(playerid, speeddraw[playerid][6], 3);
		PlayerTextDrawLetterSize(playerid, speeddraw[playerid][6], 0.270000, 1.500000);
		PlayerTextDrawColor(playerid, speeddraw[playerid][6], -34);
		PlayerTextDrawSetOutline(playerid, speeddraw[playerid][6], 1);
		PlayerTextDrawSetProportional(playerid, speeddraw[playerid][6], 1);
		PlayerTextDrawSetSelectable(playerid, speeddraw[playerid][6], 0);
		new iand = (IsAOwnableCar(number))?7:6;
		for(new i; i < iand ; i++) PlayerTextDrawShow(playerid, speeddraw[playerid][i]);