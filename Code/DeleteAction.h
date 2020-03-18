#ifndef ADD_DELETE_ACTION_H
#define ADD_DELETE_ACTION_H

#include "Actions\Action.h"

//Add delete Action class
class DeleteAction : public Action
{
public:
	DeleteAction(ApplicationManager *pApp);

	//Reads parameters
	virtual void ReadActionParameters();

	//Add delete to the ApplicationManager
	virtual void Execute();

};

#endif