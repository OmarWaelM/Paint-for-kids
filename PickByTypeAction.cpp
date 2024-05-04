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
		
		Total_Count = pManager->Get_Play_Mode_Count(params);
		
		string message = "Pick by type: pick all ";
		switch (params[0])
		{
		case (1):
			message = message + "Rectangle(s)";
			break;
		case (2):
			message = message + "Hexagon(s)";
			break;
		case (3):
			message = message + "Triangle(s)";
			break;
		case (4):
			message = message + "Square(s)";
			break;
		case (5):
			message = message + "Circle(s)";
			break;
		};

		pOut->PrintMessage(message + " : " + to_string(Correct_Count) + " / " + to_string(Total_Count + Correct_Count));

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
					pManager->UpdateInterface();
					pOut->PrintMessage(message + " : " + to_string(Correct_Count) + " / " + to_string(Total_Count + Correct_Count));
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
