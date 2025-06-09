#include "pch.h"
#include "interpolacja_newton.h"
#include <iostream>
#include <cmath>

bool czyRowne(double a, double b, double epsilon = 1e-9) {
    return std::abs(a - b) < epsilon;
}


int main4() {
    std::vector<double> xi = { 1.0, 2.0, 3.0 };
    std::vector<double> fxi = { 2.0, 3.0, 5.0 };

    auto wsp = oblicz_wspolczynniki_newton(xi, fxi);

    double x = 2.5;
    double wynik = interpolacja_newton(wsp, xi, x);
    double oczekiwany_wynik = 3.875;


    std::cout << "W(" << x << ") = " << wynik << std::endl;

    // Przyk³adowy test
    if (czyRowne(wynik, oczekiwany_wynik)) {
        std::cout << "\nWynik: TEST ZDANY" << std::endl;
    }
    else {
        std::cout << "\nWynik: TEST NIE ZDANY" << std::endl;
        std::cout << "Blad bezwzgledny: " << std::abs(wynik - oczekiwany_wynik) << std::endl;
    }

    return 0;
}
