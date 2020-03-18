#ifndef UI_INFO_H
#define UI_INFO_H

#include "..\CMUgraphicsLib\CMUgraphics.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface

enum GUI_MODE	//Graphical user interface mode
{
	MODE_DRAW,	//Drawing mode (startup mode)
	MODE_PLAY,	//Playing mode
	MODE_PALLETE,
};

enum DrawMenuItem //The items of the Draw menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here
	ITM_RECT,		//Recangle item in menu
	ITM_LINE,
	ITM_TRI,
	ITM_RHOMBUS,
	ITM_ELLIPSE,
	ITM_SELECT,
	ITM_CHNG_DRAW_CLR,
	ITM_CHNG_FILL_CLR,
	ITM_DELETE,
	ITM_COPY,
	ITM_CUT,
	ITM_PASTE,
	ITM_SAVE,
	ITM_SAVE_BY_TYPE,
	ITM_LOAD,
	ITM_PALLETE,
	ITM_RESIZE,
	ITM_TO_PLAY,
	


	//TODO: Add more items names here

	ITM_EXIT,		//Exit item
	DRAW_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum
	
};

enum PlayMenuItem //The items of the Play menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here
	
	//TODO: Add more items names here
	PLAY_FIGURE_TYPE,
	PLAY_FIGURE_COLOUR,
	PLAY_TO_DRAW,
	PLAY_RESTART,
	PLAY_EXIT,
	PLAY_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum
	
};

enum PalleteMenuItems
{
	
	PRED,
	PGREEN,
	PYELLOW,
	PBLUE,
	PBLACK,
	PTODRAW,
	PALLETE_ITM_COUNT,
};



__declspec(selectany) //This line to prevent "redefinition error"

struct UI_Info	//User Interface Info.
{
	GUI_MODE InterfaceMode;
	
	int	width, height,	    //Window width and height
		wx , wy,			//Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		MenuItemWidth;		//Width of each item in toolbar menu
	

	color DrawColor;		//Drawing color
	color FillColor;		//Filling color
	color HighlightColor;	//Highlighting color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color StatusBarColor;	//Status bar color
	int PenWidth;			//width of the pen that draws shapes

	/// Add more members if needed
	
}UI;	//create a global object UI

#endif