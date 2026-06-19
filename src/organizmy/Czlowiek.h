#pragma once
#include "Zwierze.h"
#include <string>
static constexpr int PROG_TARCZY = 6;
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
      bool czyTarczaAktywna() const;
};

