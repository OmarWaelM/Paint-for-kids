#ifndef CTRIANGLE_H
#define CTRIANGLE_H
#include "..\Figures\CFigure.h"

class CTriangle :public CFigure
{
private:
	Point P1;
	Point P2;
	Point P3;

public:
	CTriangle(Point, Point, Point, GfxInfo FigureGfxInfo); //Constructor

	CTriangle(CTriangle* old, GfxInfo newGfxInfo); //Copy constructor for Triangle* (used in paste action)

	virtual void Draw(Output* pOut) const; //Draw figure

	virtual void PrintInfo(Output* pOut); //Print info to status bar

	virtual bool IsWithin(Point P);	//Checks if point is within the triangle

	virtual void Move(Point P);	//Moves center to different point

	virtual void SetScale(double scale); //Changes scale of triangle

	virtual void Save(ofstream& OutputFile); //Saves Circle info to file

	virtual void Load(ifstream& InputFile); //Loads Circle info from file
};
#endif