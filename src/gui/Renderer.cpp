#include "Renderer.h"
#include "../swiat/Swiat.h"
#include "../organizmy/Organizm.h"

Renderer::Renderer(int kafelek) : kafelek(kafelek) {}

void Renderer::rysuj(sf::RenderWindow& okno, const Swiat& swiat) const {
    const float skala = kafelek / 16.f;
    for (int x = 1; swiat.getSzerokosc() >= x; x++) {
        for (int y = 1;swiat.getWysokosc() >= y; y++) {
            Organizm* org = swiat.getOrganizmZMapy(x, y);
            if (org == nullptr) continue;
            const sf::Texture* tex = zasoby.teksturaDla(org->getTyp());
            if (tex == nullptr) continue;
            sf::Sprite sprite(*tex);
            sprite.setScale(sf::Vector2f(skala, skala));
            sprite.setPosition(sf::Vector2f((x - 1) * kafelek, (y - 1) * kafelek));
            okno.draw(sprite);
        }
    }
}