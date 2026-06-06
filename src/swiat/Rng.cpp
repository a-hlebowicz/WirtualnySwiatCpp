#include "Rng.h"
#include "../organizmy/Organizm.h"

Rng::Rng() : rng(std::random_device{}()) {}
//Rng::Rng(unsigned seed) : rng(seed) {}

int Rng::losujInt(int min, int max) {
    std::uniform_int_distribution<int> rozklad(min, max);
    return rozklad(rng);
}

bool Rng::losujProcent(double p) {
    std::bernoulli_distribution rozklad(p / 100);
    return rozklad(rng);
}

Kierunek Rng::losowyKierunek() {
    switch (losujInt(0, 3)) {
    case 0: return Kierunek::prawo;
    case 1: return Kierunek::lewo;
    case 2: return Kierunek::gora;
    case 3: return Kierunek::dol;
    }
    return Kierunek::brak;
}