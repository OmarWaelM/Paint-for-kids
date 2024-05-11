#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

//This file contains some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{
	TO_PLAY,		//Switch interface to Play mode
	DRAW_RECT,		//Draw rectangle
	DRAW_HEXAGON,	//Draw Hexagon
	DRAW_TRIANGLE,	//Draw Triangle
	DRAW_SQUARE,	//Draw Square
	DRAW_CIRCLE,	//Draw Circle
	TO_CHANGEBORDER,//Change the border color
	TO_CHANGEFILL,	//Change the fill color
	SEL_BLACK,		//Selecting the color black
	SEL_YELLOW,		//Selecting the color yellow
	SEL_ORANGE,		//Selecting the color orange
	SEL_RED,		//Selecting the color red
	SEL_GREEN,		//Selecting the color green
	SEL_BLUE,		//Selecting the color blue
	TO_SELECT,		//Select a figure
	TO_DELETEFIGURE,//Delete the selected figures
	TO_CLEARALL,	//Clear all action
	TO_COPYFIGURE,	//Copy selected figure
	TO_CUTFIGURE,	//Cut selected figure
	TO_PASTEFIGURE,	//Paste figure in clipboard
	TO_RESIZEFOUR,	//Resize to four times figure size
	TO_RESIZETWO,	//Resize to two times figure size
	TO_RESIZEHALF,	//Resize to half figure size
	TO_RESIZEQUART,	//Resize to quarter figure size
	TO_SENDBACK,	//Send figure to back
	TO_BRINGFRONT,	//Send figure to front
	TO_SAVEGRAPH,	//Save current graph
	TO_LOADGRAPH,	//Load saved graph
	TO_TOGGLEAUDIO,	//Toggle audio mode from on to off
	EXIT,			//Exit progrma
	TO_FIGURETYPE,	//Pick and hide: pick using figure type
	TO_FILLCOLOUR,	//Pick and hide: pick using figure color
	TO_FIGUREANDFILL,//Pick and hide: pick using both figure type and color
	TO_DRAW,		//Switch interface to Draw mode
	EMPTY,			//A click on empty place in the toolbar
	DRAWING_AREA,	//A click on the drawing area
	PLAYING_AREA,	//A click on the playing area
	STATUS			//A click on the status bar
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