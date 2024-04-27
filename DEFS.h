#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

//This file contains some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{
	TO_PLAY,		//Switch interface to Play mode
	DRAW_RECT,
	DRAW_HEXAGON,
	DRAW_TRIANGLE,
	DRAW_SQUARE,
	DRAW_CIRCLE,
	TO_CHANGEBORDER,
	TO_CHANGEFILL,
	SEL_BLACK,
	SEL_YELLOW,
	SEL_ORANGE,
	SEL_RED,
	SEL_GREEN,
	SEL_BLUE,
	TO_SELECT,
	TO_DELETEFIGURE,
	TO_CLEARALL,
	TO_COPYFIGURE,
	TO_CUTFIGURE,
	TO_PASTEFIGURE,
	TO_BRINGBACK,
	TO_SENDFRONT,
	TO_SAVEGRAPH,
	TO_LOADGRAPH,
	EXIT,
	TO_FIGURETYPE,
	TO_FILLCOLOUR,
	TO_FIGUREANDFILL,


	//Exit
	TO_DRAW,		//Switch interface to Draw mode
	EMPTY,			//A click on empty place in the toolbar
	DRAWING_AREA,
	PLAYING_AREA,	//A click on the drawing area
	STATUS			//A click on the status bar

	///TODO: Add the other action types of the two modes
};

struct Point	//To be used for figures points
{
	int x, y;
};

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth;	//Width of figure borders

};

#endif