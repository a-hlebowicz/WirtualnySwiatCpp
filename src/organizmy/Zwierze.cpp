#include "Zwierze.h"

Zwierze::Zwierze(Swiat* swiat, int x, int y, char symbol, int sila, int inicjatywa) : Organizm(swiat, x, y, symbol, sila, inicjatywa)
{
	predkosc = 1;
}

kierunki Zwierze::wybierzKierunek()
{
	kierunki kierunek=brak;
	int x1 = 0, y1 = 0, i=0;
	while (1) {
		if (i >= 20) {
			return brak;
			std::cout << "nie znaleziono kierunku ";
		}
		int a = rand() % 4;
		if (a == 0) { x1 = predkosc; y1 = 0; kierunek = prawo; }
		if (a == 1) { x1 = -predkosc; y1 = 0; kierunek = lewo; }
		if (a == 2) { x1 = 0; y1 = -predkosc; kierunek = gora; }
		if (a == 3) { x1 = 0; y1 = predkosc; kierunek = dol; }
		if (swiat->czyRuchMozliwy(getX() + x1, getY() + y1))break;
		i++;
	}
	return kierunek;
}
void Zwierze::akcja() {
	if (getWiek() == 0) {
		postarzWiek();
		return;
	}
	postarzWiek();
	kierunki kierunek = wybierzKierunek();
	int x1=0, y1=0;
	if (kierunek == brak) {
		swiat->komunikat(this, "nie moze sie ruszyc ");
		return;
	}
	if (kierunek == lewo) x1 = -predkosc;
	if (kierunek == prawo)x1 = predkosc;
	if (kierunek == gora)y1 = -predkosc;
	if (kierunek == dol)y1 = predkosc;
	if (swiat->getMapaOrganizmow()[getX() + x1][getY() + y1] == nullptr)swiat->przestawOrganizm(this, getX() + x1, getY() + y1);
	else {
		Organizm* inny = swiat->getMapaOrganizmow()[getX() + x1][getY() + y1];
		inny->kolizja(this);
	}
}
void Zwierze::kolizja(Organizm* atakujacy) {
	if (this->getSymbol() == atakujacy->getSymbol()) {
		//dziecko
		if (swiat->czySasiadujaceWolne(this->getX(), this->getY())) {
			koordynaty2 pole = swiat->znajdzWolnePole(this);	
			int x1 = pole.x, y1 = pole.y;	
			swiat->dodajOrganizm(getSymbol(), x1,  y1);	
			swiat->komunikat(this, "sie rozmnozyl");	
		}
		//else swiat->komunikat(this, "nie ma miejsca na rozmnazanie");	


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
