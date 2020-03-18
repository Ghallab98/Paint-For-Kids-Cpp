#include "Exit.h"
#include  "..\ApplicationManager.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"


Exit::Exit(ApplicationManager * pApp):Action(pApp)
{
}

void Exit::ReadActionParameters() 
{	
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("EXIT");
	pOut->ClearStatusBar();
}

void Exit::Execute() 
{
	Output* pOut = pManager->GetOutput();
	pManager->ClearFigList();
	ReadActionParameters();
}
