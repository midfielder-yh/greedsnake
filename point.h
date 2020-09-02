#ifndef POINT_H
#define POINT_H
class Point
{
public:
	Point() {}//Ĭ�Ϲ��캯��
	Point(const int x, const int y) : x(x), y(y) {}//���캯��
	void Print();
	void Erase();
	void PrintCircular();
	int GetX() { return this->x; }
	int GetY() { return this->y; }
private :
	int x, y;
};
#endif // POINT_H