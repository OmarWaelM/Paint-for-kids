#include "CCircle.h"

CCircle::CCircle(Point p1, Point p2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Centre = p1;
	Radius = p2;

	ID = Number_Of_Figures;
}

CCircle::CCircle(CCircle* old, GfxInfo newGfxInfo):CFigure(newGfxInfo)
{
	Centre = old->Centre;
	Radius = old->Radius;

	ID = Number_Of_Figures;
}


void CCircle::Draw(Output* pOut) const
{
	pOut->DrawCirc(Centre, Radius, FigGfxInfo, Selected, Cut);
}

void CCircle::PrintInfo(Output* pOut)
{
	string msg = "Circle's Info : ID = " + to_string(ID);

	msg = msg + " , Center Point ( " + to_string(Centre.x) + " , " + to_string(Centre.x) + " )";

	msg = msg + " , Radius = " + to_string(sqrt(pow(Centre.x - Radius.x, 2) + pow(Centre.y - Radius.y, 2)));

	pOut->PrintMessage(msg);

}

bool CCircle::IsWithin(Point P)
{
	double r = sqrt(pow(Centre.x - P.x, 2) + pow(Centre.y - P.y, 2));
	double rad = sqrt(pow(Centre.x - Radius.x, 2) + pow(Centre.y - Radius.y, 2));

	if (r <= rad)
		return true;
	return false;
}

void CCircle::Move(Point P)
{
	int dist_x = P.x - Centre.x;
	int dist_y = P.y - Centre.y;
	Centre.x = P.x; 
	Centre.y = P.y;
	Radius.x = Radius.x + dist_x;
	Radius.y = Radius.y + dist_y;
}

void CCircle::SetScale(double scale)
{
	this->scale = scale;

	int dist_x = Radius.x - Centre.x;
	int dist_y = Radius.y - Centre.y;
	int radius = sqrt(pow(dist_x, 2) + pow(dist_y, 2));

	Radius.x = Centre.x + (dist_x * scale);
	Radius.y = Centre.y + (dist_y * scale);
	
	//collision conditions
	bool cond1 = (Centre.x - (radius * scale) < 0);
	bool cond2 = (Centre.x + (radius * scale) > UI.width);
	bool cond3 = (Centre.y - (radius * scale) < UI.ToolBarHeight);
	bool cond4 = (Centre.y + (radius * scale) > (UI.height - UI.StatusBarHeight));

	if (cond1)
		Centre.x = radius * scale;
	if (cond2)
		Centre.x = UI.width - (radius * scale);
	if (cond3)
		Centre.y = UI.ToolBarHeight + (radius * scale);
	if (cond4)
		Centre.y = UI.height - UI.StatusBarHeight - (radius * scale);
}

void CCircle::Save(ofstream& OutputFile)
{
	string DrawColor;
	string FillColor;
	string FigureType = "CIRCLE";

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

	OutputFile << FigureType << "\t\t" << ID << "\t" << Centre.x << "\t" << Centre.y << "\t" << Radius.x << "\t" << Radius.y << "\t" << DrawColor << "\t" << FillColor << '\n';
}

void CCircle::Load(ifstream& InputFile)
{
	string DrawCol, FillCol;
	InputFile >> ID >> Centre.x >> Centre.y >> Radius.x >> Radius.y >> DrawCol >> FillCol;

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

