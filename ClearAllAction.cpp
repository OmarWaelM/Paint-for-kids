#include "ClearAllAction.h"


ClearAllAction::ClearAllAction(ApplicationManager* pApp): Action (pApp)
{
}

void ClearAllAction::ReadActionParameters()
{
}

void ClearAllAction::Execute()
{
	pOut = pManager->GetOutput();
	pOut->ClearDrawArea();
	pOut->ClearStatusBar();
	pManager->SetClipboard(NULL);
	for (int i = pManager->GetFigCount() - 1; i >= 0; i--)
	{
		Fig = pManager -> GetFigListItem(i);
		pManager -> Delete_Figure(Fig);
		pManager->DeleteSelected(i, Fig);
	}
}

