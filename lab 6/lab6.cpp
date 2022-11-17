
#include <iostream>
#include "Funk.hpp"
using namespace std;
int main()
{
    int mat[100][100];
    int str, sto;
    cout << "enter the number of rows and columns"<<endl;
    cin >> str >> sto;
    for (int i = 0; i < str; i++) {//создание марицы
        for (int j = 0; j < sto; j++) {
            cin >> mat[i][j];
        }
    }
    vivod(mat, str, sto);//вывод введенной матрицы

    //проверка функций

    /*cout << "max = " << max(mat, str, sto) << endl;
    cout << "min = " << min(mat, str, sto) << endl;
    cout << "summax = " << sumdig(max(mat, str, sto)) << endl;
    cout << "summin = " << sumdig(min(mat, str, sto)) << endl;
    cout << "sumstr = " <<sums(mat,0,sto) << endl;*/
    
    
    if (sumdig(max(mat, str, sto)) == sumdig(min(mat, str, sto))) {//сортировка матрицы
        for (int i = 0; i < str; i++) {
            for (int j = i+1; j < str; j++) {
                if (sums(mat, j, sto) < sums(mat, i, sto)) {
                    for (int k = 0; k < sto; k++) {
                        swap(mat[j][k], mat[i][k]);
                    }
                }
            }
        }
    }
    vivod(mat, str, sto);//вывод новой матрицы
}
