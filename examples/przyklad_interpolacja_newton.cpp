#include "pch.h"
#include "interpolacja_newton.h"
#include <iostream>

int main() {
    std::vector<double> xi = { 0.0, 1.0, 2.0 };
    std::vector<double> fxi = { 1.0, 3.0, 2.0 };

    auto wsp = oblicz_wspolczynniki_newton(xi, fxi);

    double x;
    std::cout << "Podaj wartoœæ x: ";
    std::cin >> x;

    double wynik = interpolacja_newton(wsp, xi, x);
    std::cout << "W(x) = " << wynik << std::endl;

    return 0;
}
