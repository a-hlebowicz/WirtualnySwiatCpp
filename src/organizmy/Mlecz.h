#pragma once
#include "Roslina.h"
class Mlecz :
    public Roslina
{
public:
    Mlecz(Swiat* swiat, int x, int y);
    void akcja() override;
};

