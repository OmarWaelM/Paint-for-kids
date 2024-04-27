#include "Input.h"
#include "Output.h"


Input::Input(window* pW)
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int& x, int& y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string Input::GetSrting(Output* pO) const
{
	string Label;
	char Key;
	while (1)
	{
		pWind->WaitKeyPress(Key);
		if (Key == 27)	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if (Key == 13)	//ENTER key is pressed
			return Label;
		if ((Key == 8) && (Label.size() >= 1))	//BackSpace is pressed
			Label.resize(Label.size() - 1);
		else
			Label += Key;
		if (pO)
			pO->PrintMessage(Label);
	}
}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{
	int x, y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if (UI.InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_PLAYMODE: return TO_PLAY;
			case ITM_RECT: return DRAW_RECT;
			case ITM_HEXAGON: return DRAW_HEXAGON;
			case ITM_TRIANGLE: return DRAW_TRIANGLE;
			case ITM_SQUARE: return DRAW_SQUARE;
			case ITM_CIRCLE: return DRAW_CIRCLE;
			case ITM_CHANGEBORDER: return TO_CHANGEBORDER;
			case ITM_CHANGEFILL: return TO_CHANGEFILL;
			case ITM_BLACK: return SEL_BLACK;
			case ITM_YELLOW: return SEL_YELLOW;
			case ITM_ORANGE: return SEL_ORANGE;
			case ITM_RED: return SEL_RED;
			case ITM_GREEN: return SEL_GREEN;
			case ITM_BLUE: return SEL_BLUE;
			case ITM_SELECT: return TO_SELECT;
			case ITM_DELETEFIGURE: return TO_DELETEFIGURE;
			case ITM_CLEARALL: return TO_CLEARALL;
			case ITM_COPYFIGURE: return TO_COPYFIGURE;
			case ITM_CUTFIGURE: return TO_CUTFIGURE;
			case ITM_PASTEFIGURE: return TO_PASTEFIGURE;
			case ITM_SENDTOBACK: return TO_SENDFRONT;
			case ITM_BRINGTOFRONT: return TO_BRINGBACK;
			case ITM_SAVEGRAPH: return TO_SAVEGRAPH;
			case ITM_LOADGRAPH: return TO_LOADGRAPH;
			case ITM_EXIT: return EXIT;

			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;
	}
	else	//GUI is in PLAY mode
	{
		///TODO:
		//perform checks similar to Draw mode checks above
		//and return the correspoding action
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			int ClickedItemOrder = (x / UI.MenuItemWidth);

			switch (ClickedItemOrder)
			{
			case ITM_DRAWMODE: return TO_DRAW;
			case ITM_FIGURETYPE: return TO_FIGURETYPE;
			case ITM_FIGUREFILL: return TO_FILLCOLOUR;
			case ITM_BOTH: return TO_FIGUREANDFILL;
			case ITM_EXIT_P: return EXIT;

			default: return EMPTY;
			}
		}

		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return PLAYING_AREA;
		}

		return STATUS;	//just for now. This should be updated
	}

}
/////////////////////////////////

Input::~Input()
{
}