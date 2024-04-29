#include "CTriangle.h"

CTriangle::CTriangle(Point p1, Point p2, Point p3, GfxInfo FigureGfxInfo):CFigure(FigGfxInfo)
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
