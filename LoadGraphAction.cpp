#include "LoadGraphAction.h"
#include "Figures\CFigure.h"
#include "ClearAllAction.h"
#include <fstream>
#include "Figures\CRectangle.h"
#include "CCircle.h"
#include "Figures\CSquare.h"
#include "Figures\CTriangle.h"
#include "Figures\CHexagon.h"

LoadGraphAction::LoadGraphAction(ApplicationManager* pApp, bool check): Action(pApp) {}

void LoadGraphAction::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Please enter the file name to load it");
	FileName = pIn->GetSrting(pOut);
}

void LoadGraphAction::Execute()
{
	if (check == false)
		ReadActionParameters();
	else FileName = "Pre-switch File";

	Output* pOut = pManager->GetOutput();
	ClearAllAction C(pManager);
	C.Execute();
	GfxInfo FigureGfxInfo;
	
	int CountFig, id;
	string CrntDrawCol, CrntFillCol, Figuretype;

	ifstream InputFile;
	InputFile.open(FileNme + ".txt");
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
	else if (FillCol == "YELLOW")
		UI.FillColor = YELLOW;
	else if (FillCol == "ORANGE")
		UI.FillColor = ORANGE;
	else if (FillCol == "RED")
		UI.FillColor = RED;
	else if (FillCol == "GREEN")
		UI.FillColor = GREEN;
	else if (FillCol == "BLUE")
		UI.FillColor = BLUE;

	InputFile >> CountFig;

	// Declaring dummy parameters: A Point and FigureGfxInfo's members to utilize and call the Load function of each figure type //
	Point P1;
	P1.x = 0; P1.y = 0;
	FigureGfxInfo.DrawClr = BLACK;
	FigureGfxInfo.isFilled = true;
	FigureGfxInfo.FillClr = BLACK;
	
	for (int i = 0; i < n; i++)
	{
		InputFile >> Figuretype >> id;
		CFigure* pFig = NULL;

		if (Figuretype == "RECTANGLE")
		{
			CRectangle Rect(P1, P1, FigureGfxInfo);
			Rect.Load(InputFile, pFig);
			pManager->AddFigure(pFig);
		}
		else if (Figuretype == "HEXAGON")
		{
			CHexagon Hex(P1, FigureGfxInfo);
			Hex.Load(InputFile, pFig);
			pManager->AddFigure(pFig);
		}
		else if (Figuretype == "TRIANGLE")
		{
			CTriangle Tri(P1, P1, P1, FigureGfxInfo);
			Tri.Load(InputFile, pFig);
			pManager->AddFigure(pFig);
		}
		else if (Figuretype == "SQUARE")
		{
			CSquare SQ(P1, FigureGfxInfo);
			SQ.Load(InputFile, pFig);
			pManager->AddFigure(pFig);
		}
		else if (Figuretype == "CIRCLE")
		{
			CCircle Circ(P1, P1, FigureGfxInfo);
			Circ.Load(InputFile, pFig);
			pManager->AddFigure(pFig);
		}
	}
	InputFile.close();
}
