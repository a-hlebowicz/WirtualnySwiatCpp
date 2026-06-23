#include "Zolw.h"
#include "../swiat/Swiat.h"
Zolw::Zolw(Swiat* swiat, Rng& rng, int x, int y) : Zwierze(swiat, rng, x, y, TypOrganizmu::Zolw, 2, 1) {}
void Zolw::akcja()
{
	postarzWiek();
	if (rng.losujProcent(25)) {   //sprawdzic ile procent w oryginale
		Zwierze::akcja();
		setWiek(getWiek() - 1);
	}
}
void Zolw::kolizja(Organizm* organizm)
{
	if (organizm->getSila() < 5 && organizm->getTyp() != getTyp()) {
		swiat->komunikat(this, Zdarzenie::AtakOdparty, organizm);
	}
	else Zwierze::kolizja(organizm);
}
;