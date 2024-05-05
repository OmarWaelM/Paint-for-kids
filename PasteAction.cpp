#include "PasteAction.h"

PasteAction::PasteAction(ApplicationManager* pAct) : Action (pAct)
{
}

void PasteAction::ReadActionParameters()
{
	pOut = pManager->GetOutput();
	pIn = pManager->GetInput();
	pOut->PrintMessage("Click on point to paste to");
	pIn->GetPointClicked(PointClicked.x,PointClicked.y);
}

void PasteAction::Execute()
{
	pOut = pManager->GetOutput();
	pIn = pManager->GetInput();
	if (pManager->GetClipboard() != NULL)
	{
		ReadActionParameters();
		pOut->PrintMessage("Paste Tool Selected");
		PasteFigure = pManager->GetClipboard();
		PasteFigureGfxInfo = pManager->GetClipboardGfxInfo();

		if (dynamic_cast<CCircle*>(PasteFigure) != NULL)
		{
			NewFigure = new CCircle(dynamic_cast<CCircle*>(PasteFigure), PasteFigureGfxInfo);
		}
		else if (dynamic_cast<CSquare*>(PasteFigure) != NULL)
		{
			NewFigure = new CSquare(dynamic_cast<CSquare*>(PasteFigure), PasteFigureGfxInfo);
		}
		else if (dynamic_cast<CRectangle*>(PasteFigure) != NULL)
		{
			NewFigure = new CRectangle(dynamic_cast<CRectangle*>(PasteFigure), PasteFigureGfxInfo);
		}
		else if (dynamic_cast<CTriangle*>(PasteFigure) != NULL)
		{
			NewFigure = new CTriangle(dynamic_cast<CTriangle*>(PasteFigure), PasteFigureGfxInfo);
		}
		else if (dynamic_cast<CHexagon*>(PasteFigure) != NULL)
		{
			NewFigure = new CHexagon(dynamic_cast<CHexagon*>(PasteFigure), PasteFigureGfxInfo);
		}

		NewFigure->Move(PointClicked);
		pManager->AddFigure(NewFigure);

		if (PasteFigure->IsCut())
		{
			pManager->SetClipboard(NewFigure);
			if (PasteFigure->IsSelected())
				pManager->DeleteSelected(0, PasteFigure);
			pManager->Delete_Figure(PasteFigure);
			pManager->SetClipboard(NewFigure);
		}
		pOut->PrintMessage("Figure pasted successfully");
	}
	else
		pOut->PrintMessage("No Copied Figure");
}
