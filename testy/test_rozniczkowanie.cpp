#include "pch.h"
#include "gtest/gtest.h"
#include <cmath> 
#include "rozniczkowanie.h" 



// Prosta funkcja kwadratowa f(x) = x^2, kt�rej pochodne s� �atwe do obliczenia analitycznie.
// f'(x) = 2x
// f''(x) = 2
double funkcja_kwadratowa(double x) {
    return x * x;
}

// TEST 1: Przypadek poprawny
TEST(RozniczkowanieTest, PoprawnieObliczaPochodne) {
    // Przygotowanie danych testowych
    const double x = 5.0;           // Punkt, w kt�rym liczymy pochodn�
    const double h = 1e-5;          // krok
    const double tolerancja = 1e-4;  // Akceptowalny b��d dla przybli�enia numerycznego

    // Analitycznie obliczone, oczekiwane warto�ci
    const double oczekiwana_pochodna_1_rzedu = 10.0; // f'(5) = 2*5 = 10
    const double oczekiwana_pochodna_2_rzedu = 2.0;  // f''(x) = 2

    // Wywo�anie testowanych funkcji
    const double wynik_1_rzedu = rozniczka_1_rzedu(funkcja_kwadratowa, x, h);
    const double wynik_2_rzedu = rozniczka_2_rzedu(funkcja_kwadratowa, x, h);

    //Sprawdzenie wynik�w
    EXPECT_NEAR(wynik_1_rzedu, oczekiwana_pochodna_1_rzedu, tolerancja);
    EXPECT_NEAR(wynik_2_rzedu, oczekiwana_pochodna_2_rzedu, tolerancja);
}

// TEST 2: Przypadek b��dny
// sprawdzamy czy funkcje zachowuj� si� w przewidywalny spos�b (zwracaj� NaN),
//      gdy krok h = 0, co prowadzi do dzielenia przez zero.
TEST(RozniczkowanieTest, ZwracaNaNdlaKrokuHRownegoZero) {
    //Przygotowanie danych testowych
    const double x = 5.0;
    const double h = 0.0; // Kluczowy parametr powoduj�cy b��d

    //Wywo�anie testowanych funkcji z b��dnym parametrem
    const double wynik_1_rzedu = rozniczka_1_rzedu(funkcja_kwadratowa, x, h);
    const double wynik_2_rzedu = rozniczka_2_rzedu(funkcja_kwadratowa, x, h);

    // Sprawdzenie, czy wynikiem jest NaN
    // Dzielenie 0.0 / 0.0 daje NaN.
    EXPECT_TRUE(std::isnan(wynik_1_rzedu));
    EXPECT_TRUE(std::isnan(wynik_2_rzedu));
}