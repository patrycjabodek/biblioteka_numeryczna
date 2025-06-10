#pragma once
#include <vector>

/**
 * @brief Oblicza wsp�czynniki wielomianu interpolacyjnego Newtona 
 *
 * @param xi     Wektor wsp�rz�dnych x w�z��w interpolacyjnych 
 * @param fxi    Wektor warto�ci funkcji f(xi) w w�z�ach
 *
 * @return std::vector<double>    Wektor wsp�czynnik�w a0, a1, ..., an dla wielomianu Newtona
 *                                opartych na dzielonych r�nicach
 */
std::vector<double> oblicz_wspolczynniki_newton(const std::vector<double>& xi,
    const std::vector<double>& fxi);

/**
 * @brief Oblicza warto�� wielomianu Newtona w punkcie x
 *
 * @param wspolczynniki   Wektor wsp�czynnik�w (uzyskany z dzielonych r�nic)
 * @param xi              Wektor w�z��w interpolacyjnych (xi[0], ..., xi[n])
 * @param x               Punkt, w kt�rym chcemy obliczy� warto�� wielomianu
 *
 * @return double         Warto�� wielomianu Newtona w punkcie x
 */
double interpolacja_newton(const std::vector<double>& wspolczynniki,
    const std::vector<double>& xi,
    double x);
