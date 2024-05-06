#ifndef CCIRCLE_H
#define CCIRCLE_H
#include"..\Figures\CFigure.h"

class CCircle :public CFigure
{
private:
	Point Centre;
	Point Radius;
	 
public:
	CCircle(Point, Point, GfxInfo FigureGfxInfo);

	CCircle(CCircle* old, GfxInfo newGfxInfo);

	virtual void Draw(Output* pOut) const;

	virtual void PrintInfo(Output* pOut);

	virtual bool IsWithin(Point P);

	virtual void Move(Point P);

	virtual void SetScale(double scale);

	virtual void Save(ofstream& OutputFile);

	virtual void Load(ifstream& InputFile);
	

};
#endif