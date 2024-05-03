#include "CRectangle.h"

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;

	ID = Number_Of_Figures;
}

	

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}

void CRectangle::PrintInfo(Output* pOut)
{
	string msg = "Rectangle : ID = " + to_string(ID);

	msg = msg + " , Corner 1: ( " + to_string(Corner1.x) + " , " + to_string(Corner1.y) + " ) " +" Corner 2: ( " + to_string(Corner2.x) + " , " + to_string(Corner2.y) + " )";
	
	//Note:X_Coordinates increases to the right and Y-coordinate increases downwards 
	msg = msg + " , length = " + to_string(abs(Corner1.x - Corner2.x)) + " , width = " + to_string(abs(Corner1.y - Corner2.y));

	pOut->PrintMessage(msg);
}

bool CRectangle::IsWithin(Point P)
{
	if ((P.x < Corner1.x && P.x > Corner2.x) || (P.x > Corner1.x && P.x < Corner2.x))
	{
		if ((P.y < Corner1.y && P.y > Corner2.y) || (P.y > Corner1.y && P.y < Corner2.y))
			return true;
	}
	return false;
}

void CRectangle::Save(ofstream& OutputFile, int n)
{
	int DrawColor;
	int FillColor;
	int FigureType = RECTANGLE_FIGURE;

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
	else FillColor = NO_FILL-COLOUR;

	OutputFile << "RECT" << n << "     " << Corner1.x << "     " << Corner1.y << "     " << Corner2.x << "     " << Corner2.y << "     ";

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