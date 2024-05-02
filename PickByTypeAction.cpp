#include "PickByTypeAction.h"
#include "CCircle.h"
#include "Figures/CRectangle.h"
#include "CHexagon.h"
#include "CTriangle.h"
#include "CSquare.h"
#include <time.h>

PickByTypeAction::PickByTypeAction(ApplicationManager* pApp):Action(pApp)
{
	Correct_Count = 0;
	Wrong_Count = 0;
}

void PickByTypeAction::ReadActionParameters()
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
	else
	{
		srand(time(0));
		int r = rand() % pManager->GetFigCount(); // 34an ytala3 rakam 3a4wa2y // % :to check that random number netween 0 and figcount
		int params[2] = { getType(pManager->GetFigListItem(r)) , -1 };

		switch (params[0])
		{
		case (1):
			pOut->PrintMessage("Pick by type: pick all Rectangles");
			break;
		case (2):
			pOut->PrintMessage("Pick by type: pick all Hexagons");
			break;
		case (3):
			pOut->PrintMessage("Pick by type: pick all Triangles");
			break;
		case (4):
			pOut->PrintMessage("Pick by type: pick all Squares");
			break;
		case (5):
			pOut->PrintMessage("Pick by type: pick all Circles");
			break;
		};

		Total_Count = pManager->Get_Play_Mode_Count(params);

		while (Total_Count > 0)
		{
			pIn->GetPointClicked(Clicked.x, Clicked.y);
			pFig = pManager->GetFigure(Clicked.x, Clicked.y);
			if (pFig != NULL)
			{
				if (getType(pFig) == params[0])
				{
					Correct_Count++;
					Total_Count--;
					pManager->Delete_Figure(pFig);
				}
				else
					Wrong_Count++;
			}
		}
		pOut->PrintMessage("Game done! you scored " + to_string(Correct_Count) + " correct choices from "
			+ to_string(Correct_Count + Wrong_Count) + " choices");
	}
}

int PickByTypeAction::getType(CFigure* Fig)
{
	if (dynamic_cast<CRectangle*>(Fig) != NULL)
	{
		return 1;
	}
	else if (dynamic_cast<CHexagon*>(Fig) != NULL)
	{
		return 2;
	}
	else if (dynamic_cast<CTriangle*>(Fig) != NULL)
	{
		return 3;
	}
	else if (dynamic_cast<CSquare*>(Fig) != NULL)
	{
		return 4;
	}
	else if (dynamic_cast<CCircle*>(Fig) != NULL)
	{
		return 5;
	}
}

PickByTypeAction::~PickByTypeAction()
{
}
