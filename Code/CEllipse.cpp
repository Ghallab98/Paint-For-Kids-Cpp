#include "CEllipse.h"

CEllipse::CEllipse(Point P1, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P1;
	type = "Ellipse";
}
Point CEllipse::GetCorner1() {
	return Center;
}
Point CEllipse::GetCorner2() {
	return Center;
}
Point CEllipse::GetCorner3() {
	return Center;
}

void CEllipse::Draw(Output* pOut) const
{
	//Call Output::DrawEllipse to draw a line on the screen	
	pOut->DrawEllipse(Center, FigGfxInfo, Selected);
}

bool CEllipse::PointInside(int x, int y)
{
	
	Point P1, P2;
	P1.x = Center.x + 100;
	P1.y = Center.y - 50;

	P2.x = Center.x - 100;
	P2.y = Center.y + 50;

	float dx = x - Center.x;
	float dy = y - Center.y;
	float a = ((dx * dx) / (10000) + (dy * dy) / 2500);
	
	return (a <= 1);
}

void CEllipse::PrintInfo(Output* pOut)
{
	int majr = Center.x + 100;
	int minr = Center.y + 50;
	pOut->PrintMessage("Ellipse ID: " + to_string(GetID()) + " Center: (" + to_string(Center.x) + "," + to_string(Center.y) + ")"
		+ " minor radius: " + to_string(minr) + " major radius: " + to_string(majr));
}