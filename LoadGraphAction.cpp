#include "LoadGraphAction.h"
#include <fstream>
#include "colors.h"

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

}
