#ifndef __BMP_H__
#define __BMP_H__

#include"touch.h"
#include<dirent.h>


typedef struct circle_bmp
{
	char* name;
	struct circle_bmp* prev;
	struct circle_bmp* next;

}BMP;
typedef struct bmp_first
{
	struct circle_bmp* first;
}Bmpfirst;
int ShowBmp();
int draw_pic(int x, int y, char* pic_name);
Bmpfirst* BMPS();
int Link_Click_changepic(Bmpfirst* B, int n);//n表示传入几张图片
int Link_Fignle_changepic(Bmpfirst* B, int n);



#endif 
