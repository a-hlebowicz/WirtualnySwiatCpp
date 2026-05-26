#pragma once
#include "Organizm.h"
enum kierunki {
	brak,
	lewo,
	prawo,
	gora,
	dol,
	r
};
class Zwierze :
    public Organizm
{
	int predkosc;
public:
	Zwierze(Swiat* swiat, int x, int y,char symbol ,int sila, int inicjatywa);
	virtual void akcja();
	virtual void kolizja(Organizm* inny);
	int getPredkosc() const;
	void setPredkosc(int a);
	kierunki wybierzKierunek();
};

