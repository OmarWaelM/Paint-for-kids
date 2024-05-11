#ifndef CSQUARE_H
#define CSQUARE_H
#include "..\Figures\CFigure.h"

class CSquare :public CFigure
{
private:
	Point Centre;

public:
	CSquare(Point, GfxInfo FigureGfxInfo); //Constuctor

	CSquare(CSquare* old, GfxInfo newGfxInfo); //Copy constructor for Square* (used in paste action)

	virtual void Draw(Output* pOut) const; //Draw figure

	virtual void PrintInfo(Output* pOut); //Print info to status bar

	virtual bool IsWithin(Point P);	//Checks if point is within the square

	virtual void Move(Point P);	//Moves center to different point

	virtual void SetScale(double scale); //Changes scale of square

	virtual void Save(ofstream& OutputFile); //Saves Circle info to file

	virtual void Load(ifstream& InputFile); //Loads Circle info from file

};
#endif;

