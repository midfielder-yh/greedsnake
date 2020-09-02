#include"OpeningAnimation.h"
#include<Windows.h>
#include"windowdesign.h"
void OpeningAnimation::PrintFirst()//���˽�г�Ա���Կ���Ա��������
{
    for (auto& point : startsnake)
    {
        point.Print();
        Sleep(speed);
    }
}
void OpeningAnimation::PrintSecond()//�ߴ��������ƶ��Ĺ���
{
    for (int i = 10,j=14; i != 40; ++i) //��ͷ��Ҫ��10�ƶ���40
    {
        /*������ͷ����һ��λ�ã�������ѹ��startsnake�У����Ƴ���������βȥ��*/
        int x = i / 5; 
        if (x % 2 == 0)++j;
        else --j;
        startsnake.emplace_back(Point(i, j));
        startsnake.back().Print();//��ӡ��ͷ
        startsnake.front().Erase();//ȥ����β
        startsnake.pop_front();//������β
        Sleep(speed);
    }
}
void OpeningAnimation::PrintThird()
{
    while (!startsnake.empty()) {
        if (!startsnake.empty()) //����߻�û��ʧ�������ƶ�
        {
            startsnake.front().Erase();
            startsnake.pop_front();
        }
        Sleep(speed);
    }
}
void OpeningAnimation::Action()
{
    PrintFirst();
    PrintSecond();
    PrintThird();
    SetCursorPosition(20,30);
    //cout << "���������ʼ��Ϸ";
}