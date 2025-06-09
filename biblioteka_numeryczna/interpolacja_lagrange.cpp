#include "pch.h"
#include "interpolacja_lagrange.h"



double interpolacja_lagrange(const std::vector<Wezel>& punkty, double x) {
    double fx = 0;
    int n = punkty.size();
    for (int i = 0; i < n; i++) {
        double lx = 1;
        for (int j = 0; j < n; j++) {
            if (i != j) {
                lx *= (x - punkty[j].xi) / (punkty[i].xi - punkty[j].xi);
            }
        }
        fx += punkty[i].fxi * lx;
    }
    return fx;
}