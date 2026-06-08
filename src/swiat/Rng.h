#pragma once
#include <random>

enum class Kierunek;

class Rng {
    std::mt19937 rng;
public:
    Rng();                          
    //explicit Rng(unsigned seed);

    int losujInt(int min, int max);
    bool losujProcent(double p);
    Kierunek losowyKierunek();
    int losujIndeks(int max);
};