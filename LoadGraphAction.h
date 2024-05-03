#ifndef LoadGraphAction_H
#define LoadGraphAction_H

#pragma once
#include "ApplicationManager.h"
#include "Actions/Action.h"

class LoadGraphAction : public Action
{
private:
	string FileName;  //the file name to be entered
public:
	LoadGraphAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};
#endif