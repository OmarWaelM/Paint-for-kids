#include "PickByColourAction.h"
#include"time.h"
#include"ApplicationManager.h"

PickByColourAction::PickByColourAction(ApplicationManager* pApp):Action(pApp)
{
	Correct_Count = 0;
	Wrong_Count = 0;
}

void PickByColourAction::ReadActionParameters()
{
}

void PickByColourAction::Execute()
{
	pOut = pManager->GetOutput();
	pIn = pManager->GetInput();

	int param[2] = { -1, 7 };

	// if number of figures in list is zero 
	if (pManager->GetFigCount() == 0)
	{
		pOut->PrintMessage("No More Figures ");
	}
	else if (pManager->Get_Play_Mode_Count(param) == pManager->GetFigCount())
	{
		pOut->PrintMessage("There are no colored figures!");
	}
	else
	{
		srand(time(0));
		int r= rand() % pManager->GetFigCount();

		while (!pManager->GetFigListItem(r)->isFilled())
		{
			r = rand() % pManager->GetFigCount();
		}
		color clr = pManager->GetFigListItem(r)->Get_Filled_Colour();

		if (clr == BLACK)
		{
			pOut->PrintMessage("Pick by color: pick all Black Figures");
			param[1] = 1;
		}
		else if (clr == RED)
		{
			pOut->PrintMessage("Pick by color: pick all Red Figures");
			param[1] = 2;
		}
		else if (clr == ORANGE)
		{
			pOut->PrintMessage("Pick by color: pick all Orange Figures");
			param[1] = 3;
		}
		else if (clr == YELLOW)
		{
			pOut->PrintMessage("Pick by color: pick all Yellow Figures");
			param[1] = 4;

		}
		else if (clr == GREEN)
		{
			pOut->PrintMessage("Pick by color: pick all Green Figures");
			param[1] = 5;
		}
		else if (clr == BLUE)
		{
			pOut->PrintMessage("Pick by color: pick all Blue Figures");
			param[1] = 6;
		}

		while (Total_Count > 0)
		{
			pIn->GetPointClicked(Clicked.x, Clicked.y);
			pFig = pManager->GetFigure(Clicked.x, Clicked.y);

			if (pFig != NULL)
			{
				if (clr == pFig->Get_Filled_Colour())
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
			+ to_string(Correct_Count + Wrong_Count) + " total choices");
	}
}