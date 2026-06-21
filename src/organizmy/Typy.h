#pragma once
#include <stdexcept>
#include <array>
#include <optional>
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

inline constexpr std::array wszystkieTypy = {
	TypOrganizmu::Czlowiek,
	TypOrganizmu::Antylopa,
	TypOrganizmu::Lis,
	TypOrganizmu::Owca,
	TypOrganizmu::Wilk,
	TypOrganizmu::Zolw,
	TypOrganizmu::BarszczSosnowskiego,
	TypOrganizmu::Mlecz,
	TypOrganizmu::Guarana,
	TypOrganizmu::Trawa,
	TypOrganizmu::WilczeJagody
};

struct koordynaty {
	int x;
	int y;
};

enum class Zdarzenie {
	Pokonanie,
	Rozmnozenie,
	Rozprzestrzenienie,
	BrakRuchu,
	Zatrucie,
	Przegnanie,
	AtakOdparty      
};

struct Komunikat {
	TypOrganizmu kto;
	Zdarzenie    co;
	std::optional<TypOrganizmu> kogo;
};

char typNaZnak(TypOrganizmu t);
TypOrganizmu znakNaTyp(char znak);
Wektor kierunekNaWektor(Kierunek k, int predkosc = 1);
Kierunek losowyKierunek();