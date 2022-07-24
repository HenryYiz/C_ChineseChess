#include "Drawchessboard.h"



char* chessName1[] = { "車", "馬", "象", "士", "将", "砲", "卒",
						"俥", "马", "相", "仕", "帥", "炮", "兵" };
				

//绘制棋盘细节 小十字 
void qipan1(double x, double y)
{
	MovePen(x-0.3,y+0.05);
	DrawLine(0.25,0);
	DrawLine(0,0.25);
	MovePen(x+0.3,y+0.05);
	DrawLine(-0.25,0);
	DrawLine(0,0.25);
	MovePen(x-0.3,y-0.05);
	DrawLine(0.25,0);
	DrawLine(0,-0.25);
	MovePen(x+0.3,y-0.05);
	DrawLine(-0.25,0);
	DrawLine(0,-0.25);
} 
void qipan2(double x,double y,double di)
{
	if (di==-1)
	{
	MovePen(x+0.3,y+0.05);
	DrawLine (-0.25,0);
	DrawLine (0,0.25);
	MovePen (x+0.3,y-0.05);
	DrawLine (-0.25,0);
	DrawLine (0,-0.25);		
	}
	else 
	{
	MovePen(x-0.3,y+0.05);
	DrawLine (0.25,0);
	DrawLine (0,0.25);
	MovePen (x-0.3,y-0.05);
	DrawLine (0.25,0);
	DrawLine (0,-0.25);	
	}

}
void qipan()//绘制棋盘
{
	int i ;
	DefineColor("board1",205/256.0 ,133/256.0, 63/256.0);
	SetPenColor("board1");
	drawRectangle(0,0,9.5,11,1);
	SetPenColor("Black");
	SetPenSize(2);
	MovePen(0.5, 0.5);
	for (i = 1; i < 10; i++)
	{
		DrawLine(8, 0);
		MovePen(0.5,0.5+i );
	}
	DrawLine(8, 0);
	MovePen(0.5, 0.5);
	DrawLine(0, 9);
	MovePen(8.5, 4.5);
	DrawLine(0, 1);
	for (i = 1; i < 10; i++)
	{
		DrawLine(0, 4);
		MovePen(0.5+i, 0.5);
	}
	MovePen(0.5, 5.5);
	
	for (i = 1; i < 10; i++)
	{
		DrawLine(0, 4);
		MovePen(0.5 + i, 5.5);
	}
	char a[] = "楚河";
	SetFont("楷体") ;
	SetPointSize(50);
	drawLabel(0.5, 4.75, "      楚河         汉界");
	
	qipan1(2.5,3.5);
	qipan1(4.5,3.5);
	qipan1(6.5,3.5);
	qipan1(1.5,2.5);
	qipan1(7.5,2.5);
	qipan1(1.5,7.5);
	qipan1(2.5,6.5);
	qipan1(4.5,6.5);
	qipan1(6.5,6.5);
	qipan1(7.5,7.5);
	qipan2(0.5,6.5,-1);
	qipan2(0.5,3.5,-1);
	qipan2(8.5,6.5,1);
	qipan2(8.5,3.5,1);
	MovePen (3.5,0.5);
	DrawLine(2,2);
	MovePen (5.5,0.5);
	DrawLine(-2,2);
	MovePen (3.5,7.5);
	DrawLine(2,2);
	MovePen (5.5,7.5);
	DrawLine(-2,2);
	SetFont("Times");
	
}
void DrawCircle(double x, double y, double r)
{
    MovePen(x + r, y);
    DrawArc(r, 0.0, 360);
}
void Drawchess()//绘制棋子 
{
	//255 222 173
	DefineColor("chess2",255/256.0 ,222/256.0, 173/256.0);
	SetPenSize(1);
	int i,j;
	for (i=0;i<9;i++)
	{
		for (j=0;j<10;j++)
	{
		if (board[i][j].name==SPACE)
		continue;
		if(board[i][j].type==RED&&board[i][j].choose==FALSE)
		{
			SetPenColor("chess2");
			StartFilledRegion(1);
			DrawCircle(board[i][j].x, board[i][j].y, chesssize);
			EndFilledRegion();
			SetFont("楷体");
			SetPenColor("Red");
			SetPointSize(35);
			DrawCircle(board[i][j].x, board[i][j].y, chesssize-0.05);
			MovePen(board[i][j].x - TextStringWidth(chessName1[board[i][j].name]) / 2, board[i][j].y - GetFontAscent() / 2);
			DrawTextString(chessName1[board[i][j].name]);
		}
			
		if(board[i][j].type==BLACK&&board[i][j].choose==FALSE)
		{
			SetPenColor("chess2");
			StartFilledRegion(1);
			DrawCircle(board[i][j].x, board[i][j].y, chesssize);
			EndFilledRegion();
			SetFont("楷体");
			SetPenColor("Black");
			SetPointSize(35);
			DrawCircle(board[i][j].x, board[i][j].y, chesssize-0.05);
			MovePen(board[i][j].x - TextStringWidth(chessName1[board[i][j].name]) / 2, board[i][j].y - GetFontAscent() / 2);
			DrawTextString(chessName1[board[i][j].name]);
			
		}
		if (board[i][j].type!=NONE&&board[i][j].choose==TRUE)//选中棋子 
		{
			SetPenColor("Green");
			StartFilledRegion(0.0);
			DrawCircle(board[i][j].x, board[i][j].y, chesssize);
			EndFilledRegion();
			SetFont("楷体");
			SetPointSize(35);
			DrawCircle(board[i][j].x, board[i][j].y, chesssize-0.05);
			MovePen(board[i][j].x - TextStringWidth(chessName1[board[i][j].name]) / 2, board[i][j].y - GetFontAscent() / 2);
			DrawTextString(chessName1[board[i][j].name]);
		}
	
		}
	}
	
	SetFont("Times");
}
