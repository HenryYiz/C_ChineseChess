#include "function.h"
char* chessname[] = { "車", "馬", "象", "士", "将", "砲", "卒",
					"俥", "马", "相", "仕", "帥", "炮", "兵" };
void Drawwin();
extern ChessEaten eaten;
extern int Round;
int awin,bwin;
extern bool isstart,ispause;
extern bool timereset;
extern State state;
void Drawwin()
{
	double x=10.5,y=0.5,w=2.5,h=2.5;
	SetPenColor("Black");
	drawRectangle(x,y,w,h,0);
	MovePen(11.5, 1.5);
    if(awin==0&&bwin==0&&eaten.chessType!=NONE)
   	{
						
		if(eaten.chessType==RED&&eaten.chessName!=red_jiang)
		{
			SetPenColor("Red");
		
			DrawCircle(11.75, 1.75, 0.5);
		
            MovePen(11.75 - TextStringWidth(chessname[eaten.chessName]) / 2, 1.75 - GetFontAscent() / 2);
		
			DrawTextString(chessname[eaten.chessName]);
		}else if (eaten.chessType==BLACK&&eaten.chessName!=b_shuai)
		{
			SetPenColor("Black");
			
		    DrawCircle(11.75, 1.75, 0.5);
		    MovePen(11.75 - TextStringWidth(chessname[eaten.chessName]) / 2, 1.75 - GetFontAscent() / 2);
			DrawTextString(chessname[eaten.chessName]);
	
		}else if (eaten.chessName==red_jiang)
		{
			SetPenColor("Black");
			drawRectangle(x,y,w,h,0);
			MovePen(11.75 - TextStringWidth("黑方胜利") / 2, 1.75 - GetFontAscent() / 2);
			DrawTextString("黑方胜利");
		}
		else if(eaten.chessName==b_shuai)
		{
			SetPenColor("Red");
			drawRectangle(x,y,w,h,0);
			MovePen(11.75 - TextStringWidth("红方胜利") / 2, 1.75 - GetFontAscent() / 2);
			DrawTextString("红方胜利");
		}
	}
	if(bwin==1)
	{
	//chessinit();
	isstart=0;
	timereset=1;
    Round = redRound;
    bwin=0;
    }
    if(awin==1)
    {
	//chessinit();
	isstart=0;
	timereset=1;
    Round = redRound;
    awin=0;
	}
}
