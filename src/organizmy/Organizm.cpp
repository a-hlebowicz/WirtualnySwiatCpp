#include "Organizm.h"
#include "../swiat/Swiat.h"
#include <stdexcept>

Wektor kierunekNaWektor(Kierunek k, int predkosc = 1) {
	switch (k) {
	case Kierunek::lewo:  return { -predkosc, 0 };
	case Kierunek::prawo: return { predkosc, 0 };
	case Kierunek::gora:  return { 0, -predkosc };
	case Kierunek::dol:   return { 0,  predkosc };
	default:              return { 0, 0 };
	}
}

Kierunek losowyKierunek() {
	
}


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
TypOrganizmu znakNaTyp(char znak) {
	switch (znak) {
	case 'T': return TypOrganizmu::Trawa;
	case 'M': return TypOrganizmu::Mlecz;
	case 'G': return TypOrganizmu::Guarana;
	case 'J': return TypOrganizmu::WilczeJagody;
	case 'B': return TypOrganizmu::BarszczSosnowskiego;
	case 'W': return TypOrganizmu::Wilk;
	case 'O': return TypOrganizmu::Owca;
	case 'L': return TypOrganizmu::Lis;
	case 'Z': return TypOrganizmu::Zolw;
	case 'A': return TypOrganizmu::Antylopa;
	case 'X': return TypOrganizmu::Czlowiek;
	default:  throw std::invalid_argument("Niepoprawny znak organizmu!");
	}
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

