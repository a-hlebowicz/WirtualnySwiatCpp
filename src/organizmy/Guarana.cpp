#include "Guarana.h"
#include "../swiat/Swiat.h"
Guarana::Guarana(Swiat* swiat, Rng& rng, int x, int y): Roslina(swiat,rng,x,y, TypOrganizmu::Guarana,0){}

void Guarana::kolizja(Organizm* inny)
{
	if (this == inny)
		return;
	if (getSila() > inny->getSila())
	{
		swiat->komunikat(this, Zdarzenie::Pokonanie, inny);
		swiat->usunOrganizm(inny);
	}
	else if (getSila() < inny->getSila())
	{
		swiat->komunikat(inny, Zdarzenie::Pokonanie, this);
		inny->setSila(inny->getSila() + 3);
		swiat->zastapOrganizm(inny, this);
	}
	
}
