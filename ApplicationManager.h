#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include <fstream>
#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"

//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures

private:
	int FigCount;		//Actual number of figures
	int Rectangle_Count;
	int Circle_Count;
	int Triangle_Count;
	int Hexagon_Count;
	int Square_Count;

	int No_Filled_Figure;
	int Red_Figures;
	int Black_Figures;
	int Blue_Figures;
	int Green_Figures;
	int Yellow_Figures;
	int Orange_Figures;

	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)


	int SelCount;
	CFigure* SelectedFig[MaxFigCount]; //Pointer to the selected figure

	//Pointers to Input and Output classes
	Input* pIn;
	Output* pOut;

	CFigure* Clipboard;  //Pointer to copied/cut figure


public:
	ApplicationManager();
	~ApplicationManager();

	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType); //Creates an action and executes it
	

	// -- Figures Management Functions
	void AddFigure(CFigure* pFig); //Adds a new figure to the FigList
	void Delete_Figure(CFigure* pFig); //Deletes a figure from the FigList
	int GetFigCount() const { return FigCount; } // Getter for Figcount
	void MoveFig(CFigure* Fig, int in); //Moves Figure pointer to given index in array
	CFigure *GetFigure(int x, int y) const; //Search for a figure given a point inside the figure

	void Reset_Figure_Count();
	void Count_Figure_Types();
	int Get_Circle_Count();
	int Get_Triangle_Count();
	int Get_Square_Count();
	int Get_Rectangle_Count();
	int Get_Hexagon_Count();
	char Get_Random_Type(int ix);// return the type of fig according to its index

	int GetBlack_Figures() { return Black_Figures; };
	int Get_Red_Figures() { return Red_Figures; };
	int Get_Orange_Figures() { return Orange_Figures; };
	int Get_Yellow_Figures() { return Yellow_Figures; };
	int Get_Green_Figures() { return Yellow_Figures; };
	int Get_Blue_Figures() { return Blue_Figures; };
	int Get_No_Filled_Figure() { return No_Filled_Figure; };
	void Reset_Fill_Colour();
	void Count_Fill_Colour();
	color Get_Random_Fill_Colour(int ix);


	void AddSelected(CFigure* sFig); //Adds a Figure to selected list
	void DeleteSelected(int i, CFigure* Fig = NULL); //Removes Figure at index i from selected list or the given figure pointer
	int GetSelectedCount() const { return SelCount; } //Getter for SelectedCount
	CFigure* GetSelected(int i) const { return SelectedFig[i]; } // Getter for Selected figure in index i

	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window

	void SaveAllFigures(ofstream& F);
};

#endif
