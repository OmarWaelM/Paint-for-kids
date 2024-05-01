#include "CFigure.h"

int CFigure::Number_Of_Figures = 0;


CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
	Number_Of_Figures++;

}

void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected() const
{	return Selected; }

void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}

FillColors CFigure::Get_Filled_Colour_ENUM()
{

	color c = FigGfxInfo.FillClr;

	if (c == BLACK)
		return black;
	if (c == RED)
		return red;
	if (c == ORANGE)
		return orange;
	if (c == YELLOW)
		return yellow;
	if (c == BLUE)
		return blue;
	if (c == GREEN)
		return green;

}



