#include "..\Actions\PickByBothAction.h"
#include "..\Figures\CCircle.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\CHexagon.h"
#include "..\Figures\CSquare.h"
#include "..\Figures\CTriangle.h"
#include <time.h>

PickByBothAction::PickByBothAction(ApplicationManager* pApp) :Action(pApp)
{
	Correct_Count = 0;
	Wrong_Count = 0;
}

void PickByBothAction::ReadActionParameters() {}

void PickByBothAction::Execute()
{
	pOut = pManager->GetOutput();
	pIn = pManager->GetInput();

	int param[2] = {-1, 7};

	// if number of figures in list is zero 
	if (pManager->GetFigCount() == 0)
	{
		pOut->PrintMessage("No More Figures ");
	}
	else if (pManager->Get_Play_Mode_Count(param) == pManager->GetFigCount()) // if not colored figures exist
	{
		pOut->PrintMessage("There are no colored figures!");
	}
	else
	{
		srand(time(0));
		int r = rand() % pManager->GetFigCount();
		while (!pManager->GetFigListItem(r)->isFilled())
		{
			r = rand() % pManager->GetFigCount();
		}
		color clr = pManager->GetFigListItem(r)->Get_Filled_Colour();

		param[0] = getType(pManager->GetFigListItem(r));

		if (clr == BLACK) param[1] = 1;
		else if (clr == RED) param[1] = 2;
		else if (clr == ORANGE) param[1] = 3;
		else if (clr == YELLOW) param[1] = 4;
		else if (clr == GREEN) param[1] = 5;
		else if (clr == BLUE) param[1] = 6;
		
		Total_Count = pManager->Get_Play_Mode_Count(param);
		//Creating output message
		string message = "Pick by both: Pick all ";

		switch (param[1])
		{
		case (1):
			message = message + "Black ";
			break;
		case (2):
			message = message + "Red ";
			break;
		case (3):
			message = message + "Orange ";
			break;
		case (4):
			message = message + "Yellow ";
			break;
		case (5):
			message = message + "Green ";
			break;
		case (6):
			message = message + "Blue ";
			break;
		}

		switch (param[0])
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
		}

		pOut->PrintMessage(message + " : " + to_string(Correct_Count) + " / " + to_string(Total_Count + Correct_Count));

		while (Total_Count > 0)
		{
			pIn->GetPointClicked(Clicked.x, Clicked.y);
			pFig = pManager->GetFigure(Clicked.x, Clicked.y);

			if (pFig != NULL)
			{
				if (clr == pFig->Get_Filled_Colour() && param[0] == getType(pFig)) //checks both type and fill conditions
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

int PickByBothAction::getType(CFigure* Fig)
{
	if (dynamic_cast<CRectangle*>(Fig) != NULL)
	{
		return 1;
	}
	if (dynamic_cast<CHexagon*>(Fig) != NULL)
	{
		return 2;
	}
	if (dynamic_cast<CTriangle*>(Fig) != NULL)
	{
		return 3;
	}
	if (dynamic_cast<CSquare*>(Fig) != NULL)
	{
		return 4;
	}
	if (dynamic_cast<CCircle*>(Fig) != NULL)
	{
		return 5;
	}
}

PickByBothAction::~PickByBothAction() {}