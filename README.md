# 

# This project is currently being rewritten in modern C++ and is undergoing gradual code modernization.

# 

# Wirtualny Świat

Turowa symulacja ekosystemu z dziedziczeniem wirtualnym. Czysty C++, konsola Windows.

Każde pole siatki to organizm (zwierzę albo roślina) z siłą, inicjatywą i wiekiem. W każdej turze organizmy wykonują swoją akcję: zwierzęta poruszają się i walczą, rośliny się rozsiewają. Człowiek jest sterowany z klawiatury, reszta działa autonomicznie.

## organizmy

Wszystkie dziedziczą po klasie bazowej `Organizm` przez `Zwierze` albo `Roslina`. Kluczowe metody wirtualne: `akcja()`, `kolizja()`, `rozmnozenie()`. Każdy organizm trzyma wskaźnik na `Swiat`, swoje współrzędne, siłę, inicjatywę i wiek.

zwierzęta:

* `Wilk` (S=9, I=5); porusza się losowo
* `Owca` (S=4, I=4); porusza się losowo
* `Lis` (S=3, I=7); nie wchodzi na pole z silniejszym przeciwnikiem
* `Antylopa` (S=4, I=4); rusza się o 2 pola; 50% szansy na ucieczkę przed atakiem
* `Zolw` (S=2, I=1); 75% szansy że nie wykona ruchu; odpiera atak gdy atakujący ma siłę < 5
* `Czlowiek` (S=5, I=4); sterowany z klawiatury; umiejętność specjalna (Tarcza)

rośliny:

* `Trawa` (S=0, I=0); szansa na rozsianie się na sąsiednie pole
* `Mlecz` (S=0, I=0); jak trawa, ale do trzech prób rozsiania w jednej turze
* `Guarana` (S=0, I=0); zwiększa siłę zjadającego o 3
* `BarszczSosnowskiego` (S=90, I=0); zabija sąsiednie zwierzęta i swojego zjadającego
* `WilczeJagody` (S=99, I=0); zabijają zjadającego

## tura

Każda tura składa się z trzech faz:

1. Sortowanie listy organizmów malejąco po inicjatywie (przy remisie po wieku)
2. Wywołanie `akcja()` na każdym żywym organizmie zgodnie z kolejnością
3. Czyszczenie kolejki `doUsuniecia` (martwe organizmy zebrane podczas tury)

Akcja zwierzęcia: wybierz losowo sąsiednie pole, sprawdź czy jest puste lub zajęte przez inny organizm. Jeśli puste, przesuń się; jeśli zajęte, wywołaj `kolizja()` na obrońcy. Obrońca decyduje o wyniku (ucieczka, śmierć, rozmnożenie gdy ten sam gatunek, zabicie atakującego).

Akcja rośliny: szansa na rozsianie potomka na losowe sąsiednie wolne pole.

## człowiek i sterowanie

Sterowanie: `w`/`a`/`s`/`d` (góra, lewo, dół, prawo). Człowiek wykonuje ruch raz na turę. Po wciśnięciu klawisza świat wykonuje pełną turę i przerysowuje siatkę.

Tarcza (`r`): aktywna przez 5 tur, w tym czasie człowiek jest nietykalny. Po wygaśnięciu 5 tur cooldownu.

inne klawisze:

* `1` - nowa gra (przy starcie)
* `2` - wczytaj zapis z pliku (przy starcie)
* `z` - zapisz stan świata do pliku
* `0` - wyjście

## architektura

Siatka to `vector<vector<Organizm*>>` rozmiaru `szerokosc x wysokosc`, indeksowana przez `[x][y]`. Lista wszystkich organizmów trzymana osobno w `list<Organizm*>` po to, żeby tanio sortować po inicjatywie i iterować bez przeszukiwania mapy.

Usunięcia są opóźnione: ofiary kolizji wrzucane są do `queue<Organizm*> doUsuniecia` i kasowane dopiero po przejściu wszystkich akcji w turze. To rozwiązuje problem iteracji po liście, z której coś znika w połowie pętli.

Komunikaty zdarzeń (kto kogo zjadł, kto się urodził, kto użył tarczy) trafiają do `queue<string>` i są wypisywane jednym blokiem po turze; siatka renderowana jest przez przeciążony `operator<<` na klasie `Swiat`.

Polimorfizm odbywa się przez wirtualne `akcja()` i `kolizja()`; każdy nowy gatunek to nowa klasa dziedzicząca po `Zwierze` albo `Roslina` z przeładowanymi metodami. Symbol na mapie i kolory ANSI wybiera `getSymbol()`.

Zapis do pliku: każda linia to jeden organizm w formie `typ x y sila wiek`. Wczytanie iteruje po liniach i woła `dodajOrganizm()` z odpowiednim symbolem.

Domyślny rozmiar świata to 20x20 (zmienna w `main.cpp`).
