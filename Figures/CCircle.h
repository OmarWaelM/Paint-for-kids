#ifndef CCIRCLE_H
#define CCIRCLE_H
#include"..\Figures\CFigure.h"

class CCircle :public CFigure
{
private:
	Point Centre;
	Point Radius;
	 
public:
	CCircle(Point, Point, GfxInfo FigureGfxInfo); //Constructor

	CCircle(CCircle* old, GfxInfo newGfxInfo); //Copy constructor for Circle* (used in paste action)

	virtual void Draw(Output* pOut) const; //Draw figure

	virtual void PrintInfo(Output* pOut); //Print info to status bar

	virtual bool IsWithin(Point P);	//Checks if point is within the circle

	virtual void Move(Point P);	//Moves center to different point

	virtual void SetScale(double scale); //Changes scale of circle

	virtual void Save(ofstream& OutputFile); //Saves Circle info to file

	virtual void Load(ifstream& InputFile); //Loads Circle info from file
	
};
#endif