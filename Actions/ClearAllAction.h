#pragma once
#include "..\ApplicationManager.h"
#include "..\Actions\Action.h"
#include "..\Figures\CFigure.h"
#include "..\Actions\ClearAllAction.h"

class ClearAllAction : public Action
{
	CFigure* Fig;
	Output* pOut;
public:
	ClearAllAction (ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};
