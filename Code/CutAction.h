#ifndef ADD_CUT_ACTION_H
#define ADD_CUT_ACTION_H
#include "CMUGraphicsLib\colors.h"
#include "Actions\Action.h"
#include "Figures\CFigure.h"
class CutAction :public Action {
private:
	CFigure* P;
public:
	CutAction(ApplicationManager *pApp);

	//Reads parameters
	virtual void ReadActionParameters();

	//Add select to the ApplicationManager
	virtual void Execute();
};
#endif 