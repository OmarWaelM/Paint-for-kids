#pragma once
#include "Action.h"
#include "../ApplicationManager.h"

class ToggleAudioAction : public Action
{
public:
	ToggleAudioAction(ApplicationManager* pApp ):Action(pApp) {}

	virtual void ReadActionParameters() {}

	virtual void Execute();
};