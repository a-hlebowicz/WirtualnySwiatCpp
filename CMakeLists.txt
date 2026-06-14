cmake_minimum_required(VERSION 3.20)
project(WirtualnySwiat LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML 3 REQUIRED COMPONENTS Graphics Window System)
find_package(ImGui-SFML REQUIRED)

add_executable(WirtualnySwiat
    src/main.cpp
    src/swiat/Swiat.cpp
    src/swiat/Rng.cpp
    src/organizmy/Organizm.cpp
    src/organizmy/Antylopa.cpp
    src/organizmy/BarszczSosnowskiego.cpp
    src/organizmy/Czlowiek.cpp
    src/organizmy/Guarana.cpp
    src/organizmy/Lis.cpp
    src/organizmy/Mlecz.cpp
    src/organizmy/Owca.cpp
    src/organizmy/Roslina.cpp
    src/organizmy/Trawa.cpp
    src/organizmy/WilczeJagody.cpp
    src/organizmy/Wilk.cpp
    src/organizmy/Zolw.cpp
    src/organizmy/Zwierze.cpp
 "src/gui/App.h" "src/gui/App.cpp" "src/gui/Renderer.h" "src/gui/Renderer.cpp" "src/gui/Zasoby.h" "src/gui/Zasoby.cpp" "src/organizmy/Typy.h" "src/organizmy/Typy.cpp")

target_link_libraries(WirtualnySwiat PRIVATE
    SFML::Graphics
    SFML::Window
    SFML::System
    ImGui-SFML::ImGui-SFML
)