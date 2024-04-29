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

	for (int i = pManager->GetSelectedCount() - 1; i >= 0; i--)
	{
		pFig = pManager->GetSelected(i);
		pManager->DeleteSelected(0, pFig);
		pManager->Delete_Figure(pFig);
	}
}
