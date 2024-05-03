#include "SaveGraphAction.h"
#include <fstream>
#include "colors.h"

SaveGraphAction::SaveGraphAction(ApplicationManager* pApp): Action(pApp) {}

void SaveGraphAction::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Please enter the file name that's to be saved");
	FileName = pIn->GetSrting(pOut);
	pOut->PrintMessage("Your file was saved successfully");
}

void SaveGraphAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	color CrntDrawColour;
	color CrntFillColour;

	if (pOut->getCrntDrawColor() == BLACK)
		CrntDrawColour = BLACK;
	else if (pOut->getCrntDrawColor() == YELLOW)
		CrntDrawColour = YELLOW;
	else if (pOut->getCrntDrawColor() == ORANGE)
		CrntDrawColour = ORANGE;
	else if (pOut->getCrntDrawColor() == RED)
		CrntDrawColour = RED;
	else if (pOut->getCrntDrawColor() == GREEN)
		CrntDrawColour = GREEN;
	else if (pOut->getCrntDrawColor() == BLUE)
		CrntDrawColour = BLUE;

	if (pOut->getCrntFillColor() == BLACK)
		CrntFillColour = BLACK;
	else if (pOut->getCrntFillColor() == YELLOW)
		CrntFillColour = YELLOW;
	else if (pOut->getCrntFillColor() == ORANGE)
		CrntFillColour = ORANGE;
	else if (pOut->getCrntFillColor() == RED)
		CrntFillColour = RED;
	else if (pOut->getCrntFillColor() == GREEN)
		CrntFillColour = GREEN;
	else if (pOut->getCrntFillColor() == BLUE)
		CrntFillColour = BLUE;
	else CrntFillColour = LIGHTGOLDENRODYELLOW;

	ifstream FileExistsCheck(FileName + ".txt");
	if (FileExistsCheck.good())
	{
		FileExistsCheck.close();
	}
	if (CrntFillColour == LIGHTGOLDENRODYELLOW)
	{
		ofstream OutputFile;
		OutputFile.open(FileName + ".txt", ios::out);
		OutputFile << CrntDrawColour << "	" << "NO FILL COLOUR" << endl;
		pManager->SaveAllFigures(OutputFile);
		OutputFile.close();
	}
	else
	{
		ofstream OutputFile;
		OutputFile.open(FileName + ".txt", ios::out);
		OutputFile << CrntDrawColour << "	" << CrntFillColour << endl;
		pManager->SaveAllFigures(OutputFile);
		OutputFile.close();
	}
	
}
