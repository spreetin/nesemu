#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "screen.h"

Screen::Screen(int xSize, int ySize)
{
    setResolution(xSize, ySize);
    sans_font = TTF_OpenFont("Sans.ttf", 12);
}

Screen::~Screen()
{
    if (texture){
        SDL_DestroyTexture(texture);
    }
    if (renderer){
        SDL_DestroyRenderer(renderer);
    }
    if (window){
        SDL_DestroyWindow(window);
    }
}

void Screen::show()
{
    window = SDL_CreateWindow("NES emu", SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED, xRes, yRes, 0);
    renderer = SDL_CreateRenderer(window, -1, 0);
    texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ABGR8888,
                                SDL_TEXTUREACCESS_STATIC, 256, 240);
    back_texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ABGR8888,
                                SDL_TEXTUREACCESS_STATIC, 384, 360);
    SDL_ShowWindow(window);
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);
}

void Screen::clear() {
    color c = {0xFF000000};
    for (int x=0;x<256;x++){
        for (int y=0;y<240;y++){
            nextScreen[x + y*384] = c;
        }
    }
}

void Screen::setResolution(int xSize, int ySize)
{
    xRes = xSize;
    yRes = ySize;
}

void Screen::draw()
{
    for (int x=0;x<240;x++){
        SDL_UpdateTexture(texture, NULL, &nextScreen, 256 * sizeof(uint32_t));
    }
    for (int x=0;x<360;x++){
        SDL_UpdateTexture(back_texture, NULL, &backBox, 384 * sizeof(uint32_t));
    }
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, back_texture, NULL, NULL);
    SDL_RenderCopy(renderer, texture, NULL, &main_rect);
    for (auto & text_block : text_blocks){
        SDL_RenderCopy(renderer, text_block.texture, NULL, text_block.rect);
    }
    SDL_RenderPresent(renderer);
}

void Screen::setPixel(int x, int y, uint8_t col, bool alpha)
{
    color c = palette[col];
    c.a = alpha ? 0 : 255;
    nextScreen[x + 384*y] = c;
}

void Screen::drawBox(int x, int y, int w, int h, int thickness, color c) {
    for (int i=0;i<thickness;i++){
        for (int j=0;j<=w;j++){
            backBox[x+j + (y+i)*384] = c;
            backBox[x+j + (y+h-i)*384] = c;
        }
        for (int j=0+thickness;j<=h-thickness;j++){
            backBox[x+i + (y+j)*384] = c;
            backBox[x+w-i  + (y+j)*384] = c;
        }
    }
}

void Screen::drawText(int x, int y, int size, std::string text) {

}

void Screen::drawExtras() {
    color c = {0xFF00FAFA};
    drawBox(268, 3, 113, 240, 2, c);
    draw();
}

void Screen::drawInfoText(char *pc, char *code, char *mnemonic, char *p, char *a, char* x, char *y, char *sp) {
    for (auto & text_block : text_blocks){
        delete text_block.rect;
        delete text_block.texture;
    }
    text_blocks.empty();

}



