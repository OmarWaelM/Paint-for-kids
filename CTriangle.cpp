#include "CTriangle.h"

CTriangle::CTriangle(Point p1, Point p2, Point p3, GfxInfo FigureGfxInfo):CFigure(FigGfxInfo)
{
	P1 = p1;
	P2 = p2;
	P3 = p3;

	ID = Get_Number_Of_Figures();

}

void CTriangle::Draw(Output* pOut) const
{
	pOut->DrawTri(P1, P2, P3, FigGfxInfo, Selected);
}

void CTriangle::PrintInfo(Output* pOut)
{
	string msg = "Triangle's Info : ID =" + to_string(ID);

	msg =msg + ",Point P1 : ( " + to_string(P1.x) + "," + to_string(P1.y);

	msg =msg + ",Point P2 : ( " + to_string(P2.x) + "," + to_string(P2.y);

	msg =msg + ",Point P3 : ( " + to_string(P3.x) + "," + to_string(P3.y);

	pOut->PrintMessage(msg);

}
