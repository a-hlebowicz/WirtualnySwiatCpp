#pragma once
#include <stdexcept>

enum class Kierunek {
	brak,
	lewo,
	prawo,
	gora,
	dol,
	umiejetnosc
};

struct Wektor
{
	int x;
	int y;
};


enum class TypOrganizmu {
	Czlowiek,
	Antylopa,
	Lis,
	Owca,
	Wilk,
	Zolw,
	BarszczSosnowskiego,
	Mlecz,
	Guarana,
	Trawa,
	WilczeJagody
};

struct koordynaty {
	int x;
	int y;
};

char typNaZnak(TypOrganizmu t);
TypOrganizmu znakNaTyp(char znak);
Wektor kierunekNaWektor(Kierunek k, int predkosc = 1);
Kierunek losowyKierunek();