#ifndef CONIFERIOUS_UI_H
#define CONIFERIOUS_UI_H

#include <stdint.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

namespace UI {
    enum FontIndexes {
        OpenSansPXL = 0
    };

    class Display {
    public:

        Display(int width, int height);

        ~Display();

        void PlotPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue);

        void Update();

        SDL_Texture *CreateText(UI::FontIndexes fontIndex, const char *str, SDL_Color color);

        void DrawTexture(SDL_Texture *texture, int x, int y);

    private:
        SDL_Window *window;
        SDL_Renderer *renderer;
    };
}


#endif //CONIFERIOUS_UI_H
