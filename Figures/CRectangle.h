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

	virtual bool IsWithin(Point P);

	virtual void Save(ofstream& OutputFile, int n);
	
	virtual void Load(ifstream& InputFile, CFigure*& s);
};

#endif