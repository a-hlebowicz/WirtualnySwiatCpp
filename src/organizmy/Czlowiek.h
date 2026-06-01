#pragma once
#include "Zwierze.h"
class Czlowiek :
    public Zwierze
{
    Kierunek kierunek;
    char wejscie;
    int umiejetnosc;
public: Czlowiek(Swiat* swiat, int x, int y);
      void akcja();
      Kierunek wybierzKierunekCzlowiek(char wejscie);
      void setWejscie(char c);
      void aktywujUmietnosc();
      int getUmiejetnosc();
      void kolizja(Organizm* atakujacy);
};

