#include "rownania_rozniczkowe.h"
#include <iostream>
#include <cmath>

int main() {
    double T0 = 2021.0;
    double alfa = 1e-12;
    double beta = 0.0;
    double t_end = 2021.0;

    auto f = [alfa, beta](double T, double t) {
        return -alfa * (std::pow(T, 4) - beta);
        };

    auto dokladna = [](double t) {
        return 20210000.0 / std::pow(1000000000000.0 + 24763965783.0 * t, 1.0 / 3.0);
        };

    std::vector<double> kroki = { 50.0, 25.0, 10.0 };

    for (double h : kroki) {
        auto T_euler = metodaEuler(T0, t_end, h, f);
        auto T_heun = metodaHeuna(T0, t_end, h, f);
        auto T_mid = metodaMidpoint(T0, t_end, h, f);
        auto T_rk4 = metodaRK4(T0, t_end, h, f);

        std::cout << "h = " << h << ":\n";
        std::cout << "Euler RMSE   : " << obliczRMSE(T_euler, h, dokladna) << "\n";
        std::cout << "Heun RMSE    : " << obliczRMSE(T_heun, h, dokladna) << "\n";
        std::cout << "Midpoint RMSE: " << obliczRMSE(T_mid, h, dokladna) << "\n";
        std::cout << "RK4 RMSE     : " << obliczRMSE(T_rk4, h, dokladna) << "\n";

        wypiszKrzywa(T_rk4, h, "RK4");
    }

    return 0;
}
