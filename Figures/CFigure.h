#ifndef CFIGURE_H
#define CFIGURE_H

#include <fstream>
#include "..\defs.h"
#include "..\GUI\Output.h"

//Base class for all figures
class CFigure
{
protected:
	int ID;		//Each figure has an ID
	bool Selected;	//true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphics info
	static int Number_Of_Figures;
	/// Add more parameters if needed.
	bool Cut; // true if the shape is cut

public:
	CFigure(GfxInfo FigureGfxInfo);

	void SetSelected(bool s);	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected
	
	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color

	static void ChngNumberOfFigures(int num); //changes static value of Number_Of_Figures

	
	bool IsCut() const;  // checks whether the figure is cut
	void SetCut(bool c); // cuts/ uncuts the figure

	bool isFilled() { return FigGfxInfo.isFilled; };
	color Get_Filled_Colour() { return FigGfxInfo.FillClr; };
	color Get_Draw_Colour() { return FigGfxInfo.DrawClr; }

	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure:
	virtual void Draw(Output* pOut) const  = 0 ;		//Draw the figure
	virtual void PrintInfo(Output* pOut) = 0;          //print all figure info on the status bar
	virtual bool IsWithin(Point P) = 0;
	virtual void Move(Point P) = 0;
	///Decide the parameters that you should pass to each function	

	virtual void Save(ofstream& OutputFile) = 0;
	virtual void Load(ifstream& InputFile) = 0;
};

#endif