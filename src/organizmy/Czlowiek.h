#pragma once
#include "Zwierze.h"
#include <string>
static constexpr int PROG_TARCZY = 6;
class Czlowiek :
    public Zwierze
{
    Kierunek wejscie = Kierunek::brak;
    int umiejetnosc = 0;
public: Czlowiek(Swiat* swiat, Rng& rng, int x, int y);
      void akcja();
      void setKierunek(Kierunek k);
      void setWejscie(char c);
      void aktywujUmietnosc();
      int getUmiejetnosc();
      void kolizja(Organizm* atakujacy);
      bool czyTarczaAktywna() const;
};

