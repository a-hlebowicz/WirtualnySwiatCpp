#pragma once
#include "Organizm.h"

class Zwierze :
    public Organizm
{
	int predkosc;
public:
	Zwierze(Swiat* swiat, Rng& rng, int x, int y, TypOrganizmu typOrganizmu,int sila, int inicjatywa);
	virtual void akcja();
	virtual void kolizja(Organizm* inny);
	int getPredkosc() const;
	void setPredkosc(int a);
	Kierunek wybierzKierunek();
};

