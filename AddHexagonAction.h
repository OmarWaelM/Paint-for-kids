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
	CFigure* Figure_Is_Saved;

public:
	AddHexagonAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

	virtual void Undo_Execute();


};
#endif

