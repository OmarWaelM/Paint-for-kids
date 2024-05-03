#include "CSquare.h"

CSquare::CSquare(Point P, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Centre = P;
	ID = Number_Of_Figures;

}

void CSquare::Draw(Output* pOut) const
{
	pOut->DrawSqr(Centre, FigGfxInfo, Selected);
}

void CSquare::PrintInfo(Output* pOut)
{
	string msg = "Square's Info : ID = " + to_string(ID);

	msg = msg + " , Centre Point is : ( " + to_string(Centre.x) + " , " + to_string(Centre.y) + " )";

	msg = msg + " , Side Length = 200 ";

	pOut->PrintMessage(msg);

}

bool CSquare::IsWithin(Point P)
{
	if (abs(P.x - Centre.x) <= 100 && abs(P.y - Centre.y) <= 100)
		return true;
	return false;
}

void CSquare::Save(ofstream& OutputFile, int n)
{
	int DrawColor;
	int FillColor;
	int FigureType = SQUARE_FIGURE;

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

	OutputFile << "SQUARE" << "     " << n << "     " << Centre.x << "     " << Centre.y << "     ";

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
