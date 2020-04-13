#include <SDL2/SDL.h>
#include <iostream>

#include "Display.h"


Display::Display(int width, int height) {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cerr << "SDL failed to initialize: " << SDL_GetError();
    }
    this->window = SDL_CreateWindow("coniferous", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
    this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);
}

void Display::PlotPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue) {
    SDL_SetRenderDrawColor(this->renderer, red, green, blue, 0xff);
    SDL_RenderDrawPoint(this->renderer, x, y);
}

void Display::Update() {
    SDL_RenderPresent(this->renderer);
}

Display::~Display() {
    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow(this->window);
    std::cout << "display destroyed";
}
