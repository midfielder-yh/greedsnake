#include<iostream>
#include"point.h"
#include<deque>
using namespace std;
class OpeningAnimation
{
public:
    OpeningAnimation() : speed(35) 
    {
        startsnake.emplace_back(Point(0, 14));//蛇身
        startsnake.emplace_back(Point(1, 14));//emplace_back相当于没有临时变量资源浪费的push_back
        startsnake.emplace_back(Point(2, 15));
        startsnake.emplace_back(Point(3, 16));
        startsnake.emplace_back(Point(4, 17));
        startsnake.emplace_back(Point(5, 18));
        startsnake.emplace_back(Point(6, 17));
        startsnake.emplace_back(Point(7, 16));
        startsnake.emplace_back(Point(8, 15));
        startsnake.emplace_back(Point(9, 14));
    }
    void PrintFirst();
    void PrintSecond();
    void PrintThird();
    void Action();
private:
    int speed;
    deque<Point>startsnake;
};