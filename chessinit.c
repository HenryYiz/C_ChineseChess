#include "function.h"

//�����ⲿ����ı��� 
// �췽����
ChessType redchess[] = { red_che,red_ma,red_xiang,red_shi,red_jiang,red_pao,red_zu };
// �ڷ�����
ChessType blackchess[] = { b_che,b_ma,b_xiang,b_shi,b_shuai,b_pao,b_bing, };
extern State state;

extern int Round;

void chessinit()
{
	int x,y;//x i y-j
	for (y=0;y<10;y++)
	{
		for (x=0;x<9;x++)
		{
			board[x][y].name=SPACE;
			board[x][y].type=NONE;
		if (y<5)//��ɫ����
			{
				if (y==0)//��һ�� 
				{
					if(x<5)//�e,��,��,��,��,��,��,��,�e, 
					{
						board[x][y].name=redchess[x];
						board[x][y].type=RED;
					}
					else 
					{
						board[x][y].name=redchess[8-x];
						board[x][y].type=RED;
					}
				
				}
			
				if(y==2)
				{
						if(x==1||x==7)
						{
							board[x][y].name=redchess[5];
							board[x][y].type=RED;
						}
				}
				if(y==3)
				{
					if(x==0||x==2||x==4||x==6||x==8)
					{
						board[x][y].name=redchess[6];
						board[x][y].type=RED;
					}
				}
				board[x][y].x = x + 0.5;
				board[x][y].y = y + 0.5;	
			 } 
			else //��ɫ 
			{
				if (y==9)//��һ�� 
				{
					if(x<5)//�e,��,��,��,��,��,��,��,�e, 
					{
						board[x][y].name=blackchess[x];
						board[x][y].type=BLACK;
					}
					else 
					{
						board[x][y].name=blackchess[8-x];
						board[x][y].type=BLACK;
					}
				
				}
				if(y==7)
				{
						if(x==1||x==7)
						{
							board[x][y].name=blackchess[5];
							board[x][y].type=BLACK;
						}
				}
				if(y==6)
				{
					if(x==0||x==2||x==4||x==6||x==8)
					{
						board[x][y].name=blackchess[6];
						board[x][y].type=BLACK;
					}
				}
				board[x][y].x = x + 0.5;
				board[x][y].y = y + 0.5;
			}
			board[x][y].overRiver = FALSE;
		}
	}
}
