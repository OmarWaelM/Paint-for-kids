#ifndef SEL_FIG_H
#define SEL_FIG_H

#include "Figures/CFigure.h"
#include "Actions/Action.h"

class SelectFigure : public Action
{
protected:
	Point Clicked;
	CFigure* Fig_Clicked;

public:
	SelectFigure(ApplicationManager* pApp):Action(pApp){};

	virtual void ReadActionParameters();

	virtual void Execute();

};
#endif