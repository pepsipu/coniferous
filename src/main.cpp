#include <memory>

#include "Display.h"

int main() {
    std::shared_ptr<Display> display = std::make_shared<Display>(900, 300);
    while (1) {}
}