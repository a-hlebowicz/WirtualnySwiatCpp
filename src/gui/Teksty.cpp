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
    case TypOrganizmu::WilczeJagody:        return "Wilcza Jagoda";
    case TypOrganizmu::BarszczSosnowskiego: return "Barszcz Sosnowskiego";
    default:                                return "?";
    }
}

std::string opisZdarzenia(Zdarzenie z) {
    switch (z) {
    case Zdarzenie::Pokonanie:               return "pokonuje";
    case Zdarzenie::Rozmnozenie:          return "sie rozmnaza";
    case Zdarzenie::Rozprzestrzenienie: return "sie rozprzestrzenia";
    case Zdarzenie::BrakRuchu:          return "nie moze sie ruszyc";
    case Zdarzenie::Zatrucie:           return "zatruwa";
    case Zdarzenie::Przegnanie:         return "przegania";
    case Zdarzenie::AtakOdparty:        return "odpiera atak";
    default:                            return "";
    }
}

std::string odbiorcaZdarzenia(TypOrganizmu t){
    switch (t) {
    case TypOrganizmu::Czlowiek:            return "Czlowieka";
    case TypOrganizmu::Wilk:                return "Wilka";
    case TypOrganizmu::Owca:                return "Owce";
    case TypOrganizmu::Lis:                 return "Lisa";
    case TypOrganizmu::Zolw:                return "Zolwia";
    case TypOrganizmu::Antylopa:            return "Antylope";
    case TypOrganizmu::Trawa:               return "Trawe";
    case TypOrganizmu::Mlecz:               return "Mlecza";
    case TypOrganizmu::Guarana:             return "Guarane";
    case TypOrganizmu::WilczeJagody:        return "Wilcza Jagode";
    case TypOrganizmu::BarszczSosnowskiego: return "Barszcz Sosnowskiego";
    default:                                return "?";
    }
}

std::string tekstKomunikatu(const Komunikat& k) {
    std::string s = nazwaTypu(k.kto) + " " + opisZdarzenia(k.co);
    if (k.kogo) s += " " + odbiorcaZdarzenia(*k.kogo);
    return s;
}