#include "FiveChess.h"

int main()
{
	int x, y;
	init_lcd(0x00ffffff);

	//»­±³¾°Í¼
	draw_pic(0, 0, "17.bmp");
	draw_pic(225, 60, "18.bmp");
	draw_pic(300, 280, "16.bmp");
	draw_pic(300, 380, "15.bmp");
	while (1)
	{
		get_coordinate(&x, &y);
		if (x > 300 && x < 500 && y>280 && y < 340)
		{
			draw_pic(0, 0, "19.bmp");
			draw_pic(760, 0, "21.bmp");
		}
		if (x > 300 && x < 500 && y>380 && y < 444)
		{
			init_lcd(0x00000000);
			draw_pic(0, 15, "20.bmp");
			get_fingle_move();
			draw_pic(0, 0, "22.bmp");
			break;
		}
		if (x > 760 && x < 800 && y>0 && y < 25)
		{
			draw_pic(0, 0, "17.bmp");
			draw_pic(225, 60, "18.bmp");
			draw_pic(300, 280, "16.bmp");
			draw_pic(300, 380, "15.bmp");
		}
	}
	get_coordinate(&x, &y);
	//draw_pic(0, 0, "23.bmp");
	lcd_init();//lcd³õÊ¼»¯
	draw_line();
	draw_pic(480, 0, "13.bmp");
//	draw_pic(480, 240, "12.bmp");
	//get_coordinate(&x, &y);
	//if (x > 480 )
	//{
	//	
	//}
	game_winner();
	close_lcd();
	
	int ret = execl("/IOT/yeli/IntelSystem/main", "main", NULL);
	if (ret == -1)
	{
		perror("execl error");
		return -1;
	}
	
	return 0;
}
