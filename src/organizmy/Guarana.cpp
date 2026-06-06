#include "Guarana.h"
#include "../swiat/Swiat.h"
Guarana::Guarana(Swiat* swiat, int x, int y): Roslina(swiat,x,y, TypOrganizmu::Guarana,0){}

void Guarana::kolizja(Organizm* inny)
{
	if (this == inny)
		return;
	if (getSila() > inny->getSila())
	{
		swiat->komunikat(inny, "atakuje ");
		swiat->komunikat(this, "wygrywa ");
		swiat->usunOrganizm(inny);
	}
	else if (getSila() < inny->getSila())
	{
		swiat->komunikat(inny, "atakuje ");
		swiat->komunikat(this, "przegrywa ");
		inny->setSila(inny->getSila() + 3);
		swiat->zastapOrganizm(inny, this);
	}
	
}
