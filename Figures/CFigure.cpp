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

const bool CFigure::IsCopied()
{
	return Copied;
}

void CFigure::SetCopied(bool copy)
{
	Copied = copy;
}

const bool CFigure::IsCut()
{
	return Cut;
}

void CFigure::SetCut(bool c)
{
	Cut = c;
}


void CFigure::ChngNumberOfFigures(int num)
{
	Number_Of_Figures = 0;
}
