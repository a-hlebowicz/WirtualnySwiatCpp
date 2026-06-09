#pragma once
#include "Zwierze.h"
#include <string>
class Czlowiek :
    public Zwierze
{
    Kierunek kierunek;
    char wejscie;
    int umiejetnosc;
public: Czlowiek(Swiat* swiat, Rng& rng, int x, int y);
      void akcja();
      Kierunek wybierzKierunekCzlowiek(char wejscie);
      void setWejscie(char c);
      void aktywujUmietnosc();
      int getUmiejetnosc();
      void kolizja(Organizm* atakujacy);
};

