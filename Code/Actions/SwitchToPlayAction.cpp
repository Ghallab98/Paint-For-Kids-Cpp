#include "SwitchToPlayAction.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\ApplicationManager.h"


SwitchToPlayAction::SwitchToPlayAction(ApplicationManager *pApp):Action(pApp)
{
}

void SwitchToPlayAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	if(pManager->GetFigCount()!=0)
	pOut->PrintMessage("Switch to play mode");
	else pOut->PrintMessage("No Figures to Play with!");
}
void SwitchToPlayAction::Execute() 
{
		Output* pOut = pManager->GetOutput();
	ReadActionParameters();

	/*if(pManager->GetFigCount()!=0){
	 pManager->CleanSelectedFig();
	ofstream fout("tempsave.txt",ios::out);
	pManager->SaveAll(fout);
    pOut->CreatePlayToolBar();
	fout.close();}*/
}
