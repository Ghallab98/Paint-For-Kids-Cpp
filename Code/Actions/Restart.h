
#ifndef RESTART_ACTION_H
#define RESTART_ACTION_H

#include "Action.h"
class Restart :public Action
{
public:
	Restart(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};


#endif