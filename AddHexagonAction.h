#pragma once
#ifndef ADD_HEXAGON_ACTION_H
#define ADD_HEXAGON_ACTION_H

#include "Actions/Action.h"
#include "Figures/CFigure.h"

class AddHexagonAction :public Action
{
private:
	Point Centre;
	GfxInfo HexagonGfxInfo;

public:
	AddHexagonAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

};
#endif

