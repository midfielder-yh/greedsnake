#pragma once
#ifndef FOOD_H
#define FOOD_H
#include"snake.h"
class Snake;
class Food
{
public:
	Food() :x(0), y(0),cnt(0), f_flag(false),flag(false), f_x(0), f_y(0), count(0),f_flash (false), f_needflash(false){}
	void DrawFood( Snake&);
	void DrawFlashFood( Snake&);
	void Count();
	bool GetF_flash();
private:
	bool f_flash;//闪烁标志
	bool f_needflash;//是否需要闪烁标志
	int x, y, f_x, f_y;
	int cnt;
	bool f_flag ;
	bool flag ;
	int count;
	friend class Snake;
};
#endif