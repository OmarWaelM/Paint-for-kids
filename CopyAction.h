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
	virtual void ReadActionParameters();
	virtual void Execute();
};
