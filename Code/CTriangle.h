#ifndef CTRIANGLE_H
#define CTRIANGLE_H

#include "Figures\CFigure.h"

class CTriangle : public CFigure
{
private:
	Point Corner1;
	Point Corner2;
	Point Corner3;
public:
	CTriangle(Point, Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool PointInside(int x, int y);
	virtual void PrintInfo(Output* pOut);
	virtual void Resize(double);
	Point GetCorner1();
	Point GetCorner2();
	Point GetCorner3();
};

#endif