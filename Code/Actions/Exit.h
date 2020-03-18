#ifndef EXIT_ACTION_H
#define EXIT_ACTION_H

#include "Action.h"
class Exit :
	public Action
{
public:
	Exit(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute() ;
};


#endif