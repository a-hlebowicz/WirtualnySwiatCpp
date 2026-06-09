#include <iostream>
#include "swiat/Swiat.h"
#include "organizmy/Organizm.h"
#include "organizmy/Czlowiek.h"
//#include <conio.h>
using namespace std;

int main() {
	unsigned char a = -1;
	Swiat swiat(50,50);
	//Czlowiek czlowiek(&swiat, rand() % 20, rand() % 20);
	cout << "nowa gra - 1" << endl << "wczytaj - 2" << endl;
	while (a!='1' && a!='2')a = _getch();
	if (a=='1') {
	//swiat.dodajCzlowieka(&czlowiek);
	swiat.ustawSwiat();
	}
	
	if (a == '2') {
		cout << "podaj nazwe pliku ";
		string napis;
		cin >> napis;
		//swiat.wczytajPlik(napis, &czlowiek);
	}
	while (a!='0') {
		a=_getch();
		if (a == 'z') { swiat.zapiszDoPliku(); continue; }
		if (a == 'r') { 
			swiat.czlowiekUmiejetnosc();
			a = _getch();
		}
		if (swiat.czyCzlowiekZyje()) swiat.czlowiekSetWejscie(a);
		system("cls");
		swiat.wykonajTure();
		cout << swiat;
		swiat.wyswietlKomunikaty();
	}
	return 0;
}
