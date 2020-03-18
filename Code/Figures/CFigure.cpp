#include "CFigure.h"

int CFigure::count = 0;

CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
	ID = ++count;
}

void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected() const
{	return Selected; }
GfxInfo CFigure::GetGfxInfo() {
	return FigGfxInfo;
}

void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}

int CFigure::GetID() const
{
	return ID;
}

void CFigure::Resize(double f)
{}

void CFigure::tempSave()
{
	tempfilled=FigGfxInfo.FillClr;
	tempborder=FigGfxInfo.DrawClr;
}

void CFigure:: returntempfilled()
{
	 FigGfxInfo.FillClr=tempfilled;
}
void CFigure::returntempborder()
{
	FigGfxInfo.DrawClr=tempborder;
}

string CFigure::GetType()
{
	return type;
}
color CFigure:: GetFillClr()
{

	if(FigGfxInfo.isFilled == true)
	{
		return FigGfxInfo.FillClr;
	}
	else
	{
		return MAGENTA;
	}
}

