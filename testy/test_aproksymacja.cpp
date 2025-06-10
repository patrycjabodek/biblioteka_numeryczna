#include "pch.h"
#include "gtest/gtest.h"
#include "aproksymacja.h"
#include <vector>
#include <functional>
#include <stdexcept>

// --- Test 1: Przypadek poprawny (aproksymacja znanej funkcji) ---
// Ten test sprawdza, czy funkcja potrafi poprawnie odtworzyæ wspó³czynniki
// wielomianu, który jest sam w sobie funkcj¹ aproksymowan¹.
TEST(AproksymacjaTest, PoprawnieAproksymujeFunkcjeKwadratowa) {
    //Przygotowanie danych wejœciowych
    // Bêdziemy aproksymowaæ funkcjê f(x) = x^2 wielomianem stopnia 2.
    // Oczekujemy, ¿e wynikiem bêdzie wielomian W(x) = 0*x^0 + 0*x^1 + 1*x^2.
    // Czyli wektor wspó³czynników: {0, 0, 1}.

    int stopien = 2;
    double a = -1.0, b = 1.0; // Przedzia³ aproksymacji
    auto funkcja_do_aproksymacji = [](double x) { return x * x; };
    std::vector<double> oczekiwane_wspolczynniki = { 0.0, 0.0, 1.0 };

    // Wywo³anie funkcji aproksymacji
    std::vector<double> obliczone_wspolczynniki = aproksymacja(stopien, a, b, funkcja_do_aproksymacji);

    // Sprawdzenie wyników
    // 1. Sprawdzamy, czy wektor wyników ma poprawny rozmiar
    ASSERT_EQ(obliczone_wspolczynniki.size(), oczekiwane_wspolczynniki.size());

    // 2. Sprawdzamy, czy obliczone wspó³czynniki s¹ bliskie oczekiwanym.
    // U¿ywamy du¿ej tolerancji, poniewa¿ aproksymacja jest obarczona b³êdem numerycznym.
    for (size_t i = 0; i < oczekiwane_wspolczynniki.size(); ++i) {
        ASSERT_NEAR(obliczone_wspolczynniki[i], oczekiwane_wspolczynniki[i], 1e-5);
    }
}


// --- Test 2: Przypadek b³êdny  ---
// Ten test sprawdza, czy funkcja poprawnie obs³uguje sytuacjê, gdy
// podano jej nieprawid³owy (ujemny) stopieñ wielomianu.
TEST(AproksymacjaTest, RzucaWyjatekDlaUjemnegoStopnia) {
    //  Przygotowanie b³êdnych danych wejœciowych
    int stopien = -1;
    double a = 0.0, b = 1.0;
    auto dowolna_funkcja = [](double x) { return x; };

    // Sprawdzenie, czy funkcja rzuci wyj¹tek dla ujemnego stopnia wielomianu.
    ASSERT_THROW(aproksymacja(stopien, a, b, dowolna_funkcja), std::invalid_argument);
}