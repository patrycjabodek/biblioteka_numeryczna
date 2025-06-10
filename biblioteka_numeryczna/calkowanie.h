#pragma once
#include <vector>
#include <functional>

/**
 * @brief Oblicza przybli¿on¹ wartoœæ ca³ki z wielomianu metod¹ prostok¹tów
 *
 * @param wspolczynniki     Wektor wspó³czynników wielomianu (a0, a1, ..., an)
 * @param a                 Pocz¹tek przedzia³u ca³kowania
 * @param b                 Koniec przedzia³u ca³kowania
 * @param n                 Liczba podprzedzia³ów
 *
 * @return double           Przybli¿ona wartoœæ ca³ki
 */
double metoda_prostokatow(const std::vector<double>& wspolczynniki, double a, double b, int n);

/**
 * @brief Oblicza przybli¿on¹ wartoœæ ca³ki z wielomianu metod¹ trapezów
 */
double metoda_trapezow(const std::vector<double>& wspolczynniki, double a, double b, int n);

/**
 * @brief Oblicza przybli¿on¹ wartoœæ ca³ki z wielomianu metod¹ Simpsona
 */
double metoda_simpsona(const std::vector<double>& wspolczynniki, double a, double b, int n);

/**
 * @brief Oblicza przybli¿on¹ wartoœæ ca³ki z funkcji f(x) metod¹ prostok¹tów
 *
 * Funkcja f(x) powinna byæ wczeœniej zdefiniowana globalnie (np. `double funkcja(double x)`)
 */
double metoda_prostokatow_funkcja(double a, double b, int n);

/**
 * @brief Oblicza przybli¿on¹ wartoœæ ca³ki z funkcji f(x) metod¹ trapezów
 */
double metoda_trapezow_funkcja(double a, double b, int n);

/**
 * @brief Oblicza przybli¿on¹ wartoœæ ca³ki z funkcji f(x) metod¹ Simpsona
 *
 * @note Liczba podprzedzia³ów `n` powinna byæ parzysta (jeœli nie jest, funkcja j¹ zwiêksza)
 */
double metoda_simpsona_funkcja(double a, double b, int n);

/**
 * @brief Oblicza wartoœæ wielomianu w punkcie x za pomoc¹ schematu Hornera
 *
 * @param wspolczynniki     Wektor wspó³czynników wielomianu
 * @param x                 Punkt, w którym liczona jest wartoœæ
 *
 * @return double           Wartoœæ wielomianu w punkcie x
 */
double oblicz_schemat_hornera(const std::vector<double>& wspolczynniki, double x);

/**
 * @brief Oblicza b³¹d bezwzglêdny pomiêdzy wartoœci¹ obliczon¹ a dok³adn¹
 *
 * @param obliczona         Wynik przybli¿ony
 * @param dokladna          Wynik dok³adny (referencyjny)
 *
 * @return double           Wartoœæ b³êdu bezwzglêdnego
 */
double oblicz_blad(double obliczona, double dokladna);

/**
 * @brief Oblicza ca³kê funkcji f(x) na przedziale [a, b] metod¹ Gaussa-Legendre'a
 *
 * @param f                 Funkcja podca³kowa f(x)
 * @param a                 Pocz¹tek przedzia³u ca³kowania
 * @param b                 Koniec przedzia³u ca³kowania
 * @param l_wezlow          Liczba wêz³ów (dopuszczalne: 2, 3, 4)
 * @param l_podprzedzialow  Liczba podprzedzia³ów (dzieli przedzia³ [a, b] na mniejsze fragmenty)
 *
 * @return double           Przybli¿ona wartoœæ ca³ki
 *
 * @throws std::invalid_argument  Jeœli l_wezlow nie nale¿y do {2, 3, 4} lub l_podprzedzialow <= 0
 */
double gauss_legendre(std::function<double(double)> f, double a, double b, int l_wezlow, int l_podprzedzialow);
