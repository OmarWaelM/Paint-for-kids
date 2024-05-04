#pragma once
#include"ApplicationManager.h"
#include "Actions/Action.h"
#include "Figures/CFigure.h"
class CutAction : public Action
{
	CFigure* SelectedFig;
	Output* pOut;
public:
	CutAction(ApplicationManager* pAct);
	virtual void ReadActionParameters();
	virtual void Execute();
};