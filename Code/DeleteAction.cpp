#include "DeleteAction.h"

#include "ApplicationManager.h"

#include "GUI\Input.h"
#include "GUI\Output.h"

DeleteAction::DeleteAction(ApplicationManager * pApp) :Action(pApp)
{}

void DeleteAction::ReadActionParameters()
{

}

//Execute the action
void DeleteAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	if (pManager->GetSelectedFig() != NULL)
	{
		pManager->DeleteFigure();
		pManager->SetSelectedFig(NULL);
		pOut->ClearStatusBar();
	}
	else
	{
		pOut->PrintMessage("No Figure is selected to Delete");
	}
}

