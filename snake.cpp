#pragma once
#include "snake.h"
#include <conio.h>
#include "windowdesign.h"
#include <iostream>
#include<Windows.h>
#include<iostream>
using namespace std;
void Snake::InitSnake()//初始化蛇
{
	for (auto& point : snake)
	{
		point.PrintCircular(); 
	}
	
}
void Snake::Eat()
{
	switch (direction)
	{
	case DOWN:
		snake.emplace_back(Point(snake.back().GetX(), snake.back().GetY() + 1)); break;
	case UP:
		snake.emplace_back(Point(snake.back().GetX(), snake.back().GetY() - 1)); break;
	case LEFT:
		snake.emplace_back(Point(snake.back().GetX()-1, snake.back().GetY() )); break;
	case RIGHT:
		snake.emplace_back(Point(snake.back().GetX()+1, snake.back().GetY() )); break;
	default:
		break;
	}
	SetColor(14);
	snake.back().PrintCircular();//打印蛇头
}
void Snake::NormalMove()
{
	    Eat();
		snake.front().Erase(); //去掉蛇尾
		snake.pop_front();//弹出蛇尾
		/*Sleep(p.speed);*/
}
bool Snake::ChangeDirection()
{
	int ch; //InitSnake();
		//NormalMove();
	if (_kbhit())
	{
		ch = _getch();
		switch (ch)
		{
		case 72://上
			if (direction != Direction::DOWN)
				direction = Direction::UP; break;
		case 80://下
			if (direction != Direction::UP)
				direction = Direction::DOWN;  break;
		case 75://左
			if (direction != Direction::RIGHT)
				direction = Direction::LEFT;  break;
		case 77://右
			if (direction != Direction::LEFT)
				direction = Direction::RIGHT;  break;
		case 27://ESC
			return false;
		default:
			return true;
		}
	}
		return true;
}
bool Snake::GetFood(const Food&f)
{
	
	if (snake.back().GetX() == f.x && snake.back().GetY() == f.y)
		return true;
	else
		return false;
}
bool Snake::GetFlashFood( Food&f)
{
	if (snake.back().GetX() == f.f_x && snake.back().GetY() == f.f_y) {
		f.f_needflash = false;
		return true;
	}
	else
		return false;
}
bool  Snake::Edge()
{
	
	return snake.back().GetX() < 30 &&
		snake.back().GetY() < 30 &&
		snake.back().GetX() > 1 &&
		snake.back().GetY() > 1;
}
bool Snake::HitItself()//撞到自身
{
	int a = 0;
	Point head = Point(snake.back().GetX(), snake.back().GetY());
	for (auto& point : snake) //如果整条蛇中与蛇头相同的坐标个数大于1，则自撞
	{
			if ((point.GetX() == head.GetX()) && (point.GetY() == head.GetY())) {
				a++;
				if (a > 1)return false;

			}
			
	}return true;
}
