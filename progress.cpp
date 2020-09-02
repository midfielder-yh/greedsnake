#include"progress.h"
#include"openinganimation.h"
#include<iostream>
#include<conio.h>
#include"windowdesign.h"
#include"map.h"
#include<Windows.h>
#include<time.h>
//#include"food.h"
//#include"snake.h"
void Progress::Start()
{
    SetWindowSize(41, 32);
    SetColor(2);
    OpeningAnimation* start = new OpeningAnimation();//动态分配内存空间
    start->Action();
    delete start;//释放内存空间
}
void Progress::Select()
{
    //选择界面
    SetColor(3);
    SetCursorPosition(10, 10); cout << "请选择难度（上下移动,回车确定）：";
    SetCursorPosition(30, 11); SetBackColor(); cout << "普通难度";
    SetCursorPosition(30, 13); SetColor(3); cout << "中等难度";
    SetCursorPosition(30, 15); cout << "困难难度";
    SetCursorPosition(0, 31);
    
    int ch;//记录键入值
    key = 1;//记录选中项，初始选择第一个
    bool flag = false;//记录是否键入Enter键标记，初始置为否
    while ((ch = _getch()))
    {
        switch (ch) 
        {
        case 72://UP上方向键（不是ASCII是按键的扫描码）
            switch (key) 
            {
            case 1:
                SetCursorPosition(30, 11); SetBackColor(); cout << "普通难度"; break;
            case 2:
                SetCursorPosition(30, 11); SetBackColor(); cout << "普通难度";
                SetCursorPosition(30, 13); SetColor(3); cout << "中等难度"; key--; break;
            case 3:
                SetCursorPosition(30, 13); SetBackColor(); cout << "中等难度";
                SetCursorPosition(30, 15); SetColor(3); cout << "困难难度"; key--; break;
            }
            break;
        case 80://down
            switch (key)
            {
            case 1:
                
                SetCursorPosition(30, 13); SetBackColor(); cout << "中等难度";
                SetCursorPosition(30, 11); SetColor(3); cout << "普通难度"; key++; break;
            case 2:
                
                SetCursorPosition(30, 15); SetBackColor(); cout << "困难难度";
                SetCursorPosition(30, 13); SetColor(3); cout << "中等难度"; key++; break;
            case 3:
                SetCursorPosition(30, 15); SetBackColor(); cout << "困难难度"; break;
            }
            break;
        case 13://Enter回车键
            flag = true;
            break;
        default://无效按键
            break;
        }
        if (flag == true)break;
        SetCursorPosition(0, 31);//减少视觉影响
    }
    switch (key)//根据所选选项设置蛇的移动速度，speed值越小，速度越快
    {
    case 1:
        speed = 135;
        break;
    case 2:
        speed = 100;
        break;
    case 3:
        speed = 60;
        break;
    default:
        break;
    }
}
void Progress::DrawMap()
{
    system("cls");//清屏

    /*绘制地图*/
    SetColor(3);
    Map* init_map = new Map();
    init_map->PrintInitmap();
    delete init_map;
    /*绘制侧边栏*/
    SetColor(3);
    SetCursorPosition(33, 1);
    std::cout << "Greedy Snake";
    SetCursorPosition(34, 2);
    std::cout << "贪吃蛇";
    SetCursorPosition(31, 4);
    std::cout << "难度：";
    SetCursorPosition(36, 5);
    switch (key)
    {
    case 1:
        std::cout << "简单模式";
        break;
    case 2:
        std::cout << "普通模式";
        break;
    case 3:
        std::cout << "困难模式";
        break;
    default:
        break;
    }
    SetCursorPosition(31, 7);
    std::cout << "得分：";
    SetCursorPosition(37, 8);
    std::cout << "0";
    SetCursorPosition(33, 13);
    std::cout << " 方向键移动";
    SetCursorPosition(33, 15);
    std::cout << " ESC键暂停";
    SetCursorPosition(0, 31);
}
int Progress::Game()
{
    score = 0;
    
    Snake s;//非动态分配，自动释放空间，存栈
    srand((int)time(0));
    Food* initfood = new Food();
    s.InitSnake();
    initfood->DrawFood(s);
    while (s.Edge()&&s.HitItself())
    {
        Sleep(100);
        if (s.ChangeDirection()) {
            if (s.GetFood(*initfood))
            {
                s.Eat();
                score++;
                initfood->DrawFood(s);
                UpdateScore();
            }
            else s.NormalMove();
            if (s.GetFlashFood(*initfood))
            {
                s.Eat();  score += 5; UpdateScore();
            }
            if (initfood->GetF_flash())
            {
                initfood->Count();
            }
        }
        else {
            Menu();
        }
    }
    /*蛇死亡*/
    //delete snake;//释放分配的内存空间
    delete initfood;
    int tmp = GameOver();//绘制游戏结束界面，并返回所选项
    switch (tmp)
    {
    case 1:
        return 1;//重新开始
    case 2:
        return 2;//退出游戏
    default:
        return 2;
    }
}
void Progress::AllGame()
{
    Start();//开始界面
    while (true)//游戏可视为一个死循环，直到退出游戏时循环结束
    {
        Select();//选择界面
        DrawMap();//绘制游戏界面
        int tmp = Game();//开启游戏循环，当重新开始或退出游戏时，结束循环并返回值给tmp
        if (tmp == 1) //返回值为1时重新开始游戏
        {
            system("cls");
            continue;
        }
        else if (tmp == 2) //返回值为2时退出游戏
        {
            break;
        }
        else
        {
            break;
        }
    }
}
int Progress::Menu()
{
    /*绘制菜单*/
    SetColor(11);
    SetCursorPosition(32, 19);
    std::cout << "菜单：";
    Sleep(100);
    SetCursorPosition(34, 21);
    SetBackColor();
    std::cout << "继续游戏";
    Sleep(100);
    SetCursorPosition(34, 23);
    SetColor(11);
    std::cout << "重新开始";
    Sleep(100);
    SetCursorPosition(34, 25);
    std::cout << "退出游戏";
    SetCursorPosition(0, 31);
    int ch;//选择
    int tmp_key = 1;
    bool flag = false;
    while ((ch = _getch()))
    {
        switch (ch)
        {
        case 72://UP
            if (tmp_key > 1)
            {
                switch (tmp_key)
                {
                case 2:
                    SetCursorPosition(34, 21);
                    SetBackColor();
                    std::cout << "继续游戏";
                    SetCursorPosition(34, 23);
                    SetColor(11);
                    std::cout << "重新开始";

                    --tmp_key;
                    break;
                case 3:
                    SetCursorPosition(34, 23);
                    SetBackColor();
                    std::cout << "重新开始";
                    SetCursorPosition(34, 25);
                    SetColor(11);
                    std::cout << "退出游戏";

                    --tmp_key;
                    break;
                }
            }
            break;

        case 80://DOWN
            if (tmp_key < 3)
            {
                switch (tmp_key)
                {
                case 1:
                    SetCursorPosition(34, 23);
                    SetBackColor();
                    std::cout << "重新开始";
                    SetCursorPosition(34, 21);
                    SetColor(11);
                    std::cout << "继续游戏";

                    ++tmp_key;
                    break;
                case 2:
                    SetCursorPosition(34, 25);
                    SetBackColor();
                    std::cout << "退出游戏";
                    SetCursorPosition(34, 23);
                    SetColor(11);
                    std::cout << "重新开始";

                    ++tmp_key;
                    break;
                }
            }
            break;

        case 13://Enter
            flag = true;
            break;

        default:
            break;
        }

        if (flag)
        {
            break;
        }
        SetCursorPosition(0, 31);
    }

    if (tmp_key == 1) //选择继续游戏，则将菜单擦除
    {
        SetCursorPosition(32, 19);
        std::cout << "      ";
        SetCursorPosition(34, 21);
        std::cout << "        ";
        SetCursorPosition(34, 23);
        std::cout << "        ";
        SetCursorPosition(34, 25);
        std::cout << "        ";
    }
    return tmp_key;
}
void Progress::UpdateScore()
{
    SetCursorPosition(37, 8);
    SetColor(11);
    cout << score;
}
int Progress::GameOver()//游戏结束界面
{
    /*绘制游戏结束界面*/
    Sleep(500);
    SetColor(11);
    SetCursorPosition(10, 8);
    std::cout << "━━━━━━━━━━━━━━━━━━━━━━";
    Sleep(30);
    SetCursorPosition(9, 9);
    std::cout << " ┃               Game Over !!!              ┃";
    Sleep(30);
    SetCursorPosition(9, 10);
    std::cout << " ┃                                          ┃";
    Sleep(30);
    SetCursorPosition(9, 11);
    std::cout << " ┃              很遗憾！你挂了              ┃";
    Sleep(30);
    SetCursorPosition(9, 12);
    std::cout << " ┃                                          ┃";
    Sleep(30);
    SetCursorPosition(9, 13);
    std::cout << " ┃             你的分数为：                 ┃";
    SetCursorPosition(24, 13);
    std::cout << score;
    Sleep(30);
    SetCursorPosition(9, 14);
    std::cout << " ┃                                          ┃";
    Sleep(30);
    SetCursorPosition(9, 15);
    std::cout << " ┃   是否再来一局？                         ┃";
    Sleep(30);
    SetCursorPosition(9, 16);
    std::cout << " ┃                                          ┃";
    Sleep(30);
    SetCursorPosition(9, 17);
    std::cout << " ┃                                          ┃";
    Sleep(30);
    SetCursorPosition(9, 18);
    std::cout << " ┃    嗯，好的        不了，还是学习有意思  ┃";
    Sleep(30);
    SetCursorPosition(9, 19);
    std::cout << " ┃                                          ┃";
    Sleep(30);
    SetCursorPosition(9, 20);
    std::cout << " ┃                                          ┃";
    Sleep(30);
    SetCursorPosition(10, 21);
    std::cout << "━━━━━━━━━━━━━━━━━━━━━━";

    Sleep(100);
    SetCursorPosition(12, 18);
    SetBackColor();
    std::cout << "嗯，好的";
    SetCursorPosition(0, 31);

    /*选择部分*/
    int ch;
    int tmp_key = 1;
    bool flag = false;
    while ((ch = _getch()))
    {
        switch (ch)
        {
        case 75://LEFT
            if (tmp_key > 1)
            {
                SetCursorPosition(12, 18);
                SetBackColor();
                std::cout << "嗯，好的";
                SetCursorPosition(20, 18);
                SetColor(11);
                std::cout << "不了，还是学习有意思";
                --tmp_key;
            }
            break;

        case 77://RIGHT
            if (tmp_key < 2)
            {
                SetCursorPosition(20, 18);
                SetBackColor();
                std::cout << "不了，还是学习有意思";
                SetCursorPosition(12, 18);
                SetColor(11);
                std::cout << "嗯，好的";
                ++tmp_key;
            }
            break;

        case 13://Enter
            flag = true;
            break;

        default:
            break;
        }

        SetCursorPosition(0, 31);
        if (flag) {
            break;
        }
    }

    SetColor(11);
    switch (tmp_key)
    {
    case 1:
        return 1;//重新开始
    case 2:
        return 2;//退出游戏
    default:
        return 1;
    }
}

