#pragma once
#include <vector>
#include <functional>

/**
 * @brief Aproksymuje funkcjê f(x) na przedziale [a, b] za pomoc¹ wielomianu stopnia `stopien`
 *
 * @param stopien           Stopieñ wielomianu aproksymuj¹cego
 * @param a                 Pocz¹tek przedzia³u aproksymacji
 * @param b                 Koniec przedzia³u aproksymacji
 * @param f                 Funkcja f(x), któr¹ chcemy aproksymowaæ (przekazana jako std::function)
 *
 * @return std::vector<double> Wektor wspó³czynników wielomianu aproksymuj¹cego (od wyrazu wolnego)
 *         czyli: a[0] + a[1] * x + a[2] * x^2 + ... + a[n] * x^n
 */
std::vector<double> aproksymacja(int stopien, double a, double b, std::function<double(double)> f);

/**
 * @brief Oblicza wartoœæ wielomianu aproksymuj¹cego w punkcie x
 *
 * @param x                 Punkt, w którym obliczana jest wartoœæ wielomianu
 * @param wspolczynniki     Wektor wspó³czynników wielomianu (a[0], a[1], ..., a[n])
 *
 * @return double           Wartoœæ wielomianu w punkcie x
 */
double wielomian_aproksymujacy(double x, const std::vector<double>& wspolczynniki);
