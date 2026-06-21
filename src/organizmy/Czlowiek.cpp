#include "Czlowiek.h"
#include "../swiat/Swiat.h"
Czlowiek::Czlowiek(Swiat* swiat, Rng& rng, int x, int y) : Zwierze(swiat,rng, x,y, TypOrganizmu::Czlowiek,5,4)
{
	kierunek = Kierunek::brak;
	wejscie = '0';
	umiejetnosc = 0;
}

void Czlowiek::akcja()
{
	if (umiejetnosc > 1) {
		umiejetnosc--;
		std::string napis = "pozostalo ";
		if (umiejetnosc > 5) napis += std::to_string(umiejetnosc - 5) + " tur umiejetnosci";
		else napis += std::to_string(umiejetnosc) + " do odnowienia umiejetnosci";
		
		//swiat->komunikat(this, napis);
	}
	if (getWiek() == 0) {
		postarzWiek();
		return;
	}
	postarzWiek();
	Kierunek kierunek = wybierzKierunekCzlowiek(wejscie);
	
	if (kierunek == Kierunek::brak) {
		swiat->komunikat(this, Zdarzenie::BrakRuchu);
		return;
	}

	Wektor w = kierunekNaWektor(kierunek);
	int dx = getX() + w.x;
	int dy = getY() + w.y;

	if (!swiat->czyRuchMozliwy(dx, dy)){
		swiat->komunikat(this,Zdarzenie::BrakRuchu);
		return;
	}

	Organizm* inny = swiat->getOrganizmZMapy(dx, dy);
	if (inny == nullptr) swiat->przestawOrganizm(this, dx, dy);
	else inny->kolizja(this);
}

Kierunek Czlowiek::wybierzKierunekCzlowiek(char wejscie)
{
	if (wejscie == 'a')return Kierunek::lewo;
	if (wejscie == 'd')return Kierunek::prawo;
	if (wejscie == 'w')return Kierunek::gora;
	if (wejscie == 's')return Kierunek::dol;
	if (wejscie == 'r')return Kierunek::umiejetnosc;
	return Kierunek::brak;
}

void Czlowiek::setWejscie(char c)
{
	wejscie = c;
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
