#pragma once
#include "Organizm.h"
class Roslina :
    public Organizm
{
public:
	Roslina(Swiat* swiat,Rng& rng, int x, int y, TypOrganizmu typOrganizmu, int sila);
	void akcja() override;
	//virtual void kolizja(Organizm* inny);
	//void zrobDziecko(int x, int y);
	void kolizja(Organizm* inny) override;
};

