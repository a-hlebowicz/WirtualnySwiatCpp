#include "App.h"
#include "../swiat/Swiat.h"
#include <imgui.h>
#include <imgui-SFML.h>
#include <SFML/System/Clock.hpp>
#include "Teksty.h"

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
    const float panelSzer = 320.f;
    ImGui::SetNextWindowPos(ImVec2(okno.getSize().x - panelSzer, 0.f));
    ImGui::SetNextWindowSize(ImVec2(panelSzer, static_cast<float>(okno.getSize().y)));
    ImGui::Begin("Sterowanie", nullptr,
        ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse);
    
    naprawImgui();
    
    ImGui::Text("Tura: %d", swiat.getTura());
    if (ImGui::Button("Nastepna tura"))
        swiat.wykonajTure();

    ImGui::Separator();
    ImGui::TextUnformatted("Logi:");
    ImGui::BeginChild("logi", ImVec2(0, 0), true);   // przewijany
    for (const Komunikat& k : swiat.getKomunikaty())
        ImGui::TextUnformatted(tekstKomunikatu(k).c_str());
    if (ImGui::GetScrollY() >= ImGui::GetScrollMaxY())
        ImGui::SetScrollHereY(1.0f);                   // zostañ na dole, gdy dochodz¹ wpisy
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
    // obejœcie dynamicznego atlasu w imgui-sfml 3.0:
    // trzymamy pe³ny zestaw znaków w atlasie, ¿eby nic nie by³o dorzucane w trakcie
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
