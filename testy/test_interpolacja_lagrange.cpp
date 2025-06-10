#include "pch.h"
#include "gtest/gtest.h" 
#include "interpolacja_lagrange.h" 

#include <limits> 

// --- Test 1: Przypadek poprawny ---
// Sprawdza, czy funkcja poprawnie oblicza wartoœæ dla znanego wielomianu.
TEST(InterpolacjaLagrangeTest, PrzypadekPoprawny_InterpolacjaKwadratowa) {
    // Trzy punkty le¿¹ce na paraboli y = x^2: (-1, 1), (0, 0), (2, 4)
    std::vector<Wezel> punkty = { {-1.0, 1.0}, {0.0, 0.0}, {2.0, 4.0} };
    double x_testowy = 1.0;
    double oczekiwany_wynik = 1.0; // Oczekujemy, ¿e dla x=1, funkcja zwróci y = 1^2 = 1

    double rzeczywisty_wynik = interpolacja_lagrange(punkty, x_testowy);

    // ASSERT: Sprawdzenie, czy wynik jest zgodny z oczekiwaniami z zadan¹ tolerancj¹
    ASSERT_NEAR(rzeczywisty_wynik, oczekiwany_wynik, 1e-9);
}


// --- Test 2: Przypadek b³êdny ---
// Sprawdza zachowanie NIEZMODYFIKOWANEJ funkcji, gdy na wejœciu dostanie
// zduplikowane wspó³rzêdne 'xi', co prowadzi do dzielenia przez zero.
TEST(InterpolacjaLagrangeTest, PrzypadekBledny_DzieleniePrzezZeroZwracaNieskonczonosc) {
    // ARRANGE: Przygotowanie b³êdnych danych wejœciowych
    // Dwa punkty maj¹ tê sam¹ wspó³rzêdn¹ x = 5.0, co spowoduje dzielenie przez zero.
    std::vector<Wezel> punkty_z_bledem = { {1.0, 10.0}, {5.0, 20.0}, {5.0, 30.0} };
    double x_testowy = 2.0; // Dowolna wartoœæ x ró¿na od wêz³ów

    // ACT: Wywo³anie testowanej funkcji
    double wynik_z_dzielenia_przez_zero = interpolacja_lagrange(punkty_z_bledem, x_testowy);

    // ASSERT: Sprawdzenie, czy wynikiem jest nieskoñczonoœæ
    ASSERT_TRUE(std::isinf(wynik_z_dzielenia_przez_zero));

}