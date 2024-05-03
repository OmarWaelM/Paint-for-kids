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
	string DrawColor;
	string FillColor;
	string FigureType = "SQUARE";

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

	OutputFile << FigureType << "   " << n << "   " << Centre.x << "   " << Centre.y << "   " << DrawColor << "   " << FillColor << '\n';

}