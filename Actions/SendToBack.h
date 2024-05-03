#pragma once
#include "Actions/Action.h"

class SendToBack : public Action
{
protected:

public:
	SendToBack(ApplicationManager* pApp):Action(pApp) {}

	virtual void ReadActionParameters();

	virtual void Execute();

};