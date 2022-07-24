#include "function.h"

int isRepent = 0;  // 是否重新走棋
int isrecord;
int isrecordplay;
int help;
bool isstart,ispause;//判断开始游戏、暂停游戏 
bool timereset;//判断时间重置 
extern int 	counttime;
extern int Round;
void helpdisplay();
// 按钮程序
void drawButtons()
{
	usePredefinedColors(3);
	SetPointSize(22);
	double width, height;   // 窗口尺寸
	setButtonColors("Brown", "White", "board1", "White", 1);

	width = GetWindowWidth();
	height = GetWindowHeight();
	double h = GetFontHeight() * 2-0.05;  
	double x = width / 1.5+1;
	double y = height - h/1.5;
	double w = width / 5; 

	// 游戏开始
	if (button(GenUIID(0), x, y - 3 * h, w, h, isstart ? "结束游戏" : "开始游戏"))
		{
		isstart = !isstart;
		chessinit();
	}
	// 游戏暂停
	if (button(GenUIID(0), x, y - 6 * h, w, h, ispause ? "游戏继续" : "游戏暂停"))
		ispause = !ispause;
	// 悔棋
	if (button(GenUIID(0), x, y - 4.5 * h, w, h, "悔棋"))
		{
			isRepent = 1;
			counttime=20;
			chessrepent();
		}
	if (button(GenUIID(0), x, y - 12 * h, w, h, isrecord ? "暂停录制" : "对局录制"))
	    {
	    	isrecord=!isrecord;
		}

	// 游戏录制

	// 退出
	if (button(GenUIID(0), x, y - 10.5 * h, w/2-0.1, h, "上一局"))
		{
		    isrecordplay=1;
		   
		   // recordplay();
		    //display();
		    //InitConsole();
		   // printf("%d %d %d",board[0][0].name,board[0][0].overRiver,board[0][0].type);
		}
	if (button(GenUIID(0), x+w/2, y - 10.5 * h, w/2, h, "删除"))
	{
		FILE *file;
	    file = fopen("record.txt","w");//清空当前文件夹下的record.txt文件
		fclose(file); 
	}
	 
	 
	if (button(GenUIID(0), x, y - 7.5 * h, w, h, "停一手"))
		{
			Round = (Round + 1) % 2; 
			timereset=1;
		} 
	if (button(GenUIID(0), x, y - 9 * h, w, h, "帮助"))
	{
		help=1;
	}
}

void helpdisplay()
{
	SetPenColor("Black");
	SetFont("楷体");
	SetPointSize(22); 
	MovePen(1,9);
	DrawTextString("点击开始开始行棋子，倒计时有颜色，红色代表红方，黑色代表黑方回合，倒计时结束自动进入下一回合");
	MovePen(1,8);
	DrawTextString("选中棋子会显示绿色。当选中棋子后未按照规则行棋会取消选中，需要重新选棋子"); 
	MovePen(1,7);
	DrawTextString("点击悔棋可以撤回棋子");
	MovePen(1,6);
	DrawTextString("当发生吃棋时，右下角会显示被吃棋子");
	MovePen(1,5);
	DrawTextString("当将或帅被吃后，右下角方形框中会显示胜利方，棋局重置") ; 
	MovePen(1,4);
	DrawTextString("点击停一手后，会跳过本回合己方行棋，进入下一回合对方行棋") ;
	MovePen(1,3);
	DrawTextString("点击对局录制，会开始记录对局中每一步行棋，点击结束停止录制，点击查看上一局可以按照顺序播放录制的棋局,删除则清空录制") ;  
	if (button(GenUIID(0), 1, 1 , 2, 1, "退出帮助"))
		{
			help=0; 
	display();
		}
}
