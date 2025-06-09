#include "pch.h"
#include "gauss.h"
#include <iostream>
#include <cmath>
#include <iomanip>


const double EPSILON = 1e-10;

void wyswietl_macierz(std::vector<std::vector<double>> macierz, std::vector<double> b) {
    int n = macierz.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << std::setw(10) << macierz[i][j] << " ";
        }
        std::cout << "| " << std::setw(10) << b[i] << std::endl;
    }
    std::cout << "\n";
}

bool eliminacja_gaussa(int N, std::vector<std::vector<double>>& A, std::vector<double>& b, std::vector<double>& x) {
    for (int k = 0; k < N; k++) {
        int max_wiersz = k;
        double max_wart = std::abs(A[k][k]);

        for (int wiersz = k + 1; wiersz < N; wiersz++) {
            if (std::abs(A[wiersz][k]) > max_wart) {
                max_wart = std::abs(A[wiersz][k]);
                max_wiersz = wiersz;
            }
        }

        if (max_wart < EPSILON) {
            std::cerr << "Uklad jest liniowo zalezny\n";
            return false;
        }

        if (max_wiersz != k) {
            std::swap(A[k], A[max_wiersz]);
            std::swap(b[k], b[max_wiersz]);
        }

        for (int i = k + 1; i < N; i++) {
            double wsp = A[i][k] / A[k][k];
            for (int j = k; j < N; j++) {
                A[i][j] -= wsp * A[k][j];
                if (std::abs(A[i][j]) < EPSILON) A[i][j] = 0.0;
            }
            b[i] -= wsp * b[k];
            if (std::abs(b[i]) < EPSILON) b[i] = 0.0;
        }
    }

    x.resize(N);
    for (int i = N - 1; i >= 0; i--) {
        double suma = 0.0;
        for (int j = i + 1; j < N; j++) {
            suma += A[i][j] * x[j];
        }
        x[i] = (b[i] - suma) / A[i][i];
    }
    return true;
}

