#include "AddRhombusAction.h"
#include "CRhombus.h"

#include "ApplicationManager.h"

#include "GUI\Input.h"
#include "GUI\Output.h"


AddRhombusAction::AddRhombusAction(ApplicationManager * pApp) :Action(pApp)
{}

void AddRhombusAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Rhombus: Click at the center");

	//Read center and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);


	RhoGfxInfo.isFilled = false;
	//get drawing, filling colors and pen width from the interface
	RhoGfxInfo.DrawClr = pOut->getCrntDrawColor();
	RhoGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddRhombusAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a rhombus with the parameters read from the user
	CRhombus *R = new CRhombus(P1, RhoGfxInfo);

	//Add the rhombus to the list of figures
	pManager->AddFigure(R);
}