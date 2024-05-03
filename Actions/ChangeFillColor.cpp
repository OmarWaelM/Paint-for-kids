#include "ChangeFillColor.h"

ChangeFillColor::ChangeFillColor(ApplicationManager* pApp) : Action (pApp)
{
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
			SelectedColor = BLACK;
			break;

		case SEL_YELLOW:
			SelectedColor = YELLOW;
			break;

		case SEL_ORANGE:
			SelectedColor = ORANGE;
			break;

		case SEL_RED:
			SelectedColor = RED;
			break;

		case SEL_GREEN:
			SelectedColor = GREEN;
			break;

		case SEL_BLUE:
			SelectedColor = BLUE;
			break;

		default:
			SelectedColor = NULL;
			break;
		}
	
	
}

void ChangeFillColor::Execute()
{ 
	if (pManager->GetSelectedCount() == 1)
	{
		ReadActionParameters();
		Selected Fig = pManager->GetSelected(0);
		SelectedFig->ChngFillClr(SelectedColor);
	}
	else
	{
		cout << "Select only ONE figure";
	}

}

