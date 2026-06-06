#pragma once

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
char typNaZnak(TypOrganizmu t);
TypOrganizmu znakNaTyp(char znak);
struct koordynaty {
	int x;
	int y;
};
class Swiat;
class Organizm
{
	koordynaty polozenie;
	TypOrganizmu typOrganizmu;
	int sila;
	int inicjatywa;
	int wiek;
protected:
	 Swiat* swiat;
public:
	Organizm(Swiat* swiat, int x, int y,TypOrganizmu typOrganizmu, int sila, int inicjatywa);

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

