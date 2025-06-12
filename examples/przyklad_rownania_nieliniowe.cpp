#include "pch.h"
#include "rownania_nieliniowe.h"

#include <iostream>
#include <iomanip> 
#include <vector>
#include <string>
#include <cmath>
#include <limits>


// Funkcja, dla której szukamy pierwiastka: f(x) = x^3 - x - 2
// Dok³adny pierwiastek to ok. 1.5213797068
double funkcja_testowa(double x) {
    return x * x * x - x - 2.0;
}

// Analityczna pochodna funkcji testowej: f'(x) = 3x^2 - 1
double pochodna_testowa(double x) {
    return 3.0 * x * x - 1.0;
}

int main() {
    // Ustawienie precyzji wypisywania liczb zmiennoprzecinkowych
    std::cout << std::fixed << std::setprecision(10);

    // Dok³adny pierwiastek naszej funkcji do porównania
    std::vector<double> dokladne_pierwiastki = { 1.5213797068 };

    double pierwiastek;
    std::vector<double> historia;

    std::cout << "====================================================\n";
    std::cout << "  Szukanie pierwiastka dla f(x) = x^3 - x - 2\n";
    std::cout << "====================================================\n\n";

    // --- Przyk³ad 1: Metoda Bisekcji ---
    std::cout << "--- PRZYKLAD: Metoda Bisekcji ---\n";
    double a_bisekcja = 1.0, b_bisekcja = 2.0;
    pierwiastek = bisekcja(funkcja_testowa, a_bisekcja, b_bisekcja, historia);

    if (!std::isnan(pierwiastek)) {
        std::cout << "Przedzial poczatkowy: [" << a_bisekcja << ", " << b_bisekcja << "]\n";
        std::cout << "Znaleziony pierwiastek: " << pierwiastek << "\n";
        double dokladny = find_closest_exact_root(pierwiastek, dokladne_pierwiastki);
        std::cout << "Blad absolutny:       " << std::abs(pierwiastek - dokladny) << "\n\n";

        std::cout << "Historia iteracji (Bisekcja):\n";
        for (size_t i = 0; i < historia.size(); ++i) {
            std::cout << "  Iter " << std::setw(3) << i << ": " << historia[i] << "\n";
        }
    }
    else {
        std::cout << "Metoda bisekcji nie zbiegla lub podano zly przedzial.\n";
    }
    std::cout << "\n----------------------------------------------------\n\n";

    // --- Przyk³ad 2: Metoda Newtona (pochodna analityczna) ---
    std::cout << "--- PRZYKLAD: Metoda Newtona (pochodna analityczna) ---\n";
    double x0_newton = 1.5;
    pierwiastek = newton(funkcja_testowa, pochodna_testowa, x0_newton, historia, true);

    if (!std::isnan(pierwiastek)) {
        std::cout << "Punkt startowy x0: " << x0_newton << "\n";
        std::cout << "Znaleziony pierwiastek: " << pierwiastek << "\n";
        double dokladny = find_closest_exact_root(pierwiastek, dokladne_pierwiastki);
        std::cout << "Blad absolutny:       " << std::abs(pierwiastek - dokladny) << "\n\n";

        std::cout << "Historia iteracji (Newton analityczna):\n";
        for (size_t i = 0; i < historia.size(); ++i) {
            std::cout << "  Iter " << std::setw(3) << i << ": " << historia[i] << "\n";
        }
    }
    else {
        std::cout << "Metoda Newtona (analityczna) nie zbiegla.\n";
    }
    std::cout << "\n----------------------------------------------------\n\n";

    // --- Przyk³ad 3: Metoda Newtona (pochodna numeryczna) ---
    std::cout << "--- PRZYKLAD: Metoda Newtona (pochodna numeryczna) ---\n";
    pierwiastek = newton(funkcja_testowa, nullptr, x0_newton, historia, false);

    if (!std::isnan(pierwiastek)) {
        std::cout << "Punkt startowy x0: " << x0_newton << "\n";
        std::cout << "Znaleziony pierwiastek: " << pierwiastek << "\n";
        double dokladny = find_closest_exact_root(pierwiastek, dokladne_pierwiastki);
        std::cout << "Blad absolutny:       " << std::abs(pierwiastek - dokladny) << "\n\n";

        std::cout << "Historia iteracji (Newton numeryczna):\n";
        for (size_t i = 0; i < historia.size(); ++i) {
            std::cout << "  Iter " << std::setw(3) << i << ": " << historia[i] << "\n";
        }
    }
    else {
        std::cout << "Metoda Newtona (numeryczna) nie zbiegla.\n";
    }
    std::cout << "\n----------------------------------------------------\n\n";

    // --- Przyk³ad 4: Metoda Siecznych ---
    std::cout << "--- PRZYKLAD: Metoda Siecznych ---\n";
    double x0_sieczne = 1.0, x1_sieczne = 2.0;
    pierwiastek = siecznych(funkcja_testowa, x0_sieczne, x1_sieczne, historia);

    if (!std::isnan(pierwiastek)) {
        std::cout << "Punkty startowe x0, x1: [" << x0_sieczne << ", " << x1_sieczne << "]\n";
        std::cout << "Znaleziony pierwiastek: " << pierwiastek << "\n";
        double dokladny = find_closest_exact_root(pierwiastek, dokladne_pierwiastki);
        std::cout << "Blad absolutny:       " << std::abs(pierwiastek - dokladny) << "\n\n";

        std::cout << "Historia iteracji (Siecznych):\n";
        for (size_t i = 0; i < historia.size(); ++i) {
            std::cout << "  Iter " << std::setw(3) << i << ": " << historia[i] << "\n";
        }
    }
    else {
        std::cout << "Metoda siecznych nie zbiegla.\n";
    }
    std::cout << "\n----------------------------------------------------\n\n";

    // --- Przyk³ad 5: Metoda Regula Falsi ---
    std::cout << "--- PRZYKLAD: Metoda Regula Falsi ---\n";
    double a_rf = 1.0, b_rf = 2.0;
    std::vector<std::pair<double, double>> wyniki_rf = regula_falsi(funkcja_testowa, a_rf, b_rf, TOL, MAX_ITER, "value");

    if (!wyniki_rf.empty()) {
        pierwiastek = wyniki_rf.back().first;
        std::cout << "Przedzial poczatkowy: [" << a_rf << ", " << b_rf << "]\n";
        std::cout << "Znaleziony pierwiastek: " << pierwiastek << "\n";
        double dokladny = find_closest_exact_root(pierwiastek, dokladne_pierwiastki);
        std::cout << "Blad absolutny:       " << std::abs(pierwiastek - dokladny) << "\n\n";

        std::cout << "Historia iteracji (Regula Falsi):\n";
        for (size_t i = 0; i < wyniki_rf.size(); ++i) {
            std::cout << "  Iter " << std::setw(3) << i << ": x = " << wyniki_rf[i].first << ", f(x) = " << wyniki_rf[i].second << "\n";
        }
    }
    else {
        std::cout << "Metoda Regula Falsi nie zbiegla lub podano zly przedzial.\n";
    }
    std::cout << "\n----------------------------------------------------\n\n";

    return 0;
}