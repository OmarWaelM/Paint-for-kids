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
	CRectangle(Point , Point, GfxInfo FigureGfxInfo ); //Constructor

	CRectangle(CRectangle* old, GfxInfo newGfxInfo); //Copy constructor for Rectangle* (used in paste action)

	virtual void Draw(Output* pOut) const; //Draw figure

	virtual void PrintInfo(Output* pOut); //Print info to status bar

	virtual bool IsWithin(Point P);	//Checks if point is within the rectangle

	virtual void Move(Point P);	//Moves center to different point

	virtual void SetScale(double scale); //Changes scale of rectangle

	virtual void Save(ofstream& OutputFile); //Saves Circle info to file

	virtual void Load(ifstream& InputFile); //Loads Circle info from file
};

#endif