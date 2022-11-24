
#include <iostream>
#include "Funk.hpp"
using namespace std;
int main()
{
    int mat[100][100];
    int str, sto;
    cout << "enter the number of rows and columns"<<endl;
    vg::newmat(mat, str, sto);//создание матрицы
    vg::vivod(mat, str, sto);//вывод введенной матрицы
    cout << endl;
    if (vg:: sumdig(vg::max(mat, str, sto)) == vg::sumdig(vg::min(mat, str, sto))) {//сортировка матрицы
        vg::swap(mat, str, sto);
    }
    vg::vivod(mat, str, sto);//вывод новой матрицы
}
