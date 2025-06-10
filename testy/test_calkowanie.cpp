#include "pch.h"
#include "gtest/gtest.h"
#include "calkowanie.h"
#include <stdexcept> 
#include <vector>
#include <functional>


TEST(CalkowanieHornerTest, PustyWektorZwracaZero) {
    // ARRANGE: Pusty wektor wspó³czynników
    std::vector<double> wspolczynniki = {};

    // Sprawdzamy, czy wynikiem jest 0
    ASSERT_DOUBLE_EQ(oblicz_schemat_hornera(wspolczynniki, 123.0), 0.0);
}


// --- Testy dla  metoda_simpsona ---

TEST(CalkowanieSimpsonaTest, PoprawnyWynikDlaFunkcjiLiniowej) {
    // Testujemy na f(x) = 4x + 2. Ca³ka od 1 do 3.
    // Ca³ka oznaczona: [2x^2 + 2x] od 1 do 3 = (2*9+6) - (2*1+2) = 24 - 4 = 20.
    std::vector<double> wspolczynniki = { 2.0, 4.0 }; // 4x + 2
    double a = 1.0, b = 3.0;
    int n = 100; 
    double oczekiwany_wynik = 20.0;

    double wynik_obliczony = metoda_simpsona(wspolczynniki, a, b, n);

    // ASSERT: Sprawdzamy, czy wynik jest bardzo bliski dok³adnemu
    ASSERT_NEAR(wynik_obliczony, oczekiwany_wynik, 1e-9);
}

TEST(CalkowanieSimpsonaTest, RzucaWyjatekDlaNiepoprawnejLiczbyPrzedzialow) {
 
    std::vector<double> wspolczynniki = { 1.0 }; // Dowolny wielomian
    double a = 0.0, b = 1.0;

    //Sprawdzamy, czy funkcja rzuci wyj¹tek dla n=0 i n<0
    ASSERT_THROW(metoda_simpsona(wspolczynniki, a, b, 0), std::invalid_argument);
    ASSERT_THROW(metoda_simpsona(wspolczynniki, a, b, -10), std::invalid_argument);
}


// --- Testy dla metody Gaussa-Legendre'a ---

TEST(CalkowanieGaussLegendreTest, PoprawnyWynikDlaFunkcji) {
    // Ca³kujemy funkcjê f(x) = x^3 od 0 do 2.
    // Ca³ka oznaczona: [x^4 / 4] od 0 do 2 = (16/4) - 0 = 4.
    auto funkcja_do_calkowania = [](double x) { return x * x * x; };
    double a = 0.0, b = 2.0;
    int l_wezlow = 3;
    int l_podprzedzialow = 10;
    double oczekiwany_wynik = 4.0;

    
    double wynik_obliczony = gauss_legendre(funkcja_do_calkowania, a, b, l_wezlow, l_podprzedzialow);

    // ASSERT: Sprawdzamy, czy wynik jest bliski dok³adnemu
    ASSERT_NEAR(wynik_obliczony, oczekiwany_wynik, 1e-5);
}

TEST(CalkowanieGaussLegendreTest, RzucaWyjatekDlaNieobslugiwanejLiczbyWezlow) {
 
    auto funkcja_do_calkowania = [](double x) { return x; };
    double a = 0.0, b = 1.0;
    int l_podprzedzialow = 2;

    //  Sprawdzamy, czy rzucany jest wyj¹tek dla nieobs³ugiwanej liczby wêz³ów
    ASSERT_THROW(gauss_legendre(funkcja_do_calkowania, a, b, 1, l_podprzedzialow), std::invalid_argument);
    ASSERT_THROW(gauss_legendre(funkcja_do_calkowania, a, b, 5, l_podprzedzialow), std::invalid_argument);
}

TEST(CalkowanieGaussLegendreTest, RzucaWyjatekDlaNiepoprawnejLiczbyPodprzedzialow) {
   
    auto funkcja_do_calkowania = [](double x) { return x; };
    double a = 0.0, b = 1.0;
    int l_wezlow = 2;

    // Sprawdzamy, czy rzucany jest wyj¹tek dla niepoprawnej liczby podprzedzia³ów
    ASSERT_THROW(gauss_legendre(funkcja_do_calkowania, a, b, l_wezlow, 0), std::invalid_argument);
    ASSERT_THROW(gauss_legendre(funkcja_do_calkowania, a, b, l_wezlow, -5), std::invalid_argument);
}