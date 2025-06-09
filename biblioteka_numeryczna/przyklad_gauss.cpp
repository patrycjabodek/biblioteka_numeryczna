#include "pch.h"
#include "gauss.h"
#include <iostream>


int main2() {
    // uk³ad 2 równañ liniowych z 2 niewiadomymi:
    // 1) 2x +  y = 11
    // 2) 5x + 7y = 13

    // Liczba równañ/niewiadomych
    const int N = 2;

    // Macierz wspó³czynników (lewa strona równañ)
    std::vector<std::vector<double>> A = {
        {2, 1},  // Wspó³czynniki pierwszego równania
        {5, 7}   // Wspó³czynniki drugiego równania
    };

    // Wektor wyrazów wolnych (prawa strona równañ)
    std::vector<double> b = { 11, 13 };

    // Wektor na rozwi¹zanie (wartoœci x i y)
    std::vector<double> x;

    eliminacja_gaussa(N, A, b, x);

    std::cout << "Rozwiazanie ukladu rownan:" << std::endl;
    std::cout << "1) 2x +  y = 11" << std::endl;
    std::cout << "2) 5x + 7y = 13" << std::endl;
    std::cout << std::endl;
    std::cout << "x = " << x[0] << std::endl;
    std::cout << "y = " << x[1] << std::endl;

    return 0;
}