#include "Organizm.h"
Organizm::Organizm(Swiat* swiat, int x, int y, TypOrganizmu typOrganizmu, int sila, int inicjatywa) {
	polozenie.x = x;
	polozenie.y = y;
	this->typOrganizmu = typOrganizmu;
	this->sila = sila;
	this->inicjatywa = inicjatywa;
	this->swiat = swiat;
	wiek = 0;
}

TypOrganizmu Organizm::getTyp() const {
	return typOrganizmu;
}
char typNaZnak(TypOrganizmu t) {
	switch (t) {
	case TypOrganizmu::Trawa:               return 'T';
	case TypOrganizmu::Mlecz:               return 'M';
	case TypOrganizmu::Guarana:             return 'G';
	case TypOrganizmu::WilczeJagody:        return 'J';
	case TypOrganizmu::BarszczSosnowskiego: return 'B';
	case TypOrganizmu::Wilk:                return 'W';
	case TypOrganizmu::Owca:                return 'O';
	case TypOrganizmu::Lis:                 return 'L';
	case TypOrganizmu::Zolw:                return 'Z';
	case TypOrganizmu::Antylopa:            return 'A';
	case TypOrganizmu::Czlowiek:            return 'X';
	}
	return '?';
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

