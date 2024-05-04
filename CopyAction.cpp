#include "CopyAction.h"

CopyAction::CopyAction(ApplicationManager* pAct) : Action (pAct)
{
}

void CopyAction::ReadActionParameters()
{
}

void CopyAction::Execute()
{
	pOut = pManager->GetOutput();
	pOut->PrintMessage("Copy tool selected");

	if (pManager->GetSelectedCount() == 1)
	{
		pManager->SetClipboard(SelectedFig);
		pOut->PrintMessage("Figure Copied to the Clipboard.");
	}
	else 
	{
		pOut->PrintMessage("Select ONLY ONE Figure");
	}
}
