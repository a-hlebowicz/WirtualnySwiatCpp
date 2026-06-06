#pragma once
#include "Zwierze.h"
class Lis :
    public Zwierze
{
public:
    Lis(Swiat* swiat, Rng& rng, int x, int y);
    void akcja() ;
    Kierunek wybierzKierunekLis() ;
};

