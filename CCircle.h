#ifndef CCIRCLE_H
#define CCIRCLE_H
#include"Figures/CFigure.h"

class CCircle :public CFigure
{
private:
	Point Centre;
	Point Radius;
	 
public:
	CCircle(Point, Point, GfxInfo FigureGfxInfo);

	virtual void Draw(Output* pOut) const;

	virtual void PrintInfo(Output* pOut);

	virtual char Get_My_Type();

	virtual bool IsWithin(Point P);
	

};
#endif