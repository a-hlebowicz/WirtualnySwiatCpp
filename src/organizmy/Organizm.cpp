#include "Organizm.h"
#include "../swiat/Swiat.h"


Organizm::Organizm(Swiat* swiat, Rng &rng, int x, int y, TypOrganizmu typOrganizmu, int sila, int inicjatywa) : 
	swiat(swiat),
	rng(rng),
	polozenie{ x,y },
	typOrganizmu(typOrganizmu),
	sila(sila),
	inicjatywa(inicjatywa),
	wiek(0)
{

}

TypOrganizmu Organizm::getTyp() const {
	return typOrganizmu;
}


int Organizm::getSila() const { return sila; }
int Organizm::getInicjatywa() const { return inicjatywa; }
int Organizm::getX() const { return polozenie.x; }
int Organizm::getY() const { return polozenie.y; }
int Organizm::getWiek() const { return wiek; }

void Organizm::postarzWiek()
{
	wiek++;
}

void Organizm::setWiek(int a)
{
	wiek = a;
}

void Organizm::setSila(int a)
{
	sila = a;
}

void Organizm::setX(int x)
{
	this->polozenie.x = x;
}
void Organizm::setY(int y)
{
	this->polozenie.y = y;
}

