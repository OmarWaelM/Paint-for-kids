#include "CHexagon.h"

CHexagon::CHexagon(Point P, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Centre = P;
	ID = Number_Of_Figures;

}

void CHexagon::Draw(Output* pOut) const
{
	pOut->DrawHex(Centre, FigGfxInfo, Selected);
}

void CHexagon::PrintInfo(Output* pOut)
{
	string msg = "Hexagon's Info: ID = " + to_string(ID);

	msg=msg+ ", Center is ( " + to_string(Centre.x) + " , " + to_string(Centre.y) + " )";

	msg = msg + ", Height = 200 ";

	pOut->PrintMessage(msg);
}

bool CHexagon::IsWithin(Point P)
{
	int vertDist = 100;
	int diagDist = (int)(100 * sqrt(3) / 3);
	int horizDist = (int)(100 * 2 * sqrt(3) / 3);

	int PointsX[6] = { Centre.x - diagDist, Centre.x + diagDist, Centre.x + horizDist, Centre.x + diagDist, Centre.x - diagDist, Centre.x - horizDist };
	int PointsY[6] = { Centre.y + vertDist, Centre.y + vertDist, Centre.y, Centre.y - vertDist, Centre.y - vertDist, Centre.y};

	if (IsWithinHelper(Centre.x, Centre.y, PointsX[5], PointsY[5], PointsX[0], PointsY[0], P.x, P.y))
		return true;
	for (int i = 0; i < 5; i++)
	{
		if (IsWithinHelper(Centre.x, Centre.y, PointsX[i], PointsY[i], PointsX[i + 1], PointsY[i + 1], P.x, P.y))
			return true;
	}
	return false;
}

bool CHexagon::IsWithinHelper(int P1x, int P1y, int P2x, int P2y, int P3x, int P3y, int Px, int Py)
{
	int AT, A1, A2, A3;
	AT = abs(P1x * (P2y - P3y) + P2x * (P3y - P1y) + P3x * (P1y - P2y));
	A1 = abs(Px * (P2y - P3y) + P2x * (P3y - Py) + P3x * (Py - P2y));
	A2 = abs(P1x * (Py - P3y) + Px * (P3y - P1y) + P3x * (P1y - Py));
	A3 = abs(P1x * (P2y - Py) + P2x * (Py - P1y) + Px * (P1y - P2y));

	if (AT == (A1 + A2 + A3))
		return true;
	return false;
}

void CHexagon::Save(ofstream& OutputFile, int n)
{
	int DrawColor;
	int FillColor;
	int FigureType = HEXAGON_FIGURE;

	if (FigGfxInfo.DrawClr == BLACK)
		DrawColor = BLACK_COLOUR;
	else if (FigGfxInfo.DrawClr == YELLOW)
		DrawColor = YELLOW_COLOUR;
	else if (FigGfxInfo.DrawClr == ORANGE)
		DrawColor = ORANGE_COLOUR;
	else if (FigGfxInfo.DrawClr == RED)
		DrawColor = RED_COLOUR;
	else if (FigGfxInfo.DrawClr == GREEN)
		DrawColor = GREEN_COLOUR;
	else if (FigGfxInfo.DrawClr == BLUE)
		DrawColor = BLUE_COLOUR;

	if (FigGfxInfo.isFilled)
	{
		if (FigGfxInfo.FillClr == BLACK)
			FillColor = BLACK_COLOUR;
		else if (FigGfxInfo.FillClr == YELLOW)
			FillColor = YELLOW_COLOUR;
		else if (FigGfxInfo.FillClr == ORANGE)
			FillColor = ORANGE_COLOUR;
		else if (FigGfxInfo.FillClr == RED)
			FillColor = RED_COLOUR;
		else if (FigGfxInfo.FillClr == GREEN)
			FillColor = GREEN_COLOUR;
		else if (FigGfxInfo.FillClr == BLUE)
			FillColor = BLUE_COLOUR;
	}
	else FillColor = NO_FILL_COLOUR;

	OutputFile << "HEXAGON" << "     " << n << "     " << Centre.x << "     " << Centre.y << "     ";

	switch (DrawColor)
	{
	case BLACK_COLOUR:
		OutputFile << "BLACK" << "     ";
		break;
	case YELLOW_COLOUR:
		OutputFile << "YELLOW" << "     ";
		break;
	case ORANGE_COLOUR:
		OutputFile << "ORANGE" << "     ";
		break;
	case RED_COLOUR:
		OutputFile << "RED" << "     ";
		break;
	case GREEN_COLOUR:
		OutputFile << "GREEN" << "     ";
		break;
	case BLUE_COLOUR:
		OutputFile << "BLUE" << "     ";
		break;
	}

	switch (FillColor)
	{
	case BLACK_COLOUR:
		OutputFile << "BLACK" << '\n';
		break;
	case YELLOW_COLOUR:
		OutputFile << "YELLOW" << '\n';
		break;
	case ORANGE_COLOUR:
		OutputFile << "ORANGE" << '\n';
		break;
	case RED_COLOUR:
		OutputFile << "RED" << '\n';
		break;
	case GREEN_COLOUR:
		OutputFile << "GREEN" << '\n';
		break;
	case BLUE_COLOUR:
		OutputFile << "BLUE" << '\n';
		break;
	case NO_FILL_COLOUR:
		OutputFile << "NO_FILL" << '\n';
		break;
	}
	
}
