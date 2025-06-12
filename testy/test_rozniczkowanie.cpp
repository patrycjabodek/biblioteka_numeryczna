#include "pch.h"
#include "gtest/gtest.h"
#include <cmath> 
#include "rozniczkowanie.h" 



// Prosta funkcja kwadratowa f(x) = x^2, której pochodne s¹ ³atwe do obliczenia analitycznie.
// f'(x) = 2x
// f''(x) = 2
double funkcja_kwadratowa(double x) {
    return x * x;
}

// TEST 1: Przypadek poprawny
TEST(RozniczkowanieTest, PoprawnieObliczaPochodne) {
    // Przygotowanie danych testowych
    const double x = 5.0;           // Punkt, w którym liczymy pochodn¹
    const double h = 1e-5;          // krok
    const double tolerancja = 1e-4;  // Akceptowalny b³¹d dla przybli¿enia numerycznego

    // Analitycznie obliczone, oczekiwane wartoœci
    const double oczekiwana_pochodna_1_rzedu = 10.0; // f'(5) = 2*5 = 10
    const double oczekiwana_pochodna_2_rzedu = 2.0;  // f''(x) = 2

    // Wywo³anie testowanych funkcji
    const double wynik_1_rzedu = rozniczka_1_rzedu(funkcja_kwadratowa, x, h);
    const double wynik_2_rzedu = rozniczka_2_rzedu(funkcja_kwadratowa, x, h);

    //Sprawdzenie wyników
    EXPECT_NEAR(wynik_1_rzedu, oczekiwana_pochodna_1_rzedu, tolerancja);
    EXPECT_NEAR(wynik_2_rzedu, oczekiwana_pochodna_2_rzedu, tolerancja);
}

// TEST 2: Przypadek b³êdny
// sprawdzamy czy funkcje zachowuj¹ siê w przewidywalny sposób (zwracaj¹ NaN),
//      gdy krok h = 0, co prowadzi do dzielenia przez zero.
TEST(RozniczkowanieTest, ZwracaNaNdlaKrokuHRownegoZero) {
    //Przygotowanie danych testowych
    const double x = 5.0;
    const double h = 0.0; // Kluczowy parametr powoduj¹cy b³¹d

    //Wywo³anie testowanych funkcji z b³êdnym parametrem
    const double wynik_1_rzedu = rozniczka_1_rzedu(funkcja_kwadratowa, x, h);
    const double wynik_2_rzedu = rozniczka_2_rzedu(funkcja_kwadratowa, x, h);

    // Sprawdzenie, czy wynikiem jest NaN
    // Dzielenie 0.0 / 0.0 daje NaN.
    EXPECT_TRUE(std::isnan(wynik_1_rzedu));
    EXPECT_TRUE(std::isnan(wynik_2_rzedu));
}