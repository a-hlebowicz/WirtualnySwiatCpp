#pragma once
#include "Organizm.h"
constexpr int ILE_PROB = 20;

class Zwierze :
    public Organizm
{
	int predkosc;
public:
	Zwierze(Swiat* swiat, Rng& rng, int x, int y, TypOrganizmu typOrganizmu,int sila, int inicjatywa);
	void akcja() override;
	void kolizja(Organizm* inny) override;
	int getPredkosc() const;
	void setPredkosc(int a);
	Kierunek wybierzKierunek();
};

