#include "Lis.h"
#include "../swiat/Swiat.h"
Lis::Lis(Swiat* swiat, Rng& rng, int x, int y) : Zwierze(swiat, rng, x, y, TypOrganizmu::Lis, 3, 7) {}

std::optional<Wektor> Lis::zaplanujRuchLis() {
	const std::array<Kierunek, 4> wszystkieKierunki = {
		Kierunek::lewo, Kierunek::prawo, Kierunek::gora, Kierunek::dol
	};
	std::vector<Wektor> mozliweWektory;
	mozliweWektory.reserve(4);

	for (Kierunek k : wszystkieKierunki) {
		Wektor w = kierunekNaWektor(k);
		if (swiat->czyRuchMozliwy(getX() + w.x, getY() + w.y))
			if (swiat->getMapaOrganizmow()[getX() + w.x][getY() + w.y] == nullptr ||
				swiat->getMapaOrganizmow()[getX() + w.x][getY() + w.y]->getSila() <= getSila())mozliweWektory.push_back(w);
	}

	if (mozliweWektory.empty()) {
		return std::nullopt;
	}

	int rngI = rng.losujIndeks(mozliweWektory.size());
	return mozliweWektory[rngI];
}



void Lis::akcja() {
	if (getWiek() == 0) {
		postarzWiek();
		return;
	}
	postarzWiek();

	auto w = zaplanujRuchLis();
	if (!w) {
		swiat->komunikat(this, Zdarzenie::BrakRuchu);
		return;
	}
	auto [dx, dy] = *w;
	int x = getX() + dx, y = getY() + dy;
	Organizm* inny = swiat->getOrganizmZMapy(x, y);
	if (inny == nullptr)swiat->przestawOrganizm(this, x, y);
	else inny->kolizja(this);
}

