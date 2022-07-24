#include "Drawchessboard.h"
#define MAXSTEP 100


//bool canDisplayClear;
int jred,jblack,bwin,awin;
extern bool isstart,ispause;//判断开始游戏、暂停游戏
extern bool CountTimeflag;
extern bool timereset;
extern int isRepent;
extern int jred,jblack;
// 初始化状态
State  state = { -1, -1, -1, -1, BEGIN };
ChessEaten eaten;//被吃的棋子 

// 创建堆栈记录棋子走过的路
StackObj chessStack[MAXSTEP][2];
//step top = 0;


// 根据象棋规则，红棋先走，所以Round初始化为redRoubd
int Round = redRound;
int hasBlock(pState state);
int lastchess=0;
//悔棋函数 

double mx, my;
int x2,y2;
int x1,y3;

void MouseEventProcess(int x, int y, int button, int event) 
{
	uiGetMouse(x, y, button, event); // GUI获取鼠标

//	double mx, my;
	mx = ScaleXInches(x); 
	my = ScaleYInches(y);
	
	switch (event) {
	case BUTTON_DOWN:
		if (button == LEFT_BUTTON && isstart == 1) 
		{	// 通过鼠标坐标得到点击的数组的下标
			
			x1=(mx)/1;
			y3=(my)/1;
			x2=x1;
			y2=y3;
	    	if (state.state == BEGIN && board[x2][y2].type==Round)
	    	{
	    	state.begx = x2;
	    	state.begy = y2;
	    	state.state = END;
	    	board[x1][y3].choose=TRUE;
			}
			else if (state.state == END && (board[x2][y2].name == SPACE || board[x2][y2].type == !Round))
			{
				state.endx = x1;
				state.endy = y3;
				state.state = BEGIN;
				board[state.begx][state.begy].choose=FALSE;
			if (ispause == 0)
				chessMove();// 如果该状态不是暂停状态，则棋子移dong
			}
	}
    }
    if (state.state == BEGIN)
		state.begy = state.begx = state.endy = state.endx = -1;
	display();
	
}

void chessMove ()
{
	bool canMove;
	if (board[state.begx][state.begy].name != SPACE &&//选中的棋子不是空 
		!(state.begx == state.endx && state.begy == state.endy) && //选中的是不同的棋子 
		state.endx != -1 && state.begx != -1&& //下标合法 
		board[state.begx][state.begy].type != board[state.endx][state.endy].type //不能自己吃自己家的棋子
		 && Round == board[state.begx][state.begy].type)//是自己的回合
	{
		switch (board[state.begx][state.begy].name)
		{
			case red_che:
			case b_che : 
					if ((state.begx==state.endx||state.begy==state.endy)&&board[state.begx][state.begy].type!= board[state.endx][state.endy].type)
					//只能直线走，不能吃自己的棋子
					{
						if (!(hasBlock(&state)))
					   {
					   	canMove = TRUE;
					   	break;
					   }
					
					} 
					break;
			case red_ma:
			case b_ma: 
					if (abs(state.begx - state.endx) == 1 && abs(state.begy - state.endy) == 2
				|| abs(state.begx - state.endx) == 2 && abs(state.begy - state.endy) == 1) //马走日字
				    {
				    	if (abs(state.begx - state.endx)==1&&(state.begy - state.endy)==2&&board[state.begx][state.begy+1].type==NONE)
				    	{
				    		canMove=TRUE;
				    		break;
						}
						if (abs(state.begx - state.endx)==1&&(state.begy - state.endy)==-2&&board[state.begx][state.begy-1].type==NONE)
				    	{
				    		canMove=TRUE;
				    		break;
						}
						if ((state.begx - state.endx)==2&&abs(state.begy - state.endy)==1&&board[state.begx+1][state.begy].type==NONE)
				    	{
				    		canMove=TRUE;
				    		break;
						}
						if ((state.begx - state.endx)==-2&&abs(state.begy - state.endy)==1&&board[state.begx-1][state.begy].type==NONE)
				    	{
				    		canMove=TRUE;
				    		break;
						}
					 } 
					 break;
				case red_shi:
				case b_shi:
					if (abs(state.begy-state.endy)==1&&abs(state.begx-state.endx)==1)
					{
						if (board[state.begx][state.begy].type==RED&&(state.endx>=3)&&state.endx<=5&&(state.endy>=0)&&(state.endy<=2))
						{
							canMove=TRUE;
							break;
						}
						else if (board[state.begx][state.begy].type==BLACK&&(state.endx>=3)&&state.endx<=5&&(state.endy>=7)&&(state.endy<=9))
						{
							canMove=TRUE;
							break;
						}
						
					}
					break;
				case red_xiang:	if(abs(state.begx-state.endx)==2&&abs(state.begy-state.endy)==2&&board[(state.begx+state.endx)/2][(state.begy+state.endy)/2].type==NONE)
						//&&判断目标位置是否是自己的棋子； 
						{
								canMove = TRUE;
								break;
						}
				case b_xiang :
						if(abs(state.begx-state.endx)==2&&abs(state.begy-state.endy)==2&&board[(state.begx+state.endx)/2][(state.begy+state.endy)/2].type==NONE)
						//&&判断目标位置是否是自己的棋子； 
						{
								canMove = TRUE;
								break;
						 } 
						 break;
				case red_zu:
						if (board[state.begx][state.begy].overRiver==FALSE&&state.endy-state.begy==1&&state.endx==state.begx)
						{//没过河，只能向前一格 
							canMove=TRUE;
							break;
						}
						else if(board[state.begx][state.begy].overRiver==TRUE&&((state.endx == state.begx && abs(state.endy - state.begy) == 1) ||
						(state.endx - state.begx == 1 && state.endy == state.begy)))
						{//过河后可以左右移动一格 
							canMove=TRUE;
							break;
						}
						break;
				case b_bing: 
						if (board[state.begx][state.begy].overRiver==FALSE&&state.endy-state.begy==-1&&state.endx==state.begx)
						{
							canMove=TRUE;
							break;
						}
						else if(board[state.begx][state.begy].overRiver==TRUE&&((state.endx == state.begx && abs(state.endy - state.begy) == 1) ||
						(state.endx - state.begx ==-1 && state.endy == state.begy)))
						{
							canMove=TRUE;
							break;
						}
						break;
				case red_jiang:
						if (abs(state.begx - state.endx) == 1 && abs(state.begy - state.endy) == 0 || abs(state.begx - state.endx) == 0 && abs(state.begy - state.endy) == 1)
						{
							if (state.endx>=3&&state.endx<=5&&state.begy<=2&&state.begy>=0) 
							{
						       canMove = TRUE;
						       break;
					        }
						}
						break;
				case b_shuai: 
				 		if (abs(state.begx - state.endx) == 1 && abs(state.begy - state.endy) == 0 || abs(state.begx - state.endx) == 0 && abs(state.begy - state.endy) == 1)
						{
							if (state.endx>=3&&state.endx<=5&&state.begy<=9&&state.begy>=7) 
							{
						       canMove = TRUE;
						       break;
					        }
						}
						break;
				case red_pao:
				case b_pao:
						if(board[state.endx][state.endy].type==NONE)
						{//炮可以直线移动，只要线路上是空； 
							if(state.begy==state.endy||state.begx==state.endx)
							{
								if (!hasBlock(&state))
								{
									canMove=TRUE;
									break;
								}
							}
						}
						else if (board[state.endx][state.endy].type==!Round)
						{//炮吃对面的棋子
						 if(state.begy==state.endy||state.begx==state.endx)//炮走直线 
						{
							int count =0,i;//计数
							if (state.begy==state.endy)
							{//横向打吃
								 if(state.begx<state.endx)
								 {
								 	for ( i=1;i<(state.endx-state.begx);i++)
								 	{
								 		if (board[state.begx+i][state.begy].type!=NONE)
								 		{
								 			count++;
										 }
									 }
									if (count==1)
									{
										canMove=TRUE;
										break;
									}
								  } 
								 else
								 {
								 	for ( i=1;i<abs(state.endx-state.begx);i++)
								 	{
								 		if (board[state.begx-i][state.begy].type!=NONE)
								 		{
								 			count++;
										 }
									 }
									if (count==1)
									{
										canMove=TRUE;
										break;
									}
								  } 
							}	//shuxiang
							else
							{//shu向打吃
								 if(state.begy<state.endy)
								 {
								 	for (i=1;i<(state.endy-state.begy);i++)
								 	{
								 		if (board[state.begx][state.begy+i].type!=NONE)
								 		{
								 			count++;
										 }
									 }
									if (count==1)
									{
										canMove=TRUE;
										break;
									}
								  } 
								 else
								 {
								 	for (i=1;i<abs(state.endy-state.begy);i++)
								 	{
								 		if (board[state.begx][state.begy-i].type!=NONE)
								 		{
								 			count++;
										 }
									 }
									if (count==1)
									{
										canMove=TRUE;
										break;
									}
								  } 
							}
						} 
						} 
				break;
		default :
			break;
		}
		
		
		if (canMove==TRUE)
		{
			if (board[state.begx][state.begy ].type==RED)
			{
				if (state.endy>=5)
				board[state.endx][state.endy].overRiver =TRUE;
				else
				board[state.endx][state.endy].overRiver =FALSE;	
			} 
			if (board[state.begx][state.begy].type==BLACK)
			{
				if (state.endy<5)
				board[state.endx][state.endy].overRiver =TRUE;
				else
				board[state.endx][state.endy].overRiver =FALSE;	
			} 
			//开始的棋子 
            chessrecord();//如果可以走，则记录数据 
            	
			if (board[state.endx][state.endy].type!=NONE)
			{
				eaten.chessName=board[state.endx][state.endy].name;
				eaten.chessType=board[state.endx][state.endy].type;
					if(eaten.chessName==red_jiang)
						bwin=1;
					if(eaten.chessName==b_shuai)
						awin=1;	
			}
			
			//后来的空位被替换或者被吃,原位置变空 
			board[state.endx][state.endy].name=board[state.begx][state.begy].name; 
			board[state.endx][state.endy].type=board[state.begx][state.begy].type;
			board[state.begx][state.begy].name=SPACE;
			board[state.begx][state.begy].type=NONE;
		 	
		 	recordgame();
			//canDisplayClear=1;
			Round = (Round + 1) % 2; 
			timereset=1;
		}
	}	 
	
	// CountTimeflag = TRUE;
}

void chessrecord()
{
	//开始的棋子 
	chessStack[lastchess][0].name=board[state.begx][state.begy].name ;
	chessStack[lastchess][0].type=board[state.begx][state.begy].type ;
	chessStack[lastchess][0].overRiver=board[state.begx][state.begy].overRiver;
	chessStack[lastchess][0].x=board[state.begx][state.begy].x ;
	chessStack[lastchess][0].y=board[state.begx][state.begy].y ;
	//动后的棋子
	chessStack[lastchess][1].name=board[state.endx][state.endy].name ;
	chessStack[lastchess][1].type=board[state.endx][state.endy].type ;
	chessStack[lastchess][1].overRiver=board[state.endx][state.endy].overRiver;
	chessStack[lastchess][1].x=board[state.endx][state.endy].x ;
	chessStack[lastchess][1].y=board[state.endx][state.endy].y ;
	
	lastchess++;
}

void chessrepent()
{
	//if (isRepent==1&&lastchess>=1)
	//{
		lastchess--;
		board[chessStack[lastchess][0].x ][chessStack[lastchess][0].y].name=chessStack[lastchess][0].name;
		board[chessStack[lastchess][0].x ][chessStack[lastchess][0].y].type=chessStack[lastchess][0].type;
		board[chessStack[lastchess][0].x ][chessStack[lastchess][0].y].overRiver=chessStack[lastchess][0].overRiver;
		
		board[chessStack[lastchess][1].x ][chessStack[lastchess][1].y].name=chessStack[lastchess][1].name;
		board[chessStack[lastchess][1].x ][chessStack[lastchess][1].y].type=chessStack[lastchess][1].type;
		board[chessStack[lastchess][1].x ][chessStack[lastchess][1].y].overRiver=chessStack[lastchess][1].overRiver;
		
		recordgame();
		isRepent=0;
		Round = (Round + 1) % 2; 
		display();
	//}	
} 

int hasBlock(pState state)
{
	int flag = 0,i;
	if (state->begx != state->endx)
	{
		// 找出begx和endx的最小值和最大值
		int minr = state->begx < state->endx ? state->begx : state->endx;
		int maxr = state->begx > state->endx ? state->begx : state->endx;
		for ( i = minr + 1; i < maxr; i++)
		{
			if (board[i][state->begy].name != SPACE)
			{
				flag = 1;
				return flag;
			}
		}
	}
	else if (state->begy != state->endy)
	{
		int minc = state->begy < state->endy ? state->begy : state->endy;
		int maxc = state->begy > state->endy ? state->begy : state->endy;
		for ( i = minc + 1; i < maxc; i++)
		{
			if (board[state->begx][i].name != SPACE)
			{
				flag = 1;
				return flag;
			}
		}
	}
	return flag;
}

