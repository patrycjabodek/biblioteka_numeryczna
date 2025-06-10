#pragma once
#include <vector>

/**
 * @brief Struktura reprezentuj�ca w�ze� interpolacyjny
 *
 * @param xi   Wsp�rz�dna x punktu (argument)
 * @param fxi  Warto�� funkcji w tym punkcie (warto��)
 */

struct Wezel {
    double xi;   
    double fxi;  
};

/**
 * @brief Oblicza warto�� wielomianu interpolacyjnego Lagrange'a w punkcie x
 *
 * @param punkty     Wektor w�z��w interpolacyjnych (xi, f(xi))
 * @param x          Punkt, w kt�rym ma by� obliczona warto�� interpolacji
 *
 * @return double    Przybli�ona warto�� funkcji interpoluj�cej w punkcie x
 */
double interpolacja_lagrange(const std::vector<Wezel>& punkty, double x);
