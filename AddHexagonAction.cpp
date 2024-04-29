#include "AddHexagonAction.h"
#include"ApplicationManager.h"
#include"CHexagon.h"

AddHexagonAction::AddHexagonAction(ApplicationManager* pApp):Action(pApp)
{
}

void AddHexagonAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Hexagon: Click at Centre ");

	//Read Centre coordinates and store in point centre
	pIn->GetPointClicked(Centre.x, Centre.y);


	HexagonGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	HexagonGfxInfo.DrawClr = pOut->getCrntDrawColor();
	HexagonGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();
}

void AddHexagonAction::Execute()
{
	// This action needs to read some parameters first
	ReadActionParameters();

	//Create a Square with the parameters read from the user
	CHexagon* H = new CHexagon(Centre, HexagonGfxInfo);

	//Add the rectangle to the list of figures
	pManager->AddFigure(H);

}


