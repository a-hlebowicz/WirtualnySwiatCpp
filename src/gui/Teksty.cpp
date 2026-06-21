#include "Teksty.h"
std::string nazwaTypu(TypOrganizmu t) {
    switch (t) {
    case TypOrganizmu::Czlowiek:            return "Czlowiek";
    case TypOrganizmu::Wilk:                return "Wilk";
    case TypOrganizmu::Owca:                return "Owca";
    case TypOrganizmu::Lis:                 return "Lis";
    case TypOrganizmu::Zolw:                return "Zolw";
    case TypOrganizmu::Antylopa:            return "Antylopa";
    case TypOrganizmu::Trawa:               return "Trawa";
    case TypOrganizmu::Mlecz:               return "Mlecz";
    case TypOrganizmu::Guarana:             return "Guarana";
    case TypOrganizmu::WilczeJagody:        return "Wilcze Jagody";
    case TypOrganizmu::BarszczSosnowskiego: return "Barszcz Sosnowskiego";
    default:                                return "?";
    }
}

std::string opisZdarzenia(Zdarzenie z) {
    switch (z) {
    case Zdarzenie::Pokonanie:               return "pokonuje";
    case Zdarzenie::Rozmnozenie:          return "sie rozmnozyl";
    case Zdarzenie::Rozprzestrzenienie: return "sie rozprzestrzenil";
    case Zdarzenie::BrakRuchu:          return "nie moze sie ruszyc";
    case Zdarzenie::Zatrucie:           return "zostal zatruty";
    case Zdarzenie::Przegnanie:         return "zostal przegnany";
    case Zdarzenie::AtakOdparty:        return "odpiera atak";
    default:                            return "";
    }
}

std::string tekstKomunikatu(const Komunikat& k) {
    return nazwaTypu(k.kto) + " " + opisZdarzenia(k.co);
}