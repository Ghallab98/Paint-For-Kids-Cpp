#include "CTriangle.h"

CTriangle::CTriangle(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;
	type = "Triangle";
}

Point CTriangle::GetCorner1() {
	return Corner1;
}

Point CTriangle::GetCorner2()
{
	return Corner2;
}

Point CTriangle::GetCorner3() {
	return Corner3;
}

void CTriangle::Draw(Output* pOut) const
{
	//Call Output::DrawTri to draw a triangle on the screen	
	pOut->DrawTri(Corner1, Corner2, Corner3, FigGfxInfo, Selected);
}

bool CTriangle::PointInside(int x, int y)
{
	int as_x = x - Corner1.x;
	int as_y = y - Corner1.y;

	bool s_ab = (Corner2.x - Corner1.x)*as_y - (Corner2.y - Corner1.y)*as_x > 0;

	if ((Corner3.x - Corner1.x)*as_y - (Corner3.y - Corner1.y)*as_x > 0 == s_ab) return false;

	if ((Corner3.x - Corner2.x)*(y - Corner2.y) - (Corner3.y - Corner2.y)*(x - Corner2.x) > 0 != s_ab) return false;

	return true;

}

void CTriangle::PrintInfo(Output* pOut)
{
	pOut->PrintMessage("Triangle ID: " + to_string(GetID()) + " Corner1: (" + to_string(Corner1.x) + "," + to_string(Corner1.y) + ")"
		+ " Corner2: (" + to_string(Corner2.x) + "," + to_string(Corner2.y) + ")"
		+ " Corner3: (" + to_string(Corner3.x) + "," + to_string(Corner3.y) + ")");
}

void CTriangle::Resize(double f)
{
	Point Center;
	Center.x = (Corner1.x + Corner2.x + Corner3.x) / 3;
	Center.y = (Corner1.y + Corner2.y + Corner3.y) / 3;
	Corner1.x = Center.x + f * (Corner1.x - Center.x);
	Corner1.y = Center.y + f * (Corner1.y - Center.y);
	Corner2.x = Center.x + f * (Corner2.x - Center.x);
	Corner2.y = Center.y + f * (Corner2.y - Center.y);
	Corner3.x = Center.x + f * (Corner3.x - Center.x);
	Corner3.y = Center.y + f * (Corner3.y - Center.y);
}