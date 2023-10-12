#include"my_draw.h"

//画点函数
int draw_point(int x, int y, int color)
{
	*(plcd + y * 800 + x) = color;
}

int draw_line()
{
	int x, y;
	for (y = 0; y < 480; y++)
	{
		for (x = 0; x < 800; x++)
		{
			draw_point(x, y, 0x0080ffff);
		}
	}
	//画横线
	for (y = 0; y < 480; y++)
	{
		if (y % 40 == 0)
		{
			for (x = 0; x <= 480; x++)
			{
				int flag = 0;
				while (flag < 2)
				{
					draw_point(x, y, 0x00000000);
					flag++;
				}
			}
			y += 2;
		}
	}
	//画竖线
	for (x = 0; x <= 480; x++)
	{
		if (x % 40 == 0)
		{
			for (y = 0; y < 480; y++)
			{
				int flag1 = 0;
				while (flag1 < 2)
				{
					draw_point(x, y, 0x00000000);
					flag1++;
				}
			}
			x += 2;
		}

	}
}
//生成棋子
void ChessPieces(int x, int y, int color)
{
	int x1, y1;
	for (int y1 = 0; y1 < 480; y1++)
	{
		for (int x1 = 0; x1 < 480; x1++)
		{
			if (((x1 - x) * (x1 - x) + (y1 - y) * (y1 - y)) <= 64)//五分之一的边长为半径
			{
				draw_point(x1, y1, color);
			}
		}
	}
}

