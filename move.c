#include "Drawchessboard.h"
#define MAXSTEP 100

typedef int step;
typedef char* string;
bool canDisplayClear;
extern bool CountTimeflag;
// ��ʼ��״̬
State  state = { -1, -1, -1, -1, BEGIN };

// ��������˧�ͺ��彫�Ķ�ջ
Chess redKingStack[MAXSTEP] = {11, 1, 0, 4, 0};
step redKingTop = 0;
Chess blackKingStack[MAXSTEP] = {4, 0, 9, 4, 0};
step blackKingTop = 0;

// ������ջ��¼�����߹���·
StackObj chessStack[MAXSTEP][2];
step top = 0;

ChessEaten eatStack[MAXSTEP][2] = {-1};
step eatTop = 0;


// ����������򣬺������ߣ�����Round��ʼ��ΪredRoubd
int Round = redRound;

int hasBlock(pState state);
void chessMove ();
	double mx, my;
	int x2,y2;
	int x1,y3;

void MouseEventProcess(int x, int y, int button, int event) 
{
	uiGetMouse(x, y, button, event); // GUI��ȡ���

//	double mx, my;
	mx = ScaleXInches(x); 
	my = ScaleYInches(y);
	
	switch (event) {
	case BUTTON_DOWN:
		if (button == LEFT_BUTTON )//&& start_game_end == 1) 
		{	// ͨ���������õ������������±�
			
			x1=(mx)/1;
			//if(mx>=x1+0.5) x1++;
			y3=(my)/1;
			//if(my>=y1+0.5) y1++;
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
				chessMove();
	
			}
		//	if (pause_or_continue == 0)
				// �����״̬������ͣ״̬���������ƶ�
	}
    }
    if (state.state == BEGIN)
		state.begy = state.begx = state.endy = state.endx = -1;
	display();
	
}

void chessMove ()
{
	bool canMove;
	if (board[state.begx][state.begy].name != SPACE &&//ѡ�е����Ӳ��ǿ� 
		!(state.begx == state.endx && state.begy == state.endy) && //ѡ�е��ǲ�ͬ������ 
		state.endx != -1 && state.begx != -1&& //�±�Ϸ� 
		board[state.begx][state.begy].type != board[state.endx][state.endy].type //�����Լ����Լ��ҵ�����
		 && Round == board[state.begx][state.begy].type)//���Լ��Ļغ�
	{
		switch (board[state.begx][state.begy].name)
		{
			case red_che:
			case b_che : 
					if ((state.begx==state.endx||state.begy==state.endy)&&board[state.begx][state.begy].type!= board[state.endx][state.endy].type)
					//ֻ��ֱ���ߣ����ܳ��Լ�������
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
				|| abs(state.begx - state.endx) == 2 && abs(state.begy - state.endy) == 1) //��������
				    {
				    	if (abs(state.begx - state.endx)==1&&(state.begy - state.endy)==2&&board[state.begx][state.begx+1].type==NONE)
				    	{
				    		canMove=TRUE;
				    		break;
						}
						if (abs(state.begx - state.endx)==1&&(state.begy - state.endy)==-2&&board[state.begx][state.begx-1].type==NONE)
				    	{
				    		canMove=TRUE;
				    		break;
						}
						if ((state.begx - state.endx)==2&&abs(state.begy - state.endy)==1&&board[state.begx+1][state.begx].type==NONE)
				    	{
				    		canMove=TRUE;
				    		break;
						}
						if ((state.begx - state.endx)==-2&&abs(state.begy - state.endy)==1&&board[state.begx-1][state.begx].type==NONE)
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
				case red_xiang:
				case b_xiang :
						if(abs(state.begx-state.endx)==2&&abs(state.begy-state.endy)==2&&board[(state.begx+state.endx)/2][(state.begy+state.endy)/2].type==NONE)
						//&&�ж�Ŀ��λ���Ƿ����Լ������ӣ� 
						{
							if(board[state.begx][state.begy].type==RED&&state.endy<=4.5)
							{
								canMove = TRUE;
								break;
							}
							if(board[state.begx][state.begy].type==BLACK&&state.endy>=5.5)
							{
								canMove = TRUE;
								break;
							}
						 } 
						 break;
				case red_zu:
						if (board[state.begx][state.begy].overRiver==FALSE&&state.endy-state.begy==1&&state.endx==state.begx)
						{//û���ӣ�ֻ����ǰһ�� 
							canMove=TRUE;
							break;
						}
						else if(board[state.begx][state.begy].overRiver==TRUE&&((state.endx == state.begx && abs(state.endy - state.begy) == 1) ||
						(state.endx - state.begx == 1 && state.endy == state.begy)))
						{//���Ӻ���������ƶ�һ�� 
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
							if (state.endx>=3.5&&state.endx<=5.5&&state.begy<=2.5&&state.begy>=0.5) 
							{
						       canMove = TRUE;
						       break;
					        }
						}
						break;
				case b_shuai: 
				 		if (abs(state.begx - state.endx) == 1 && abs(state.begy - state.endy) == 0 || abs(state.begx - state.endx) == 0 && abs(state.begy - state.endy) == 1)
						{
							if (state.endx>=3.5&&state.endx<=5.5&&state.begy<=9.5&&state.begy>=7.5) 
							{
						       canMove = TRUE;
						       break;
					        }
						}
						break;
				case red_pao:
				case b_pao:
						if(board[state.endx][state.endy].type==NONE)
						{//�ڿ���ֱ���ƶ���ֻҪ��·���ǿգ� 
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
						{//�ڳԶ��������
						 if(state.begy==state.endy||state.begx==state.endx)//����ֱ�� 
						{
							int count =0,i;//����
							if (state.begy==state.endy)
							{//������
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
							{//shu����
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
			//�����Ŀ�λ���滻���߱���,ԭλ�ñ�� 
			board[state.endx][state.endy].name=board[state.begx][state.begy].name; 
			board[state.endx][state.endy].type=board[state.begx][state.begy].type;
			board[state.begx][state.begy].name=SPACE;
			board[state.begx][state.begy].type=NONE;
			canDisplayClear=1;
			Round = (Round + 1) % 2; 
		}
	}	 
	
	// CountTimeflag = TRUE;
}




int hasBlock(pState state)
{
	int flag = 0,i;
	if (state->begx != state->endx)
	{
		// �ҳ�begx��endx����Сֵ�����ֵ
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









