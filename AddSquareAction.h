#pragma once
#ifndef ADD_SQUARE_ACTION_H
#define ADD_SQUARE_ACTION_H

#include "Actions/Action.h"
#include "Figures/CFigure.h"

class AddSquareAction :public Action
{
private:
	Point Centre;
	GfxInfo SquareGfxInfo;

public:
	AddSquareAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

};
#endif