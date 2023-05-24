// Эс лаба 2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <ctime>
#include <math.h>

using namespace std;

//50 205 50 - зелёный

class Color
{

private:
	int red, green, blue, num;


	static int fit(Color& A)//Color& A)
	{
		return (abs(50 - A.red) + abs(205 - A.green) + abs(50 - A.blue)); //чем меньше значение, тем больше подходит
	}
	static void shellSort(Color*& array, int n, int*& Arr)
	{
		int i, j, h;
		for (h = 1; h <= n / 9; h = h * 3 + 1);
		while (h >= 1) {
			for (i = h; i < n; i++)  //Сортировка всех цепочек с текущим шагом h
				for (j = i - h; j >= 0 && Arr[j] > Arr[j + h]; j -= h) {
					swap(array[j], array[j + h]);
					swap(Arr[j], Arr[j + h]);
				}

			h = (h - 1) / 3;
		}

	}
	static void TenToTwo(bool*& bit, int n)
	{
		int k = 7;
		while (k >= 0)
		{
			bit[k] = n % 2;
			n = n / 2;
			k -= 1;
		}
	}

	static int TwoToTen(bool*& bit)
	{
		int n = 0, count = 0;
		int k = 7;
		while (k >= 0) {
			n += bit[k] * pow(2, count);
			count += 1;
			k -= 1;
		}
		return n;
	}

	static void mutation(bool* bit)
	{
		double P = 0.125; //8^-1
		double randc;
		for (int i = 0; i < 8; i++)
		{
			randc = 0 + rand() % 1000;
			randc /= 1000;
			if (P > randc)
			{
				if (bit[i] == 0)
					bit[i] = 1;
				else bit[i] = 0;
			}
		}
	}
	static void crossingover(Color& parent1, Color& parent2, Color& child1, Color& child2)
	{
		int cut = 1 + rand() % 7; //номер, начиая с которого 2 половина
		bool* bit1;
		bool* bit2;
		bit1 = new bool[8];
		bit2 = new bool[8];
		TenToTwo(bit1, parent1.red);
		TenToTwo(bit2, parent2.red);
		for (int i = cut; i < 8; i++)
		{
			swap(bit1[i], bit2[i]);
		}
		mutation(bit1);
		mutation(bit2);
		child1.red = TwoToTen(bit1);
		child2.red = TwoToTen(bit2);

		TenToTwo(bit1, parent1.green);
		TenToTwo(bit2, parent2.green);
		for (int i = cut; i < 8; i++)
		{
			swap(bit1[i], bit2[i]);
		}
		mutation(bit1);
		mutation(bit2);
		child1.green = TwoToTen(bit1);
		child2.green = TwoToTen(bit2);

		TenToTwo(bit1, parent1.blue);
		TenToTwo(bit2, parent2.blue);
		for (int i = cut; i < 8; i++)
		{
			swap(bit1[i], bit2[i]);
		}
		mutation(bit1);
		mutation(bit2);
		child1.blue = TwoToTen(bit1);
		child2.blue = TwoToTen(bit2);
		delete[]bit1;
		delete[]bit2;
	}
public:
	Color();
	Color(int a);
	~Color();
	friend ostream& operator<<(ostream& stream, Color& p);
	static int fitness(Color*& A, int n, int*& Arr)
	{
		int oo = 0, coo = 0;

		for (int i = 0; i < n; i++)
		{
			Arr[i] = fit(A[i]);
			oo += Arr[i];
			coo++;
			if (Arr[i] == 0)
			{
				oo = oo / coo;
				cout << "среднее приближение " << oo << endl;
				return i;
			}
		}
		oo = oo / coo;
		cout << "среднее приближение " << oo << endl;
		return -1;
	}
	static int selection(Color*& array, int n, int*& Arr)
	{
		int l = n / 2;
		shellSort(array, n, Arr);
		return l;
	}
	static void breeding(Color*& parents, int n, int l)
	{
		Color* children;
		children = new Color[n];
		int k = 0, i = 0, j = 0;
		double P = 0.7;
		double randc;
		while (k < n)
		{
			randc = rand() % 10;
			randc /= 10;
			i = randc * l;
			j = i;
			while (j == i)
			{
				randc = rand() % 10;
				randc /= 10;
				j = randc * l;
			}
			randc = rand() % 10;
			randc /= 10;
			if (P > randc)
			{
				crossingover(parents[i], parents[j], children[k], children[k + 1]);
				k = k + 2;
			}
			else
			{
				children[k] = parents[i];
				children[k + 1] = parents[j];
				k = k + 2;
			}

		}
		for (int i = 0; i < n; i++)
		{
			parents[i] = children[i];

		}
		delete[]children;
	}

	//ostream& operator<<(ostream& stream)
	//{
	//	stream << "red: " << red << ", green:" << green << ", blue:" << blue << endl;
	//	return stream;		// возврат потока
	//}

};

Color::Color()
{
	red = rand() % 255;
	green = rand() % 255;
	blue = rand() % 255;
}
Color::Color(int a)
{
	red = 0;
	green = 0;
	blue = 0;
}

Color::~Color()
{
}

ostream& operator<<(ostream& stream, Color& p)
{
	stream << "red: " << p.red << ", green: " << p.green << ", blue: " << p.blue << endl;
	return stream;		// возврат потока
}


int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(0));
	int n = 100, l;
	int flag = -1, generation = 1;
	Color* population;

	//вывод популяции
	population = new Color[n];
	int* Arr;
	Arr = new int[n];
	cout << "generation " << generation << endl;
	while (flag == -1)
	{
		flag = Color::fitness(population, n, Arr);
		if (flag != -1)
		{

			cout << "Искомое значение номер " << flag << " generation " << generation << endl;
			cout << population[flag];
			break;
		}
		l = Color::selection(population, n, Arr);
		Color::breeding(population, n, l);
		generation++;
		cout << "generation " << generation << endl;
	}
	delete[]population;
	delete[]Arr;
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
