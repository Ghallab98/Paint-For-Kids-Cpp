#include "SwitchToDrawAction.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\ApplicationManager.h"
SwitchToDrawAction::SwitchToDrawAction(ApplicationManager * pApp):Action(pApp)
{
}


void SwitchToDrawAction::ReadActionParameters() 
{	
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Switch to draw mode");
}

void SwitchToDrawAction::Execute() 
{
    Output* pOut = pManager->GetOutput();
	ReadActionParameters();
	/*ifstream fin("tempsave.txt",ios::in);
	pManager->LoadAll(fin);
	pOut->CreateDrawToolBar();
	fin.close();*/
}
