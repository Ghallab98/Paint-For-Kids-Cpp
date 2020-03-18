#ifndef ADD_SELECT_ACTION_H
#define ADD_SELECT_ACTION_H

#include "Actions\Action.h"

//Add select Action class
class SelectAction : public Action
{
private:
	Point P1;
	
public:
	SelectAction(ApplicationManager *pApp);

	//Reads parameters
	virtual void ReadActionParameters();

	//Add select to the ApplicationManager
	virtual void Execute();

};

#endif