#pragma once
#include <vector>

/**
 * @brief Oblicza wspó³czynniki wielomianu interpolacyjnego Newtona 
 *
 * @param xi     Wektor wspó³rzêdnych x wêz³ów interpolacyjnych 
 * @param fxi    Wektor wartoœci funkcji f(xi) w wêz³ach
 *
 * @return std::vector<double>    Wektor wspó³czynników a0, a1, ..., an dla wielomianu Newtona
 *                                opartych na dzielonych ró¿nicach
 */
std::vector<double> oblicz_wspolczynniki_newton(const std::vector<double>& xi,
    const std::vector<double>& fxi);

/**
 * @brief Oblicza wartoœæ wielomianu Newtona w punkcie x
 *
 * @param wspolczynniki   Wektor wspó³czynników (uzyskany z dzielonych ró¿nic)
 * @param xi              Wektor wêz³ów interpolacyjnych (xi[0], ..., xi[n])
 * @param x               Punkt, w którym chcemy obliczyæ wartoœæ wielomianu
 *
 * @return double         Wartoœæ wielomianu Newtona w punkcie x
 */
double interpolacja_newton(const std::vector<double>& wspolczynniki,
    const std::vector<double>& xi,
    double x);
