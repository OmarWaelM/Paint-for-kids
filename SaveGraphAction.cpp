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
	int CrntDrawColour;
	int CrntFillColour;

	if (pOut->getCrntDrawColor() == BLACK)
		CrntDrawColour = BLACK_COLOUR;
	else if (pOut->getCrntDrawColor() == YELLOW)
		CrntDrawColour = YELLOW_COLOUR;
	else if (pOut->getCrntDrawColor() == ORANGE)
		CrntDrawColour = ORANGE_COLOUR;
	else if (pOut->getCrntDrawColor() == RED)
		CrntDrawColour = RED_COLOUR;
	else if (pOut->getCrntDrawColor() == GREEN)
		CrntDrawColour = GREEN_COLOUR;
	else if (pOut->getCrntDrawColor() == BLUE)
		CrntDrawColour = BLUE_COLOUR;

	if (pOut->getCrntFillColor() == BLACK)
		CrntFillColour = BLACK_COLOUR;
	else if (pOut->getCrntFillColor() == YELLOW)
		CrntFillColour = YELLOW_COLOUR;
	else if (pOut->getCrntFillColor() == ORANGE)
		CrntFillColour = ORANGE_COLOUR;
	else if (pOut->getCrntFillColor() == RED)
		CrntFillColour = RED_COLOUR;
	else if (pOut->getCrntFillColor() == GREEN)
		CrntFillColour = GREEN_COLOUR;
	else if (pOut->getCrntFillColor() == BLUE)
		CrntFillColour = BLUE_COLOUR;
	else CrntFillColour = NO_FILL_COLOUR;

	ofstream OutputFile;
	OutputFile.open(FileName + ".txt", ios::out);
	
	switch (CrntDrawColour)
	{
	case BLACK_COLOUR:
		OutputFile << "BLACK" << "     ";
		break;
	case YELLOW_COLOUR:
		OutputFile << "YELLOW" << "     ";
		break;
	case ORANGE_COLOUR:
		OutputFile << "ORANGE" << "     ";
		break;
	case RED_COLOUR:
		OutputFile << "RED" << "     ";
		break;
	case GREEN_COLOUR:
		OutputFile << "GREEN" << "     ";
		break;
	case BLUE_COLOUR:
		OutputFile << "BLUE" << "     ";
		break;
	}

	switch (CrntFillColour)
	{
	case BLACK_COLOUR:
		OutputFile << "BLACK" << '\n';
		break;
	case YELLOW_COLOUR:
		OutputFile << "YELLOW" << '\n';
		break;
	case ORANGE_COLOUR:
		OutputFile << "ORANGE" << '\n';
		break;
	case RED_COLOUR:
		OutputFile << "RED" << '\n';
		break;
	case GREEN_COLOUR:
		OutputFile << "GREEN" << '\n';
		break;
	case BLUE_COLOUR:
		OutputFile << "BLUE" << '\n';
		break;
	case NO_FILL_COLOUR:
		OutputFile << "NO_FILL" << '\n';
		break;
	}

	pManager->SaveAllFigures(OutputFile);
	OutputFile.close();
	
}
