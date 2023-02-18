// ConsoleApplication3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

double FX(double x)
{
	return (x - (5*x + 8*log(x) - 8)/13);
}



double PhiOtX(double x)
{
	return (x - (5 * x + 8 * log(x) - 8) / 13);
}

double diff(double x)
{
	return (-1 / x);
}


bool uslovie(double a1, double b2) {
	while (a1 < b2) {
		const double peps = 0.01;
		a1 += peps; 
		if (abs(diff(a1)) >= 1) return false;

	}
	return true;
}

bool interval(double a1, double b1) {
	if ((FX(a1) * FX(b1)) < 0) return true;
	else 
	return false; 
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
	int count = 0;
	double eps = 0.1;
	double p = 0;

	//Интервал
	double A = 1;
	double B = 1.4;
	int i = 1;
	while (interval(A, B) != true) {
		A = A + 0.3;
		B = B + 0.3;
	}
	cout << "Начало отрезка = " << A << "      Конец отрезка=" << B;
	
	
	//// Метод дихотомии
	
	/*double b = 7;
	double a = -7;
	while ((b - a) > 0.00001) {
		c = (a + b) / 2;
		if (FX(c) == 0) cout << "корень = " << c;

		if ((FX(a) * FX(c)) < 0) b = c;
		else a = c;
		count++;
	}*/
	//cout << count;
	//cout << a << " " << b;
	
	

	//cout << "а =  " << a << "   b=  " << b;
	//cout << endl;

	
	
	//Условие сходимости
	if (uslovie(A, B) == true) {
		cout << "Условие сходимости выполняется";
	}

	//
	////cout << X1 << endl;
	//cout << X2 << endl;
	//cout << endl;

	//cout << "X1Last " << "X1 " << "dx " << endl;

	//основной алгоритм
	
	X1 = 10;
	while (dx > 0.01)
	{
		X1Last = X1;
		X1 = PhiOtX(X1Last);
		dx = (abs(X1 - X1Last) / abs(X1));
		cout << X1Last << " " <<  X1 << " " << dx << endl;
	}
	cout << endl;
	cout << X1;

	cout << endl;
	cout << endl;
	cout << endl;


	//int k;
	//k = 0; 
	//dx = 5;
	//cout << " кол-во итераций   погрешность";
	//cout << endl;
	//eps = 0.001;
	//	while (eps > 0.00000001) {
	//		eps = (eps / 10);
	//		while (dx > eps)
	//		{
	//			X1Last = X1;
	//			X1 = PhiOtX(X1Last);
	//			dx = abs(X1 - X1Last) / abs(X1);
	//			//cout << X1Last << " " << X1 << " " << dx << endl;
	//			k++;
	//		}
	//		cout << k << "                       " << eps;
	//		cout << endl;
	//	}
	
	/*double b = 7;
	double a = 1;
	count = 0;
	cout << " кол-во итераций   погрешность";
	cout << endl;
	while (eps > 0.00000001) {
		eps = (eps / 10);

		while ((b - a) > eps) {
			c = (a + b) / 2;
			if (FX(c) == 0) cout << "корень = " << c;

			if ((FX(a) * FX(c)) < 0) b = c;
			else a = c;
			count++;
		}
		cout << count << "                     " << eps;
		cout << endl;


	}*/
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
