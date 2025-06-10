#pragma once
#include <vector>
#include <functional>
#include <string>

/// @brief Metoda Eulera do rozwi�zywania r�wnania r�niczkowego pierwszego rz�du T' = f(T, t).
/// 
/// @param T0 Warto�� pocz�tkowa T(0).
/// @param t_end Koniec przedzia�u czasowego.
/// @param h Krok ca�kowania.
/// @param f Funkcja f(T, t), pochodna T wzgl�dem t.
/// @return Wektor przybli�onych warto�ci T w kolejnych krokach czasowych.
std::vector<double> metodaEuler(
    double T0, double t_end, double h,
    std::function<double(double, double)> f);

/// @brief Metoda Heuna (poprawiona Euler) do rozwi�zywania r�wnania T' = f(T, t).
/// 
/// @param T0 Warto�� pocz�tkowa T(0).
/// @param t_end Koniec przedzia�u czasowego.
/// @param h Krok ca�kowania.
/// @param f Funkcja f(T, t), pochodna T wzgl�dem t.
/// @return Wektor przybli�onych warto�ci T w kolejnych krokach czasowych.
std::vector<double> metodaHeuna(
    double T0, double t_end, double h,
    std::function<double(double, double)> f);

/// @brief Metoda punktu �rodkowego (Midpoint) do rozwi�zywania r�wnania T' = f(T, t).
/// 
/// @param T0 Warto�� pocz�tkowa T(0).
/// @param t_end Koniec przedzia�u czasowego.
/// @param h Krok ca�kowania.
/// @param f Funkcja f(T, t), pochodna T wzgl�dem t.
/// @return Wektor przybli�onych warto�ci T w kolejnych krokach czasowych.
std::vector<double> metodaMidpoint(
    double T0, double t_end, double h,
    std::function<double(double, double)> f);

/// @brief Metoda Rungego-Kutty 4. rz�du (RK4) do rozwi�zywania r�wnania T' = f(T, t).
/// 
/// @param T0 Warto�� pocz�tkowa T(0).
/// @param t_end Koniec przedzia�u czasowego.
/// @param h Krok ca�kowania.
/// @param f Funkcja f(T, t), pochodna T wzgl�dem t.
/// @return Wektor przybli�onych warto�ci T w kolejnych krokach czasowych.
std::vector<double> metodaRK4(
    double T0, double t_end, double h,
    std::function<double(double, double)> f);

/// @brief Oblicza b��d �redniokwadratowy (RMSE) pomi�dzy wektorem przybli�onych warto�ci a funkcj� dok�adn�.
/// 
/// @param przybl Wektor przybli�onych warto�ci.
/// @param h Krok czasowy.
/// @param dokladna Funkcja dok�adna T(t), s�u��ca jako odniesienie.
/// @return Warto�� b��du RMSE.
double obliczRMSE(
    const std::vector<double>& przybl,
    double h,
    std::function<double(double)> dokladna);

/// @brief Wypisuje krzyw� ch�odzenia (warto�ci temperatury w czasie).
/// 
/// @param temp Wektor temperatur w kolejnych chwilach czasu.
/// @param h Krok czasowy.
/// @param metoda Nazwa metody numerycznej, kt�ra zosta�a u�yta.
void wypiszKrzywa(
    const std::vector<double>& temp,
    double h,
    const std::string& metoda);
