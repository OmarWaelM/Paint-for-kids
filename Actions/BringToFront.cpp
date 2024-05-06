#include "..\Actions\BringToFront.h"
#include "..\ApplicationManager.h"

void BringToFront::ReadActionParameters()
{
}

void BringToFront::Execute()
{

	Output* pOut = pManager->GetOutput();

	if (pManager->GetSelectedCount() == 1)
		pManager->MoveFig(pManager->GetSelected(0), pManager->GetFigCount() - 1);
	else if (pManager->GetSelectedCount() == 0)
		pOut->PrintMessage("No Figure Selected");
	else
		pOut->PrintMessage("Select one Figure only");

}