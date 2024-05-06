#include "ChangeFillColor.h"


ChangeFillColor::ChangeFillColor(ApplicationManager* pApp) : Action (pApp)
{
}

void ChangeFillColor::ReadActionParameters()
{
	pOut = pManager->GetOutput();										//initializing pOut pointer
	pIn = pManager->GetInput();											//initializing pIn pointer

	pOut->PrintMessage("Change fill tool picked, Click on a color.");	//print message
	ActType = pIn->GetUserAction();										//gets the color selected by the user from the toolbar
	
		//depending on the color the user clicked on on the toolbar, the SelectedColor is set to it
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
	pOut = pManager->GetOutput();						//initializing pOut pointer

	//checks if only one figure is selected
	if (pManager->GetSelectedCount() == 1)
	{
		ReadActionParameters();							//if yes, read input parameters from user
		SelectedFig = pManager->GetSelected(0);			//set the SelectedFig pointer to point to this figure
		SelectedFig->ChngFillClr(SelectedColor);		//change the fill color of the selected figure to the selected color
	}
	//if no figure is selected,
	else if (pManager->GetSelectedCount() == 0)
	{
		pOut->PrintMessage("No Items are Selected");	//print message
	}
	//if more than one figure is selected,
	else
	{
		pOut->PrintMessage("Select ONLY ONE Figure");	//print message
	}

}

