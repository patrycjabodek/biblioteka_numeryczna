#include "pch.h"
#include "gtest/gtest.h"
#include "gauss.h"
#include <vector>

// --- Test 1: Przypadek poprawny ---
// Ten test sprawdza, czy funkcja poprawnie rozwi�zuje prosty, znany uk�ad r�wna� liniowych 2x2.
TEST(EliminacjaGaussaTest, PoprawnyWynikDlaUkladu2x2) {
    // Przygotowanie danych wej�ciowych
    // Uk�ad r�wna�:
    // 2x + 1y = 5
    // 1x - 3y = 6
    // Oczekiwane rozwi�zanie: x = 3, y = -1

    int N = 2;
    std::vector<std::vector<double>> A = {
        {2.0, 1.0},
        {1.0, -3.0}
    };
    std::vector<double> b = { 5.0, 6.0 };
    std::vector<double> oczekiwane_x = { 3.0, -1.0 };
    std::vector<double> obliczone_x; 

    
    bool czy_rozwiazano = eliminacja_gaussa(N, A, b, obliczone_x);

    // Sprawdzenie wynik�w
    // 1. Sprawdzamy, czy funkcja zasygnalizowa�a sukces
    ASSERT_TRUE(czy_rozwiazano);

    // 2. Sprawdzamy, czy wektor wynik�w ma poprawny rozmiar
    ASSERT_EQ(obliczone_x.size(), oczekiwane_x.size());

    // 3. Sprawdzamy, czy obliczone warto�ci s� zgodne z oczekiwanymi
    for (size_t i = 0; i < oczekiwane_x.size(); ++i) {
        ASSERT_NEAR(obliczone_x[i], oczekiwane_x[i], 1e-9);
    }
}


// --- Test 2: Przypadek b��dny (uk�ad osobliwy) ---
// Ten test sprawdza, czy funkcja poprawnie identyfikuje uk�ad liniowo zale�ny i zwraca 'false'.
TEST(EliminacjaGaussaTest, ZwracaFalseDlaUkladuOsobliwego) {
    // Przygotowanie danych dla uk�adu osobliwego
    // Uk�ad r�wna�:
    // 2x + 4y = 10
    // 1x + 2y = 5 
    // Drugie r�wnanie jest wielokrotno�ci� pierwszego, wi�c uk�ad jest osobliwy.

    int N = 2;
    std::vector<std::vector<double>> A = {
        {2.0, 4.0},
        {1.0, 2.0}
    };
    std::vector<double> b = { 10.0, 5.0 };
    std::vector<double> obliczone_x; // Ten wektor pozostanie pusty

    // Wywo�anie testowanej funkcji
    bool czy_rozwiazano = eliminacja_gaussa(N, A, b, obliczone_x);

    // Sprawdzenie, czy funkcja zwr�ci�a 'false'
    // To jest oczekiwane zachowanie dla uk�adu osobliwego.
    ASSERT_FALSE(czy_rozwiazano);
}