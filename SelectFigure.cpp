#include "SelectFigure.h"
#include "ApplicationManager.h"

#include "GUI/Input.h"
#include "GUI/Output.h"

void SelectFigure::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Selection tool picked, Click on a figure.");
	pIn->GetPointClicked(Clicked.x, Clicked.y);

}

void SelectFigure::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	if (pManager->GetFigCount() != 0)
	{
		ReadActionParameters();
		Fig_Clicked = pManager->GetFigure(Clicked.x, Clicked.y);

		if (Fig_Clicked != NULL)
		{
			if (Fig_Clicked->IsSelected())
				pManager->DeleteSelected(0, Fig_Clicked);
			else
				pManager->AddSelected(Fig_Clicked);
		}
		else
		{
			for (int i = pManager->GetSelectedCount() - 1; i >= 0 ; i--)
				pManager->DeleteSelected(i);
		}
	}
	else
	{
		pOut->PrintMessage("Error! No items to select.");
	}
}