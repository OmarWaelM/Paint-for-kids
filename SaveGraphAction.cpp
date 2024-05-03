#include "SaveGraphAction.h"
#include <fstream>
#include "ApplicationManager.h"

SaveGraphAction::SaveGraphAction(ApplicationManager* pApp): Action(pApp) {}

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
	int DrawColour;
	int FillColour;

	ReadActionParameters();

	ofstream OutputFile;
	OutputFile.open(FileName + ".txt", ios::out);
	
	str_to_int
	if (pOut->getCrntDrawColor() == BLACK)
		OutputFile << "BLACK";
	else if (pOut->getCrntDrawColor() == YELLOW)
		OutputFile << "YELLOW";
	else if (pOut->getCrntDrawColor() == ORANGE)
		OutputFile << "ORANGE";
	else if (pOut->getCrntDrawColor() == RED)
		OutputFile << "RED";
	else if (pOut->getCrntDrawColor() == GREEN)
		OutputFile << "GREEN";
	else if (pOut->getCrntDrawColor() == BLUE)
		OutputFile << "BLUE";
	OutputFile << "   ";
	if (pOut->getCrntFillColor() == BLACK)
		OutputFile << "BLACK";
	else if (pOut->getCrntFillColor() == YELLOW)
		OutputFile << "YELLOW";
	else if (pOut->getCrntFillColor() == ORANGE)
		OutputFile << "ORANGE";
	else if (pOut->getCrntFillColor() == RED)
		OutputFile << "RED";
	else if (pOut->getCrntFillColor() == GREEN)
		OutputFile << "GREEN";
	else if (pOut->getCrntFillColor() == BLUE)
		OutputFile << "BLUE";
	OutputFile << "\n";
	//pManager->SaveAllFigures(OutputFile);
	OutputFile.close();
	pOut->PrintMessage("Your file was saved successfully");
}
