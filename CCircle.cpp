#include "CCircle.h"

CCircle::CCircle(Point p1, Point p2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	P1 = p1;
	P2 = p2;

	ID = Get_Number_Of_Figures();

}

void CCircle::Draw(Output* pOut) const
{
	pOut->DrawCirc(P1, P2, FigGfxInfo, Selected);
}

void CCircle::PrintInfo(Output* pOut)
{
	string msg = "Circle's Info : ID = " + to_string(ID);

	msg =msg+ ", Point P1 ( " + to_string(P1.x) + "," + to_string(P1.x);

	msg = msg + ",Point P2 ( " + to_string(P2.x) + "," + to_string(P2.x);

	pOut->PrintMessage(msg);

}
