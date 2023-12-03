	InfoText[playerid] = CreatePlayerTextDraw(playerid, 400,300,"-");
	PlayerTextDrawBackgroundColor(playerid, InfoText[playerid],0x000000FF);
	PlayerTextDrawFont(playerid, InfoText[playerid],2);
	PlayerTextDrawLetterSize(playerid, InfoText[playerid],0.42,1.1);
	PlayerTextDrawColor(playerid, InfoText[playerid],-1);
	PlayerTextDrawSetOutline(playerid, InfoText[playerid],1);
	PlayerTextDrawSetProportional(playerid, InfoText[playerid],1);
	PlayerTextDrawSetShadow(playerid, InfoText[playerid],1);

	TaxiDraw[playerid] = CreatePlayerTextDraw(playerid,574.000000, 205.000000, "0");
	PlayerTextDrawBackgroundColor(playerid,TaxiDraw[playerid], 255);
	PlayerTextDrawFont(playerid,TaxiDraw[playerid], 2);
	PlayerTextDrawLetterSize(playerid,TaxiDraw[playerid], 0.229998, 1.699998);
	PlayerTextDrawColor(playerid,TaxiDraw[playerid], -1);
	PlayerTextDrawSetOutline(playerid,TaxiDraw[playerid], 0);
	PlayerTextDrawSetProportional(playerid,TaxiDraw[playerid], 1);
	PlayerTextDrawSetShadow(playerid,TaxiDraw[playerid], 1);
	PlayerTextDrawSetSelectable(playerid,TaxiDraw[playerid], 0);

	ActionText[playerid] = CreatePlayerTextDraw(playerid, 325.000000, 83.000000, "PRESS ~r~ENTER");
	PlayerTextDrawAlignment(playerid, ActionText[playerid], 2);
	PlayerTextDrawBackgroundColor(playerid, ActionText[playerid], 255);
	PlayerTextDrawFont(playerid, ActionText[playerid], 2);
	PlayerTextDrawLetterSize(playerid, ActionText[playerid], 0.909999, 2.599999);
	PlayerTextDrawColor(playerid, ActionText[playerid], -1);
	PlayerTextDrawSetOutline(playerid, ActionText[playerid], 1);
	PlayerTextDrawSetProportional(playerid, ActionText[playerid], 1);

	ActionBand[playerid] = CreatePlayerTextDraw(playerid, 205.000000, 112.000000, "Band");
	PlayerTextDrawBackgroundColor(playerid, ActionBand[playerid], 255);
	PlayerTextDrawFont(playerid, ActionBand[playerid], 1);
	PlayerTextDrawLetterSize(playerid, ActionBand[playerid], -0.000000, 0.899999);
	PlayerTextDrawColor(playerid, ActionBand[playerid], -1);
	PlayerTextDrawSetOutline(playerid, ActionBand[playerid], 0);
	PlayerTextDrawSetProportional(playerid, ActionBand[playerid], 1);
	PlayerTextDrawSetShadow(playerid, ActionBand[playerid], 1);
	PlayerTextDrawUseBox(playerid, ActionBand[playerid], 1);
	PlayerTextDrawBoxColor(playerid, ActionBand[playerid], 0xFF990055);
	PlayerTextDrawTextSize(playerid, ActionBand[playerid], 201.000000, 0.000000);

    KindFuelDraw[playerid] = CreatePlayerTextDraw(playerid, 301.766205, 218.244400, "DIESEL");
	PlayerTextDrawLetterSize(playerid, KindFuelDraw[playerid], 0.400000, 1.600000);
	PlayerTextDrawTextSize(playerid, KindFuelDraw[playerid], 1280.000000, 1280.000000);
	PlayerTextDrawAlignment(playerid, KindFuelDraw[playerid], 1);
	PlayerTextDrawColor(playerid, KindFuelDraw[playerid], 0xA52A2AFF);
	PlayerTextDrawUseBox(playerid, KindFuelDraw[playerid], 0);
	PlayerTextDrawBoxColor(playerid, KindFuelDraw[playerid], 0x80808080);
	PlayerTextDrawSetShadow(playerid, KindFuelDraw[playerid], 0);
	PlayerTextDrawSetOutline(playerid, KindFuelDraw[playerid], 0);
	PlayerTextDrawBackgroundColor(playerid, KindFuelDraw[playerid], 0x000000FF);
	PlayerTextDrawFont(playerid, KindFuelDraw[playerid], 1);
	PlayerTextDrawSetProportional(playerid, KindFuelDraw[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, KindFuelDraw[playerid], 0);

	FuelCostDraw[playerid] = CreatePlayerTextDraw(playerid, 320.966187, 199.348099, "$0");
	PlayerTextDrawLetterSize(playerid, FuelCostDraw[playerid], 0.281599, 1.346899);
	PlayerTextDrawTextSize(playerid, FuelCostDraw[playerid], 10.100000, 30.100000);
	PlayerTextDrawAlignment(playerid, FuelCostDraw[playerid], 2);
	PlayerTextDrawColor(playerid, FuelCostDraw[playerid], 0x141414FF);
	PlayerTextDrawUseBox(playerid, FuelCostDraw[playerid], 0);
	PlayerTextDrawBoxColor(playerid, FuelCostDraw[playerid], 0x80808080);
	PlayerTextDrawSetShadow(playerid, FuelCostDraw[playerid], 0);
	PlayerTextDrawSetOutline(playerid, FuelCostDraw[playerid], 0);
	PlayerTextDrawBackgroundColor(playerid, FuelCostDraw[playerid], 0x000000FF);
	PlayerTextDrawFont(playerid, FuelCostDraw[playerid], 1);
	PlayerTextDrawSetProportional(playerid, FuelCostDraw[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, FuelCostDraw[playerid], 1);
	

	HInfoDraw[playerid][0] = CreatePlayerTextDraw(playerid, 598.000000, 169.000000, "HOUSE 1");
	PlayerTextDrawAlignment(playerid, HInfoDraw[playerid][0], 3);
	PlayerTextDrawBackgroundColor(playerid, HInfoDraw[playerid][0], 255);
	PlayerTextDrawFont(playerid, HInfoDraw[playerid][0], 2);
	PlayerTextDrawLetterSize(playerid, HInfoDraw[playerid][0], 0.569998, 1.899999);
	PlayerTextDrawColor(playerid, HInfoDraw[playerid][0], -1);
	PlayerTextDrawSetOutline(playerid, HInfoDraw[playerid][0], 1);
	PlayerTextDrawSetProportional(playerid, HInfoDraw[playerid][0], 1);

	HInfoDraw[playerid][1] = CreatePlayerTextDraw(playerid, 499.000000, 194.000000, "Owner~n~~g~Jack_Alliance");
	PlayerTextDrawAlignment(playerid, HInfoDraw[playerid][1], 2);
	PlayerTextDrawBackgroundColor(playerid, HInfoDraw[playerid][1], 255);
	PlayerTextDrawFont(playerid, HInfoDraw[playerid][1], 3);
	PlayerTextDrawLetterSize(playerid, HInfoDraw[playerid][1], 0.509999, 1.0);
	PlayerTextDrawColor(playerid, HInfoDraw[playerid][1], -1);
	PlayerTextDrawSetOutline(playerid, HInfoDraw[playerid][1], 1);
	PlayerTextDrawSetProportional(playerid, HInfoDraw[playerid][1], 1);

	HInfoDraw[playerid][2] = CreatePlayerTextDraw(playerid, 403.000000, 229.000000, "LEVEL: ~g~5");
	PlayerTextDrawBackgroundColor(playerid, HInfoDraw[playerid][2], 255);
	PlayerTextDrawFont(playerid, HInfoDraw[playerid][2], 3);
	PlayerTextDrawLetterSize(playerid, HInfoDraw[playerid][2], 0.709999, 1.399999);
	PlayerTextDrawColor(playerid, HInfoDraw[playerid][2], -1);
	PlayerTextDrawSetOutline(playerid, HInfoDraw[playerid][2], 1);
	PlayerTextDrawSetProportional(playerid, HInfoDraw[playerid][2], 1);

	HInfoDraw[playerid][3] = CreatePlayerTextDraw(playerid, 403.000000, 248.000000, "PRICE: ~g~1000000");
	PlayerTextDrawBackgroundColor(playerid, HInfoDraw[playerid][3], 255);
	PlayerTextDrawFont(playerid, HInfoDraw[playerid][3], 3);
	PlayerTextDrawLetterSize(playerid, HInfoDraw[playerid][3], 0.709999, 1.399999);
	PlayerTextDrawColor(playerid, HInfoDraw[playerid][3], -1);
	PlayerTextDrawSetOutline(playerid, HInfoDraw[playerid][3], 1);
	PlayerTextDrawSetProportional(playerid, HInfoDraw[playerid][3], 1);

	HInfoDraw[playerid][4] = CreatePlayerTextDraw(playerid, 403.000000, 267.000000, "ROOMS: ~g~4");
	PlayerTextDrawBackgroundColor(playerid, HInfoDraw[playerid][4], 255);
	PlayerTextDrawFont(playerid, HInfoDraw[playerid][4], 3);
	PlayerTextDrawLetterSize(playerid, HInfoDraw[playerid][4], 0.709999, 1.399999);
	PlayerTextDrawColor(playerid, HInfoDraw[playerid][4], -1);
	PlayerTextDrawSetOutline(playerid, HInfoDraw[playerid][4], 1);
	PlayerTextDrawSetProportional(playerid, HInfoDraw[playerid][4], 1);

	HInfoDraw[playerid][5] = CreatePlayerTextDraw(playerid, 403.000000, 286.000000, "STATUS: ~r~Open");
	PlayerTextDrawBackgroundColor(playerid, HInfoDraw[playerid][5], 255);
	PlayerTextDrawFont(playerid, HInfoDraw[playerid][5], 3);
	PlayerTextDrawLetterSize(playerid, HInfoDraw[playerid][5], 0.709999, 1.399999);
	PlayerTextDrawColor(playerid, HInfoDraw[playerid][5], -1);
	PlayerTextDrawSetOutline(playerid, HInfoDraw[playerid][5], 1);
	PlayerTextDrawSetProportional(playerid, HInfoDraw[playerid][5], 1);