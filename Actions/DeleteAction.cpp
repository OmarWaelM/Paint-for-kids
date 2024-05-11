#include "..\Actions\DeleteAction.h"
#include "..\ApplicationManager.h"


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
			pFig = pManager->GetSelected(i); //gets figure from selected list
			pManager->DeleteSelected(0, pFig); //removes figure from selected list
			pManager->Delete_Figure(pFig); //deletes figure from figlist
		}
		pOut->ClearStatusBar();
	}
	else
		pOut->PrintMessage("No Items Selected.");
  
}