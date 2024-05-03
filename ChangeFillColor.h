#pragma once
#include "ApplicationManager.h"
#include "Actions/Action.h"
#include "SelectFigure.h"
#include "Figures/CFigure.h"
#include "CMUgraphicsLib/colors.h"

class ChangeFillColor : public Action
{
	CFigure* SelectedFig;
	color SelectedColor;
	ActionType ActType;
public:
	ChangeFillColor(ApplicationManager* pApp);
	void SetSelectedColor(color c);
	virtual void ReadActionParameters();
	virtual void Execute();
};
