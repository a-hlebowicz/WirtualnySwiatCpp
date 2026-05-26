#include "Antylopa.h"

Antylopa::Antylopa(Swiat* swiat, int x, int y) :Zwierze(swiat, x, y, 'A', 4, 4) {
	setPredkosc(2);
}

void Antylopa::kolizja(Organizm* atakujacy)
{
	if (rand() % 2 == 0 || atakujacy->getSymbol() == getSymbol())Zwierze::kolizja(atakujacy);
	else {
		if (!swiat->czySasiadujaceWolne(getX(), getY()))Zwierze::kolizja(atakujacy);
		else {
			swiat->komunikat(atakujacy, "przegania antylope");
			swiat->przegonOrganizm(atakujacy, this);
			
		}
	}
}
