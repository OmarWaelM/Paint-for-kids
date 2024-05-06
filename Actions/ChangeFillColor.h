#pragma once
#include "..\ApplicationManager.h"
#include "..\Actions\Action.h"
#include "..\Actions\SelectFigure.h"
#include "..\Figures\CFigure.h"

class ChangeFillColor : public Action
{
	CFigure* SelectedFig;
	color SelectedColor;
	ActionType ActType;
	Output* pOut;
	Input* pIn;

public:
	ChangeFillColor(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};
