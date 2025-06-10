#include "pch.h"
#include "gtest/gtest.h" 
#include "interpolacja_lagrange.h" 

#include <limits> 

// --- Test 1: Przypadek poprawny ---
// Sprawdza, czy funkcja poprawnie oblicza warto�� dla znanego wielomianu.
TEST(InterpolacjaLagrangeTest, PrzypadekPoprawny_InterpolacjaKwadratowa) {
    // Trzy punkty le��ce na paraboli y = x^2: (-1, 1), (0, 0), (2, 4)
    std::vector<Wezel> punkty = { {-1.0, 1.0}, {0.0, 0.0}, {2.0, 4.0} };
    double x_testowy = 1.0;
    double oczekiwany_wynik = 1.0; // Oczekujemy, �e dla x=1, funkcja zwr�ci y = 1^2 = 1

    double rzeczywisty_wynik = interpolacja_lagrange(punkty, x_testowy);

    // ASSERT: Sprawdzenie, czy wynik jest zgodny z oczekiwaniami z zadan� tolerancj�
    ASSERT_NEAR(rzeczywisty_wynik, oczekiwany_wynik, 1e-9);
}


// --- Test 2: Przypadek b��dny ---
// Sprawdza zachowanie NIEZMODYFIKOWANEJ funkcji, gdy na wej�ciu dostanie
// zduplikowane wsp�rz�dne 'xi', co prowadzi do dzielenia przez zero.
TEST(InterpolacjaLagrangeTest, PrzypadekBledny_DzieleniePrzezZeroZwracaNieskonczonosc) {
    // ARRANGE: Przygotowanie b��dnych danych wej�ciowych
    // Dwa punkty maj� t� sam� wsp�rz�dn� x = 5.0, co spowoduje dzielenie przez zero.
    std::vector<Wezel> punkty_z_bledem = { {1.0, 10.0}, {5.0, 20.0}, {5.0, 30.0} };
    double x_testowy = 2.0; // Dowolna warto�� x r�na od w�z��w

    // ACT: Wywo�anie testowanej funkcji
    double wynik_z_dzielenia_przez_zero = interpolacja_lagrange(punkty_z_bledem, x_testowy);

    // ASSERT: Sprawdzenie, czy wynikiem jest niesko�czono��
    ASSERT_TRUE(std::isinf(wynik_z_dzielenia_przez_zero));

}