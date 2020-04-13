#include <iostream>
#include <memory>
#include <glm/glm.hpp>
#include "UI.h"

int main() {
    std::unique_ptr<UI::Display> display = std::make_unique<UI::Display>(900, 300);
    SDL_Texture *texture = display->CreateText(UI::OpenSansPXL, "coniferous", {0xff, 0xff, 0xff});
    display->DrawTexture(texture, 0, 0);
    display->Update();
    while (1) {}
}