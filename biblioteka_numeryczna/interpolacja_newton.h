#pragma once
#include <vector>

// Oblicza wsp�czynniki dla wielomianu Newtona
std::vector<double> oblicz_wspolczynniki_newton(const std::vector<double>& xi, const std::vector<double>& fxi);

// Oblicza warto�� wielomianu Newtona w punkcie x
double interpolacja_newton(const std::vector<double>& wspolczynniki, const std::vector<double>& xi, double x);
