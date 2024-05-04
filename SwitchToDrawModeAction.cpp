#include "SwitchToDrawModeAction.h"
#include "LoadGraphAction.h"

SwitchToDrawModeAction::SwitchToDrawModeAction(ApplicationManager* pApp): Action(pApp) {}

void SwitchToDrawModeAction::ReadActionParameters() {}

void SwitchToDrawModeAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	pOut->ClearDrawArea();
	pOut->CreateDrawToolBar();
	LoadGraphAction l(pManager, true);
	l.Execute();
	pOut->PrintMessage("You have just switched to Draw mode, Enjoy!");
}
