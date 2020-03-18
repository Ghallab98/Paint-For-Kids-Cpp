#ifndef ADD_RHOMBUS_ACTION_H
#define ADD_RHOMBUS_ACTION_H

#include "Actions\Action.h"

//Add rhombus Action class
class AddRhombusAction : public Action
{
private:
	Point P1; //Rhombus center
	GfxInfo RhoGfxInfo;
public:
	AddRhombusAction(ApplicationManager *pApp);

	//Reads rhombus parameters
	virtual void ReadActionParameters();

	//Add rhombus to the ApplicationManager
	virtual void Execute();

};

#endif