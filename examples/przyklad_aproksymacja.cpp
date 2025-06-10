#include "aproksymacja.h"
#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    auto f = [](double x) {
        return std::exp(x) * std::cos(6 * x) - std::pow(x, 3) + 5 * std::pow(x, 2) - 10;
        };

    double a = 1.5, b = 4.5;
    int stopien = 5;
    int liczba_punktow = 100;
    int l_wezlow = 4;
    int l_podprzedzialow = 100;

    std::vector<double> wsp = aproksymacja(stopien, a, b, f, l_wezlow, l_podprzedzialow);

    std::cout << "\nWspó³czynniki aproksymacji:\n";
    for (size_t i = 0; i < wsp.size(); ++i) {
        std::cout << "a[" << i << "] = " << wsp[i] << "\n";
    }

    std::cout << std::fixed << std::setprecision(6);
    std::cout << "\nPunkty testowe:\n";
    std::cout << "x;f(x);P(x);blad\n";

    double krok = (b - a) / (liczba_punktow - 1);
    for (int i = 0; i < liczba_punktow; i++) {
        double x = a + i * krok;
        double fx = f(x);
        double Px = wielomian_aproksymujacy(x, wsp);
        double blad = std::abs(fx - Px);

        std::cout << x << ";" << fx << ";" << Px << ";" << blad << "\n";
    }

    return 0;
}