#include"food.h"
#include"point.h"
#include"windowdesign.h"
#include <cstdlib>
#include<stdio.h>
#include<time.h>
#include<Windows.h>
#include<iostream>
using namespace std;
void Food::DrawFood( Snake&s)
{
	while (1) 
	{
		int tmpx = rand() % 30;
		int tmpy = rand() % 30 ;
		if (tmpx < 2) tmpx += 2;
		if (tmpy < 2) tmpy += 2;
		bool flag = false;
		for (auto& point : s.snake)
		{
			if ((point.GetX() == tmpx && point.GetY() == tmpy) || (tmpx == f_x && tmpy == f_y)) {//防止食物与蛇身重叠
				flag = true;
				break;
			}
		}
		if (flag)
			continue;
		x = tmpx;
		y = tmpy;
		SetCursorPosition(x, y);
		cout << "★"; 
		cnt++;
		if (cnt == 2)
		{
			DrawFlashFood(s);
			cnt = 0;
		}
		break;
	}
}
void Food::DrawFlashFood( Snake&s)
{
	count = 40;
	while (1) {
		int tmpx = rand() % 30;
		int tmpy = rand() % 30;
		if (tmpx < 2) tmpx += 2;
		if (tmpy < 2) tmpy += 2;
		bool f_flag = false;
		for (auto& point : s.snake)
		{
			if ((point.GetX() == tmpx && point.GetY() == tmpy) || (tmpx == x && tmpy == y)) {
				f_flag = true;
				break;
			}
		}
		if (f_flag)
			continue;
		f_x = tmpx;
		f_y = tmpy;
		SetCursorPosition(f_x, f_y);
		SetColor(18);
		cout << "■"; 
		f_needflash = true;
		f_flash = true;
		break;
	}
}
void Food::Count()
{
	SetCursorPosition(f_x, f_y);
	SetColor(18);
	if (f_flash ==false)
	{
		cout << " ";
		f_flash = true;
	}
	else
	{
		cout << "■";
		f_flash = false;
	}
		--count;//闪烁时间倒计时
	if (count == 0)
	{
		SetCursorPosition(f_x, f_y);
		SetColor(0);
		cout << "  ";
		f_x = 0;
		f_y= 0;
		f_needflash = false;
	}
		
}
bool Food::GetF_flash()
{
	return f_needflash;
}