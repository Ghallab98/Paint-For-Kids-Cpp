#ifndef SWITCHPM_ACTION_H
#define SWITCHPM_ACTION_H
#include "Action.h"

class SwitchToPlayAction :public Action
{
public:
	SwitchToPlayAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute() ;
};

#endif