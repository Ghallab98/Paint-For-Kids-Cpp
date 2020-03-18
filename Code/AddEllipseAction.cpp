#include "AddEllipseAction.h"
#include "CEllipse.h"

#include "ApplicationManager.h"

#include "GUI\Input.h"
#include "GUI\Output.h"


AddEllipseAction::AddEllipseAction(ApplicationManager * pApp) :Action(pApp)
{}

void AddEllipseAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Ellipse: Click at the center");

	//Read 1st point and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);


	EllGfxInfo.isFilled = false;
	//get drawing, filling colors and pen width from the interface
	EllGfxInfo.DrawClr = pOut->getCrntDrawColor();
	EllGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddEllipseAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a ellipse with the parameters read from the user
	CEllipse *E = new CEllipse(P1, EllGfxInfo);

	//Add the ellipse to the list of figures
	pManager->AddFigure(E);
}