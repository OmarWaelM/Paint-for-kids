#include "CCircle.h"

CCircle::CCircle(Point p1, Point p2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Centre = p1;
	Radius = p2;

	ID = Number_Of_Figures;

}

void CCircle::Draw(Output* pOut) const
{
	pOut->DrawCirc(Centre, Radius, FigGfxInfo, Selected);
}

void CCircle::PrintInfo(Output* pOut)
{
	string msg = "Circle's Info : ID = " + to_string(ID);

	msg = msg + " , Center Point ( " + to_string(Centre.x) + " , " + to_string(Centre.x) + " )";

	msg = msg + " , Radius = " + to_string(sqrt(pow(Centre.x - Radius.x, 2) + pow(Centre.y - Radius.y, 2)));

	pOut->PrintMessage(msg);

}

bool CCircle::IsWithin(Point P)
{
	double r = sqrt(pow(Centre.x - P.x, 2) + pow(Centre.y - P.y, 2));
	double rad = sqrt(pow(Centre.x - Radius.x, 2) + pow(Centre.y - Radius.y, 2));

	if (r <= rad)
		return true;
	return false;
}

void CCircle::Save(ofstream& OutputFile, int n)
{
	int DrawColor;
	int FillColor;
	int FigureType = CIRCLE_FIGURE;

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

	OutputFile << "CIRCLE" << "     " << n << "     " << Centre.x << "     " << Centre.y << "     " << Radius.x << "     " << Radius.y << "     ";

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

