
#include "PickbyShapeAction.h"


#include "..\CRhombus.h"
#include "..\CTriangle.h"
#include "..\CEllipse.h"
#include "..\CLine.h"
#include"..\Figures\CRectangle.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

PickbyShapeAction::PickbyShapeAction(ApplicationManager * pApp):Action(pApp)
{
	NFigures=0;
	tries=0;
	correct=0;
	incorrect=0;
}

void PickbyShapeAction::ReadActionParameters() 
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	type=pManager->GetRandomShape();
	if(type!="NULL"){
		pOut->PrintMessage("Pick all "+type+"S");}
	else {pOut->PrintMessage("No Figures Remaining");}
}

//Execute the action
void PickbyShapeAction::Execute() 
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	ReadActionParameters();
	if(type!="NULL"){
	NFigures=pManager->GetNumShape(type);
	while(correct!=NFigures)
	{
		pIn->GetPointClicked(P1.x, P1.y);
		CFigure *Selected=pManager->GetFigure(P1.x,P1.y);
		if(Selected==NULL)
		{
			pOut->PrintMessage("No new figure has been picked");
		}
		else if(pManager->IsCorrectShape(Selected,type))
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