#include "function.h"

int isRepent = 0;  // �Ƿ���������
int isrecord;
int isrecordplay;
int help;
bool isstart,ispause;//�жϿ�ʼ��Ϸ����ͣ��Ϸ 
bool timereset;//�ж�ʱ������ 
extern int 	counttime;
extern int Round;
void helpdisplay();
// ��ť����
void drawButtons()
{
	usePredefinedColors(3);
	SetPointSize(22);
	double width, height;   // ���ڳߴ�
	setButtonColors("Brown", "White", "board1", "White", 1);

	width = GetWindowWidth();
	height = GetWindowHeight();
	double h = GetFontHeight() * 2-0.05;  
	double x = width / 1.5+1;
	double y = height - h/1.5;
	double w = width / 5; 

	// ��Ϸ��ʼ
	if (button(GenUIID(0), x, y - 3 * h, w, h, isstart ? "������Ϸ" : "��ʼ��Ϸ"))
		{
		isstart = !isstart;
		chessinit();
	}
	// ��Ϸ��ͣ
	if (button(GenUIID(0), x, y - 6 * h, w, h, ispause ? "��Ϸ����" : "��Ϸ��ͣ"))
		ispause = !ispause;
	// ����
	if (button(GenUIID(0), x, y - 4.5 * h, w, h, "����"))
		{
			isRepent = 1;
			counttime=20;
			chessrepent();
		}
	if (button(GenUIID(0), x, y - 12 * h, w, h, isrecord ? "��ͣ¼��" : "�Ծ�¼��"))
	    {
	    	isrecord=!isrecord;
		}

	// ��Ϸ¼��

	// �˳�
	if (button(GenUIID(0), x, y - 10.5 * h, w/2-0.1, h, "��һ��"))
		{
		    isrecordplay=1;
		   
		   // recordplay();
		    //display();
		    //InitConsole();
		   // printf("%d %d %d",board[0][0].name,board[0][0].overRiver,board[0][0].type);
		}
	if (button(GenUIID(0), x+w/2, y - 10.5 * h, w/2, h, "ɾ��"))
	{
		FILE *file;
	    file = fopen("record.txt","w");//��յ�ǰ�ļ����µ�record.txt�ļ�
		fclose(file); 
	}
	 
	 
	if (button(GenUIID(0), x, y - 7.5 * h, w, h, "ͣһ��"))
		{
			Round = (Round + 1) % 2; 
			timereset=1;
		} 
	if (button(GenUIID(0), x, y - 9 * h, w, h, "����"))
	{
		help=1;
	}
}

void helpdisplay()
{
	SetPenColor("Black");
	SetFont("����");
	SetPointSize(22); 
	MovePen(1,9);
	DrawTextString("�����ʼ��ʼ�����ӣ�����ʱ����ɫ����ɫ����췽����ɫ����ڷ��غϣ�����ʱ�����Զ�������һ�غ�");
	MovePen(1,8);
	DrawTextString("ѡ�����ӻ���ʾ��ɫ����ѡ�����Ӻ�δ���չ��������ȡ��ѡ�У���Ҫ����ѡ����"); 
	MovePen(1,7);
	DrawTextString("���������Գ�������");
	MovePen(1,6);
	DrawTextString("����������ʱ�����½ǻ���ʾ��������");
	MovePen(1,5);
	DrawTextString("������˧���Ժ����½Ƿ��ο��л���ʾʤ�������������") ; 
	MovePen(1,4);
	DrawTextString("���ͣһ�ֺ󣬻��������غϼ������壬������һ�غ϶Է�����") ;
	MovePen(1,3);
	DrawTextString("����Ծ�¼�ƣ��Ὺʼ��¼�Ծ���ÿһ�����壬�������ֹͣ¼�ƣ�����鿴��һ�ֿ��԰���˳�򲥷�¼�Ƶ����,ɾ�������¼��") ;  
	if (button(GenUIID(0), 1, 1 , 2, 1, "�˳�����"))
		{
			help=0; 
	display();
		}
}
