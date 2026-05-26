#include "Zolw.h"
Zolw::Zolw(Swiat* swiat, int x, int y) : Zwierze(swiat, x, y, 'Z', 2, 1) {}
void Zolw::akcja()
{
	postarzWiek();
	if (rand() % 4 == 1) {
		Zwierze::akcja();
		setWiek(getWiek() - 1);
	}
}
void Zolw::kolizja(Organizm* organizm)
{
	if (organizm->getSila() < 5 && organizm->getSymbol()!=getSymbol()) {
		swiat->komunikat(organizm, "bezskutecznie zaatakowal zolwia");
	}
	else Zwierze::kolizja(organizm);
}
;