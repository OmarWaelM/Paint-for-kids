 #include "SwitchToPlayModeAction.h"
#include "SaveGraphAction.h"

SwitchToPlayModeAction::SwitchToPlayModeAction(ApplicationManager* pApp) : Action(pApp) {}

void SwitchToPlayModeAction::ReadActionParameters() {}

void SwitchToPlayModeAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	SaveGraphAction s(pManager,true); // saves current graph to pre-switch file
	s.Execute();
	pOut->ClearDrawArea();
	pOut->CreatePlayToolBar();
	pOut->PrintMessage("You have just switched to Play mode, Enjoy!");
}
