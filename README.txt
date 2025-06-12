Pobierz repozytorium z githuba:
git clone https://github.com/patrycjabodek/biblioteka_numeryczna.git

Następnie w swoim projekcie należy we właściwościach (Projekt->nazwa_projektu właściwości) dodać odpowiednie ścieżki:
- Konsolidator->Dane wejściowe->Dodatkowe zależności: biblioteka_numeryczna.lib
- Katalogi VC++->Katalogi plików nagłówkowych: [ścieżka do folderu z repozytorium githuba, np.: C:\Users\User\Desktop]\biblioteka_numeryczna\biblioteka_numeryczna
- Katalogi VC++->Katalogi bibliotek: [ścieżka do folderu z repozytorium githuba]\biblioteka_numeryczna\x64\Debug

Aby móc skorzystać z wszystkich funkcji z biblioteki na początku pliku zaimportuj plik nagłówkowy:
#include "biblioteka_numeryczna.h"

Aby skorzystac tylko z wybranych funckji można załączyć potrzebne pliki nagłowkowe:
#include "aproksymacja.h"
#include "calkowanie.h"
#include "gauss.h"
#include "interpolacja_lagrange.h"
#include "interpolacja_newton.h"
#include "metoda_lu.h"
#include "rownania_rozniczkowe.h"
#include "rownania_nieliniowe.h"
#include "rozniczkowanie.h"
