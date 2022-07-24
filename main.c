#include "function.h"

int m;

extern double mx, my;
extern int help;
extern int x2,y2;
extern int My_count;
extern int My_record;
extern bool isexit,isbegin,ispause,isReStart;

//extern bool canDisplayClear;
extern double countDownTime;

//void MouseEventProcess;
 
void Main()
{
	SetWindowTitle("ÖÐ¹úÏóÆå");
	InitGraphics();
	SetWindowSize(14, 10);
	chessinit();
	eaten.chessType=-1;
	registerMouseEvent(MouseEventProcess);   
	registerTimerEvent(TimerEventProcess);
	startTimer(My_count, 1000);
	
 } 
void display()
{  
	DisplayClear();
	if(help==0)
	{
		DrawCount();
    	drawButtons();
    	qipan();
    	Drawchess();
    	Drawwin();
    }
    else
    {
    	helpdisplay();
	}
}

