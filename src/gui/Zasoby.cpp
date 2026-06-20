#include "Zasoby.h"
#include <iostream>

static std::string plikDlaTypu(TypOrganizmu typ) {
    switch (typ) {
    case TypOrganizmu::Czlowiek:            return "assets/gracz.png";
    case TypOrganizmu::Wilk:                return "assets/wilk.png";
    case TypOrganizmu::Owca:                return "assets/owca.png";
    case TypOrganizmu::Lis:                 return "assets/lis.png";
    case TypOrganizmu::Zolw:                return "assets/zolw.png";
    case TypOrganizmu::Antylopa:            return "assets/antylopa.png";
    case TypOrganizmu::Trawa:               return "assets/trawa.png";
    case TypOrganizmu::Mlecz:               return "assets/mlecz.png";
    case TypOrganizmu::Guarana:             return "assets/guarana.png";
    case TypOrganizmu::WilczeJagody:        return "assets/jagody.png";
    case TypOrganizmu::BarszczSosnowskiego: return "assets/barszcz.png";
    default:                                return "";
    }
}

bool Zasoby::zaladuj() {
    bool ok = true;
    for (TypOrganizmu typ : wszystkieTypy)
        if (!tekstury[typ].loadFromFile(plikDlaTypu(typ))) ok = false;
    if (!czlowiekTarcza.loadFromFile("assets/gracz_tarcza.png")) ok = false;
    return ok;
}

const sf::Texture* Zasoby::teksturaDla(TypOrganizmu typ) const {
    auto it = tekstury.find(typ);
    return it == tekstury.end() ? nullptr : &it->second;
}