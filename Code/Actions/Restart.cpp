#include "Restart.h"
#include "../ApplicationManager.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"


Restart::Restart(ApplicationManager* pApp) :Action(pApp)
{
}

void Restart::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Restarting Play Mode");
}

void Restart::Execute()
{
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();
	/*ifstream fin("tempsave.txt", ios::in);
	pManager->LoadAll(fin);
	fin.close();*/
}


