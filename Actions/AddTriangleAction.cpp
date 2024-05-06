#include "..\Actions\AddTriangleAction.h"
#include "..\ApplicationManager.h"
#include "..\Figures\CTriangle.h"

AddTriangleAction::AddTriangleAction(ApplicationManager* pApp):Action(pApp)
{
}

void AddTriangleAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Triangle: Click at First Corner ");
	//Read first coordinates and store in point p1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage(" Click at Second Corner ");
	//Read Second coordinates and store in point p2
	pIn->GetPointClicked(P2.x, P2.y);

	pOut->PrintMessage(" Click at Third Corner ");
	//Read Third coordinates and store in point p3
	pIn->GetPointClicked(P3.x, P3.y);


	TriangleGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	TriangleGfxInfo.DrawClr = pOut->getCrntDrawColor();
	TriangleGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();
}

void AddTriangleAction::Execute()
{
	// This action needs to read some parameters first
	ReadActionParameters();
	// Add sound after drawing the shape if not muted
	if (UI.audio == AUDIO_ON)
		PlaySound("Audio/triangle.wav", NULL, SND_ASYNC);
	//Create a Square with the parameters read from the user
	CTriangle* T = new CTriangle(P1,P2,P3,TriangleGfxInfo);

	//Add the rectangle to the list of figures
	pManager->AddFigure(T);
}

