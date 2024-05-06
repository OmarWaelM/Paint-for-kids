#ifndef LoadGraphAction_H
#define LoadGraphAction_H

#pragma once
#include "..\ApplicationManager.h"
#include "..\Actions\Action.h"

class LoadGraphAction : public Action
{
private:
	string FileName;  //the file name to be entered
	bool check;
public:
	LoadGraphAction(ApplicationManager* pApp, bool check = false);
	virtual void ReadActionParameters();
	virtual void Execute();
};
#endif