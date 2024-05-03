#pragma once
#include"ApplicationManager.h"
#include "Actions/Action.h"
#include "Figures/CFigure.h"
#include "DeleteAction.h"

class ClearAllAction : public Action
{
	CFigure* Fig;
	Output* pOut;
public:
	ClearAllAction (ApplicationManager* pApp);
	void ReadActionParameters();
	void Execute();
};
