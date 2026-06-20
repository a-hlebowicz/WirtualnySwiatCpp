#include "swiat/Swiat.h"
#include "gui/App.h"

int main() {
    Swiat swiat(20, 20);
    swiat.ustawSwiat();
    App app(swiat);
    app.uruchom();
    return 0;
}