#ifndef UI_INFO_H
#define UI_INFO_H

#include "..\CMUgraphicsLib\CMUgraphics.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface

enum GUI_MODE	//Graphical user interface mode
{
	MODE_DRAW,	//Drawing mode (startup mode)
	MODE_PLAY	//Playing mode
};

enum AUDIO_MODE //Audio mode
{
	AUDIO_ON,	//Audio on
	AUDIO_OFF	//Mute
};

enum DrawMenuItem //The items of the Draw menu (you should add more items)
{
	//Note: Items are **(ordered)** here as they appear in menu
	//If you want to change the menu items order, change the order here

	ITM_PLAYMODE,	//Switch to play mode item in menu
	ITM_RECT,		//Rectangle item in menu
	ITM_HEXAGON,	//Hexagon item in menu		
	ITM_TRIANGLE,   //Triangle item in menu
	ITM_SQUARE,		//Square item in menu
	ITM_CIRCLE,		//Circle item in menu
	ITM_CHANGEBORDER,//Change border color item in menu
	ITM_CHANGEFILL,	//Change fill color item in menu
	ITM_BLACK,		//Select black color item in menu
	ITM_YELLOW,		//Select yellow color item in menu
	ITM_ORANGE,		//Select orange color item in menu
	ITM_RED,		//Select red color item in menu
	ITM_GREEN,		//Select green color item in menu
	ITM_BLUE,		//Select blue color item in menu
	ITM_SELECT,		//Select figure item in menu
	ITM_DELETEFIGURE,//Delete Selected figure item in menu
	ITM_CLEARALL,	//Clear all item in menu
	ITM_COPYFIGURE,	//Copy selected figure item in menu
	ITM_CUTFIGURE,	//Cut selected figure item in menu
	ITM_PASTEFIGURE,//Paste clipboard figure item in menu
	ITM_RESIZEFOUR,	//Resize to four times figure size item in menu
	ITM_RESIZETWO,	//Resize to twice figure size item in menu
	ITM_RESIZEHALF,	//Resize to hald figure size item in menu
	ITM_RESIZEQUART,//Resize to quarter figure size item in menu
	ITM_SENDTOBACK,	//Send to back item in menu
	ITM_BRINGTOFRONT,//Bring to front item in menu
	ITM_SAVEGRAPH,	//Save graph item in menu
	ITM_LOADGRAPH,	//Load saved graph item in menu
	ITM_AUDIO,		//Toggle audio mode item in menu
	ITM_EXIT,		//Exit item

	DRAW_ITM_COUNT	//no. of menu items ==> This should be the last line in this enum

};

enum PlayMenuItem //The items of the Play menu (you should add more items)
{
	//Note: Items are **(ordered)** here as they appear in menu
	//If you want to change the menu items order, change the order here

	ITM_DRAWMODE,	//Switch to draw mode item in menu
	ITM_FIGURETYPE,	//Pick and hide: pick by figure type in menu
	ITM_FIGUREFILL,	//Pick and hide: pick by figure color item in menu
	ITM_BOTH,		//Pick and hide: pick by both figure type and color item in menu
	ITM_EXIT_P,		//Exit item
	PLAY_ITM_COUNT	//no. of menu items ==> This should be the last line in this enum

};

__declspec(selectany) //This line to prevent "redefinition error"

struct UI_Info	//User Interface Info.
{
	GUI_MODE InterfaceMode;
	AUDIO_MODE audio;

	int	width, height,	    //Window width and height
		wx, wy,				//Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		LineUnderTBWidth,	//line Under the Toolbar Pen Width
		MenuItemWidth;		//Width of each item in toolbar menu


	color DrawColor;		//Drawing color
	color FillColor;		//Filling color
	color HighlightColor;	//Highlighting color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color StatusBarColor;	//Status bar color
	int PenWidth;			//width of the pen that draws shapes

}UI;	//create a global object UI

#endif