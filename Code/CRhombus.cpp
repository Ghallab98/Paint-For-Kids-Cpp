#include "CRhombus.h"

CRhombus::CRhombus(Point P1, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P1;
	type = "Rhombus";
}
Point CRhombus::GetCorner1() {
	return Center;
}
Point CRhombus::GetCorner2() {
	return Center;
}
Point CRhombus::GetCorner3() {
	return Center;
}


void CRhombus::Draw(Output* pOut) const
{
	//Call Output::DrawRhombus to draw a rhombus on the screen	
	pOut->DrawRhombus(Center, FigGfxInfo, Selected);
}

bool CRhombus::PointInside(int x, int y)
{
	double f = abs(x - (double) Center.x) / 100 + abs(y - (double) Center.y) / 150;
	return (f <= 1);
}

void CRhombus::PrintInfo(Output* pOut)
{
	pOut->PrintMessage("Rhombus ID: " + to_string(GetID()) + " Center: (" + to_string(Center.x) + "," + to_string(Center.y) + ")");
}