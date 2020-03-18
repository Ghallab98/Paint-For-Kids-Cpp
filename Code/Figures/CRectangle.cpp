#include "CRectangle.h"

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	type = "Rectangle";
}
Point CRectangle::GetCorner1() {
	return Corner1;
}

Point CRectangle::GetCorner2() {
	return Corner2;
}

Point CRectangle::GetCorner3() {
	return Corner2;
}

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}

bool CRectangle::PointInside(int x, int y)
{
	Point Large, Small;
	if (Corner1.x > Corner2.x)
	{
		Large.x = Corner1.x;
		Small.x = Corner2.x;
	}
	else
	{
		Large.x = Corner2.x;
		Small.x = Corner1.x;
	}
	if (Corner1.y > Corner2.y)
	{
		Large.y = Corner1.y;
		Small.y = Corner2.y;
	}
	else
	{
		Large.y = Corner2.y;
		Small.y = Corner1.y;
	}
	if (x >= Small.x && x <= Large.x && y >= Small.y && y <= Large.y)
		return true;
	else
		return false;

}

void CRectangle::PrintInfo(Output* pOut)
{
	int width = (Corner1.x > Corner2.x ? (Corner1.x - Corner2.x) : (Corner2.x - Corner1.x));
	int height = (Corner1.y > Corner2.y ? (Corner1.y - Corner2.y) : (Corner2.y - Corner1.y));
	pOut->PrintMessage("Rectangle ID: " + to_string(GetID()) + " Corner1: (" + to_string(Corner1.x) + "," + to_string(Corner1.y) + ")"
		+ " Corner2: (" + to_string(Corner2.x) + "," + to_string(Corner2.y) + ")"
		+ " width: " + to_string(width) + " height: " + to_string(height));
}

void CRectangle::Resize(double f)
{
	Point Center;
	Center.x = (Corner1.x + Corner2.x) / 2;
	Center.y = (Corner1.y + Corner2.y) / 2;
	Corner1.x = Center.x + f * (Corner1.x - Center.x);
	Corner1.y = Center.y + f * (Corner1.y - Center.y);
	Corner2.x = Center.x + f * (Corner2.x - Center.x);
	Corner2.y = Center.y + f * (Corner2.y - Center.y);

}