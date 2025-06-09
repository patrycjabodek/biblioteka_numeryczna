#pragma once
#include <vector>

bool eliminacja_gaussa(int N, std::vector<std::vector<double>>& A, std::vector<double>& b, std::vector<double>& x);
void wyswietl_macierz(std::vector<std::vector<double>> macierz, std::vector<double> b);