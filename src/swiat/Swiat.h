#pragma once
#include "../organizmy/Organizm.h"
#include "Rng.h"
#include <vector>
#include <iostream>
#include <list>
#include <algorithm>
#include <queue>
#include <conio.h>
#include <random>
#include <optional>
struct koordynaty2 { //nie dzialalo dla zwyklych koordynatow
	int x;
	int y;
};
class Organizm;
class Czlowiek;
class Swiat
{
private:
	Rng rng;
	int tura;
	int szerokosc;
	int wysokosc;
	std::vector< std::vector< Organizm* > > mapaOrganizmow;
	std::list<std::unique_ptr<Organizm>> listaOrganizmow;
	std::queue<Organizm*> doUsuniecia;	
	std::queue<std::string> komunikaty;
	friend std::ostream& operator<<(std::ostream& out, const Swiat& swiat);	
	Czlowiek* czlowiek;
public:
	
	Swiat(int szerokosc, int wysokosc);

	//gettery
	int getSzerokosc() const { return szerokosc; }
	int getWysokosc() const { return wysokosc; }
	int getTura() const { return tura; }
	const std::vector< std::vector< Organizm* > >& getMapaOrganizmow() const { return mapaOrganizmow; }
	Organizm* getOrganizmZMapy(int x, int y) const;
	//std::list<std::unique_ptr<Organizm>>& getListaOrganizmow() const { return listaOrganizmow; }; nikt tego i tak nie uzywa?
	void ustawSwiat(); 
	void wykonajTure();
	Organizm* dodajOrganizm(TypOrganizmu typ, int x, int y);
	Organizm* dodajCzlowieka(int x, int y);
	void przestawOrganizm(Organizm* organizm,int x1, int x2);
	void przegonOrganizm(Organizm* atakujacy, Organizm* broniacy);
	void tarczaPrzegon(Organizm* atakujacy, Organizm* broniacy);
	void usunOrganizm(Organizm* organizm);
	void usunOrganizmyZListy();	
	bool czyRuchMozliwy(int x, int y) const;
	bool czyPoleWolne(int x, int y) const;
	bool czyWPlanszy(int x, int y) const;
	bool czySasiadujaceWolne(int x, int y, int predkosc = 1)const;
	void komunikat(Organizm* organizm, std::string text);
	void wyswietlKomunikaty();
	void zastapOrganizm(Organizm* atakujacy, Organizm* broniacy);
	bool jestZwierzeciem(Organizm* organizm);
	//void komunikat(Organizm* organizm, std::string text, Organizm* organizm2, std::strin text2);
	std::optional<koordynaty> znajdzWolnePole(Organizm* organizm) ;
	void zapiszDoPliku();
	void wczytajPlik(std::string& nazwaPliku, Organizm* czlowiek);
	bool czyCzlowiekZyje() const;
	void czlowiekUmiejetnosc();
	void czlowiekSetWejscie(char c);
};
