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
    OpeningAnimation* start = new OpeningAnimation();//��̬�����ڴ�ռ�
    start->Action();
    delete start;//�ͷ��ڴ�ռ�
}
void Progress::Select()
{
    //ѡ�����
    SetColor(3);
    SetCursorPosition(10, 10); cout << "��ѡ���Ѷȣ������ƶ�,�س�ȷ������";
    SetCursorPosition(30, 11); SetBackColor(); cout << "��ͨ�Ѷ�";
    SetCursorPosition(30, 13); SetColor(3); cout << "�е��Ѷ�";
    SetCursorPosition(30, 15); cout << "�����Ѷ�";
    SetCursorPosition(0, 31);
    
    int ch;//��¼����ֵ
    key = 1;//��¼ѡ�����ʼѡ���һ��
    bool flag = false;//��¼�Ƿ����Enter����ǣ���ʼ��Ϊ��
    while ((ch = _getch()))
    {
        switch (ch) 
        {
        case 72://UP�Ϸ����������ASCII�ǰ�����ɨ���룩
            switch (key) 
            {
            case 1:
                SetCursorPosition(30, 11); SetBackColor(); cout << "��ͨ�Ѷ�"; break;
            case 2:
                SetCursorPosition(30, 11); SetBackColor(); cout << "��ͨ�Ѷ�";
                SetCursorPosition(30, 13); SetColor(3); cout << "�е��Ѷ�"; key--; break;
            case 3:
                SetCursorPosition(30, 13); SetBackColor(); cout << "�е��Ѷ�";
                SetCursorPosition(30, 15); SetColor(3); cout << "�����Ѷ�"; key--; break;
            }
            break;
        case 80://down
            switch (key)
            {
            case 1:
                
                SetCursorPosition(30, 13); SetBackColor(); cout << "�е��Ѷ�";
                SetCursorPosition(30, 11); SetColor(3); cout << "��ͨ�Ѷ�"; key++; break;
            case 2:
                
                SetCursorPosition(30, 15); SetBackColor(); cout << "�����Ѷ�";
                SetCursorPosition(30, 13); SetColor(3); cout << "�е��Ѷ�"; key++; break;
            case 3:
                SetCursorPosition(30, 15); SetBackColor(); cout << "�����Ѷ�"; break;
            }
            break;
        case 13://Enter�س���
            flag = true;
            break;
        default://��Ч����
            break;
        }
        if (flag == true)break;
        SetCursorPosition(0, 31);//�����Ӿ�Ӱ��
    }
    switch (key)//������ѡѡ�������ߵ��ƶ��ٶȣ�speedֵԽС���ٶ�Խ��
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
    system("cls");//����

    /*���Ƶ�ͼ*/
    SetColor(3);
    Map* init_map = new Map();
    init_map->PrintInitmap();
    delete init_map;
    /*���Ʋ����*/
    SetColor(3);
    SetCursorPosition(33, 1);
    std::cout << "Greedy Snake";
    SetCursorPosition(34, 2);
    std::cout << "̰����";
    SetCursorPosition(31, 4);
    std::cout << "�Ѷȣ�";
    SetCursorPosition(36, 5);
    switch (key)
    {
    case 1:
        std::cout << "��ģʽ";
        break;
    case 2:
        std::cout << "��ͨģʽ";
        break;
    case 3:
        std::cout << "����ģʽ";
        break;
    default:
        break;
    }
    SetCursorPosition(31, 7);
    std::cout << "�÷֣�";
    SetCursorPosition(37, 8);
    std::cout << "0";
    SetCursorPosition(33, 13);
    std::cout << " ������ƶ�";
    SetCursorPosition(33, 15);
    std::cout << " ESC����ͣ";
    SetCursorPosition(0, 31);
}
int Progress::Game()
{
    score = 0;
    
    Snake s;//�Ƕ�̬���䣬�Զ��ͷſռ䣬��ջ
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
    /*������*/
    //delete snake;//�ͷŷ�����ڴ�ռ�
    delete initfood;
    int tmp = GameOver();//������Ϸ�������棬��������ѡ��
    switch (tmp)
    {
    case 1:
        return 1;//���¿�ʼ
    case 2:
        return 2;//�˳���Ϸ
    default:
        return 2;
    }
}
void Progress::AllGame()
{
    Start();//��ʼ����
    while (true)//��Ϸ����Ϊһ����ѭ����ֱ���˳���Ϸʱѭ������
    {
        Select();//ѡ�����
        DrawMap();//������Ϸ����
        int tmp = Game();//������Ϸѭ���������¿�ʼ���˳���Ϸʱ������ѭ��������ֵ��tmp
        if (tmp == 1) //����ֵΪ1ʱ���¿�ʼ��Ϸ
        {
            system("cls");
            continue;
        }
        else if (tmp == 2) //����ֵΪ2ʱ�˳���Ϸ
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
    /*���Ʋ˵�*/
    SetColor(11);
    SetCursorPosition(32, 19);
    std::cout << "�˵���";
    Sleep(100);
    SetCursorPosition(34, 21);
    SetBackColor();
    std::cout << "������Ϸ";
    Sleep(100);
    SetCursorPosition(34, 23);
    SetColor(11);
    std::cout << "���¿�ʼ";
    Sleep(100);
    SetCursorPosition(34, 25);
    std::cout << "�˳���Ϸ";
    SetCursorPosition(0, 31);
    int ch;//ѡ��
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
                    std::cout << "������Ϸ";
                    SetCursorPosition(34, 23);
                    SetColor(11);
                    std::cout << "���¿�ʼ";

                    --tmp_key;
                    break;
                case 3:
                    SetCursorPosition(34, 23);
                    SetBackColor();
                    std::cout << "���¿�ʼ";
                    SetCursorPosition(34, 25);
                    SetColor(11);
                    std::cout << "�˳���Ϸ";

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
                    std::cout << "���¿�ʼ";
                    SetCursorPosition(34, 21);
                    SetColor(11);
                    std::cout << "������Ϸ";

                    ++tmp_key;
                    break;
                case 2:
                    SetCursorPosition(34, 25);
                    SetBackColor();
                    std::cout << "�˳���Ϸ";
                    SetCursorPosition(34, 23);
                    SetColor(11);
                    std::cout << "���¿�ʼ";

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

    if (tmp_key == 1) //ѡ�������Ϸ���򽫲˵�����
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
int Progress::GameOver()//��Ϸ��������
{
    /*������Ϸ��������*/
    Sleep(500);
    SetColor(11);
    SetCursorPosition(10, 8);
    std::cout << "��������������������������������������������";
    Sleep(30);
    SetCursorPosition(9, 9);
    std::cout << " ��               Game Over !!!              ��";
    Sleep(30);
    SetCursorPosition(9, 10);
    std::cout << " ��                                          ��";
    Sleep(30);
    SetCursorPosition(9, 11);
    std::cout << " ��              ���ź��������              ��";
    Sleep(30);
    SetCursorPosition(9, 12);
    std::cout << " ��                                          ��";
    Sleep(30);
    SetCursorPosition(9, 13);
    std::cout << " ��             ��ķ���Ϊ��                 ��";
    SetCursorPosition(24, 13);
    std::cout << score;
    Sleep(30);
    SetCursorPosition(9, 14);
    std::cout << " ��                                          ��";
    Sleep(30);
    SetCursorPosition(9, 15);
    std::cout << " ��   �Ƿ�����һ�֣�                         ��";
    Sleep(30);
    SetCursorPosition(9, 16);
    std::cout << " ��                                          ��";
    Sleep(30);
    SetCursorPosition(9, 17);
    std::cout << " ��                                          ��";
    Sleep(30);
    SetCursorPosition(9, 18);
    std::cout << " ��    �ţ��õ�        ���ˣ�����ѧϰ����˼  ��";
    Sleep(30);
    SetCursorPosition(9, 19);
    std::cout << " ��                                          ��";
    Sleep(30);
    SetCursorPosition(9, 20);
    std::cout << " ��                                          ��";
    Sleep(30);
    SetCursorPosition(10, 21);
    std::cout << "��������������������������������������������";

    Sleep(100);
    SetCursorPosition(12, 18);
    SetBackColor();
    std::cout << "�ţ��õ�";
    SetCursorPosition(0, 31);

    /*ѡ�񲿷�*/
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
                std::cout << "�ţ��õ�";
                SetCursorPosition(20, 18);
                SetColor(11);
                std::cout << "���ˣ�����ѧϰ����˼";
                --tmp_key;
            }
            break;

        case 77://RIGHT
            if (tmp_key < 2)
            {
                SetCursorPosition(20, 18);
                SetBackColor();
                std::cout << "���ˣ�����ѧϰ����˼";
                SetCursorPosition(12, 18);
                SetColor(11);
                std::cout << "�ţ��õ�";
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
        return 1;//���¿�ʼ
    case 2:
        return 2;//�˳���Ϸ
    default:
        return 1;
    }
}

