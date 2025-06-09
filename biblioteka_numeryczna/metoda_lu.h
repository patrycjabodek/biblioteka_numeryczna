#pragma once
#include <vector>

// Rozk³ad LU
bool metodaLU(const std::vector<std::vector<double>>& A, std::vector<std::vector<double>>& L, std::vector<std::vector<double>>& U, int n);

// Rozwi¹zanie uk³adu LU
std::vector<double> rozwiaz_LU(const std::vector<std::vector<double>>& L, const std::vector<std::vector<double>>& U, const std::vector<double>& b, int n);

// Podstawianie w przód i wstecz
std::vector<double> podstawianie_w_przod(const std::vector<std::vector<double>>& L, const std::vector<double>& b, int n);
std::vector<double> podstawianie_wstecz(const std::vector<std::vector<double>>& U, const std::vector<double>& z, int n);

// Sprawdzenie poprawnoœci rozwi¹zania
bool sprawdzenie(int N, const std::vector<std::vector<double>>& A, const std::vector<double>& b, const std::vector<double>& x);

// Mno¿enie macierzy L * U
std::vector<std::vector<double>> mnoz_macierze(const std::vector<std::vector<double>>& L, const std::vector<std::vector<double>>& U, int n);

// Wypisanie macierzy 
void wyswietl_macierz(const std::vector<std::vector<double>>& macierz);
