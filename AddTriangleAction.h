#pragma once
#ifndef ADD_TRIANGLE_ACTION_H
#define ADD_TRIANGLE_ACTION_H

#include "Actions/Action.h"
#include "Figures/CFigure.h"

class AddTriangleAction : public Action
{
private:
	Point P1;
	Point P2;
	Point P3;

	GfxInfo TriangleGfxInfo;
	

public:
	AddTriangleAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();


};
#endif

