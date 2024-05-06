#pragma once
#include "..\ApplicationManager.h"
#include "..\Actions\Action.h"
#include "..\Figures\CFigure.h"
#include "..\Figures\CCircle.h"
#include "..\Figures\CSquare.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\CTriangle.h"
#include "..\Figures\CHexagon.h"

class PasteAction : public Action
{
	Output* pOut;
	Input* pIn;
	CFigure* PasteFigure;
	CFigure* NewFigure;
	Point PointClicked;
	GfxInfo PasteFigureGfxInfo;

public:
	PasteAction(ApplicationManager* pAct);
	virtual void ReadActionParameters();
	virtual void Execute();
};