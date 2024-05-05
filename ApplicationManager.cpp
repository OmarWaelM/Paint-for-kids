#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "AddCircleAction.h"
#include "AddHexagonAction.h"
#include "AddSquareAction.h"
#include "AddTriangleAction.h"
#include "PickByTypeAction.h"
#include "PickByColourAction.h"
#include "PickByBothAction.h"
#include "DeleteAction.h"
#include "SelectFigure.h"
#include "DeleteAction.h"
#include "SendToBack.h"
#include "BringToFront.h"
#include "ChangeFillColor.h"
#include "ChangeBoarderColor.h"
#include "ClearAllAction.h"
#include "SaveGraphAction.h"
#include "LoadGraphAction.h"
#include "SwitchToPlayModeAction.h"
#include "SwitchToDrawModeAction.h"
#include "ExitAction.h"

#include "CopyAction.h"
#include "CutAction.h"
#include "PasteAction.h"
#include "Figures/CRectangle.h"
#include "CCircle.h"
#include "CHexagon.h"
#include "CSquare.h"
#include "CTriangle.h"

//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();

	FigCount = 0;
	SelCount = 0;
	//Create an array of figure pointers and set them to NULL		
	for (int i = 0; i < MaxFigCount; i++)
	{
		FigList[i] = NULL;
		SelectedFig[i] = NULL;
	}
	Clipboard = NULL;
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
		case DRAW_RECT:
			pAct = new AddRectAction(this);
			break;

		case DRAW_HEXAGON:
			pAct = new AddHexagonAction(this);
			break;

		case DRAW_CIRCLE:
			pAct = new AddCircleAction(this);
			break;

		case DRAW_TRIANGLE:
			pAct = new AddTriangleAction(this);
			break;

		case DRAW_SQUARE:
			pAct = new AddSquareAction(this);
			break;
      
		case TO_CHANGEFILL:
			pAct = new ChangeFillColor(this);
			break;

		case TO_CHANGEBORDER:
			pAct = new ChangeBoarderColor(this);
			break;

		case TO_SELECT:
			pAct = new SelectFigure(this);
			break;

		case TO_DELETEFIGURE:
			pAct = new DeleteAction(this);
			break;

		case TO_SENDBACK:
			pAct = new SendToBack(this);
			break;

		case TO_BRINGFRONT:
			pAct = new BringToFront(this);
			break;

		case TO_FIGURETYPE:
			pAct = new PickByTypeAction(this);
			break;

		case TO_FILLCOLOUR:
			pAct = new PickByColourAction(this);
			break;


		case TO_SAVEGRAPH:
			pAct = new SaveGraphAction(this);
			break;

		case TO_LOADGRAPH:
			pAct = new LoadGraphAction(this);
			break;

		case TO_PLAY:
			pAct = new SwitchToPlayModeAction(this);
			break;

		case TO_DRAW:
			pAct = new SwitchToDrawModeAction(this);
			break;

		case TO_CLEARALL:
			pAct = new ClearAllAction(this);
			break;
		case TO_COPYFIGURE:
			pAct = new CopyAction(this);
			break;

		case TO_CUTFIGURE:
			pAct = new CutAction(this);
			break;

		case TO_PASTEFIGURE:
			pAct = new PasteAction(this);
			break;

		case TO_FIGUREANDFILL:
			pAct = new PickByBothAction(this);
			break;

		case EXIT:
			pAct = new ExitAction(this);
			break;
		
		case STATUS:	//a click on the status bar ==> no action
			return;
	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//You may need to change this line depending to your implementation
		pAct = NULL;
	}
}

//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if(FigCount < MaxFigCount )
		FigList[FigCount++] = pFig;	
}
////////////////////////////////////////////////////////////////////////////////////
void ApplicationManager::Delete_Figure(CFigure* pFig)
{
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i] == pFig)
		{
			delete FigList[i];
			// shifting array
			for (int j = i; j < FigCount - 1; j++)
				FigList[j] = FigList[j + 1];
			FigList[FigCount - 1] = NULL;
			FigCount--;
		}
	}
}
////////////////////////////////////////////////////////////////////////////////////
void ApplicationManager::MoveFig(CFigure* Fig, int in)
{
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i] == Fig)
		{
			if (i > in)
			{
				for (int j = i-1; j >= in; j--)
					FigList[j + 1] = FigList[j];
				FigList[in] = Fig;
			}
			else
			{
				for (int j = i + 1; j <= in; j++)
					FigList[j - 1] = FigList[j];
				FigList[in] = Fig;
			}
		}
	}
}
////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL
	Point P; 
	P.x = x; P.y = y;

	for (int i = FigCount-1; i >= 0; i--)
	{
		if (FigList[i]->IsWithin(P))
			return FigList[i];
	}
	//Add your code here to search for a figure given a point x,y	
	//Remember that ApplicationManager only calls functions do NOT implement it.

	return NULL;
}
////////////////////////////////////////////////////////////////////////////////////
int ApplicationManager::Get_Play_Mode_Count(int param[2]) // param [ Figure type, Figure Color ]
{
	//Figures : Rect, Hex, Triangle, Square, Circle
	//Colors : Black, Red Orange, Yellow, Green, Blue, Unfilled
	int count = 0;
	
	for (int i = 0; i < FigCount; i++)
	{
		bool condFig = (param[0] == -1);
		bool condCol = (param[1] == -1);
		switch (param[0])
		{
		case 1:
			condFig = (dynamic_cast<CRectangle*>(FigList[i]) != NULL);
			break;

		case 2:
			condFig = (dynamic_cast<CHexagon*>(FigList[i]) != NULL);
			break;

		case 3:
			condFig = (dynamic_cast<CTriangle*>(FigList[i]) != NULL);
			break;

		case 4:
			condFig = (dynamic_cast<CSquare*>(FigList[i]) != NULL);
			break;

		case 5:
			condFig = (dynamic_cast<CCircle*>(FigList[i]) != NULL);
			break;

		default:
			break;
		}
		
		switch (param[1])
		{
		case 1:
			condCol = (FigList[i]->Get_Filled_Colour() == BLACK);
			break;

		case 2:
			condCol = (FigList[i]->Get_Filled_Colour() == RED);
			break;

		case 3:
			condCol = (FigList[i]->Get_Filled_Colour() == ORANGE);
			break;

		case 4:
			condCol = (FigList[i]->Get_Filled_Colour() == YELLOW);
			break;

		case 5:
			condCol = (FigList[i]->Get_Filled_Colour() == GREEN);
			break;

		case 6:
			condCol = (FigList[i]->Get_Filled_Colour() == BLUE);
			break;

		case 7:
			condCol = (FigList[i]->isFilled() == false);
			break;

		default:
			break;
		}
		
		if (condFig && condCol)
			count++;
	}
	return count;
}
////////////////////////////////////////////////////////////////////////////////////
void ApplicationManager::AddSelected(CFigure* sFig)
{
	SelectedFig[SelCount++] = sFig;
	sFig->SetSelected(true);
}
////////////////////////////////////////////////////////////////////////////////////
void ApplicationManager::DeleteSelected(int i, CFigure* Fig)
{
	if (Fig == NULL)
	{
		SelectedFig[i]->SetSelected(false);
	}
	else
	{
		for (int j = 0; j < SelCount; j++)
		{
			if (SelectedFig[j] == Fig)
			{
				SelectedFig[j]->SetSelected(false);
				i = j;
			}
		}
	}
	for (int j = i; j < SelCount - 1; j++)
			SelectedFig[j] = SelectedFig[j + 1];
	SelectedFig[SelCount - 1] = NULL;
	SelCount--;
}
/////////////////////////////////////////////////////////////////
//Set Clipboard Function
void ApplicationManager::SetClipboard(CFigure* Fig)
{
	if (Clipboard != NULL)
	{
		if (Clipboard->IsCut())
		{
			Clipboard->SetCut(false);
		}
	}
	
	Clipboard = Fig;
}
//////////////////////////////////////////////////////////////
//Get Clipboard Function
CFigure* ApplicationManager::GetClipboard()
{
	return Clipboard;
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Save all figures
void ApplicationManager::SaveAllFigures(ofstream& OutputFile)
{
	OutputFile << FigCount << endl;
	for (int j = 0; j < FigCount; j++)
	{
		FigList[j]->Save(OutputFile);
	}
}

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	pOut->ClearDrawArea();
	for(int i=0; i<FigCount; i++)
	FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for (int i = 0; i < FigCount; i++)
	{
		SelectedFig[i] = NULL;
		delete FigList[i];
	}
	delete pIn;
	delete pOut;
	
}