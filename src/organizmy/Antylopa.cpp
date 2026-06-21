#include "Antylopa.h"
#include "../swiat/Swiat.h"

Antylopa::Antylopa(Swiat* swiat, Rng& rng, int x, int y) : Zwierze(swiat, rng, x, y, TypOrganizmu::Antylopa, 4, 4) {
	setPredkosc(2);
}

void Antylopa::kolizja(Organizm* atakujacy)
{
	if (rng.losujProcent(50) || atakujacy->getTyp() == getTyp())Zwierze::kolizja(atakujacy);
	else {
		if (!swiat->czySasiadujaceWolne(getX(), getY()))Zwierze::kolizja(atakujacy);
		else {
			swiat->komunikat(atakujacy, Zdarzenie::Przegnanie, this);
			swiat->przegonOrganizm(atakujacy, this);
			
		}
	}
}
