#include "SaveGraphAction.h"
#include <fstream>
#include "ApplicationManager.h"

SaveGraphAction::SaveGraphAction(ApplicationManager* pApp, bool switch = false): Action(pApp) {}

void SaveGraphAction::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Please enter the file name that's to be saved");
	FileName = pIn->GetSrting(pOut);
}

void SaveGraphAction::Execute()
{
	Output* pOut = pManager->GetOutput();

	if (switch == false)
		ReadActionParameters();
	else FileName = "Pre-switch File";

	string CrntDrawColour;
	string CrntFillColour;

	ReadActionParameters();

	ofstream OutputFile;
	OutputFile.open(FileName + ".txt", ios::out);
	
	str_to_int
	if (pOut->getCrntDrawColor() == BLACK)
		CrntDrawColour = "BLACK";
	else if (pOut->getCrntDrawColor() == YELLOW)
		CrntDrawColour = "YELLOW";
	else if (pOut->getCrntDrawColor() == ORANGE)
		CrntDrawColour = "ORANGE";
	else if (pOut->getCrntDrawColor() == RED)
		CrntDrawColour = "RED";
	else if (pOut->getCrntDrawColor() == GREEN)
		CrntDrawColour = "GREEN";
	else if (pOut->getCrntDrawColor() == BLUE)
		CrntDrawColour = "BLUE";

	if (pOut->getCrntFillColor() == BLACK)
		CrntFillColour = "BLACK";
	else if (pOut->getCrntFillColor() == YELLOW)
		CrntFillColour = "YELLOW";
	else if (pOut->getCrntFillColor() == ORANGE)
		CrntFillColour = "ORANGE";
	else if (pOut->getCrntFillColor() == RED)
		CrntFillColour = "RED";
	else if (pOut->getCrntFillColor() == GREEN)
		CrntFillColour = "GREEN";
	else if (pOut->getCrntFillColor() == BLUE)
		CrntFillColour = "BLUE";
	else CrntFillColour = "NO_FILL";

	ofstream OutputFile;
	OutputFile.open(FileName + ".txt", ios::out);
	OutputFile << CrntDrawColour << "   " << CrntFillColour << endl;
	pManager->SaveAllFigures(OutputFile);
	OutputFile.close();
  pOut->PrintMessage("Your file was saved successfully");
}
