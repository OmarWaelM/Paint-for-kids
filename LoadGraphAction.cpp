#include "LoadGraphAction.h"
#include "CFigure.h"
// #include "ClearAllAction.h"
#include <fstream>

LoadGraphAction::LoadGraphAction(ApplicationManager* pApp): Action(pApp) {}

void LoadGraphAction::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Please enter the file name to load it");
	FileName = pIn->GetSrting(pOut);
}

void LoadGraphAction::Execute()
{
	Output* pOut = pManager->GetOutput();
}
