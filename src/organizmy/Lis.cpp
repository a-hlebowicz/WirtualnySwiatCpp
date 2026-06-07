#include "Lis.h"
#include "../swiat/Swiat.h"
Lis::Lis(Swiat* swiat, Rng& rng, int x, int y) : Zwierze(swiat, rng, x, y, TypOrganizmu::Lis, 3, 7) {}
void Lis::akcja()
{
	if (getWiek() == 0) {
		postarzWiek();
		return;
	}
	postarzWiek();
	Kierunek kierunek = wybierzKierunekLis();
	int x1=0, y1=0;
	if (kierunek == Kierunek::brak) {
		swiat->komunikat(this, "nie moze sie ruszyc ");
		return;
	}
	if (kierunek == Kierunek::lewo) x1 = -1;
	if (kierunek == Kierunek::prawo)x1 = 1;
	if (kierunek == Kierunek::gora)y1 = -1;
	if (kierunek == Kierunek::dol)y1 = 1;
	if (swiat->getMapaOrganizmow()[getX() + x1][getY() + y1] == nullptr)swiat->przestawOrganizm(this, getX() + x1, getY() + y1);
	else {
		Organizm* inny = swiat->getMapaOrganizmow()[getX() + x1][getY() + y1];
		inny->kolizja(this);
	}
}
Kierunek Lis::wybierzKierunekLis()
{
	Kierunek kierunek = Kierunek::brak;
	for (int i = 0;ILE_PROB > i;i++) {
		kierunek = rng.losowyKierunek();
		auto [dx, dy] = kierunekNaWektor(kierunek);
		if (swiat->czyRuchMozliwy(getX() + dx, getY() + dy))
			if (swiat->getMapaOrganizmow()[getX() + dx][getY() + dy] == nullptr || 
				swiat->getMapaOrganizmow()[getX() + dx][getY() + dy]->getSila() <= getSila()) return kierunek;
	}
	std::cout << "nie znaleziono kierunku ";
	return Kierunek::brak;
}
;
