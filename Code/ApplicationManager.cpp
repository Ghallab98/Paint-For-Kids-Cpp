#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "AddLineAction.h"
#include "AddTriangleAction.h"
#include "AddRhombusAction.h"
#include "AddEllipseAction.h"
#include "SelectAction.h"
#include "DeleteAction.h"
#include "ResizeAction.h"
#include "Actions\PickbyColorAction.h"
#include "Actions\PickbyShapeAction.h"
#include "Actions\SwitchToDrawAction.h"
#include "Actions\SwitchToPlayAction.h"
#include "Actions\Restart.h"
#include "Actions\Exit.h"
#include "CopyAction.h"
#include "CutAction.h"
#include "PasteAction.h"

//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	
	FigCount = 0;

	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;	

	SelectedFig = NULL;
}
int ApplicationManager::GetCutCopy() {
	return CutCopy;
}

CFigure* ApplicationManager::GetClipboard()
{
	return Clipboard;
}

void ApplicationManager::SetClipboard(CFigure*pSelected) {
	Clipboard = pSelected;
}

int ApplicationManager::GetFigCount(){ return FigCount; }


void ApplicationManager::switchToPlay()
{
	for (int i = 0; i<FigCount; i++)
		FigList[i]->tempSave();
}
void ApplicationManager::switchToDraw()
{
	for (int i = 0; i<FigCount; i++)
	{
		FigList[i]->returntempborder();
		FigList[i]->returntempfilled();
	}
}
color ApplicationManager::GetRandomFillClr()
{
	if (FigCount != 0)
	{
		int x = rand() % FigCount;
		if (FigList[x]->GetType() == "LINE") return MAGENTA;
		return FigList[x]->GetFillClr();
	}
	else

		return WHITE;
}
string ApplicationManager::GetRandomShape()
{
	if (FigCount != 0)
	{
		int y = rand() % FigCount;
		return FigList[y]->GetType();
	}
	else
		return NULL;
}
int ApplicationManager::GetNumFillClr(color f)
{
	int n = 0;
	for (int i = 0; i< FigCount; i++)
	{
		if (f == FigList[i]->GetFillClr())
			n++;
	}
	return n;
}
int ApplicationManager::GetNumShape(string s)
{
	int m = 0;
	for (int i = 0; i < FigCount; i++)
	{
		if (s == FigList[i]->GetType())
		{
			m++;
		}
	}
	return m;
}
void ApplicationManager::CleanSelectedFig()
{
	for (int i = 0; i<SelectedCount; i++)
	{
		SelectedFig->SetSelected(false);
		SelectedFig = NULL;
	}
	SelectedCount = 0;
}
bool ApplicationManager::IsCorrectFillClr(CFigure *Selected, color fill)
{
	if (Selected->GetFillClr() == fill)
	{
		SelectedFig = Selected;
		SelectedCount++;
		DeleteFigure();
		return true;
	}
	else
	{
		SelectedFig = Selected;
		SelectedCount++;
		DeleteFigure();
		return false;
	}
}

bool ApplicationManager::IsCorrectShape(CFigure *Selected, string type)
{
	if (Selected->GetType() == type)
	{
		SelectedFig = Selected;
		SelectedCount++;
		DeleteFigure();
		return true;
	}
	else
	{
		SelectedFig = Selected;
		SelectedCount++;
		DeleteFigure();
		return false;
	}
}
void ApplicationManager::ClearFigList()
{
	for (int i = 0; i<FigCount; i++)
	{
		delete FigList[i];
		FigList[i] = NULL;
	}
	FigCount = 0;
}


//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
		case DRAW_RECT:
			pAct = new AddRectAction(this);
			break;

		case DRAW_LINE:
			///create AddLineAction here
			pAct = new AddLineAction(this);

			break;

		case DRAW_TRI:
			///create AddTriangleAction here
			pAct = new AddTriangleAction(this);

			break;

		case DRAW_RHOMBUS:
			///create AddRhombusAction here
			pAct = new AddRhombusAction(this);

			break;

		case DRAW_ELLIPSE:
			pAct = new AddEllipseAction(this);

			break;

		case SELECT:
			pAct = new SelectAction(this);

			break;

		case COPY:
			pAct = new CopyAction(this);
			CutCopy = 2;
			break;

		case CUT:
			pAct = new CutAction(this);
			CutCopy = 1;
			break;

		case PASTE:
			pAct = new PasteAction(this);

			break;


		case DEL:
			pAct = new DeleteAction(this);

			break;
		case RESIZE:
			pAct = new ResizeAction(this);

		case FIGURE_COLOUR:
			pAct = new PickbyColorAction(this);

			break;

		case FIGURE_TYPE:
			pAct = new PickbyShapeAction(this);

			break;

		case TO_DRAW:
			pAct = new SwitchToDrawAction(this);

			break;
		case TO_PLAY:
			pAct = new SwitchToPlayAction(this);

			break;
		case RESTART:
			pAct = new Restart(this);
			break;


		case EXIT:
			///create ExitAction here
			pAct = new Exit(this);
			break;
		
		case STATUS:	//a click on the status bar ==> no action
			return;
	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
		pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures

void ApplicationManager::ResizeFigure(double f)
{
	if (f == 0.5 || f == 0.25 || f == 2 || f == 4)
	{
		SelectedFig->Resize(f);
	pOut->ClearStatusBar();
}
	  else
		pOut->PrintMessage("Invalid factor value");
}

void ApplicationManager::AddFigure(CFigure* pFig)
{
	if(FigCount < MaxFigCount )
		FigList[FigCount++] = pFig;	
}
////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) const
{
	for (int i = FigCount - 1; i >= 0; i--)
	{
		if (FigList[i]->PointInside(x, y))
		{
			if (FigList[i]->IsSelected() == false)
			{
				FigList[i]->SetSelected(true);
				if (SelectedFig != NULL)
				{
					SelectedFig->SetSelected(false);
				}
				FigList[i]->PrintInfo(pOut);
				return FigList[i];
			}
			else
			{
				FigList[i]->SetSelected(false);
				return NULL;
			}
		}
	}
	if (SelectedFig != NULL)
	{
		SelectedFig->SetSelected(false);
	}
	return NULL;
}

void ApplicationManager::DeleteFigure()
{
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i] == SelectedFig)
		{
			for (int j = i; j < FigCount - 1; j++)
			{
				FigList[i] = FigList[i + 1];
			}
		}
	}
	FigList[FigCount] = NULL;
	FigCount--;
}




void ApplicationManager::SetSelectedFig(CFigure* pSelected)
{
	SelectedFig = pSelected;
}

CFigure* ApplicationManager::GetSelectedFig()
{
	return SelectedFig;
}






//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	pOut->ClearDrawArea();
	for(int i=0; i<FigCount; i++)
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;
	
}
