#include <SDL2/SDL.h>
#include "screen.h"

Screen::Screen(int xSize, int ySize)
{
    setResolution(xSize, ySize);
    scale.i = 3;
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
}

void Screen::setResolution(int xSize, int ySize)
{
    xRes = xSize;
    yRes = ySize;
}

void Screen::setScalingI(int scaling)
{
    scale.i = scaling;
    intScaling = true;
}

void Screen::setScalingF(float scaling)
{
    scale.f = scaling;
    intScaling = false;
}

void Screen::draw()
{

}

void Screen::setPixel(int x, int y, char color)
{

}
