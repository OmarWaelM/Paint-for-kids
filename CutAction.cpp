#include "CutAction.h"

CutAction::CutAction(ApplicationManager* pAct) : Action (pAct)
{
}

void CutAction::ReadActionParameters()
{
}

void CutAction::Execute()
{
	pOut = pManager->GetOutput();
	pOut->PrintMessage("Cut tool selected");

	if (pManager->GetSelectedCount() == 1)
	{
		SelectedFig = pManager->GetSelected(0);
		pManager->SetClipboard(SelectedFig);
		SelectedFig->SetCut(true);
	}
	else if (pManager->GetSelectedCount() == 0)
	{
		pOut->PrintMessage("No items are selected");
	}
	else
	{
		pOut->PrintMessage("Select ONLY ONE Figure");
	}
}
