#include "Czlowiek.h"
#include "../swiat/Swiat.h"
Czlowiek::Czlowiek(Swiat* swiat, int x, int y) : Zwierze(swiat,x,y, TypOrganizmu::Czlowiek,5,4)
{
	kierunek = Kierunek::brak;
}

void Czlowiek::akcja()
{
	if (umiejetnosc > 1) {
		umiejetnosc--;
		std::string napis = "pozostalo ";
		if (umiejetnosc > 5) { napis = napis + char(umiejetnosc - 5 + '0'); napis = napis + " tur umiejetnosci"; }
		else { napis = napis + char(umiejetnosc  + '0'); napis = napis + " do odnowienia umiejetnosci"; }
		
		swiat->komunikat(this, napis);
	}
	if (getWiek() == 0) {
		postarzWiek();
		return;
	}
	postarzWiek();
	Kierunek kierunek = wybierzKierunekCzlowiek(wejscie);
	int x1 = 0, y1 = 0;
	if (kierunek == Kierunek::brak) {
		swiat->komunikat(this, "nie moze sie ruszyc ");
		return;
	}
	if (kierunek == Kierunek::lewo) x1 = -1;
	if (kierunek == Kierunek::prawo)x1 = 1;
	if (kierunek == Kierunek::gora)y1 = -1;
	if (kierunek == Kierunek::dol)y1 = 1;
	if (!swiat->czyRuchMozliwy(getX()+x1, getY()+y1)){swiat->komunikat(this,"Czlowiek chce wyjsc poza plansze ");return; }
	if (swiat->getMapaOrganizmow()[getX() + x1][getY() + y1] == nullptr)swiat->przestawOrganizm(this, getX() + x1, getY() + y1);
	else {
		Organizm* inny = swiat->getMapaOrganizmow()[getX() + x1][getY() + y1];
		inny->kolizja(this);
	}
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
	if (umiejetnosc < 6) Zwierze::kolizja(atakujacy);
	else {
		swiat->tarczaPrzegon(atakujacy, this);
		swiat->komunikat(this, "przegania tarcza ");
	}
}
