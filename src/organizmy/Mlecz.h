#pragma once
#include "Roslina.h"
class Mlecz :
    public Roslina
{
public:
    Mlecz(Swiat* swiat, Rng& rng, int x, int y);
    void akcja() override;
};

