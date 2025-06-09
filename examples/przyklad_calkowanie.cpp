#include "pch.h"
#include "calkowanie.h"
#include <iostream>
#include <vector>
#include <functional>


int main() {
    std::vector<double> wsp = { 1.0, 0.0, 1.0 }; // f(x) = x^2 + 1
    double a = 0.0, b = 2.0;
    int n = 100;

    std::cout << "Ca³kowanie wielomianu f(x) = x^2 + 1 w przedziale [0, 2]\n";
    std::cout << "Metoda prostok¹tów : " << metoda_prostokatow(wsp, a, b, n) << "\n";
    std::cout << "Metoda trapezów    : " << metoda_trapezow(wsp, a, b, n) << "\n";
    std::cout << "Metoda Simpsona    : " << metoda_simpsona(wsp, a, b, n) << "\n";

    std::function<double(double)> wielomian = [](double x) {
        return x * x + 1;
        };
    std::cout << "Gauss-Legendre (3 wêz³y, 50 podprzedzia³ów): "
        << gauss_legendre(wielomian, a, b, 3, 50) << "\n\n";

    // Funkcja: f(x) = x * cos^3(x)
    double dokladna = 4.2025;
    double a2 = 3.5, b2 = 6.52968912439344;

    std::cout << "Ca³kowanie funkcji f(x) = x * cos^3(x) w przedziale [3.5, 6.52968912439344]\n";
    double p2 = metoda_prostokatow_funkcja(a2, b2, n);
    double t2 = metoda_trapezow_funkcja(a2, b2, n);
    double s2 = metoda_simpsona_funkcja(a2, b2, n);

    std::cout << "Metoda prostok¹tów : " << p2 << " | B³¹d: " << oblicz_blad(p2, dokladna) << "\n";
    std::cout << "Metoda trapezów    : " << t2 << " | B³¹d: " << oblicz_blad(t2, dokladna) << "\n";
    std::cout << "Metoda Simpsona    : " << s2 << " | B³¹d: " << oblicz_blad(s2, dokladna) << "\n";

    std::function<double(double)> f2 = [](double x) {
        return x * std::pow(std::cos(x), 3);
        };
    double g2 = gauss_legendre(f2, a2, b2, 4, 50);
    std::cout << "Gauss-Legendre (4 wêz³y): " << g2 << " | B³¹d: " << oblicz_blad(g2, dokladna) << "\n";

    return 0;
}
