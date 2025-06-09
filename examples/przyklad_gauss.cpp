#include "pch.h"
#include "gauss.h"
#include <iostream>


int main() {
    int N = 2;
    std::vector<std::vector<double>> A = {
        {2, 1},
        {5, 7}
    };
    std::vector<double> b = { 11, 13 };
    std::vector<double> x;

    eliminacja_gaussa(N, A, b, x);

    std::cout << "Rozwi¹zanie: ";
    for (double xi : x) std::cout << xi << " ";
    std::cout << std::endl;

    return 0;
}