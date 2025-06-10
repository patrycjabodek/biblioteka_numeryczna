#pragma once
#include <vector>

/**
 * @brief Rozwi�zuje uk�ad r�wna� liniowych A * x = b metod� eliminacji Gaussa z wyborem elementu g��wnego
 *
 * @param N     Rozmiar macierzy (liczba r�wna� i zmiennych)
 * @param A     Macierz wsp�czynnik�w (n x n), zostaje zmodyfikowana w trakcie oblicze�
 * @param b     Wektor wyraz�w wolnych, zostaje zmodyfikowany w trakcie oblicze�
 * @param x     Wektor wynikowy � rozwi�zanie uk�adu r�wna�
 *
 * @return true     Je�li uk�ad ma jednoznaczne rozwi�zanie
 * @return false    Je�li uk�ad jest osobliwy (np. ma niesko�czenie wiele lub brak rozwi�za�)
 */
bool eliminacja_gaussa(int N,
    std::vector<std::vector<double>>& A,
    std::vector<double>& b,
    std::vector<double>& x);

/**
 * @brief Wy�wietla rozszerzon� macierz uk�adu r�wna� (macierz A oraz wektor b)
 *
 * @param macierz     Macierz wsp�czynnik�w (A)
 * @param b           Wektor wyraz�w wolnych
 */
void wyswietl_macierz(std::vector<std::vector<double>> macierz,
    std::vector<double> b);
