#include "App.h"
#include "../swiat/Swiat.h"
#include <imgui.h>
#include <imgui-SFML.h>
#include <SFML/System/Clock.hpp>

static sf::VideoMode trybDla(const Swiat& swiat, int kafelek) {
    return sf::VideoMode({ static_cast<unsigned>(swiat.getSzerokosc() * kafelek + 320),
                           static_cast<unsigned>(swiat.getWysokosc() * kafelek) });
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
    }
}

void App::rysujPanel() {
    ImGui::Begin("Sterowanie");
    ImGui::Text("Tura: %d", swiat.getTura());
    if (ImGui::Button("Nastepna tura"))
        swiat.wykonajTure();
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