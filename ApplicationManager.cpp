#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "AddCircleAction.h"
#include "AddHexagonAction.h"
#include "AddSquareAction.h"
#include "AddTriangleAction.h"
#include"PickByTypeAction.h"
#include"DeleteAction.h"

#include "SelectFigure.h"
#include "DeleteAction.h"
#include "SendToBack.h"
#include "BringToFront.h"


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



		case TO_SENDBACK:
			pAct = new SendToBack(this);
			break;

		case TO_BRINGFRONT:
			pAct = new BringToFront(this);
			break;

	 case TO_FIGURETYPE:
		 pAct = new PickByTypeAction(this);
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

void ApplicationManager::Reset_Figure_Count()
{
	Rectangle_Count = 0;
	Square_Count = 0;
	Triangle_Count = 0;
	Hexagon_Count = 0;
	Circle_Count = 0;
}

void ApplicationManager::Count_Figure_Types()
{
	Reset_Figure_Count();

	for (int i = 0; i < FigCount; i++)
	{
		char Type = FigList[i]->Get_My_Type();

		if (Type == 'R')
			Rectangle_Count++;

		if (Type == 'C')
			Circle_Count++;

		if (Type == 'H')
			Hexagon_Count++;

		if (Type += 'T')
			Triangle_Count++;

		if (Type == 'S')
			Square_Count++;

	}
}

int ApplicationManager::Get_Circle_Count()
{
	return Circle_Count;
}

int ApplicationManager::Get_Triangle_Count()
{
	return Triangle_Count;
}

int ApplicationManager::Get_Square_Count()
{
	return Square_Count;
}

int ApplicationManager::Get_Rectangle_Count()
{
	return Rectangle_Count;
}

int ApplicationManager::Get_Hexagon_Count()
{
	return Hexagon_Count;
}

char ApplicationManager::Get_Random_Type(int ix) // returns type of figure according to its place in the array
{
	return FigList[ix]->Get_My_Type();
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
void ApplicationManager::Reset_Fill_Colour()
{
	Yellow_Figures = 0;
	Blue_Figures = 0;
	Black_Figures = 0;
	Green_Figures = 0;
	Orange_Figures = 0;
	Red_Figures = 0;
	No_Filled_Figure = 0;
}
void ApplicationManager::Count_Fill_Colour()
{
	Reset_Fill_Colour();

	for (int i = 0; i < FigCount; i++)
	{
		if (!FigList[i]->isFilled())
		{
			No_Filled_Figure++;
		}
		else
		{
			color c = FigList[i]->Get_Filled_Colour();

			if (c == RED)
				Red_Figures++;
			if (c == ORANGE)
				Orange_Figures++;
			if (c == BLACK)
				Black_Figures++;
			if (c == GREEN)
				Green_Figures++;
			if (c == YELLOW)
				Yellow_Figures++;
			if (c == BLUE)
				Blue_Figures++;
		}


	}
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
