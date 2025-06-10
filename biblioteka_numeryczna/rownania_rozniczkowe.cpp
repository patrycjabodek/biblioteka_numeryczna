#include "pch.h"
#include "rownania_rozniczkowe.h"
#include <iostream>
#include <cmath>
#include <iomanip>
#include <stdexcept>

std::vector<double> metodaEuler(double T0, double t_end, double h,
    std::function<double(double, double)> f) {
    
    if (h <= 0) {
        throw std::invalid_argument("Krok czasowy (h) musi byc dodatni.");
    }
    
    std::vector<double> wynik;
    double T = T0, t = 0.0;
    while (t < t_end + 1e-9) {
        wynik.push_back(T);
        T += h * f(T, t);
        t += h;
    }
    return wynik;
}

std::vector<double> metodaHeuna(double T0, double t_end, double h,
    std::function<double(double, double)> f) {

    if (h <= 0) {
        throw std::invalid_argument("Krok czasowy (h) musi byc dodatni.");
    }

    std::vector<double> wynik;
    double T = T0, t = 0.0;
    while (t < t_end + 1e-9) {
        wynik.push_back(T);
        double f1 = f(T, t);
        double T_pred = T + h * f1;
        double f2 = f(T_pred, t + h);
        T += (h / 2.0) * (f1 + f2);
        t += h;
    }
    return wynik;
}

std::vector<double> metodaMidpoint(double T0, double t_end, double h,
    std::function<double(double, double)> f) {

    if (h <= 0) {
        throw std::invalid_argument("Krok czasowy (h) musi byc dodatni.");
    }

    std::vector<double> wynik;
    double T = T0, t = 0.0;
    while (t < t_end + 1e-9) {
        wynik.push_back(T);
        double k1 = h * f(T, t);
        double k2 = h * f(T + k1 / 2.0, t + h / 2.0);
        T += k2;
        t += h;
    }
    return wynik;
}

std::vector<double> metodaRK4(double T0, double t_end, double h,
    std::function<double(double, double)> f) {

    if (h <= 0) {
        throw std::invalid_argument("Krok czasowy (h) musi byc dodatni.");
    }

    std::vector<double> wynik;
    double T = T0, t = 0.0;
    while (t < t_end + 1e-9) {
        wynik.push_back(T);
        double k1 = h * f(T, t);
        double k2 = h * f(T + k1 / 2.0, t + h / 2.0);
        double k3 = h * f(T + k2 / 2.0, t + h / 2.0);
        double k4 = h * f(T + k3, t + h);
        T += (1.0 / 6.0) * (k1 + 2 * k2 + 2 * k3 + k4);
        t += h;
    }
    return wynik;
}

double obliczRMSE(const std::vector<double>& przybl, double h,
    std::function<double(double)> dokladna) {
    double blad = 0.0;
    int N = przybl.size();
    for (int i = 0; i < N; ++i) {
        double t = i * h;
        double T_dokl = dokladna(t);
        double err = przybl[i] - T_dokl;
        blad += err * err;
    }
    return std::sqrt(blad / N);
}

void wypiszKrzywa(const std::vector<double>& temp, double h, const std::string& metoda) {
    std::cout << "Krzywa dla: " << metoda << ", h = " << h << "\n";
    std::cout << std::setw(10) << "t [s]" << std::setw(15) << "T [K]\n";
    for (int i = 0; i < temp.size(); ++i) {
        std::cout << std::setw(10) << std::fixed << std::setprecision(2) << i * h
            << std::setw(15) << std::fixed << std::setprecision(6) << temp[i] << "\n";
    }
    std::cout << "\n";
}
