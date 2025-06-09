#include "pch.h"
#include "metoda_lu.h"
#include <iostream>
#include <iomanip>
#include <cmath>



const double EPSILON = 1e-10;

void wyswietl_macierz(const std::vector<std::vector<double>>& macierz) {
    int n = macierz.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << std::setw(10) << macierz[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

bool metodaLU(const std::vector<std::vector<double>>& A, std::vector<std::vector<double>>& L, std::vector<std::vector<double>>& U, int n) {
    L.assign(n, std::vector<double>(n, 0.0));
    U.assign(n, std::vector<double>(n, 0.0));

    for (int k = 0; k < n; k++) {
        for (int j = k; j < n; j++) {
            double sum = 0.0;
            for (int s = 0; s < k; s++) {
                sum += L[k][s] * U[s][j];
            }
            U[k][j] = A[k][j] - sum;
        }

        for (int i = k; i < n; i++) {
            if (k == i) {
                L[i][k] = 1.0;
            }
            else {
                double sum = 0.0;
                for (int s = 0; s < k; s++) {
                    sum += L[i][s] * U[s][k];
                }
                if (U[k][k] == 0.0) return false;
                L[i][k] = (A[i][k] - sum) / U[k][k];
            }
        }
    }
    return true;
}

std::vector<double> podstawianie_w_przod(const std::vector<std::vector<double>>& L, const std::vector<double>& b, int n) {
    std::vector<double> z(n, 0.0);
    for (int i = 0; i < n; i++) {
        double sum = 0.0;
        for (int j = 0; j < i; j++) {
            sum += L[i][j] * z[j];
        }
        z[i] = b[i] - sum;
    }
    return z;
}

std::vector<double> podstawianie_wstecz(const std::vector<std::vector<double>>& U, const std::vector<double>& z, int n) {
    std::vector<double> x(n, 0.0);
    for (int i = n - 1; i >= 0; i--) {
        double sum = 0.0;
        for (int j = i + 1; j < n; j++) {
            sum += U[i][j] * x[j];
        }
        if (std::abs(U[i][i]) < EPSILON) return {};
        x[i] = (z[i] - sum) / U[i][i];
    }
    return x;
}

std::vector<double> rozwiaz_LU(const std::vector<std::vector<double>>& L, const std::vector<std::vector<double>>& U, const std::vector<double>& b, int n) {
    std::vector<double> z = podstawianie_w_przod(L, b, n);
    std::vector<double> x = podstawianie_wstecz(U, z, n);
    return x;
}

std::vector<std::vector<double>> mnoz_macierze(const std::vector<std::vector<double>>& L, const std::vector<std::vector<double>>& U, int n) {
    std::vector<std::vector<double>> wynik(n, std::vector<double>(n, 0.0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                wynik[i][j] += L[i][k] * U[k][j];
            }
        }
    }
    return wynik;
}

bool sprawdzenie(int N, const std::vector<std::vector<double>>& A, const std::vector<double>& b, const std::vector<double>& x) {
    bool poprawne = true;
    for (int i = 0; i < N; i++) {
        double suma = 0.0;
        for (int j = 0; j < N; j++) {
            suma += A[i][j] * x[j];
        }
        double roznica = std::fabs(suma - b[i]);
        if (roznica > EPSILON) {
            poprawne = false;
        }
    }
    return poprawne;
}
