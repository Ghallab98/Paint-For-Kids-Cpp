#ifndef CLINE_H
#define CLINE_H

#include "Figures\CFigure.h"

class CLine : public CFigure
{
private:
	Point Corner1;
	Point Corner2;
public:
	CLine(Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool PointInside(int x, int y);
	virtual void PrintInfo(Output* pOut);
	virtual void Resize(double);
	Point GetCorner1();
	Point GetCorner2();
	Point GetCorner3();
};

#endif