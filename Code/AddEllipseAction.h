#ifndef ADD_ELLIPSE_ACTION_H
#define ADD_ELLIPSE_ACTION_H

#include "Actions\Action.h"

//Add ellipse Action class
class AddEllipseAction : public Action
{
private:
	Point P1;
	GfxInfo EllGfxInfo;
public:
	AddEllipseAction(ApplicationManager *pApp);

	//Reads ellipse parameters
	virtual void ReadActionParameters();

	//Add ellipse to the ApplicationManager
	virtual void Execute();

};

#endif