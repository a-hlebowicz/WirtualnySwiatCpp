#pragma once
#include "Organizm.h"
#include <array>
#include <optional>
constexpr int ILE_PROB = 20;

class Zwierze :
    public Organizm
{
	int predkosc;
public:
	Zwierze(Swiat* swiat, Rng& rng, int x, int y, TypOrganizmu typOrganizmu,int sila, int inicjatywa);
	void akcja() override;
	void kolizja(Organizm* inny) override;
	std::optional<Wektor> zaplanujRuch();
	int getPredkosc() const;
	void setPredkosc(int a);
};

