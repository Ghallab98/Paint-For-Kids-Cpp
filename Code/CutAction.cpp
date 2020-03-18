#include "CutAction.h"
#include "Figures\CFigure.h"
#include "ApplicationManager.h"

#include "GUI\Input.h"
#include "GUI\Output.h"

CutAction::CutAction(ApplicationManager *pApp) :Action(pApp) {
}

//Reads parameters
void CutAction::ReadActionParameters() {
	CFigure* P = (pManager->GetSelectedFig());
	Output* pOut = pManager->GetOutput();

	if (pManager->GetSelectedFig() != NULL)
	{
		pManager->SetClipboard(pManager->GetSelectedFig());
		P->ChngDrawClr(GRAY);
		P->ChngFillClr(GRAY);
		P->SetSelected(false);

		pOut->PrintMessage("Figure Cut");
	}
	else
	{
		pOut->PrintMessage("No Figure is selected to Cut");
	}
}

//Add Cut to the ApplicationManager
void CutAction::Execute() {
	//This action needs to read some parameters first
	ReadActionParameters();

}