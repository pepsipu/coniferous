#include <memory>
#include <glm/glm.hpp>
#include "Display.h"

int main() {
    std::unique_ptr<Display> display = std::make_unique<Display>(900, 300);
    display->PlotPixel(0, 0, 0xff, 0xff, 0xff);
    display->Update();
    while (1) {}
}