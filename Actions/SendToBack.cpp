#include "..\Actions\SendToBack.h"
#include "..\ApplicationManager.h"

void SendToBack::ReadActionParameters()
{
}

void SendToBack::Execute()
{
	Output* pOut = pManager->GetOutput();

	if (pManager->GetSelectedCount() == 1) // checks if only 1 figure is selected
		pManager->MoveFig(pManager->GetSelected(0), 0); // moves figure to start of figure list
	else if (pManager->GetSelectedCount() == 0)
		pOut->PrintMessage("No Figure Selected");
	else
		pOut->PrintMessage("Select one Figure only");

}