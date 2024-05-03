#ifndef SwitchToPlayModeAction_H
#define SwitchToPlayModeAction_H

#pragma once
#include "ApplicationManager.h"
#include "Actions/Action.h"

class SwitchToPlayModeAction : public Action
{
public:
	SwitchToPlayModeAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};
#endif
