#pragma once
#include <vector>

struct Wezel {
    double xi;   // wsp�rz�dna x
    double fxi;  // warto�� funkcji w tym punkcie
};

// Oblicza warto�� wielomianu interpolacyjnego Lagrange'a w punkcie x
double interpolacja_lagrange(const std::vector<Wezel>& punkty, double x);
