#ifndef __FIVECHESS_H__
#define __FIVECHESS_H__
#include"bmp.h"
#define WHITE 2
#define BLACK 1

//���һ��˫�������Ŷ�������
typedef struct vertex
{
	int status;//�ж��Ƿ���Ի���
	int winner;
	int flag;//�ж��Ƿ�����ı�־λ
	int x;
	int y;
	struct vertex* next;
	struct vertex* prev;
}Vertex;
typedef struct verfirst
{
	//int blacklength;//����ж��ٸ�����
	//int whitelength;//����ж��ٸ�����
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
