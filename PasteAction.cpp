#include "PasteAction.h"

PasteAction::PasteAction(ApplicationManager* pAct) : Action (pAct)
{
}

void PasteAction::ReadActionParameters()
{
	pIn->GetPointClicked(PointClicked.x,PointClicked.y);
}

void PasteAction::Execute()
{
	ReadActionParameters();
	pOut->PrintMessage("Paste Tool Selected");
	PasteFigure = pManager->GetClipboard();
	if (dynamic_cast<CCircle*>(PasteFigure)!= NULL)
	{
	}
}
