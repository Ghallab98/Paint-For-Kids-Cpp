#ifndef ADD_PASTE_ACTION_H
#define ADD_PASTE_ACTION_H

#include "Figures\CFigure.h"
#include "Actions\Action.h"

class PasteAction :public Action {
private:
	Point P1;
	CFigure *P;
	GfxInfo EllGfxInfo;
public:
	PasteAction(ApplicationManager *pApp);

	//Reads parameters
	virtual void ReadActionParameters();

	//Add select to the ApplicationManager
	virtual void Execute();

};
#endif