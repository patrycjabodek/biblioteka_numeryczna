#pragma once
#include <vector>
#include <functional>

/**
 * @brief Oblicza przybli�on� warto�� ca�ki z wielomianu metod� prostok�t�w
 *
 * @param wspolczynniki     Wektor wsp�czynnik�w wielomianu (a0, a1, ..., an)
 * @param a                 Pocz�tek przedzia�u ca�kowania
 * @param b                 Koniec przedzia�u ca�kowania
 * @param n                 Liczba podprzedzia��w
 *
 * @return double           Przybli�ona warto�� ca�ki
 */
double metoda_prostokatow(const std::vector<double>& wspolczynniki, double a, double b, int n);

/**
 * @brief Oblicza przybli�on� warto�� ca�ki z wielomianu metod� trapez�w
 */
double metoda_trapezow(const std::vector<double>& wspolczynniki, double a, double b, int n);

/**
 * @brief Oblicza przybli�on� warto�� ca�ki z wielomianu metod� Simpsona
 */
double metoda_simpsona(const std::vector<double>& wspolczynniki, double a, double b, int n);

/**
 * @brief Oblicza przybli�on� warto�� ca�ki z funkcji f(x) metod� prostok�t�w
 *
 * Funkcja f(x) powinna by� wcze�niej zdefiniowana globalnie (np. `double funkcja(double x)`)
 */
double metoda_prostokatow_funkcja(double a, double b, int n);

/**
 * @brief Oblicza przybli�on� warto�� ca�ki z funkcji f(x) metod� trapez�w
 */
double metoda_trapezow_funkcja(double a, double b, int n);

/**
 * @brief Oblicza przybli�on� warto�� ca�ki z funkcji f(x) metod� Simpsona
 *
 * @note Liczba podprzedzia��w `n` powinna by� parzysta (je�li nie jest, funkcja j� zwi�ksza)
 */
double metoda_simpsona_funkcja(double a, double b, int n);

/**
 * @brief Oblicza warto�� wielomianu w punkcie x za pomoc� schematu Hornera
 *
 * @param wspolczynniki     Wektor wsp�czynnik�w wielomianu
 * @param x                 Punkt, w kt�rym liczona jest warto��
 *
 * @return double           Warto�� wielomianu w punkcie x
 */
double oblicz_schemat_hornera(const std::vector<double>& wspolczynniki, double x);

/**
 * @brief Oblicza b��d bezwzgl�dny pomi�dzy warto�ci� obliczon� a dok�adn�
 *
 * @param obliczona         Wynik przybli�ony
 * @param dokladna          Wynik dok�adny (referencyjny)
 *
 * @return double           Warto�� b��du bezwzgl�dnego
 */
double oblicz_blad(double obliczona, double dokladna);

/**
 * @brief Oblicza ca�k� funkcji f(x) na przedziale [a, b] metod� Gaussa-Legendre'a
 *
 * @param f                 Funkcja podca�kowa f(x)
 * @param a                 Pocz�tek przedzia�u ca�kowania
 * @param b                 Koniec przedzia�u ca�kowania
 * @param l_wezlow          Liczba w�z��w (dopuszczalne: 2, 3, 4)
 * @param l_podprzedzialow  Liczba podprzedzia��w (dzieli przedzia� [a, b] na mniejsze fragmenty)
 *
 * @return double           Przybli�ona warto�� ca�ki
 *
 * @throws std::invalid_argument  Je�li l_wezlow nie nale�y do {2, 3, 4} lub l_podprzedzialow <= 0
 */
double gauss_legendre(std::function<double(double)> f, double a, double b, int l_wezlow, int l_podprzedzialow);
