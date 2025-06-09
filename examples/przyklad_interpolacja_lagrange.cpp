#include "pch.h"
#include "interpolacja_lagrange.h"
#include <iostream>


int main() {
    std::vector<Wezel> punkty = {
        {0.0, 1.0},
        {1.0, 3.0},
        {2.0, 2.0}
    };

    double x;
    std::cout << "Podaj x, dla którego chcesz obliczyæ wartoœæ wielomianu interpolacyjnego: ";
    std::cin >> x;

    double wynik = interpolacja_lagrange(punkty, x);
    std::cout << "W(x) = " << wynik << std::endl;

    return 0;
}