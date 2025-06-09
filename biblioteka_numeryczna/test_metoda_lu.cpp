#include "pch.h"
#include "metoda_lu.h"
#include <iostream>

int main() {
    // Uk³ad 3 równañ liniowych:
    // 1) 2x - y - 2z = -2
    // 2) -4x + 6y + 3z = 9
    // 3) -4x - 2y + 8z = -5

    const int N = 3;
    std::vector<std::vector<double>> A = {
        { 2, -1, -2},  // Wspó³czynniki 1. równania
        {-4,  6,  3},  // Wspó³czynniki 2. równania
        {-4, -2,  8}   // Wspó³czynniki 3. równania
    };

    std::vector<double> b = { -2, 9, -5 };  // Prawe strony równañ
    std::vector<std::vector<double>> L, U; // Macierze rozk³adu LU

    // Wyœwietlenie uk³adu równañ
    std::cout << "Rozwiazywany uklad rownan:\n";
    std::cout << "1)  2x -  y - 2z = -2\n";
    std::cout << "2) -4x + 6y + 3z =  9\n";
    std::cout << "3) -4x - 2y + 8z = -5\n\n";

    // Próba wykonania rozk³adu LU
    if (metodaLU(A, L, U, N)) {
        // Rozwi¹zanie uk³adu
        auto x = rozwiaz_LU(L, U, b, N);

        // Wyœwietlenie rozwi¹zania
        std::cout << "Znalezione rozwiazanie:\n";
        std::cout << "x = " << x[0] << "\n";
        std::cout << "y = " << x[1] << "\n";
        std::cout << "z = " << x[2] << "\n\n";

        // Sprawdzenie poprawnoœci
        std::cout << "Weryfikacja rozwiazania:\n";
        if (sprawdzenie(N, A, b, x)) {
            std::cout << "Rozwiazanie poprawne (bledy w granicach tolerancji)\n";
        }
        else {
            std::cout << "UWAGA: Rozwiazanie moze byc niepoprawne!\n";
        }
    }
    else {
        std::cout << "Nie udalo sie wykonac rozkladu LU - macierz moze byc osobliwa.\n";
    }

    return 0;
}
