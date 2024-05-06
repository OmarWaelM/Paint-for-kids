#include "ExitAction.h"

ExitAction::ExitAction(ApplicationManager* pApp): Action(pApp) {}

void ExitAction::ReadActionParameters() {}

void ExitAction::Execute()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	int x, y;
	pOut->PrintMessage("Click anywhere to Exit, Goodbye!");
	pIn->GetPointClicked(x,y);
}
