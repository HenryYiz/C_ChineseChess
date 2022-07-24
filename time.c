#include "function.h"
#include <time.h>

#define alltime 20
bool judge=TRUE;
int recordtime=0;
extern int Round;
extern int isRepent;
extern int My_count;
int My_record;
extern bool timereset;
extern int help;
int counttime = alltime;
void ClearCount();
void DrawCount();
char* countnumber[]={"0","1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18","19","20"};
void TimerEventProcess(int timerID)
{
	//ClearCount();
	//display();
	if (judge==isstart)
	{
		counttime=alltime;
	}
	judge=FALSE;
	if (timerID==My_count)
	{

		if (ispause==TRUE)
		{
			return;
		}	
		if (counttime<1)
		{
			Round = (Round + 1) % 2; 
			counttime=alltime;
		}

		if (timereset==1)
		{
			timereset=0;
			counttime=alltime;
		}

		if  (isstart)    
		counttime--;
		
		if(isrecordplay==1)
		{
		recordtime++;
		recordplay();
	    }
		   
		
		display();
		
	}

}

void DrawCount()
{
	SetPenSize(2);

	double x_=11.6,y_=9.3,r_=0.5;
	if (counttime>0)
	{
		SetPenColor("Black");
		drawRectangle(x_-0.5,y_-0.5,1,1,0);
		if (Round==redRound)
		SetPenColor("Red");
		if (Round==blackRound)
		SetPenColor("Black");
		MovePen(x_ - TextStringWidth(countnumber[counttime]) / 2, y_ - GetFontAscent() / 2);
		DrawTextString(countnumber[counttime]);
	}
}

