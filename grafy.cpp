// графы.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <ctime>
#include <math.h>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

class point {
public:
    double x; 
    double y; 
    int index; //добавить метод дистанция
    point() {
        x = -10 + rand() % 20;
        y = -10 + rand() % 20;
        index = 0;
    }
    static double distance(point p1, point p2) {
        double weight = sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
        //cout << "A: x=" << p1.x << " y= " << p1.y << endl;
        //cout << "B: x=" << p2.x << " y= " << p2.y << endl;
        //cout <<" weight from A before B: " << weight << endl;
        return weight;
    }
};
class edge{
public:
    int indexA, indexB; //вместо координат индексы вершин
    double weight;
    edge() {
        indexA = 0;
        indexB = 0;
        weight = 0;
    }
    edge(int ia, int ib, double we){
        indexA = ia;
        indexB = ib;
        weight = we;

    }
    bool operator < (const edge& other) const {
        return weight < other.weight;
    }
    friend ostream& operator<< (ostream& stream, edge& obj);
};
ostream& operator<< (ostream& stream, edge& obj){
    stream << "A " << obj.indexA << " B " << obj.indexB << " weight " << obj.weight << endl;
    return stream; 
}


class Graph {
public:
    int vnum;
    vector<point> vec; 
    double * MatrixWeight;
   //double ** MatrixOstova;
    Graph(int n) {
        vnum = n;
        vec.reserve(n);
        cout << " x  ;  y " << endl;
        MatrixWeight = new double [vnum,vnum];
        for (int i = 0; i < vnum; i++) {
            point a;
            a.index = i;
            vec.push_back(a);
            //MatrixWeight[i] = new double[vnum];
        }
         for (int i = 0; i < vnum; i++) {
                for (int j = 0; j < vnum; j++) {
                    MatrixWeight[i,j] = point::distance(vec[i], vec[j]);
                    cout << MatrixWeight[i, j] << "|";
                }
                cout << endl;
          }
    }
    point getPoint(int n) {
        return vec[n];
    }


    vector<edge> AlgoritmPrima() {
        vector<edge> minostova;
        int* B = new int[vnum];
        int wm;
        double wmin;
        B[0] = -1;
        for (int i = 1; i < vnum; i++) { B[i] = 0; }
        for (int i = 1; i < vnum; i++) {
            wmin = 100000; wm = 0;
            for (int j = 1; j < vnum; j++)
                if (B[j] != -1 && wmin > MatrixWeight[j,B[j]]) {
                    wmin = MatrixWeight[j,B[j]]; wm = j;
                }
            
            minostova.push_back(edge(wm,B[wm], point::distance(vec[wm],vec[B[wm]])));
            B[wm] = -1;
            for (int j = 1; j < vnum; j++)  //проверяем не является ли вершина вм для остальных вершин более близкой
                if (B[j] != -1 && MatrixWeight[j,wm] < MatrixWeight[j,B[j]])
                    B[j] = wm;
            
        }
        return minostova;
    }
    void dfs(int vm, vector <int> & visited, vector<int>& component, int** MatrixSmegnosti) {
        visited[vm] = 1;
        component.push_back(vm);

        for (int i = 0; i < vnum; ++i) {
            if (visited[i] == 0 && MatrixSmegnosti[vm][i] != 0) {
                dfs(i, visited, component, MatrixSmegnosti);
            }
        }
    }
};


int main()
{
    using namespace std; 
    setlocale(LC_CTYPE, "rus");
    int N, K;
    cout << "Число точек: "; 
    cin >> N;
    cout << "Число кластеров: ";
    cin >> K;
    srand(time(0));

    // Генерируем N случайных точек.
    Graph graph(N);
    vector<edge> MinOs = graph.AlgoritmPrima(); 

    sort(MinOs.begin(), MinOs.end());
    MinOs.erase(MinOs.end() - 1);
   // MinOs.erase(MinOs.begin() + N - K, MinOs.end());
    int** MatrixSmegnosti = new int* [N]; 
    for (int i = 0; i < N; i++) {
        MatrixSmegnosti[i] = new int[N];
        for (int j = 0; j < N; j++){
            MatrixSmegnosti[i][j] = 0;
        //cout << MatrixSmegnosti[i][j] << " ";
        }
        //cout << endl;
    }
    for (int i = 0; i < N - K; i++) {
        MatrixSmegnosti[MinOs[i].indexA][MinOs[i].indexB] = 1;
        MatrixSmegnosti[MinOs[i].indexB][MinOs[i].indexA] = 1;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << MatrixSmegnosti[i][j] << " ";
        }
        cout << endl;
    }
    vector<vector<int>> componentS;
    vector<int> visited(N, 0);
    //for (int i = 0; i < N; i++) {
    //    visited[i] = 0;
    //}
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            vector<int> component;
            graph.dfs(i, visited, component, MatrixSmegnosti);
            componentS.push_back(component);
        }
    }
    /*для каждой компоненты подсчитать и
    вывести число вершин, а также минимальные и максимальные
    значения координат вершин и координаты центроида.*/
    //int size1 = componentS.size();
    //cout << size1; 
    for (int i = 0; i < K; i++) {
        double xsum = 0;
        double ysum = 0;
        double minx = 1000;
        double miny = 1000;
        double maxx = -1000;
        double maxy = -1000;
        double centoidaPoX = 0;
        double centoidaPoY = 0;
        int size = componentS[i].size();
        cout << "количество точек в компаненте связности " << size << endl;
        for (int j = 0; j < size; j++) {
            double xtemp = 1000;
            double ytemp = 1000;
            int PointIndex = componentS[i][j]; 
            xtemp = graph.getPoint(PointIndex).x;
            ytemp = graph.getPoint(PointIndex).y;
            xsum += xtemp;
            ysum += ytemp; 
            if (xtemp < minx) { minx = xtemp;  }
            if (ytemp < miny) { miny = ytemp; }
            if (xtemp > maxx) { maxx = xtemp; }
            if (ytemp > maxy) { maxy = ytemp; }
        }
        centoidaPoX += xsum;
        centoidaPoY += ysum;
        cout << "Сумма по x= " << xsum << "; мин х= " << minx << "; макс х= " << maxx <<  "; Центроида по Х=" << centoidaPoX/size << endl;
        cout << "Сумма по y=" << ysum << "; мин y= " << miny << "; макс y= " << maxy << " Центроида по Y=" << centoidaPoY/size << endl;
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
