#ifndef CONIFERIOUS_DISPLAY_H
#define CONIFERIOUS_DISPLAY_H

#include <stdint.h>
#include <SDL2/SDL.h>

class Display {
public:
    Display(int width, int height);
    ~Display();
    void PlotPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue);
    void Update();
private:
    SDL_Window *window;
    SDL_Renderer *renderer;
};


#endif //CONIFERIOUS_DISPLAY_H
