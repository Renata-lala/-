// лаба 1 выч мат.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>


    double PhiOtX(double x)
    {
    return (2- log(x));
    }

    double diff(double x)
    {
        const double h = 1e-10;
        return (-1/x);
    }
    
    
    double DDdiff(double x)
    {
        const double h = 1e-10;
        return (1 / pow(x,2));
    }

    
    int main()
{
    setlocale(LC_ALL, "Russian");

    using namespace std;
    double X1;
    double X2;
    double X1Last;
    double X2Last;
    double c; 
    
    double dx = 4;
    double eps = 0.001;
    double p = 0; 

    //поиск интервала и Метод дихотомии 
    double b = 10;
    double a = 1;
    while ((b - a) > 1) {
        c = (a + b) / 2;
        if (PhiOtX(c) == 0) cout << "корень = " << c;

        if ((PhiOtX(a) * PhiOtX(c)) > 0) b = c;
        else a = c;
    }
    X1 = a;
    X2 = b;
    
  
    
    cout << X1 << endl;
    cout << X2 << endl;
    cout << endl;
    
    cout << "X1Last    " << "X1       " << "dx      " << endl;
   
    //основной алгоритм
    while (dx > eps)
    {
        X1Last = X1;
        X1 = PhiOtX(X1Last);
        dx = abs(X1 - X1Last) / abs(X1);
        cout << X1Last << "  " << X1 << "  " << dx << endl;
    }

    cout << endl;
    cout << endl;
    cout << endl;
    
    dx = 5;
    cout << "X2Last    " << "X2   " << "dx   " << endl;
    while (dx > eps)
    {
        X2Last = X2;
        X2 = PhiOtX(X2Last);
        dx = abs(X2 - X2Last) / abs(X2);
        cout << X2Last << "  " << X2 << "  " << dx << endl;
    }

    //Условие сходимости 
    double Xuslovie;
    Xuslovie = X1;
    for (Xuslovie; Xuslovie < X2; Xuslovie = Xuslovie + 0.0001) {
        if ((PhiOtX(Xuslovie) < X2) || (PhiOtX(Xuslovie) > X1)) {
            for (double alfa = 0.0001; alfa < 0, 9999; alfa = 0.0001) {
                if (abs(PhiOtX(Xuslovie)) < alfa)  cout << "Условие для Альфа выполняется";
                else cout << "Условие для Альфа не выполняется";
            }
        }
        else cout << "Значения не пренадлежать промежцтку";
    }

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
