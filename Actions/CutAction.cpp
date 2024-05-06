#include "CutAction.h"

CutAction::CutAction(ApplicationManager* pAct) : Action (pAct)
{
}

void CutAction::ReadActionParameters()
{
}

void CutAction::Execute()
{
	pOut = pManager->GetOutput();						//initializing pOut pointer
	pOut->PrintMessage("Cut Tool Selected");			//print message

	//checks if only one figure is selected
	if (pManager->GetSelectedCount() == 1)
	{
		SelectedFig = pManager->GetSelected(0);			//if yes, set the SelectedFig pointer to this figure
		pManager->SetClipboard(SelectedFig);			//sets the clipboard to this figure
		SelectedFig->SetCut(true);						//sets cut status to true (the figure is cut)
	}
	//if no figure is selected
	else if (pManager->GetSelectedCount() == 0)
	{
		pOut->PrintMessage("No Items are Selected");	//print message
	}
	//if more than one shape is selected
	else
	{
		pOut->PrintMessage("Select ONLY ONE Figure");	//print message
	}
}
