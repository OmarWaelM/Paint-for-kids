#include "..\Actions\LoadGraphAction.h"
#include "..\Figures\CFigure.h"
#include "..\Actions\ClearAllAction.h"
#include <fstream>
#include "..\Figures\CRectangle.h"
#include "..\Figures\CCircle.h"
#include "..\Figures\CSquare.h"
#include "..\Figures\CTriangle.h"
#include "..\Figures\CHexagon.h"

LoadGraphAction::LoadGraphAction(ApplicationManager* pApp, bool check): Action(pApp), check(check) {}

void LoadGraphAction::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Please enter the file name to load it");
	FileName = pIn->GetSrting(pOut);
}

void LoadGraphAction::Execute()
{
	//To check whether the file is beinng loaded naturally or due to switching to draw mode, and not prompting the user to enter a file name in the latter case
	if (check == false)
		ReadActionParameters();
	else FileName = "Pre-switch File";

	Output* pOut = pManager->GetOutput();
	ClearAllAction C(pManager);
	C.Execute();
	GfxInfo FigureGfxInfo;
	
	int CountFig;
	string CrntDrawCol, CrntFillCol, Figuretype;

	ifstream InputFile;
	InputFile.open(FileName + ".txt");

	while (InputFile.fail())
	{
		pOut->PrintMessage("This file does not exist! Please re-enter a file name that exists to load it");
		FileName = pIn->GetSrting(pOut);
		InputFile.open(FileName + ".txt");
	}

	InputFile >> CrntDrawCol >> CrntFillCol;

	if (CrntDrawCol == "BLACK")
		UI.DrawColor = BLACK;
	else if (CrntDrawCol == "YELLOW")
		UI.DrawColor = YELLOW;
	else if (CrntDrawCol == "ORANGE")
		UI.DrawColor = ORANGE;
	else if (CrntDrawCol == "RED")
		UI.DrawColor = RED;
	else if (CrntDrawCol == "GREEN")
		UI.DrawColor = GREEN;
	else if (CrntDrawCol == "BLUE")
		UI.DrawColor = BLUE;

	if (CrntFillCol == "BLACK")
		UI.FillColor = BLACK;
	else if (CrntFillCol == "YELLOW")
		UI.FillColor = YELLOW;
	else if (CrntFillCol == "ORANGE")
		UI.FillColor = ORANGE;
	else if (CrntFillCol == "RED")
		UI.FillColor = RED;
	else if (CrntFillCol == "GREEN")
		UI.FillColor = GREEN;
	else if (CrntFillCol == "BLUE")
		UI.FillColor = BLUE;

	InputFile >> CountFig;

	// Declaring dummy parameters: A Point and FigureGfxInfo's members to utilize and call the Load function of each figure type //
	Point P1;
	P1.x = 0; P1.y = 0;
	FigureGfxInfo.DrawClr = BLACK;
	FigureGfxInfo.isFilled = true;
	FigureGfxInfo.FillClr = BLACK;
	
	for (int i = 0; i < CountFig; i++)
	{
		InputFile >> Figuretype;
		CFigure* pFig = NULL;

		if (Figuretype == "RECTANGLE")
		{
			pFig = new CRectangle(P1, P1, FigureGfxInfo);
			pFig->Load(InputFile);
			pManager->AddFigure(pFig);
		}
		else if (Figuretype == "HEXAGON")
		{
			pFig = new CHexagon(P1, FigureGfxInfo);
			pFig->Load(InputFile);
			pManager->AddFigure(pFig);
		}
		else if (Figuretype == "TRIANGLE")
		{
			pFig = new CTriangle(P1, P1, P1, FigureGfxInfo);
			pFig->Load(InputFile);
			pManager->AddFigure(pFig);
		}
		else if (Figuretype == "SQUARE")
		{
			pFig = new CSquare(P1, FigureGfxInfo);
			pFig->Load(InputFile);
			pManager->AddFigure(pFig);
		}
		else if (Figuretype == "CIRCLE")
		{
			pFig = new CCircle(P1, P1, FigureGfxInfo);
			pFig->Load(InputFile);
			pManager->AddFigure(pFig);
		}
	}
	InputFile.close();
}
