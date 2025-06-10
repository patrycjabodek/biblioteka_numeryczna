#include "pch.h"
#include "gtest/gtest.h"
#include "metoda_lu.h"
#include <vector>

// --- Test 1: Przypadek poprawny  ---
// Ten test sprawdza, czy ca³y proces (dekompozycja LU, a nastêpnie rozwi¹zanie uk³adu) daje poprawny wynik dla znanego uk³adu.
TEST(MetodaLUTest, PoprawnyWynikRozwiazaniaUkladu) {
    // Przygotowanie danych wejœciowych
    // Uk³ad równañ:
    // 2x + 1y = 5
    // 1x - 3y = 6
    // Oczekiwane rozwi¹zanie: x = 3, y = -1

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
    // 2. Rozwi¹¿ uk³ad równañ za pomoc¹ L i U
    std::vector<double> obliczone_x = rozwiaz_LU(L, U, b, n);

    // Sprawdzenie wyników
    // 1. Sprawdzamy, czy dekompozycja siê powiod³a
    ASSERT_TRUE(czy_dekompozycja_udana);

    // 2. Sprawdzamy, czy wektor wyników ma poprawny rozmiar
    ASSERT_EQ(obliczone_x.size(), oczekiwane_x.size());

    // 3. Sprawdzamy, czy obliczone wartoœci s¹ zgodne z oczekiwanymi
    for (size_t i = 0; i < oczekiwane_x.size(); ++i) {
        ASSERT_NEAR(obliczone_x[i], oczekiwane_x[i], 1e-9);
    }
}


// --- Test 2: Przypadek b³êdny ---
// Ten test sprawdza, czy funkcja `metodaLU` poprawnie identyfikuje macierz, dla której dekompozycja LU w tej formie jest niemo¿liwa (element na przek¹tnej U jest zerem).
TEST(MetodaLUTest, ZwracaFalseGdyDekompozycjaNiemozliwa) {
    // Przygotowanie danych dla macierzy, której dekompozycja LU zawiedzie
    // Macierz:
    // 0 1
    // 1 1
    // Ju¿ na pierwszym kroku U[0][0] bêdzie równe A[0][0], czyli 0, co uniemo¿liwi dzielenie.

    int n = 2;
    std::vector<std::vector<double>> A = {
        {0.0, 1.0},
        {1.0, 1.0}
    };

    std::vector<std::vector<double>> L, U; // Te macierze nie zostan¹ poprawnie wype³nione

    // Wywo³anie funkcji dekompozycji
    bool czy_dekompozycja_udana = metodaLU(A, L, U, n);

    // Sprawdzenie, czy funkcja zwróci³a 'false'
    // To jest oczekiwane zachowanie, gdy algorytm napotka zero na przek¹tnej U.
    ASSERT_FALSE(czy_dekompozycja_udana);
}