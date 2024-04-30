#pragma once
#include"Actions/Action.h"
#include"ApplicationManager.h"
#include"Figures/CFigure.h"

class PickByTypeAction :public Action
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
	PickByTypeAction(ApplicationManager* pApp);

	virtual void ReadParameters();

	virtual void Execute();

	virtual void Execute_Body(char Type, int Total_Count);






};
