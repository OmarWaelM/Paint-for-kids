#ifndef CSQUARE_H
#define CSQUARE_H
#include"Figures/CFigure.h"

class CSquare :public CFigure
{
private:
	Point Centre;

public:
	CSquare(Point, GfxInfo FigureGfxInfo);

	CSquare(CSquare* old, GfxInfo newGfxInfo);

	virtual void Draw(Output* pOut) const;

	virtual void PrintInfo(Output* pOut);

	virtual bool IsWithin(Point P);

	virtual void Move(Point P);

	virtual void SetScale(double scale);

	virtual void Save(ofstream& OutputFile);

	virtual void Load(ifstream& InputFile);

};
#endif;

