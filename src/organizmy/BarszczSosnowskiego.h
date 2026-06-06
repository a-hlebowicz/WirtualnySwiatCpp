#pragma once
#include "Roslina.h"
class BarszczSosnowskiego :
    public Roslina
{
public:
    BarszczSosnowskiego(Swiat* swiat, Rng& rng, int x, int y);
    void akcja();
};

