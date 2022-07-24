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

//extern char* chessName[] = { "車", "馬", "象", "士", "将", "砲", "卒",
//						"俥", "马", "相", "仕", "帥", "炮", "兵" };
				

							
							
//所有结构体 
enum chesslist //枚举棋子 車,馬,象,士,将,砲,卒,俥,马,相,仕,帥,炮,兵,
{
SPACE = -1,red_che,red_ma,red_xiang,red_shi,red_jiang,red_pao,red_zu,
b_che,b_ma,b_xiang,b_shi,b_shuai,b_pao,b_bing,BEGIN,END
};

typedef enum chesslist ChessType;
typedef char* string;
typedef int step;

typedef struct chess
{
	ChessType name; // 棋子名称
	unsigned int type; // 棋子的类别,红色或者黑色
	double x; // 横坐标
	double y; // 纵坐标
	bool overRiver;
	bool choose; //是否选中 
} Chess;//, * pChess;

typedef struct myStackObj
{
	int x; // 棋子在地图中的横坐标
	int y; // 棋子在地图中的纵坐标
	ChessType name; // 棋子名称
	unsigned int type; // 棋子的类别,红色或者黑色
	bool overRiver; // 是否过河
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


Chess board[9][10];//棋盘每个坐标点的信息 

// 定义棋子的属性

//记录每一个位置的棋子信息 

void MouseEventProcess(int x, int y, int button, int event);
void chessMove();
void ChessInit();
void qipan1(double x, double y);
void qipan();//绘制棋盘
void qipan2(double x,double y,double di);
void Drawchess();		
void DrawCircle();
void chessrecord();
void chessrepent();
void judgewinner();

#endif
