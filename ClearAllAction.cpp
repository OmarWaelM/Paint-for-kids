#include "ClearAllAction.h"


ClearAllAction::ClearAllAction(ApplicationManager* pApp): Action (pApp)
{
}

void ClearAllAction::ReadActionParameters()
{
}

void ClearAllAction::Execute()
{
	pOut = pManager->GetOutput();//initializing pOut pointer
	pOut->ClearDrawArea(); //clears the drawing area
	pOut->ClearStatusBar(); //clears the status bar
	pManager->SetClipboard(NULL); //empties the clipboard

	//clears the selected figure list items
	for (int i = pManager->GetSelectedCount() - 1; i >= 0; i--)
	{
		Fig = pManager->GetSelected(i);
		pManager->DeleteSelected(i, Fig);
	}

	//clears the figure list items
	for (int i = pManager->GetFigCount() - 1; i >= 0; i--)
	{
		Fig = pManager->GetFigListItem(i);
		pManager->Delete_Figure(Fig);
	}

	//resets the number of figures
	CFigure::ChngNumberOfFigures(0);
}

