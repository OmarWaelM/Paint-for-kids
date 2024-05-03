#include "CTriangle.h"

CTriangle::CTriangle(Point p1, Point p2, Point p3, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	P1 = p1;
	P2 = p2;
	P3 = p3;

	ID = Number_Of_Figures;

}

void CTriangle::Draw(Output* pOut) const
{
	pOut->DrawTri(P1, P2, P3, FigGfxInfo, Selected);
}

void CTriangle::PrintInfo(Output* pOut)
{
	string msg = "Triangle's Info : ID =" + to_string(ID);

	msg =msg + " ,Point 1 : ( " + to_string(P1.x) + " , " + to_string(P1.y) + " )";

	msg =msg + " ,Point 2 : ( " + to_string(P2.x) + " , " + to_string(P2.y) + " )";

	msg =msg + " ,Point 3 : ( " + to_string(P3.x) + " , " + to_string(P3.y) + " )";

	pOut->PrintMessage(msg);

}

bool CTriangle::IsWithin(Point P)
{
	int AT, A1, A2, A3;
	AT = abs(P1.x * (P2.y - P3.y) + P2.x * (P3.y - P1.y) + P3.x * (P1.y - P2.y));
	A1 = abs(P.x * (P2.y - P3.y) + P2.x * (P3.y - P.y) + P3.x * (P.y - P2.y));
	A2 = abs(P1.x * (P.y - P3.y) + P.x * (P3.y - P1.y) + P3.x * (P1.y - P.y));
	A3 = abs(P1.x * (P2.y - P.y) + P2.x * (P.y - P1.y) + P.x * (P1.y - P2.y));
	
	if (AT == (A1 + A2 + A3))
		return true;
	return false;
}

void CTriangle::Save(ofstream& OutputFile, int n)
{
	int DrawColor;
	int FillColor;
	int FigureType = TRIANGLE_FIGURE;

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

	OutputFile << "TRIANGLE" << "     " << n << "     " << P1.x << "     " << P1.y << "     " << P2.x << "     " << P2.y << "     " << P3.x << "     " << P3.y << "     ";

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
