#include "CRectangle.h"

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;

	ID = Get_Number_Of_Figures();
}

	

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}

void CRectangle::PrintInfo(Output* pOut)
{
	string msg= "Rectangle : ID = " + to_string(ID);

	msg=msg+ ", Start(" + to_string(Upper_Left.x) + ", " + to_string(Upper_Left.y) + ") " +" End (" + to_string(Bottom_Right.x) + ", " + to_string(Bottom_Right.y) + ")";
	
	//Note:X_Coordinates increases to the right and Y-coordinate increases downwards 
	msg=msg+ ", length = " + to_string(Bottom_Right.x - Upper_Left.x) + ", width = " + to_string(Bottom_Right.y - Upper_Left.y);

	pOut->PrintMessage(msg);
}
