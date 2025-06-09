#include "pch.h"
#include "metoda_lu.h"
#include <iostream>

int main() {
    // Uk�ad 3 r�wna� liniowych:
    // 1) 2x - y - 2z = -2
    // 2) -4x + 6y + 3z = 9
    // 3) -4x - 2y + 8z = -5

    const int N = 3;
    std::vector<std::vector<double>> A = {
        { 2, -1, -2},  // Wsp�czynniki 1. r�wnania
        {-4,  6,  3},  // Wsp�czynniki 2. r�wnania
        {-4, -2,  8}   // Wsp�czynniki 3. r�wnania
    };

    std::vector<double> b = { -2, 9, -5 };  // Prawe strony r�wna�
    std::vector<std::vector<double>> L, U; // Macierze rozk�adu LU

    // Wy�wietlenie uk�adu r�wna�
    std::cout << "Rozwiazywany uklad rownan:\n";
    std::cout << "1)  2x -  y - 2z = -2\n";
    std::cout << "2) -4x + 6y + 3z =  9\n";
    std::cout << "3) -4x - 2y + 8z = -5\n\n";

    // Pr�ba wykonania rozk�adu LU
    if (metodaLU(A, L, U, N)) {
        // Rozwi�zanie uk�adu
        auto x = rozwiaz_LU(L, U, b, N);

        // Wy�wietlenie rozwi�zania
        std::cout << "Znalezione rozwiazanie:\n";
        std::cout << "x = " << x[0] << "\n";
        std::cout << "y = " << x[1] << "\n";
        std::cout << "z = " << x[2] << "\n\n";

        // Sprawdzenie poprawno�ci
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
