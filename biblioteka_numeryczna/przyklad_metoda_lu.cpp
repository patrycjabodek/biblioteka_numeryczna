#include "pch.h"
#include "metoda_lu.h"
#include <iostream>

int main() {
    // uk³ad 3 równañ liniowych z 3 niewiadomymi:
    // 1) 1x + 2y + 4z =  3
    // 2) 3x + 8y + 14z = 13
    // 3) 2x + 6y + 13z = 4

    // Macierz wspó³czynników uk³adu równañ (lewa strona)
    std::vector<std::vector<double>> A = {
        {1,  2,  4},  // Wspó³czynniki pierwszego równania
        {3,  68, 14},  // Wspó³czynniki drugiego równania
        {2,  6, 13}   // Wspó³czynniki trzeciego równania
    };

    // Wektor wyrazów wolnych (prawa strona równañ)
    std::vector<double> b = { 3, 13, 4 };

    // Liczba równañ/niewiadomych
    int N = 3;

   
    std::vector<std::vector<double>> L, U;

    //rozk³ad LU macierzy A
    if (metodaLU(A, L, U, N)) {
      
        std::vector<double> x = rozwiaz_LU(L, U, b, N);

        std::cout << "Rozwiazanie ukladu rownan:" << std::endl;
        std::cout << "1) 1x + 2y + 4z =  3" << std::endl;
        std::cout << "2) 3x + 68y + 14z = 13" << std::endl;
        std::cout << "3) 2x + 6y + 13z =  4" << std::endl;
        std::cout << std::endl;

        std::cout << "Rozwiazanie:" << std::endl;
        std::cout << "x = " << x[0] << std::endl;
        std::cout << "y = " << x[1] << std::endl;
        std::cout << "z = " << x[2] << std::endl;
    }
    else {
        std::cout << "Nie udalo sie wykonac rozkladu LU - macierz mo¿e byæ osobliwa.\n";
    }

    return 0;
}
