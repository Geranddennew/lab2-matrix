#include <iostream>
#include <ctime>
#include <thread>
#include <chrono>
using namespace std;
const int n = 100;
const int m = 100;

void line_nechet(int(*numbers1)[m], int(*numbers2)[m], int(*numbersfinal)[m],  int maxline, int maxstolb) {
    
    for (int i = 0; i < maxstolb; i += 2) {
        for (int j = 0; j < maxline; j++)
        {
            numbersfinal[i][j] = numbers1[i][j] * numbers2[i][j];

        }
    }
    //return numbersfinal[idx][6];
}



void line_chet(int(*numbers1)[m], int(*numbers2)[m], int(*numbersfinal)[m], int maxline,int maxstolb) {

    for (int i = 1; i < maxstolb; i += 2)
    {
        for (int j = 0; j < maxline; j++)
        {
            numbersfinal[i][j] = numbers1[i][j] * numbers2[i][j];

        }
    }
    //return numbersfinal[idx][6];
}


int main()
{
    auto start = chrono::high_resolution_clock::now();
    //unsigned int start_time = clock();
    //srand(time(NULL));
    setlocale(LC_ALL, "");

    int arr_first[n][m] = { 0 };
    int arr_second[n][m] = { 0 };
    int final_arr[n][m] = { 0 };

    //const int length = 20;
    //const int length2 = 20;



    //thread final[n][m];
     for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            arr_first[i][j] = rand() % 100;
            arr_second[i][j] = rand() % 100;
        }
    


    

    //line_chet(arr_first, arr_second, ref(final_arr), m, n);
    //line_nechet(arr_first, arr_second, ref(final_arr), m, n);
   
   // for (int i = 0; i < n; i+=2) {
    thread t1(line_chet, arr_first, arr_second, ref(final_arr), m,n);
        //final_arr[i][6] = line_chet(arr_first,arr_second, final_arr, i, m);
    t1.join();
    //}
    
    //for (int i = 1; i < n; i+=2)
   // {
    thread t2(line_nechet, arr_first, arr_second, ref(final_arr), m,n);
    t2.join();
        //final_arr[i][6] = line_nechet(arr_first, arr_second, final_arr, i, m);
    //}
    

    //вывод
    cout << "Первый массив" << '\n';
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout.width(3);
            cout << arr_first[i][j];
        }
        cout << endl;
    }
    cout << "Второй массив" << '\n';
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout.width(3);
            cout << arr_second[i][j];
        }
        cout << endl;
    }
    cout << "Итоговый массив"<<'\n';
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout.width(7);
            cout << final_arr[i][j];
        }
        cout  << endl;
    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<float> duration = end - start;
    cout << '\n' << "Выполнен за t = " << duration.count() << " seconds" << '\n';
    //unsigned int end_time = clock(); // конечное время
    //unsigned int search_time = end_time - start_time;
    //cout << '\n' << "Выполнен за t = " << search_time<<'\n';
    system("pause");
    return 0;
}