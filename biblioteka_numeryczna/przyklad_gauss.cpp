#include "pch.h"
#include "gauss.h"
#include <iostream>


int main2() {
    // uk�ad 2 r�wna� liniowych z 2 niewiadomymi:
    // 1) 2x +  y = 11
    // 2) 5x + 7y = 13

    // Liczba r�wna�/niewiadomych
    const int N = 2;

    // Macierz wsp�czynnik�w (lewa strona r�wna�)
    std::vector<std::vector<double>> A = {
        {2, 1},  // Wsp�czynniki pierwszego r�wnania
        {5, 7}   // Wsp�czynniki drugiego r�wnania
    };

    // Wektor wyraz�w wolnych (prawa strona r�wna�)
    std::vector<double> b = { 11, 13 };

    // Wektor na rozwi�zanie (warto�ci x i y)
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