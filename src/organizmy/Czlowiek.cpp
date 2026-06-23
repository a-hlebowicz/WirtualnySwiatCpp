#include "Czlowiek.h"
#include "../swiat/Swiat.h"
Czlowiek::Czlowiek(Swiat* swiat, Rng& rng, int x, int y) : Zwierze(swiat,rng, x,y, TypOrganizmu::Czlowiek,5,4)
{
	wejscie = Kierunek::brak;
	umiejetnosc = 0;
}

void Czlowiek::akcja()
{
	if (umiejetnosc >= 1) {
		umiejetnosc--;
	}

	if (getWiek() == 0) {
		postarzWiek();
		return;
	}
	postarzWiek();

	if (wejscie == Kierunek::brak) {
		return;
	}

	Wektor w = kierunekNaWektor(wejscie);
	int dx = getX() + w.x, dy = getY() + w.y;
	if (!swiat->czyRuchMozliwy(dx, dy)) {
		swiat->komunikat(this, Zdarzenie::BrakRuchu);
		wejscie = Kierunek::brak;
		return;
	}

	Organizm* inny = swiat->getOrganizmZMapy(dx, dy);
	if (inny == nullptr) swiat->przestawOrganizm(this, dx, dy);
	else inny->kolizja(this);

	wejscie = Kierunek::brak;
}

void Czlowiek::setKierunek(Kierunek k) {
	wejscie = k; 
}
void Czlowiek::aktywujUmietnosc() {
	umiejetnosc = 10;
}
int Czlowiek::getUmiejetnosc() {
	return umiejetnosc;
}
void Czlowiek::kolizja(Organizm* atakujacy) {
	if (!czyTarczaAktywna()) Zwierze::kolizja(atakujacy);
	else {
		swiat->tarczaPrzegon(atakujacy, this);
		swiat->komunikat(this, Zdarzenie::Przegnanie);
	}
}
bool Czlowiek::czyTarczaAktywna() const { 
	return umiejetnosc >= PROG_TARCZY; 
}
