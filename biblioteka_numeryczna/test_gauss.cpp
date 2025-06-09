#include "pch.h"
#include "gauss.h"
#include <iostream>

int main2() {
    // Uk�ad 3 r�wna� liniowych z 3 niewiadomymi:
    // 1) 2x - y + z = 2
    // 2) 3x + 3y + 9z = -1
    // 3) 3x + 3y + 5z = 4

    const int N = 3;
    std::vector<std::vector<double>> A = {
        { 2, -1, 1 },  // Wsp�czynniki 1. r�wnania
        { 3,  3, 21 },  // Wsp�czynniki 2. r�wnania
        { 3,  3, 5 }   // Wsp�czynniki 3. r�wnania
    };

    std::vector<double> b = { 2, -1, 4 };  // Prawe strony r�wna�
    std::vector<double> x;                 // Wektor na rozwi�zania

    // Kopie oryginalnych danych do sprawdzenia poprawno�ci
    auto A_kopia = A;
    auto b_kopia = b;

    // Rozwi�zanie uk�adu metod� Gaussa
    if (eliminacja_gaussa(N, A, b, x)) {
        // Wy�wietlenie r�wna�
        std::cout << "Rozwiazany uklad rownan:\n";
        std::cout << "1) 2x -  y +  z =  2\n";
        std::cout << "2) 3x + 3y + 21z = -1\n";
        std::cout << "3) 3x + 3y + 5z =  4\n\n";

        // Wy�wietlenie rozwi�zania
        std::cout << "Rozwiazanie:\n";
        std::cout << "x = " << x[0] << "\n";
        std::cout << "y = " << x[1] << "\n";
        std::cout << "z = " << x[2] << "\n\n";

        // Sprawdzenie poprawno�ci rozwi�zania
        std::cout << "Sprawdzenie poprawnosci:\n";
        double max_blad = 0.0;
        for (int i = 0; i < N; ++i) {
            double suma = 0.0;
            for (int j = 0; j < N; ++j) {
                suma += A_kopia[i][j] * x[j];
            }
            double blad = fabs(suma - b_kopia[i]);
            std::cout << "Rownanie " << i + 1 << ": blad = " << blad << "\n";
            if (blad > max_blad) max_blad = blad;
        }

        const double tolerancja = 1e-9;
        std::cout << "\nMaksymalny blad: " << max_blad;
        if (max_blad < tolerancja) {
            std::cout << " (rozwiazanie poprawne)\n";
        }
        else {
            std::cout << " (rozwiazanie moze byc niepoprawne!)\n";
        }
    }
    else {
        std::cerr << "Uk�ad nie ma jednoznacznego rozwi�zania (macierz osobliwa).\n";
    }


    return 0;
}