#ifndef CCIRCLE_H
#define CCIRCLE_H
#include"Figures/CFigure.h"

class CCircle :public CFigure
{
private:
	Point P1;
	Point P2;

public:
	CCircle(Point, Point, GfxInfo FigureGfxInfo);

	virtual void Draw(Output* pOut) const;

	virtual void PrintInfo(Output* pOut);

	//
};
#endif