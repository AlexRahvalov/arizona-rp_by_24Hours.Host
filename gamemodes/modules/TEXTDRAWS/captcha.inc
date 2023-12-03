    captch_PTD[playerid][0] = CreatePlayerTextDraw(playerid, 234.9998 + captch_x, 201.0442 + captch_y, "LD_SPAC:white");
    captch_PTD[playerid][1] = CreatePlayerTextDraw(playerid, 237.9998 + captch_x, 205.1923 + captch_y, "LD_SPAC:white");
    
    enum td_info
    {
        Float:pos_x,
		Float:pos_x_plus,
        Float:pos_y
    };
    new captch_code_PTD_info[][td_info] =
    {
        //1 цифра
        {246.6666, -8.0, 209.0815},
        {269.4012, -8.0, 208.5110},
        {246.5346, -8.0, 208.5110},
        {246.5346, -8.0, 256.6484},
        {246.4346, -8.0, 233.0471},
        {246.6666, -8.0, 232.4681},
        {269.4012, -8.0, 232.9273},
        //2 цифра
        {277.6015, -6.0, 209.0815},
        {300.3363, -12.0, 208.5110},
        {277.8030, -6.0, 208.5110},
        {277.4696, -6.0, 256.6484},
        {277.3695, -6.0, 233.0471},
        {277.6016, -6.0, 232.4681},
        {300.3363, -12.0, 232.9273},
        //3 цифра
        {305.2366, -6.0, 208.6667},
        {328.6380, -6.0, 208.5110},
        {305.1047, -6.0, 208.5110},
        {305.7713, -6.0, 256.6484},
        {305.6712, -6.0, 233.0471},
        {305.2366, -6.0, 233.7126},
        {328.6380, -6.0, 232.5124},
        //4 цифра
        {334.8500, 0.0, 209.4963},
        {358.5731, 0.0, 209.3407},
        {334.7064, 0.0, 209.3406},
        {335.3730, 0.0, 255.4040},
        {336.6063, 0.0, 232.6323},
        {334.5049, 0.0, 232.4681},
        {358.5731, 0.0, 234.5865},
        //5 цифра
        {365.6401, 1.0, 209.4963},
        {391.0414, 1.0, 209.3407},
        {367.1748, 1.0, 209.3406},
        {367.1748, 1.0, 255.4040},
        {367.1748, 1.0, 232.6323},
        {365.6400, 1.0, 232.4681},
        {391.0414, 1.0, 234.5865}
    };
    new captch_random_cycle_i[5] = {3, 1, 4, 0, 2};
    new captch_random_cycle_d[7] = {4, 0, 3, 6, 1, 2, 5};
    for(new i; i < 5; i++)
    {
        new i_cycle = captch_random_cycle_i[i];
    	for(new d; d < 7; d++)
    	{
        	new d_cycle = captch_random_cycle_d[d];
    	    new info = d_cycle + (7 * i_cycle);
    		captch_code_PTD[playerid][i_cycle][d_cycle] = CreatePlayerTextDraw(playerid, captch_code_PTD_info[info][pos_x] + captch_x+X+captch_code_PTD_info[info][pos_x_plus], captch_code_PTD_info[info][pos_y] + captch_y+X, "LD_SPAC:white");
        }
    }
    
    PlayerTextDrawTextSize(playerid, captch_PTD[playerid][0], 173.0000, 74.0000);
    PlayerTextDrawAlignment(playerid, captch_PTD[playerid][0], 1);
    PlayerTextDrawColor(playerid, captch_PTD[playerid][0], 0x1A2432FF);
    PlayerTextDrawBackgroundColor(playerid, captch_PTD[playerid][0], 255);
    PlayerTextDrawFont(playerid, captch_PTD[playerid][0], 4);
    PlayerTextDrawSetProportional(playerid, captch_PTD[playerid][0], 0);
    PlayerTextDrawSetShadow(playerid, captch_PTD[playerid][0], 1);

    PlayerTextDrawTextSize(playerid, captch_PTD[playerid][1], 167.0000, 66.0000);
    PlayerTextDrawAlignment(playerid, captch_PTD[playerid][1], 1);
    PlayerTextDrawColor(playerid, captch_PTD[playerid][1], 0x759DA3FF);
    PlayerTextDrawBackgroundColor(playerid, captch_PTD[playerid][1], 255);
    PlayerTextDrawFont(playerid, captch_PTD[playerid][1], 4);
    PlayerTextDrawSetProportional(playerid, captch_PTD[playerid][1], 0);
    PlayerTextDrawSetShadow(playerid, captch_PTD[playerid][1], 1);

    PlayerTextDrawTextSize(playerid, captch_code_PTD[playerid][0][0], 5.0000+X, 25.0000+X);
    PlayerTextDrawAlignment(playerid, captch_code_PTD[playerid][0][0], 1);
    PlayerTextDrawColor(playerid, captch_code_PTD[playerid][0][0], 0x1A2432FF);
    PlayerTextDrawBackgroundColor(playerid, captch_code_PTD[playerid][2][0], 255);
    PlayerTextDrawFont(playerid, captch_code_PTD[playerid][0][0], 4);
    PlayerTextDrawSetProportional(playerid, captch_code_PTD[playerid][0][0], 0);
    PlayerTextDrawSetShadow(playerid, captch_code_PTD[playerid][0][0], 1);

    PlayerTextDrawTextSize(playerid, captch_code_PTD[playerid][0][1], 5.0000+X, 25.0000+X);
    PlayerTextDrawAlignment(playerid, captch_code_PTD[playerid][0][1], 1);
    PlayerTextDrawColor(playerid, captch_code_PTD[playerid][0][1], 0x1A2432FF);
    PlayerTextDrawBackgroundColor(playerid, captch_code_PTD[playerid][0][1], 255);
    PlayerTextDrawFont(playerid, captch_code_PTD[playerid][0][1], 4);
    PlayerTextDrawSetProportional(playerid, captch_code_PTD[playerid][0][1], 0);
    PlayerTextDrawSetShadow(playerid, captch_code_PTD[playerid][0][1], 1);

    PlayerTextDrawTextSize(playerid, captch_code_PTD[playerid][0][2], 27.0000+X, 5.0000+X);
    PlayerTextDrawAlignment(playerid, captch_code_PTD[playerid][0][2], 1);
    PlayerTextDrawColor(playerid, captch_code_PTD[playerid][0][2], 0x1A2432FF);
    PlayerTextDrawBackgroundColor(playerid, captch_code_PTD[playerid][0][2], 255);
    PlayerTextDrawFont(playerid, captch_code_PTD[playerid][0][2], 4);
    PlayerTextDrawSetProportional(playerid, captch_code_PTD[playerid][0][2], 0);
    PlayerTextDrawSetShadow(playerid, captch_code_PTD[playerid][0][2], 1);

    PlayerTextDrawTextSize(playerid, captch_code_PTD[playerid][0][3], 25.0000+X, 5.0000+X);
    PlayerTextDrawAlignment(playerid, captch_code_PTD[playerid][0][3], 1);
    PlayerTextDrawColor(playerid, captch_code_PTD[playerid][0][3], 0x1A2432FF);
    PlayerTextDrawBackgroundColor(playerid, captch_code_PTD[playerid][0][3], 255);
    PlayerTextDrawFont(playerid, captch_code_PTD[playerid][0][3], 4);
    PlayerTextDrawSetProportional(playerid, captch_code_PTD[playerid][0][3], 0);
    PlayerTextDrawSetShadow(playerid, captch_code_PTD[playerid][0][3], 1);

    PlayerTextDrawTextSize(playerid, captch_code_PTD[playerid][0][4], 27.0000+X, 5.0000+X);
    PlayerTextDrawAlignment(playerid, captch_code_PTD[playerid][0][4], 1);
    PlayerTextDrawColor(playerid, captch_code_PTD[playerid][0][4], 0x1A2432FF);
    PlayerTextDrawBackgroundColor(playerid, captch_code_PTD[playerid][0][4], 255);
    PlayerTextDrawFont(playerid, captch_code_PTD[playerid][0][4], 4);
    PlayerTextDrawSetProportional(playerid, captch_code_PTD[playerid][0][4], 0);
    PlayerTextDrawSetShadow(playerid, captch_code_PTD[playerid][0][4], 1);

    PlayerTextDrawTextSize(playerid, captch_code_PTD[playerid][0][5], 5.0000+X, 24.0000+X);
    PlayerTextDrawAlignment(playerid, captch_code_PTD[playerid][0][5], 1);
    PlayerTextDrawColor(playerid, captch_code_PTD[playerid][0][5], 0x1A2432FF);
    PlayerTextDrawBackgroundColor(playerid, captch_code_PTD[playerid][0][5], 255);
    PlayerTextDrawFont(playerid, captch_code_PTD[playerid][0][5], 4);
    PlayerTextDrawSetProportional(playerid, captch_code_PTD[playerid][0][5], 0);
    PlayerTextDrawSetShadow(playerid, captch_code_PTD[playerid][0][5], 1);

    PlayerTextDrawTextSize(playerid, captch_code_PTD[playerid][0][6], 5.0000+X, 27.8000+X);
    PlayerTextDrawAlignment(playerid, captch_code_PTD[playerid][0][6], 1);
    PlayerTextDrawColor(playerid, captch_code_PTD[playerid][0][6], 0x1A2432FF);
    PlayerTextDrawBackgroundColor(playerid, captch_code_PTD[playerid][0][6], 255);
    PlayerTextDrawFont(playerid, captch_code_PTD[playerid][0][6], 4);
    PlayerTextDrawSetProportional(playerid, captch_code_PTD[playerid][0][6], 0);
    PlayerTextDrawSetShadow(playerid, captch_code_PTD[playerid][0][6], 1);

    PlayerTextDrawTextSize(playerid, captch_code_PTD[playerid][1][0], 5.0000+X, 25.0000+X);
    PlayerTextDrawAlignment(playerid, captch_code_PTD[playerid][1][0], 1);
    PlayerTextDrawColor(playerid, captch_code_PTD[playerid][1][0], 0x1A2432FF);
    PlayerTextDrawBackgroundColor(playerid, captch_code_PTD[playerid][1][0], 255);
    PlayerTextDrawFont(playerid, captch_code_PTD[playerid][1][0], 4);
    PlayerTextDrawSetProportional(playerid, captch_code_PTD[playerid][1][0], 0);
    PlayerTextDrawSetShadow(playerid, captch_code_PTD[playerid][1][0], 1);

    PlayerTextDrawTextSize(playerid, captch_code_PTD[playerid][1][1], 5.0000+X, 25.0000+X);
    PlayerTextDrawAlignment(playerid, captch_code_PTD[playerid][1][1], 1);
    PlayerTextDrawColor(playerid, captch_code_PTD[playerid][1][1], 0x1A2432FF);
    PlayerTextDrawBackgroundColor(playerid, captch_code_PTD[playerid][1][1], 255);
    PlayerTextDrawFont(playerid, captch_code_PTD[playerid][1][1], 4);
    PlayerTextDrawSetProportional(playerid, captch_code_PTD[playerid][1][1], 0);
    PlayerTextDrawSetShadow(playerid, captch_code_PTD[playerid][1][1], 1);

    PlayerTextDrawTextSize(playerid, captch_code_PTD[playerid][1][2], 20.0000+X, 5.0000+X);
    PlayerTextDrawAlignment(playerid, captch_code_PTD[playerid][1][2], 1);
    PlayerTextDrawColor(playerid, captch_code_PTD[playerid][1][2], 0x1A2432FF);
    PlayerTextDrawBackgroundColor(playerid, captch_code_PTD[playerid][1][2], 255);
    PlayerTextDrawFont(playerid, captch_code_PTD[playerid][1][2], 4);
    PlayerTextDrawSetProportional(playerid, captch_code_PTD[playerid][1][2], 0);
    PlayerTextDrawSetShadow(playerid, captch_code_PTD[playerid][1][2], 1);

    PlayerTextDrawTextSize(playerid, captch_code_PTD[playerid][1][3], 22.0000+X, 5.0000+X);
    PlayerTextDrawAlignment(playerid, captch_code_PTD[playerid][1][3], 1);
    PlayerTextDrawColor(playerid, captch_code_PTD[playerid][1][3], 0x1A2432FF);
    PlayerTextDrawBackgroundColor(playerid, captch_code_PTD[playerid][1][3], 255);
    PlayerTextDrawFont(playerid, captch_code_PTD[playerid][1][3], 4);
    PlayerTextDrawSetProportional(playerid, captch_code_PTD[playerid][1][3], 0);
    PlayerTextDrawSetShadow(playerid, captch_code_PTD[playerid][1][3], 1);

    PlayerTextDrawTextSize(playerid, captch_code_PTD[playerid][1][4], 23.0000+X, 5.0000+X);
    PlayerTextDrawAlignment(playerid, captch_code_PTD[playerid][1][4], 1);
    PlayerTextDrawColor(playerid, captch_code_PTD[playerid][1][4], 0x1A2432FF);
    PlayerTextDrawBackgroundColor(playerid, captch_code_PTD[playerid][1][4], 255);
    PlayerTextDrawFont(playerid, captch_code_PTD[playerid][1][4], 4);
    PlayerTextDrawSetProportional(playerid, captch_code_PTD[playerid][1][4], 0);
    PlayerTextDrawSetShadow(playerid, captch_code_PTD[playerid][1][4], 1);

    PlayerTextDrawTextSize(playerid, captch_code_PTD[playerid][1][5], 5.0000+X, 25.0000+X);
    PlayerTextDrawAlignment(playerid, captch_code_PTD[playerid][1][5], 1);
    PlayerTextDrawColor(playerid, captch_code_PTD[playerid][1][5], 0x1A2432FF);
    PlayerTextDrawBackgroundColor(playerid, captch_code_PTD[playerid][1][5], 255);
    PlayerTextDrawFont(playerid, captch_code_PTD[playerid][1][5], 4);
    PlayerTextDrawSetProportional(playerid, captch_code_PTD[playerid][1][5], 0);
    PlayerTextDrawSetShadow(playerid, captch_code_PTD[playerid][1][5], 1);

    PlayerTextDrawTextSize(playerid, captch_code_PTD[playerid][1][6], 5.0000+X, 27.6500+X);
    PlayerTextDrawAlignment(playerid, captch_code_PTD[playerid][1][6], 1);
    PlayerTextDrawColor(playerid, captch_code_PTD[playerid][1][6], 0x1A2432FF);
    PlayerTextDrawBackgroundColor(playerid, captch_code_PTD[playerid][1][6], 255);
    PlayerTextDrawFont(playerid, captch_code_PTD[playerid][1][6], 4);
    PlayerTextDrawSetProportional(playerid, captch_code_PTD[playerid][1][6], 0);
    PlayerTextDrawSetShadow(playerid, captch_code_PTD[playerid][1][6], 1);

    PlayerTextDrawTextSize(playerid, captch_code_PTD[playerid][2][0], 5.0000+X, 26.0000+X);
    PlayerTextDrawAlignment(playerid, captch_code_PTD[playerid][2][0], 1);
    PlayerTextDrawColor(playerid, captch_code_PTD[playerid][2][0], 0x1A2432FF);
    PlayerTextDrawBackgroundColor(playerid, captch_code_PTD[playerid][2][0], 255);
    PlayerTextDrawFont(playerid, captch_code_PTD[playerid][2][0], 4);
    PlayerTextDrawSetProportional(playerid, captch_code_PTD[playerid][2][0], 0);
    PlayerTextDrawSetShadow(playerid, captch_code_PTD[playerid][2][0], 1);

    PlayerTextDrawTextSize(playerid, captch_code_PTD[playerid][2][1], 5.0000+X, 26.0000+X);
    PlayerTextDrawAlignment(playerid, captch_code_PTD[playerid][2][1], 1);
    PlayerTextDrawColor(playerid, captch_code_PTD[playerid][2][1], 0x1A2432FF);
    PlayerTextDrawBackgroundColor(playerid, captch_code_PTD[playerid][2][1], 255);
    PlayerTextDrawFont(playerid, captch_code_PTD[playerid][2][1], 4);
    PlayerTextDrawSetProportional(playerid, captch_code_PTD[playerid][2][1], 0);
    PlayerTextDrawSetShadow(playerid, captch_code_PTD[playerid][2][1], 1);

    PlayerTextDrawTextSize(playerid, captch_code_PTD[playerid][2][2], 26.0000+X, 5.0000+X);
    PlayerTextDrawAlignment(playerid, captch_code_PTD[playerid][2][2], 1);
    PlayerTextDrawColor(playerid, captch_code_PTD[playerid][2][2], 0x1A2432FF);
    PlayerTextDrawBackgroundColor(playerid, captch_code_PTD[playerid][2][2], 255);
    PlayerTextDrawFont(playerid, captch_code_PTD[playerid][2][2], 4);
    PlayerTextDrawSetProportional(playerid, captch_code_PTD[playerid][2][2], 0);
    PlayerTextDrawSetShadow(playerid, captch_code_PTD[playerid][2][2], 1);

    PlayerTextDrawTextSize(playerid, captch_code_PTD[playerid][2][3], 26.0000+X, 5.0000+X);
    PlayerTextDrawAlignment(playerid, captch_code_PTD[playerid][2][3], 1);
    PlayerTextDrawColor(playerid, captch_code_PTD[playerid][2][3], 0x1A2432FF);
    PlayerTextDrawBackgroundColor(playerid, captch_code_PTD[playerid][2][3], 255);
    PlayerTextDrawFont(playerid, captch_code_PTD[playerid][2][3], 4);
    PlayerTextDrawSetProportional(playerid, captch_code_PTD[playerid][2][3], 0);
    PlayerTextDrawSetShadow(playerid, captch_code_PTD[playerid][2][3], 1);

    PlayerTextDrawTextSize(playerid, captch_code_PTD[playerid][2][4], 26.0000+X, 5.0000+X);
    PlayerTextDrawAlignment(playerid, captch_code_PTD[playerid][2][4], 1);
    PlayerTextDrawColor(playerid, captch_code_PTD[playerid][2][4], 0x1A2432FF);
    PlayerTextDrawBackgroundColor(playerid, captch_code_PTD[playerid][2][4], 255);
    PlayerTextDrawFont(playerid, captch_code_PTD[playerid][2][4], 4);
    PlayerTextDrawSetProportional(playerid, captch_code_PTD[playerid][2][4], 0);
    PlayerTextDrawSetShadow(playerid, captch_code_PTD[playerid][2][4], 1);

    PlayerTextDrawTextSize(playerid, captch_code_PTD[playerid][2][5], 5.0000+X, 26.0000+X);
    PlayerTextDrawAlignment(playerid, captch_code_PTD[playerid][2][5], 1);
    PlayerTextDrawColor(playerid, captch_code_PTD[playerid][2][5], 0x1A2432FF);
    PlayerTextDrawBackgroundColor(playerid, captch_code_PTD[playerid][2][5], 255);
    PlayerTextDrawFont(playerid, captch_code_PTD[playerid][2][5], 4);
    PlayerTextDrawSetProportional(playerid, captch_code_PTD[playerid][2][5], 0);
    PlayerTextDrawSetShadow(playerid, captch_code_PTD[playerid][2][5], 1);

    PlayerTextDrawTextSize(playerid, captch_code_PTD[playerid][2][6], 5.0000+X, 28.5000+X);
    PlayerTextDrawAlignment(playerid, captch_code_PTD[playerid][2][6], 1);
    PlayerTextDrawColor(playerid, captch_code_PTD[playerid][2][6], 0x1A2432FF);
    PlayerTextDrawBackgroundColor(playerid, captch_code_PTD[playerid][2][6], 255);
    PlayerTextDrawFont(playerid, captch_code_PTD[playerid][2][6], 4);
    PlayerTextDrawSetProportional(playerid, captch_code_PTD[playerid][2][6], 0);
    PlayerTextDrawSetShadow(playerid, captch_code_PTD[playerid][2][6], 1);

    PlayerTextDrawTextSize(playerid, captch_code_PTD[playerid][3][0], 4.0000+X, 26.2000+X);
    PlayerTextDrawAlignment(playerid, captch_code_PTD[playerid][3][0], 1);
    PlayerTextDrawColor(playerid, captch_code_PTD[playerid][3][0], 0x1A2432FF);
    PlayerTextDrawBackgroundColor(playerid, captch_code_PTD[playerid][3][0], 255);
    PlayerTextDrawFont(playerid, captch_code_PTD[playerid][3][0], 4);
    PlayerTextDrawSetProportional(playerid, captch_code_PTD[playerid][3][0], 0);
    PlayerTextDrawSetShadow(playerid, captch_code_PTD[playerid][3][0], 1);

    PlayerTextDrawTextSize(playerid, captch_code_PTD[playerid][3][1], 4.0000+X, 26.0000+X);
    PlayerTextDrawAlignment(playerid, captch_code_PTD[playerid][3][1], 1);
    PlayerTextDrawColor(playerid, captch_code_PTD[playerid][3][1], 0x1A2432FF);
    PlayerTextDrawBackgroundColor(playerid, captch_code_PTD[playerid][3][1], 255);
    PlayerTextDrawFont(playerid, captch_code_PTD[playerid][3][1], 4);
    PlayerTextDrawSetProportional(playerid, captch_code_PTD[playerid][3][1], 0);
    PlayerTextDrawSetShadow(playerid, captch_code_PTD[playerid][3][1], 1);

    PlayerTextDrawTextSize(playerid, captch_code_PTD[playerid][3][2], 25.0000+X, 4.0000+X);
    PlayerTextDrawAlignment(playerid, captch_code_PTD[playerid][3][2], 1);
    PlayerTextDrawColor(playerid, captch_code_PTD[playerid][3][2], 0x1A2432FF);
    PlayerTextDrawBackgroundColor(playerid, captch_code_PTD[playerid][3][2], 255);
    PlayerTextDrawFont(playerid, captch_code_PTD[playerid][3][2], 4);
    PlayerTextDrawSetProportional(playerid, captch_code_PTD[playerid][3][2], 0);
    PlayerTextDrawSetShadow(playerid, captch_code_PTD[playerid][3][2], 1);

    PlayerTextDrawTextSize(playerid, captch_code_PTD[playerid][3][3], 25.0000+X, 4.0000+X);
    PlayerTextDrawAlignment(playerid, captch_code_PTD[playerid][3][3], 1);
    PlayerTextDrawColor(playerid, captch_code_PTD[playerid][3][3], 0x1A2432FF);
    PlayerTextDrawBackgroundColor(playerid, captch_code_PTD[playerid][3][3], 255);
    PlayerTextDrawFont(playerid, captch_code_PTD[playerid][3][3], 4);
    PlayerTextDrawSetProportional(playerid, captch_code_PTD[playerid][3][3], 0);
    PlayerTextDrawSetShadow(playerid, captch_code_PTD[playerid][3][3], 1);

    PlayerTextDrawTextSize(playerid, captch_code_PTD[playerid][3][4], 26.0000+X, 4.0000+X);
    PlayerTextDrawAlignment(playerid, captch_code_PTD[playerid][3][4], 1);
    PlayerTextDrawColor(playerid, captch_code_PTD[playerid][3][4], 0x1A2432FF);
    PlayerTextDrawBackgroundColor(playerid, captch_code_PTD[playerid][3][4], 255);
    PlayerTextDrawFont(playerid, captch_code_PTD[playerid][3][4], 4);
    PlayerTextDrawSetProportional(playerid, captch_code_PTD[playerid][3][4], 0);
    PlayerTextDrawSetShadow(playerid, captch_code_PTD[playerid][3][4], 1);

    PlayerTextDrawTextSize(playerid, captch_code_PTD[playerid][3][5], 4.0000+X, 27.0000+X);
    PlayerTextDrawAlignment(playerid, captch_code_PTD[playerid][3][5], 1);
    PlayerTextDrawColor(playerid, captch_code_PTD[playerid][3][5], 0x1A2432FF);
    PlayerTextDrawBackgroundColor(playerid, captch_code_PTD[playerid][3][5], 255);
    PlayerTextDrawFont(playerid, captch_code_PTD[playerid][3][5], 4);
    PlayerTextDrawSetProportional(playerid, captch_code_PTD[playerid][3][5], 0);
    PlayerTextDrawSetShadow(playerid, captch_code_PTD[playerid][3][5], 1);

    PlayerTextDrawTextSize(playerid, captch_code_PTD[playerid][3][6], 4.0000+X, 25.0000+X);
    PlayerTextDrawAlignment(playerid, captch_code_PTD[playerid][3][6], 1);
    PlayerTextDrawColor(playerid, captch_code_PTD[playerid][3][6], 0x1A2432FF);
    PlayerTextDrawBackgroundColor(playerid, captch_code_PTD[playerid][3][6], 255);
    PlayerTextDrawFont(playerid, captch_code_PTD[playerid][3][6], 4);
    PlayerTextDrawSetProportional(playerid, captch_code_PTD[playerid][3][6], 0);
    PlayerTextDrawSetShadow(playerid, captch_code_PTD[playerid][3][6], 1);

    PlayerTextDrawTextSize(playerid, captch_code_PTD[playerid][4][0], 4.0000+X, 27.8500+1.5);
    PlayerTextDrawAlignment(playerid, captch_code_PTD[playerid][4][0], 1);
    PlayerTextDrawColor(playerid, captch_code_PTD[playerid][4][0], 0x1A2432FF);
    PlayerTextDrawBackgroundColor(playerid, captch_code_PTD[playerid][4][0], 255);
    PlayerTextDrawFont(playerid, captch_code_PTD[playerid][4][0], 4);
    PlayerTextDrawSetProportional(playerid, captch_code_PTD[playerid][4][0], 0);
    PlayerTextDrawSetShadow(playerid, captch_code_PTD[playerid][4][0], 1);

    PlayerTextDrawTextSize(playerid, captch_code_PTD[playerid][4][1], 4.0000+X, 25.0000+X);
    PlayerTextDrawAlignment(playerid, captch_code_PTD[playerid][4][1], 1);
    PlayerTextDrawColor(playerid, captch_code_PTD[playerid][4][1], 0x1A2432FF);
    PlayerTextDrawBackgroundColor(playerid, captch_code_PTD[playerid][4][1], 255);
    PlayerTextDrawFont(playerid, captch_code_PTD[playerid][4][1], 4);
    PlayerTextDrawSetProportional(playerid, captch_code_PTD[playerid][4][1], 0);
    PlayerTextDrawSetShadow(playerid, captch_code_PTD[playerid][4][1], 1);

    PlayerTextDrawTextSize(playerid, captch_code_PTD[playerid][4][2], 27.0000+X, 5.0000+X);
    PlayerTextDrawAlignment(playerid, captch_code_PTD[playerid][4][2], 1);
    PlayerTextDrawColor(playerid, captch_code_PTD[playerid][4][2], 0x1A2432FF);
    PlayerTextDrawBackgroundColor(playerid, captch_code_PTD[playerid][4][2], 255);
    PlayerTextDrawFont(playerid, captch_code_PTD[playerid][4][2], 4);
    PlayerTextDrawSetProportional(playerid, captch_code_PTD[playerid][4][2], 0);
    PlayerTextDrawSetShadow(playerid, captch_code_PTD[playerid][4][2], 1);

    PlayerTextDrawTextSize(playerid, captch_code_PTD[playerid][4][3], 26.0000+X, 3.0000+X);
    PlayerTextDrawAlignment(playerid, captch_code_PTD[playerid][4][3], 1);
    PlayerTextDrawColor(playerid, captch_code_PTD[playerid][4][3], 0x1A2432FF);
    PlayerTextDrawBackgroundColor(playerid, captch_code_PTD[playerid][4][3], 255);
    PlayerTextDrawFont(playerid, captch_code_PTD[playerid][4][3], 4);
    PlayerTextDrawSetProportional(playerid, captch_code_PTD[playerid][4][3], 0);
    PlayerTextDrawSetShadow(playerid, captch_code_PTD[playerid][4][3], 1);

    PlayerTextDrawTextSize(playerid, captch_code_PTD[playerid][4][4], 25.0000+X, 5.0000+X);
    PlayerTextDrawAlignment(playerid, captch_code_PTD[playerid][4][4], 1);
    PlayerTextDrawColor(playerid, captch_code_PTD[playerid][4][4], 0x1A2432FF);
    PlayerTextDrawBackgroundColor(playerid, captch_code_PTD[playerid][4][4], 255);
    PlayerTextDrawFont(playerid, captch_code_PTD[playerid][4][4], 4);
    PlayerTextDrawSetProportional(playerid, captch_code_PTD[playerid][4][4], 0);
    PlayerTextDrawSetShadow(playerid, captch_code_PTD[playerid][4][4], 1);

    PlayerTextDrawTextSize(playerid, captch_code_PTD[playerid][4][5], 4.0000+X, 25.0000+X);
    PlayerTextDrawAlignment(playerid, captch_code_PTD[playerid][4][5], 1);
    PlayerTextDrawColor(playerid, captch_code_PTD[playerid][4][5], 0x1A2432FF);
    PlayerTextDrawBackgroundColor(playerid, captch_code_PTD[playerid][4][5], 255);
    PlayerTextDrawFont(playerid, captch_code_PTD[playerid][4][5], 4);
    PlayerTextDrawSetProportional(playerid, captch_code_PTD[playerid][4][5], 0);
    PlayerTextDrawSetShadow(playerid, captch_code_PTD[playerid][4][5], 1);

    PlayerTextDrawTextSize(playerid, captch_code_PTD[playerid][4][6], 4.0000+X, 24.9000+X);
    PlayerTextDrawAlignment(playerid, captch_code_PTD[playerid][4][6], 1);
    PlayerTextDrawColor(playerid, captch_code_PTD[playerid][4][6], 0x1A2432FF);
    PlayerTextDrawBackgroundColor(playerid, captch_code_PTD[playerid][4][6], 255);
    PlayerTextDrawFont(playerid, captch_code_PTD[playerid][4][6], 4);
    PlayerTextDrawSetProportional(playerid, captch_code_PTD[playerid][4][6], 0);
    PlayerTextDrawSetShadow(playerid, captch_code_PTD[playerid][4][6], 1);