#include "pch.h"
#include "gtest/gtest.h"
#include "metoda_lu.h"
#include <vector>

// --- Test 1: Przypadek poprawny  ---
// Ten test sprawdza, czy ca�y proces (dekompozycja LU, a nast�pnie rozwi�zanie uk�adu) daje poprawny wynik dla znanego uk�adu.
TEST(MetodaLUTest, PoprawnyWynikRozwiazaniaUkladu) {
    // Przygotowanie danych wej�ciowych
    // Uk�ad r�wna�:
    // 2x + 1y = 5
    // 1x - 3y = 6
    // Oczekiwane rozwi�zanie: x = 3, y = -1

    int n = 2;
    std::vector<std::vector<double>> A = {
        {2.0, 1.0},
        {1.0, -3.0}
    };
    std::vector<double> b = { 5.0, 6.0 };
    std::vector<double> oczekiwane_x = { 3.0, -1.0 };

    std::vector<std::vector<double>> L, U; 

 
    // 1. Dokonaj dekompozycji LU
    bool czy_dekompozycja_udana = metodaLU(A, L, U, n);
    // 2. Rozwi�� uk�ad r�wna� za pomoc� L i U
    std::vector<double> obliczone_x = rozwiaz_LU(L, U, b, n);

    // Sprawdzenie wynik�w
    // 1. Sprawdzamy, czy dekompozycja si� powiod�a
    ASSERT_TRUE(czy_dekompozycja_udana);

    // 2. Sprawdzamy, czy wektor wynik�w ma poprawny rozmiar
    ASSERT_EQ(obliczone_x.size(), oczekiwane_x.size());

    // 3. Sprawdzamy, czy obliczone warto�ci s� zgodne z oczekiwanymi
    for (size_t i = 0; i < oczekiwane_x.size(); ++i) {
        ASSERT_NEAR(obliczone_x[i], oczekiwane_x[i], 1e-9);
    }
}


// --- Test 2: Przypadek b��dny ---
// Ten test sprawdza, czy funkcja `metodaLU` poprawnie identyfikuje macierz, dla kt�rej dekompozycja LU w tej formie jest niemo�liwa (element na przek�tnej U jest zerem).
TEST(MetodaLUTest, ZwracaFalseGdyDekompozycjaNiemozliwa) {
    // Przygotowanie danych dla macierzy, kt�rej dekompozycja LU zawiedzie
    // Macierz:
    // 0 1
    // 1 1
    // Ju� na pierwszym kroku U[0][0] b�dzie r�wne A[0][0], czyli 0, co uniemo�liwi dzielenie.

    int n = 2;
    std::vector<std::vector<double>> A = {
        {0.0, 1.0},
        {1.0, 1.0}
    };

    std::vector<std::vector<double>> L, U; // Te macierze nie zostan� poprawnie wype�nione

    // Wywo�anie funkcji dekompozycji
    bool czy_dekompozycja_udana = metodaLU(A, L, U, n);

    // Sprawdzenie, czy funkcja zwr�ci�a 'false'
    // To jest oczekiwane zachowanie, gdy algorytm napotka zero na przek�tnej U.
    ASSERT_FALSE(czy_dekompozycja_udana);
}