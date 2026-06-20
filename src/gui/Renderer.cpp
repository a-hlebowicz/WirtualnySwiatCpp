#include "Renderer.h"
#include "../swiat/Swiat.h"
#include "../organizmy/Organizm.h"

Renderer::Renderer(int kafelek) : kafelek(kafelek) {}

void Renderer::rysuj(sf::RenderWindow& okno, const Swiat& swiat) const {
    for (int x = 1; x <= swiat.getSzerokosc(); ++x) {
        for (int y = 1; y <= swiat.getWysokosc(); ++y) {
            Organizm* org = swiat.getOrganizmZMapy(x, y);
            if (org == nullptr) continue;

            const sf::Texture* tex = zasoby.teksturaDla(org->getTyp());
            if (tex == nullptr) continue;

            sf::Vector2u rozmiar = tex->getSize();
            sf::Sprite sprite(*tex);
            sprite.setScale(sf::Vector2f(
                static_cast<float>(kafelek) / rozmiar.x,
                static_cast<float>(kafelek) / rozmiar.y));
            sprite.setPosition(sf::Vector2f((x - 1) * kafelek, (y - 1) * kafelek));
            okno.draw(sprite);
        }
    }
}