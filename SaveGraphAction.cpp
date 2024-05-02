#include "SaveGraphAction.h"
#include <fstream>

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
	int DrawColour;
	int FillColour;

	switch (pOut->getCrntDrawColor())
	{
	case BLACK:
		DrawColour = BLACK_COLOUR;
		break;
	case YELLOW:
		DrawColour = YELLOW_COLOUR;
		break;
	case ORANGE:
		DrawColour = ORANGE_COLOUR;
		break;
	case RED:
		DrawColour = RED_COLOUR;
		break;
	case GREEN:
		DrawColour = GREEN_COLOUR;
		break;
	case BLUE:
		DrawColour = BLUE_COLOUR;
		break;
	}

	switch (pOut->getCrntFillColor())
	{
	case BLACK:
		FillColour = BLACK_COLOUR;
		break;
	case YELLOW:
		FillColour = YELLOW_COLOUR;
		break;
	case ORANGE:
		FillColour = ORANGE_COLOUR;
		break;
	case RED:
		FillColour = RED_COLOUR;
		break;
	case GREEN:
		FillColour = GREEN_COLOUR;
		break;
	case BLUE:
		FillColour = BLUE_COLOUR;
		break;
	default:
		FillColour = NO_FILL_COLOUR;
		break;
	}

	ifstream FileExistsCheck(FileName + ".txt");
	if (FileExistsCheck.good())
	{
		FileExistsCheck.close();
		ofstream OutputFile;
		OutputFile.open(FileName + ".txt", ios::out);
		OutputFile << DrawColour << "  " << FillColour << endl;
		pManager->SaveAllFigures(OutputFile);
		OutputFile.close();
	}
	else 
	{
		ofstream OutputFile;
		OutputFile.open(FileName + ".txt", ios::out);
		OutputFile << DrawColour << "  " << FillColour << endl;
		pManager->SaveAllFigures(OutputFile);
		OutputFile.close();
	}
}
