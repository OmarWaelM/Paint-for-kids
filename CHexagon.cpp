#include "CHexagon.h"

CHexagon::CHexagon(Point P, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Centre = P;
	ID = Get_Number_Of_Figures();

}

void CHexagon::Draw(Output* pOut) const
{
	pOut->DrawHex(Centre, FigGfxInfo, Selected);
}

void CHexagon::PrintInfo(Output* pOut)
{
	string msg = "Hexagon's Info: ID = " + to_string(ID);

	msg=msg+ ", Center is (" + to_string(Centre.x) + ", " + to_string(Centre.y) + ")";

	msg = msg + "Height = 200 ";

	pOut->PrintMessage(msg);
}
