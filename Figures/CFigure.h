#ifndef CFIGURE_H
#define CFIGURE_H

#include <fstream>
#include "..\defs.h"
#include "..\GUI\Output.h"

//Base class for all figures
class CFigure
{
protected:
	int ID;	//Each figure has an ID
	bool Selected; //true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphics info
	static int Number_Of_Figures; //static member of number of figures drawn
	bool Cut; // true if the shape is cut
	double scale; //scale of figure
public:
	CFigure(GfxInfo FigureGfxInfo);

	void SetSelected(bool s);	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected
	
	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color

	static void ChngNumberOfFigures(int num); //changes static value of Number_Of_Figures

	bool IsCut() const;  // checks whether the figure is cut
	void SetCut(bool c); // cuts/ uncuts the figure

	bool isFilled() { return FigGfxInfo.isFilled; }; // returns if figure is filled
	color Get_Filled_Colour() { return FigGfxInfo.FillClr; } // returns fill color
	color Get_Draw_Colour() { return FigGfxInfo.DrawClr; } // returns border color
	double Get_Scale() { return scale; } // returns scale

	virtual void Draw(Output* pOut) const  = 0 ; //Draw the figure
	virtual void PrintInfo(Output* pOut) = 0; //print all figure info on the status bar
	virtual bool IsWithin(Point P) = 0; //checks if point is within the figure
	virtual void Move(Point P) = 0; //moves center of figure to point
	virtual void SetScale(double scale) = 0; //changes scale of figure

	virtual void Save(ofstream& OutputFile) = 0; //Saves each figure's parameters and GfxInfo accordingly
	virtual void Load(ifstream& InputFile) = 0;  //Loads each figure's parameters and GfxInfo accordingly
};

#endif