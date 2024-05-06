#include "PasteAction.h"

PasteAction::PasteAction(ApplicationManager* pAct) : Action (pAct)
{
}

void PasteAction::ReadActionParameters()
{
	pOut = pManager->GetOutput();							//initializing pOut pointer
	pIn = pManager->GetInput();								//initializing pIn pointer
	pOut->PrintMessage("Click on a point to paste to");		//print message
	pIn->GetPointClicked(PointClicked.x,PointClicked.y);	//gets the point to be paste to
}

void PasteAction::Execute()
{
	pOut = pManager->GetOutput();								//initializing pOut pointer
	pIn = pManager->GetInput();									//initializing pIn pointer

	//checks whether the clipboard is empty or not
	if (pManager->GetClipboard() != NULL)
	{
		//if the clipboard is not empty,
		ReadActionParameters();									//read the point clicked
		pOut->PrintMessage("Paste Tool Selected");
		PasteFigure = pManager->GetClipboard();					//get the figure in clipboard
		PasteFigureGfxInfo = pManager->GetClipboardGfxInfo();	//get the graphics info of the figure in clipboard

		//checking on the figure type in clipboard, and sets the figure to be paste to this shape
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

		NewFigure->Move(PointClicked);							//moves the figure points according to the point clicked on screen
		pManager->AddFigure(NewFigure);							//adds the figure to the desired location

		//checks whether the figure is cut or not
		if (PasteFigure->IsCut())							
		{
			pManager->SetClipboard(NewFigure);					//if it is cut, set the clipboard to the new figure
			if (PasteFigure->IsSelected())						//if the previous figure in clipboard is selected,
				pManager->DeleteSelected(0, PasteFigure);		//delete it from the selected figure list
			pManager->Delete_Figure(PasteFigure);				//delete the previous figure from the figure list
			pManager->SetClipboard(NewFigure);					//set the clipboard to the new figure
		}
		pOut->PrintMessage("Figure Pasted Successfully");		//print message
	}
	else
		pOut->PrintMessage("No Copied Figure");					//print message
}
