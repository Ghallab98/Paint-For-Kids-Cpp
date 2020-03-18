#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
public:
	CRectangle(Point , Point, GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;
	bool PointInside(int x, int y);
	virtual void PrintInfo(Output* pOut);
	virtual void Resize(double);
	Point GetCorner1();
	Point GetCorner2();
	Point GetCorner3();
};

#endif