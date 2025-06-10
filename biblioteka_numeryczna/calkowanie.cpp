#include "pch.h"
#include "calkowanie.h"
#include <cmath>
#include <iostream>
#include <stdexcept>

double oblicz_schemat_hornera(const std::vector<double>& wspolczynniki, double x) {
    double wynik = 0;
    for (int i = wspolczynniki.size() - 1; i >= 0; i--) {
        wynik = wspolczynniki[i] + x * wynik;
    }
    return wynik;
}

double metoda_prostokatow(const std::vector<double>& wspolczynniki, double a, double b, int n) {
    if (n <= 0) {
        throw std::invalid_argument("Liczba podprzedzialow (n) musi byc dodatnia.");
    }
    double h = (b - a) / n;
    double suma = 0.0;
    for (int i = 0; i < n; i++) {
        double x = a + (i + 0.5) * h;
        suma += oblicz_schemat_hornera(wspolczynniki, x);
    }
    return suma * h;
}

double metoda_trapezow(const std::vector<double>& wspolczynniki, double a, double b, int n) {
    if (n <= 0) {
        throw std::invalid_argument("Liczba podprzedzialow (n) musi byc dodatnia.");
    }
    double h = (b - a) / n;
    double suma = 0.5 * (oblicz_schemat_hornera(wspolczynniki, a) + oblicz_schemat_hornera(wspolczynniki, b));
    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        suma += oblicz_schemat_hornera(wspolczynniki, x);
    }
    return suma * h;
}

double metoda_simpsona(const std::vector<double>& wspolczynniki, double a, double b, int n) {
    if (n <= 0) {
        throw std::invalid_argument("Liczba podprzedzialow (n) musi byc dodatnia.");
    }
    if (n % 2 != 0) n++;
    double h = (b - a) / n;
    double suma = oblicz_schemat_hornera(wspolczynniki, a) + oblicz_schemat_hornera(wspolczynniki, b);
    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        suma += (i % 2 == 0 ? 2 : 4) * oblicz_schemat_hornera(wspolczynniki, x);
    }
    return suma * h / 3;
}

double funkcja(double x) {
    return x * std::pow(std::cos(x), 3);
}

double metoda_prostokatow_funkcja(double a, double b, int n) {
    double h = (b - a) / n;
    double suma = 0.0;
    for (int i = 0; i < n; i++) {
        double x = a + (i + 0.5) * h;
        suma += funkcja(x);
    }
    return suma * h;
}

double metoda_trapezow_funkcja(double a, double b, int n) {
    double h = (b - a) / n;
    double suma = 0.5 * (funkcja(a) + funkcja(b));
    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        suma += funkcja(x);
    }
    return suma * h;
}

double metoda_simpsona_funkcja(double a, double b, int n) {
    if (n % 2 != 0) n++;
    double h = (b - a) / n;
    double suma = funkcja(a) + funkcja(b);
    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        suma += (i % 2 == 0 ? 2 : 4) * funkcja(x);
    }
    return suma * h / 3;
}

double oblicz_blad(double obliczona, double dokladna) {
    return std::fabs(obliczona - dokladna);
}

double gauss_legendre(std::function<double(double)> f, double a, double b, int l_wezlow, int l_podprzedzialow) {
   
    if (l_podprzedzialow <= 0) {
        throw std::invalid_argument("Liczba podprzedzialow musi byc dodatnia.");
    }
    double h = (b - a) / l_podprzedzialow;
    double result = 0.0;

    std::vector<double> x, w;

    if (l_wezlow == 2) {
        x = { -0.57735, 0.57735 };
        w = { 1.0, 1.0 };
    }
    else if (l_wezlow == 3) {
        x = { -0.774597, 0.0, 0.774597 };
        w = { 0.555556, 0.888889, 0.555556 };
    }
    else if (l_wezlow == 4) {
        x = { -0.861136, -0.339981, 0.339981, 0.861136 };
        w = { 0.347855, 0.652145, 0.652145, 0.347855 };
    }
    else {
        throw std::invalid_argument("Liczba wezlow (l_wezlow) musi nalezec do {2, 3, 4}.");
    }

    for (int k = 0; k < l_podprzedzialow; ++k) {
        double a_k = a + k * h;
        double b_k = a + (k + 1) * h;

        for (int i = 0; i < l_wezlow; ++i) {
            double xi = ((b_k - a_k) / 2.0) * x[i] + (a_k + b_k) / 2.0;
            result += w[i] * f(xi);
        }
    }

    return result * h / 2.0;
}
