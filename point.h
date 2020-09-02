#ifndef POINT_H
#define POINT_H
class Point
{
public:
	Point() {}//默认构造函数
	Point(const int x, const int y) : x(x), y(y) {}//构造函数
	void Print();
	void Erase();
	void PrintCircular();
	int GetX() { return this->x; }
	int GetY() { return this->y; }
private :
	int x, y;
};
#endif // POINT_H