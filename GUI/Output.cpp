#include "Output.h"


Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;
	UI.audio = AUDIO_ON;
	UI.width = 1250;
	UI.height = 650;
	UI.wx = 5;
	UI.wy = 5;


	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 40;
	UI.LineUnderTBWidth = 2;
	UI.MenuItemWidth = 40;

	UI.DrawColor = BLACK;	//Drawing color
	UI.FillColor = GREEN;	//Filling color
	UI.MsgColor = RED;		//Messages color
	UI.BkGrndColor = LIGHTGOLDENRODYELLOW;	//Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = TURQUOISE;
	UI.PenWidth = 3;	//width of the figures frames


	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project - Spring 2024");

	CreateDrawToolBar();
	CreateStatusBar();
}


Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawToolBar() const
{
	UI.InterfaceMode = MODE_DRAW;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT];
	MenuItemImages[ITM_PLAYMODE] = "images\\MenuItems\\To_Play.jpg";
	MenuItemImages[ITM_RECT] = "images\\MenuItems\\Menu_Rectangle.jpg";
	MenuItemImages[ITM_SQUARE] = "images\\MenuItems\\Menu_Square.jpg";
	MenuItemImages[ITM_TRIANGLE] = "images\\MenuItems\\Menu_Triangle.jpg";
	MenuItemImages[ITM_HEXAGON] = "images\\MenuItems\\Menu_Hexagon.jpg";
	MenuItemImages[ITM_CIRCLE] = "images\\MenuItems\\Menu_Circle.jpg";
	MenuItemImages[ITM_CHANGEBORDER] = "images\\MenuItems\\Menu_ChangeBorder.jpg";
	MenuItemImages[ITM_CHANGEFILL] = "images\\MenuItems\\Menu_ChangeFill.jpg";
	MenuItemImages[ITM_BLACK] = "images\\MenuItems\\Menu_Black.jpg";
	MenuItemImages[ITM_YELLOW] = "images\\MenuItems\\Menu_Yellow.jpg";
	MenuItemImages[ITM_ORANGE] = "images\\MenuItems\\Menu_Orange.jpg";
	MenuItemImages[ITM_RED] = "images\\MenuItems\\Menu_Red.jpg";
	MenuItemImages[ITM_GREEN] = "images\\MenuItems\\Menu_Green.jpg";
	MenuItemImages[ITM_BLUE] = "images\\MenuItems\\Menu_Blue.jpg";
	MenuItemImages[ITM_SELECT] = "images\\MenuItems\\Menu_Select.jpg";
	MenuItemImages[ITM_DELETEFIGURE] = "images\\MenuItems\\Menu_Delete.jpg";
	MenuItemImages[ITM_CLEARALL] = "images\\MenuItems\\Menu_Clear.jpg";
	MenuItemImages[ITM_COPYFIGURE] = "images\\MenuItems\\Menu_Copy.jpg";
	MenuItemImages[ITM_CUTFIGURE] = "images\\MenuItems\\Menu_Cut.jpg";
	MenuItemImages[ITM_PASTEFIGURE] = "images\\MenuItems\\Menu_Paste.jpg";
	MenuItemImages[ITM_RESIZEFOUR] = "images\\MenuItems\\Menu_ResizeFour.jpg";
	MenuItemImages[ITM_RESIZETWO] = "images\\MenuItems\\Menu_ResizeTwo.jpg";
	MenuItemImages[ITM_RESIZEHALF] = "images\\MenuItems\\Menu_ResizeHalf.jpg";
	MenuItemImages[ITM_RESIZEQUART] = "images\\MenuItems\\Menu_ResizeQuart.jpg";
	MenuItemImages[ITM_SENDTOBACK] = "images\\MenuItems\\Menu_Back.jpg";
	MenuItemImages[ITM_BRINGTOFRONT] = "images\\MenuItems\\Menu_Front.jpg";
	MenuItemImages[ITM_SAVEGRAPH] = "images\\MenuItems\\Menu_Save.jpg";
	MenuItemImages[ITM_LOADGRAPH] = "images\\MenuItems\\Menu_Load.jpg";
	if (UI.audio == AUDIO_ON) 
		MenuItemImages[ITM_AUDIO] = "images\\MenuItems\\Menu_AudioOn.jpg";
	else
		MenuItemImages[ITM_AUDIO] = "images\\MenuItems\\Menu_AudioOff.jpg";
	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\Menu_Exit.jpg";

	pWind->DrawImage("images\\MenuItems\\Toolbar_Background.jpg", 0, 0, UI.width, UI.ToolBarHeight);

	//Draw menu item one image at a time
	for (int i = 0; i < DRAW_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	//Draw a line under the toolbar
	pWind->SetPen(RED, UI.LineUnderTBWidth);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreatePlayToolBar() const
{
	UI.InterfaceMode = MODE_PLAY;
	///TODO: write code to create Play mode menu
	string MenuItemImages[PLAY_ITM_COUNT];
	MenuItemImages[ITM_DRAWMODE] = "images\\MenuItems\\To_Draw.jpg";
	MenuItemImages[ITM_FIGURETYPE] = "images\\MenuItems\\Menu_FigureType.jpg";
	MenuItemImages[ITM_FIGUREFILL] = "images\\MenuItems\\Menu_ChangeFill.jpg";
	MenuItemImages[ITM_BOTH] = "images\\MenuItems\\Menu_Both.jpg";
	MenuItemImages[ITM_EXIT_P] = "images\\MenuItems\\Menu_Exit.jpg";

	pWind->SetBrush(WHITE);

	pWind->DrawImage("images\\MenuItems\\Toolbar_Background.jpg", 0, 0, UI.width, UI.ToolBarHeight);

	//Draw menu item one image at a time
	for (int i = 0; i < PLAY_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	pWind->SetPen(RED, UI.LineUnderTBWidth);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);


}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight + UI.LineUnderTBWidth, UI.width, UI.height - UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar

	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight / 1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntDrawColor() const	//get current drawing color
{
	return UI.DrawColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntFillColor() const	//get current filling color
{
	return UI.FillColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

int Output::getCrntPenWidth() const		//get current pen width
{
	return UI.PenWidth;
}


//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected, bool cut) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, UI.PenWidth);
	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;

	if (cut)
	{
		style = FILLED;
		pWind->SetBrush(GREY);
		pWind->SetPen(GREY, UI.PenWidth);
	}

	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);
}

void Output::DrawSqr(Point P, GfxInfo SqrGfxInfo, double scale, bool selected, bool cut) const
{
	int sideLen = 200 * scale;

	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor;
	else
		DrawingClr = SqrGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, UI.PenWidth);
	drawstyle style;
	if (SqrGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(SqrGfxInfo.FillClr);
	}
	else
		style = FRAME;

	if (cut)
	{
		style = FILLED;
		pWind->SetBrush(GREY);
		pWind->SetPen(GREY, UI.PenWidth);
	}

	Point P1;
	P1.x = P.x - sideLen / 2;
	P1.y = P.y - sideLen / 2;

	Point P2;
	P2.x = P.x + sideLen / 2;
	P2.y = P.y + sideLen / 2;

	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);
}

void Output::DrawTri(Point P1, Point P2, Point P3, GfxInfo TriGfxInfo, bool selected, bool cut) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor;
	else
		DrawingClr = TriGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, UI.PenWidth);
	drawstyle style;
	if (TriGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(TriGfxInfo.FillClr);
	}
	else
		style = FRAME;

	if (cut)
	{
		style = FILLED;
		pWind->SetBrush(GREY);
		pWind->SetPen(GREY, UI.PenWidth);
	}

	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);
}

void Output::DrawHex(Point P, GfxInfo HexGfxInfo, double scale, bool selected, bool cut) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor;
	else
		DrawingClr = HexGfxInfo.DrawClr;

	
	pWind->SetPen(DrawingClr, UI.PenWidth);
	drawstyle style;
	if (HexGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(HexGfxInfo.FillClr);
	}
	else
		style = FRAME;

	if (cut)
	{
		style = FILLED;
		pWind->SetBrush(GREY);
		pWind->SetPen(GREY, UI.PenWidth);
	}

	//Distances from center of different points
	int vertDist = 100 * scale;
	int diagDist = (int)(vertDist * sqrt(3) / 3);
	int horizDist = (int)(vertDist * 2 * sqrt(3) / 3);

	//Creating and filling array of vertices co-ordinates
	int X[6];
	int Y[6];

	X[0] = P.x - diagDist;
	X[1] = P.x + diagDist;
	X[2] = P.x + horizDist;
	X[3] = P.x + diagDist;
	X[4] = P.x - diagDist;
	X[5] = P.x - horizDist;

	Y[0] = P.y + vertDist;
	Y[1] = P.y + vertDist;
	Y[2] = P.y;
	Y[3] = P.y - vertDist;
	Y[4] = P.y - vertDist;
	Y[5] = P.y;

	pWind->DrawPolygon(X, Y, 6, style);
}

void Output::DrawCirc(Point P1, Point P2, GfxInfo CircGfxInfo, bool selected, bool cut) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor;
	else
		DrawingClr = CircGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, UI.PenWidth);
	drawstyle style;
	if (CircGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(CircGfxInfo.FillClr);
	}
	else
		style = FRAME;

	if (cut)
	{
		style = FILLED;
		pWind->SetBrush(GREY);
		pWind->SetPen(GREY, UI.PenWidth);
	}

	int radius = sqrt(pow(P1.x - P2.x, 2) + pow(P1.y - P2.y, 2));

	pWind->DrawCircle(P1.x, P1.y, radius, style);
}

//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}

