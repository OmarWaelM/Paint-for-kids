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
	FillColors clr;

	switch (clr)
	{
	case black:
		pOut->PrintMessage("Pick by color: pick all Black Figures");
		Total_Count = pManager->GetBlack_Figures();
		Execute_Body(black, Total_Count);
		break;

	case red:
		pOut->PrintMessage("Pick by color: pick all Red Figures");
		Total_Count = pManager->Get_Red_Figures();
		Execute_Body(red, Total_Count);
		break;

	case orange:
		pOut->PrintMessage("Pick by color: pick all Orange Figures");
		Total_Count = pManager->Get_Orange_Figures();
		Execute_Body(orange, Total_Count);
		break;

	case yellow:
		pOut->PrintMessage("Pick by color: pick all Yellow Figures");
		Total_Count = pManager->Get_Yellow_Figures();
		Execute_Body(yellow, Total_Count);
		break;

	case green:
		pOut->PrintMessage("Pick by color: pick all Green Figures");
		Total_Count = pManager->Get_Green_Figures();
		Execute_Body(green, Total_Count);
		break;

	case blue:
		pOut->PrintMessage("Pick by color: pick all Blue Figures");
		Total_Count = pManager->Get_Blue_Figures();
		Execute_Body(blue, Total_Count);
		break;
	}
	
	pManager->Reset_Fill_Colour();


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

