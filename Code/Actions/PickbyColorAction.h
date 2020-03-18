#ifndef _pickbyclr
#define _pickbyclr
#include "Action.h"
class PickbyColorAction :public Action
{
private:
	color fill;
	int NFigures,tries,correct,incorrect;
	Point P1;
public:
	PickbyColorAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute() ;
};

#endif