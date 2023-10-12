#include"lcd.h"
u32* plcd = NULL;
int fd = -1;

//´ò¿ªÓ³Éä£¬lcd
int lcd_init()
{
	int x, y;
	fd = open("/dev/fb0", O_RDWR);
	if (fd == -1)
	{
		perror("open lcd fail!");
		return -1;
	}

	plcd = mmap(NULL, 800 * 480 * 4, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	if (MAP_FAILED == plcd)
	{
		perror("open lcd fail!");
		return -1;
	}
}
int init_lcd(int color)
{
	int i, j;
	lcd_init();
	//È«ÆÁË¢°×
	for (i = 0; i < 480; i++)
	{
		for (j = 0; j < 800; j++)
		{
			draw_point(j, i, color);
		}
	}
	return fd;
}

//¹Ø±ÕlcdÆÁ
void close_lcd()
{
	munmap(plcd, 800 * 480 * 4);
	close(lcd_init());
}