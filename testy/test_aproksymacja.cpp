#include "pch.h"
#include "gtest/gtest.h"
#include "aproksymacja.h"
#include <vector>
#include <functional>
#include <stdexcept>

// --- Test 1: Przypadek poprawny (aproksymacja znanej funkcji) ---
// Ten test sprawdza, czy funkcja potrafi poprawnie odtworzy� wsp�czynniki
// wielomianu, kt�ry jest sam w sobie funkcj� aproksymowan�.
TEST(AproksymacjaTest, PoprawnieAproksymujeFunkcjeKwadratowa) {
    //Przygotowanie danych wej�ciowych
    // B�dziemy aproksymowa� funkcj� f(x) = x^2 wielomianem stopnia 2.
    // Oczekujemy, �e wynikiem b�dzie wielomian W(x) = 0*x^0 + 0*x^1 + 1*x^2.
    // Czyli wektor wsp�czynnik�w: {0, 0, 1}.

    int stopien = 2;
    double a = -1.0, b = 1.0; // Przedzia� aproksymacji
    auto funkcja_do_aproksymacji = [](double x) { return x * x; };
    std::vector<double> oczekiwane_wspolczynniki = { 0.0, 0.0, 1.0 };

    // Wywo�anie funkcji aproksymacji
    std::vector<double> obliczone_wspolczynniki = aproksymacja(stopien, a, b, funkcja_do_aproksymacji);

    // Sprawdzenie wynik�w
    // 1. Sprawdzamy, czy wektor wynik�w ma poprawny rozmiar
    ASSERT_EQ(obliczone_wspolczynniki.size(), oczekiwane_wspolczynniki.size());

    // 2. Sprawdzamy, czy obliczone wsp�czynniki s� bliskie oczekiwanym.
    // U�ywamy du�ej tolerancji, poniewa� aproksymacja jest obarczona b��dem numerycznym.
    for (size_t i = 0; i < oczekiwane_wspolczynniki.size(); ++i) {
        ASSERT_NEAR(obliczone_wspolczynniki[i], oczekiwane_wspolczynniki[i], 1e-5);
    }
}


// --- Test 2: Przypadek b��dny  ---
// Ten test sprawdza, czy funkcja poprawnie obs�uguje sytuacj�, gdy
// podano jej nieprawid�owy (ujemny) stopie� wielomianu.
TEST(AproksymacjaTest, RzucaWyjatekDlaUjemnegoStopnia) {
    //  Przygotowanie b��dnych danych wej�ciowych
    int stopien = -1;
    double a = 0.0, b = 1.0;
    auto dowolna_funkcja = [](double x) { return x; };

    // Sprawdzenie, czy funkcja rzuci wyj�tek dla ujemnego stopnia wielomianu.
    ASSERT_THROW(aproksymacja(stopien, a, b, dowolna_funkcja), std::invalid_argument);
}