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

	virtual bool IsWithin(Point P);

	virtual void Save(ofstream& OutputFile, int n);

	virtual void Load(ifstream& InputFile, CFigure*& s);
	

};
#endif