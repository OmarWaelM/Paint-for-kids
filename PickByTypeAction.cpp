#include "PickByTypeAction.h"
#include "CCircle.h"
#include "Figures/CRectangle.h"
#include "CHexagon.h"
#include "CTriangle.h"
#include "CSquare.h"
PickByTypeAction::PickByTypeAction(ApplicationManager* pApp):Action(pApp)
{
}

void PickByTypeAction::ReadParameters()
{
}

void PickByTypeAction::Execute()
{
	pOut = pManager->GetOutput();
	pIn = pManager->GetInput();

	// if number of figures in list is zero 
	if (pManager->GetFigCount() == 0)
	{
		pOut->PrintMessage("No More Figures ");
	}

	//srand(time(0));
	int r = rand() % pManager->GetFigCount();
	char Type = pManager->Get_Random_Type(r);// returns type of figure according to its place in the array

	switch (Type)
	{
	case 'C':
		pOut->PrintMessage("Pick by type: pick all Circles");
		Total_Count = pManager->Get_Circle_Count();
		Execute_Body(Type, Total_Count);
		break;

	case 'R':
		pOut->PrintMessage("Pick by type: pick all Rectangles");
		Total_Count = pManager->Get_Rectangle_Count();
		Execute_Body(Type, Total_Count);
		break;

	case 'T':
		pOut->PrintMessage("Pick by type: pick all Triangles");
		Total_Count = pManager->Get_Triangle_Count();
		Execute_Body(Type, Total_Count);
		break;

	case 'H':
		pOut->PrintMessage("Pick by type: pick all Hexagons");
		Total_Count = pManager->Get_Hexagon_Count();
		Execute_Body(Type, Total_Count);
		break;

	}

	pManager->Reset_Figure_Count();
}

void PickByTypeAction::Execute_Body(char Type, int Total_Count)
{
	while (Total_Count > 0)
	{
		pIn->GetPointClicked(Clicked.x, Clicked.y);
		pFig = pManager->GetFigure(Clicked.x, Clicked.y);

		if (pFig->Get_My_Type() == Type)
		{
			pManager->Delete_Figure(pFig);
			Correct_Count++;
			Total_Count--;
		}

		if (pFig == NULL)
		{
			pOut->PrintMessage("You clicked on an empty space");
		}

		else
		{
			pManager->Delete_Figure(pFig);
			Wrong_Count++;

		}
		pManager->UpdateInterface();
	}
}
