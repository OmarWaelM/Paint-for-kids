#ifndef CHEXA_H
#define CHEXA_H

#include"Figures/CFigure.h"

class CHexagon :public CFigure
{
private:
	Point Centre;

public:
	CHexagon(Point, GfxInfo FigureGfxInfo);

	virtual void Draw(Output* pOut) const;

	virtual void PrintInfo(Output* pOut);




};
#endif
