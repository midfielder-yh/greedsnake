#include"point.h"
#include"windowdesign.h"
#include<iostream>
using namespace std;
void Point::Print()//�������
{
    SetCursorPosition(x, y);
    cout << "��";
}
void Point::Erase()//��������
{
    SetCursorPosition(x, y);
    cout << " ";
}
void Point::PrintCircular()//���Բ��
{
    SetCursorPosition(x, y);
    std::cout << "��";
}