#ifndef CELLIPSE_H
#define CELLIPSE_H

#include "Figures\CFigure.h"

class CEllipse : public CFigure
{
private:
	Point Center;
public:
	CEllipse(Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool PointInside(int x, int y);
	virtual void PrintInfo(Output* pOut);
	Point GetCorner1();
	Point GetCorner2();
	Point GetCorner3();
};

#endif