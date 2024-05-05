#pragma once
#include"ApplicationManager.h"
#include "Actions/Action.h"
#include "Figures/CFigure.h"
#include "CCircle.h"
#include "CSquare.h"

class PasteAction : public Action
{
	Output* pOut;
	Input* pIn;
	CFigure* PasteFigure;
	Point PointClicked;

public:
	PasteAction(ApplicationManager* pAct);
	virtual void ReadActionParameters();
	virtual void Execute();
};