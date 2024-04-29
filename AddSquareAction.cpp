#include "AddSquareAction.h"
#include"ApplicationManager.h"
#include"CSquare.h"

AddSquareAction::AddSquareAction(ApplicationManager* pApp):Action(pApp)
{
}

void AddSquareAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Square: Click at Centre ");

	//Read Centre coordinates and store in point centre
	pIn->GetPointClicked(Centre.x, Centre.y);

	
	SquareGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	SquareGfxInfo.DrawClr = pOut->getCrntDrawColor();
	SquareGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

void AddSquareAction::Execute()
{
	// This action needs to read some parameters first
		ReadActionParameters();

	//Create a Square with the parameters read from the user
	CSquare* S = new CSquare(Centre,SquareGfxInfo);

	//Add the rectangle to the list of figures
	pManager->AddFigure(S);

	
}

