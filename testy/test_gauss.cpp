#include "pch.h"
#include "gtest/gtest.h"
#include "gauss.h"
#include <vector>

// --- Test 1: Przypadek poprawny ---
// Ten test sprawdza, czy funkcja poprawnie rozwi¹zuje prosty, znany uk³ad równañ liniowych 2x2.
TEST(EliminacjaGaussaTest, PoprawnyWynikDlaUkladu2x2) {
    // Przygotowanie danych wejœciowych
    // Uk³ad równañ:
    // 2x + 1y = 5
    // 1x - 3y = 6
    // Oczekiwane rozwi¹zanie: x = 3, y = -1

    int N = 2;
    std::vector<std::vector<double>> A = {
        {2.0, 1.0},
        {1.0, -3.0}
    };
    std::vector<double> b = { 5.0, 6.0 };
    std::vector<double> oczekiwane_x = { 3.0, -1.0 };
    std::vector<double> obliczone_x; 

    
    bool czy_rozwiazano = eliminacja_gaussa(N, A, b, obliczone_x);

    // Sprawdzenie wyników
    // 1. Sprawdzamy, czy funkcja zasygnalizowa³a sukces
    ASSERT_TRUE(czy_rozwiazano);

    // 2. Sprawdzamy, czy wektor wyników ma poprawny rozmiar
    ASSERT_EQ(obliczone_x.size(), oczekiwane_x.size());

    // 3. Sprawdzamy, czy obliczone wartoœci s¹ zgodne z oczekiwanymi
    for (size_t i = 0; i < oczekiwane_x.size(); ++i) {
        ASSERT_NEAR(obliczone_x[i], oczekiwane_x[i], 1e-9);
    }
}


// --- Test 2: Przypadek b³êdny (uk³ad osobliwy) ---
// Ten test sprawdza, czy funkcja poprawnie identyfikuje uk³ad liniowo zale¿ny i zwraca 'false'.
TEST(EliminacjaGaussaTest, ZwracaFalseDlaUkladuOsobliwego) {
    // Przygotowanie danych dla uk³adu osobliwego
    // Uk³ad równañ:
    // 2x + 4y = 10
    // 1x + 2y = 5 
    // Drugie równanie jest wielokrotnoœci¹ pierwszego, wiêc uk³ad jest osobliwy.

    int N = 2;
    std::vector<std::vector<double>> A = {
        {2.0, 4.0},
        {1.0, 2.0}
    };
    std::vector<double> b = { 10.0, 5.0 };
    std::vector<double> obliczone_x; // Ten wektor pozostanie pusty

    // Wywo³anie testowanej funkcji
    bool czy_rozwiazano = eliminacja_gaussa(N, A, b, obliczone_x);

    // Sprawdzenie, czy funkcja zwróci³a 'false'
    // To jest oczekiwane zachowanie dla uk³adu osobliwego.
    ASSERT_FALSE(czy_rozwiazano);
}