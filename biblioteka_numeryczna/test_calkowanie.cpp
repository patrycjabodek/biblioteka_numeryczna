#include "pch.h"
#include "calkowanie.h"
#include <iostream>
#include <cmath>
#include <functional>

int main1() {
    std::vector<double> wsp = { 1.0, 0.0, 1.0 }; // f(x) = x^2 + 1
    double a = 0.0, b = 2.0;
    int n = 100;
    double dokladna = 4.6666667;

    std::cout << "Test calkowania dla f(x) = x^2 + 1 w przedziale [0, 2]\n";
    std::cout << "Wartosc dokladna: " << dokladna << "\n\n";

    double p = metoda_prostokatow(wsp, a, b, n);
    double t = metoda_trapezow(wsp, a, b, n);
    double s = metoda_simpsona(wsp, a, b, n);

    std::function<double(double)> fx = [](double x) { return x * x + 1; };
    double g = gauss_legendre(fx, a, b, 4, 1000);

    std::cout << "Metoda prostokatow : " << p << "  | Blad: " << oblicz_blad(p, dokladna) << "\n";
    std::cout << "Metoda trapezow    : " << t << "  | Blad: " << oblicz_blad(t, dokladna) << "\n";
    std::cout << "Metoda Simpsona    : " << s << "  | Blad: " << oblicz_blad(s, dokladna) << "\n";
    std::cout << "Gauss-Legendre (4) : " << g << "  | Blad: " << oblicz_blad(g, dokladna) << "\n";

    return 0;
}
