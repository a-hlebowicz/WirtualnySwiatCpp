#pragma once
#include "Typy.h"
class Swiat;
class Rng;
class Organizm
{
	koordynaty polozenie;
	TypOrganizmu typOrganizmu;
	int sila;
	int inicjatywa;
	int wiek;
protected:
	 Swiat* swiat;
	 Rng& rng;
public:
	Organizm(Swiat* swiat, Rng& rng, int x, int y,TypOrganizmu typOrganizmu, int sila, int inicjatywa);

	virtual void akcja() = 0;
	virtual void kolizja(Organizm* inny) = 0;


	//gettery
	char getSymbol() const { return typNaZnak(typOrganizmu); }
	TypOrganizmu getTyp() const;
	int getSila() const;
	int getInicjatywa() const;
	int getX() const;
	int getY() const;
	int getWiek() const;
	void postarzWiek();
	void setWiek(int a);
	void setSila(int a);
	void setX(int x);
	void setY(int y);
	virtual ~Organizm() = default;
};

