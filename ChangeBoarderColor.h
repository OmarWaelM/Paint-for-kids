#pragma once
#include "ApplicationManager.h"
#include "Actions/Action.h"
#include "SelectFigure.h"
#include "Figures/CFigure.h"
#include "CMUgraphicsLib/colors.h"

class ChangeBoarderColor : public Action
{
	CFigure* SelectedFig;
	color SelectedColor;
	ActionType ActType;
public:
	ChangeBoarderColor(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};

