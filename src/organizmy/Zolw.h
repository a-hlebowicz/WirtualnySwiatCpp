#pragma once
#include "Zwierze.h"
class Zolw :
    public Zwierze
{
public:
    Zolw(Swiat* swiat, Rng& rng, int x, int y);
    void akcja() ;
    void kolizja(Organizm* organizm) ;
};

