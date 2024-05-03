#include "LoadGraphAction.h"
#include "CFigure.h"
#include "ClearAllAction.h"
#include <fstream>

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
		pOut->setCrntDrawColor(BLACK);
	else if (CrntDrawCol == "YELLOW")
		pOut->setCrntDrawColor(YELLOW);
	else if (CrntDrawCol == "ORANGE")
		pOut->setCrntDrawColor(ORANGE);
	else if (CrntDrawCol == "RED")
		pOut->setCrntDrawColor(RED);
	else if (CrntDrawCol == "GREEN")
		pOut->setCrntDrawColor(GREEN);
	else if (CrntDrawCol == "BLUE")
		pOut->setCrntDrawColor(BLUE);

	if (CrntFillCol == "BLACK")
		pOut->setCrntFillColor(BLACK);
	else if (FillCol == "YELLOW")
		pOut->setCrntFillColor(YELLOW);
	else if (FillCol == "ORANGE")
		pOut->setCrntFillColor(ORANGE);
	else if (FillCol == "RED")
		pOut->setCrntFillColor(RED);
	else if (FillCol == "GREEN")
		pOut->setCrntFillColor(GREEN);
	else if (FillCol == "BLUE")
		pOut->setCrntFillColor(BLUE);

	InputFile >> CountFig;
	
	for (int i = 0; i < n; i++)
	{
		InputFile >> Figuretype >> id;
		CFigure* s = NULL;

		if (Figuretype == "RECTANGLE")
		{

		}
	}
}
