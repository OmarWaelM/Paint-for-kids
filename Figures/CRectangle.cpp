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