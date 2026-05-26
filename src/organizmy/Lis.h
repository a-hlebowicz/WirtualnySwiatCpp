#pragma once
#include "Zwierze.h"
class Lis :
    public Zwierze
{
public:
    Lis(Swiat* swiat, int x, int y);  
    void akcja() ;
    kierunki wybierzKierunekLis() ;
};

