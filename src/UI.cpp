#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>

#include "UI.h"

#define FONT_LENGTH 1

struct {
    char *fontName;
    int fontSize;
} fontNames[FONT_LENGTH] = {
        {"fonts/OpenSansPX.ttf", 45}
};

TTF_Font *fonts[FONT_LENGTH];

UI::Display::Display(int width, int height) {
    TTF_Init();
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cerr << "SDL failed to initialize: " << SDL_GetError();
    }
    this->window = SDL_CreateWindow("coniferous", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
    this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);
    for (int i = 0; i < FONT_LENGTH; i++) {
        fonts[i] = TTF_OpenFont(fontNames[i].fontName, fontNames[i].fontSize);
    }
}

void UI::Display::PlotPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue) {
    SDL_SetRenderDrawColor(this->renderer, red, green, blue, 0xff);
    SDL_RenderDrawPoint(this->renderer, x, y);
}

void UI::Display::Update() {
    SDL_RenderPresent(this->renderer);
}

SDL_Texture *UI::Display::CreateText(UI::FontIndexes fontIndex, const char *str, SDL_Color color) {
    TTF_Font *font = fonts[fontIndex];
    SDL_Surface *surface = TTF_RenderText_Solid(font, str, color);
    SDL_Texture *texture =  SDL_CreateTextureFromSurface(this->renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}

void UI::Display::DrawTexture(SDL_Texture *texture, int x, int y) {
    SDL_Rect textBox;
    SDL_QueryTexture(texture, NULL, NULL, &textBox.w, &textBox.h);
    textBox.x = x;
    textBox.y = y;
    SDL_RenderCopy(this->renderer, texture, NULL, &textBox);
}

UI::Display::~Display() {
    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow(this->window);
    std::cout << "display destroyed";
}
