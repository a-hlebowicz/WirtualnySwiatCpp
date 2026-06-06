#include "Owca.h"
#include "../swiat/Swiat.h"
Owca::Owca(Swiat* swiat, Rng& rng, int x, int y) : Zwierze(swiat,rng,  x, y, TypOrganizmu::Owca, 4, 4) {};