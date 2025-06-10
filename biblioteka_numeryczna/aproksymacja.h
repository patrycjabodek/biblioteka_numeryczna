#pragma once
#include <vector>
#include <functional>

/**
 * @brief Aproksymuje funkcj� f(x) na przedziale [a, b] za pomoc� wielomianu stopnia `stopien`
 *
 * @param stopien           Stopie� wielomianu aproksymuj�cego
 * @param a                 Pocz�tek przedzia�u aproksymacji
 * @param b                 Koniec przedzia�u aproksymacji
 * @param f                 Funkcja f(x), kt�r� chcemy aproksymowa� (przekazana jako std::function)
 *
 * @return std::vector<double> Wektor wsp�czynnik�w wielomianu aproksymuj�cego (od wyrazu wolnego)
 *         czyli: a[0] + a[1] * x + a[2] * x^2 + ... + a[n] * x^n
 */
std::vector<double> aproksymacja(int stopien, double a, double b, std::function<double(double)> f);

/**
 * @brief Oblicza warto�� wielomianu aproksymuj�cego w punkcie x
 *
 * @param x                 Punkt, w kt�rym obliczana jest warto�� wielomianu
 * @param wspolczynniki     Wektor wsp�czynnik�w wielomianu (a[0], a[1], ..., a[n])
 *
 * @return double           Warto�� wielomianu w punkcie x
 */
double wielomian_aproksymujacy(double x, const std::vector<double>& wspolczynniki);
