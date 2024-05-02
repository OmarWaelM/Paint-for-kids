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
	pOut->PrintMessage("Your file was saved successfully")
}

void SaveGraphAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	color DrawColour;
	color FillColour;

	if (pOut->getCrntDrawColor() == BLACK)
		DrawColour = BLACK;
	else if (pOut->getCrntDrawColor() == YELLOW)
		DrawColour = YELLOW;
	else if (pOut->getCrntDrawColor() == ORANGE)
		DrawColour = ORANGE;
	else if (pOut->getCrntDrawColor() == RED)
		DrawColour = RED;
	else if (pOut->getCrntDrawColor() == GREEN)
		DrawColour = GREEN;
	else if (pOut->getCrntDrawColor() == BLUE)
		DrawColour = BLUE;

	if (pOut->getCrntFillColor() == BLACK)
		FillColour = BLACK;
	else if (pOut->getCrntFillColor() == YELLOW)
		FillColour = YELLOW;
	else if (pOut->getCrntFillColor() == ORANGE)
		FillColour = ORANGE;
	else if (pOut->getCrntFillColor() == RED)
		FillColour = RED;
	else if (pOut->getCrntFillColor() == GREEN)
		FillColour = GREEN;
	else if (pOut->getCrntFillColor() == BLUE)
		FillColour = BLUE;
	else FillColour = LIGHTGOLDENRODYELLOW;

	ifstream FileExistsCheck(FileName + ".txt");
	if (FileExistsCheck.good())
	{
		FileExistsCheck.close();
	}
	if (FillColour == LIGHTGOLDENRODYELLOW)
	{
		ofstream OutputFile;
		OutputFile.open(FileName + ".txt", ios::out);
		OutputFile << DrawColour << "	" << "NO FILL COLOUR" << endl;
		pManager->SaveAllFigures(OutputFile);
		OutputFile.close();
	}
	else
	{
		ofstream OutputFile;
		OutputFile.open(FileName + ".txt", ios::out);
		OutputFile << DrawColour << "	" << FillColour << endl;
		pManager->SaveAllFigures(OutputFile);
		OutputFile.close();
	}
	
}
