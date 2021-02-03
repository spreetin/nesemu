#include <SDL2/SDL.h>
#include "screen.h"

Screen::Screen(int xSize, int ySize)
{
    setResolution(xSize, ySize);
    setScalingF(3.0);
}

Screen::~Screen()
{
    if (renderer){
        SDL_DestroyRenderer(renderer);
    }
    if (window){
        SDL_DestroyWindow(window);
    }
}

void Screen::show()
{
    SDL_CreateWindowAndRenderer(xRes, yRes, 0, &window, &renderer);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);
    SDL_ShowWindow(window);
}

void Screen::setResolution(int xSize, int ySize)
{
    xRes = xSize;
    yRes = ySize;
}

void Screen::setScalingI(int scaling)
{
    SDL_RenderSetScale(renderer, (float)scaling, (float)scaling);
}

void Screen::setScalingF(float scaling)
{
    SDL_RenderSetScale(renderer, scaling, scaling);
}

void Screen::draw()
{
    for (int x=0;x<256;x++){
        for (int y=0;y<240;y++){
            color c = nextScreen[x][y];
            SDL_SetRenderDrawColor(renderer, c.r, c.g, c.b, c.a);
            SDL_RenderDrawPoint(renderer, x, y);
        }
    }
}

void Screen::setPixel(int x, int y, uint8_t col, bool alpha)
{
    color c = palette[col];
    c.a = alpha ? 0 : 255;
    nextScreen[x][y] = c;
}
