#include "SwitchToPlayModeAction.h"
#include "SaveGraphAction.h"

SwitchToPlayModeAction::SwitchToPlayModeAction(ApplicationManager* pApp) {}

void SwitchToPlayModeAction::ReadActionParameters() {}

void SwitchToPlayModeAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	pOut->ClearDrawAreaForSwitch();
	pOut->CreatePlayToolBar();
	pOut->PrintMessage("You have just switched to Play mode, Enjoy!");
	SaveGraphAction s(pManager);
	s.Execute();
}
