#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
	Point Upper_Left;
	Point Bottom_Right;

public:
	CRectangle(Point , Point, GfxInfo FigureGfxInfo );

	virtual void Draw(Output* pOut) const;

	virtual void PrintInfo(Output* pOut);

	virtual char Get_My_Type();

	virtual bool IsWithin(Point P);
};

#endif