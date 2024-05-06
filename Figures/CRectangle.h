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

	CRectangle(CRectangle* old, GfxInfo newGfxInfo);

	virtual void Draw(Output* pOut) const;

	virtual void PrintInfo(Output* pOut);

	virtual bool IsWithin(Point P);

	virtual void Move(Point P);

	virtual void SetScale(double scale);

	virtual void Save(ofstream& OutputFile);
	
	virtual void Load(ifstream& InputFile);
};

#endif