Pobierz repozytorium z githuba:
git clone https://github.com/patrycjabodek/biblioteka_numeryczna.git

Następnie w swoim projekcie należy we właściwościach (Projekt->nazwa_projektu właściwości) dodać odpowiednie ścieżki:
- Konsolidator->Dane wejściowe->Dodatkowe zależności: biblioteka_numeryczna.lib
- Katalogi VC++->Katalogi plików nagłówkowych: [ścieżka do folderu z repozytorium githuba, np.: C:\Users\User\Desktop]\biblioteka_numeryczna\biblioteka_numeryczna
- Katalogi VC++->Katalogi bibliotek: [ścieżka do folderu z repozytorium githuba]\biblioteka_numeryczna\x64\Debug

Aby użyć funkcji z biblioteki na początku pliku zaimportuj plik nagłówkowy:
#include "biblioteka_numeryczna.h"
