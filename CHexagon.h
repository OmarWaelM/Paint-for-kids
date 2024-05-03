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

	virtual bool IsWithin(Point P);

	bool IsWithinHelper(int P1x, int P1y, int P2x, int P2y, int P3x, int P3y, int Px, int Py);

	virtual void Save(ofstream& OutputFile);

	virtual void Load(ifstream& InputFile, CFigure*& s);
};
#endif
