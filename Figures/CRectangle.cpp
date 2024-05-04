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
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected, Cut);
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

void CRectangle::Move(Point P) 
{
	Point Centre;
	Centre.x = (Corner1.x + Corner2.x) / 2;
	Centre.y = (Corner2.y + Corner2.y) / 2;

	int dist_x = P.x - Centre.x;
	int dist_y = P.y - Centre.y;

	Corner1.x = Corner1.x + dist_x;
	Corner1.y = Corner1.y + dist_y;

	Corner2.x = Corner2.x + dist_x;
	Corner2.y = Corner2.y + dist_y;
}

void CRectangle::Save(ofstream& OutputFile)
{
	string DrawColor;
	string FillColor;
	string FigureType = "RECTANGLE";

	if (FigGfxInfo.DrawClr == BLACK)
		DrawColor = "BLACK";
	else if (FigGfxInfo.DrawClr == YELLOW)
		DrawColor = "YELLOW";
	else if (FigGfxInfo.DrawClr == ORANGE)
		DrawColor = "ORANGE";
	else if (FigGfxInfo.DrawClr == RED)
		DrawColor = "RED";
	else if (FigGfxInfo.DrawClr == GREEN)
		DrawColor = "GREEN";
	else if (FigGfxInfo.DrawClr == BLUE)
		DrawColor = "BLUE";

	if (FigGfxInfo.isFilled)
	{
		if (FigGfxInfo.FillClr == BLACK)
			FillColor = "BLACK";
		else if (FigGfxInfo.FillClr == YELLOW)
			FillColor = "YELLOW";
		else if (FigGfxInfo.FillClr == ORANGE)
			FillColor = "ORANGE";
		else if (FigGfxInfo.FillClr == RED)
			FillColor = "RED";
		else if (FigGfxInfo.FillClr == GREEN)
			FillColor = "GREEN";
		else if (FigGfxInfo.FillClr == BLUE)
			FillColor = "BLUE";
	}
	else FillColor = "NO_FILL";

	OutputFile << FigureType << "\t" << ID << "\t" << Corner1.x << "\t" << Corner1.y << "\t" << Corner2.x << "\t" << Corner2.y << "\t" << DrawColor << "\t" << FillColor << '\n';
}

void CRectangle::Load(ifstream& InputFile)
{
	string DrawCol, FillCol;
	InputFile >> ID >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y >> DrawCol >> FillCol;

	if (DrawCol == "BLACK")
		FigGfxInfo.DrawClr = BLACK;
	else if (DrawCol == "YELLOW")
		FigGfxInfo.DrawClr = YELLOW;
	else if (DrawCol == "ORANGE")
		FigGfxInfo.DrawClr = ORANGE;
	else if (DrawCol == "RED")
		FigGfxInfo.DrawClr = RED;
	else if (DrawCol == "GREEN")
		FigGfxInfo.DrawClr = GREEN;
	else if (DrawCol == "BLUE")
		FigGfxInfo.DrawClr = BLUE;

	if (FillCol == "BLACK")
	{
		FigGfxInfo.isFilled = true;
		FigGfxInfo.FillClr = BLACK;
	}
	else if (FillCol == "YELLOW")
	{
		FigGfxInfo.isFilled = true;
		FigGfxInfo.FillClr = YELLOW;
	}
	else if (FillCol == "ORANGE")
	{
		FigGfxInfo.isFilled = true;
		FigGfxInfo.FillClr = ORANGE;
	}
	else if (FillCol == "RED")
	{
		FigGfxInfo.isFilled = true;
		FigGfxInfo.FillClr = RED;
	}
	else if (FillCol == "GREEN")
	{
		FigGfxInfo.isFilled = true;
		FigGfxInfo.FillClr = GREEN;
	}
	else if (FillCol == "BLUE")
	{
		FigGfxInfo.isFilled = true;
		FigGfxInfo.FillClr = BLUE;
	}
	else if (FillCol == "NO_FILL")
	{
		FigGfxInfo.isFilled = false;
	}
}
