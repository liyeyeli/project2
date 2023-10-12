#ifndef __FIVECHESS_H__
#define __FIVECHESS_H__
#include"bmp.h"
#define WHITE 2
#define BLACK 1

//设计一个双向链表存放顶点坐标
typedef struct vertex
{
	int status;//判断是否可以悔棋
	int winner;
	int flag;//判断是否有棋的标志位
	int x;
	int y;
	struct vertex* next;
	struct vertex* prev;
}Vertex;
typedef struct verfirst
{
	//int blacklength;//存放有多少个黑棋
	//int whitelength;//存放有多少个白棋
	struct vertex* first;
}Verfirst;

Vertex* my_distance(Vertex* v, int x0, int y0, Vertex* p);
Verfirst* init_ver();
Verfirst* Hor_vertex_all();
Verfirst* Ver_vertex_all();
//Verfirst* Left_vertex_all();
Vertex* MoveChesspiont(int* x1, int* y1);
int game_winner();
//int black_winner(Vertex* v, int flag, int length);
int game_status(Vertex* H, Vertex* V, /*Vertex* L,*/ int winner);
int Rafmiacg(Vertex* v);


#endif 
