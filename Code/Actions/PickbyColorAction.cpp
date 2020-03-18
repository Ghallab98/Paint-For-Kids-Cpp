#include "PickbyColorAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"
#include "..\CRhombus.h"
#include "..\CTriangle.h"
#include "..\CEllipse.h"
#include "..\CLine.h"
#include"..\Figures\CRectangle.h"

PickbyColorAction::PickbyColorAction(ApplicationManager * pApp):Action(pApp)
{
	NFigures=0;
	tries=0;
	correct=0;
	incorrect=0;
}


void PickbyColorAction::ReadActionParameters() 
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	fill=pManager->GetRandomFillClr();
	if(fill==BLACK)
		pOut->PrintMessage("Pick figures with Black fill color");
	else if(fill==YELLOW)
		pOut->PrintMessage("Pick figures with Yellow fill color");
	else if(fill==RED)
		pOut->PrintMessage("Pick figures with Red fill color");
	else if(fill==GREEN)
		pOut->PrintMessage("Pick figures with Green fill color");
	else if(fill==BLUE)
		pOut->PrintMessage("Pick figures with Blue fill color");
	else if(fill==WHITE)
		pOut->PrintMessage("No Figures Remaining");
	else
		pOut->PrintMessage("Pick figures with no fill color");
}

//Execute the action
void PickbyColorAction::Execute() 
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	ReadActionParameters();
	NFigures=pManager->GetNumFillClr(fill);

	if(fill==WHITE){}
	else{
	while(correct!=NFigures)
	{
		pIn->GetPointClicked(P1.x, P1.y);
		CFigure *Selected=pManager->GetFigure(P1.x,P1.y);
		if(Selected==NULL)
		{
			pOut->PrintMessage("No new figure has been picked");
		}
		else if(pManager->IsCorrectFillClr(Selected,fill))
		{
			correct++;
			pOut->PrintMessage("Correct figure");
		}
		else
		{
			incorrect++;
			pOut->PrintMessage("Incorrect figure");
		}
		tries++;
			pManager->UpdateInterface();
	}
	pOut->PrintMessage("Congratulations! You have won the game. Total number of tries:"+to_string(tries)+". Correct tries:"+to_string(correct)+". Incorrect tries:"+to_string(incorrect)+".");
}
}

