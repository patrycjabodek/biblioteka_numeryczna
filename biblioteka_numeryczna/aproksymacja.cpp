#include "pch.h"
#include "aproksymacja.h"
#include "gauss.h"        
#include "calkowanie.h"    
#include <cmath>
#include <iostream>
#include <stdexcept>

const double EPSILON = 1e-10;

std::vector<double> aproksymacja(int stopien, double a, double b, std::function<double(double)> f) {
   
    if (stopien < 0) {
        throw std::invalid_argument("Stopien wielomianu aproksymujacego musi byc nieujemny.");
    }
    
    int n = stopien + 1;
    std::vector<std::vector<double>> A(n, std::vector<double>(n, 0.0));
    std::vector<double> B(n, 0.0);
    std::vector<double> x;

    const int l_wezlow = 4;
    const int l_podprzedzialow = 100;

    // Wype³nienie macierzy A i wektora B
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // ca³ka z x^(i+j)
            A[i][j] = (std::pow(b, i + j + 1) - std::pow(a, i + j + 1)) / (i + j + 1);
        }
        // ca³ka z f(x)*x^i
        B[i] = gauss_legendre([=](double x) { return f(x) * std::pow(x, i); }, a, b, l_wezlow, l_podprzedzialow);
    }

    if (!eliminacja_gaussa(n, A, B, x)) {
        std::cerr << "B³¹d: nie mo¿na rozwi¹zaæ uk³adu równañ w aproksymacji.\n";
        return {};
    }

    return x;
}

double wielomian_aproksymujacy(double x, const std::vector<double>& wspolczynniki) {
    double wynik = 0.0;
    for (int i = 0; i < wspolczynniki.size(); i++) {
        wynik += wspolczynniki[i] * std::pow(x, i);
    }
    return wynik;
}
