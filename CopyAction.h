#pragma once
#include"ApplicationManager.h"
#include "Actions/Action.h"
#include "Figures/CFigure.h"

class CopyAction : public Action
{
	CFigure* SelectedFig;
	Output* pOut;
public:
	CopyAction(ApplicationManager* pAct);
	void ReadActionParameters();
	void Execute();
};
