#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

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
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)

	int SelCount;
	CFigure* SelectedFig[MaxFigCount]; //Pointer to the selected figure

	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;

	CFigure* Clipboard;  //Pointer to copied/cut figure

	
public:	
	ApplicationManager(); 
	~ApplicationManager();
	
	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType) ; //Creates an action and executes it

	void Set_Selected_Figure(CFigure*pFig); // to set the selected figure//
	CFigure* Get_Selected_Figure(); // to return the selected figure // mardash y return abstract class f 3amalt pointer f nf3t
	
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig); //Adds a new figure to the FigList
	void Delete_Figure(CFigure* pFig); //Deletes a figure from the FigList
	int GetFigCount() const { return FigCount; } // Getter for Figcount
	void MoveFig(CFigure* Fig, int in); //Moves Figure pointer to given index in array
	CFigure *GetFigure(int x, int y) const; //Search for a figure given a point inside the figure

	void AddSelected(CFigure* sFig); //Adds a Figure to selected list
	void DeleteSelected(int i, CFigure* Fig = NULL); //Removes Figure at index i from selected list or the given figure pointer
	int GetSelectedCount() const { return SelCount; } //Getter for SelectedCount
	CFigure* GetSelected(int i) const { return SelectedFig[i]; } // Getter for Selected figure in index i

	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window	
};

#endif