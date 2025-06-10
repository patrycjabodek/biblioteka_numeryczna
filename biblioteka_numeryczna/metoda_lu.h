#pragma once
#include <vector>

/// @brief Wykonuje rozk�ad LU macierzy A, tj. znajduje macierze L i U takie, �e A = L * U.
/// 
/// @param A Macierz wej�ciowa A (n x n), dla kt�rej chcemy znale�� rozk�ad LU.
/// @param L Macierz dolna tr�jk�tna L (n x n), wynik rozk�adu.
/// @param U Macierz g�rna tr�jk�tna U (n x n), wynik rozk�adu.
/// @param n Rozmiar macierzy (n x n).
/// @return true, je�li rozk�ad LU powi�d� si�; false, je�li nie (np. dzielenie przez zero).
bool metodaLU(const std::vector<std::vector<double>>& A, std::vector<std::vector<double>>& L, std::vector<std::vector<double>>& U, int n);

/// @brief Rozwi�zuje uk�ad r�wna� Ax = b, gdzie A = L * U, przy u�yciu wcze�niej obliczonych macierzy L i U.
/// 
/// @param L Macierz dolna tr�jk�tna L (n x n).
/// @param U Macierz g�rna tr�jk�tna U (n x n).
/// @param b Wektor wyraz�w wolnych b (n-elementowy).
/// @param n Rozmiar uk�adu.
/// @return Wektor x b�d�cy rozwi�zaniem uk�adu.
std::vector<double> rozwiaz_LU(const std::vector<std::vector<double>>& L, const std::vector<std::vector<double>>& U, const std::vector<double>& b, int n);

/// @brief Rozwi�zuje uk�ad r�wna� Lz = b metod� podstawiania w prz�d.
/// 
/// @param L Macierz dolna tr�jk�tna L (n x n).
/// @param b Wektor wyraz�w wolnych b (n-elementowy).
/// @param n Rozmiar uk�adu.
/// @return Wektor z b�d�cy rozwi�zaniem uk�adu Lz = b.
std::vector<double> podstawianie_w_przod(const std::vector<std::vector<double>>& L, const std::vector<double>& b, int n);

/// @brief Rozwi�zuje uk�ad r�wna� Ux = z metod� podstawiania wstecz.
/// 
/// @param U Macierz g�rna tr�jk�tna U (n x n).
/// @param z Wektor z (n-elementowy), wynik wcze�niejszego podstawienia w prz�d.
/// @param n Rozmiar uk�adu.
/// @return Wektor x b�d�cy rozwi�zaniem uk�adu Ux = z.
std::vector<double> podstawianie_wstecz(const std::vector<std::vector<double>>& U, const std::vector<double>& z, int n);

/// @brief Sprawdza poprawno�� rozwi�zania uk�adu r�wna� Ax = b.
/// 
/// @param N Rozmiar macierzy A i wektor�w b, x.
/// @param A Macierz wsp�czynnik�w A (N x N).
/// @param b Wektor wyraz�w wolnych b (N-elementowy).
/// @param x Wektor rozwi�zania x (N-elementowy).
/// @return true, je�li rozwi�zanie jest poprawne (Ax = b); false w przeciwnym razie.
bool sprawdzenie(int N, const std::vector<std::vector<double>>& A, const std::vector<double>& b, const std::vector<double>& x);

/// @brief Mno�y macierze L i U (L * U).
/// 
/// @param L Macierz dolna tr�jk�tna (n x n).
/// @param U Macierz g�rna tr�jk�tna (n x n).
/// @param n Rozmiar macierzy.
/// @return Wynikowa macierz (n x n) b�d�ca iloczynem L i U.
std::vector<std::vector<double>> mnoz_macierze(const std::vector<std::vector<double>>& L, const std::vector<std::vector<double>>& U, int n);

/// @brief Wy�wietla macierz w konsoli.
/// 
/// @param macierz Macierz do wy�wietlenia.
void wyswietl_macierz(const std::vector<std::vector<double>>& macierz);