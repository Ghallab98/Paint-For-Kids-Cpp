#ifndef ADD_LINE_ACTION_H
#define ADD_LINE_ACTION_H

#include "Actions\Action.h"

//Add line Action class
class AddLineAction : public Action
{
private:
	Point P1, P2; //Line Points
	GfxInfo LineGfxInfo;
public:
	AddLineAction(ApplicationManager *pApp);

	//Reads line parameters
	virtual void ReadActionParameters();

	//Add line to the ApplicationManager
	virtual void Execute();

};

#endif