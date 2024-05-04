#ifndef SaveGraphAction_H
#define SaveGraphAction_H

#pragma once
#include "ApplicationManager.h"
#include "Actions/Action.h"

class SaveGraphAction : public Action
{
private:
	string FileName;
	bool check;
public:
	SaveGraphAction(ApplicationManager* pApp, bool check = false);
	virtual void ReadActionParameters();
	virtual void Execute();
};
#endif
