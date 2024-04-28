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
