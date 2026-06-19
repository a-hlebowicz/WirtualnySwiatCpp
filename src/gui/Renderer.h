#pragma once
#include "Zasoby.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>

class Swiat;

class Renderer {
    Zasoby zasoby;
    int kafelek;
public:
    explicit Renderer(int kafelek = 16);
    bool zaladujZasoby() { return zasoby.zaladuj(); }
    void rysuj(sf::RenderWindow& okno, const Swiat& swiat) const;
};