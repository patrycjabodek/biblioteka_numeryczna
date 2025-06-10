#pragma once
#include <vector>

/**
 * @brief Rozwi¹zuje uk³ad równañ liniowych A * x = b metod¹ eliminacji Gaussa z wyborem elementu g³ównego
 *
 * @param N     Rozmiar macierzy (liczba równañ i zmiennych)
 * @param A     Macierz wspó³czynników (n x n), zostaje zmodyfikowana w trakcie obliczeñ
 * @param b     Wektor wyrazów wolnych, zostaje zmodyfikowany w trakcie obliczeñ
 * @param x     Wektor wynikowy – rozwi¹zanie uk³adu równañ
 *
 * @return true     Jeœli uk³ad ma jednoznaczne rozwi¹zanie
 * @return false    Jeœli uk³ad jest osobliwy (np. ma nieskoñczenie wiele lub brak rozwi¹zañ)
 */
bool eliminacja_gaussa(int N,
    std::vector<std::vector<double>>& A,
    std::vector<double>& b,
    std::vector<double>& x);

/**
 * @brief Wyœwietla rozszerzon¹ macierz uk³adu równañ (macierz A oraz wektor b)
 *
 * @param macierz     Macierz wspó³czynników (A)
 * @param b           Wektor wyrazów wolnych
 */
void wyswietl_macierz(std::vector<std::vector<double>> macierz,
    std::vector<double> b);
