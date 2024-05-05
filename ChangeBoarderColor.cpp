#include "ChangeBoarderColor.h"
#include "ApplicationManager.h"


ChangeBoarderColor::ChangeBoarderColor(ApplicationManager* pApp) : Action (pApp)
{
}

void ChangeBoarderColor::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Change border color tool picked, Click on a color.");
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

void ChangeBoarderColor::Execute()
{
	Output* pOut = pManager->GetOutput();

	if (pManager->GetSelectedCount() == 1)
	{
		ReadActionParameters();
		SelectedFig = pManager->GetSelected(0);
		SelectedFig->ChngDrawClr(SelectedColor);
	}
	else if (pManager->GetSelectedCount() == 0)
	{
		pOut->PrintMessage("No items are selected");
	}
	else
	{
		pOut->PrintMessage("Select Only ONE figure");
	}
}
