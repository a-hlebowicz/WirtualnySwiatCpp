#include "Zwierze.h"
#include <iostream>
#include "../swiat/Swiat.h"


Zwierze::Zwierze(Swiat* swiat, Rng& rng , int x, int y, TypOrganizmu typOrganizmu, int sila, int inicjatywa) : Organizm(swiat, rng, x, y, typOrganizmu, sila, inicjatywa)
{
	predkosc = 1;
}

std::optional<Wektor> Zwierze::zaplanujRuch() {
	const std::array<Kierunek, 4> wszystkieKierunki = {
		Kierunek::lewo, Kierunek::prawo, Kierunek::gora, Kierunek::dol
	};
	std::vector<Wektor> mozliweWektory;
	mozliweWektory.reserve(4);

	for (Kierunek k : wszystkieKierunki) {
		Wektor w = kierunekNaWektor(k, predkosc);
		if (swiat->czyRuchMozliwy(getX()+w.x, getY()+w.y)) mozliweWektory.push_back(w);
	}

	if (mozliweWektory.empty()) {
		return std::nullopt;
	}

	int rngI = rng.losujIndeks(mozliweWektory.size());
	return mozliweWektory[rngI];
}

void Zwierze::akcja() {
	if (getWiek() == 0) {
		postarzWiek();
		return;
	}
	postarzWiek();

	auto w = zaplanujRuch();
	if (!w) {
		swiat->komunikat(this, "nie moze sie ruszyc ");
		return;
	}
	auto [dx, dy] = *w;

	Organizm* inny = swiat->getMapaOrganizmow()[getX() + dx][getY() + dy];  //zmienic interfejs
	if (inny == nullptr)swiat->przestawOrganizm(this, getX() + dx, getY() + dy);
	else inny->kolizja(this);
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
