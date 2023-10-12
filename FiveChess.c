#include "FiveChess.h"

//落子位置函数：当触摸位置距离哪个顶点最近，就在那个顶点生成棋子
//首先写一个比较距离大小的函数
//v为所有顶点坐标，x0，y0为触摸屏获取坐标，p为存放最短距离的坐标节点
Vertex* my_distance(Vertex* v, int x0, int y0, Vertex* p)
{
	if (v == NULL)
	{
		return p;
	}
	if (v->x == 440&&v->y==440)
	{
		return p;
	}
	int distance= (v->x - x0) * (v->x - x0) + (v->y - y0) * (v->y - y0);
	int dis= (p->x - x0) * (p->x - x0) + (p->y - y0) * (p->y - y0);
	if (dis < distance)
	{
		return my_distance(v->next,x0,y0,p);
	}
	else
	{
		p = v;
		return my_distance(v->next, x0,y0,p);
	}
}
Verfirst* init_ver()
{
	Verfirst* v = (Verfirst*)malloc(sizeof(*v));
	v->first = NULL;
//	v->blacklength = 0;
//	v->whitelength = 0;
	return v;
}
//写一个函数横向存放所有顶点信息。横：horizontal，竖：vertical左对角：left diagonal
Verfirst* Hor_vertex_all()
{
	Verfirst* v = init_ver();
	Vertex* ver = (Vertex*)malloc(sizeof(*ver));
	ver->next = NULL;
	ver->prev = NULL;
	v->first = ver;

	//找到落子的位置:横向遍历每一个顶点
	int x, y;
	for (y = 40; y < 480; y++)
	{
		for (x = 40; x < 480; x++)
		{
			if (x % 40 == 0 && y % 40 == 0)
			{
				//此时的xy为顶点坐标,拿双向循环链表存放此时的xy坐标值
				ver->status = 0;
				ver->flag = 0;//标志位置0
				ver->x = x;
				ver->y = y;
				if (x == 440 && y == 440)
				{
					ver->next = v->first;
					v->first->prev = ver;
					continue;
				}
				Vertex* q = (Vertex*)malloc(sizeof(*q));
				q->next = NULL;
				q->prev = NULL;
				ver->next = q;
				q->prev = ver;
				ver = q;
			}
		}
	}
	return v;
}
//写一个函数竖向存放所有顶点信息。横：horizontal，竖：vertical左对角：left diagonal
Verfirst* Ver_vertex_all()
{
	Verfirst* v = init_ver();
	Vertex* ver = (Vertex*)malloc(sizeof(*ver));
	ver->next = NULL;
	ver->prev = NULL;
	v->first = ver;

	//找到落子的位置:竖直遍历每一个顶点
	int x, y;
	for (x = 40; x < 480; x++)
	{
		for (y = 40; y < 480; y++)
		{
			if (x % 40 == 0 && y % 40 == 0)
			{
				//此时的xy为顶点坐标,拿双向循环链表存放此时的xy坐标值
				ver->status = 0;
				ver->flag = 0;//标志位置0
				ver->x = x;
				ver->y = y;
				if (x == 440 && y == 440)
				{
					ver->next = v->first;
					v->first->prev = ver;
					continue;
				}
				Vertex* q = (Vertex*)malloc(sizeof(*q));
				q->next = NULL;
				q->prev = NULL;
				ver->next = q;
				q->prev = ver;
				ver = q;
			}
		}
	}
	return v;
}
////写一个函数左对角存放所有顶点信息。横：horizontal，竖：vertical左对角：left diagonal
Verfirst* Left_vertex_all()
{
	Verfirst* v = init_ver();
	Vertex* ver = (Vertex*)malloc(sizeof(*ver));
	ver->next = NULL;
	ver->prev = NULL;
	v->first = ver;
	int flag = 0;
	int flag1 = 0;
	//找到落子的位置:左对角遍历每一个顶点
	int x, y;
	for (x = 40; x < 480; x++)
	{
		for (y = 40; y < 480; y++)
		{
			if (x % 40 == 0 && y % 40 == 0)
			{
				if (y == 40)
				{
					while (1)
					{
						//此时的xy为顶点坐标,拿双向循环链表存放此时的xy坐标值
						ver->flag = 0;//标志位置0
						ver->x = x;
						ver->y = y;
						Vertex* q = (Vertex*)malloc(sizeof(*q));
						q->next = NULL;
						q->prev = NULL;
						ver->next = q;
						q->prev = ver;
						ver = q;
						if (x == 40)
						{
							x = x + x * flag;
							break;
						}
						else
						{
							x = x - 40;
							y = y + 40;
							flag++;
						}
					}
					break;
				}
			}
		}
	}
	//printf("%d %d\n", v->first->x, v->first->y);
	//printf("%d %d\n", v->first->next->x, v->first->next->y);
	//printf("%d %d\n", v->first->next->next->x, v->first->next->next->y);
	//printf("%d %d\n", v->first->next->next->next->x, v->first->next->next->next->y);
	for (x = 40; x <480; x++)
	{
		for (y = 80; y < 480; y++)
		{
			if (x % 40 == 0 && y % 40 == 0)
			{
				if (x == 440)
				{
					while (1)
					{
						//此时的xy为顶点坐标,拿双向循环链表存放此时的xy坐标值
						ver->flag = 0;//标志位置0
						ver->x = x;
						ver->y = y;
						if (x == 440 && y == 440)
						{
							ver->next = v->first;
							v->first->prev = ver;
							break;
						}
						Vertex* q = (Vertex*)malloc(sizeof(*q));
						q->next = NULL;
						q->prev = NULL;
						ver->next = q;
						q->prev = ver;
						ver = q;
						printf("%d %d\n", ver->prev->x, ver->prev->y);
						printf("%d %d\n", ver->prev->prev->x, ver->prev->prev->y);
						break;
						if (y == 440)
						{
							y = y - 40 * flag1++;
							break;
						}
						else
						{
							x = x - 40;
							y = y + 40;
							flag1++;
						}

					}
					break;
				}
			}
		}
	}
	return v;
}
//落子函数,找到落子位置
Vertex*  MoveChesspiont(int* x1, int* y1)
{
	Verfirst* v = init_ver();
	v = Hor_vertex_all();
	Vertex* p = (Vertex*)malloc(sizeof(*p));
	p->next = NULL;
	p->prev = NULL;
	Vertex* q = (Vertex*)malloc(sizeof(*q));
	q->x = 40;
	q->y = 40;
	q->next = NULL;
	q->prev = NULL;
	//判断此时的x1，y1距离哪个点最近
	p = my_distance(v->first, *x1, *y1,q);
	return p;
	
}
//黑棋先行，并返回游戏胜利的那个玩家执黑棋还是白棋
int game_winner()
{
	int flag = 0;
	int* x = (int*)malloc(sizeof(*x));
	int* y = (int*)malloc(sizeof(*x));
	Verfirst* H = init_ver();
	H = Hor_vertex_all();
	Verfirst* V = init_ver();
	V = Ver_vertex_all();
//	Verfirst* L = init_ver();
//	L = Left_vertex_all();
	//Vertex* blackhead = (Vertex*)malloc(sizeof(*blackhead));//存放所有黑色的棋子
	//Vertex* whitehead = (Vertex*)malloc(sizeof(*whitehead));//存放所有白色的棋子
	Vertex* p = (Vertex*)malloc(sizeof(*p));
	while (1)
	{		
		get_coordinate(x, y);
		if (*x > 750 && *y > 420)
		{
			break;
		}
		p = MoveChesspiont(x, y);
		while (1)
		{
			if (p->x == V->first->x && p->y == V->first->y)
			{
				break;
			}
			V->first = V->first->next;
		}
	/*	while (1)
		{
			if (p->x == L->first->x && p->y == L->first->y)
			{
				break;
			}
			L->first = L->first->next;
		}*/
		while (1)
		{
			if (H->first->x == p->x && H->first->y == p->y && H->first->flag == 0)
			{
				if (flag % 2 == 0)
				{
					//此时p内存放的xy坐标即为最短距离坐标
					ChessPieces(p->x, p->y, 0x00000000);
					//v->blacklength++;
					H->first->flag = 1;
					V->first->flag = 1;
				//	L->first->flag = 1;
					flag++;
					H->first->winner = BLACK;
					V->first->winner = BLACK;
				//	L->first->winner = BLACK;
					Rafmiacg(H->first);
					//flag++;
					int gameover = game_status(H->first, V->first,/*L->first,*/ H->first->winner);
					if (gameover == 0)
					{
						printf("BLACK WINNER\n");
						printf("game over!\n");
						return 0;
					}

					break;
				}
				if (flag % 2 == 1)
				{
					ChessPieces(p->x, p->y, 0x00ffffff);
				//	v->whitelength++;
					H->first->flag = 1;
					V->first->flag = 1;
				//	L->first->flag = 1;
					flag++;
					H->first->winner = WHITE;
					V->first->winner = WHITE;
				//	L->first->winner = WHITE;
					Rafmiacg(H->first);
					//flag++;
					int gameover = game_status(H->first, V->first/*, L->first*/, H->first->winner);
					if (gameover == 0)
					{
						printf("WRITE WINNER\n");
						printf("game over!\n");
						return 0;
					}
					break;
				}
			}
			else if (H->first->x == p->x && H->first->y == p->y && H->first->flag == 1)
			{
				perror("This point is not NULL!\n");
				perror("Please continue!\n");
				break;
			}
			H->first = H->first->next;
		}
	}
}
//判断输赢
int game_status(Vertex* H, Vertex* V, /*Vertex* L,*/ int winner)
{
	int V1 = 0;
	int V2 = 0;
	while (V->winner == V->next->winner && V->winner == winner && V->x == V->next->x)
	{
		V1++;
		V = V->next;
	}
	while (V->winner == V->prev->winner && V->winner == winner && V->x == V->next->x)
	{
		V2++;
		V = V->prev;
	}
	if (V2 >= 4)
	{
		return 0;
	}
	int H1=0;
	int H2=0;
	while (H->winner == H->next->winner && H->winner == winner && H->y == H->next->y)
	{
		H1++;
		H = H->next;
	}
	while (H->winner == H->prev->winner && H->winner == winner && H->y == H->next->y)
	{
		H2++;
		H = H->prev;
	}
	if (H2 >= 4)
	{
		return 0;
	}
	/*int L1 = 0;
	int L2 = 0;
	while (L->winner == L->next->winner && L->winner == winner && abs(L->y - L->next->y)==40)
	{
		L1++;
		L = L->next;
	}
	while (L->winner == L->prev->winner && L->winner == winner && abs(L->y - L->next->y) == 40)
	{
		L2++;
		L = L->prev;
	}
	if (L2 >= 4)
	{
		return 0;
	}*/
	return 1;
}
//悔棋功能retract a false move in a chess game,返回1.
int Rafmiacg(Vertex* v)
{
	int x3, y3;
	get_coordinate(&x3, &y3);
	if (x3 > 480 && y3 < 240)
	{
		int x1, y1;
		for (y1 = 0; y1 < 480; y1++)
		{
			for (x1 = 0; x1 < 480; x1++)
			{
				if (((x1 - v->x) * (x1 - v->x) + (y1 - v->y) * (y1 - v->y)) <= 64)//五分之一的边长为半径
				{
					draw_point(x1, y1, 0x0080ffff);
				}
			}
		}
		int x, y;
		for (x = 0; x < 480; x++)
		{
			if (x == v->x)
			{
				for (y = 0; y < 480; y++)
				{
					if (y <= v->y + 8 && y >= v->y - 8)
					{	
						int flag = 0;
						while (flag < 2)
						{
							draw_point(x, y, 0x00000000);
							flag++;
						}
					}
				}
			}
		}
		int x2, y2;
		for (y2 = 0; y2 < 480; y2++)
		{
			if (y2 == v->y)
			{
				for (x2 = 0; x2 < 480; x2++)
				{
					if (x2 <= v->x + 8 && x2 >= v->x - 8)
					{

						int flag = 0;
						while (flag < 2)
						{
							draw_point(x2, y2, 0x00000000);
							flag++;
						}
					}
				}
			}
		}
		v->flag = 0;
		return 1;
	}
	return 0;
}


//int black_winner(Vertex* v,int flag,int length)
//{
//	if (flag == 4)
//	{
//		printf("BLACK WINNER!\n");
//		return 0;
//	}
//	if (length <= 5)
//	{
//		return 1;
//	}
//	if (v->x == v->next->x && abs(v->y - v->next->y) == 40)
//	{
//		if (length > flag)
//		{
//			flag++;
//		}
//		else
//		{
//			return 0;
//		}
//		printf("%d\n", flag);
//		return black_winner(v->next, flag,length);
//	}
//	return 1;
//}
//判断游戏是否结束,结果返回0，否则返回1;
//int game_status(Verfirst* V,char c, Vertex* blackhead, Vertex* whitehead)
//{
//	Vertex* v1 = (Vertex*)malloc(sizeof(*v1));
//	v1->next == NULL;
//	v1->prev == NULL;
//	Vertex* v3 = (Vertex*)malloc(sizeof(*v3));
//	v3->next == NULL;
//	v3->prev == NULL;
//	v3 = v->first;
//	v1 = blackhead;
//	int flag = 0;
//	int i = 0;
//	while (1)
//	{
//		if (i)
//		{
//			v3 = v3->next;
//			if (i == 121)
//			{
//				break;
//			}
//		}
//		if (v3->flag == 1 && v3->winner==BLACK)
//		{
//			if (flag == 0)
//			{
//				v1->flag = v3->flag;
//				v1->winner = v3->winner;
//				v1->x = v3->x;
//				v1->y = v3->y;
//				flag++;
//				i++;
//				continue;
//			}
//			Vertex* v2 = (Vertex*)malloc(sizeof(*v2));
//			v2->next == NULL;
//			v2->prev == NULL;
//			v2->flag = v3->flag;
//			v2->winner = v3->winner;
//			v2->x = v3->x;
//			v2->y = v3->y;
//			v1->next = v2;
//			v2->prev = v1;
//			//v1 = v1->next;
//			while (v1->prev)
//			{
//				v1 = v1->prev;
//			}
//			v2->next = v1;
//			v1->prev = v2;
//			v1 = v2;
//		}
//		i++;
//	}
//	int len = v->blacklength;
//	int a = black_winner(blackhead, 0,len);
//	if (a == 0)
//	{
//		return 0;
//	}
//	return 1;
//}




