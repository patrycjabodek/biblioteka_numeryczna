#pragma once
#include <vector>

struct Wezel {
    double xi;   // wspó³rzêdna x
    double fxi;  // wartoœæ funkcji w tym punkcie
};

// Oblicza wartoœæ wielomianu interpolacyjnego Lagrange'a w punkcie x
double interpolacja_lagrange(const std::vector<Wezel>& punkty, double x);
