#include "PickByColourAction.h"
#include"time.h"
PickByColourAction::PickByColourAction(ApplicationManager* pApp):Action(pApp)
{
}

void PickByColourAction::ReadActionParameters()
{
}

void PickByColourAction::Execute()
{
	pOut = pManager->GetOutput();
	pIn = pManager->GetInput();

	// if number of figures in list is zero 
	if (pManager->GetFigCount() == 0)
	{
		pOut->PrintMessage("No More Figures ");
	}

	pManager->Count_Fill_Colour();

	int No_Filled_Figures = pManager->Get_No_Filled_Figure();
	if (No_Filled_Figures==pManager->GetFigCount())
	{
		pOut->PrintMessage("There are no colored figures!");
	}

	srand(time(0));
	int r= rand() % pManager->GetFigCount();
	


}

void PickByColourAction::Execute_Body(FillColors fillclr, int TotalCount)
{
	while (Total_Count > 0)
	{
		pIn->GetPointClicked(Clicked.x, Clicked.y);
		pFig = pManager->GetFigure(Clicked.x, Clicked.y);

		if (pFig == NULL)
		{
			pOut->PrintMessage("You clicked on an empty space");
		}
		if (pFig->Get_Filled_Colour() == fillclr)
		{
			pManager->Delete_Figure(pFig);
			Correct_Count++;
			Total_Count--;
			pOut->PrintMessage("You are only " + to_string(Total_Count) + " correct clicks away from winning the game!");
		}

		else
		{
			pManager->Delete_Figure(pFig);
			Wrong_Count++;
			pOut->PrintMessage("Try again! Try clicking on a figure");
		}
		pManager->UpdateInterface();
	}
	pOut->PrintMessage("Won the game,score:Correct clicks: " + to_string(Correct_Count) + " Wrong clicks: " + to_string(Wrong_Count));
}

