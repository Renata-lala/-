#include <fstream>
#include <iostream>

using namespace std;

static string questions[5] = { "Вам нужен ПК для 1.досуга или 2.работы?", "Вам нужен ПК для: 1.Офиса, 2.Программирования, 3.Работы с графическими редакторами, 4.Работы со звуковыми редакторами?", "Вам нужен ПК для: 1.Игр, 2.Домашнего использования?", "Вам нужен ПК для: 1.Для менее требовательных игр (Minecraft, Volarant, Dota 2, The witcher, Genshin Impact) 2.Для очень требовательных игр(Cyberpunk 2077, Atomic Heart, The Last of Us)", "На какую сумму вы рассчитываете?(Введите только число тысяч)"};
static string name[1] = { "game.txt" };
static ifstream file;
static string nprice[3] = { "Price0+", "Price30+", "Price50+" };

class Conf
{
    string buff;
public:
    int price, /*<30; 30-50; 50+*/ purpoce, /*Игровой, домашний, офис, прога, графика, звуки*/ power /*менее мощный, более мощный*/;
    Conf ()//ПК по умолчанию
    {
        price = 3;
        purpoce = 1;
        power = 2;

    }

    ~Conf()
    {
        file.close();
    }

    void Srav(int c)
    {
        
        if (c <= 30)
        {
            price = 1;
        }
        else if (c <= 50)
        {
            price = 2;
        }
        else
        {
            price = 3;

        }
    }

    void OpenFile(int purpoce)
    {
        purpoce--;
        file.open(name[purpoce]);
        
    }
    void SearchPower(int power)
    {
        string search[2] = { "less", "more" };
       // string buff;

        file >> buff;
        power--;
        while (buff != search[power])
        {
            file >> buff;
        }
    }
      
    void SearchPrice(int c)
    {
        Srav(c);
        if (price == 1)
        {
            while ((buff != nprice[0]) && (buff != nprice[1]) && (buff != nprice[2]))
            {
                file >> buff;
            }
        };
        if (price == 2)
        {
            while ((buff != nprice[1]) && (buff != nprice[2]))
            {
                file >> buff;
            }
        };
        if (price == 3)
        {
            while  (buff != nprice[2])
            {
                file >> buff;
            }
        };
        file >> buff;
        while (buff != "blockend")
        {   cout << buff<<" ";
            file >> buff;
            

        };
        cout << endl;
    
    }


};

int main()
{
    setlocale(LC_ALL, "Russian");
    Conf a;
    int buff;
    cout << questions[0]<<endl;
    cin >> buff;
    if (buff == 1)
        cout << questions[2]<<endl;
    cin >> buff;
    if (buff == 1)
    {
        a.OpenFile(1);
    }
    cout << questions[3]<<endl;
    cin >> buff;
    a.SearchPower(buff);
    cout << questions[4]<<endl;
    cin >> buff;
    a.SearchPrice(buff);


}

