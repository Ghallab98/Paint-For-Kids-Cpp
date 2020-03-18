#include "CLine.h"

CLine::CLine(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	type = "Line";
}
Point CLine::GetCorner2() {
	return Corner2;
}

Point CLine::GetCorner1() {
	return Corner1;
}

Point CLine::GetCorner3() {
	return Corner1;
}

void CLine::Draw(Output* pOut) const
{
	//Call Output::DrawLine to draw a line on the screen	
	pOut->DrawLine(Corner1, Corner2, FigGfxInfo, Selected);
}

bool CLine::PointInside(int x, int y)
{
	int maxx, minx, maxy, miny;
	if (Corner1.x>Corner2.x){ maxx = Corner1.x; minx = Corner2.x; }
	else { maxx = Corner2.x; minx = Corner1.x; }
	if (Corner1.y>Corner2.y){ maxy = Corner1.y; miny = Corner2.y; }
	else { maxy = Corner2.y; miny = Corner1.y; }

	if (Corner1.x != Corner2.x && Corner1.y != Corner2.y)
	{
		float m = float(Corner1.y - Corner2.y) / (Corner1.x - Corner2.x);
		int c = (Corner1.y) - (m*Corner1.x);


		if (int(y - (m*x)) <= c + 5 && int(y - (m*x)) >= c - 5 && x <= maxx && x >= minx && y >= miny && y <= maxy){ return true; }
		else { return false; }

	}
	if (Corner1.x == Corner2.x) {
		if (y <= maxy && y >= miny && x>Corner1.x - 4 && x<Corner1.x + 4){ return true; }
		else return false;
	}

	if (Corner1.y == Corner2.y) {
		if (x <= maxx && x >= minx && y>Corner1.y - 4 && y<Corner1.y + 4){ return true; }
		else return false;
	}
}

void CLine::PrintInfo(Output* pOut)
{
	int length = sqrt((Corner1.x - Corner2.x)*(Corner1.x - Corner2.x) + (Corner1.y - Corner2.y)*(Corner1.y - Corner2.y));
	pOut->PrintMessage("Line ID: " + to_string(GetID()) + " Start Point: (" + to_string(Corner1.x) + "," + to_string(Corner1.y) + ")"
		+ " End Point: (" + to_string(Corner2.x) + "," + to_string(Corner2.y) + ")" + " length: " + to_string(length));
}

void CLine::Resize(double f)
{
	Point Center;
	Center.x = (Corner1.x + Corner2.x) / 2;
	Center.y = (Corner1.y + Corner2.y) / 2;
	Corner1.x = Center.x + f * (Corner1.x - Center.x);
	Corner1.y = Center.y + f * (Corner1.y - Center.y);
	Corner2.x = Center.x + f * (Corner2.x - Center.x);
	Corner2.y = Center.y + f * (Corner2.y - Center.y);
}