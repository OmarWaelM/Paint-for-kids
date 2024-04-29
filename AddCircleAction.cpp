#include "AddCircleAction.h"

AddCircleAction::AddCircleAction(ApplicationManager* pApp):Action(pApp)
{
}

void AddCircleAction::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces
	Output * pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Circle: Click at Centre ");

	//Read Centre coordinates and store in point centre
	pIn->GetPointClicked(Centre.x, Centre.y);

	pOut->PrintMessage("Click on the radius");

	//Read Radius coordinates and store in point radius
	pIn->GetPointClicked(Radius.x, Radius.y);

	CircleGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	CircleGfxInfo.DrawClr = pOut->getCrntDrawColor();
	CircleGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();
}

void AddCircleAction::Execute()
{
	// This action needs to read some parameters first
	ReadActionParameters();

	//Create a Square with the parameters read from the user
	CCircle* C = new CCircle(Centre, Radius, CircleGfxInfo);

	//Add the rectangle to the list of figures
	pManager->AddFigure(C);

}