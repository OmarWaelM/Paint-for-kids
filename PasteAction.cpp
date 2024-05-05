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
		CCircle* NewFigure = new CCircle (dynamic_cast<CCircle*>(PasteFigure), PasteFigureGfxInfo);
	}
	else if (dynamic_cast<CSquare*>(PasteFigure) != NULL)
	{
		CSquare* NewFigure = new CSquare(dynamic_cast<CSquare*>(PasteFigure), PasteFigureGfxInfo);
	}
	else if (dynamic_cast<CRectangle*>(PasteFigure) != NULL)
	{
		CRectangle* NewFigure = new CRectangle(dynamic_cast<CRectangle*>(PasteFigure), PasteFigureGfxInfo);
	}
	else if (dynamic_cast<CTriangle*>(PasteFigure) != NULL)
	{
		CTriangle* NewFigure = new CTriangle(dynamic_cast<CTriangle*>(PasteFigure), PasteFigureGfxInfo);
	}
	else if (dynamic_cast<CHexagon*>(PasteFigure) != NULL)
	{
		CHexagon* NewFigure = new CHexagon(dynamic_cast<CHexagon*>(PasteFigure), PasteFigureGfxInfo);
	}
	
	if (PasteFigure->IsCut())
	{

	}
}
