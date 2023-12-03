	PAI[playerid][testdrive_td][22] = CreatePlayerTextDraw(playerid, 180.666107, 105.636398, "LD_SPAC:white");
	PlayerTextDrawLetterSize(playerid, PAI[playerid][testdrive_td][22], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, PAI[playerid][testdrive_td][22], 277.000000, 269.000000);
	PlayerTextDrawAlignment(playerid, PAI[playerid][testdrive_td][22], 1);
	PlayerTextDrawColor(playerid, PAI[playerid][testdrive_td][22], 0x1E1E1EFF);
	PlayerTextDrawUseBox(playerid, PAI[playerid][testdrive_td][22], 0);
	PlayerTextDrawBoxColor(playerid, PAI[playerid][testdrive_td][22], 0x80808080);
	PlayerTextDrawSetShadow(playerid, PAI[playerid][testdrive_td][22], 0);
	PlayerTextDrawSetOutline(playerid, PAI[playerid][testdrive_td][22], 0);
	PlayerTextDrawBackgroundColor(playerid, PAI[playerid][testdrive_td][22], 0x000000FF);
	PlayerTextDrawFont(playerid, PAI[playerid][testdrive_td][22], 4);
	PlayerTextDrawSetProportional(playerid, PAI[playerid][testdrive_td][22], 0);
	PlayerTextDrawSetSelectable(playerid, PAI[playerid][testdrive_td][22], 0);

	PAI[playerid][testdrive_td][21] = CreatePlayerTextDraw(playerid, 180.532806, 128.866302, "");
	PlayerTextDrawLetterSize(playerid, PAI[playerid][testdrive_td][21], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, PAI[playerid][testdrive_td][21], 277.299103, 2.000000);
	PlayerTextDrawAlignment(playerid, PAI[playerid][testdrive_td][21], 1);
	PlayerTextDrawColor(playerid, PAI[playerid][testdrive_td][21], 0xA52A2AFF);
	PlayerTextDrawUseBox(playerid, PAI[playerid][testdrive_td][21], 0);
	PlayerTextDrawBoxColor(playerid, PAI[playerid][testdrive_td][21], 0x80808080);
	PlayerTextDrawSetShadow(playerid, PAI[playerid][testdrive_td][21], 0);
	PlayerTextDrawSetOutline(playerid, PAI[playerid][testdrive_td][21], 0);
	PlayerTextDrawBackgroundColor(playerid, PAI[playerid][testdrive_td][21], 0x00000000);
	PlayerTextDrawFont(playerid, PAI[playerid][testdrive_td][21], 5);
	PlayerTextDrawSetProportional(playerid, PAI[playerid][testdrive_td][21], 0);
	PlayerTextDrawSetSelectable(playerid, PAI[playerid][testdrive_td][21], 0);
	PlayerTextDrawSetPreviewModel(playerid, PAI[playerid][testdrive_td][21], 19063);
	PlayerTextDrawSetPreviewRot(playerid, PAI[playerid][testdrive_td][21], 0.000000, 0.000000, 50.000000, 0.234500);

	PAI[playerid][testdrive_td][20] = CreatePlayerTextDraw(playerid, 180.532806, 79.502800, "");
	PlayerTextDrawLetterSize(playerid, PAI[playerid][testdrive_td][20], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, PAI[playerid][testdrive_td][20], 277.269104, 46.000000);
	PlayerTextDrawAlignment(playerid, PAI[playerid][testdrive_td][20], 1);
	PlayerTextDrawColor(playerid, PAI[playerid][testdrive_td][20], 0xA52A2AFF);
	PlayerTextDrawUseBox(playerid, PAI[playerid][testdrive_td][20], 0);
	PlayerTextDrawBoxColor(playerid, PAI[playerid][testdrive_td][20], 0x80808080);
	PlayerTextDrawSetShadow(playerid, PAI[playerid][testdrive_td][20], 0);
	PlayerTextDrawSetOutline(playerid, PAI[playerid][testdrive_td][20], 0);
	PlayerTextDrawBackgroundColor(playerid, PAI[playerid][testdrive_td][20], 0x00000000);
	PlayerTextDrawFont(playerid, PAI[playerid][testdrive_td][20], 5);
	PlayerTextDrawSetProportional(playerid, PAI[playerid][testdrive_td][20], 0);
	PlayerTextDrawSetSelectable(playerid, PAI[playerid][testdrive_td][20], 0);
	PlayerTextDrawSetPreviewModel(playerid, PAI[playerid][testdrive_td][20], 19063);
	PlayerTextDrawSetPreviewRot(playerid, PAI[playerid][testdrive_td][20], 0.000000, 75.000000, 177.000000, 0.234500);

	str_1[0] = EOS;
	switch(listitem)
	{
		case 0: 
		{
			if(PI[playerid][pInvLang]) str_1 = "Œƒ≈∆ƒ€";
			else str_1 = "SKIN";
		}
		case 1..2: 
		{
			if(PI[playerid][pInvLang]) str_1 = "¿ —≈——”¿–Œ¬";
			else str_1 = "ACCESSORIES";
		}
		default:
		{
			if(PI[playerid][pInvLang]) str_1 = "—œŒ–“»¬Õ€…";
			else str_1 = "SPORT";
		}
	}
	PAI[playerid][testdrive_td][19] = CreatePlayerTextDraw(playerid, 224.666504, 103.218201, FixText(str_1));
	PlayerTextDrawLetterSize(playerid, PAI[playerid][testdrive_td][19], 0.291700, 1.350900);
	PlayerTextDrawTextSize(playerid, PAI[playerid][testdrive_td][19], 1280.000000, 1280.000000);
	PlayerTextDrawAlignment(playerid, PAI[playerid][testdrive_td][19], 1);
	PlayerTextDrawColor(playerid, PAI[playerid][testdrive_td][19], 0xFF6E5AFF);
	PlayerTextDrawUseBox(playerid, PAI[playerid][testdrive_td][19], 0);
	PlayerTextDrawBoxColor(playerid, PAI[playerid][testdrive_td][19], 0x80808080);
	PlayerTextDrawSetShadow(playerid, PAI[playerid][testdrive_td][19], 0);
	PlayerTextDrawSetOutline(playerid, PAI[playerid][testdrive_td][19], 0);
	PlayerTextDrawBackgroundColor(playerid, PAI[playerid][testdrive_td][19], 0x000000FF);
	PlayerTextDrawFont(playerid, PAI[playerid][testdrive_td][19], 1);
	PlayerTextDrawSetProportional(playerid, PAI[playerid][testdrive_td][19], 1);
	PlayerTextDrawSetSelectable(playerid, PAI[playerid][testdrive_td][19], 0);
	str_1[0] = EOS;
	switch(listitem)
	{
		case 0..2: 
		{
			if(PI[playerid][pInvLang]) str_1 = "œ–»Ã≈– ¿";
			else str_1 = "FITTING";
		}
		default:
		{
			if(PI[playerid][pInvLang]) str_1 = "—œŒ–“»¬Õ€…";
			else str_1 = "SPORT";
		}
	}
	PAI[playerid][testdrive_td][18] = CreatePlayerTextDraw(playerid, 224.233200, 88.640602, FixText(str_1));
	PlayerTextDrawLetterSize(playerid, PAI[playerid][testdrive_td][18], 0.404100, 1.865300);
	PlayerTextDrawTextSize(playerid, PAI[playerid][testdrive_td][18], 1280.000000, 1280.000000);
	PlayerTextDrawAlignment(playerid, PAI[playerid][testdrive_td][18], 1);
	PlayerTextDrawColor(playerid, PAI[playerid][testdrive_td][18], 0xFFFFFFFF);
	PlayerTextDrawUseBox(playerid, PAI[playerid][testdrive_td][18], 0);
	PlayerTextDrawBoxColor(playerid, PAI[playerid][testdrive_td][18], 0x80808080);
	PlayerTextDrawSetShadow(playerid, PAI[playerid][testdrive_td][18], 0);
	PlayerTextDrawSetOutline(playerid, PAI[playerid][testdrive_td][18], 0);
	PlayerTextDrawBackgroundColor(playerid, PAI[playerid][testdrive_td][18], 0x000000FF);
	PlayerTextDrawFont(playerid, PAI[playerid][testdrive_td][18], 1);
	PlayerTextDrawSetProportional(playerid, PAI[playerid][testdrive_td][18], 1);
	PlayerTextDrawSetSelectable(playerid, PAI[playerid][testdrive_td][18], 0);

	PAI[playerid][testdrive_td][17] = CreatePlayerTextDraw(playerid, 180.666306, 134.673401, "LD_SPAC:white");
	PlayerTextDrawLetterSize(playerid, PAI[playerid][testdrive_td][17], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, PAI[playerid][testdrive_td][17], 277.000000, 233.000000);
	PlayerTextDrawAlignment(playerid, PAI[playerid][testdrive_td][17], 1);
	PlayerTextDrawColor(playerid, PAI[playerid][testdrive_td][17], 0x141414FF);
	PlayerTextDrawUseBox(playerid, PAI[playerid][testdrive_td][17], 0);
	PlayerTextDrawBoxColor(playerid, PAI[playerid][testdrive_td][17], 0x80808080);
	PlayerTextDrawSetShadow(playerid, PAI[playerid][testdrive_td][17], 0);
	PlayerTextDrawSetOutline(playerid, PAI[playerid][testdrive_td][17], 0);
	PlayerTextDrawBackgroundColor(playerid, PAI[playerid][testdrive_td][17], 0x000000FF);
	PlayerTextDrawFont(playerid, PAI[playerid][testdrive_td][17], 4);
	PlayerTextDrawSetProportional(playerid, PAI[playerid][testdrive_td][17], 0);
	PlayerTextDrawSetSelectable(playerid, PAI[playerid][testdrive_td][17], 0);

	PAI[playerid][testdrive_td][16] = CreatePlayerTextDraw(playerid, 193.666702, 85.725700, "LD_BEAT:chit");
	PlayerTextDrawLetterSize(playerid, PAI[playerid][testdrive_td][16], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, PAI[playerid][testdrive_td][16], 31.000000, 36.000000);
	PlayerTextDrawAlignment(playerid, PAI[playerid][testdrive_td][16], 1);
	PlayerTextDrawColor(playerid, PAI[playerid][testdrive_td][16], 0xFFFFFFFF);
	PlayerTextDrawUseBox(playerid, PAI[playerid][testdrive_td][16], 0);
	PlayerTextDrawBoxColor(playerid, PAI[playerid][testdrive_td][16], 0x80808080);
	PlayerTextDrawSetShadow(playerid, PAI[playerid][testdrive_td][16], 0);
	PlayerTextDrawSetOutline(playerid, PAI[playerid][testdrive_td][16], 0);
	PlayerTextDrawBackgroundColor(playerid, PAI[playerid][testdrive_td][16], 0x000000FF);
	PlayerTextDrawFont(playerid, PAI[playerid][testdrive_td][16], 4);
	PlayerTextDrawSetProportional(playerid, PAI[playerid][testdrive_td][16], 0);
	PlayerTextDrawSetSelectable(playerid, PAI[playerid][testdrive_td][16], 0);

	PAI[playerid][testdrive_td][15] = CreatePlayerTextDraw(playerid, 197.800003, 91.118401, "LD_BEAT:chit");
	PlayerTextDrawLetterSize(playerid, PAI[playerid][testdrive_td][15], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, PAI[playerid][testdrive_td][15], 23.000000, 18.000000);
	PlayerTextDrawAlignment(playerid, PAI[playerid][testdrive_td][15], 1);
	PlayerTextDrawColor(playerid, PAI[playerid][testdrive_td][15], 0xA52A2AFF);
	PlayerTextDrawUseBox(playerid, PAI[playerid][testdrive_td][15], 0);
	PlayerTextDrawBoxColor(playerid, PAI[playerid][testdrive_td][15], 0x80808080);
	PlayerTextDrawSetShadow(playerid, PAI[playerid][testdrive_td][15], 0);
	PlayerTextDrawSetOutline(playerid, PAI[playerid][testdrive_td][15], 0);
	PlayerTextDrawBackgroundColor(playerid, PAI[playerid][testdrive_td][15], 0x000000FF);
	PlayerTextDrawFont(playerid, PAI[playerid][testdrive_td][15], 4);
	PlayerTextDrawSetProportional(playerid, PAI[playerid][testdrive_td][15], 0);
	PlayerTextDrawSetSelectable(playerid, PAI[playerid][testdrive_td][15], 0);

	PAI[playerid][testdrive_td][14] = CreatePlayerTextDraw(playerid, 209.799805, 84.222000, "._.");
	PlayerTextDrawLetterSize(playerid, PAI[playerid][testdrive_td][14], 0.505200, 3.549499);
	PlayerTextDrawTextSize(playerid, PAI[playerid][testdrive_td][14], 1280.000000, 1280.000000);
	PlayerTextDrawAlignment(playerid, PAI[playerid][testdrive_td][14], 2);
	PlayerTextDrawColor(playerid, PAI[playerid][testdrive_td][14], 0xA52A2AFF);
	PlayerTextDrawUseBox(playerid, PAI[playerid][testdrive_td][14], 0);
	PlayerTextDrawBoxColor(playerid, PAI[playerid][testdrive_td][14], 0x80808080);
	PlayerTextDrawSetShadow(playerid, PAI[playerid][testdrive_td][14], 0);
	PlayerTextDrawSetOutline(playerid, PAI[playerid][testdrive_td][14], 0);
	PlayerTextDrawBackgroundColor(playerid, PAI[playerid][testdrive_td][14], 0x000000FF);
	PlayerTextDrawFont(playerid, PAI[playerid][testdrive_td][14], 1);
	PlayerTextDrawSetProportional(playerid, PAI[playerid][testdrive_td][14], 1);
	PlayerTextDrawSetSelectable(playerid, PAI[playerid][testdrive_td][14], 0);

	PAI[playerid][testdrive_td][13] = CreatePlayerTextDraw(playerid, 256.000000, 354.681396, "In case of damage, you will pay for the repair");
	PlayerTextDrawLetterSize(playerid, PAI[playerid][testdrive_td][13], 0.184300, 0.874000);
	PlayerTextDrawTextSize(playerid, PAI[playerid][testdrive_td][13], 1280.000000, 1280.000000);
	PlayerTextDrawAlignment(playerid, PAI[playerid][testdrive_td][13], 1);
	PlayerTextDrawColor(playerid, PAI[playerid][testdrive_td][13], 0xFFFFFF4A);
	PlayerTextDrawUseBox(playerid, PAI[playerid][testdrive_td][13], 0);
	PlayerTextDrawBoxColor(playerid, PAI[playerid][testdrive_td][13], 0x80808080);
	PlayerTextDrawSetShadow(playerid, PAI[playerid][testdrive_td][13], 0);
	PlayerTextDrawSetOutline(playerid, PAI[playerid][testdrive_td][13], 0);
	PlayerTextDrawBackgroundColor(playerid, PAI[playerid][testdrive_td][13], 0x000000FF);
	PlayerTextDrawFont(playerid, PAI[playerid][testdrive_td][13], 1);
	PlayerTextDrawSetProportional(playerid, PAI[playerid][testdrive_td][13], 1);
	PlayerTextDrawSetSelectable(playerid, PAI[playerid][testdrive_td][13], 0);

	PAI[playerid][testdrive_td][12] = CreatePlayerTextDraw(playerid, 201.199905, 106.666702, "LD_BEAT:chit");
	PlayerTextDrawLetterSize(playerid, PAI[playerid][testdrive_td][12], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, PAI[playerid][testdrive_td][12], 16.000000, 8.000000);
	PlayerTextDrawAlignment(playerid, PAI[playerid][testdrive_td][12], 1);
	PlayerTextDrawColor(playerid, PAI[playerid][testdrive_td][12], 0xA52A2AFF);
	PlayerTextDrawUseBox(playerid, PAI[playerid][testdrive_td][12], 0);
	PlayerTextDrawBoxColor(playerid, PAI[playerid][testdrive_td][12], 0x80808080);
	PlayerTextDrawSetShadow(playerid, PAI[playerid][testdrive_td][12], 0);
	PlayerTextDrawSetOutline(playerid, PAI[playerid][testdrive_td][12], 0);
	PlayerTextDrawBackgroundColor(playerid, PAI[playerid][testdrive_td][12], 0x000000FF);
	PlayerTextDrawFont(playerid, PAI[playerid][testdrive_td][12], 4);
	PlayerTextDrawSetProportional(playerid, PAI[playerid][testdrive_td][12], 0);
	PlayerTextDrawSetSelectable(playerid, PAI[playerid][testdrive_td][12], 0);

	PAI[playerid][testdrive_td][11] = CreatePlayerTextDraw(playerid, 194.600006, 99.929604, "LD_BEAT:chit");
	PlayerTextDrawLetterSize(playerid, PAI[playerid][testdrive_td][11], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, PAI[playerid][testdrive_td][11], 29.000000, 12.000000);
	PlayerTextDrawAlignment(playerid, PAI[playerid][testdrive_td][11], 1);
	PlayerTextDrawColor(playerid, PAI[playerid][testdrive_td][11], 0xFFFFFFFF);
	PlayerTextDrawUseBox(playerid, PAI[playerid][testdrive_td][11], 0);
	PlayerTextDrawBoxColor(playerid, PAI[playerid][testdrive_td][11], 0x80808080);
	PlayerTextDrawSetShadow(playerid, PAI[playerid][testdrive_td][11], 0);
	PlayerTextDrawSetOutline(playerid, PAI[playerid][testdrive_td][11], 0);
	PlayerTextDrawBackgroundColor(playerid, PAI[playerid][testdrive_td][11], 0x000000FF);
	PlayerTextDrawFont(playerid, PAI[playerid][testdrive_td][11], 4);
	PlayerTextDrawSetProportional(playerid, PAI[playerid][testdrive_td][11], 0);
	PlayerTextDrawSetSelectable(playerid, PAI[playerid][testdrive_td][11], 0);

	PAI[playerid][testdrive_td][10] = CreatePlayerTextDraw(playerid, 320.333313, 141.466507, "ACCESSIBLE_TRANSPORT");
	PlayerTextDrawLetterSize(playerid, PAI[playerid][testdrive_td][10], 0.216600, 1.039800);
	PlayerTextDrawTextSize(playerid, PAI[playerid][testdrive_td][10], 1280.000000, 1280.000000);
	PlayerTextDrawAlignment(playerid, PAI[playerid][testdrive_td][10], 2);
	PlayerTextDrawColor(playerid, PAI[playerid][testdrive_td][10], 0xA35148FF);
	PlayerTextDrawUseBox(playerid, PAI[playerid][testdrive_td][10], 0);
	PlayerTextDrawBoxColor(playerid, PAI[playerid][testdrive_td][10], 0x80808080);
	PlayerTextDrawSetShadow(playerid, PAI[playerid][testdrive_td][10], 0);
	PlayerTextDrawSetOutline(playerid, PAI[playerid][testdrive_td][10], 0);
	PlayerTextDrawBackgroundColor(playerid, PAI[playerid][testdrive_td][10], 0x000000FF);
	PlayerTextDrawFont(playerid, PAI[playerid][testdrive_td][10], 1);
	PlayerTextDrawSetProportional(playerid, PAI[playerid][testdrive_td][10], 1);
	PlayerTextDrawSetSelectable(playerid, PAI[playerid][testdrive_td][10], 0);

	PAI[playerid][testdrive_td][9] = CreatePlayerTextDraw(playerid, 283.599915, 330.051910, "LD_SPAC:white");
	PlayerTextDrawLetterSize(playerid, PAI[playerid][testdrive_td][9], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, PAI[playerid][testdrive_td][9], 35.000000, 16.000000);
	PlayerTextDrawAlignment(playerid, PAI[playerid][testdrive_td][9], 1);
	PlayerTextDrawColor(playerid, PAI[playerid][testdrive_td][9], 0xA52A2AFF);
	PlayerTextDrawUseBox(playerid, PAI[playerid][testdrive_td][9], 0);
	PlayerTextDrawBoxColor(playerid, PAI[playerid][testdrive_td][9], 0x80808080);
	PlayerTextDrawSetShadow(playerid, PAI[playerid][testdrive_td][9], 0);
	PlayerTextDrawSetOutline(playerid, PAI[playerid][testdrive_td][9], 0);
	PlayerTextDrawBackgroundColor(playerid, PAI[playerid][testdrive_td][9], 0x000000FF);
	PlayerTextDrawFont(playerid, PAI[playerid][testdrive_td][9], 4);
	PlayerTextDrawSetProportional(playerid, PAI[playerid][testdrive_td][9], 0);
	PlayerTextDrawSetSelectable(playerid, PAI[playerid][testdrive_td][9], 1);

	PAI[playerid][testdrive_td][8] = CreatePlayerTextDraw(playerid, 320.600006, 330.051910, "LD_SPAC:white");
	PlayerTextDrawLetterSize(playerid, PAI[playerid][testdrive_td][8], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, PAI[playerid][testdrive_td][8], 35.000000, 16.000000);
	PlayerTextDrawAlignment(playerid, PAI[playerid][testdrive_td][8], 1);
	PlayerTextDrawColor(playerid, PAI[playerid][testdrive_td][8], 0xA52A2AFF);
	PlayerTextDrawUseBox(playerid, PAI[playerid][testdrive_td][8], 0);
	PlayerTextDrawBoxColor(playerid, PAI[playerid][testdrive_td][8], 0x80808080);
	PlayerTextDrawSetShadow(playerid, PAI[playerid][testdrive_td][8], 0);
	PlayerTextDrawSetOutline(playerid, PAI[playerid][testdrive_td][8], 0);
	PlayerTextDrawBackgroundColor(playerid, PAI[playerid][testdrive_td][8], 0x000000FF);
	PlayerTextDrawFont(playerid, PAI[playerid][testdrive_td][8], 4);
	PlayerTextDrawSetProportional(playerid, PAI[playerid][testdrive_td][8], 0);
	PlayerTextDrawSetSelectable(playerid, PAI[playerid][testdrive_td][8], 1);

	PAI[playerid][testdrive_td][7] = CreatePlayerTextDraw(playerid, 401.600006, 330.051910, "LD_SPAC:white");
	PlayerTextDrawLetterSize(playerid, PAI[playerid][testdrive_td][7], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, PAI[playerid][testdrive_td][7], 47.000000, 16.000000);
	PlayerTextDrawAlignment(playerid, PAI[playerid][testdrive_td][7], 1);
	PlayerTextDrawColor(playerid, PAI[playerid][testdrive_td][7], 0xA52A2AFF);
	PlayerTextDrawUseBox(playerid, PAI[playerid][testdrive_td][7], 0);
	PlayerTextDrawBoxColor(playerid, PAI[playerid][testdrive_td][7], 0x80808080);
	PlayerTextDrawSetShadow(playerid, PAI[playerid][testdrive_td][7], 0);
	PlayerTextDrawSetOutline(playerid, PAI[playerid][testdrive_td][7], 0);
	PlayerTextDrawBackgroundColor(playerid, PAI[playerid][testdrive_td][7], 0x000000FF);
	PlayerTextDrawFont(playerid, PAI[playerid][testdrive_td][7], 4);
	PlayerTextDrawSetProportional(playerid, PAI[playerid][testdrive_td][7], 0);
	PlayerTextDrawSetSelectable(playerid, PAI[playerid][testdrive_td][7], 1);

	PAI[playerid][testdrive_td][6] = CreatePlayerTextDraw(playerid, 301.000000, 329.577698, "<<<");
	PlayerTextDrawLetterSize(playerid, PAI[playerid][testdrive_td][6], 0.287900, 1.699399);
	PlayerTextDrawTextSize(playerid, PAI[playerid][testdrive_td][6], 1280.000000, 1280.000000);
	PlayerTextDrawAlignment(playerid, PAI[playerid][testdrive_td][6], 2);
	PlayerTextDrawColor(playerid, PAI[playerid][testdrive_td][6], 0xFFFFFFFF);
	PlayerTextDrawUseBox(playerid, PAI[playerid][testdrive_td][6], 0);
	PlayerTextDrawBoxColor(playerid, PAI[playerid][testdrive_td][6], 0x80808080);
	PlayerTextDrawSetShadow(playerid, PAI[playerid][testdrive_td][6], 0);
	PlayerTextDrawSetOutline(playerid, PAI[playerid][testdrive_td][6], 0);
	PlayerTextDrawBackgroundColor(playerid, PAI[playerid][testdrive_td][6], 0x000000FF);
	PlayerTextDrawFont(playerid, PAI[playerid][testdrive_td][6], 1);
	PlayerTextDrawSetProportional(playerid, PAI[playerid][testdrive_td][6], 1);
	PlayerTextDrawSetSelectable(playerid, PAI[playerid][testdrive_td][6], 0);

	PAI[playerid][testdrive_td][5] = CreatePlayerTextDraw(playerid, 338.666504, 329.577698, ">>>");
	PlayerTextDrawLetterSize(playerid, PAI[playerid][testdrive_td][5], 0.287900, 1.699399);
	PlayerTextDrawTextSize(playerid, PAI[playerid][testdrive_td][5], 1280.000000, 1280.000000);
	PlayerTextDrawAlignment(playerid, PAI[playerid][testdrive_td][5], 2);
	PlayerTextDrawColor(playerid, PAI[playerid][testdrive_td][5], 0xFFFFFFFF);
	PlayerTextDrawUseBox(playerid, PAI[playerid][testdrive_td][5], 0);
	PlayerTextDrawBoxColor(playerid, PAI[playerid][testdrive_td][5], 0x80808080);
	PlayerTextDrawSetShadow(playerid, PAI[playerid][testdrive_td][5], 0);
	PlayerTextDrawSetOutline(playerid, PAI[playerid][testdrive_td][5], 0);
	PlayerTextDrawBackgroundColor(playerid, PAI[playerid][testdrive_td][5], 0x000000FF);
	PlayerTextDrawFont(playerid, PAI[playerid][testdrive_td][5], 1);
	PlayerTextDrawSetProportional(playerid, PAI[playerid][testdrive_td][5], 1);
	PlayerTextDrawSetSelectable(playerid, PAI[playerid][testdrive_td][5], 0);

	PAI[playerid][testdrive_td][4] = CreatePlayerTextDraw(playerid, 425.333313, 333.411102, "ACCEPT");
	PlayerTextDrawLetterSize(playerid, PAI[playerid][testdrive_td][4], 0.185200, 0.878099);
	PlayerTextDrawTextSize(playerid, PAI[playerid][testdrive_td][4], 1280.000000, 1280.000000);
	PlayerTextDrawAlignment(playerid, PAI[playerid][testdrive_td][4], 2);
	PlayerTextDrawColor(playerid, PAI[playerid][testdrive_td][4], 0xFFFFFFFF);
	PlayerTextDrawUseBox(playerid, PAI[playerid][testdrive_td][4], 0);
	PlayerTextDrawBoxColor(playerid, PAI[playerid][testdrive_td][4], 0x80808080);
	PlayerTextDrawSetShadow(playerid, PAI[playerid][testdrive_td][4], 0);
	PlayerTextDrawSetOutline(playerid, PAI[playerid][testdrive_td][4], 0);
	PlayerTextDrawBackgroundColor(playerid, PAI[playerid][testdrive_td][4], 0x000000FF);
	PlayerTextDrawFont(playerid, PAI[playerid][testdrive_td][4], 1);
	PlayerTextDrawSetProportional(playerid, PAI[playerid][testdrive_td][4], 1);
	PlayerTextDrawSetSelectable(playerid, PAI[playerid][testdrive_td][4], 0);

	PAI[playerid][testdrive_td][3] = CreatePlayerTextDraw(playerid, 190.533401, 324.399994, "To pay:");
	PlayerTextDrawLetterSize(playerid, PAI[playerid][testdrive_td][3], 0.216600, 1.039800);
	PlayerTextDrawTextSize(playerid, PAI[playerid][testdrive_td][3], 1280.000000, 1280.000000);
	PlayerTextDrawAlignment(playerid, PAI[playerid][testdrive_td][3], 1);
	PlayerTextDrawColor(playerid, PAI[playerid][testdrive_td][3], 0xA35148FF);
	PlayerTextDrawUseBox(playerid, PAI[playerid][testdrive_td][3], 0);
	PlayerTextDrawBoxColor(playerid, PAI[playerid][testdrive_td][3], 0x80808080);
	PlayerTextDrawSetShadow(playerid, PAI[playerid][testdrive_td][3], 0);
	PlayerTextDrawSetOutline(playerid, PAI[playerid][testdrive_td][3], 0);
	PlayerTextDrawBackgroundColor(playerid, PAI[playerid][testdrive_td][3], 0x000000FF);
	PlayerTextDrawFont(playerid, PAI[playerid][testdrive_td][3], 1);
	PlayerTextDrawSetProportional(playerid, PAI[playerid][testdrive_td][3], 1);
	PlayerTextDrawSetSelectable(playerid, PAI[playerid][testdrive_td][3], 0);

	PAI[playerid][testdrive_td][2] = CreatePlayerTextDraw(playerid, 189.533401, 331.037201, "350_000$");
	PlayerTextDrawLetterSize(playerid, PAI[playerid][testdrive_td][2], 0.235499, 1.765900);
	PlayerTextDrawTextSize(playerid, PAI[playerid][testdrive_td][2], 1280.000000, 1280.000000);
	PlayerTextDrawAlignment(playerid, PAI[playerid][testdrive_td][2], 1);
	PlayerTextDrawColor(playerid, PAI[playerid][testdrive_td][2], 0xFFFFFFFF);
	PlayerTextDrawUseBox(playerid, PAI[playerid][testdrive_td][2], 0);
	PlayerTextDrawBoxColor(playerid, PAI[playerid][testdrive_td][2], 0x80808080);
	PlayerTextDrawSetShadow(playerid, PAI[playerid][testdrive_td][2], 0);
	PlayerTextDrawSetOutline(playerid, PAI[playerid][testdrive_td][2], 0);
	PlayerTextDrawBackgroundColor(playerid, PAI[playerid][testdrive_td][2], 0x000000FF);
	PlayerTextDrawFont(playerid, PAI[playerid][testdrive_td][2], 2);
	PlayerTextDrawSetProportional(playerid, PAI[playerid][testdrive_td][2], 1);
	PlayerTextDrawSetSelectable(playerid, PAI[playerid][testdrive_td][2], 0);

	PAI[playerid][testdrive_td][1] = CreatePlayerTextDraw(playerid, 435.933411, 86.140800, "LD_SPAC:white");
	PlayerTextDrawLetterSize(playerid, PAI[playerid][testdrive_td][1], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, PAI[playerid][testdrive_td][1], 13.000000, 13.000000);
	PlayerTextDrawAlignment(playerid, PAI[playerid][testdrive_td][1], 1);
	PlayerTextDrawColor(playerid, PAI[playerid][testdrive_td][1], 0xA52A2AFF);
	PlayerTextDrawUseBox(playerid, PAI[playerid][testdrive_td][1], 0);
	PlayerTextDrawBoxColor(playerid, PAI[playerid][testdrive_td][1], 0x80808080);
	PlayerTextDrawSetShadow(playerid, PAI[playerid][testdrive_td][1], 0);
	PlayerTextDrawSetOutline(playerid, PAI[playerid][testdrive_td][1], 0);
	PlayerTextDrawBackgroundColor(playerid, PAI[playerid][testdrive_td][1], 0x000000FF);
	PlayerTextDrawFont(playerid, PAI[playerid][testdrive_td][1], 4);
	PlayerTextDrawSetProportional(playerid, PAI[playerid][testdrive_td][1], 0);
	PlayerTextDrawSetSelectable(playerid, PAI[playerid][testdrive_td][1], 1);

	PAI[playerid][testdrive_td][0] = CreatePlayerTextDraw(playerid, 442.866394, 86.081299, "X");
	PlayerTextDrawLetterSize(playerid, PAI[playerid][testdrive_td][0], 0.258500, 1.243100);
	PlayerTextDrawTextSize(playerid, PAI[playerid][testdrive_td][0], 1280.000000, 1280.000000);
	PlayerTextDrawAlignment(playerid, PAI[playerid][testdrive_td][0], 2);
	PlayerTextDrawColor(playerid, PAI[playerid][testdrive_td][0], 0xFFFFFFFF);
	PlayerTextDrawUseBox(playerid, PAI[playerid][testdrive_td][0], 0);
	PlayerTextDrawBoxColor(playerid, PAI[playerid][testdrive_td][0], 0x80808080);
	PlayerTextDrawSetShadow(playerid, PAI[playerid][testdrive_td][0], 0);
	PlayerTextDrawSetOutline(playerid, PAI[playerid][testdrive_td][0], 0);
	PlayerTextDrawBackgroundColor(playerid, PAI[playerid][testdrive_td][0], 0x000000FF);
	PlayerTextDrawFont(playerid, PAI[playerid][testdrive_td][0], 2);
	PlayerTextDrawSetProportional(playerid, PAI[playerid][testdrive_td][0], 1);
	PlayerTextDrawSetSelectable(playerid, PAI[playerid][testdrive_td][0], 0);
