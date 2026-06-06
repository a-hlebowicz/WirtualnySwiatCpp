#pragma once
#include "Roslina.h"
class Guarana :
    public Roslina
{
public:
    Guarana(Swiat* swiat, Rng& rng, int x, int y);
    void kolizja(Organizm* organizm);
};

