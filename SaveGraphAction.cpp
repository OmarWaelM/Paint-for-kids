#include "SaveGraphAction.h"
#include <fstream>

SaveGraphAction::SaveGraphAction(ApplicationManager* pApp): Action(pApp) {}

void SaveGraphAction::ReadActionParameters()
{
	int x, y;
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Please enter the file name that's to be saved");
	FileName = pIn->GetSrting(pOut);
	pOut->PrintMessage("Your file was saved successfully")
}

void SaveGraphAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	int DrawColour;
	int FillColour;

	if (pOut->getCrntDrawColor() == BLACK)
		DrawColour = BLACK_COLOUR;
	else if (pOut->getCrntDrawColor() == YELLOW)
		DrawColour = YELLOW_COLOUR;
	else if (pOut->getCrntDrawColor() == ORANGE)
		DrawColour = ORANGE_COLOUR;
	else if (pOut->getCrntDrawColor() == RED)
		DrawColour = RED_COLOUR;
	else if (pOut->getCrntDrawColor() == GREEN)
		DrawColour = GREEN_COLOUR;
	else if (pOut->getCrntDrawColor() == BLUE)
		DrawColour = BLUE_COLOUR;

	if (pOut->getCrntFillColor() == BLACK)
		FillColour = BLACK_COLOUR;
	else if (pOut->getCrntFillColor() == YELLOW)
		FillColour = YELLOW_COLOUR;
	else if (pOut->getCrntFillColor() == ORANGE)
		FillColour = ORANGE_COLOUR;
	else if (pOut->getCrntFillColor() == RED)
		FillColour = RED_COLOUR;
	else if (pOut->getCrntFillColor() == GREEN)
		FillColour = GREEN_COLOUR;
	else if (pOut->getCrntFillColor() == BLUE)
		FillColour = BLUE_COLOUR;
	else FillColour = NO_FILL_COLOUR;

	ifstream FileExistsCheck(FileName + ".txt");
	if (FileExistsCheck)
	{
		FileExistsCheck.close();
		ofstream OutputFile;
		OutputFile.open(FileName + ".txt", ios::out);
		OutputFile << DrawColour << "  " << FillColour << endl;
		pManager->SaveAllFigures(OutputFile);
		OutputFile.close();
	}

	ofstream OutputFile;
	OutputFile.open(FileName + ".txt", ios::out);
	OutputFile << DrawColour << "  " << FillColour << endl;
	pManager->SaveAllFigures(OutputFile);
	OutputFile.close();
}
