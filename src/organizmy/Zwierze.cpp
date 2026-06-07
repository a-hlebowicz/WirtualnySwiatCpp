#include "Zwierze.h"
#include <iostream>
#include "../swiat/Swiat.h"


Zwierze::Zwierze(Swiat* swiat, Rng& rng , int x, int y, TypOrganizmu typOrganizmu, int sila, int inicjatywa) : Organizm(swiat, rng, x, y, typOrganizmu, sila, inicjatywa)
{
	predkosc = 1;
}
Kierunek Zwierze::wybierzKierunek()
{
	/*int x1 = 0, y1 = 0, i=0;
	while (1) {
		if (i >= 20) {
			return Kierunek::brak;
			std::cout << "nie znaleziono kierunku ";
		}
		auto [dx, dy] = kierunekNaWektor(rng.losowyKierunek());
		if (swiat->czyRuchMozliwy(getX() + dx, getY() + dy))break;
		i++;
	}
	return kierunek;*/
	Kierunek kierunek = Kierunek::brak;
	for (int i = 0;ILE_PROB > i;i++) {
		kierunek = rng.losowyKierunek();
		auto [dx, dy] = kierunekNaWektor(kierunek, predkosc);
		if (swiat->czyRuchMozliwy(getX() + dx, getY() + dy)) return kierunek;
	}
	std::cout << "nie znaleziono kierunku ";
	return Kierunek::brak;
}
void Zwierze::akcja() {
	if (getWiek() == 0) {
		postarzWiek();
		return;
	}
	postarzWiek();
	Kierunek kierunek = wybierzKierunek();
	int x1=0, y1=0;
	if (kierunek == Kierunek::brak) {
		swiat->komunikat(this, "nie moze sie ruszyc ");
		return;
	}
	if (kierunek == Kierunek::lewo) x1 = -predkosc;
	if (kierunek == Kierunek::prawo)x1 = predkosc;
	if (kierunek == Kierunek::gora)y1 = -predkosc;
	if (kierunek == Kierunek::dol)y1 = predkosc;
	if (swiat->getMapaOrganizmow()[getX() + x1][getY() + y1] == nullptr)swiat->przestawOrganizm(this, getX() + x1, getY() + y1);
	else {
		Organizm* inny = swiat->getMapaOrganizmow()[getX() + x1][getY() + y1];
		inny->kolizja(this);
	}
}
void Zwierze::kolizja(Organizm* atakujacy) {
	if (this->getTyp() == atakujacy->getTyp()) {
		//dziecko
		auto pole = swiat->znajdzWolnePole(this);	
		if (!pole) return;	
		swiat->dodajOrganizm(getTyp(), pole->x,  pole->y);
		swiat->komunikat(this, "sie rozmnozyl");	
	}
	else if (atakujacy->getSila() >= this->getSila()) {
		swiat->komunikat(atakujacy, "atakuje ");
		swiat->komunikat(this, "przegrywa ");
		swiat->zastapOrganizm(atakujacy, this);
	}
	else {
		swiat->komunikat(atakujacy, "atakuje ");
		swiat->komunikat(this, "wygrywa ");
		swiat->usunOrganizm(atakujacy);
	}
}
int Zwierze::getPredkosc() const {
	return predkosc;
}
void Zwierze::setPredkosc(int a) {
	predkosc = a;
}
