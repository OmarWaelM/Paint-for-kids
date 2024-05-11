#include "CTriangle.h"

CTriangle::CTriangle(Point p1, Point p2, Point p3, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	P1 = p1;
	P2 = p2;
	P3 = p3;

	ID = Number_Of_Figures;
}

CTriangle::CTriangle(CTriangle* old, GfxInfo newGfxInfo) :CFigure(newGfxInfo)
{
	P1 = old->P1;
	P2 = old->P2;
	P3 = old->P3;

	ID = Number_Of_Figures;
}

void CTriangle::Draw(Output* pOut) const
{
	pOut->DrawTri(P1, P2, P3, FigGfxInfo, Selected, Cut);
}

void CTriangle::PrintInfo(Output* pOut)
{
	string msg = "Triangle's Info : ID =" + to_string(ID);

	msg =msg + " ,Point 1 : ( " + to_string(P1.x) + " , " + to_string(P1.y) + " )";

	msg =msg + " ,Point 2 : ( " + to_string(P2.x) + " , " + to_string(P2.y) + " )";

	msg =msg + " ,Point 3 : ( " + to_string(P3.x) + " , " + to_string(P3.y) + " )";

	pOut->PrintMessage(msg);

}

bool CTriangle::IsWithin(Point P)
{
	//This function gets the total area fo the triangle and then the area of three other triangles made when connecting the test point with two vertices
	//If the sum of the three areas are equal to the total area then point is within the triangle
	int AT, A1, A2, A3;
	AT = abs(P1.x * (P2.y - P3.y) + P2.x * (P3.y - P1.y) + P3.x * (P1.y - P2.y));
	A1 = abs(P.x * (P2.y - P3.y) + P2.x * (P3.y - P.y) + P3.x * (P.y - P2.y));
	A2 = abs(P1.x * (P.y - P3.y) + P.x * (P3.y - P1.y) + P3.x * (P1.y - P.y));
	A3 = abs(P1.x * (P2.y - P.y) + P2.x * (P.y - P1.y) + P.x * (P1.y - P2.y));
	
	if (AT == (A1 + A2 + A3))
		return true;
	return false;
}

void CTriangle::Move(Point P)
{
	//getting centre
	Point Centre;
	Centre.x = (P1.x + P2.x + P3.x) / 3;
	Centre.y = (P1.y + P2.y + P3.y) / 3;
	
	int dist_x = P.x - Centre.x;
	int dist_y = P.y - Centre.y;
	//moving points same distance as centre is moved
	P1.x = P1.x + dist_x;
	P1.y = P1.y + dist_y;

	P2.x = P2.x + dist_x;
	P2.y = P2.y + dist_y;

	P3.x = P3.x + dist_x;
	P3.y = P3.y + dist_y;
}

void CTriangle::SetScale(double scale)
{
	this->scale = scale;
	Point Centre;
	Centre.x = (P1.x + P2.x + P3.x) / 3;
	Centre.y = (P1.y + P2.y + P3.y) / 3;
	
	int dist1_x = Centre.x - P1.x;
	int dist1_y = Centre.y - P1.y;
	int dist2_x = Centre.x - P2.x;
	int dist2_y = Centre.y - P2.y;
	int dist3_x = Centre.x - P3.x;
	int dist3_y = Centre.y - P3.y;

	P1.x = Centre.x - dist1_x * scale;
	P1.y = Centre.y - dist1_y * scale;
	P2.x = Centre.x - dist2_x * scale;
	P2.y = Centre.y - dist2_y * scale;
	P3.x = Centre.x - dist3_x * scale;
	P3.y = Centre.y - dist3_y * scale;

	int dif1_x = 0, dif1_y = 0, dif2_x = 0, dif2_y = 0, dif3_x = 0, dif3_y = 0;
	//checking for collision with boundaries
	if (P1.x < 0)
		dif1_x = 0 - P1.x;
	else if (P1.x > UI.width)
		dif1_x = UI.width - P1.x;
	if (P1.y < UI.ToolBarHeight)
		dif1_y = UI.ToolBarHeight - P1.y;
	else if (P1.y > UI.height - UI.StatusBarHeight)
		dif1_y = P1.y - UI.height - UI.StatusBarHeight;

	if (P2.x < 0)
		dif2_x = 0 - P2.x;
	else if (P2.x > UI.width)
		dif2_x = UI.width - P2.x;
	if (P2.y < UI.ToolBarHeight)
		dif2_y = UI.ToolBarHeight - P2.y;
	else if (P2.y > UI.height - UI.StatusBarHeight)
		dif2_y = P2.y - UI.height - UI.StatusBarHeight;

	if (P3.x < 0)
		dif3_x = 0 - P3.x;
	else if (P3.x > UI.width)
		dif3_x = UI.width - P3.x;
	if (P3.y < UI.ToolBarHeight)
		dif3_y = UI.ToolBarHeight - P3.y;
	else if (P3.y > UI.height - UI.StatusBarHeight)
		dif3_y = P3.y - UI.height - UI.StatusBarHeight ;
	//checking for maximum offset of point from boudary and moves centre by said distance
	if (max(dif1_x, max(dif2_x, dif3_x)) > 0)
		Centre.x = Centre.x + max(dif1_x, max(dif2_x, dif3_x));
	else if (min(dif1_x, min(dif2_x, dif3_x)) < 0)
		Centre.x = Centre.x + min(dif1_x, min(dif2_x, dif3_x));

	if (max(dif1_y, max(dif2_y, dif3_y)) > 0)
		Centre.y = Centre.y + max(dif1_y, max(dif2_y, dif3_y));
	else if (min(dif1_y, min(dif2_y, dif3_y)) < 0)
		Centre.y = Centre.y + min(dif1_y, min(dif2_y, dif3_y));
	//updating centre
	Move(Centre);
}

void CTriangle::Save(ofstream& OutputFile)
{
	string DrawColor;
	string FillColor;
	string FigureType = "TRIANGLE";

	if (FigGfxInfo.DrawClr == BLACK)
		DrawColor = "BLACK";
	else if (FigGfxInfo.DrawClr == YELLOW)
		DrawColor = "YELLOW";
	else if (FigGfxInfo.DrawClr == ORANGE)
		DrawColor = "ORANGE";
	else if (FigGfxInfo.DrawClr == RED)
		DrawColor = "RED";
	else if (FigGfxInfo.DrawClr == GREEN)
		DrawColor = "GREEN";
	else if (FigGfxInfo.DrawClr == BLUE)
		DrawColor = "BLUE";

	if (FigGfxInfo.isFilled)
	{
		if (FigGfxInfo.FillClr == BLACK)
			FillColor = "BLACK";
		else if (FigGfxInfo.FillClr == YELLOW)
			FillColor = "YELLOW";
		else if (FigGfxInfo.FillClr == ORANGE)
			FillColor = "ORANGE";
		else if (FigGfxInfo.FillClr == RED)
			FillColor = "RED";
		else if (FigGfxInfo.FillClr == GREEN)
			FillColor = "GREEN";
		else if (FigGfxInfo.FillClr == BLUE)
			FillColor = "BLUE";
	}
	else FillColor = "NO_FILL";

	OutputFile << FigureType << "\t" << ID << "\t" << P1.x << "\t" << P1.y << "\t" << P2.x << "\t" << P2.y << "\t" << P3.x << "\t" << P3.y << "\t" << DrawColor << "\t" << FillColor << '\n';
}

void CTriangle::Load(ifstream& InputFile)
{
	string DrawCol, FillCol;
	InputFile >> ID >> P1.x >> P1.y >> P2.x >> P2.y >> P3.x >> P3.y >> DrawCol >> FillCol;

	if (DrawCol == "BLACK")
		FigGfxInfo.DrawClr = BLACK;
	else if (DrawCol == "YELLOW")
		FigGfxInfo.DrawClr = YELLOW;
	else if (DrawCol == "ORANGE")
		FigGfxInfo.DrawClr = ORANGE;
	else if (DrawCol == "RED")
		FigGfxInfo.DrawClr = RED;
	else if (DrawCol == "GREEN")
		FigGfxInfo.DrawClr = GREEN;
	else if (DrawCol == "BLUE")
		FigGfxInfo.DrawClr = BLUE;

	if (FillCol == "BLACK")
	{
		FigGfxInfo.isFilled = true;
		FigGfxInfo.FillClr = BLACK;
	}
	else if (FillCol == "YELLOW")
	{
		FigGfxInfo.isFilled = true;
		FigGfxInfo.FillClr = YELLOW;
	}
	else if (FillCol == "ORANGE")
	{
		FigGfxInfo.isFilled = true;
		FigGfxInfo.FillClr = ORANGE;
	}
	else if (FillCol == "RED")
	{
		FigGfxInfo.isFilled = true;
		FigGfxInfo.FillClr = RED;
	}
	else if (FillCol == "GREEN")
	{
		FigGfxInfo.isFilled = true;
		FigGfxInfo.FillClr = GREEN;
	}
	else if (FillCol == "BLUE")
	{
		FigGfxInfo.isFilled = true;
		FigGfxInfo.FillClr = BLUE;
	}
	else if (FillCol == "NO_FILL")
	{
		FigGfxInfo.isFilled = false;
	}
}
