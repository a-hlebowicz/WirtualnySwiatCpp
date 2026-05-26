#include"Swiat.h"
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
	this->szerokosc = szerokosc++; // aby indeksowac od 1 nie od 0
	this->wysokosc = wysokosc++; 
	tura = 0;	
	mapaOrganizmow = std::vector< std::vector<Organizm*> >(szerokosc, std::vector<Organizm*>(wysokosc, nullptr));
}

Organizm* Swiat::dodajOrganizm(char symbol,int x, int y) {
	Organizm* organizm = nullptr;
	if (mapaOrganizmow[x][y] != nullptr)std::cout << "pole " << x << " , " << y << " jest zajete";
	else 
	{
		if (symbol == 'T')organizm = new Trawa(this, x, y);
		if (symbol == 'M')organizm = new Mlecz(this, x, y);
		if (symbol == 'W')organizm = new Wilk(this, x, y);
		if (symbol == 'O')organizm = new Owca(this, x, y);
		if (symbol == 'L')organizm = new Lis(this, x, y);
		if (symbol == 'Z')organizm = new Zolw(this, x, y);
		if (symbol == 'A')organizm = new Antylopa(this, x, y);
		if (symbol == 'G')organizm = new Guarana(this, x, y);
		if (symbol == 'J')organizm = new WilczeJagody(this, x, y);
		if (symbol == 'B')organizm = new BarszczSosnowskiego(this, x, y);

		if (organizm != nullptr) {
			mapaOrganizmow[organizm->getX()][organizm->getY()] = organizm;
			listaOrganizmow.push_back(organizm);
		}
	}
	return organizm;
}
void Swiat::dodajCzlowieka(Organizm* organizm)
{
	mapaOrganizmow[organizm->getX()][organizm->getY()] = organizm;
	listaOrganizmow.push_back(organizm);
}
void color(int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void ustawKolor(char symbol) {
	switch (symbol)
	{
	case 'T':
		color(10);
		break;
	case 'M':
		color(14);
		break;
	case 'G':
		color(13);
		break;
	case 'J':
		color(12);
		break;
	case 'B':
		color(4);
		break;
	case 'X':
		color(11);
		break;
	case 'W':
		color(8);
		break;
	case 'O':
		color(15);
		break;
	case 'Z':
		color(2);
		break;
	case 'L':
		color(6);
		break;
	case 'A':
		color(6);
		break;
	default:
		color(15);
		break;
	}
}
std::ostream& operator<<(std::ostream& out, const Swiat& swiat ) {
	char symbol;
	out <<"tura: " << swiat.getTura() << std::endl;
	for (int i = 0; swiat.getWysokosc()+1 >= i; i++) {
		for (int j = 0; swiat.getSzerokosc()+1 >= j; j++) {
			if (i == 0 || j == 0 || i == swiat.getWysokosc() + 1 || j == swiat.getWysokosc() + 1)out << '*';
			else if (swiat.getMapaOrganizmow()[j][i] != nullptr) {
				symbol = swiat.getMapaOrganizmow()[j][i]->getSymbol();
				ustawKolor(symbol);
				out << symbol;
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
	inline bool operator() (const Organizm* organizm1, const Organizm* organizm2) {
		if (organizm1->getInicjatywa() != organizm2->getInicjatywa())
			return (organizm1->getInicjatywa() > organizm2->getInicjatywa());
		else return (organizm1->getWiek() > organizm2->getWiek());
		
	}
};

void Swiat::ustawSwiat()
{
	dodajOrganizm('W', rand() % 20, rand() % 20);
	dodajOrganizm('W', rand() % 20, rand() % 20);
	dodajOrganizm('O', rand() % 20, rand() % 20);
	dodajOrganizm('O', rand() % 20, rand() % 20);
	dodajOrganizm('Z', rand() % 20, rand() % 20);
	dodajOrganizm('Z', rand() % 20, rand() % 20);
	dodajOrganizm('A', rand() % 20, rand() % 20);
	dodajOrganizm('A', rand() % 20, rand() % 20);
	dodajOrganizm('L', rand() % 20, rand() % 20);
	dodajOrganizm('L', rand() % 20, rand() % 20);
	dodajOrganizm('T', rand() % 20, rand() % 20);
	dodajOrganizm('T', rand() % 20, rand() % 20);
	dodajOrganizm('M', rand() % 20, rand() % 20);
	dodajOrganizm('M', rand() % 20, rand() % 20);
	dodajOrganizm('J', rand() % 20, rand() % 20);
	dodajOrganizm('J', rand() % 20, rand() % 20);
	dodajOrganizm('B', rand() % 20, rand() % 20);
	dodajOrganizm('B', rand() % 20, rand() % 20);
	dodajOrganizm('G', rand() % 20, rand() % 20);
	dodajOrganizm('G', rand() % 20, rand() % 20);
}

void Swiat::wykonajTure() {
	tura++;
	listaOrganizmow.sort(ktoPierwszy());	
	for (Organizm* organizm : listaOrganizmow) {
		if (mapaOrganizmow[organizm->getX()][organizm->getY()]==organizm)organizm->akcja();
	}
	usunOrganizmyZListy();
}
bool Swiat::czyRuchMozliwy (int x, int y) {
	if (x<1 || x>szerokosc || y<1 || y>wysokosc)return false;
	return true;
}
bool Swiat::czyPoleWolne(int x, int y) {	
	if (x<1 || x>szerokosc || y<1 || y>wysokosc)return false;
	if (mapaOrganizmow[x][y] == nullptr)return true;
	return false;
}
bool Swiat::czySasiadujaceWolne(int x, int y) {
	bool a = czyPoleWolne(x + 1, y) + czyPoleWolne(x, y + 1) + czyPoleWolne(x - 1, y) + czyPoleWolne(x, y - 1);
	return a;
}
bool Swiat::czySasiadujaceWolnePredkosc(int x, int y, int predkosc) {
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
	/*atakujacy->setX(broniacy->getX());
	atakujacy->setY(broniacy->getY());
	mapaOrganizmow[atakujacy->getX()][atakujacy->getY()] = atakujacy;*/

	koordynaty2 pole=znajdzWolnePole(broniacy);
	int stary_x = broniacy->getX(), stary_y = broniacy->getY();
	przestawOrganizm(broniacy, pole.x, pole.y);
	przestawOrganizm(atakujacy, stary_x, stary_y);
	/*broniacy->setX(pole.x);
	broniacy->setY(pole.y);
	mapaOrganizmow[broniacy->getX()][broniacy->getY()] = broniacy;*/
}
void Swiat::tarczaPrzegon(Organizm* atakujacy, Organizm* broniacy) {
	koordynaty2 pole = znajdzWolnePole(broniacy);
	przestawOrganizm(atakujacy, pole.x, pole.y);
}
void Swiat::usunOrganizmyZListy() {
	while (!doUsuniecia.empty()) {
		Organizm* organizm = doUsuniecia.front();
		doUsuniecia.pop();
		auto it = std::find(listaOrganizmow.begin(), listaOrganizmow.end(), organizm);
		if (it != listaOrganizmow.end()) {
			listaOrganizmow.erase(it);
		}
		if (organizm->getSymbol() == 'X')organizm->setSila(-1);
		else delete organizm;
	}
}

void Swiat::komunikat(Organizm* organizm, std::string text){
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

void Swiat::zastapOrganizm(Organizm* atakujacy, Organizm* broniacy)
{
	int nowy_x = broniacy->getX(), nowy_y = broniacy->getY();
	usunOrganizm(broniacy);
	przestawOrganizm(atakujacy, nowy_x, nowy_y);
}

bool Swiat::jestZwierzeciem(Organizm* organizm)
{
	if (organizm == nullptr)return false;
	if (organizm->getSymbol() == 'O')return true;
	if (organizm->getSymbol() == 'W')return true;
	if (organizm->getSymbol() == 'L')return true;
	if (organizm->getSymbol() == 'A')return true;
	if (organizm->getSymbol() == 'Z')return true;
	if (organizm->getSymbol() == 'X')return true;
	return false;
}

koordynaty2 Swiat::znajdzWolnePole(Organizm* organizm)
{
	int x1 = 0, y1 = 0, i=0;
	koordynaty2 pole;
	while (1) {
		if (i > 50) {
			komunikat(organizm, "nie znaleziono wolnego pola ");
			pole.x = organizm->getX()+0; pole.y = organizm->getY() + 0;
			return pole;
		}
		int a = rand() % 4;
		if (a == 0) { x1 = 1; y1 = 0; }
		if (a == 1) { x1 = -1; y1 = 0; }
		if (a == 2) { x1 = 0; y1 = 1; }
		if (a == 3) { x1 = 0; y1 = -1; }
		if (czyPoleWolne(organizm->getX() + x1, organizm->getY() + y1)) {
			pole.x = organizm->getX() + x1;
			pole.y = organizm->getY() + y1;
			return pole;
		}
	}
}
void Swiat::zapiszDoPliku() {
	std::string napis;
	std::cout << "podaj nazwe pliku ";
	std::cin >> napis;
	std::string& nazwaPliku = napis;
	std::ofstream plik(nazwaPliku);
	if (plik.is_open()) {
		plik << tura << std::endl;
		for (Organizm* organizm : listaOrganizmow) {
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
				Organizm* organizm = dodajOrganizm(symbol, x, y);
				organizm->setSila(sila);
				organizm->setWiek(wiek);
			}
		}
	}
}

