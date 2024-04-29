#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "AddCircleAction.h"
#include "AddHexagonAction.h"
#include "AddSquareAction.h"
#include "AddTriangleAction.h"

#include"DeleteAction.h"

#include "SelectFigure.h"
#include "DeleteAction.h"


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
      
		case TO_SELECT:
			pAct = new SelectFigure(this);
			break;

		case TO_DELETEFIGURE:
			pAct = new DeleteAction(this);
			break;

		case EXIT:
			///create ExitAction here
			
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
			for (int j = i; j < FigCount - 1; j++)
				FigList[j] = FigList[j + 1];
			FigList[FigCount - 1] = NULL;
			FigCount--;
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
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

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
