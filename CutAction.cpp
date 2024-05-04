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
	else
	{
		pOut->PrintMessage("Select ONLY ONE Figure");
	}
}
