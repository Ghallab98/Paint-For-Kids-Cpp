#ifndef ADD_RESIZE_ACTION_H
#define ADD_RESIZE_ACTION_H

#include "Actions\Action.h"


class ResizeAction : public Action
{
private:
	double Factor;

public:
	ResizeAction(ApplicationManager *pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

};

#endif