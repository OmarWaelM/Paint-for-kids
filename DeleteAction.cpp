#include "DeleteAction.h"
#include "ApplicationManager.h"


DeleteAction::DeleteAction(ApplicationManager* pApp):Action(pApp)
{
}

void DeleteAction::ReadActionParameters()
{
}

void DeleteAction::Execute()
{
	ReadActionParameters();

	//pFig = pManager->Get_Selected_Figure();
	pOut = pManager->GetOutput();

	if (pFig)
	{
		pOut->ClearDrawArea();
		pManager->Delete_Figure(pFig);
		pOut->PrintMessage("The Selected Figure is Deleted ");
	}
	else
     	pOut->PrintMessage("No selected figure. Please select a figure first!");

}