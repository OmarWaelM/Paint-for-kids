#ifndef CFIGURE_H
#define CFIGURE_H

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

public:
	CFigure(GfxInfo FigureGfxInfo);

	void SetSelected(bool s);	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected
	
	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color

	bool isFilled() { return FigGfxInfo.isFilled; };
	color Get_Filled_Colour() { return FigGfxInfo.FillClr; };
	

	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure:
	virtual void Draw(Output* pOut) const  = 0 ;		//Draw the figure
	virtual void PrintInfo(Output* pOut) = 0;          //print all figure info on the status bar
	virtual bool IsWithin(Point P) = 0;
	virtual char Get_My_Type() = 0;
	///Decide the parameters that you should pass to each function	


	//virtual void Save(ofstream &OutFile) = 0;	//Save the figure parameters to the file
	//virtual void Load(ifstream &Infile) = 0;	//Load the figure parameters to the file
	//
};

#endif