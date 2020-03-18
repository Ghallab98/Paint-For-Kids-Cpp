#ifndef PICK_SHAPE_ACTION_H
#define PICK_SHAPE_ACTION_H

#include "Action.h"

class PickbyShapeAction :
	public Action
{
public:
private:
	string type;
	int NFigures,tries,correct,incorrect;
	Point P1;
public:
	PickbyShapeAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute() ;
};

#endif