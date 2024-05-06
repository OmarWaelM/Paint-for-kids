#include "..\Actions\SendToBack.h"
#include "..\ApplicationManager.h"

void SendToBack::ReadActionParameters()
{
}

void SendToBack::Execute()
{
	Output* pOut = pManager->GetOutput();

	if (pManager->GetSelectedCount() == 1)
		pManager->MoveFig(pManager->GetSelected(0), 0);
	else if (pManager->GetSelectedCount() == 0)
		pOut->PrintMessage("No Figure Selected");
	else
		pOut->PrintMessage("Select one Figure only");

}