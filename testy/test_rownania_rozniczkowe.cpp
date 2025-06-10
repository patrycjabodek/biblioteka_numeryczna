#include "pch.h"
#include "gtest/gtest.h"
#include "rownania_rozniczkowe.h"
#include <vector>
#include <functional>
#include <stdexcept>
#include <cmath> 

// --- Test 1: Przypadek poprawny (rozwi�zanie znanego r�wnania) ---
// Ten test sprawdza, czy metoda RK4 poprawnie przybli�a rozwi�zanie
// prostego r�wnania r�niczkowego y' = y, kt�rego znamy dok�adne rozwi�zanie y(t) = e^t.
TEST(RownaniaRozniczkoweTest, RK4_PoprawnieRozwiazujeProsteRownanie) {
    // Przygotowanie danych wej�ciowych
    // R�wnanie: y' = y. W naszej notacji f(T, t) = T.
    auto funkcja_f = [](double T, double t) { return T; };

    double T0 = 1.0;      // Warunek pocz�tkowy y(0) = 1
    double h = 0.01;       // Krok czasowy
    double t_end = 1.0;   // Rozwi�zujemy do czasu t = 1.0

    // Oczekiwany wynik w punkcie t_end = 1.0 to y(1) = e^1 = 2.71828
    double oczekiwany_wynik_na_koncu = std::exp(1.0);

    std::vector<double> wynik_numeryczny = metodaRK4(T0, t_end, h, funkcja_f);

    //Sprawdzenie wynik�w
    // 1. Sprawdzamy, czy wektor wynik�w nie jest pusty
    ASSERT_FALSE(wynik_numeryczny.empty());

    // 2. Sprawdzamy, czy ostatni element obliczonego rozwi�zania
    // jest bliski dok�adnej warto�ci analitycznej.
    // Metoda RK4 jest bardzo dok�adna, wi�c mo�emy u�y� ma�ej tolerancji.
    ASSERT_NEAR(wynik_numeryczny.back(), oczekiwany_wynik_na_koncu, 1e-6);
}


// --- Test 2: Przypadek b��dny (nieprawid�owe dane wej�ciowe) ---
// Ten test sprawdza, czy funkcja poprawnie obs�uguje sytuacj�, gdy
// podano jej nieprawid�owy (zerowy lub ujemny) krok czasowy 'h'.
TEST(RownaniaRozniczkoweTest, RK4_RzucaWyjatekDlaNiepoprawnegoKrokuH) {
    // Przygotowanie b��dnych danych wej�ciowych
    auto dowolna_funkcja = [](double T, double t) { return T; };
    double T0 = 1.0;
    double t_end = 1.0;

    // Sprawdzenie, czy funkcja rzuci wyj�tek dla h=0 i h<0
    ASSERT_THROW(metodaRK4(T0, t_end, 0.0, dowolna_funkcja), std::invalid_argument);
    ASSERT_THROW(metodaRK4(T0, t_end, -0.1, dowolna_funkcja), std::invalid_argument);
}