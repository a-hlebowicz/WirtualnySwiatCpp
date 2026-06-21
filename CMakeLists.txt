cmake_minimum_required(VERSION 3.20)
project(WirtualnySwiat LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(swiat_logika STATIC
    src/organizmy/Typy.cpp
    src/organizmy/Organizm.cpp
    src/organizmy/Zwierze.cpp
    src/organizmy/Roslina.cpp
    src/organizmy/Wilk.cpp
    src/organizmy/Owca.cpp
    src/organizmy/Lis.cpp
    src/organizmy/Zolw.cpp
    src/organizmy/Antylopa.cpp
    src/organizmy/Czlowiek.cpp
    src/organizmy/Trawa.cpp
    src/organizmy/Mlecz.cpp
    src/organizmy/Guarana.cpp
    src/organizmy/WilczeJagody.cpp
    src/organizmy/BarszczSosnowskiego.cpp
    src/swiat/Swiat.cpp
    src/swiat/Rng.cpp
 "src/gui/Teksty.cpp")
target_include_directories(swiat_logika PUBLIC src)


find_package(SFML 3 REQUIRED COMPONENTS Graphics Window System)
find_package(ImGui-SFML REQUIRED)

add_executable(WirtualnySwiat
    src/main.cpp
    src/gui/App.cpp
    src/gui/Renderer.cpp
    src/gui/Zasoby.cpp
 "src/gui/Teksty.cpp")
target_link_libraries(WirtualnySwiat PRIVATE
    swiat_logika
    SFML::Graphics
    SFML::Window
    SFML::System
    ImGui-SFML::ImGui-SFML
)

add_custom_command(TARGET WirtualnySwiat POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/assets $<TARGET_FILE_DIR:WirtualnySwiat>/assets)