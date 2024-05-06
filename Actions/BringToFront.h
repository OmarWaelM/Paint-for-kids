#pragma once
#include "..\Actions\Action.h"

class BringToFront : public Action
{
protected:

public:
	BringToFront(ApplicationManager* pApp) : Action(pApp) {}

	virtual void ReadActionParameters();

	virtual void Execute();
};