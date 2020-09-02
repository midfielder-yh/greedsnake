
#pragma once
#ifndef SNAKE_H
#define SNAKE_H
#include <deque>
#include "point.h"
#include "food.h"

class Food;
class Snake
{
public:
	enum Direction { UP, DOWN, LEFT, RIGHT };
	Snake() {
		snake.emplace_back(14, 8);
		snake.emplace_back(15, 8);
		snake.emplace_back(16, 8);
		direction = Direction::DOWN;//如果方向为右整个蛇身会向上移动一行，向下则不会
	}
	void NormalMove();
	void InitSnake();
	bool GetFood(const Food&);
	bool GetFlashFood( Food&);
	bool ChangeDirection();
	void Eat();
	void HitSelf();//是否撞到自己
	bool Edge();//是否超越边界
	bool HitItself();
private:
	std::deque<Point>snake;
	Direction direction;

	friend class Food;//将Food类置为友元，以便访问其私有元素
};
#endif
