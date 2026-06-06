#include "Roslina.h"
#include "../swiat/Swiat.h"
//#define SZANSA_NA_ROZPRZESTRZENIENIE 20;
Roslina::Roslina(Swiat* swiat, Rng& rng, int x, int y, TypOrganizmu typOrganizmu, int sila) : Organizm(swiat,rng , x, y, typOrganizmu, sila, 0) {
}

void Roslina::akcja() {
	//bool czyRozprzestrzeni = rand() % SZANSA_NA_ROZPRZESTRZENIENIE;
	if (getWiek() <= 0) {
		postarzWiek();
		return;
	}
	postarzWiek();
	if (rng.losujProcent(5)) {
		if (swiat->czySasiadujaceWolne(getX(), getY()) == true) {
			koordynaty2 pole = swiat->znajdzWolnePole(this);
			int x1 = pole.x, y1 = pole.y;
			swiat->dodajOrganizm(this->getTyp(), x1, y1);
			swiat->komunikat(this, "sie rozprzestrzenil");
		}
	}
}
void Roslina::kolizja(Organizm* inny) {
	if (this == inny)
		return;
	if (getSila() > inny->getSila())
	{
		swiat->komunikat(inny, "atakuje ");
		swiat->komunikat(this, "wygrywa ");
		swiat->usunOrganizm(inny);
	}
	else if (getSila() < inny->getSila())
	{
		swiat->komunikat(inny, "atakuje ");
		swiat->komunikat(this, "przegrywa ");
		swiat->zastapOrganizm(inny, this);
	}
}