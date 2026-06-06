#pragma once
#include "Organizm.h"
enum class Kierunek {
	brak,
	lewo,
	prawo,
	gora,
	dol,
	umiejetnosc
};
class Zwierze :
    public Organizm
{
	int predkosc;
public:
	Zwierze(Swiat* swiat, int x, int y, TypOrganizmu typOrganizmu,int sila, int inicjatywa);
	virtual void akcja();
	virtual void kolizja(Organizm* inny);
	int getPredkosc() const;
	void setPredkosc(int a);
	Kierunek wybierzKierunek();
};

