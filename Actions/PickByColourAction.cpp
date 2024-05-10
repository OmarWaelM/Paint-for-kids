#include "..\Actions\PickByColourAction.h"
#include "time.h"
#include "..\ApplicationManager.h"

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

	int param[2] = { -1, 7 };   // -1:I am working on the colour now // 7:6 colours + unfilled

	// if number of figures in list is zero 
	if (pManager->GetFigCount() == 0)
	{
		pOut->PrintMessage("No More Figures ");
	}
	else if (pManager->Get_Play_Mode_Count(param) == pManager->GetFigCount())  // if unfilled figures==figcount
	{
		pOut->PrintMessage("There are no colored figures!");
	}
	else
	{
		srand(time(0));
		int r= rand() % pManager->GetFigCount();

		while (!pManager->GetFigListItem(r)->isFilled())  // if fig not filled, ytala3 random number again
		{
			r = rand() % pManager->GetFigCount();
		}
		color clr = pManager->GetFigListItem(r)->Get_Filled_Colour();

		string message = "Pick by color: pick all ";

		if (clr == BLACK)
		{
			message = message + " Black Figures";
			param[1] = 1;
		}
		else if (clr == RED)
		{
			message = message + " Red Figures";
			param[1] = 2;
		}
		else if (clr == ORANGE)
		{
			message = message + " Orange Figures";
			param[1] = 3;
		}
		else if (clr == YELLOW)
		{
			message = message + " Yellow Figures";
			param[1] = 4;

		}
		else if (clr == GREEN)
		{
			message = message + " Greeb Figures";
			param[1] = 5;
		}
		else if (clr == BLUE)
		{
			message = message + " Blue Figures";
			param[1] = 6;
		}

		Total_Count = pManager->Get_Play_Mode_Count(param);

		pOut->PrintMessage(message + " : " + to_string(Correct_Count) + " / " + to_string(Total_Count + Correct_Count));

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
					pManager->UpdateInterface();
					pOut->PrintMessage(message + " : " + to_string(Correct_Count) + " / " + to_string(Total_Count + Correct_Count));
				}
				else
					Wrong_Count++;
			}
		}
		pOut->PrintMessage("Game done! you scored " + to_string(Correct_Count) + " correct choices from "
			+ to_string(Correct_Count + Wrong_Count) + " total choices");
	}
}