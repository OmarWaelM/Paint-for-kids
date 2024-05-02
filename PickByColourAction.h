#pragma once
#include"Actions/Action.h"
#include"ApplicationManager.h"
#include"Figures/CFigure.h"

class PickByColourAction : public Action
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
	PickByColourAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

	void Execute_Body(FillColors fillclr, int TotalCount);

};
