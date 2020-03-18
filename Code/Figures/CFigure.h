#ifndef CFIGURE_H
#define CFIGURE_H

#include "..\defs.h"
#include "..\GUI\Output.h"

//Base class for all figures
class CFigure
{
protected:
	int ID;		//Each figure has an ID
	bool Selected;	//true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphis info
	int static count;
	color tempborder;
	color tempfilled;
	string type;

public:
	CFigure(GfxInfo FigureGfxInfo);
	GfxInfo CFigure::GetGfxInfo();
	void SetSelected(bool s);	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected
	int GetID() const;
	virtual bool PointInside(int x, int y) = 0 ;

	virtual void Draw(Output* pOut) const  = 0 ;		//Draw the figure
	
	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color

	virtual void Resize(double);

	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure

	///Decide the parameters that you should pass to each function	
	virtual Point GetCorner1() = 0;
	virtual Point GetCorner2() = 0;
	virtual Point GetCorner3() = 0;

	//virtual void Save(ofstream &OutFile) = 0;	//Save the figure parameters to the file
	//virtual void Load(ifstream &Infile) = 0;	//Load the figure parameters to the file

	virtual void PrintInfo(Output* pOut) = 0;	//print all figure info on the status bar
	void tempSave();
	void returntempfilled();
	void returntempborder();
	string GetType();
	color GetFillClr();
	

};

#endif