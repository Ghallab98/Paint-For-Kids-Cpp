#include "SelectAction.h"

#include "ApplicationManager.h"

#include "GUI\Input.h"
#include "GUI\Output.h"

SelectAction::SelectAction(ApplicationManager * pApp) :Action(pApp)
{}

void SelectAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Select a figure");

	//Read 1st point and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->ClearStatusBar();

}

//Execute the action
void SelectAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	pManager->SetSelectedFig(pManager->GetFigure(P1.x, P1.y));


}