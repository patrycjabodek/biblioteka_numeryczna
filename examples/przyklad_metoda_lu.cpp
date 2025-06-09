#include "pch.h"
#include "metoda_lu.h"
#include <iostream>

int main() {
    std::vector<std::vector<double>> A = {
        {1, 2, 4},
        {3, 8, 14},
        {2, 6, 13}
    };
    std::vector<double> b = { 3, 13, 4 };
    int N = 3;

    std::vector<std::vector<double>> L, U;

    if (metodaLU(A, L, U, N)) {
        std::vector<double> x = rozwiaz_LU(L, U, b, N);

        std::cout << "Rozwi¹zanie x: ";
        for (double xi : x) std::cout << xi << " ";
        std::cout << std::endl;
    }
    else {
        std::cout << "Nie uda³o siê wykonaæ rozk³adu LU.\n";
    }

    return 0;
}
