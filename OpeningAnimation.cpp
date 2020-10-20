#include"OpeningAnimation.h"
#include<Windows.h>
#include"windowdesign.h"
void OpeningAnimation::PrintFirst()//类的私有成员可以靠成员函数访问
{
    for (auto& point : startsnake)
    {
        point.Print();
        Sleep(speed);
    }
}
void OpeningAnimation::PrintSecond()//蛇从左向右移动的过程
{
    for (int i = 10,j=14; i != 40; ++i) //蛇头需要从10移动到40
    {
        /*计算蛇头的下一个位置，并将其压入startsnake中，绘制出来，将蛇尾去掉*/
        int x = i / 5; 
        if (x % 2 == 0)++j;
        else --j;
        startsnake.emplace_back(Point(i, j));
        startsnake.back().Print();//打印蛇头
        startsnake.front().Erase();//去掉蛇尾
        startsnake.pop_front();//弹出蛇尾
        Sleep(speed);
    }
}
void OpeningAnimation::PrintThird()
{
    while (!startsnake.empty()) {
        //如果蛇还没完全消失，继续弹出蛇尾 
            startsnake.front().Erase();
            startsnake.pop_front();
        Sleep(speed);
    }
}
void OpeningAnimation::Action()
{
    PrintFirst();
    PrintSecond();
    PrintThird();
    SetCursorPosition(20,30);
    //cout << "按任意键开始游戏";
}
