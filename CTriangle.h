#ifndef CTRIANGLE_H
#define CTRIANGLE_H
#include"Figures/CFigure.h"

class CTriangle :public CFigure
{
private:
	Point P1;
	Point P2;
	Point P3;

public:
	CTriangle(Point, Point, Point, GfxInfo FigureGfxInfo);

	virtual void Draw(Output* pOut) const;

	virtual void PrintInfo(Output* pOut);

	virtual bool IsWithin(Point P);

	virtual void Save(ofstream& OutputFile);

	virtual void Load(ifstream& InputFile, CFigure*& s);
};
#endif