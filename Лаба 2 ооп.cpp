#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <map>

using namespace std;

class SBase
{
public:
	virtual int Get() = 0;
};

class SKbrd : public SBase
{
private : 
	int l;
public :
	SKbrd() {
		l = 6;
	}
	int Get() 
	{
		if (cin.peek() == '\n') return -1; //смотрит на след символ в потоке
		int number;
		cin >> number;
		return number;
	};
};

//файлик 
class SFile : public SBase
{
	ifstream f;
public :
	SFile() {
		f.open("пр.txt");
	}
	~SFile() {
		f.close();
	}

	int Get() { 
		if (!f.eof() && (f.is_open())) {
			int numm;
			f >> numm;
			return numm; //eof проверяет на окончание файла
		}
		else {
			return -1;
		};
	};
};
//массивчик 

class SQueue : public SBase
{
	int* que, lenght, current;
public:
	SQueue(int leng)
	{ 
		current = 0;
		int* que = new int[leng];
		for (int i = 0; i < leng; i++) {
			que[i] = rand() % 100 + 1;
		}
		lenght = leng;
	}

	int Get() {
		for (int i = 0; i < lenght; i++) { //цикла не должно быть
			if (current < lenght) {
				return que[i];
				current++;
			}
			else { return -1; }
		}
	}
};

class Freq
{
public :
	map<int, int> counts;
	void Calc(SBase* pobj) {
		int sum = 0; 
		int temp = pobj->Get();
		
		while (temp != -1) {
			counts[temp]+=1;
			sum += temp;
			temp = pobj->Get();
		}
	}
		
	friend ostream& operator<<(ostream& stream, Freq& obj) {
		for (auto it = obj.counts.begin(); it != obj.counts.end(); it++) {
			stream << it->first << "  " << it->second << endl;

		}
		return stream;
	};
};

//
class Diap : public Freq {
	int min, max, count;
public:
	Diap() {
		min = 10000;
		max = 0; 
		count = 0;
	};
	void Calc(SBase* pobj) 
	{
		int temp = pobj->Get();

		while (temp != -1) {
			counts[temp] += 1;
			count += 1;
			if (temp > max) max = temp;
			if (temp < min) min = temp;
			temp = pobj->Get();
			}
		}
	friend ostream& operator<<(ostream& stream, Diap& obj) {
		stream << "Min: " << obj.min << endl; 
		stream << "Max: " << obj.max << "   " << "Count: " << obj.count << endl;
		return stream;

	};
		
};


int main()
{
	setlocale(LC_ALL, "Russian");

	srand(time(NULL));

	SKbrd proverochka1; //с клавы
	SFile proverochka2; // с файла
	SQueue proverochka3(15); //очередь 

	SBase* proverka = &proverochka1; 
	Diap skbrd;
	Diap sfile; 
	Diap squeue; 

	/*cout << "для SKbrd, то есть ввод с клавиатуры " << endl;
	skbrd.Calc(&proverochka1); 
	cout << skbrd << endl;

	cout << "для SFile, то есть ввод с файла " << endl;
	sfile.Calc(&proverochka2);
	cout << sfile << endl;*/

	
	/*cout << "для SQueu, то есть ввод с массива " << endl;
	squeue.Calc(&proverochka3); 
	cout << squeue  << endl;*/

	
	Freq sk;
	Freq sf;
	Freq sq;
	
	cout << "для sk, то есть ввод с клавиатуры " << endl;
	sk.Calc(&proverochka1);
	cout << sk << endl;

	cout << "для sf, то есть ввод с файла " << endl;
	sf.Calc(&proverochka2);
	cout << sf << endl;

	cout << "sq, то есть ввод с массива " << endl;
	sq.Calc(&proverochka3);
	cout << squeue << endl;
	
	

}