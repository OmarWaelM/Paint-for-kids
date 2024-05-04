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

void CTriangle::Save(ofstream& OutputFile)
{
	string DrawColor;
	string FillColor;
	string FigureType = "TRIANGLE";

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

	OutputFile << FigureType << "\t" << ID << "\t" << P1.x << "\t" << P1.y << "\t" << P2.x << "\t" << P2.y << "\t" << P3.x << "\t" << P3.y << "\t" << DrawColor << "\t" << FillColor << '\n';
}

void CTriangle::Load(ifstream& InputFile)
{
	string DrawCol, FillCol;
	InputFile >> ID >> P1.x >> P1.y >> P2.x >> P2.y >> P3.x >> P3.y >> DrawCol >> FillCol;

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
