#pragma once
#include <vector>
#include <functional>
#include <string>

/// @brief Metoda Eulera do rozwi¹zywania równania ró¿niczkowego pierwszego rzêdu T' = f(T, t).
/// 
/// @param T0 Wartoœæ pocz¹tkowa T(0).
/// @param t_end Koniec przedzia³u czasowego.
/// @param h Krok ca³kowania.
/// @param f Funkcja f(T, t), pochodna T wzglêdem t.
/// @return Wektor przybli¿onych wartoœci T w kolejnych krokach czasowych.
std::vector<double> metodaEuler(
    double T0, double t_end, double h,
    std::function<double(double, double)> f);

/// @brief Metoda Heuna (poprawiona Euler) do rozwi¹zywania równania T' = f(T, t).
/// 
/// @param T0 Wartoœæ pocz¹tkowa T(0).
/// @param t_end Koniec przedzia³u czasowego.
/// @param h Krok ca³kowania.
/// @param f Funkcja f(T, t), pochodna T wzglêdem t.
/// @return Wektor przybli¿onych wartoœci T w kolejnych krokach czasowych.
std::vector<double> metodaHeuna(
    double T0, double t_end, double h,
    std::function<double(double, double)> f);

/// @brief Metoda punktu œrodkowego (Midpoint) do rozwi¹zywania równania T' = f(T, t).
/// 
/// @param T0 Wartoœæ pocz¹tkowa T(0).
/// @param t_end Koniec przedzia³u czasowego.
/// @param h Krok ca³kowania.
/// @param f Funkcja f(T, t), pochodna T wzglêdem t.
/// @return Wektor przybli¿onych wartoœci T w kolejnych krokach czasowych.
std::vector<double> metodaMidpoint(
    double T0, double t_end, double h,
    std::function<double(double, double)> f);

/// @brief Metoda Rungego-Kutty 4. rzêdu (RK4) do rozwi¹zywania równania T' = f(T, t).
/// 
/// @param T0 Wartoœæ pocz¹tkowa T(0).
/// @param t_end Koniec przedzia³u czasowego.
/// @param h Krok ca³kowania.
/// @param f Funkcja f(T, t), pochodna T wzglêdem t.
/// @return Wektor przybli¿onych wartoœci T w kolejnych krokach czasowych.
std::vector<double> metodaRK4(
    double T0, double t_end, double h,
    std::function<double(double, double)> f);

/// @brief Oblicza b³¹d œredniokwadratowy (RMSE) pomiêdzy wektorem przybli¿onych wartoœci a funkcj¹ dok³adn¹.
/// 
/// @param przybl Wektor przybli¿onych wartoœci.
/// @param h Krok czasowy.
/// @param dokladna Funkcja dok³adna T(t), s³u¿¹ca jako odniesienie.
/// @return Wartoœæ b³êdu RMSE.
double obliczRMSE(
    const std::vector<double>& przybl,
    double h,
    std::function<double(double)> dokladna);

/// @brief Wypisuje krzyw¹ ch³odzenia (wartoœci temperatury w czasie).
/// 
/// @param temp Wektor temperatur w kolejnych chwilach czasu.
/// @param h Krok czasowy.
/// @param metoda Nazwa metody numerycznej, która zosta³a u¿yta.
void wypiszKrzywa(
    const std::vector<double>& temp,
    double h,
    const std::string& metoda);
