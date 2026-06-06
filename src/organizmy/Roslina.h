#pragma once
#include "Organizm.h"
class Roslina :
    public Organizm
{
public:
	Roslina(Swiat* swiat, int x, int y, TypOrganizmu typOrganizmu, int sila);
	virtual void akcja();
	//virtual void kolizja(Organizm* inny);
	//void zrobDziecko(int x, int y);
	virtual void kolizja(Organizm* inny) ;
};

