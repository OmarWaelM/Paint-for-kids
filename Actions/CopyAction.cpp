#include "CopyAction.h"

CopyAction::CopyAction(ApplicationManager* pAct) : Action (pAct)
{
}

void CopyAction::ReadActionParameters()
{
}

void CopyAction::Execute()
{
	//initializing pOut pointer
	pOut = pManager->GetOutput();
	pOut->PrintMessage("Copy Tool Selected");

	//checks on the number of selected figures
	if (pManager->GetSelectedCount() == 1)
	{
		//if only one figure is selected, set the SelectedFig pointer to point to this figure
		SelectedFig = pManager->GetSelected(0);
		//set the clipboard pointer to point to this selected figure
		pManager->SetClipboard(SelectedFig);
		pOut->PrintMessage("Figure Copied to the Clipboard.");
	}
	// if no figure is selected, print: No items are selected 
	else if (pManager->GetSelectedCount() == 0)
	{
		pOut->PrintMessage("No Items are Selected");
	}
	// if more than one figure is selected, print: Select only one figure
	else 
	{
		pOut->PrintMessage("Select ONLY ONE Figure");
	}
}
