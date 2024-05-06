#pragma once
#include "..\Actions/Action.h"
#include "..\ApplicationManager.h"
#include "..\Figures/CFigure.h"

class PickByBothAction : public Action
{
private:
	int Correct_Count;
	int Wrong_Count;
	int Total_Count;

	Input* pIn;
	Output* pOut;
	CFigure* pFig;
	Point Clicked;

public:
	PickByBothAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

	int getType(CFigure* Fig);

	~PickByBothAction();
};