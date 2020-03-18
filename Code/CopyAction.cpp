#include "CopyAction.h"

#include "ApplicationManager.h"

#include "GUI\Input.h"
#include "GUI\Output.h"

CopyAction::CopyAction(ApplicationManager *pApp) :Action(pApp) {

}

void CopyAction::ReadActionParameters() {

	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	if (pManager->GetSelectedFig() != NULL)
	{
		pManager->SetClipboard(pManager->GetSelectedFig());
		pOut->PrintMessage("Figure Copied");
	}
	else
	{
		pOut->PrintMessage("No Figure is selected to Copy");
	}

}

void CopyAction::Execute() {
	//This action needs to read some parameters first
	ReadActionParameters();


}