#pragma once
#include "Renderer.h"
#include <SFML/Graphics/RenderWindow.hpp>

class Swiat;

class App {
    sf::RenderWindow okno;
    Renderer renderer;
    Swiat& swiat;
public:
    App(Swiat& swiat, int kafelek = 51);
    ~App();
    void uruchom();
private:
    void przetworzZdarzenia();
    void rysujPanel();
};