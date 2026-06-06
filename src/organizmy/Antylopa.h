#pragma once
#include "Zwierze.h"
class Antylopa :
    public Zwierze
{
public:
    Antylopa(Swiat* swiat, Rng& rng,int x, int y);
    void kolizja(Organizm* atakujacy);
};

