#include <iostream>
#include <cmath>
#include "rozniczkowanie.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

double example_function(double x) {
    return std::sin(x); // f(x) = sin(x), f'(x) = cos(x)
}

int main() {
    double x = M_PI / 4; // 45 stopni
    double h = 1e-5;

    double d1 = rozniczka_1_rzedu(example_function, x, h);
    double d2 = rozniczka_2_rzedu(example_function, x, h);

    std::cout << "f'(x) = " << d1 << " (oczekiwane: " << std::cos(x) << ")" << std::endl;
    std::cout << "f''(x) = " << d2 << " (oczekiwane: " << -std::sin(x) << ")" << std::endl;

    return 0;
}
