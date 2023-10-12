#ifndef __LCD_H__
#define __LCD_H__
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include <sys/mman.h>
#include<unistd.h>
#include<errno.h>

typedef unsigned int u32;
extern u32* plcd;

int lcd_init();
void close_lcd();
//Ë¢ÆÁº¯Êý
int init_lcd(int color);

#endif 
