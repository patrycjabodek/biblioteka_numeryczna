#pragma once
#include <vector>

/// @brief Wykonuje rozk³ad LU macierzy A, tj. znajduje macierze L i U takie, ¿e A = L * U.
/// 
/// @param A Macierz wejœciowa A (n x n), dla której chcemy znaleŸæ rozk³ad LU.
/// @param L Macierz dolna trójk¹tna L (n x n), wynik rozk³adu.
/// @param U Macierz górna trójk¹tna U (n x n), wynik rozk³adu.
/// @param n Rozmiar macierzy (n x n).
/// @return true, jeœli rozk³ad LU powiód³ siê; false, jeœli nie (np. dzielenie przez zero).
bool metodaLU(const std::vector<std::vector<double>>& A, std::vector<std::vector<double>>& L, std::vector<std::vector<double>>& U, int n);

/// @brief Rozwi¹zuje uk³ad równañ Ax = b, gdzie A = L * U, przy u¿yciu wczeœniej obliczonych macierzy L i U.
/// 
/// @param L Macierz dolna trójk¹tna L (n x n).
/// @param U Macierz górna trójk¹tna U (n x n).
/// @param b Wektor wyrazów wolnych b (n-elementowy).
/// @param n Rozmiar uk³adu.
/// @return Wektor x bêd¹cy rozwi¹zaniem uk³adu.
std::vector<double> rozwiaz_LU(const std::vector<std::vector<double>>& L, const std::vector<std::vector<double>>& U, const std::vector<double>& b, int n);

/// @brief Rozwi¹zuje uk³ad równañ Lz = b metod¹ podstawiania w przód.
/// 
/// @param L Macierz dolna trójk¹tna L (n x n).
/// @param b Wektor wyrazów wolnych b (n-elementowy).
/// @param n Rozmiar uk³adu.
/// @return Wektor z bêd¹cy rozwi¹zaniem uk³adu Lz = b.
std::vector<double> podstawianie_w_przod(const std::vector<std::vector<double>>& L, const std::vector<double>& b, int n);

/// @brief Rozwi¹zuje uk³ad równañ Ux = z metod¹ podstawiania wstecz.
/// 
/// @param U Macierz górna trójk¹tna U (n x n).
/// @param z Wektor z (n-elementowy), wynik wczeœniejszego podstawienia w przód.
/// @param n Rozmiar uk³adu.
/// @return Wektor x bêd¹cy rozwi¹zaniem uk³adu Ux = z.
std::vector<double> podstawianie_wstecz(const std::vector<std::vector<double>>& U, const std::vector<double>& z, int n);

/// @brief Sprawdza poprawnoœæ rozwi¹zania uk³adu równañ Ax = b.
/// 
/// @param N Rozmiar macierzy A i wektorów b, x.
/// @param A Macierz wspó³czynników A (N x N).
/// @param b Wektor wyrazów wolnych b (N-elementowy).
/// @param x Wektor rozwi¹zania x (N-elementowy).
/// @return true, jeœli rozwi¹zanie jest poprawne (Ax = b); false w przeciwnym razie.
bool sprawdzenie(int N, const std::vector<std::vector<double>>& A, const std::vector<double>& b, const std::vector<double>& x);

/// @brief Mno¿y macierze L i U (L * U).
/// 
/// @param L Macierz dolna trójk¹tna (n x n).
/// @param U Macierz górna trójk¹tna (n x n).
/// @param n Rozmiar macierzy.
/// @return Wynikowa macierz (n x n) bêd¹ca iloczynem L i U.
std::vector<std::vector<double>> mnoz_macierze(const std::vector<std::vector<double>>& L, const std::vector<std::vector<double>>& U, int n);

/// @brief Wyœwietla macierz w konsoli.
/// 
/// @param macierz Macierz do wyœwietlenia.
void wyswietl_macierz(const std::vector<std::vector<double>>& macierz);