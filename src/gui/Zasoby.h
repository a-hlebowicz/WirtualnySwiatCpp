#pragma once
#include "../organizmy/Typy.h"
#include <SFML/Graphics/Texture.hpp>
#include <unordered_map>

class Zasoby {
    std::unordered_map<TypOrganizmu, sf::Texture> tekstury;
    sf::Texture czlowiekTarcza;
public:
    bool zaladuj();
    const sf::Texture* teksturaDla(TypOrganizmu typ) const;
    const sf::Texture* teksturaCzlowiekZTarcza() const { return &czlowiekTarcza; }
};