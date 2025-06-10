#include "pch.h"
#include "gtest/gtest.h"
#include "interpolacja_newton.h"
#include <vector>
#include <limits> 

// --- Test 1: Przypadek poprawny  ---
// Ten test sprawdza, czy ca�y proces (obliczenie wsp�czynnik�w, 
// a nast�pnie interpolacja) daje poprawny wynik dla znanego wielomianu.
TEST(NewtonInterpolacjaTest, PoprawnyWynikDlaNowegoPunktu) {
    // U�ywamy punkt�w z paraboli y = x^2: (-1, 1), (0, 0), (2, 4)
    std::vector<double> xi = { -1.0, 0.0, 2.0 };
    std::vector<double> fxi = { 1.0, 0.0, 4.0 };

    // B�dziemy interpolowa� w punkcie x=3. Oczekujemy wyniku y = 3^2 = 9.
    double x_do_obliczenia = 3.0;
    double oczekiwany_wynik = 9.0;

    // 1. Oblicz wsp�czynniki Newtona
    std::vector<double> wspolczynniki = oblicz_wspolczynniki_newton(xi, fxi);
    // 2. U�yj wsp�czynnik�w do obliczenia warto�ci w nowym punkcie
    double wynik_interpolacji = interpolacja_newton(wspolczynniki, xi, x_do_obliczenia);

    // Sprawdzenie, czy ko�cowy wynik jest zgodny z oczekiwaniami
    ASSERT_NEAR(wynik_interpolacji, oczekiwany_wynik, 1e-9);
}


// --- Test 2: Przypadek b��dny---
// Ten test sprawdza zachowanie funkcji, gdy dostanie zduplikowane w�z�y 'xi',
// co musi prowadzi� do dzielenia przez zero w oryginalnym kodzie.
TEST(NewtonWspolczynnikiTest, BlednyPrzypadek_ZduplikowaneWezlyDajaNieskonczonosc) {
   
    // Wektor 'xi' zawiera dwa takie same w�z�y (x = 1.0), co spowoduje b��d.
    std::vector<double> xi_z_bledem = { 1.0, 5.0, 1.0 };
    std::vector<double> fxi = { 10.0, 20.0, 30.0 };

    std::vector<double> obliczone_wspolczynniki = oblicz_wspolczynniki_newton(xi_z_bledem, fxi);

    //Sprawdzenie, czy w wyniku pojawi�a si� niesko�czono��

    bool znaleziono_nieskonczonosc = false;
    for (double wsp : obliczone_wspolczynniki) {
        if (std::isinf(wsp)) {
            znaleziono_nieskonczonosc = true;
            break;
        }
    }
    ASSERT_TRUE(znaleziono_nieskonczonosc);
}