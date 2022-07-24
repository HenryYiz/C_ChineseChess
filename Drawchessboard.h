#ifndef ___drawchessboard___h____
#define ___drawchessboard___h____

#include "function.h"

#define row  10
#define col  9 
#define BLACK 0
#define RED 1
#define NONE -1
#define blackRound 0
#define redRound 1
#define chesssize 0.5

//extern char* chessName[] = { "܇", "�R", "��", "ʿ", "��", "�h", "��",
//						"�e", "��", "��", "��", "��", "��", "��" };
				

							
							
//���нṹ�� 
enum chesslist //ö������ ܇,�R,��,ʿ,��,�h,��,�e,��,��,��,��,��,��,
{
SPACE = -1,red_che,red_ma,red_xiang,red_shi,red_jiang,red_pao,red_zu,
b_che,b_ma,b_xiang,b_shi,b_shuai,b_pao,b_bing,BEGIN,END
};

typedef enum chesslist ChessType;
typedef char* string;
typedef int step;

typedef struct chess
{
	ChessType name; // ��������
	unsigned int type; // ���ӵ����,��ɫ���ߺ�ɫ
	double x; // ������
	double y; // ������
	bool overRiver;
	bool choose; //�Ƿ�ѡ�� 
} Chess;//, * pChess;

typedef struct myStackObj
{
	int x; // �����ڵ�ͼ�еĺ�����
	int y; // �����ڵ�ͼ�е�������
	ChessType name; // ��������
	unsigned int type; // ���ӵ����,��ɫ���ߺ�ɫ
	bool overRiver; // �Ƿ����
} StackObj;

typedef struct nowstate
{
	int begx;
	int begy;
	int endx;
	int endy;
	int state;
	int choose;
} State, * pState;

typedef struct EatChess
{
	int chessType;
	int chessName;
} ChessEaten;


Chess board[9][10];//����ÿ����������Ϣ 

// �������ӵ�����

//��¼ÿһ��λ�õ�������Ϣ 

void MouseEventProcess(int x, int y, int button, int event);
void chessMove();
void ChessInit();
void qipan1(double x, double y);
void qipan();//��������
void qipan2(double x,double y,double di);
void Drawchess();		
void DrawCircle();
void chessrecord();
void chessrepent();
void judgewinner();

#endif
