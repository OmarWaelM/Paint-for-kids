#ifndef SwitchToDrawModeAction_H
#define SwitchToDrawModeAction_H

#pragma once
#include "..\ApplicationManager.h"
#include "..\Actions\Action.h"

class SwitchToDrawModeAction : public Action
{
public:
	SwitchToDrawModeAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};
#endif
