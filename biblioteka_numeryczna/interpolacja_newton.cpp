#include "pch.h"
#include "interpolacja_newton.h"



std::vector<double> oblicz_wspolczynniki_newton(const std::vector<double>& xi, const std::vector<double>& fxi) {
    int n = xi.size();
    std::vector<double> a = fxi; 

    for (int j = 1; j < n; ++j) {
        for (int i = n - 1; i >= j; --i) {
            a[i] = (a[i] - a[i - 1]) / (xi[i] - xi[i - j]);
        }
    }

    return a;
}

double interpolacja_newton(const std::vector<double>& wspolczynniki, const std::vector<double>& xi, double x) {
    double wynik = wspolczynniki[0];
    double iloczyn = 1.0;

    for (size_t i = 1; i < wspolczynniki.size(); i++) {
        iloczyn *= (x - xi[i - 1]);
        wynik += wspolczynniki[i] * iloczyn;
    }

    return wynik;
}
