#pragma once
#include "Funk.hpp"
#include <iostream>
namespace vg {
    int max(int m[100][100], int a, int b) { //?????????? ????????????? ???????? ???????
        int maxch = 0;
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                if (m[i][j] > maxch) {
                    maxch = m[i][j];
                }
            }
        }
        return maxch;
    }

    int min(int m[100][100], int a, int b) {//?????????? ???????????? ???????? ???????
        int minch = m[0][0];
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                if (m[i][j] < minch) {
                    minch = m[i][j];
                }
            }
        }
        return minch;
    }

    int sumdig(int a) {// ????? ????
        int sum = 0;
        while (a != 0) {
            sum += a % 10;
            a /= 10;
        }
        return sum;
    }

    int sums(int m[100][100], int strok, int stolb) {//????? ????????? ? ??????
        int sums = 0;
        for (int i = 0; i < stolb; i++) {
            sums += m[strok][i];
        }
        return sums;
    }

    void vivod(int m[100][100], int strok, int stolb) {//????? ???????
        for (int i = 0; i < strok; i++) {
            for (int j = 0; j < stolb; j++) {
                std::cout << m[i][j] << "\t";

            }
            std::cout << "\n";
        }
    }

    void swap(int m[100][100], int strok, int stolb) {// ???? ???????
        for (int i = 0; i < strok; i++) {
            for (int j = i + 1; j < strok; j++) {
                if (sums(m, j, strok) < sums(m, i, strok)) {
                    for (int k = 0; k < strok; k++) {
                        std::swap(m[j][k], m[i][k]);
                    }
                }
            }
        }
    }

    void newmat(int m[100][100], int& strok, int& stolb) {
        std::cin >> strok >> stolb;
        for (int i = 0; i < strok; i++) {
            for (int j = 0; j < stolb; j++) {
                std::cin >> m[i][j];
            }
        }
    }
}