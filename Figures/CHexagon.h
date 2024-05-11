#ifndef CHEXA_H
#define CHEXA_H

#include"..\Figures\CFigure.h"

class CHexagon :public CFigure
{
private:
	Point Centre;

public:
	CHexagon(Point, GfxInfo FigureGfxInfo); //Constructor

	CHexagon(CHexagon* old, GfxInfo newGfxInfo); //Copy constructor for Hexagon* (used in paste action)
	
	virtual void Draw(Output* pOut) const; //Draw figure

	virtual void PrintInfo(Output* pOut); //Print info to status bar

	virtual bool IsWithin(Point P);	//Checks if point is within the hexagon

	bool IsWithinHelper(int P1x, int P1y, int P2x, int P2y, int P3x, int P3y, int Px, int Py); //Helper function for IsWithin

	virtual void Move(Point P);	//Moves center to different point

	virtual void SetScale(double scale); //Changes scale of hexagon

	virtual void Save(ofstream& OutputFile); //Saves Circle info to file

	virtual void Load(ifstream& InputFile); //Loads Circle info from file
};
#endif
