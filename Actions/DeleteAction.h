#pragma once
#include"ApplicationManager.h"
#include "Actions/Action.h"


class DeleteAction : public Action
{
private:
	CFigure* pFig;
	Output* pOut;

public:
	DeleteAction(ApplicationManager*pApp);

	virtual void ReadActionParameters();

	virtual void Execute();


};


