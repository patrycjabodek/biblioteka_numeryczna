#include "pch.h"
#include "rozniczkowanie.h"

double rozniczka_1_rzedu(double (*f)(double), double x, double h) {
    return (f(x + h) - f(x - h)) / (2.0 * h);
}

double rozniczka_2_rzedu(double (*f)(double), double x, double h) {
    return (f(x + h) - 2.0 * f(x) + f(x - h)) / (h * h);
}