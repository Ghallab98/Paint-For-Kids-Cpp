#include "PasteAction.h"
#include "CRhombus.h"
#include "CEllipse.h"
#include "CLine.h"
#include "Figures/CRectangle.h"
#include "CTriangle.h"
#include "CRhombus.h"
#include "ApplicationManager.h"

#include "GUI\Input.h"
#include "GUI\Output.h"

PasteAction::PasteAction(ApplicationManager *pApp) :Action(pApp) {
}

//Reads parameters
void PasteAction::ReadActionParameters() {
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	CFigure*PP = pManager->GetSelectedFig();
	CFigure*P = pManager->GetClipboard();
	Point P2, P3;
	Input* pIn = pManager->GetInput();
	pIn->GetPointClicked(P1.x, P1.y);
	if (pManager->GetCutCopy() == 1) {
		if (pManager->GetClipboard() != NULL)
		{
			if (dynamic_cast<CRhombus*>(P) != NULL) {
				CRhombus* Rho = new CRhombus(P1, PP->GetGfxInfo());
				pManager->AddFigure(Rho);
				pOut->PrintMessage("Pasted");
			}
			if (dynamic_cast<CTriangle*>(P) != NULL) {
				double Diffx = P1.x - (P->GetCorner1().x);
				double Diffy = P1.y - (P->GetCorner1().y);
				P2.x = (P->GetCorner2().x) + Diffx;
				P2.y = (P->GetCorner2().y) + Diffy;
				P3.x = (P->GetCorner3().x) + Diffx;
				P3.y = (P->GetCorner3().y) + Diffy;
				CTriangle* Tri = new CTriangle(P1, P2, P3, PP->GetGfxInfo());
				pManager->AddFigure(Tri);
				pOut->PrintMessage("Pasted");
			}
			if (dynamic_cast<CRectangle*>(P) != NULL) {
				double Diffx = P1.x - (P->GetCorner1().x);
				double Diffy = P1.y - (P->GetCorner1().y);
				P2.x = (P->GetCorner2().x) + Diffx;
				P2.y = (P->GetCorner2().y) + Diffy;
				CRectangle* Rec = new CRectangle(P1, P2, PP->GetGfxInfo());
				pManager->AddFigure(Rec);
				pOut->PrintMessage("Pasted");
			}
			if (dynamic_cast<CEllipse*>(P) != NULL) {
				CEllipse* E = new CEllipse(P1, PP->GetGfxInfo());
				pManager->AddFigure(E);
				pOut->PrintMessage("Pasted");
			}

			if (dynamic_cast<CLine*>(P) != NULL) {
				double Diffx = P1.x - (P->GetCorner1().x);
				double Diffy = P1.y - (P->GetCorner1().y);
				P2.x = (P->GetCorner2().x) + Diffx;
				P2.y = (P->GetCorner2().y) + Diffy;
				CLine* L = new CLine(P1, P2, PP->GetGfxInfo());

				pManager->AddFigure(L);
				pOut->PrintMessage("Pasted");
			}
			pManager->DeleteFigure();
			pOut->ClearDrawArea();
			PP->SetSelected(false);
			pOut->PrintMessage("Figure Pasted");
		}
		else
		{
			pOut->PrintMessage("No Figure in Clipboard to Paste");
		}
	}
	else if (pManager->GetCutCopy() == 2) {
		if (pManager->GetClipboard() != NULL)
		{
			if (dynamic_cast<CRhombus*>(P) != NULL) {
				CRhombus* Rho = new CRhombus(P1, P->GetGfxInfo());
				pManager->AddFigure(Rho);
				pOut->PrintMessage("Pasted");
			}
			if (dynamic_cast<CTriangle*>(P) != NULL) {
				double Diffx = P1.x - (P->GetCorner1().x);
				double Diffy = P1.y - (P->GetCorner1().y);
				P2.x = (P->GetCorner2().x) + Diffx;
				P2.y = (P->GetCorner2().y) + Diffy;
				P3.x = (P->GetCorner3().x) + Diffx;
				P3.y = (P->GetCorner3().y) + Diffy;
				CTriangle* Tri = new CTriangle(P1, P2, P3, P->GetGfxInfo());
				pManager->AddFigure(Tri);
				pOut->PrintMessage("Pasted");
			}
			if (dynamic_cast<CRectangle*>(P) != NULL) {
				double Diffx = P1.x - (P->GetCorner1().x);
				double Diffy = P1.y - (P->GetCorner1().y);
				P2.x = (P->GetCorner2().x) + Diffx;
				P2.y = (P->GetCorner2().y) + Diffy;
				CRectangle* Rec = new CRectangle(P1, P2, P->GetGfxInfo());
				pManager->AddFigure(Rec);
				pOut->PrintMessage("Pasted");
			}
			if (dynamic_cast<CEllipse*>(P) != NULL) {
				CEllipse* E = new CEllipse(P1, P->GetGfxInfo());
				pManager->AddFigure(E);
				pOut->PrintMessage("Pasted");
			}

			if (dynamic_cast<CLine*>(P) != NULL) {
				double Diffx = P1.x - (P->GetCorner1().x);
				double Diffy = P1.y - (P->GetCorner1().y);
				P2.x = (P->GetCorner2().x) + Diffx;
				P2.y = (P->GetCorner2().y) + Diffy;
				CLine* L = new CLine(P1, P2, P->GetGfxInfo());

				pManager->AddFigure(L);
				pOut->PrintMessage("Pasted");
			}
			PP->SetSelected(false);
			pOut->PrintMessage("Figure Pasted");
		}
		else
		{
			pOut->PrintMessage("No Figure in Clipboard to Paste");
		}
	}
}

//Add select to the ApplicationManager
void PasteAction::Execute() {
	//This action needs to read some parameters first
	ReadActionParameters();
}
