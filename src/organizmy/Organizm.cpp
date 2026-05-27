#include "Organizm.h"
Organizm::Organizm(Swiat* swiat, int x, int y, char symbol, int sila, int inicjatywa) {
	polozenie.x = x;
	polozenie.y = y;
	this->symbol = symbol;
	this->sila = sila;
	this->inicjatywa = inicjatywa;
	this->swiat = swiat;
	wiek = 0;
}
char Organizm::getSymbol() const {
	return symbol;
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

