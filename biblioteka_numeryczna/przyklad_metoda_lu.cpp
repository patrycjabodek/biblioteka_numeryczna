#include "pch.h"
#include "metoda_lu.h"
#include <iostream>

int main() {
    // uk�ad 3 r�wna� liniowych z 3 niewiadomymi:
    // 1) 1x + 2y + 4z =  3
    // 2) 3x + 8y + 14z = 13
    // 3) 2x + 6y + 13z = 4

    // Macierz wsp�czynnik�w uk�adu r�wna� (lewa strona)
    std::vector<std::vector<double>> A = {
        {1,  2,  4},  // Wsp�czynniki pierwszego r�wnania
        {3,  68, 14},  // Wsp�czynniki drugiego r�wnania
        {2,  6, 13}   // Wsp�czynniki trzeciego r�wnania
    };

    // Wektor wyraz�w wolnych (prawa strona r�wna�)
    std::vector<double> b = { 3, 13, 4 };

    // Liczba r�wna�/niewiadomych
    int N = 3;

   
    std::vector<std::vector<double>> L, U;

    //rozk�ad LU macierzy A
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
        std::cout << "Nie udalo sie wykonac rozkladu LU - macierz mo�e by� osobliwa.\n";
    }

    return 0;
}
