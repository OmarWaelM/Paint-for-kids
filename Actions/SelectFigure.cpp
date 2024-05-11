#include "..\Actions\SelectFigure.h"
#include "..\ApplicationManager.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\CCircle.h"
#include "..\Figures\CTriangle.h"
#include "..\Figures\CHexagon.h"
#include "..\Figures\CSquare.h"

using namespace std;

void SelectFigure::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Selection tool picked, Click on a figure.");
	pIn->GetPointClicked(Clicked.x, Clicked.y);

}

void SelectFigure::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	if (pManager->GetFigCount() != 0) //checks that a figure has been drawn
	{	
		ReadActionParameters();
		Fig_Clicked = pManager->GetFigure(Clicked.x, Clicked.y);

		if (Fig_Clicked != NULL) 
		{
			if (Fig_Clicked->IsSelected()) //if clicked on selected figure, unselects it
				pManager->DeleteSelected(0, Fig_Clicked);
			else
				pManager->AddSelected(Fig_Clicked);
		}
		else //if clickedo on empty area removes all figures from selected list
		{
			for (int i = pManager->GetSelectedCount() - 1; i >= 0 ; i--)
				pManager->DeleteSelected(i);
		}
		PrintInfo();
	}
	else
	{
		pOut->PrintMessage("Error! No items to select.");
	}
}

void SelectFigure::PrintInfo() const
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	int counts[5] = { 0,0,0,0,0 };

	CRectangle* R = NULL;
	CSquare* S = NULL;
	CCircle* C = NULL;
	CTriangle* T = NULL;
	CHexagon* H = NULL;
	CFigure* Fig;

	switch (pManager->GetSelectedCount())
	{
	case (0): //if no selected figures
		pOut->PrintMessage("No Figure Selected.");
		break;

	case (1): //if only one selected figure prints its info
		pManager->GetSelected(0)->PrintInfo(pOut);
		break;

	default: // if more that one selected figure, prints count of each type of figure
		for (int i = 0; i < pManager->GetSelectedCount(); i++)
		{
			Fig = pManager->GetSelected(i);
			R = dynamic_cast<CRectangle*>(Fig);
			H = dynamic_cast<CHexagon*>(Fig);
			T = dynamic_cast<CTriangle*>(Fig);
			S = dynamic_cast<CSquare*>(Fig);
			C = dynamic_cast<CCircle*>(Fig);

			if (R != NULL) { counts[0]++; }
			else if (H != NULL) { counts[1]++; }
			else if (T != NULL) { counts[2]++; }
			else if (S != NULL) { counts[3]++; }
			else if (C != NULL) { counts[4]++; }
		}
		string msg; 
		msg = (counts[0] > 0) ? msg + to_string(counts[0]) + " Rectangle(s), " : msg ;
		msg = (counts[1] > 0) ? msg + to_string(counts[1]) + " Hexagon(s), " : msg ;
		msg = (counts[2] > 0) ? msg + to_string(counts[2]) + " Triangle(s), " : msg ;
		msg = (counts[3] > 0) ? msg + to_string(counts[3]) + " Square(s), " : msg ;
		msg = (counts[4] > 0) ? msg + to_string(counts[4]) + " Circle(s), " : msg ;

		pOut->PrintMessage(msg);
		break;
	}
}