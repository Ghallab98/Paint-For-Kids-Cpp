#include "ResizeAction.h"

#include "ApplicationManager.h"

#include "GUI\Input.h"
#include "GUI\Output.h"


ResizeAction::ResizeAction(ApplicationManager * pApp) :Action(pApp)
{}

void ResizeAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Enter the factor you want to resize the selected figure by: ");
	Factor = stod(pIn->GetSrting(pOut));

}

//Execute the action
void ResizeAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	if (pManager->GetSelectedFig() != NULL)
	{
		ReadActionParameters();
		pManager->ResizeFigure(Factor);
	}
	else
		pOut->PrintMessage("No selected figures");
}