#pragma once
#include "..\Actions\Action.h"
#include "..\ApplicationManager.h"

class ResizeAction :public Action
{
protected:
	CFigure* pFig;
	double scale;
public:
	ResizeAction(ApplicationManager* pApp, double scale) : Action(pApp), scale(scale) {}

	virtual void ReadActionParameters();

	virtual void Execute();
};
