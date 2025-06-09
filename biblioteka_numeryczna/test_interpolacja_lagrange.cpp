#include "pch.h"
#include "interpolacja_lagrange.h"
#include <iostream>
#include <cmath>

bool czyPrawieRowne(double a, double b, double epsilon = 1e-9) {
    return std::abs(a - b) < epsilon;
}

int main3() {
    std::vector<Wezel> punkty = {
        {1.0, 2.0},
        {2.0, 3.0},
        {3.0, 5.0}
    };

    double x = 2.5;
    // W(2.5) = 0.5*(2.5)^2 - 0.5*(2.5) + 2 = 3.875
    double oczekiwany_wynik = 3.875;

    double wynik = interpolacja_lagrange(punkty, x);

    std::cout << "Interpolacja w punkcie " << x << " = " << wynik << std::endl;

    if (czyPrawieRowne(wynik, oczekiwany_wynik)) {
        std::cout << "\nWynik: TEST ZDANY" << std::endl;
    }
    else {
        std::cout << "\nWynik: TEST NIE ZDANY" << std::endl;
        std::cout << "Blad bezwzgledny: " << std::abs(wynik - oczekiwany_wynik) << std::endl;
    }


    return 0;
}