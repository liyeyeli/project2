#include"my_draw.h"

//���㺯��
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
	//������
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
	//������
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
//��������
void ChessPieces(int x, int y, int color)
{
	int x1, y1;
	for (int y1 = 0; y1 < 480; y1++)
	{
		for (int x1 = 0; x1 < 480; x1++)
		{
			if (((x1 - x) * (x1 - x) + (y1 - y) * (y1 - y)) <= 64)//���֮һ�ı߳�Ϊ�뾶
			{
				draw_point(x1, y1, color);
			}
		}
	}
}

