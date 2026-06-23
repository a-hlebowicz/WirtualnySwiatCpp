#include "App.h"
#include "../swiat/Swiat.h"
#include <imgui.h>
#include <imgui-SFML.h>
#include <SFML/System/Clock.hpp>
#include "Teksty.h"
#include <SFML/Window/Keyboard.hpp>

static sf::VideoMode trybDla(const Swiat& swiat, int kafelek) {
    return sf::VideoMode({ static_cast<unsigned>(swiat.getSzerokosc() * kafelek + 320),
                           static_cast<unsigned>(swiat.getWysokosc() * kafelek) });
}

static Kierunek kierunekZKlawisza(sf::Keyboard::Key k) {
    switch (k) {
    case sf::Keyboard::Key::W: case sf::Keyboard::Key::Up:    return Kierunek::gora;
    case sf::Keyboard::Key::S: case sf::Keyboard::Key::Down:  return Kierunek::dol;
    case sf::Keyboard::Key::A: case sf::Keyboard::Key::Left:  return Kierunek::lewo;
    case sf::Keyboard::Key::D: case sf::Keyboard::Key::Right: return Kierunek::prawo;
    default: return Kierunek::brak;
    }
}

App::App(Swiat& swiat, int kafelek)
    : okno(trybDla(swiat, kafelek), "Wirtualny Swiat"),
    renderer(kafelek),
    swiat(swiat)
{
    okno.setFramerateLimit(60);
    if (!ImGui::SFML::Init(okno)) throw std::runtime_error("ImGui init");
    ImGui::GetIO().Fonts->AddFontDefault(); 
    renderer.zaladujZasoby();
}

App::~App() {
    ImGui::SFML::Shutdown();
}

void App::przetworzZdarzenia() {
    while (const std::optional event = okno.pollEvent()) {
        ImGui::SFML::ProcessEvent(okno, *event);
        if (event->is<sf::Event::Closed>())
            okno.close();

        if (const auto* klaw = event->getIf<sf::Event::KeyPressed>()) {
            if (klaw->code == sf::Keyboard::Key::Space) {
                swiat.czlowiekSetKierunek(Kierunek::brak);
                swiat.wykonajTure();
            }
            else if (klaw->code == sf::Keyboard::Key::R) {
                swiat.czlowiekUmiejetnosc();
            }
            else {
                Kierunek k = kierunekZKlawisza(klaw->code);
                if (k != Kierunek::brak) {
                    swiat.czlowiekSetKierunek(k);
                    swiat.wykonajTure();
                }
            }
        }
    }
}

void App::rysujPanel() {
    const float panelSzer = 320.f;
    ImGui::SetNextWindowPos(ImVec2(okno.getSize().x - panelSzer, 0.f));
    ImGui::SetNextWindowSize(ImVec2(panelSzer, static_cast<float>(okno.getSize().y)));
    ImGui::Begin("Sterowanie", nullptr,
        ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse);
    
    naprawImgui();
    
    ImGui::Text("Tura: %d", swiat.getTura());

    if (ImGui::Button("Nastepna tura")) swiat.wykonajTure();

    if (swiat.czyCzlowiekZyje()) {
        float bw = ImGui::CalcTextSize("Tarcza").x
            + ImGui::GetStyle().FramePadding.x * 2.0f;
        ImGui::SameLine(ImGui::GetWindowWidth() - bw
            - ImGui::GetStyle().WindowPadding.x);

        bool gotowa = swiat.czlowiekUmiejetnoscGotowa();
        if (!gotowa) ImGui::BeginDisabled();
        if (ImGui::Button("Tarcza"))
            swiat.czlowiekUmiejetnosc();
        if (!gotowa) ImGui::EndDisabled();
    }

    ImGui::Separator();
    ImGui::TextUnformatted("Logi:");
    ImGui::BeginChild("logi", ImVec2(0, 0), true);
    for (const Komunikat& k : swiat.getKomunikaty())
        ImGui::TextUnformatted(tekstKomunikatu(k).c_str());
    if (ImGui::GetScrollY() >= ImGui::GetScrollMaxY())
        ImGui::SetScrollHereY(1.0f);
    ImGui::EndChild();


    ImGui::End();
}

void App::uruchom() {
    sf::Clock zegar;
    while (okno.isOpen()) {
        przetworzZdarzenia();
        ImGui::SFML::Update(okno, zegar.restart());
        rysujPanel();

        okno.clear(sf::Color(20, 20, 20));
        renderer.rysuj(okno, swiat);
        ImGui::SFML::Render(okno);
        okno.display();
    }
}

void App::naprawImgui() {
    static const std::string znaki = [] {
        std::string s;
        for (char c = 32; c < 127; ++c) s += c;
        return s;
        }();

    float y = ImGui::GetCursorPosY();
    ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0, 0, 0, 0));
    ImGui::TextUnformatted(znaki.c_str());
    ImGui::PopStyleColor();
    ImGui::SetCursorPosY(y);
}
