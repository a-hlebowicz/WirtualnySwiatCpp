#include"Swiat.h"
#include"../organizmy/Czlowiek.h"
#include"../organizmy/Trawa.h"
#include"../organizmy/Mlecz.h"
#include"../organizmy/Wilk.h"
#include"../organizmy/Owca.h"
#include "../organizmy/Lis.h"
#include"../organizmy/Zolw.h"
#include "../organizmy/Antylopa.h"
#include "../organizmy/Guarana.h"
#include "../organizmy/WilczeJagody.h"
#include "../organizmy/BarszczSosnowskiego.h"
#include <fstream>
#include <Windows.h>



Swiat::Swiat(int szerokosc, int wysokosc) {
	this->szerokosc = szerokosc++;
	this->wysokosc = wysokosc++; 
	tura = 0;
	czlowiek = nullptr;
	mapaOrganizmow = std::vector< std::vector<Organizm*> >(szerokosc, std::vector<Organizm*>(wysokosc, nullptr));
}

Organizm* Swiat::getOrganizmZMapy(int x, int y) const {
	if (!czyWPlanszy(x, y)) return nullptr;
	return mapaOrganizmow[x][y];
}

Organizm* Swiat::dodajCzlowieka(int x, int y) {
	std::unique_ptr<Czlowiek> czlowiek  = std::make_unique <Czlowiek>(this, this->rng, x, y);
	Organizm* obs = czlowiek.get();
	this->czlowiek = czlowiek.get();
	mapaOrganizmow[obs->getX()][obs->getY()] = obs;
	listaOrganizmow.push_back(std::move(czlowiek));
	return obs;
}

Organizm* Swiat::dodajOrganizm(TypOrganizmu typ,int x, int y) {
	/*
	TODO
	zmienic wypisaywanie cout na komunikat
	*/
	if (mapaOrganizmow[x][y] != nullptr) {
		std::cout << "pole " << x << " , " << y << " jest zajete \n";
		return nullptr;
	}
	std::unique_ptr<Organizm> organizm;
	if (typ == TypOrganizmu::Czlowiek) {
		Organizm* obs = dodajCzlowieka(x, y);
		return obs;
	} 
	if (typ == TypOrganizmu::Trawa )organizm = std::make_unique <Trawa>(this,this->rng, x, y);
	if (typ == TypOrganizmu::Mlecz )organizm = std::make_unique <Mlecz>(this, this->rng, x, y);
	if (typ == TypOrganizmu::Wilk )organizm = std::make_unique <Wilk>(this, this->rng, x, y);
	if (typ == TypOrganizmu::Owca )organizm = std::make_unique <Owca>(this, this->rng, x, y);
	if (typ == TypOrganizmu::Lis )organizm = std::make_unique <Lis>(this, this->rng, x, y);
	if (typ == TypOrganizmu::Zolw )organizm = std::make_unique <Zolw>(this, this->rng, x, y);
	if (typ == TypOrganizmu::Antylopa )organizm = std::make_unique <Antylopa>(this, this->rng, x, y);
	if (typ == TypOrganizmu::Guarana )organizm = std::make_unique <Guarana>(this, this->rng, x, y);
	if (typ == TypOrganizmu::WilczeJagody )organizm = std::make_unique <WilczeJagody>(this, this->rng, x, y);
	if (typ == TypOrganizmu::BarszczSosnowskiego )organizm = std::make_unique <BarszczSosnowskiego>(this, this->rng, x, y);

	if (organizm == nullptr) {
		std::cout << "nie mozna stworzyc organizmu \n";
		return nullptr;
	}
	Organizm* obs = organizm.get();
	mapaOrganizmow[obs->getX()][obs->getY()] = obs;
	listaOrganizmow.push_back(std::move(organizm));
	
	return obs;
}
/*
void Swiat::dodajCzlowieka(Organizm* organizm)
{
	mapaOrganizmow[organizm->getX()][organizm->getY()] = organizm;
	listaOrganizmow.push_back(organizm);
}
*/
void color(int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void ustawKolor(TypOrganizmu typ) {
	switch (typ) {
		case TypOrganizmu::Trawa:               color(10); break;
		case TypOrganizmu::Mlecz:               color(14); break;
		case TypOrganizmu::Guarana:             color(13); break;
		case TypOrganizmu::WilczeJagody:        color(12); break;
		case TypOrganizmu::BarszczSosnowskiego: color(4);  break;
		case TypOrganizmu::Wilk:                color(8);  break;
		case TypOrganizmu::Owca:                color(15); break;
		case TypOrganizmu::Zolw:                color(2);  break;
		case TypOrganizmu::Lis:                 color(6);  break;
		case TypOrganizmu::Antylopa:            color(6);  break;
		case TypOrganizmu::Czlowiek:            color(11); break;
		default:                                color(15); break;
	}
	}
std::ostream& operator<<(std::ostream& out, const Swiat& swiat ) {
	TypOrganizmu typ;
	out <<"tura: " << swiat.getTura() << std::endl;
	for (int i = 0; swiat.getWysokosc()+1 >= i; i++) {
		for (int j = 0; swiat.getSzerokosc()+1 >= j; j++) {
			if (i == 0 || j == 0 || i == swiat.getWysokosc() + 1 || j == swiat.getWysokosc() + 1)out << '*';
			else if (swiat.getMapaOrganizmow()[j][i] != nullptr) {
				typ = swiat.getMapaOrganizmow()[j][i]->getTyp();
				ustawKolor(typ);
				out << typNaZnak(typ);
				color(15);
			}
			else out << " ";
			out << " ";
		}
		out << std::endl;
		//out << std::endl;
	}
	out << std::endl;
	return out;
}

struct ktoPierwszy {
	inline bool operator() (const std::unique_ptr<Organizm>& organizm1, const std::unique_ptr<Organizm>& organizm2) {
		if (organizm1->getInicjatywa() != organizm2->getInicjatywa())
			return (organizm1->getInicjatywa() > organizm2->getInicjatywa());
		else return (organizm1->getWiek() > organizm2->getWiek());
		
	}
};

bool Swiat::jestZwierzeciem(Organizm* organizm)
{
	if (organizm == nullptr)return false;
	switch (organizm->getTyp()) {
	case TypOrganizmu::Owca:
	case TypOrganizmu::Wilk:
	case TypOrganizmu::Lis:
	case TypOrganizmu::Antylopa:
	case TypOrganizmu::Zolw:
	case TypOrganizmu::Czlowiek:
		return true;
	default:
		return false;
	}
}

void Swiat::ustawSwiat()
{
	int p = szerokosc * wysokosc;

	// liczba kazdego organizmu = sqrt(pole)/10
	int n = static_cast<int>(std::sqrt(p) / 10);
	if (n <= 0)n = 1;
	
	dodajOrganizm(TypOrganizmu::Czlowiek, rng.losujInt(1, szerokosc), rng.losujInt(1, wysokosc));

	const std::array<TypOrganizmu, 10> gatunki = {
		TypOrganizmu::Wilk,
		TypOrganizmu::Owca,
		TypOrganizmu::Zolw,
		TypOrganizmu::Antylopa,
		TypOrganizmu::Lis,
		TypOrganizmu::Trawa,
		TypOrganizmu::Mlecz,
		TypOrganizmu::WilczeJagody,
		TypOrganizmu::BarszczSosnowskiego,
		TypOrganizmu::Guarana
	};

	for (TypOrganizmu typ : gatunki) {
		for (int i = 0;n > i;i++) {
			dodajOrganizm(typ, rng.losujInt(1, szerokosc), rng.losujInt(1, wysokosc));
		}
	}
}

void Swiat::wykonajTure() {
	tura++;
	listaOrganizmow.sort(ktoPierwszy());	
	for (const auto& organizm : listaOrganizmow) {
		if (mapaOrganizmow[organizm->getX()][organizm->getY()]==organizm.get())organizm->akcja();			//TODO metoda czyZyje
	}
	usunOrganizmyZListy();
}
bool Swiat::czyRuchMozliwy (int x, int y) const {
	return czyWPlanszy(x,y);
}
bool Swiat::czyWPlanszy(int x, int y) const {
	if (x<1 || x>szerokosc || y<1 || y>wysokosc)return false;
	return true;
}
bool Swiat::czyPoleWolne(int x, int y) const {
	if (x<1 || x>szerokosc || y<1 || y>wysokosc)return false;
	if (mapaOrganizmow[x][y] == nullptr)return true;
	return false;
}

bool Swiat::czySasiadujaceWolne(int x, int y, int predkosc) const {
	bool a = czyPoleWolne(x + predkosc, y) + czyPoleWolne(x, y + predkosc) + czyPoleWolne(x - predkosc, y) + czyPoleWolne(x, y - predkosc);
	return a;
}

void Swiat::usunOrganizm(Organizm* organizm)
{
	mapaOrganizmow[organizm->getX()][organizm->getY()] = nullptr;
	doUsuniecia.push(organizm);
	
}
void Swiat::przestawOrganizm(Organizm* organizm, int x1, int y1)
{
	mapaOrganizmow[organizm->getX()][organizm->getY()] = nullptr;
	organizm->setX(x1);
	organizm->setY(y1);
	mapaOrganizmow[organizm->getX()][organizm->getY()] = organizm;
	
}
void Swiat::przegonOrganizm(Organizm* atakujacy, Organizm* broniacy) {
	auto pole=znajdzWolnePole(broniacy);
	if (!pole) {

		return;
	}
	int stary_x = broniacy->getX(), stary_y = broniacy->getY();
	przestawOrganizm(broniacy, pole->x, pole->y);
	przestawOrganizm(atakujacy, stary_x, stary_y);
}
void Swiat::tarczaPrzegon(Organizm* atakujacy, Organizm* broniacy) {
	auto pole = znajdzWolnePole(broniacy);
	if (!pole) {

		return;
	}
	przestawOrganizm(atakujacy, pole->x, pole->y);
}
void Swiat::usunOrganizmyZListy() {
	while (!doUsuniecia.empty()) {
		Organizm* organizm = doUsuniecia.front();
		doUsuniecia.pop();
		if (organizm->getTyp() == TypOrganizmu::Czlowiek) czlowiek = nullptr;
		listaOrganizmow.remove_if([&](const std::unique_ptr<Organizm>& p) {
			return p.get() == organizm;
		});
		//if (organizm->getSymbol() == 'X')organizm->setSila(-1);
		//else delete organizm;
	}
}


void Swiat::zastapOrganizm(Organizm* atakujacy, Organizm* broniacy) {
	int nowy_x = broniacy->getX(), nowy_y = broniacy->getY();
	usunOrganizm(broniacy);
	przestawOrganizm(atakujacy, nowy_x, nowy_y);
}

std::optional<koordynaty> Swiat::znajdzWolnePole(Organizm* organizm) {
	const std::array<Kierunek, 4> wszystkieKierunki = {
		Kierunek::lewo, Kierunek::prawo, Kierunek::gora, Kierunek::dol
	};
	std::vector<koordynaty> wolnePola;
	wolnePola.reserve(4);

	for (Kierunek k : wszystkieKierunki) {
		Wektor w = kierunekNaWektor(k);
		int x = organizm->getX() + w.x;
		int y = organizm->getY() + w.y;
		if (czyPoleWolne(x, y)) wolnePola.push_back(koordynaty{ x, y });
	}

	if (wolnePola.empty()) {
		return std::nullopt;
	}

	int rngI = rng.losujIndeks(wolnePola.size());
	return wolnePola[rngI];
}



bool Swiat::czyCzlowiekZyje() const {
	if (czlowiek != nullptr)return true;
	return false;
}
void Swiat::czlowiekUmiejetnosc() {
	if (!czyCzlowiekZyje()) return;
	if (czlowiek->getUmiejetnosc() > 0) return;
	czlowiek->aktywujUmietnosc();
	return;
}

void Swiat::czlowiekSetWejscie(char c) {
	if (!czyCzlowiekZyje()) return;
	czlowiek->setWejscie(c);
}

bool Swiat::czyCzlowiekZTarcza() const {
	return czlowiek != nullptr && czlowiek->czyTarczaAktywna();
}


//=============================


void Swiat::komunikat(Organizm* organizm, std::string text) {
	std::string napis;
	napis = organizm->getSymbol();
	text = ":" + text;
	napis = napis + text;
	komunikaty.push(napis);
}

void Swiat::wyswietlKomunikaty()
{
	while (!komunikaty.empty()) {
		std::cout << komunikaty.front() << std::endl;
		komunikaty.pop();
	}
}

//================================
void Swiat::zapiszDoPliku() {
	std::string napis;
	std::cout << "podaj nazwe pliku ";
	std::cin >> napis;
	std::string& nazwaPliku = napis;
	std::ofstream plik(nazwaPliku);
	if (plik.is_open()) {
		plik << tura << std::endl;
		for (const auto& organizm : listaOrganizmow) {
			plik << organizm->getSymbol() << " ";
			plik << organizm->getX() << " " <<organizm->getY() << " ";
			plik << organizm->getSila() << " ";
			plik << organizm->getWiek() << " ";
			plik << std::endl;
		}
		plik << 'K';
	}
	else std::cout << "nie udalo sie otworzyc pliku";
}

void Swiat::wczytajPlik(std::string& nazwaPliku, Organizm* czlowiek)
{
	std::ifstream plik(nazwaPliku);
	if (plik.is_open()) {
		plik >> tura;
		while (!plik.eof()) {
			char symbol;
			int x, y, sila, wiek;
			plik >> symbol >> x >> y >> sila >> wiek;
			if (symbol == 'K')break;
			if (symbol == 'X') {
				czlowiek->setX(x);
				czlowiek->setY(y);
				czlowiek->setSila(sila);
				czlowiek->setWiek(wiek);
			}
			else {
				Organizm* organizm = dodajOrganizm(znakNaTyp(symbol), x, y);
				organizm->setSila(sila);
				organizm->setWiek(wiek);
			}
		}
	}
}

