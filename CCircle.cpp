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

