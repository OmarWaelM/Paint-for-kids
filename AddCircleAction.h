#pragma once
#pragma once
#ifndef ADD_CIRCLE_ACTION_H
#define ADD_CIRCLE_ACTION_H

#include "Actions/Action.h"
#include "Figures/CFigure.h"
#include"ApplicationManager.h"
#include"CCircle.h"

class AddCircleAction :public Action
{
private:
	Point Centre;
	Point Radius;
	GfxInfo CircleGfxInfo;
	CFigure* Figure_Is_Saved;

public:
	AddCircleAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();



};
#endif
