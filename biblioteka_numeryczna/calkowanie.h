#pragma once
#include <vector>
#include <functional>

// Metody dla wielomianu (dane jako wspó³czynniki)
double metoda_prostokatow(const std::vector<double>& wspolczynniki, double a, double b, int n);
double metoda_trapezow(const std::vector<double>& wspolczynniki, double a, double b, int n);
double metoda_simpsona(const std::vector<double>& wspolczynniki, double a, double b, int n);

// Metody dla funkcji f(x)
double metoda_prostokatow_funkcja(double a, double b, int n);
double metoda_trapezow_funkcja(double a, double b, int n);
double metoda_simpsona_funkcja(double a, double b, int n);

// Schemat Hornera do obliczania wielomianu
double oblicz_schemat_hornera(const std::vector<double>& wspolczynniki, double x);

// Obliczanie b³êdu
double oblicz_blad(double obliczona, double dokladna);

// Kwadratura Gaussa-Legendre’a
double gauss_legendre(std::function<double(double)> f, double a, double b, int l_wezlow, int l_podprzedzialow);

