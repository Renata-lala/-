// выч мат 6 лаба.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <math.h>
#include <cstdio>

using namespace std;




int main()
{ 
    setlocale(LC_ALL, "Russian");
    const int n  = 4;
    const int m = 4;
    long double matrix[n][m];
    matrix[0][0] = 10;
    matrix[0][1] = 1;
    matrix[0][2] = -0.5; 
    matrix[0][3] = 0.7;
    matrix[1][0] = 1;
    matrix[1][1] = 15;
    matrix[1][2] = 0.5;
    matrix[1][3] = 4;
    matrix[2][0] = -0.5;
    matrix[2][1] = 0.5;
    matrix[2][2] = 20;
    matrix[2][3] = 1;
    matrix[3][0] = 0.7;
    matrix[3][1] = 4;
    matrix[3][2] = 1;
    matrix[3][3] = 17;

    long double mB[m];
    mB[0] = 11.2;
    mB[1] = 20.5; 
    mB[2] = 21;
    mB[3] = 22.7;
 



   // float matrix1[n][m]; 
   // float matrix2[n][m]; 
   // float matrixCC[n][m];
   long double matrixT[n][m];

   //проверка на симметричность 
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != n && matrix[i][j] != matrix[i][j])
                flag = 1;
        }
    }
    if (flag == 1)
        cout << "массив не симетричен" << endl;
    else
        cout << "массив симетричен" << endl;

    //проверка на элеменеиы по главной диагонали  
     flag = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((i != n) && ( i != j) && (matrix[i][i] > matrix[i][j]))
                flag = 1;
        }
    }
    if (flag == 1)
        cout << "На диагонали находятся элементы сущетсвенно бьльше остальных" << endl;
    else
        cout << "На диагонали есть элементы меньше остальных" << endl ;




        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++) {
                cout << matrix[i][j] << "  ";
            }
            cout << endl;
        }
        cout << endl;


        matrixT[0][0] = sqrt(matrix[0][0]);
        long double t11 = sqrt(matrix[0][0]);
        long double t22 = 0;
        long double t12 = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i ==0 ) {
                    matrixT[0][j] = (matrix[0][j] / t11);
                }
                if ((i == j) && (i != 0)) {
                    for (int k = 0; k < i - 1; k++) {
                        t22 += pow(matrixT[k][j], 2);
                    }
                    matrixT[i][j] = sqrt(matrix[i][j] - t22);
                    t22 = 0;
                }
                else {
                    for (int k = 0; k < i - 1; k++) {
                        t12 += (matrix[k][i] * matrix[k][j]);
                    }
                    matrixT[i][j] = ((matrix[i][j] - t12) / matrixT[i][i]);
                    t12 = 0;
                }
                if (i > j) matrixT[i][j] = 0;

            }
        }

        cout << "____________" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << matrixT[i][j] << " ";
            }
            cout << endl;
        }

        flag = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (pow(matrixT[i][j],2) >0 )
                    flag = 1;
            }
        }
        if (flag == 1)
            cout << "Коэффиценты матрицы Т действительны" << endl;
        else
            cout << "Коэффиценты матрицы Т не действительны" << endl;

        cout << "matrixT :" << endl;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++) { cout << matrixT[i][j] << "  ";}
            cout << endl;
        }
        cout << endl;
        cout << endl;
        cout << "транспонированая  матрица с тэшками";
        cout << endl;
        //транспонирование матрицы 

        long double transporMAT[n][n];
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++) {transporMAT[i][j] = matrixT[j][i]; }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++) { cout << transporMAT[i][j] << "  "; }
            cout << endl;
        }


        long double y[n];
        y[0] = 0;
        y[1] = 0;
        y[2] = 0;
        y[3] = 0;

        long double x[n];
        x[0] = 0;
        x[1] = 0; 
        x[2] = 0;
        x[3] = 0;
        double temp = 0;
        
        
        //решение для y
        y[0] = (mB[0] / transporMAT[0][0]);
        for (int i = 1; i < n; i++) {
            for (int k = 0; k < i - 1; k++) {
                temp += (transporMAT[k][i] * y[k]);
                        }
            y[i] = ((mB[i] - temp) / transporMAT[i][i]);
            temp = 0;
        }
        cout << "YYY" << endl;
        for (int i = 0; i < n; i++) {
            cout << y[i] << endl;
        }
        cout << endl;

        //решение для x
        x[n-1] = (y[n-1] / matrixT[n-1][n-1]);
        for (int i = 0; i < n ; i++) {
            for (int k = i+1; k < n; k++) {
                temp += (matrixT[i][k] * x[k]);
                }
                x[i] = ((y[i] - temp) / matrixT[i][i]);
            temp = 0;
        }
        cout << endl;
        cout << "XXX" << endl;
        for (int i = 0; i < n; i++) {
            cout << x[i] << endl;
        }
        
        long double bbb[n];
        for (int i = 0; i < n; i++) {
             bbb[i] = 0;
        }
       
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                bbb[i] += matrix[i][j] * x[j];
            }
        }
        cout << endl; 
        cout << endl;
        cout << "Проверка ответа" << endl;
        cout << "bbb" << endl; 
        for (int i = 0; i < n; i++) {
            cout << bbb[i] << endl;
        }



    cout << "Сходиость простой иетрации " << endl; 
    long double A[n][m];
    A[0][0] = 2;
    A[0][1] = 1;
    A[0][2] = 0.3;
    A[1][0] = 0.001; 
    A[1][1] = -9;
    A[1][2] = 0; 
    A[2][0] = 6; 
    A[2][1] = 1; 
    A[2][2] = 1;

    long double a[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j] = 0;
      
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i != j) {
                a[i][j] = (-(A[i][j] / A[i][i]));
            }
        }
    }

    cout << "____________" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
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
