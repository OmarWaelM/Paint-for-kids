#include "DeleteAction.h"
#include "ApplicationManager.h"


DeleteAction::DeleteAction(ApplicationManager* pApp):Action(pApp)
{
}

void DeleteAction::ReadActionParameters()
{
}

void DeleteAction::Execute()
{
	ReadActionParameters();

	pOut = pManager->GetOutput();

	if (pManager->GetSelectedCount() > 0)
	{
		for (int i = pManager->GetSelectedCount() - 1; i >= 0; i--)
		{
			pFig = pManager->GetSelected(i);
			pManager->DeleteSelected(0, pFig);
			pManager->Delete_Figure(pFig);
			pOut->ClearStatusBar();
		}
	}
	else
		pOut->PrintMessage("No Items Selected.");
}
