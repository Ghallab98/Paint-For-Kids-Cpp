#ifndef SWITCHDM_ACTION_H
#define SWITCHDM_ACTION_H

#include "Action.h"
class SwitchToDrawAction :public Action 
{
public:
	 SwitchToDrawAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute() ;
};

#endif