// Алгоритмы хэш таблицы.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <ctime>
#include<string.h>
const int m = 15;
using namespace std;
const int qq = 15;
//class String {
//public:
//    char* p;
//    int len;
//    String(int LL) {
//        len = LL;
//        p = new char[LL + 1];
//        for (int i = 0; i < LL; i++) {
//            p[i] = 'a' + rand() % 26;
//        }
//        p[LL] = '\0';
//
//    }
//    int getLength() {
//        int length = 1; 
//        int i = 0;
//        while (this->p[i] != '\0') {
//            length += 1; 
//            i++;
//        }
//        return length; 
//     }
//  /*  char* operator [] (int i) { return p[i];  }
//    const char* operator[] (const int i) const { return p[i]; }*/
//
//    friend ostream& operator<< (ostream& stream, String& arr);
//
//};
//
//ostream& operator<< (ostream& stream, String& obj) {
//    int len = obj.getLength();
//    for (int i = 0; i < len+1; i++) {
//        stream << obj.p[i];
//    }
//    return stream;
//}

class HashTable {
public:
    char** table;
    int q;
    int r;
    int s;

    HashTable() {
        q =977 ;
        table = new char* [q];
        r = q / 2;
        s = 100;

        for (int i = 0; i < q; i++) { table[i] = 0; }
    }

    int Hash_function(const char* LL, int len) {
        int Fx = 0;
        for (int i = 0; i < len; i++) {
            Fx = (31 * Fx + LL[i]) % q;
        }
        return Fx;
    }
    int  Duble_hash_function(int fx) {
        int shag = (fx % r) + s;
        return shag;
    }
    int getLength(const char* LL) {
        int length = 1;
        int i = 0;
        while (LL[i] != '\0') {
            length += 1;
            i++;
        }
        return length;
    }
    int Add(char* LL) {
        int length = getLength(LL);
        int Fx = Hash_function(LL, length);
        int count_srav = 0; 
        //if (find_str(LL) == 1) {}
        //else {
            if (!table[Fx]) { table[Fx] = LL; }
            if (table[Fx]) {
                int shag = Duble_hash_function(Fx);
                while (1) {
                    if (table[Fx] == 0) { table[Fx] = LL; break; }
                    count_srav += 1;
                    if (strcmp(table[Fx], LL) == 0) {break; }
                    Fx = (Fx + shag) % q;
                }
            //}
        }
        return count_srav;

    }
    char* operator [] (int i)
    {
        return table[i];

    }
    int find_str(const char* SS) {
        int length = getLength(SS);
        int k = Hash_function(SS, length);
        int ShagFind = Duble_hash_function(k);
        int CountProhodov = 0;
        int CountSravneniy = 1;
        if (table[k] == 0) { return 0; } //пока строки нет
        else if ((strcmp(table[k], SS) == 0)) { return 1; } //сразу же нашли нужную  строку

        else {

            for (CountProhodov = 1; CountProhodov <= q; CountProhodov += 1) {
                if (((table[(k + ShagFind) % q]) == 0) || ((strcmp(table[(k + ShagFind) % q], SS) == 0))) {
                    return 1;
                    //break;
                }
                ShagFind = CountProhodov * ShagFind;
                CountSravneniy += 1;
            }
            return 0;
        }
    }
    //    while ((CountProhodov <= q && (table[(k + ShagFind) % q]) != 0) && ((strcmp(table[(k + ShagFind) % q], SS) != 0))) {
    //        CountProhodov += 1;
    //        ShagFind = CountProhodov * ShagFind;
    //        CountSravneniy += 1;
    //        //cout << "adr = " << int(table[k + ShagFind%q]) << endl;
    //    }
    //    if ((CountProhodov > q || (table[k + ShagFind % q]) == 0)) { return 0; }
    //    else {
    //        return 1;
    //    }
    //}
    int  count_unique_rows() {
        int count_unique = 0; 
        for (int i = 0; i < q; i++) {
            if (table[i] != 0) { count_unique += 1;  }
        }
        return count_unique; 
    }


   friend ostream& operator<< (ostream& stream, HashTable& arr);
};
ostream& operator<< (ostream& stream, HashTable& table) {
    for (int i = 0; i < table.q; i++) {
        //cout << "table[" << i << "] = " << int(table[i]) << endl;
        if (!table[i]) { stream << "\"\" "; }
        else {
            stream << "\"" << table[i] << "\" ";
        }
    }
    return stream;
}

//int main()
//{ 
//    setlocale(LC_CTYPE, "rus");
//    HashTable tab(); 
//    char kt[] = "Renata";
//    float middle_count_srav;
//    middle_count_srav += tab.Add(kt);
//    cout << "Срдение число сравнений строк: " << middle_count_srav / n << endl;
//    cout << "число уникальных строк : ";
//    cout << tab.count_unique_rows();
//}


int main()
{ 
    int n = 500;
    setlocale(LC_CTYPE, "rus");
    //HashTable t(); 
    int  Randomdlina;
    char** arr_p = new char* [n]; 
    cout << "Исходные строки" << endl;
    HashTable tab;
    //cout << tab << endl;
    float middle_count_srav = 0;
    for (int i = 0; i < n; i++) {
        Randomdlina = n + rand() % (m - n + 1);

        arr_p[i] = new char[Randomdlina + 1];
        //char* p = new char[Randomdlina + 1];
        for (int j = 0; j <= Randomdlina; j++) {
            arr_p[i][j] = 'a' + rand() % 26;
            //p[j] = arr_p[i][j];
            //cout << arr_p[i][j];
        }
        //p[Randomdlina] = '\0';
        arr_p[i][Randomdlina] = '\0';
        //cout << arr_p[i] << endl;
        middle_count_srav += tab.Add(arr_p[i]);
    }

    cout << "Срдение число сравнений строк: " << middle_count_srav/n << endl;
    cout << "----------------------------" << endl;
    
    const char* PPP = "Renata";
    //PPP = PP;
    //проверям есть ли похожа строка
    if (tab.find_str(PPP) == 0) { cout << "Такой же строки не нашлось" << endl; }
    else {
        cout << "Такая строка уже есть" << endl;
    }
    char st[] = "Renata";
    middle_count_srav += tab.Add(st);
    cout << "A" << endl;
    //cout << tab << endl;
    cout << "B" << endl;
    
    
    if (tab.find_str(PPP) == 0) { cout << "Такой же строки не нашлось" << endl; }
    else {
        cout << "Такая строка уже есть" << endl;
    }
    
    char kt[] = "Renata";
    middle_count_srav += tab.Add(kt);
    n = 17;
    cout << "Срдение число сравнений строк: " << middle_count_srav / n << endl;
    cout << "число уникальных строк : ";
    cout << tab.count_unique_rows();
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
