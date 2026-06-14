#include "Typy.h"

Wektor kierunekNaWektor(Kierunek k, int predkosc) {
	switch (k) {
	case Kierunek::lewo:  return { -predkosc, 0 };
	case Kierunek::prawo: return { predkosc, 0 };
	case Kierunek::gora:  return { 0, -predkosc };
	case Kierunek::dol:   return { 0,  predkosc };
	}
	return { 0, 0 };
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