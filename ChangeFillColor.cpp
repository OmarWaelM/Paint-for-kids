#include "ChangeFillColor.h"

ChangeFillColor::ChangeFillColor(ApplicationManager* pApp) : Action (pApp)
{
}

void ChangeFillColor::SetSelectedColor(color c)
{
	SelectedColor = c;
}


void ChangeFillColor::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Change Fill tool picked, Click on a color.");
	ActType = pIn->GetUserAction();
	switch (ActType)
	{
	case SEL_BLACK:
		SelectedFig->ChngFillClr(BLACK);
		SetSelectedColor(BLACK);
		break;

	case SEL_YELLOW:
		SelectedFig->ChngFillClr(YELLOW);
		SetSelectedColor(YELLOW);
		break;

	case SEL_ORANGE:
		SelectedFig->ChngFillClr(ORANGE);
		SetSelectedColor(ORANGE);
		break;

	case SEL_RED:
		SelectedFig->ChngFillClr(RED);
		break;
	case SEL_GREEN:
		SelectedFig->ChngFillClr(GREEN);
		SetSelectedColor(GREEN);
		break;

	case SEL_BLUE:
		SelectedFig->ChngFillClr(BLUE);
		SetSelectedColor(BLUE);
		break;

	default:
		SelectedFig->ChngFillClr(NULL);
		SetSelectedColor(NULL);
		break;
	}
}

void ChangeFillColor::Execute()
{ 
	if (pManager ->GetSelectedCount() == 0)
	{
		SelectedFig -> ChngFillClr(SelectedColor);
	}
}

