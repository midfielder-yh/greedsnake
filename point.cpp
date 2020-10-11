#include"point.h"
#include"windowdesign.h"
#include<iostream>
using namespace std;
void Point::Print()//输出方块
{
    SetCursorPosition(x, y);
    cout << "■";
}
void Point::Erase()//擦除方块
{
    SetCursorPosition(x, y);
    cout << "  ";//注意这里是两个空格
}
void Point::PrintCircular()//输出圆形
{
    SetCursorPosition(x, y);
    std::cout << "●";
}
