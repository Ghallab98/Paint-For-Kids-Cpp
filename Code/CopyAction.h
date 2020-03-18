#ifndef ADD_COPY_ACTION_H
#define ADD_COPY_ACTION_H

#include "Actions\Action.h"


//Add Copy Action class
class CopyAction : public Action {
public:
	CopyAction(ApplicationManager *pApp);

	//Reads parameters
	virtual void ReadActionParameters();

	//Add Copy to the ApplicationManager
	virtual void Execute();
};
#endif