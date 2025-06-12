#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <string>
#include <limits>

const double TOL = 1e-9;
const int MAX_ITER = 1000;
const double NaN = std::numeric_limits<double>::quiet_NaN();

/**
 * @brief Metoda bisekcji do znajdowania pierwiastka r�wnania f(x)=0.
 *
 * @param f Funkcja matematyczna f(x)
 * @param a Pocz�tek przedzia�u [a, b]
 * @param b Koniec przedzia�u [a, b]
 * @param historia Wektor do przechowywania kolejnych przybli�e� rozwi�zania
 * @return Przybli�ony pierwiastek funkcji
 */
double bisekcja(double (*f)(double), double a, double b, std::vector<double>& historia);

/**
 * @brief Metoda Newtona do znajdowania pierwiastka r�wnania f(x)=0.
 *
 * @param f Funkcja matematyczna f(x)
 * @param df Pochodna funkcji f(x); je�li analityczna = false, zostanie aproksymowana numerycznie
 * @param x0 Punkt startowy
 * @param historia Wektor do przechowywania kolejnych przybli�e� rozwi�zania
 * @param analityczna Czy u�ywa� analitycznej pochodnej (true) czy numerycznej (false)
 * @return Przybli�ony pierwiastek funkcji
 */
double newton(double (*f)(double), double (*df)(double), double x0, std::vector<double>& historia, bool analityczna);

/**
 * @brief Metoda siecznych do znajdowania pierwiastka f(x)=0.
 *
 * @param f Funkcja matematyczna f(x)
 * @param x0 Pierwsze przybli�enie
 * @param x1 Drugie przybli�enie
 * @param historia Wektor do przechowywania kolejnych przybli�e� rozwi�zania
 * @return Przybli�ony pierwiastek funkcji
 */
double siecznych(double (*f)(double), double x0, double x1, std::vector<double>& historia);

/**
 * @brief Metoda Regula Falsi do znajdowania pierwiastka f(x)=0.
 *
 * @param f Funkcja matematyczna f(x)
 * @param a Pocz�tek przedzia�u [a, b]
 * @param b Koniec przedzia�u [a, b]
 * @param epsilon Dok�adno�� zako�czenia iteracji
 * @param max_iter Maksymalna liczba iteracji
 * @param stop_condition Warunek zatrzymania: "value", "interval" lub "both"
 * @return Wektor par (x, f(x)) z ka�dej iteracji
 */
std::vector<std::pair<double, double>> regula_falsi(
    double (*f)(double),
    double a,
    double b,
    double epsilon,
    int max_iter,
    std::string stop_condition = "value"
);

/**
 * @brief Znajduje dok�adny pierwiastek najbli�szy danemu przybli�eniu.
 *
 * @param approx_root Przybli�ony pierwiastek
 * @param exact_roots Wektor znanych dok�adnych pierwiastk�w
 * @return Najbli�szy dok�adny pierwiastek (lub NaN je�li brak danych)
 */
double find_closest_exact_root(double approx_root, const std::vector<double>& exact_roots);