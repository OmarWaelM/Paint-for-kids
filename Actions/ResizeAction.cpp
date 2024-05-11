#include "ResizeAction.h"

void ResizeAction::ReadActionParameters() {}

void ResizeAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	
	if (pManager->GetSelectedCount() == 1) //checks if selected count is = 1
	{
		pFig = pManager->GetSelected(0);
		pFig->SetScale(scale);//changes scale of figure
		pOut->PrintMessage("Figure resized successfully");
	}
	else
		pOut->PrintMessage("Select only ONE figure");
}