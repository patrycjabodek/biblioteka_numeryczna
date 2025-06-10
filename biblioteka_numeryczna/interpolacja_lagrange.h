#pragma once
#include <vector>

/**
 * @brief Struktura reprezentuj¹ca wêze³ interpolacyjny
 *
 * @param xi   Wspó³rzêdna x punktu (argument)
 * @param fxi  Wartoœæ funkcji w tym punkcie (wartoœæ)
 */

struct Wezel {
    double xi;   
    double fxi;  
};

/**
 * @brief Oblicza wartoœæ wielomianu interpolacyjnego Lagrange'a w punkcie x
 *
 * @param punkty     Wektor wêz³ów interpolacyjnych (xi, f(xi))
 * @param x          Punkt, w którym ma byæ obliczona wartoœæ interpolacji
 *
 * @return double    Przybli¿ona wartoœæ funkcji interpoluj¹cej w punkcie x
 */
double interpolacja_lagrange(const std::vector<Wezel>& punkty, double x);
